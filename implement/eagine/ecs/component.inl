/**
 *  @file eagine/ecs/component.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine {
namespace ecs {
//------------------------------------------------------------------------------
template <>
EAGINE_LIB_FUNC component_uid_t&
component_uid_getter<false>::_curr_uid() {
    static component_uid_t uid = 0;
    return uid;
}
//------------------------------------------------------------------------------
template <>
EAGINE_LIB_FUNC component_uid_t&
component_uid_getter<true>::_curr_uid() {
    static component_uid_t uid = 0;
    return uid;
}
//------------------------------------------------------------------------------
} // namespace ecs
} // namespace eagine
