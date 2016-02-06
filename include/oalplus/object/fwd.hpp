/**
 *  @file oalplus/object/fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_OBJECT_FWD_1509260923_HPP
#define OALPLUS_OBJECT_FWD_1509260923_HPP

#include <eagine/object/fwd.hpp>

namespace oalplus {

using eagine::object_traits;

using eagine::object_names;

using eagine::object_name;

using eagine::owned;

using eagine::object_owner;

using any_object_name =
	eagine::any_object_name<ALuint, ALenum, ~ALuint(0), 200>;

template <typename ObjTag>
struct obj_gen_del_ops;

template <typename ObjTag, typename Derived, typename Base>
struct obj_member_ops;

} // namespace oalplus

#endif // include guard
