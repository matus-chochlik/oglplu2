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
struct prog_var_get_set_ops<tag::uniform, GLint>
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
		OGLPLUS_VERIFY_SIMPLE(Uniform1i, debug);
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
		OGLPLUS_VERIFY_SIMPLE(Uniform2i, debug);
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
		OGLPLUS_VERIFY_SIMPLE(Uniform3i, debug);
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
		OGLPLUS_VERIFY_SIMPLE(Uniform4i, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint[1]>,
		uniform_location u,
		GLsizei count,
		const span<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(1*count));
		OGLPLUS_GLFUNC(Uniform1iv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform1iv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint[2]>,
		uniform_location u,
		GLsizei count,
		const span<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(2*count));
		OGLPLUS_GLFUNC(Uniform2iv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform2iv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint[3]>,
		uniform_location u,
		GLsizei count,
		const span<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(3*count));
		OGLPLUS_GLFUNC(Uniform3iv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform3iv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint[4]>,
		uniform_location u,
		GLsizei count,
		const span<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(4*count));
		OGLPLUS_GLFUNC(Uniform4iv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform4iv, debug);
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
			ProgramUniform1i,
			gl_object(pu.program()),
			debug
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
			ProgramUniform2i,
			gl_object(pu.program()),
			debug
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
			ProgramUniform3i,
			gl_object(pu.program()),
			debug
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
			ProgramUniform4i,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint[1]>,
		program_uniform_location pu,
		GLsizei count,
		const span<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(1*count));
		OGLPLUS_GLFUNC(ProgramUniform1iv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform1iv,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint[2]>,
		program_uniform_location pu,
		GLsizei count,
		const span<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(2*count));
		OGLPLUS_GLFUNC(ProgramUniform2iv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform2iv,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint[3]>,
		program_uniform_location pu,
		GLsizei count,
		const span<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(3*count));
		OGLPLUS_GLFUNC(ProgramUniform3iv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform3iv,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLint[4]>,
		program_uniform_location pu,
		GLsizei count,
		const span<const GLint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(4*count));
		OGLPLUS_GLFUNC(ProgramUniform4iv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform4iv,
			gl_object(pu.program()),
			debug
		);
		return {};
	}
#endif
};

template <>
struct prog_var_get_set_ops<tag::uniform, GLuint>
{

	static
	outcome<void>
	set(
		identity<GLuint>,
		uniform_location u,
		GLuint v0
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform1ui)(u.location(), v0);
		OGLPLUS_VERIFY_SIMPLE(Uniform1ui, debug);
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
		OGLPLUS_VERIFY_SIMPLE(Uniform2ui, debug);
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
		OGLPLUS_VERIFY_SIMPLE(Uniform3ui, debug);
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
		OGLPLUS_VERIFY_SIMPLE(Uniform4ui, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint[1]>,
		uniform_location u,
		GLsizei count,
		const span<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(1*count));
		OGLPLUS_GLFUNC(Uniform1uiv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform1uiv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint[2]>,
		uniform_location u,
		GLsizei count,
		const span<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(2*count));
		OGLPLUS_GLFUNC(Uniform2uiv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform2uiv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint[3]>,
		uniform_location u,
		GLsizei count,
		const span<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(3*count));
		OGLPLUS_GLFUNC(Uniform3uiv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform3uiv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint[4]>,
		uniform_location u,
		GLsizei count,
		const span<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(4*count));
		OGLPLUS_GLFUNC(Uniform4uiv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform4uiv, debug);
		return {};
	}

#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shader_objects)

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
			ProgramUniform1ui,
			gl_object(pu.program()),
			debug
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
			ProgramUniform2ui,
			gl_object(pu.program()),
			debug
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
			ProgramUniform3ui,
			gl_object(pu.program()),
			debug
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
			ProgramUniform4ui,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint[1]>,
		program_uniform_location pu,
		GLsizei count,
		const span<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(1*count));
		OGLPLUS_GLFUNC(ProgramUniform1uiv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform1uiv,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint[2]>,
		program_uniform_location pu,
		GLsizei count,
		const span<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(2*count));
		OGLPLUS_GLFUNC(ProgramUniform2uiv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform2uiv,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint[3]>,
		program_uniform_location pu,
		GLsizei count,
		const span<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(3*count));
		OGLPLUS_GLFUNC(ProgramUniform3uiv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform3uiv,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLuint[4]>,
		program_uniform_location pu,
		GLsizei count,
		const span<const GLuint>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(4*count));
		OGLPLUS_GLFUNC(ProgramUniform4uiv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform4uiv,
			gl_object(pu.program()),
			debug
		);
		return {};
	}
