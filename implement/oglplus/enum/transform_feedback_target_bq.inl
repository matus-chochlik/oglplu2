//  File implement/oglplus/enum/transform_feedback_target_bq.inl
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
namespace oglplus {

OGLPLUS_LIB_FUNC
binding_query
get_binding_query(transform_feedback_target tgt)
noexcept
{
	GLenum result = 0;
	switch(GLenum(tgt))
	{
#if	defined(GL_TRANSFORM_FEEDBACK) && \
	defined(GL_TRANSFORM_FEEDBACK_BINDING)
		case GL_TRANSFORM_FEEDBACK:
			result = GL_TRANSFORM_FEEDBACK_BINDING;
			break;
#endif
		default:;
	}
	return binding_query(result);
}

} // namespace oglplus
