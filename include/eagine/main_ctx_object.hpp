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
#include "logging/logger.hpp"

namespace eagine {

class main_ctx;

class main_ctx_log_backend_getter {
public:
    main_ctx_log_backend_getter() noexcept;

    auto operator()() noexcept -> auto* {
        return _backend;
    }

private:
    logger_backend* _backend{nullptr};
};

class main_ctx_object;
class main_ctx_object_parent_info {
public:
    main_ctx_object_parent_info(main_ctx&) noexcept {}

    main_ctx_object_parent_info(const main_ctx_object& obj) noexcept
      : _object{&obj} {}

private:
    friend class main_ctx_object;
    const main_ctx_object* _object{nullptr};
};

using main_ctx_parent = const main_ctx_object_parent_info&;

class main_ctx_object
  : public named_logging_object<main_ctx_log_backend_getter> {
    using base = named_logging_object<main_ctx_log_backend_getter>;

    static auto _make_base(identifier obj_id, main_ctx_parent parent) noexcept {
        if(parent._object) {
            return base{obj_id, static_cast<const base&>(*parent._object)};
        }
        return base{obj_id, main_ctx_log_backend_getter{}};
    }

public:
    main_ctx_object(identifier obj_id, main_ctx_parent parent) noexcept
      : base{_make_base(obj_id, parent)} {}

    auto context() const noexcept -> main_ctx&;
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/main_ctx_object.inl>
#endif

#endif // EAGINE_MAIN_CTX_OBJECT_HPP
