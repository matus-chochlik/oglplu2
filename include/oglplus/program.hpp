/**
 *  @file oglplus/program.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PROGRAM_1509260923_HPP
#define OGLPLUS_PROGRAM_1509260923_HPP

#include "program_name.hpp"
#include "shader_name.hpp"
#include "vertex_attrib.hpp"
#include "uniform.hpp"
#include "oper/computing.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "glsl/source_ref.hpp"
#include "utils/gl_func.hpp"
#include "utils/boolean.hpp"
#include "utils/memory_block.hpp"
#include "enum/types.hpp"

namespace oglplus {
namespace oper {

struct program_ops
{
	static
	outcome<void>
	attach_shader(program_name prog, shader_name shdr)
	noexcept;

	static
	outcome<void>
	detach_shader(program_name prog, shader_name shdr)
	noexcept;

	static
	outcome<void>
	link_program(program_name prog)
	noexcept;

	static
	outcome<void>
	report_program_link_error(program_name prog)
	noexcept;

	static
	outcome<void>
	validate_program(program_name prog)
	noexcept;

	static
	outcome<void>
	report_program_validate_error(program_name prog)
	noexcept;

	static
	outcome<void>
	use_program(program_name prog)
	noexcept;

	static
	outcome<program_name>
	current_program(void)
	noexcept;

#if defined(GL_VERSION_4_1)
	static
	outcome<void>
	program_parameter_i(
		program_name prog,
		program_parameter param,
		GLint value
	) noexcept;

	static
	outcome<void>
	program_binary_retrievable_hint(program_name prog, boolean value)
	noexcept;

	static
	outcome<void>
	program_separable(program_name prog, boolean value)
	noexcept;

	static
	outcome<GLsizei>
	get_program_binary_length(program_name prog)
	noexcept;

	static
	outcome<memory_block>
	get_program_binary(program_name prog, GLenum& format, memory_block dest)
	noexcept;

	static
	outcome<void>
	program_binary(program_name prog, GLenum format, const_memory_block binary)
	noexcept;
#endif

	static
	outcome<void>
	get_program_iv(
		program_name prog,
		program_parameter param,
		span<GLint> values
	) noexcept;

	template <typename R, typename T>
	static
	outcome<R>
	return_program_parameter_i(program_name, program_parameter parameter)
	noexcept;

	static
	outcome<boolean>
	get_program_delete_status(program_name prog)
	noexcept;

	static
	outcome<boolean>
	get_program_link_status(program_name prog)
	noexcept;

	static
	outcome<boolean>
	get_program_validate_status(program_name prog)
	noexcept;

	static
	outcome<GLsizei>
	get_program_info_log_length(program_name prog)
	noexcept;

	static
	outcome<span<char>>
	get_program_info_log(program_name prog, span<char> dest)
	noexcept;

	static
	outcome<GLuint>
	get_program_active_attributes(program_name prog)
	noexcept;

	static
	outcome<GLsizei>
	get_program_active_attribute_max_length(program_name prog)
	noexcept;

	static
	outcome<GLsizei>
	get_active_attrib(
		program_name prog,
		GLuint index,
		span<char> name,
		GLint& size,
		sl_data_type& type
	) noexcept;

	static
	outcome<GLuint>
	get_program_active_uniforms(program_name prog)
	noexcept;

	static
	outcome<GLsizei>
	get_program_active_uniform_max_length(program_name prog)
	noexcept;

	static
	outcome<GLsizei>
	get_active_uniform(
		program_name prog,
		GLuint index,
		span<char> name,
		GLint& size,
		sl_data_type& type
	) noexcept;

#if defined(GL_ACTIVE_ATOMIC_COUNTER_BUFFERS)
	static
	outcome<GLsizei>
	get_program_active_atomic_counter_buffers(program_name prog)
	noexcept;
#endif

	static
	outcome<transform_feedback_mode>
	get_program_transform_feedback_buffer_mode(program_name prog)
	noexcept;

#if defined(GL_VERSION_3_2)
	static
	outcome<GLsizei>
	get_program_geometry_vertices_out(program_name prog)
	noexcept;
#endif

#if defined(GL_VERSION_3_2)
	static
	outcome<primitive_type>
	get_program_geometry_input_type(program_name prog)
	noexcept;
#endif

#if defined(GL_VERSION_3_2)
	static
	outcome<primitive_type>
	get_program_geometry_output_type(program_name prog)
	noexcept;
#endif

#if defined(GL_VERSION_4_3)
	static
	outcome<compute_work_group_size>
	get_program_compute_work_group_size(program_name prog)
	noexcept;
#endif
	// TODO other parameters

	static
	outcome<void>
	bind_attrib_location(
		program_name prog,
		GLuint index,
		cstr_ref attr_name
	) noexcept;

	static
	outcome<void>
	bind_attrib_location(
		program_uniform_location location,
		cstr_ref attr_name
	) noexcept {
		return bind_attrib_location(
			location.program(),
			location.index(),
			attr_name
		);
	}
};

} // namespace oper

// obj_dsa_ops
template <>
struct obj_dsa_ops<tag::program>
 : obj_zero_dsa_ops<tag::program>
{
	typedef oper::program_ops _ops;

	using obj_zero_dsa_ops<tag::program>::obj_zero_dsa_ops;

	outcome<obj_dsa_ops&>
	attach(shader_name shdr)
	noexcept { return {_ops::attach_shader(*this, shdr), *this}; }

	outcome<obj_dsa_ops&>
	detach(shader_name shdr)
	noexcept { return {_ops::detach_shader(*this, shdr), *this}; }

	outcome<obj_dsa_ops&>
	link(void)
	noexcept { return {_ops::link_program(*this), *this}; }

	outcome<obj_dsa_ops&>
	validate(void)
	noexcept { return {_ops::validate_program(*this), *this}; }

	outcome<obj_dsa_ops&>
	report_link_error(void)
	noexcept { return {_ops::report_program_link_error(*this), *this}; }

	outcome<obj_dsa_ops&>
	report_validate_error(void)
	noexcept { return {_ops::report_program_validate_error(*this), *this}; }

#if defined(GL_VERSION_4_1)
	outcome<obj_dsa_ops&>
	binary_retrievable_hint(boolean value)
	noexcept {
		return {_ops::program_binary_retrievable_hint(*this, value), *this};
	}

	outcome<obj_dsa_ops&>
	separable(boolean value)
	noexcept { return {_ops::program_separable(*this, value), *this}; }

	outcome<GLsizei>
	get_binary_length(void)
	noexcept { return _ops::get_program_binary_length(*this); }

	outcome<memory_block>
	get_binary(GLenum& format, memory_block dest)
	noexcept { return _ops::get_program_binary(*this, format, dest); }

	outcome<obj_dsa_ops&>
	binary(GLenum format, memory_block dest)
	noexcept { return {_ops::program_binary(*this, format, dest), *this}; }
#endif

	outcome<boolean>
	get_delete_status(void) const
	noexcept { return _ops::get_program_delete_status(*this); }

	outcome<boolean>
	get_link_status(void) const
	noexcept { return _ops::get_program_link_status(*this); }

	outcome<boolean>
	get_validate_status(void) const
	noexcept { return _ops::get_program_validate_status(*this); }

	outcome<GLsizei>
	get_info_log_length(void) const
	noexcept { return _ops::get_program_info_log_length(*this); }

	outcome<span<char>>
	get_info_log(span<char> dest) const
	noexcept { return _ops::get_program_info_log(*this, dest); }

	outcome<GLuint>
	get_active_attributes(void) const
	noexcept { return _ops::get_program_active_attributes(*this); }

	outcome<GLsizei>
	get_active_attribute_max_length(void) const
	noexcept { return _ops::get_program_active_attribute_max_length(*this); }

	outcome<GLsizei>
	get_active_attrib(
		GLuint index,
		span<char> name,
		GLint& size,
		sl_data_type& type
	) const
	noexcept { return _ops::get_active_attrib(*this, index, name, size, type); }

	outcome<GLuint>
	get_active_uniforms(void) const
	noexcept { return _ops::get_program_active_uniforms(*this); }

	outcome<GLsizei>
	get_active_uniform_max_length(void) const
	noexcept { return _ops::get_program_active_uniform_max_length(*this); }

	outcome<GLsizei>
	get_active_uniform(
		GLuint index,
		span<char> name,
		GLint& size,
		sl_data_type& type
	) const
	noexcept {
		return _ops::get_active_uniform(*this, index, name, size, type);
	}

#if defined(GL_ACTIVE_ATOMIC_COUNTER_BUFFERS)
	outcome<GLsizei>
	get_active_atomic_counter_buffers(void) const
	noexcept { return _ops::get_program_active_atomic_counter_buffers(*this); }
#endif

	outcome<transform_feedback_mode>
	get_transform_feedback_buffer_mode(void) const
	noexcept { return _ops::get_program_transform_feedback_buffer_mode(*this); }

#if defined(GL_VERSION_3_2)
	outcome<GLsizei>
	get_geometry_vertices_out(void) const
	noexcept { return _ops::get_program_geometry_vertices_out(*this); }
#endif

#if defined(GL_VERSION_3_2)
	outcome<primitive_type>
	get_geometry_input_type(void) const
	noexcept { return _ops::get_program_geometry_input_type(*this); }
#endif

#if defined(GL_VERSION_3_2)
	outcome<primitive_type>
	get_geometry_output_type(void) const
	noexcept { return _ops::get_program_geometry_output_type(*this); }
#endif

#if defined(GL_VERSION_4_3)
	outcome<oper::compute_work_group_size>
	get_compute_work_group_size(void) const
	noexcept { return _ops::get_program_compute_work_group_size(*this); }
#endif
};

// obj_gen_del_ops
template <>
struct obj_gen_del_ops<tag::program>
{
	static
	deferred_error_handler
	_gen(span<GLuint> names)
	noexcept;

	static
	deferred_error_handler
	_create(span<GLuint> names)
	noexcept;

	static
	deferred_error_handler
	_delete(span<GLuint> names)
	noexcept;

	static
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using program = object_owner<tag::program>;
template <std::size_t N>
using program_array = object_array_owner<tag::program, N>;

static const object_zero_and_ops<tag::program>
	no_program = {};

} // namespace oglplus

#include <oglplus/program.inl>

#endif // include guard
