/**
 *  @file eagine/application_config.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_APPLICATION_CONFIG_HPP
#define EAGINE_APPLICATION_CONFIG_HPP

#include "main_ctx_object.hpp"
#include "program_args.hpp"
#include "valid_if/decl.hpp"
#include "value_tree/wrappers.hpp"
#include <memory>

namespace eagine {
//------------------------------------------------------------------------------
class master_ctx;
class application_config_impl;

class application_config : public main_ctx_object {
public:
    application_config(main_ctx_parent parent) noexcept
      : main_ctx_object{EAGINE_ID(AppConfig), parent} {}

    auto is_set(string_view key, string_view tag = {}) noexcept -> bool {
        if(const auto attr{_find_comp_attr(key, tag)}) {
            bool flag{false};
            if(attr.fetch_value(flag)) {
                return flag;
            }
        }
        if(const auto arg{_find_prog_arg(key)}) {
            bool result{true};
            arg.parse_next(result, log_debug_stream());
            return result;
        }
        if(const auto opt_val{_eval_env_var(key)}) {
            if(auto converted{from_string<bool>(extract(opt_val))}) {
                return extract(converted);
            }
        }
        return false;
    }

    template <typename T>
    auto fetch(string_view key, T& dest, string_view tag = {}) noexcept
      -> bool {
        if(const auto arg{_find_prog_arg(key)}) {
            if(arg.parse_next(dest, log_error_stream())) {
                return true;
            } else {
                log_error("could not parse configuration value '${value}'")
                  .arg(EAGINE_ID(key), key)
                  .arg(EAGINE_ID(value), arg.get());
            }
        }
        if(const auto opt_val{_eval_env_var(key)}) {
            if(auto converted{from_string<T>(extract(opt_val))}) {
                dest = std::move(extract(converted));
                return true;
            } else {
                log_error("could not convert configuration value '${value}'")
                  .arg(EAGINE_ID(key), key)
                  .arg(EAGINE_ID(value), extract(opt_val));
            }
        }
        if(const auto attr{_find_comp_attr(key, tag)}) {
            if(attr.fetch_value(dest)) {
                return true;
            } else {
                log_error("could not fetch configuration value '${key}'")
                  .arg(EAGINE_ID(key), key);
            }
        }
        return false;
    }

    template <typename T, typename P>
    auto fetch(string_view key, valid_if<T, P>& dest, string_view tag) noexcept
      -> bool {
        T temp{};
        if(fetch(key, temp, tag)) {
            if(dest.is_valid(temp)) {
                dest = std::move(temp);
                return true;
            } else {
                log_error("value '${value}' is not valid for '${key}'")
                  .arg(EAGINE_ID(value), temp)
                  .arg(EAGINE_ID(key), key);
            }
        }
        return false;
    }

    template <typename T>
    auto get(string_view key, identity<T> = {}) -> optionally_valid<T> {
        T temp{};
        const auto fetched = fetch(key, temp);
        return {std::move(temp), fetched};
    }

    template <typename T>
    auto init(string_view key, T& initial, string_view tag = {}) -> T {
        fetch(key, initial, tag);
        return initial;
    }

private:
    std::shared_ptr<application_config_impl> _pimpl;
    auto _impl() noexcept -> application_config_impl*;

    auto _find_comp_attr(string_view key, string_view tag) noexcept
      -> valtree::compound_attribute;
    auto _find_prog_arg(string_view key) noexcept -> program_arg;
    auto _eval_env_var(string_view key) noexcept
      -> optionally_valid<string_view>;
};
//------------------------------------------------------------------------------
template <typename T>
inline auto application_config_initial(
  application_config& config,
  string_view key,
  T& initial,
  string_view tag) -> T& {
    config.init(key, initial, tag);
    return initial;
}
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/application_config.inl>
#endif

#endif
