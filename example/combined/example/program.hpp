/**
 *  .file oglplus/example/program.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "params.hpp"
#include <oglplus/utils/program.hpp>
#include <oglplus/utils/string_span.hpp>

namespace eagine {
namespace oglp {

class example_program_base : public program {
protected:
    static shader_source_file get_shader_source(
      const example_params& params, string_view shdr_name) {
        std::string path = params.get_resource_file_path(
          example_resource_type::shader_source, shdr_name);
        return shader_source_file(string_view(path));
    }

    static shader make_shader(
      const example_params& params, string_view shdr_name) {
        return build_shader(get_shader_source(params, shdr_name));
    }

    static program_source_file get_program_source(
      const example_params& params, string_view prog_name) {
        std::string path = params.get_resource_file_path(
          example_resource_type::program_source, prog_name);
        return program_source_file(string_view(path));
    }

    static program make_program(
      const example_params& params, string_view prog_name) {
        return build_program(get_program_source(params, prog_name));
    }

public:
    example_program_base() = default;

    example_program_base(const example_params& params, string_view prog_name)
      : program(make_program(params, prog_name)) {
    }
};

} // namespace oglp
} // namespace eagine
