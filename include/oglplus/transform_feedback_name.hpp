/**
 *  @file oglplus/transform_feedback_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TRANSFORM_FEEDBACK_NAME_1509260923_HPP
#define OGLPLUS_TRANSFORM_FEEDBACK_NAME_1509260923_HPP

#include "object/gl_name.hpp"
#include "enum/types.hpp"

#ifndef GL_TRANSFORM_FEEDBACK
#define GL_TRANSFORM_FEEDBACK 0x8E22
#endif

namespace oglplus {
namespace tag {

using transform_feedback = gl_obj_tag<GL_TRANSFORM_FEEDBACK>;

} // namespace tag

using transform_feedback_name = object_name<tag::transform_feedback>;

template <>
struct get_obj_binding_point<tag::transform_feedback>
{
	typedef transform_feedback_target type;
};

} // namespace oglplus

#endif // include guard
