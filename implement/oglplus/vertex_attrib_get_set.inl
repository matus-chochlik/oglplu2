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

#if defined(GL_VERSION_3_0)
template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLshort> {

	static
	outcome<void>
	set(
		identity<GLshort>,
		vertex_attrib_location va,
		bool ge,
		GLshort v0
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib1s)(va.index(), v0);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib1s, debug); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLshort>,
		vertex_attrib_location va,
		bool ge,
		GLshort v0, GLshort v1
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib2s)(va.index(), v0, v1);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib2s, debug); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLshort>,
		vertex_attrib_location va,
		bool ge,
		GLshort v0, GLshort v1, GLshort v2
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib3s)(va.index(), v0, v1, v2);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib3s, debug); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLshort>,
		vertex_attrib_location va,
		bool ge,
		GLshort v0, GLshort v1, GLshort v2, GLshort v3
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib4s)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4s, debug); }
		return {};
	}


	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLshort[1]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLshort, N>& v
	) noexcept {
		assert(v.size() >= 1);
		OGLPLUS_GLFUNC(VertexAttrib1sv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib1sv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLshort[2]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLshort, N>& v
	) noexcept {
		assert(v.size() >= 2);
		OGLPLUS_GLFUNC(VertexAttrib2sv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib2sv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLshort[3]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLshort, N>& v
	) noexcept {
		assert(v.size() >= 3);
		OGLPLUS_GLFUNC(VertexAttrib3sv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib3sv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLshort[4]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLshort, N>& v
	) noexcept {
		assert(v.size() >= 4);
		OGLPLUS_GLFUNC(VertexAttrib4sv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4sv, debug); }
		return {};
	}
};
#endif // GL_VERSION_3_0

#if defined(GL_VERSION_3_0)
template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLint> {

	static
	outcome<void>
	setI(
		identity<GLint>,
		vertex_attrib_location va,
		bool ge,
		GLint v0
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttribI1i)(va.index(), v0);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI1i, debug); }
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLint>,
		vertex_attrib_location va,
		bool ge,
		GLint v0, GLint v1
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttribI2i)(va.index(), v0, v1);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI2i, debug); }
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLint>,
		vertex_attrib_location va,
		bool ge,
		GLint v0, GLint v1, GLint v2
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttribI3i)(va.index(), v0, v1, v2);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI3i, debug); }
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLint>,
		vertex_attrib_location va,
		bool ge,
		GLint v0, GLint v1, GLint v2, GLint v3
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttribI4i)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI4i, debug); }
		return {};
	}


	template <span_size_t N>
	static
	outcome<void>
	setI(
		identity<GLint[1]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLint, N>& v
	) noexcept {
		assert(v.size() >= 1);
		OGLPLUS_GLFUNC(VertexAttribI1iv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI1iv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	setI(
		identity<GLint[2]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLint, N>& v
	) noexcept {
		assert(v.size() >= 2);
		OGLPLUS_GLFUNC(VertexAttribI2iv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI2iv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	setI(
		identity<GLint[3]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLint, N>& v
	) noexcept {
		assert(v.size() >= 3);
		OGLPLUS_GLFUNC(VertexAttribI3iv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI3iv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	setI(
		identity<GLint[4]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLint, N>& v
	) noexcept {
		assert(v.size() >= 4);
		OGLPLUS_GLFUNC(VertexAttribI4iv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI4iv, debug); }
		return {};
	}
};
#endif // GL_VERSION_3_0

#if defined(GL_VERSION_3_0)
template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLuint> {

	static
	outcome<void>
	setI(
		identity<GLuint>,
		vertex_attrib_location va,
		bool ge,
		GLuint v0
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttribI1ui)(va.index(), v0);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI1ui, debug); }
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLuint>,
		vertex_attrib_location va,
		bool ge,
		GLuint v0, GLuint v1
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttribI2ui)(va.index(), v0, v1);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI2ui, debug); }
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLuint>,
		vertex_attrib_location va,
		bool ge,
		GLuint v0, GLuint v1, GLuint v2
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttribI3ui)(va.index(), v0, v1, v2);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI3ui, debug); }
		return {};
	}

	static
	outcome<void>
	setI(
		identity<GLuint>,
		vertex_attrib_location va,
		bool ge,
		GLuint v0, GLuint v1, GLuint v2, GLuint v3
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttribI4ui)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI4ui, debug); }
		return {};
	}


	template <span_size_t N>
	static
	outcome<void>
	setI(
		identity<GLuint[1]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLuint, N>& v
	) noexcept {
		assert(v.size() >= 1);
		OGLPLUS_GLFUNC(VertexAttribI1uiv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI1uiv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	setI(
		identity<GLuint[2]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLuint, N>& v
	) noexcept {
		assert(v.size() >= 2);
		OGLPLUS_GLFUNC(VertexAttribI2uiv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI2uiv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	setI(
		identity<GLuint[3]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLuint, N>& v
	) noexcept {
		assert(v.size() >= 3);
		OGLPLUS_GLFUNC(VertexAttribI3uiv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI3uiv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	setI(
		identity<GLuint[4]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLuint, N>& v
	) noexcept {
		assert(v.size() >= 4);
		OGLPLUS_GLFUNC(VertexAttribI4uiv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribI4uiv, debug); }
		return {};
	}
};
#endif // GL_VERSION_3_0

template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLfloat> {

	static
	outcome<void>
	set(
		identity<GLfloat>,
		vertex_attrib_location va,
		bool ge,
		GLfloat v0
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib1f)(va.index(), v0);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib1f, debug); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		vertex_attrib_location va,
		bool ge,
		GLfloat v0, GLfloat v1
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib2f)(va.index(), v0, v1);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib2f, debug); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		vertex_attrib_location va,
		bool ge,
		GLfloat v0, GLfloat v1, GLfloat v2
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib3f)(va.index(), v0, v1, v2);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib3f, debug); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		vertex_attrib_location va,
		bool ge,
		GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib4f)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4f, debug); }
		return {};
	}


	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[1]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLfloat, N>& v
	) noexcept {
		assert(v.size() >= 1);
		OGLPLUS_GLFUNC(VertexAttrib1fv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib1fv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[2]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLfloat, N>& v
	) noexcept {
		assert(v.size() >= 2);
		OGLPLUS_GLFUNC(VertexAttrib2fv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib2fv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[3]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLfloat, N>& v
	) noexcept {
		assert(v.size() >= 3);
		OGLPLUS_GLFUNC(VertexAttrib3fv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib3fv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[4]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLfloat, N>& v
	) noexcept {
		assert(v.size() >= 4);
		OGLPLUS_GLFUNC(VertexAttrib4fv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4fv, debug); }
		return {};
	}
};

#if defined(GL_VERSION_3_0)
template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLdouble> {

	static
	outcome<void>
	set(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib1d)(va.index(), v0);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib1d, debug); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0, GLdouble v1
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib2d)(va.index(), v0, v1);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib2d, debug); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0, GLdouble v1, GLdouble v2
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib3d)(va.index(), v0, v1, v2);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib3d, debug); }
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib4d)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4d, debug); }
		return {};
	}


	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLdouble[1]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLdouble, N>& v
	) noexcept {
		assert(v.size() >= 1);
		OGLPLUS_GLFUNC(VertexAttrib1dv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib1dv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLdouble[2]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLdouble, N>& v
	) noexcept {
		assert(v.size() >= 2);
		OGLPLUS_GLFUNC(VertexAttrib2dv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib2dv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLdouble[3]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLdouble, N>& v
	) noexcept {
		assert(v.size() >= 3);
		OGLPLUS_GLFUNC(VertexAttrib3dv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib3dv, debug); }
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLdouble[4]>,
		vertex_attrib_location va,
		bool ge,
		const span<const GLdouble, N>& v
	) noexcept {
		assert(v.size() >= 4);
		OGLPLUS_GLFUNC(VertexAttrib4dv)(va.index(), v.data());
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4dv, debug); }
		return {};
	}
