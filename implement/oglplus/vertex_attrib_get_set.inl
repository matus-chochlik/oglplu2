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
struct prog_var_get_set_ops<tag::vertex_attrib, GLshort>
{

	static
	outcome<void>
	set(
		identity<GLshort>,
		vertex_attrib_location va,
		bool ge,
		GLshort v0
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib1s)(va.index(), v0);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib1s, always); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLshort>,
		vertex_attrib_location va,
		bool ge,
		GLshort v0, GLshort v1
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib2s)(va.index(), v0, v1);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib2s, always); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLshort>,
		vertex_attrib_location va,
		bool ge,
		GLshort v0, GLshort v1, GLshort v2
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib3s)(va.index(), v0, v1, v2);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib3s, always); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLshort>,
		vertex_attrib_location va,
		bool ge,
		GLshort v0, GLshort v1, GLshort v2, GLshort v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib4s)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4s, always); }
		return {};
	}


	template <span_size_type N>
	static
	outcome<void>
	set(
		identity<GLshort[1]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLshort, N>& v
	) noexcept
	{
		assert(v.size() >= 1);
		OGLPLUS_GLFUNC(VertexAttrib1sv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib1sv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	set(
		identity<GLshort[2]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLshort, N>& v
	) noexcept
	{
		assert(v.size() >= 2);
		OGLPLUS_GLFUNC(VertexAttrib2sv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib2sv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	set(
		identity<GLshort[3]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLshort, N>& v
	) noexcept
	{
		assert(v.size() >= 3);
		OGLPLUS_GLFUNC(VertexAttrib3sv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib3sv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	set(
		identity<GLshort[4]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLshort, N>& v
	) noexcept
	{
		assert(v.size() >= 4);
		OGLPLUS_GLFUNC(VertexAttrib4sv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4sv, always); }
		return {};
	}
};

template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLint>
{

	static
	outcome<void>
	setI(
		identity<GLint>,
		vertex_attrib_location va,
		bool ge,
		GLint v0
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI1i)(va.index(), v0);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI1i, always); }
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLint>,
		vertex_attrib_location va,
		bool ge,
		GLint v0, GLint v1
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI2i)(va.index(), v0, v1);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI2i, always); }
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLint>,
		vertex_attrib_location va,
		bool ge,
		GLint v0, GLint v1, GLint v2
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI3i)(va.index(), v0, v1, v2);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI3i, always); }
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLint>,
		vertex_attrib_location va,
		bool ge,
		GLint v0, GLint v1, GLint v2, GLint v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI4i)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI4i, always); }
		return {};
	}


	template <span_size_type N>
	static
	outcome<void>
	setI(
		identity<GLint[1]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLint, N>& v
	) noexcept
	{
		assert(v.size() >= 1);
		OGLPLUS_GLFUNC(VertexAttribI1iv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI1iv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	setI(
		identity<GLint[2]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLint, N>& v
	) noexcept
	{
		assert(v.size() >= 2);
		OGLPLUS_GLFUNC(VertexAttribI2iv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI2iv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	setI(
		identity<GLint[3]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLint, N>& v
	) noexcept
	{
		assert(v.size() >= 3);
		OGLPLUS_GLFUNC(VertexAttribI3iv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI3iv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	setI(
		identity<GLint[4]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLint, N>& v
	) noexcept
	{
		assert(v.size() >= 4);
		OGLPLUS_GLFUNC(VertexAttribI4iv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI4iv, always); }
		return {};
	}
};

template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLuint>
{

	static
	outcome<void>
	setI(
		identity<GLuint>,
		vertex_attrib_location va,
		bool ge,
		GLuint v0
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI1ui)(va.index(), v0);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI1ui, always); }
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLuint>,
		vertex_attrib_location va,
		bool ge,
		GLuint v0, GLuint v1
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI2ui)(va.index(), v0, v1);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI2ui, always); }
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLuint>,
		vertex_attrib_location va,
		bool ge,
		GLuint v0, GLuint v1, GLuint v2
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI3ui)(va.index(), v0, v1, v2);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI3ui, always); }
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLuint>,
		vertex_attrib_location va,
		bool ge,
		GLuint v0, GLuint v1, GLuint v2, GLuint v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribI4ui)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI4ui, always); }
		return {};
	}


	template <span_size_type N>
	static
	outcome<void>
	setI(
		identity<GLuint[1]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLuint, N>& v
	) noexcept
	{
		assert(v.size() >= 1);
		OGLPLUS_GLFUNC(VertexAttribI1uiv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI1uiv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	setI(
		identity<GLuint[2]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLuint, N>& v
	) noexcept
	{
		assert(v.size() >= 2);
		OGLPLUS_GLFUNC(VertexAttribI2uiv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI2uiv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	setI(
		identity<GLuint[3]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLuint, N>& v
	) noexcept
	{
		assert(v.size() >= 3);
		OGLPLUS_GLFUNC(VertexAttribI3uiv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI3uiv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	setI(
		identity<GLuint[4]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLuint, N>& v
	) noexcept
	{
		assert(v.size() >= 4);
		OGLPLUS_GLFUNC(VertexAttribI4uiv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI4uiv, always); }
		return {};
	}
};

template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLfloat>
{

	static
	outcome<void>
	set(
		identity<GLfloat>,
		vertex_attrib_location va,
		bool ge,
		GLfloat v0
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib1f)(va.index(), v0);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib1f, always); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		vertex_attrib_location va,
		bool ge,
		GLfloat v0, GLfloat v1
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib2f)(va.index(), v0, v1);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib2f, always); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		vertex_attrib_location va,
		bool ge,
		GLfloat v0, GLfloat v1, GLfloat v2
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib3f)(va.index(), v0, v1, v2);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib3f, always); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		vertex_attrib_location va,
		bool ge,
		GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib4f)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4f, always); }
		return {};
	}


	template <span_size_type N>
	static
	outcome<void>
	set(
		identity<GLfloat[1]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(v.size() >= 1);
		OGLPLUS_GLFUNC(VertexAttrib1fv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib1fv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	set(
		identity<GLfloat[2]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(v.size() >= 2);
		OGLPLUS_GLFUNC(VertexAttrib2fv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib2fv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	set(
		identity<GLfloat[3]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(v.size() >= 3);
		OGLPLUS_GLFUNC(VertexAttrib3fv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib3fv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	set(
		identity<GLfloat[4]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(v.size() >= 4);
		OGLPLUS_GLFUNC(VertexAttrib4fv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4fv, always); }
		return {};
	}
};

template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLdouble>
{

	static
	outcome<void>
	set(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib1d)(va.index(), v0);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib1d, always); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0, GLdouble v1
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib2d)(va.index(), v0, v1);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib2d, always); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0, GLdouble v1, GLdouble v2
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib3d)(va.index(), v0, v1, v2);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib3d, always); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib4d)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4d, always); }
		return {};
	}


	template <span_size_type N>
	static
	outcome<void>
	set(
		identity<GLdouble[1]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLdouble, N>& v
	) noexcept
	{
		assert(v.size() >= 1);
		OGLPLUS_GLFUNC(VertexAttrib1dv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib1dv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	set(
		identity<GLdouble[2]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLdouble, N>& v
	) noexcept
	{
		assert(v.size() >= 2);
		OGLPLUS_GLFUNC(VertexAttrib2dv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib2dv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	set(
		identity<GLdouble[3]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLdouble, N>& v
	) noexcept
	{
		assert(v.size() >= 3);
		OGLPLUS_GLFUNC(VertexAttrib3dv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib3dv, always); }
		return {};
	}

	template <span_size_type N>
	static
	outcome<void>
	set(
		identity<GLdouble[4]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLdouble, N>& v
	) noexcept
	{
		assert(v.size() >= 4);
		OGLPLUS_GLFUNC(VertexAttrib4dv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4dv, always); }
		return {};
	}

	static
	outcome<void>
	setL(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribL1d)(va.index(), v0);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribL1d, always); }
		return {};
	}

	static
	outcome<void>
	setL(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0, GLdouble v1
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribL2d)(va.index(), v0, v1);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribL2d, always); }
		return {};
	}

	static
	outcome<void>
	setL(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0, GLdouble v1, GLdouble v2
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribL3d)(va.index(), v0, v1, v2);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribL3d, always); }
		return {};
	}

	static
	outcome<void>
	setL(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttribL4d)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribL4d, always); }
		return {};
	}
};

template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLubyte>
{

	static
	outcome<void>
	setN(
		identity<GLubyte>,
		vertex_attrib_location va,
		bool ge,
		GLubyte v0, GLubyte v1, GLubyte v2, GLubyte v3
	) noexcept
	{
		OGLPLUS_GLFUNC(VertexAttrib4Nub)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4Nub, always); }
		return {};
	}
};

} // namespace oglplus
