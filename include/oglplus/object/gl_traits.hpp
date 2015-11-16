/**
 *  @file oglplus/object/gl_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_GL_TRAITS_1509260923_HPP
#define OGLPLUS_OBJECT_GL_TRAITS_1509260923_HPP

#include "fwd.hpp"

namespace oglplus {
namespace tag {

template <GLenum Tag>
struct gl_obj_tag
{ };

} // namespace tag

template <typename ObjName>
struct obj_zero_dsa_ops;

template <typename ObjTag>
struct obj_zero_dsa_ops<object_name<ObjTag>>
 : object_zero_name<ObjTag>
{
	obj_zero_dsa_ops(void) = default;

protected:
	obj_zero_dsa_ops(object_name<ObjTag> name)
	noexcept
	 : object_zero_name<ObjTag>(name)
	{ }
};

template <typename ObjName>
struct obj_dsa_ops
 : obj_zero_dsa_ops<ObjName>
{
	obj_dsa_ops(void) = default;

	obj_dsa_ops(ObjName name)
	noexcept
	 : obj_zero_dsa_ops<ObjName>(name)
	{ }
};

template <typename Tag>
struct gl_object_traits
{
	typedef Tag tag;

	typedef GLuint name_type;

	typedef obj_gen_del_ops<tag> gen_del_ops;

	template <typename ObjName>
	using zero_dsa_ops_t = obj_zero_dsa_ops<ObjName>;

	template <typename ObjName>
	using dsa_ops_t = obj_dsa_ops<ObjName>;

	static inline constexpr
	GLuint invalid_name(void)
	noexcept
	{
		return ~GLuint(0);
	}
};

} // namespace oglplus

namespace eagine {

template <GLenum Tag>
struct object_traits<oglplus::tag::gl_obj_tag<Tag>>
 : oglplus::gl_object_traits<oglplus::tag::gl_obj_tag<Tag>>
{
	static inline constexpr
	GLenum get_type(void)
	noexcept
	{
		return Tag;
	}
};

} // namespace eagine

#endif // include guard
