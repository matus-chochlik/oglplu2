/**
 *  @file oglplus/program_pipeline.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PROGRAM_PIPELINE_1509260923_HPP
#define OGLPLUS_PROGRAM_PIPELINE_1509260923_HPP

#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "object/owner.hpp"
#include "program_name.hpp"
#include "program_pipeline_name.hpp"
#include "utils/boolean.hpp"
#include "utils/gl_func.hpp"

namespace oglplus {
namespace oper {

struct program_pipeline_ops {
#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
    static outcome<void> bind_program_pipeline(
      program_pipeline_name ppo) noexcept;

    static outcome<program_pipeline_name> program_pipeline_binding(
      void) noexcept;

    static outcome<void> use_program_stages(program_pipeline_name ppl,
      enum_bitfield<program_pipeline_stage> stages,
      program_name prog) noexcept;

    static outcome<void> active_shader_program(
      program_pipeline_name ppl, program_name prog) noexcept;

    static outcome<void> validate_program_pipeline(
      program_pipeline_name ppl) noexcept;

    static outcome<void> report_program_pipeline_validate_error(
      program_pipeline_name ppl) noexcept;

    static outcome<void> get_program_pipeline_iv(program_pipeline_name buf,
      program_pipeline_parameter param,
      span<GLint> values) noexcept;

    template <typename R, typename T>
    static outcome<R> return_program_pipeline_i(
      program_pipeline_name ppl, program_pipeline_parameter parameter) noexcept;

    static outcome<boolean> get_program_pipeline_validate_status(
      program_pipeline_name ppl) noexcept;

    static outcome<program_name> get_program_pipeline_active_program(
      program_pipeline_name ppl) noexcept;

    static outcome<GLsizei> get_program_pipeline_info_log_length(
      program_pipeline_name ppl) noexcept;

    static outcome<span<char>> get_program_pipeline_info_log(
      program_pipeline_name ppl, span<char> dest) noexcept;
#endif
};

} // namespace oper

// obj_dsa_ops
template <>
struct obj_dsa_ops<tag::program_pipeline>
  : obj_zero_dsa_ops<tag::program_pipeline> {
    typedef oper::program_pipeline_ops _ops;

    using obj_zero_dsa_ops<tag::program_pipeline>::obj_zero_dsa_ops;

#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
    outcome<obj_dsa_ops&> use_program_stages(
      enum_bitfield<program_pipeline_stage> stages,
      program_name prog) noexcept {
	return {_ops::use_program_stages(*this, stages, prog), *this};
    }

    outcome<obj_dsa_ops&> active_program(program_name prog) noexcept {
	return {_ops::active_shader_program(*this, prog), *this};
    }

    outcome<obj_dsa_ops&> validate(void) noexcept {
	return {_ops::validate_program_pipeline(*this), *this};
    }

    outcome<boolean> get_validate_status(void) const noexcept {
	return _ops::get_program_pipeline_validate_status(*this);
    }

    outcome<obj_dsa_ops&> report_validate_error(void) noexcept {
	return {_ops::report_program_pipeline_validate_error(*this), *this};
    }

    outcome<program_name> get_active_program(void) const noexcept {
	return _ops::get_program_pipeline_active_program(*this);
    }

    outcome<GLsizei> get_info_log_length(void) const noexcept {
	return _ops::get_program_pipeline_info_log_length(*this);
    }

    outcome<span<char>> get_info_log(span<char> dest) const noexcept {
	return _ops::get_program_pipeline_info_log(*this, dest);
    }
#endif
};

#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shared_objects)
template <>
struct obj_gen_del_ops<tag::program_pipeline> {
    static deferred_error_handler _gen(span<GLuint> names) noexcept;

#if defined(GL_VERSION_4_5)
    static deferred_error_handler _create(span<GLuint> names) noexcept;
#endif

    static deferred_error_handler _delete(span<GLuint> names) noexcept;

    static outcome<boolean> _is_a(GLuint name) noexcept;
};

using program_pipeline = object_owner<tag::program_pipeline>;
template <std::size_t N>
using program_pipeline_array = object_array_owner<tag::program_pipeline, N>;

static const object_zero_and_ops<tag::program_pipeline> no_program_pipeline =
  {};
#endif

} // namespace oglplus

#include <oglplus/program_pipeline.inl>

#endif // include guard
