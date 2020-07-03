/**
 *  @file oglplus/gl_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_HPP
#define OGLPLUS_GL_API_HPP

#include "gl_api/api.hpp"
#include "gl_api/api_traits.hpp"
#include "gl_api/constants.hpp"
#include "gl_api_fwd.hpp"
#include <eagine/math/tmat.hpp>
//
#include "utils/program_file.hpp"

namespace eagine::oglp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_gl_api
  : protected ApiTraits
  , public basic_gl_operations<ApiTraits>
  , public basic_gl_constants<ApiTraits> {

public:
    template <typename R>
    using combined_result = typename ApiTraits::template combined_result<R>;

    using int_type = typename gl_types::int_type;
    using float_type = typename gl_types::float_type;

    basic_gl_api(ApiTraits traits)
      : ApiTraits{std::move(traits)}
      , basic_gl_operations<ApiTraits>{*static_cast<ApiTraits*>(this)}
      , basic_gl_constants<ApiTraits>{
          *static_cast<ApiTraits*>(this),
          *static_cast<basic_gl_operations<ApiTraits>*>(this)} {
    }

    basic_gl_api()
      : basic_gl_api{ApiTraits{}} {
    }

    basic_gl_operations<ApiTraits>& operations() noexcept {
        return *this;
    }

    const basic_gl_operations<ApiTraits>& operations() const noexcept {
        return *this;
    }

    basic_gl_operations<ApiTraits>& operator()() noexcept {
        return *this;
    }

    const basic_gl_operations<ApiTraits>& operator()() const noexcept {
        return *this;
    }

    basic_gl_constants<ApiTraits>& constants() noexcept {
        return *this;
    }

    const basic_gl_constants<ApiTraits>& constants() const noexcept {
        return *this;
    }

    basic_gl_constants<ApiTraits>& operator~() noexcept {
        return *this;
    }

    const basic_gl_constants<ApiTraits>& operator~() const noexcept {
        return *this;
    }

    // convenience functions
    constexpr true_false true_or_false(bool b) const noexcept {
        return b ? true_false(this->true_) : true_false(this->false_);
    }

    // build program
    combined_result<void> build_program(
      program_name prog, const program_source_block& prog_src_blk) const {
        if(prog_src_blk.is_valid()) {
            const span_size_t n = prog_src_blk.shader_source_count();
            for(span_size_t i = 0; i < n; ++i) {
                auto shdr_src_blk{prog_src_blk.shader_source(i)};
                owned_shader_name shdr;
                this->create_shader(shdr_src_blk.type()) >> shdr;
                auto cleanup = this->delete_shader.raii(shdr);
                this->shader_source(shdr, shdr_src_blk);
                this->compile_shader(shdr);
                this->attach_shader(prog, shdr);
            }
        }
        return this->link_program(prog);
    }

    combined_result<void> build_program(
      program_name prog, memory::const_block prog_src_blk) const {
        return build_program(prog, program_source_block(prog_src_blk));
    }

    // set_uniform
private:
    template <typename ProgramUniformFunc, typename UniformFunc, typename T>
    combined_result<void> _set_uniform(
      ProgramUniformFunc& program_uniform_func,
      UniformFunc& uniform_func,
      program_name prog,
      uniform_location loc,
      T&& value) const {
        if(program_uniform_func) {
            return program_uniform_func(prog, loc, std::forward<T>(value));
        } else {
            if(auto use_res{this->use_program(prog)}) {
                return uniform_func(loc, std::forward<T>(value));
            } else {
                return use_res;
            }
        }
    }

    template <typename ProgramUniformFunc, typename UniformFunc, typename T>
    combined_result<void> _set_uniform_matrix(
      ProgramUniformFunc& program_uniform_func,
      UniformFunc& uniform_func,
      program_name prog,
      uniform_location loc,
      T&& value,
      true_false transpose) const {
        if(program_uniform_func) {
            return program_uniform_func(
              prog, loc, transpose, std::forward<T>(value));
        } else {
            if(auto use_res{this->use_program(prog)}) {
                return uniform_func(loc, transpose, std::forward<T>(value));
            } else {
                return use_res;
            }
        }
    }

public:
    // int
    combined_result<void> set_uniform(
      program_name prog, uniform_location loc, int_type value) const {
        return _set_uniform(
          this->program_uniform1i, this->uniform1i, prog, loc, value);
    }

    combined_result<void> set_uniform(
      program_name prog,
      uniform_location loc,
      span<const int_type> value,
      identity<int_type[1]>) const {
        return _set_uniform(
          this->program_uniform1iv, this->uniform1iv, prog, loc, value);
    }

    combined_result<void> set_uniform(
      program_name prog,
      uniform_location loc,
      span<const int_type> value,
      identity<int_type[2]>) const {
        return _set_uniform(
          this->program_uniform2iv, this->uniform2iv, prog, loc, value);
    }

    combined_result<void> set_uniform(
      program_name prog,
      uniform_location loc,
      span<const int_type> value,
      identity<int_type[3]>) const {
        return _set_uniform(
          this->program_uniform3iv, this->uniform3iv, prog, loc, value);
    }

    combined_result<void> set_uniform(
      program_name prog,
      uniform_location loc,
      span<const int_type> value,
      identity<int_type[4]>) const {
        return _set_uniform(
          this->program_uniform4iv, this->uniform4iv, prog, loc, value);
    }

    // float
    combined_result<void> set_uniform(
      program_name prog, uniform_location loc, float_type value) const {
        return _set_uniform(
          this->program_uniform1f, this->uniform1f, prog, loc, value);
    }

    combined_result<void> set_uniform(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      identity<float_type[1]>) const {
        return _set_uniform(
          this->program_uniform1fv, this->uniform1fv, prog, loc, value);
    }

    combined_result<void> set_uniform(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      identity<float_type[2]>) const {
        return _set_uniform(
          this->program_uniform2fv, this->uniform2fv, prog, loc, value);
    }

    combined_result<void> set_uniform(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      identity<float_type[3]>) const {
        return _set_uniform(
          this->program_uniform3fv, this->uniform3fv, prog, loc, value);
    }

    combined_result<void> set_uniform(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      identity<float_type[4]>) const {
        return _set_uniform(
          this->program_uniform4fv, this->uniform4fv, prog, loc, value);
    }

    template <typename T>
    std::enable_if_t<is_known_vector_type_v<T>, combined_result<void>>
    set_uniform(program_name prog, uniform_location loc, const T& value) const {
        return set_uniform(
          prog, loc, element_view(value), canonical_compound_type<T>());
    }

    // uniform matrix
    combined_result<void> set_uniform_matrix(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      true_false transpose,
      identity<float_type[2][2]>) const {
        return _set_uniform_matrix(
          this->program_uniform_matrix2fv,
          this->uniform_matrix2fv,
          prog,
          loc,
          value,
          transpose);
    }

    combined_result<void> set_uniform_matrix(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      true_false transpose,
      identity<float_type[2][3]>) const {
        return _set_uniform_matrix(
          this->program_uniform_matrix2x3fv,
          this->uniform_matrix2x3fv,
          prog,
          loc,
          value,
          transpose);
    }

    combined_result<void> set_uniform_matrix(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      true_false transpose,
      identity<float_type[2][4]>) const {
        return _set_uniform_matrix(
          this->program_uniform_matrix2x4fv,
          this->uniform_matrix2x4fv,
          prog,
          loc,
          value,
          transpose);
    }

    combined_result<void> set_uniform_matrix(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      true_false transpose,
      identity<float_type[3][2]>) const {
        return _set_uniform_matrix(
          this->program_uniform_matrix3x2fv,
          this->uniform_matrix3x2fv,
          prog,
          loc,
          value,
          transpose);
    }

    combined_result<void> set_uniform_matrix(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      true_false transpose,
      identity<float_type[3][3]>) const {
        return _set_uniform_matrix(
          this->program_uniform_matrix3fv,
          this->uniform_matrix3fv,
          prog,
          loc,
          value,
          transpose);
    }

    combined_result<void> set_uniform_matrix(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      true_false transpose,
      identity<float_type[3][4]>) const {
        return _set_uniform_matrix(
          this->program_uniform_matrix3x4fv,
          this->uniform_matrix3x4fv,
          prog,
          loc,
          value,
          transpose);
    }

    combined_result<void> set_uniform_matrix(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      true_false transpose,
      identity<float_type[4][2]>) const {
        return _set_uniform_matrix(
          this->program_uniform_matrix4x2fv,
          this->uniform_matrix4x2fv,
          prog,
          loc,
          value,
          transpose);
    }

    combined_result<void> set_uniform_matrix(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      true_false transpose,
      identity<float_type[4][3]>) const {
        return _set_uniform_matrix(
          this->program_uniform_matrix4x3fv,
          this->uniform_matrix4x3fv,
          prog,
          loc,
          value,
          transpose);
    }

    combined_result<void> set_uniform_matrix(
      program_name prog,
      uniform_location loc,
      span<const float_type> value,
      true_false transpose,
      identity<float_type[4][4]>) const {
        return _set_uniform_matrix(
          this->program_uniform_matrix4fv,
          this->uniform_matrix4fv,
          prog,
          loc,
          value,
          transpose);
    }

    template <typename T>
    std::enable_if_t<is_known_matrix_type_v<T>, combined_result<void>>
    set_uniform(program_name prog, uniform_location loc, const T& value) const {
        return set_uniform_matrix(
          prog,
          loc,
          element_view(value),
          true_or_false(math::is_row_major_v<T>),
          canonical_compound_type<T>());
    }
};

template <std::size_t I, typename ApiTraits>
typename std::tuple_element<I, basic_gl_api<ApiTraits>>::type& get(
  basic_gl_api<ApiTraits>& x) noexcept {
    return x;
}

template <std::size_t I, typename ApiTraits>
const typename std::tuple_element<I, basic_gl_api<ApiTraits>>::type& get(
  const basic_gl_api<ApiTraits>& x) noexcept {
    return x;
}
//------------------------------------------------------------------------------
template <typename A>
true_false translate(const basic_gl_api<A>& api, bool value) noexcept {
    if(value) {
        return api.true_;
    }
    return api.false_;
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp

// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct tuple_size<eagine::oglp::basic_gl_api<ApiTraits>>
  : public std::integral_constant<std::size_t, 2> {};

template <typename ApiTraits>
struct tuple_element<0, eagine::oglp::basic_gl_api<ApiTraits>> {
    using type = eagine::oglp::basic_gl_operations<ApiTraits>;
};

template <typename ApiTraits>
struct tuple_element<1, eagine::oglp::basic_gl_api<ApiTraits>> {
    using type = eagine::oglp::basic_gl_constants<ApiTraits>;
};
//------------------------------------------------------------------------------
} // namespace std

#endif // OGLPLUS_GL_API_HPP

