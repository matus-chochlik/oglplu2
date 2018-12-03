/**
 *  @file oglplus/uniform.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_UNIFORM_1509260923_HPP
#define OGLPLUS_UNIFORM_1509260923_HPP

#include "prog_var/dsa_location.hpp"
#include "prog_var/location.hpp"
#include "prog_var/wrapper.hpp"
#include "utils/identity.hpp"
#include "utils/span.hpp"
#include <cassert>
#include <vector>

namespace oglplus {
namespace tag {

struct uniform {};

} // namespace tag

using uniform_location = prog_var_loc<tag::uniform>;
using program_uniform_location = dsa_prog_var_loc<tag::uniform>;

template <typename T>
using uniform = prog_var_wrapper<uniform_location, T>;

template <typename T>
using program_uniform = prog_var_wrapper<program_uniform_location, T>;

template <>
struct prog_var_loc_ops<tag::uniform> {
    typedef tag::uniform tag;

    static outcome<prog_var_loc<tag>>
    get_location(program_name prog, string_view identifier) noexcept {
        GLint loc = OGLPLUS_GLFUNC(GetUniformLocation)(
          get_raw_name(prog), c_str(identifier));
        OGLPLUS_VERIFY(
          GetUniformLocation, identifier(identifier).gl_object(prog), always);

        return {prog_var_loc<tag>{loc}};
    }

    static outcome<span<prog_var_loc<tag>>> get_indices(
      program_name prog,
      span<string_view> identifiers,
      span<prog_var_loc<tag>> indices) noexcept {
        assert(identifiers.size() == indices.size());

        std::vector<const GLchar*> names(identifiers.size());
        std::vector<GLuint> results(indices.size());

        for(span_size_t i = 0; i < identifiers.size(); ++i) {
            names[i] = c_str(identifiers[i]);
        }

        OGLPLUS_GLFUNC(GetUniformIndices)
        (get_raw_name(prog),
         GLsizei(identifiers.size()),
         names.data(),
         results.data());
        OGLPLUS_VERIFY(GetUniformIndices, gl_object(prog), always);

        for(span_size_t i = 0; i < indices.size(); ++i) {
            indices[i] = prog_var_loc<tag>{GLint(results[i])};
        }

        return indices;
    }
};

} // namespace oglplus

#include <oglplus/uniform_get_set.inl>
#include <oglplus/uniform_get_set_spec.inl>

#endif // include guard
