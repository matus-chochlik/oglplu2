/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_APPLICATION_CONFIG_HPP
#define EAGINE_APPLICATION_CONFIG_HPP

#include "main_ctx_object.hpp"
#include "program_args.hpp"
#include "valid_if/decl.hpp"
#include "value_tree/wrappers.hpp"
#include <memory>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
class master_ctx;
class application_config_impl;

/// @brief Class for reading application configuration.
/// @ingroup main_context
///
/// This class allow to read application configuration values from from
/// environment variables, command line arguments and/or configuration files.
class application_config : public main_ctx_object {
public:
    application_config(main_ctx_parent parent) noexcept
      : main_ctx_object{EAGINE_ID(AppConfig), parent} {}

    /// @brief Checks is the boolean option identified by @p key is set to true.
    auto is_set(string_view key, string_view tag = {}) noexcept -> bool {
        if(const auto attr{_find_comp_attr(key, tag)}) {
            bool flag{false};
            if(attr.select_value(flag, application_config_tag())) {
                return flag;
            }
        }
        if(const auto arg{_find_prog_arg(key)}) {
            bool result{true};
            arg.parse_next(
              result, application_config_tag(), log_debug_stream());
            return result;
        }
        if(const auto opt_val{_eval_env_var(key)}) {
            if(auto converted{from_string<bool>(extract(opt_val))}) {
                return extract(converted);
            }
        }
        return false;
    }

    /// @brief Fetches the configuration value identified by @p key, into @p dest.
    template <typename T>
    auto fetch(string_view key, T& dest, string_view tag = {}) noexcept
      -> bool {
        if(const auto arg{_find_prog_arg(key)}) {
            if(arg.parse_next(
                 dest, application_config_tag(), log_error_stream())) {
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
            if(attr.select_value(dest, application_config_tag())) {
                return true;
            } else {
                log_error("could not fetch configuration value '${key}'")
                  .arg(EAGINE_ID(key), key);
            }
        }
        return false;
    }

    /// @brief Fetches the configuration values identified by @p key, into @p dest.
    template <typename T, typename A>
    auto fetch(
      string_view key,
      std::vector<T, A>& dest,
      string_view tag = {}) noexcept {
        const auto arg_name{_prog_arg_name(key)};
        for(auto arg : _prog_args()) {
            if(arg.is_tag(arg_name)) {
                T temp{};
                if(arg.parse_next(
                     temp, application_config_tag(), log_error_stream())) {
                    dest.emplace_back(std::move(temp));
                } else {
                    log_error("could not parse configuration value '${value}'")
                      .arg(EAGINE_ID(key), key)
                      .arg(EAGINE_ID(value), arg.get());
                    return false;
                }
            }
        }
        if(const auto opt_val{_eval_env_var(key)}) {
            if(auto converted{from_string<T>(extract(opt_val))}) {
                dest.emplace_back(std::move(extract(converted)));
            } else {
                log_error("could not convert configuration value '${value}'")
                  .arg(EAGINE_ID(key), key)
                  .arg(EAGINE_ID(value), extract(opt_val));
                return false;
            }
        }
        if(const auto attr{_find_comp_attr(key, tag)}) {
            const auto count = attr.value_count();
            if(count > 0) {
                dest.resize(dest.size() + std_size(count));
                if(!attr.select_values(
                     tail(cover(dest), count), application_config_tag())) {
                    log_error("could not fetch configuration values '${key}'")
                      .arg(EAGINE_ID(key), key);
                    return false;
                }
            }
        }
        return true;
    }

    /// @brief Fetches the configuration value identified by @p key, into @p dest.
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

    /// @brief Returns the configuration value or type @p T, identified by @p key.
    template <typename T>
    auto get(string_view key, type_identity<T> = {}) -> optionally_valid<T> {
        T temp{};
        const auto fetched = fetch(key, temp);
        return {std::move(temp), fetched};
    }

    /// @brief Fetches the configuration value identified by @p key, into @p init.
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

    auto _prog_args() noexcept -> const program_args&;
    auto _prog_arg_name(string_view key) noexcept -> std::string;
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
/// @brief Class wrapping values that can be loaded from application_config.
/// @ingroup main_context
template <typename T, typename As = std::add_const_t<T>&>
class application_config_value {
public:
    /// @brief Initialization from key, tag and optional initial value.
    application_config_value(
      application_config& config,
      string_view key,
      string_view tag,
      T initial = {}) noexcept
      : _value{application_config_initial(config, key, initial, tag)} {}

    /// @brief Initialization from key and optional initial value.
    application_config_value(
      application_config& config,
      string_view key,
      T initial = {}) noexcept
      : application_config_value{config, key, {}, initial} {}

    auto operator=(T new_value) -> auto& {
        _value = std::move(new_value);
        return *this;
    }

    /// @brief Returns the stored value converted to the @p As type.
    auto value() const noexcept -> As {
        return _value;
    }

    /// @brief Implicit conversion of the stored value to the @p As type.
    /// @see value
    operator As() const noexcept {
        return value();
    }

    friend auto extract(const application_config_value& that) noexcept -> As {
        return that.value();
    }

private:
    T _value{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/application_config.inl>
#endif

#endif
