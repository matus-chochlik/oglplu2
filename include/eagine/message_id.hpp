/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_ID_HPP
#define EAGINE_MESSAGE_ID_HPP

#include "identifier.hpp"
#include <tuple>

namespace eagine {
//------------------------------------------------------------------------------
template <identifier_t ClassId, identifier_t MethodId>
struct static_message_id;
//------------------------------------------------------------------------------
/// @brief Class storing two identifier values representing class/method pair.
/// @ingroup identifiers
/// @see static_message_id
/// @see identifier_t
/// @see identifier
struct message_id : std::tuple<identifier_t, identifier_t> {
    using base = std::tuple<identifier_t, identifier_t>;

    ///	@brief Default constructor.
    /// @post !is_valid()
    constexpr message_id() noexcept
      : base{0U, 0U} {}

    ///	@brief Construction from two identifier values.
    constexpr message_id(identifier_t c, identifier_t m) noexcept
      : base{c, m} {}

    ///	@brief Construction from two identifier objects.
    constexpr message_id(identifier c, identifier m) noexcept
      : base{c.value(), m.value()} {}

    ///	@brief Construction from a tuple of two identifier objects.
    constexpr message_id(std::tuple<identifier, identifier> t) noexcept
      : message_id{std::get<0>(t), std::get<1>(t)} {}

    ///	@brief Construction from static_message_id value.
    template <identifier_t ClassId, identifier_t MethodId>
    constexpr message_id(const static_message_id<ClassId, MethodId>&) noexcept
      : base{ClassId, MethodId} {}

    /// @brief Returns the class identifier value.
    constexpr auto class_id() const noexcept -> identifier_t {
        return std::get<0>(*this);
    }

    /// @brief Returns the class identifier.
    constexpr auto class_() const noexcept -> identifier {
        return identifier{class_id()};
    }

    /// @brief Returns the method identifier value.
    constexpr auto method_id() const noexcept -> identifier_t {
        return std::get<1>(*this);
    }

    /// @brief Returns the method identifier.
    constexpr auto method() const noexcept -> identifier {
        return identifier{method_id()};
    }

    /// @brief Checks if the stored identifier values are non-zero.
    constexpr auto is_valid() const noexcept {
        return (class_id() != 0U) && (method_id() != 0U);
    }

    /// @brief Returns the class and method identifiers in a tuple.
    /// See class_
    /// See method
    constexpr auto id_tuple() const noexcept
      -> std::tuple<identifier, identifier> {
        return {class_(), method()};
    }

    /// @brief Checks if the class identifier matches the argument.
    /// @see has_method
    constexpr auto has_class(identifier id) const noexcept {
        return class_id() == id.value();
    }

    /// @brief Checks if the method identifier matches the argument.
    /// @see has_class
    constexpr auto has_method(identifier id) const noexcept {
        return method_id() == id.value();
    }
};
//------------------------------------------------------------------------------
/// @brief Template with two identifier parameters representing class/method pair.
/// @ingroup identifiers
/// @see message_id
///
/// This class encodes an identifier pair in its template parameters.
/// It is implicitly convertible to message_id.
template <identifier_t ClassId, identifier_t MethodId>
struct static_message_id {
    using type = static_message_id;

    /// @brief Returns the class identifier value.
    static constexpr auto class_id() noexcept -> identifier_t {
        return ClassId;
    }

    /// @brief Returns the class identifier.
    static constexpr auto class_() noexcept -> identifier {
        return identifier{class_id()};
    }

    /// @brief Returns the method identifier value.
    static constexpr auto method_id() noexcept -> identifier_t {
        return MethodId;
    }

    /// @brief Returns the method identifier.
    static constexpr auto method() noexcept -> identifier {
        return identifier{method_id()};
    }
};
//------------------------------------------------------------------------------
/// @brief Equality comparison between message_id and static_message_id.
/// @ingroup identifiers
template <identifier_t ClassId, identifier_t MethodId>
inline auto
operator==(message_id l, static_message_id<ClassId, MethodId> r) noexcept {
    return l == message_id{r};
}
//------------------------------------------------------------------------------
/// @brief Macro for declaring instantiations of static_message_id.
/// @ingroup identifiers
/// @see eagine::static_message_id
/// @see EAGINE_ID
/// @see EAGINE_MSG_ID
#define EAGINE_MSG_TYPE(API, NAME) \
    ::eagine::static_message_id<EAGINE_ID_V(API), EAGINE_ID_V(NAME)>

/// @brief Macro for instantiating objects of static_message_id.
/// @ingroup identifiers
/// @see eagine::static_message_id
/// @see EAGINE_ID
/// @see EAGINE_MSG_TYPE
#define EAGINE_MSG_ID(API, NAME) \
    EAGINE_MSG_TYPE(API, NAME) {}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MESSAGE_ID_HPP
