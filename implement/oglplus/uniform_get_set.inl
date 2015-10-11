//  File implement/oglplus/uniform_get_set.inl
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
struct prog_var_get_set_ops<tag::uniform>
{

	static
	outcome<void>
	set(
		identity<GLint>,
		uniform_location u,
		GLint v0
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform1i)(u.location(), v0);
		OGLPLUS_VERIFY_SIMPLE(Uniform1i, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		uniform_location u,
		GLint v0, GLint v1
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform2i)(u.location(), v0, v1);
		OGLPLUS_VERIFY_SIMPLE(Uniform2i, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		uniform_location u,
		GLint v0, GLint v1, GLint v2
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform3i)(u.location(), v0, v1, v2);
		OGLPLUS_VERIFY_SIMPLE(Uniform3i, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		uniform_location u,
		GLint v0, GLint v1, GLint v2, GLint v3
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform4i)(u.location(), v0, v1, v2, v3);
		OGLPLUS_VERIFY_SIMPLE(Uniform4i, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		std::integral_constant<int, 1>,
		uniform_location u,
		GLsizei count,
		const array_view<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(1*count));
		OGLPLUS_GLFUNC(Uniform1iv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform1iv, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		std::integral_constant<int, 2>,
		uniform_location u,
		GLsizei count,
		const array_view<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(2*count));
		OGLPLUS_GLFUNC(Uniform2iv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform2iv, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		std::integral_constant<int, 3>,
		uniform_location u,
		GLsizei count,
		const array_view<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(3*count));
		OGLPLUS_GLFUNC(Uniform3iv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform3iv, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		std::integral_constant<int, 4>,
		uniform_location u,
		GLsizei count,
		const array_view<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(4*count));
		OGLPLUS_GLFUNC(Uniform4iv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform4iv, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		uniform_location u,
		GLuint v0
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform1ui)(u.location(), v0);
		OGLPLUS_VERIFY_SIMPLE(Uniform1ui, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		uniform_location u,
		GLuint v0, GLuint v1
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform2ui)(u.location(), v0, v1);
		OGLPLUS_VERIFY_SIMPLE(Uniform2ui, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		uniform_location u,
		GLuint v0, GLuint v1, GLuint v2
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform3ui)(u.location(), v0, v1, v2);
		OGLPLUS_VERIFY_SIMPLE(Uniform3ui, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		uniform_location u,
		GLuint v0, GLuint v1, GLuint v2, GLuint v3
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform4ui)(u.location(), v0, v1, v2, v3);
		OGLPLUS_VERIFY_SIMPLE(Uniform4ui, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		std::integral_constant<int, 1>,
		uniform_location u,
		GLsizei count,
		const array_view<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(1*count));
		OGLPLUS_GLFUNC(Uniform1uiv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform1uiv, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		std::integral_constant<int, 2>,
		uniform_location u,
		GLsizei count,
		const array_view<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(2*count));
		OGLPLUS_GLFUNC(Uniform2uiv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform2uiv, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		std::integral_constant<int, 3>,
		uniform_location u,
		GLsizei count,
		const array_view<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(3*count));
		OGLPLUS_GLFUNC(Uniform3uiv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform3uiv, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		std::integral_constant<int, 4>,
		uniform_location u,
		GLsizei count,
		const array_view<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(4*count));
		OGLPLUS_GLFUNC(Uniform4uiv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform4uiv, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		uniform_location u,
		GLfloat v0
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform1f)(u.location(), v0);
		OGLPLUS_VERIFY_SIMPLE(Uniform1f, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		uniform_location u,
		GLfloat v0, GLfloat v1
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform2f)(u.location(), v0, v1);
		OGLPLUS_VERIFY_SIMPLE(Uniform2f, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		uniform_location u,
		GLfloat v0, GLfloat v1, GLfloat v2
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform3f)(u.location(), v0, v1, v2);
		OGLPLUS_VERIFY_SIMPLE(Uniform3f, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		uniform_location u,
		GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform4f)(u.location(), v0, v1, v2, v3);
		OGLPLUS_VERIFY_SIMPLE(Uniform4f, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		std::integral_constant<int, 1>,
		uniform_location u,
		GLsizei count,
		const array_view<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(1*count));
		OGLPLUS_GLFUNC(Uniform1fv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform1fv, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		std::integral_constant<int, 2>,
		uniform_location u,
		GLsizei count,
		const array_view<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(2*count));
		OGLPLUS_GLFUNC(Uniform2fv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform2fv, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		std::integral_constant<int, 3>,
		uniform_location u,
		GLsizei count,
		const array_view<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(3*count));
		OGLPLUS_GLFUNC(Uniform3fv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform3fv, always);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		std::integral_constant<int, 4>,
		uniform_location u,
		GLsizei count,
		const array_view<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(4*count));
		OGLPLUS_GLFUNC(Uniform4fv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform4fv, always);
		return {};
	}

