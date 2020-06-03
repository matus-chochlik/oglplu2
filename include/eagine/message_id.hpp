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
template <identifier_t ClassId, identifier_t MethodId>
struct static_message_id;
//------------------------------------------------------------------------------
struct message_id_tuple : std::tuple<identifier_t, identifier_t> {
    using base = std::tuple<identifier_t, identifier_t>;

    constexpr message_id_tuple() noexcept
      : base{0U, 0U} {
    }

    constexpr message_id_tuple(identifier_t c, identifier_t m) noexcept
      : base{c, m} {
    }

    constexpr message_id_tuple(identifier c, identifier m) noexcept
      : base{c.value(), m.value()} {
    }

    constexpr message_id_tuple(std::tuple<identifier, identifier> t) noexcept
      : message_id_tuple{std::get<0>(t), std::get<1>(t)} {
    }

    template <identifier_t ClassId, identifier_t MethodId>
    constexpr message_id_tuple(
      const static_message_id<ClassId, MethodId>&) noexcept
      : base{ClassId, MethodId} {
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

    constexpr bool is_valid() const noexcept {
        return (class_id() != 0U) && (method_id() != 0U);
    }

    constexpr auto id_tuple() const noexcept {
        return std::make_tuple(class_(), method());
    }

    constexpr bool has_class(identifier id) const noexcept {
        return class_id() == id.value();
    }

    constexpr bool has_method(identifier id) const noexcept {
        return method_id() == id.value();
    }
};
//------------------------------------------------------------------------------
template <identifier_t ClassId, identifier_t MethodId>
struct static_message_id {
    using type = static_message_id;

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
};
//------------------------------------------------------------------------------
template <identifier_t ClassId, identifier_t MethodId>
inline bool operator==(
  message_id_tuple l, static_message_id<ClassId, MethodId> r) noexcept {
    return l == message_id_tuple{r};
}
//------------------------------------------------------------------------------
#define EAGINE_MSG_TYPE(API, NAME) \
    ::eagine::static_message_id<EAGINE_ID_V(API), EAGINE_ID_V(NAME)>
#define EAGINE_MSG_ID(API, NAME) \
    EAGINE_MSG_TYPE(API, NAME) { \
    }
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MESSAGE_ID_HPP
