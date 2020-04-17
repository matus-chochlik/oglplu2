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
struct message_id {
    using type = message_id;

    static constexpr bool matches(
      identifier_t class_id, identifier_t method_id) noexcept {
        return (ClassId == class_id) && (MethodId == method_id);
    }
};
//------------------------------------------------------------------------------
struct message_id_tuple : std::tuple<identifier_t, identifier_t> {
    using std::tuple<identifier_t, identifier_t>::tuple;
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
