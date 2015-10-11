//  File implement/oglplus/vertex_attrib_get_set.inl
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the the 'source/misc/make_code.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#include <cassert>

namespace oglplus {

template <>
struct prog_var_get_set_ops<tag::vertex_attrib>
{

	static
	outcome<void>
	set(
		identity<GLshort>,
		vertex_attrib_location va,
		GLshort v0
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib1s)(va.index(), v0);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib1s, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLshort>,
		vertex_attrib_location va,
		GLshort v0, GLshort v1
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib2s)(va.index(), v0, v1);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib2s, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLshort>,
		vertex_attrib_location va,
		GLshort v0, GLshort v1, GLshort v2
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib3s)(va.index(), v0, v1, v2);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib3s, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLshort>,
		vertex_attrib_location va,
		GLshort v0, GLshort v1, GLshort v2, GLshort v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib4s)(va.index(), v0, v1, v2, v3);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib4s, always);
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLint>,
		vertex_attrib_location va,
		GLint v0
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI1i)(va.index(), v0);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribI1i, always);
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLint>,
		vertex_attrib_location va,
		GLint v0, GLint v1
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI2i)(va.index(), v0, v1);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribI2i, always);
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLint>,
		vertex_attrib_location va,
		GLint v0, GLint v1, GLint v2
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI3i)(va.index(), v0, v1, v2);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribI3i, always);
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLint>,
		vertex_attrib_location va,
		GLint v0, GLint v1, GLint v2, GLint v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI4i)(va.index(), v0, v1, v2, v3);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribI4i, always);
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLuint>,
		vertex_attrib_location va,
		GLuint v0
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI1ui)(va.index(), v0);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribI1ui, always);
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLuint>,
		vertex_attrib_location va,
		GLuint v0, GLuint v1
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI2ui)(va.index(), v0, v1);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribI2ui, always);
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLuint>,
		vertex_attrib_location va,
		GLuint v0, GLuint v1, GLuint v2
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI3ui)(va.index(), v0, v1, v2);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribI3ui, always);
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLuint>,
		vertex_attrib_location va,
		GLuint v0, GLuint v1, GLuint v2, GLuint v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI4ui)(va.index(), v0, v1, v2, v3);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribI4ui, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		vertex_attrib_location va,
		GLfloat v0
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib1f)(va.index(), v0);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib1f, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		vertex_attrib_location va,
		GLfloat v0, GLfloat v1
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib2f)(va.index(), v0, v1);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib2f, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		vertex_attrib_location va,
		GLfloat v0, GLfloat v1, GLfloat v2
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib3f)(va.index(), v0, v1, v2);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib3f, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		vertex_attrib_location va,
		GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib4f)(va.index(), v0, v1, v2, v3);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib4f, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLdouble>,
		vertex_attrib_location va,
		GLdouble v0
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib1d)(va.index(), v0);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib1d, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLdouble>,
		vertex_attrib_location va,
		GLdouble v0, GLdouble v1
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib2d)(va.index(), v0, v1);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib2d, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLdouble>,
		vertex_attrib_location va,
		GLdouble v0, GLdouble v1, GLdouble v2
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib3d)(va.index(), v0, v1, v2);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib3d, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLdouble>,
		vertex_attrib_location va,
		GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib4d)(va.index(), v0, v1, v2, v3);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib4d, always);
		return {};
	}

	static
	outcome<void>
	setN(
		identity<GLubyte>,
		vertex_attrib_location va,
		GLubyte v0, GLubyte v1, GLubyte v2, GLubyte v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib4Nub)(va.index(), v0, v1, v2, v3);
		OGLPLUS_VERIFY_SIMPLE(VertexAttrib4Nub, always);
		return {};
	}

	static
	outcome<void>
	setL(
		identity<GLdouble>,
		vertex_attrib_location va,
		GLdouble v0
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribL1d)(va.index(), v0);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribL1d, always);
		return {};
	}

	static
	outcome<void>
	setL(
		identity<GLdouble>,
		vertex_attrib_location va,
		GLdouble v0, GLdouble v1
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribL2d)(va.index(), v0, v1);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribL2d, always);
		return {};
	}

	static
	outcome<void>
	setL(
		identity<GLdouble>,
		vertex_attrib_location va,
		GLdouble v0, GLdouble v1, GLdouble v2
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribL3d)(va.index(), v0, v1, v2);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribL3d, always);
		return {};
	}

	static
	outcome<void>
	setL(
		identity<GLdouble>,
		vertex_attrib_location va,
		GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribL4d)(va.index(), v0, v1, v2, v3);
		OGLPLUS_VERIFY_SIMPLE(VertexAttribL4d, always);
		return {};
	}
};

} // namespace oglplus