#endif
};

template <>
struct prog_var_get_set_ops<tag::uniform, GLfloat>
{

	static
	outcome<void>
	set(
		identity<GLfloat>,
		uniform_location u,
		GLfloat v0
	) noexcept
	{
		OGLPLUS_GLFUNC(Uniform1f)(u.location(), v0);
		OGLPLUS_VERIFY_SIMPLE(Uniform1f, debug);
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
		OGLPLUS_VERIFY_SIMPLE(Uniform2f, debug);
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
		OGLPLUS_VERIFY_SIMPLE(Uniform3f, debug);
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
		OGLPLUS_VERIFY_SIMPLE(Uniform4f, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[1]>,
		uniform_location u,
		GLsizei count,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(1*count));
		OGLPLUS_GLFUNC(Uniform1fv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform1fv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[2]>,
		uniform_location u,
		GLsizei count,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(2*count));
		OGLPLUS_GLFUNC(Uniform2fv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform2fv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[3]>,
		uniform_location u,
		GLsizei count,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(3*count));
		OGLPLUS_GLFUNC(Uniform3fv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform3fv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[4]>,
		uniform_location u,
		GLsizei count,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(4*count));
		OGLPLUS_GLFUNC(Uniform4fv)(u.location(), count, v.data());
		OGLPLUS_VERIFY_SIMPLE(Uniform4fv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[2][2]>,
		uniform_location u,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(2*2*count));
		OGLPLUS_GLFUNC(UniformMatrix2fv)(u.location(), count, transpose, v.data());
		OGLPLUS_VERIFY_SIMPLE(UniformMatrix2fv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[2][3]>,
		uniform_location u,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(2*3*count));
		OGLPLUS_GLFUNC(UniformMatrix2x3fv)(u.location(), count, transpose, v.data());
		OGLPLUS_VERIFY_SIMPLE(UniformMatrix2x3fv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[2][4]>,
		uniform_location u,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(2*4*count));
		OGLPLUS_GLFUNC(UniformMatrix2x4fv)(u.location(), count, transpose, v.data());
		OGLPLUS_VERIFY_SIMPLE(UniformMatrix2x4fv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[3][2]>,
		uniform_location u,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(3*2*count));
		OGLPLUS_GLFUNC(UniformMatrix3x2fv)(u.location(), count, transpose, v.data());
		OGLPLUS_VERIFY_SIMPLE(UniformMatrix3x2fv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[3][3]>,
		uniform_location u,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(3*3*count));
		OGLPLUS_GLFUNC(UniformMatrix3fv)(u.location(), count, transpose, v.data());
		OGLPLUS_VERIFY_SIMPLE(UniformMatrix3fv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[3][4]>,
		uniform_location u,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(3*4*count));
		OGLPLUS_GLFUNC(UniformMatrix3x4fv)(u.location(), count, transpose, v.data());
		OGLPLUS_VERIFY_SIMPLE(UniformMatrix3x4fv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[4][2]>,
		uniform_location u,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(4*2*count));
		OGLPLUS_GLFUNC(UniformMatrix4x2fv)(u.location(), count, transpose, v.data());
		OGLPLUS_VERIFY_SIMPLE(UniformMatrix4x2fv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[4][3]>,
		uniform_location u,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(4*3*count));
		OGLPLUS_GLFUNC(UniformMatrix4x3fv)(u.location(), count, transpose, v.data());
		OGLPLUS_VERIFY_SIMPLE(UniformMatrix4x3fv, debug);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[4][4]>,
		uniform_location u,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(4*4*count));
		OGLPLUS_GLFUNC(UniformMatrix4fv)(u.location(), count, transpose, v.data());
		OGLPLUS_VERIFY_SIMPLE(UniformMatrix4fv, debug);
		return {};
	}

