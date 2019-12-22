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

namespace eagine {
//------------------------------------------------------------------------------
template <std::uint64_t ApiId, std::uint64_t Id>
struct message_id {
    using type = message_id;
};
//------------------------------------------------------------------------------
#define EAGINE_MSG_TYPE(API, NAME) \
    ::eagine::message_id<EAGINE_ID(API).value(), EAGINE_ID(NAME).value()>
#define EAGINE_MSG_ID(NAME) \
    EAGINE_MSG_TYPE(NAME) { \
    }
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_MESSAGE_ID_HPP
