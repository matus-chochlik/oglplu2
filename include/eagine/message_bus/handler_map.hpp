/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_HANDLER_MAP_HPP
#define EAGINE_MESSAGE_BUS_HANDLER_MAP_HPP

#include "../mem_func_const.hpp"
#include "../message_id.hpp"
#include "../span.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Represents a mapping from a message type id to member function constant.
/// @ingroup msgbus
/// @see message_id
/// @see static_message_handler_map
/// @see member_function_constant
template <typename MemFuncConst>
struct message_handler_map {
    message_id _msg_id;

    /// @brief Construction from message type id.
    constexpr message_handler_map(message_id msgid) noexcept
      : _msg_id{std::move(msgid)} {}

    /// @brief Returns the message type id.
    constexpr auto msg_id() const noexcept -> message_id {
        return _msg_id;
    }

    /// @brief Returns the member function constant.
    static constexpr auto method() noexcept -> MemFuncConst {
        return {};
    }
};
//------------------------------------------------------------------------------
/// @brief Represents a mapping from a message type id to member function constant.
/// @ingroup msgbus
/// @see message_id
/// @see message_handler_map
/// @see member_function_constant
template <typename MessageId, typename MemFuncConst>
struct static_message_handler_map {

    /// @brief Returns the message type id.
    static constexpr auto msg_id() noexcept -> MessageId {
        return {};
    }

    /// @brief Returns the member function constant.
    static constexpr auto method() noexcept -> MemFuncConst {
        return {};
    }
};
//------------------------------------------------------------------------------
/// @brief Constructs an instance of static message handler map.
/// @ingroup msgbus
/// @see eagine::msgbus::static_message_handler_map
/// @see EAGINE_MSG_TYPE
/// @see EAGINE_MEM_FUNC_T
#define EAGINE_MSG_MAP(CLASS_ID, METHOD_ID, CLASS, METHOD) \
    eagine::msgbus::static_message_handler_map<            \
      EAGINE_MSG_TYPE(CLASS_ID, METHOD_ID),                \
      EAGINE_MEM_FUNC_T(CLASS, METHOD)>()
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_HANDLER_MAP_HPP