#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shader_objects)

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
			ProgramUniform1f,
			gl_object(pu.program()),
			debug
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
			ProgramUniform2f,
			gl_object(pu.program()),
			debug
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
			ProgramUniform3f,
			gl_object(pu.program()),
			debug
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
			ProgramUniform4f,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[1]>,
		program_uniform_location pu,
		GLsizei count,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(1*count));
		OGLPLUS_GLFUNC(ProgramUniform1fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform1fv,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[2]>,
		program_uniform_location pu,
		GLsizei count,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(2*count));
		OGLPLUS_GLFUNC(ProgramUniform2fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform2fv,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[3]>,
		program_uniform_location pu,
		GLsizei count,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(3*count));
		OGLPLUS_GLFUNC(ProgramUniform3fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform3fv,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	static
	outcome<void>
	set(
		identity<GLfloat[4]>,
		program_uniform_location pu,
		GLsizei count,
		const span<const GLfloat>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(4*count));
		OGLPLUS_GLFUNC(ProgramUniform4fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			v.data()
		);
		OGLPLUS_VERIFY(
			ProgramUniform4fv,
			gl_object(pu.program()),
			debug
		);
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[2][2]>,
		program_uniform_location pu,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(2*2*count));
		OGLPLUS_GLFUNC(ProgramUniformMatrix2fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			transpose,
			v.data()
		);
		OGLPLUS_VERIFY_SIMPLE(ProgramUniformMatrix2fv, debug);
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[2][3]>,
		program_uniform_location pu,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(2*3*count));
		OGLPLUS_GLFUNC(ProgramUniformMatrix2x3fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			transpose,
			v.data()
		);
		OGLPLUS_VERIFY_SIMPLE(ProgramUniformMatrix2x3fv, debug);
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[2][4]>,
		program_uniform_location pu,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(2*4*count));
		OGLPLUS_GLFUNC(ProgramUniformMatrix2x4fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			transpose,
			v.data()
		);
		OGLPLUS_VERIFY_SIMPLE(ProgramUniformMatrix2x4fv, debug);
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[3][2]>,
		program_uniform_location pu,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(3*2*count));
		OGLPLUS_GLFUNC(ProgramUniformMatrix3x2fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			transpose,
			v.data()
		);
		OGLPLUS_VERIFY_SIMPLE(ProgramUniformMatrix3x2fv, debug);
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[3][3]>,
		program_uniform_location pu,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(3*3*count));
		OGLPLUS_GLFUNC(ProgramUniformMatrix3fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			transpose,
			v.data()
		);
		OGLPLUS_VERIFY_SIMPLE(ProgramUniformMatrix3fv, debug);
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[3][4]>,
		program_uniform_location pu,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(3*4*count));
		OGLPLUS_GLFUNC(ProgramUniformMatrix3x4fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			transpose,
			v.data()
		);
		OGLPLUS_VERIFY_SIMPLE(ProgramUniformMatrix3x4fv, debug);
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[4][2]>,
		program_uniform_location pu,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(4*2*count));
		OGLPLUS_GLFUNC(ProgramUniformMatrix4x2fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			transpose,
			v.data()
		);
		OGLPLUS_VERIFY_SIMPLE(ProgramUniformMatrix4x2fv, debug);
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[4][3]>,
		program_uniform_location pu,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(4*3*count));
		OGLPLUS_GLFUNC(ProgramUniformMatrix4x3fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			transpose,
			v.data()
		);
		OGLPLUS_VERIFY_SIMPLE(ProgramUniformMatrix4x3fv, debug);
		return {};
	}

	template <span_size_t N>
	static
	outcome<void>
	set(
		identity<GLfloat[4][4]>,
		program_uniform_location pu,
		GLsizei count,
		GLboolean transpose,
		const span<const GLfloat, N>& v
	) noexcept
	{
		assert(count >= 0);
		assert(v.size() >= span_size_t(4*4*count));
		OGLPLUS_GLFUNC(ProgramUniformMatrix4fv)(
			get_raw_name(pu.program()),
			pu.location(),
			count,
			transpose,
			v.data()
		);
		OGLPLUS_VERIFY_SIMPLE(ProgramUniformMatrix4fv, debug);
		return {};
	}
#endif
};


} // namespace oglplus
