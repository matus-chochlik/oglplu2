/**
 *  @file eagine/message_id.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_ID_HPP
#define EAGINE_MESSAGE_ID_HPP

#include "identifier.hpp"
#include <tuple>

namespace eagine {
//------------------------------------------------------------------------------
struct message_id_tuple : std::tuple<identifier_t, identifier_t> {
    using base = std::tuple<identifier_t, identifier_t>;

    constexpr message_id_tuple(identifier_t c, identifier_t m) noexcept
      : base{c, m} {
    }

    constexpr message_id_tuple(identifier c, identifier m) noexcept
      : base{c.value(), m.value()} {
    }

    constexpr identifier_t class_id() const noexcept {
        return std::get<0>(*this);
    }

    constexpr auto class_() const noexcept {
        return identifier{class_id()};
    }

    constexpr identifier_t method_id() const noexcept {
        return std::get<1>(*this);
    }

    constexpr auto method() const noexcept {
        return identifier{method_id()};
    }
};
//------------------------------------------------------------------------------
template <identifier_t ClassId, identifier_t MethodId>
struct message_id {
    using type = message_id;

    static constexpr identifier_t class_id() noexcept {
        return ClassId;
    }

    static constexpr auto class_() noexcept {
        return identifier{class_id()};
    }

    static constexpr identifier_t method_id() noexcept {
        return MethodId;
    }

    static constexpr auto method() noexcept {
        return identifier{method_id()};
    }

    static constexpr bool matches(const message_id_tuple& mid) noexcept {
        return (ClassId == mid.class_id()) && (MethodId == mid.method_id());
    }

    static constexpr bool matches(
      identifier_t class_id, identifier_t method_id) noexcept {
        return (ClassId == class_id) && (MethodId == method_id);
    }
};
//------------------------------------------------------------------------------
template <identifier_t ClassId, identifier_t MethodId>
constexpr inline message_id_tuple as_tuple(
  message_id<ClassId, MethodId>) noexcept {
    return {ClassId, MethodId};
}
//------------------------------------------------------------------------------
#define EAGINE_MSG_TYPE(API, NAME) \
    ::eagine::message_id<EAGINE_ID_V(API), EAGINE_ID_V(NAME)>
#define EAGINE_MSG_ID(API, NAME) \
    EAGINE_MSG_TYPE(API, NAME) { \
    }
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MESSAGE_ID_HPP
