/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/data_baking.hpp>
#include <eagine/input_data.hpp>
#include <eagine/program_args.hpp>
#include <eagine/valid_if/not_empty.hpp>
#include <eagine/valid_if/one_of.hpp>
#include <oglplus/gl.hpp>
#include <oglplus/utils/program_file_hdr.hpp>
#include <fstream>
#include <iostream>
//------------------------------------------------------------------------------
struct options {
    using _str_param_t = eagine::program_parameter<
      eagine::valid_if_not_empty<eagine::string_view>>;

    using _sht_param_t = eagine::program_parameter<eagine::valid_if_one_of<
      GLenum,
      GL_VERTEX_SHADER,
#ifdef GL_GEOMETRY_SHADER
      GL_GEOMETRY_SHADER,
#endif
#ifdef GL_TESS_CONTROL_SHADER
      GL_TESS_CONTROL_SHADER,
#endif
#ifdef GL_TESS_EVALUATION_SHADER
      GL_TESS_EVALUATION_SHADER,
#endif
#ifdef GL_COMPUTE_SHADER
      GL_COMPUTE_SHADER,
#endif
      GL_FRAGMENT_SHADER>>;

    _str_param_t input_path;
    _str_param_t output_path;
    _sht_param_t shader_type;

    options()
      : input_path("-i", "--input", eagine::string_view())
      , output_path("-o", "--output", eagine::string_view("a.oglpshdr"))
      , shader_type("-t", "--shader-type", GL_NONE) {
    }

    void print_usage(std::ostream& log) {
        log << "bake_shader_source options" << std::endl;
        log << "  options:" << std::endl;
        log << "   -i|--input PATH: Input GLSL file path "
            << "or '-' for stdin." << std::endl;
        log << "   -o|--output PATH: Output file path "
               "or '-' for stdout."
            << std::endl;
        log << "   -t|--shader-type TYPE: Shader type." << std::endl;
        log << "     TYPE is one of the following:" << std::endl;
        log << "       vertex" << std::endl;
#ifdef GL_GEOMETRY_SHADER
        log << "       geometry" << std::endl;
#endif
#ifdef GL_TESS_CONTROL_SHADER
        log << "       tess_control" << std::endl;
#endif
#ifdef GL_TESS_EVALUATION_SHADER
        log << "       tess_evaluation" << std::endl;
#endif
        log << "       fragment" << std::endl;
#ifdef GL_COMPUTE_SHADER
        log << "       compute" << std::endl;
#endif
    }

    bool check(std::ostream& log) {
        return input_path.validate(log) && output_path.validate(log) &&
               shader_type.validate(log);
    }

    bool parse(eagine::program_arg& a, std::ostream& log) {
        const eagine::string_view shader_type_names[] = {"vertex",
#ifdef GL_GEOMETRY_SHADER
                                                         "geometry",
#endif
#ifdef GL_TESS_CONTROL_SHADER
                                                         "tess_control",
#endif
#ifdef GL_TESS_EVALUATION_SHADER
                                                         "tess_evaluation",
#endif
#ifdef GL_COMPUTE_SHADER
                                                         "compute",
#endif
                                                         "fragment"};
        const eagine::span<const eagine::string_view> shtnames =
          eagine::view(shader_type_names);

        const GLenum shader_type_values[] = {GL_VERTEX_SHADER,
#ifdef GL_GEOMETRY_SHADER
                                             GL_GEOMETRY_SHADER,
#endif
#ifdef GL_TESS_CONTROL_SHADER
                                             GL_TESS_CONTROL_SHADER,
#endif
#ifdef GL_TESS_EVALUATION_SHADER
                                             GL_TESS_EVALUATION_SHADER,
#endif
#ifdef GL_COMPUTE_SHADER
                                             GL_COMPUTE_SHADER,
#endif
                                             GL_FRAGMENT_SHADER};
        const eagine::span<const GLenum> shtvalues =
          eagine::view(shader_type_values);

        return a.parse_param(output_path, log) ||
               a.parse_param(input_path, log) ||
               a.parse_param(shader_type, shtnames, shtvalues, log);
    }
};
//------------------------------------------------------------------------------
void write_output(
  std::istream& input, std::ostream& output, const options& opts) {
    oglplus::shader_source_header hdr;

    eagine::memory::buffer source_text;
    eagine::read_stream_data(input, source_text);

    eagine::memory::buffer buf;
    buf.resize(
      eagine::span_size(sizeof(oglplus::shader_source_header)) +
      source_text.size() * 2);

    eagine::data_bake_arena bakery(buf);

    auto& shdr_src_hdr = bakery.make<oglplus::shader_source_header>();

    shdr_src_hdr.shader_type = opts.shader_type.value();
    shdr_src_hdr.source_text =
      bakery.copy_array(eagine::memory::accomodate<const GLchar>(
        eagine::memory::const_block(source_text)));

    eagine::write_to_stream(output, bakery.baked_data());
}
//------------------------------------------------------------------------------
int parse_options(int argc, const char** argv, options& opts);
//------------------------------------------------------------------------------
int run(int argc, const char** argv) {
    options opts;

    if(int err = parse_options(argc, argv, opts)) {
        return err;
    }

    bool from_stdin =
      are_equal(opts.input_path.value(), eagine::string_view("-"));
    bool to_stdout =
      are_equal(opts.output_path.value(), eagine::string_view("-"));

    if(from_stdin && to_stdout) {
        write_output(std::cin, std::cout, opts);
    } else if(from_stdin) {
        std::ofstream output_file(c_str(opts.output_path.value()));
        write_output(std::cin, output_file, opts);
    } else if(to_stdout) {
        std::ifstream input_file(c_str(opts.input_path.value()));
        write_output(input_file, std::cout, opts);
    } else {
        std::ifstream input_file(c_str(opts.input_path.value()));
        std::ofstream output_file(c_str(opts.output_path.value()));
        write_output(input_file, output_file, opts);
    }
    return 0;
}
//------------------------------------------------------------------------------
int main(int argc, const char** argv) {

    try {
        return run(argc, argv);
    } catch(std::exception& err) {
        std::cerr << "Error: " << err.what() << std::endl;
    }
    return 1;
}
//------------------------------------------------------------------------------
bool parse_argument(eagine::program_arg& a, options& opts) {

    if(!opts.parse(a, std::cerr)) {
        std::cerr << "Failed to parse argument '" << a.get() << "'"
                  << std::endl;
        return false;
    }
    return true;
}
//------------------------------------------------------------------------------
int parse_options(int argc, const char** argv, options& opts) {

    eagine::program_args args(argc, argv);

    for(auto a = args.first(); a; a = a.next()) {
        if(a.is_help_arg()) {
            opts.print_usage(std::cout);
            return 1;
        } else if(!parse_argument(a, opts)) {
            opts.print_usage(std::cerr);
            return 2;
        }
    }

    if(!opts.check(std::cerr)) {
        opts.print_usage(std::cerr);
        return 3;
    }

    return 0;
}
//------------------------------------------------------------------------------
