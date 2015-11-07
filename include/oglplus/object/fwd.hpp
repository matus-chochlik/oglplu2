/**
 *  @file oglplus/object/fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_FWD_1509260923_HPP
#define OGLPLUS_OBJECT_FWD_1509260923_HPP

#include <eagine/object/fwd.hpp>

namespace oglplus {

using eagine::object_traits;

using eagine::object_subtype;

using eagine::object_subtype_t;

using eagine::object_names;

using eagine::object_name;

using eagine::object_zero_and_ops;

using eagine::owned;

using eagine::object_owner;

using any_object_type = eagine::any_object_type<GLenum, 0>;

using any_object_name =
	eagine::any_object_name<GLuint, GLenum, ~GLuint(0), 0>;

template <typename ObjTag>
struct obj_gen_del_ops;

template <typename ObjTag>
struct get_obj_binding_point;

template <typename ObjTag>
using obj_binding_point = typename get_obj_binding_point<ObjTag>::type;

} // namespace oglplus

#endif // include guard
