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
struct message_id : std::tuple<identifier_t, identifier_t> {
    using base = std::tuple<identifier_t, identifier_t>;

    constexpr message_id() noexcept
      : base{0U, 0U} {}

    constexpr message_id(identifier_t c, identifier_t m) noexcept
      : base{c, m} {}

    constexpr message_id(identifier c, identifier m) noexcept
      : base{c.value(), m.value()} {}

    constexpr message_id(std::tuple<identifier, identifier> t) noexcept
      : message_id{std::get<0>(t), std::get<1>(t)} {}

    template <identifier_t ClassId, identifier_t MethodId>
    constexpr message_id(const static_message_id<ClassId, MethodId>&) noexcept
      : base{ClassId, MethodId} {}

    constexpr auto class_id() const noexcept -> identifier_t {
        return std::get<0>(*this);
    }

    constexpr auto class_() const noexcept {
        return identifier{class_id()};
    }

    constexpr auto method_id() const noexcept -> identifier_t {
        return std::get<1>(*this);
    }

    constexpr auto method() const noexcept {
        return identifier{method_id()};
    }

    constexpr auto is_valid() const noexcept {
        return (class_id() != 0U) && (method_id() != 0U);
    }

    constexpr auto id_tuple() const noexcept {
        return std::make_tuple(class_(), method());
    }

    constexpr auto has_class(identifier id) const noexcept {
        return class_id() == id.value();
    }

    constexpr auto has_method(identifier id) const noexcept {
        return method_id() == id.value();
    }
};
//------------------------------------------------------------------------------
template <identifier_t ClassId, identifier_t MethodId>
struct static_message_id {
    using type = static_message_id;

    static constexpr auto class_id() noexcept -> identifier_t {
        return ClassId;
    }

    static constexpr auto class_() noexcept {
        return identifier{class_id()};
    }

    static constexpr auto method_id() noexcept -> identifier_t {
        return MethodId;
    }

    static constexpr auto method() noexcept {
        return identifier{method_id()};
    }
};
//------------------------------------------------------------------------------
template <identifier_t ClassId, identifier_t MethodId>
inline auto
operator==(message_id l, static_message_id<ClassId, MethodId> r) noexcept {
    return l == message_id{r};
}
//------------------------------------------------------------------------------
#define EAGINE_MSG_TYPE(API, NAME) \
    ::eagine::static_message_id<EAGINE_ID_V(API), EAGINE_ID_V(NAME)>
#define EAGINE_MSG_ID(API, NAME) \
    EAGINE_MSG_TYPE(API, NAME) {}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MESSAGE_ID_HPP