#if defined(GL_VERSION_4_1)

	static
	outcome<void>
	setL(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttribL1d)(va.index(), v0);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribL1d, debug); }
		return {};
	}

	static
	outcome<void>
	setL(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0, GLdouble v1
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttribL2d)(va.index(), v0, v1);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribL2d, debug); }
		return {};
	}

	static
	outcome<void>
	setL(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0, GLdouble v1, GLdouble v2
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttribL3d)(va.index(), v0, v1, v2);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribL3d, debug); }
		return {};
	}

	static
	outcome<void>
	setL(
		identity<GLdouble>,
		vertex_attrib_location va,
		bool ge,
		GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttribL4d)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttribL4d, debug); }
		return {};
	}
#endif // GL_VERSION_4_1
};
#endif // GL_VERSION_3_0

#if defined(GL_VERSION_3_0)
template <>
struct prog_var_get_set_ops<tag::vertex_attrib, GLubyte> {

	static
	outcome<void>
	setN(
		identity<GLubyte>,
		vertex_attrib_location va,
		bool ge,
		GLubyte v0, GLubyte v1, GLubyte v2, GLubyte v3
	) noexcept {
		OGLPLUS_GLFUNC(VertexAttrib4Nub)(va.index(), v0, v1, v2, v3);
		if(ge) { OGLPLUS_VERIFY_SIMPLE(VertexAttrib4Nub, debug); }
		return {};
	}
};
#endif // GL_VERSION_3_0

} // namespace oglplus