#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shader_objects)

	static
	outcome<void>
	set(
		identity<GLint>,
		program_uniform_location pu,
		GLint v0
	) noexcept
	{
		OGLPLUS_GLFUNC(ProgramUniform1i)(
			get_raw_name(pu.program()),
			pu.location(),
			v0
		);
		OGLPLUS_VERIFY(
			ProgramUniform1iv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		program_uniform_location pu,
		GLint v0, GLint v1
	) noexcept
	{
		OGLPLUS_GLFUNC(ProgramUniform2i)(
			get_raw_name(pu.program()),
			pu.location(),
			v0, v1
		);
		OGLPLUS_VERIFY(
			ProgramUniform2iv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		program_uniform_location pu,
		GLint v0, GLint v1, GLint v2
	) noexcept
	{
		OGLPLUS_GLFUNC(ProgramUniform3i)(
			get_raw_name(pu.program()),
			pu.location(),
			v0, v1, v2
		);
		OGLPLUS_VERIFY(
			ProgramUniform3iv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		program_uniform_location pu,
		GLint v0, GLint v1, GLint v2, GLint v3
	) noexcept
	{
		OGLPLUS_GLFUNC(ProgramUniform4i)(
			get_raw_name(pu.program()),
			pu.location(),
			v0, v1, v2, v3
		);
		OGLPLUS_VERIFY(
			ProgramUniform4iv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		std::integral_constant<int, 1>,
		program_uniform_location pu,
		GLsizei count,
		const array_view<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(1*count));
		OGLPLUS_GLFUNC(ProgramUniform1iv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform1iv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		std::integral_constant<int, 2>,
		program_uniform_location pu,
		GLsizei count,
		const array_view<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(2*count));
		OGLPLUS_GLFUNC(ProgramUniform2iv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform2iv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		std::integral_constant<int, 3>,
		program_uniform_location pu,
		GLsizei count,
		const array_view<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(3*count));
		OGLPLUS_GLFUNC(ProgramUniform3iv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform3iv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint>,
		std::integral_constant<int, 4>,
		program_uniform_location pu,
		GLsizei count,
		const array_view<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(4*count));
		OGLPLUS_GLFUNC(ProgramUniform4iv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform4iv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		program_uniform_location pu,
		GLuint v0
	) noexcept
	{
		OGLPLUS_GLFUNC(ProgramUniform1ui)(
			get_raw_name(pu.program()),
			pu.location(),
			v0
		);
		OGLPLUS_VERIFY(
			ProgramUniform1uiv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		program_uniform_location pu,
		GLuint v0, GLuint v1
	) noexcept
	{
		OGLPLUS_GLFUNC(ProgramUniform2ui)(
			get_raw_name(pu.program()),
			pu.location(),
			v0, v1
		);
		OGLPLUS_VERIFY(
			ProgramUniform2uiv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		program_uniform_location pu,
		GLuint v0, GLuint v1, GLuint v2
	) noexcept
	{
		OGLPLUS_GLFUNC(ProgramUniform3ui)(
			get_raw_name(pu.program()),
			pu.location(),
			v0, v1, v2
		);
		OGLPLUS_VERIFY(
			ProgramUniform3uiv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		program_uniform_location pu,
		GLuint v0, GLuint v1, GLuint v2, GLuint v3
	) noexcept
	{
		OGLPLUS_GLFUNC(ProgramUniform4ui)(
			get_raw_name(pu.program()),
			pu.location(),
			v0, v1, v2, v3
		);
		OGLPLUS_VERIFY(
			ProgramUniform4uiv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		std::integral_constant<int, 1>,
		program_uniform_location pu,
		GLsizei count,
		const array_view<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(1*count));
		OGLPLUS_GLFUNC(ProgramUniform1uiv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform1uiv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		std::integral_constant<int, 2>,
		program_uniform_location pu,
		GLsizei count,
		const array_view<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(2*count));
		OGLPLUS_GLFUNC(ProgramUniform2uiv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform2uiv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		std::integral_constant<int, 3>,
		program_uniform_location pu,
		GLsizei count,
		const array_view<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(3*count));
		OGLPLUS_GLFUNC(ProgramUniform3uiv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform3uiv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint>,
		std::integral_constant<int, 4>,
		program_uniform_location pu,
		GLsizei count,
		const array_view<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(4*count));
		OGLPLUS_GLFUNC(ProgramUniform4uiv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform4uiv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		program_uniform_location pu,
		GLfloat v0
	) noexcept
	{
		OGLPLUS_GLFUNC(ProgramUniform1f)(
			get_raw_name(pu.program()),
			pu.location(),
			v0
		);
		OGLPLUS_VERIFY(
			ProgramUniform1fv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		program_uniform_location pu,
		GLfloat v0, GLfloat v1
	) noexcept
	{
		OGLPLUS_GLFUNC(ProgramUniform2f)(
			get_raw_name(pu.program()),
			pu.location(),
			v0, v1
		);
		OGLPLUS_VERIFY(
			ProgramUniform2fv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		program_uniform_location pu,
		GLfloat v0, GLfloat v1, GLfloat v2
	) noexcept
	{
		OGLPLUS_GLFUNC(ProgramUniform3f)(
			get_raw_name(pu.program()),
			pu.location(),
			v0, v1, v2
		);
		OGLPLUS_VERIFY(
			ProgramUniform3fv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		program_uniform_location pu,
		GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3
	) noexcept
	{
		OGLPLUS_GLFUNC(ProgramUniform4f)(
			get_raw_name(pu.program()),
			pu.location(),
			v0, v1, v2, v3
		);
		OGLPLUS_VERIFY(
			ProgramUniform4fv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		std::integral_constant<int, 1>,
		program_uniform_location pu,
		GLsizei count,
		const array_view<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(1*count));
		OGLPLUS_GLFUNC(ProgramUniform1fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform1fv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		std::integral_constant<int, 2>,
		program_uniform_location pu,
		GLsizei count,
		const array_view<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(2*count));
		OGLPLUS_GLFUNC(ProgramUniform2fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform2fv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		std::integral_constant<int, 3>,
		program_uniform_location pu,
		GLsizei count,
		const array_view<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(3*count));
		OGLPLUS_GLFUNC(ProgramUniform3fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform3fv,
			gl_object(pu.program()),
			always
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat>,
		std::integral_constant<int, 4>,
		program_uniform_location pu,
		GLsizei count,
		const array_view<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= std::size_t(4*count));
		OGLPLUS_GLFUNC(ProgramUniform4fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform4fv,
			gl_object(pu.program()),
			always
		);
		return {};
	}
#endif
};

} // namespace oglplus
