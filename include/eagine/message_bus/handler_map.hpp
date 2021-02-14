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
template <typename MemFuncConst>
struct message_handler_map {
    message_id _msg_id;

    constexpr message_handler_map(message_id msgid) noexcept
      : _msg_id{std::move(msgid)} {}

    constexpr auto msg_id() const noexcept -> message_id {
        return _msg_id;
    }

    static constexpr auto method() noexcept -> MemFuncConst {
        return {};
    }
};
//------------------------------------------------------------------------------
template <typename MessageId, typename MemFuncConst>
struct static_message_handler_map {
    static constexpr auto msg_id() noexcept -> MessageId {
        return {};
    }

    static constexpr auto method() noexcept -> MemFuncConst {
        return {};
    }
};
//------------------------------------------------------------------------------
#define EAGINE_MSG_MAP(CLASS_ID, METHOD_ID, CLASS, METHOD) \
    eagine::msgbus::static_message_handler_map<            \
      EAGINE_MSG_TYPE(CLASS_ID, METHOD_ID),                \
      EAGINE_MEM_FUNC_T(CLASS, METHOD)>()
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_HANDLER_MAP_HPP
