/**
 *  @file eagine/main_ctx_object.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MAIN_CTX_OBJECT_HPP
#define EAGINE_MAIN_CTX_OBJECT_HPP

#include "assert.hpp"
#include "identifier_t.hpp"
#include "logging/logger.hpp"
#include "main_ctx_fwd.hpp"

namespace eagine {

template <typename T>
auto application_config_initial(
  application_config& config,
  string_view key,
  T& initial,
  string_view tag) -> T&;

class main_ctx_log_backend_getter {
public:
    main_ctx_log_backend_getter() noexcept;
    main_ctx_log_backend_getter(master_ctx&) noexcept;

    auto operator()() noexcept -> auto* {
        return _backend;
    }

private:
    logger_backend* const _backend{nullptr};
};

class main_ctx_object_parent_info {
public:
    main_ctx_object_parent_info(main_ctx&) noexcept {}

    main_ctx_object_parent_info(master_ctx& ctx) noexcept
      : _context{&ctx} {}

    main_ctx_object_parent_info(const main_ctx_object& obj) noexcept
      : _object{&obj} {}

private:
    friend class main_ctx_object;

    master_ctx* _context{nullptr};
    const main_ctx_object* _object{nullptr};
};

class application_config;

class main_ctx_object
  : public named_logging_object<main_ctx_log_backend_getter> {
    using base = named_logging_object<main_ctx_log_backend_getter>;

    static auto _make_base(identifier obj_id, main_ctx_parent parent) noexcept {
        if(parent._object) {
            return base{obj_id, static_cast<const base&>(*parent._object)};
        }
        if(parent._context) {
            return base{obj_id, main_ctx_log_backend_getter{*parent._context}};
        }
        return base{obj_id, main_ctx_log_backend_getter{}};
    }

public:
    main_ctx_object(identifier obj_id, main_ctx_parent parent) noexcept
      : base{_make_base(obj_id, parent)} {}

    auto process_instance_id() const noexcept -> process_instance_id_t;

    auto main_context() const noexcept -> main_ctx&;

    auto app_config() const noexcept -> application_config&;

    auto as_parent() noexcept -> main_ctx_object_parent_info {
        return {*this};
    }

    template <typename T>
    auto cfg_init(string_view key, T initial, string_view tag = {}) -> T {
        return application_config_initial(app_config(), key, initial, tag);
    }

    template <typename Extractable, typename T>
    auto cfg_extr(
      string_view key,
      T initial,
      string_view tag = {},
      type_identity<Extractable> = {}) -> T {
        Extractable value(initial);
        return extract_or(
          application_config_initial(app_config(), key, value, tag), initial);
    }
};

} // namespace eagine

#endif // EAGINE_MAIN_CTX_OBJECT_HPP
