/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/data_baking.hpp>
#include <eagine/file_contents.hpp>
#include <eagine/main_ctx.hpp>
#include <eagine/memory/buffer.hpp>
#include <eagine/program_args.hpp>
#include <eagine/valid_if/not_empty.hpp>
#include <oglplus/gl.hpp>
#include <oglplus/utils/program_file_hdr.hpp>
#include <fstream>
#include <iostream>

namespace eagine {
//------------------------------------------------------------------------------
struct options {
    using _str_param_t = program_parameter<valid_if_not_empty<string_view>>;

    using _str_list_param_t =
      program_parameter<std::vector<valid_if_not_empty<string_view>>>;

    _str_list_param_t vertex_shader_paths;
#ifdef GL_GEOMETRY_SHADER
    _str_list_param_t geometry_shader_paths;
#endif
#ifdef GL_TESS_CONTROL_SHADER
    _str_list_param_t tess_control_shader_paths;
#endif
#ifdef GL_TESS_EVALUATION_SHADER
    _str_list_param_t tess_evaluation_shader_paths;
#endif
    _str_list_param_t fragment_shader_paths;
#ifdef GL_COMPUTE_SHADER
    _str_list_param_t compute_shader_paths;
#endif

    _str_param_t output_path;

    program_parameters all;

    options()
      : vertex_shader_paths("-vx", "--vertex", {})
#ifdef GL_GEOMETRY_SHADER
      , geometry_shader_paths("-gy", "--geometry", {})
#endif
#ifdef GL_TESS_CONTROL_SHADER
      , tess_control_shader_paths("-tc", "--tess-control", {})
#endif
#ifdef GL_TESS_EVALUATION_SHADER
      , tess_evaluation_shader_paths("-te", "--tess-evaluation", {})
#endif
      , fragment_shader_paths("-ft", "--fragment", {})
#ifdef GL_COMPUTE_SHADER
      , compute_shader_paths("-ce", "--compute", {})
#endif
      , output_path("-o", "--output", string_view("a.oglpprog"))
      , all(
          vertex_shader_paths,
#ifdef GL_GEOMETRY_SHADER
          geometry_shader_paths,
#endif
#ifdef GL_TESS_CONTROL_SHADER
          tess_control_shader_paths,
#endif
#ifdef GL_TESS_EVALUATION_SHADER
          tess_evaluation_shader_paths,
#endif
          fragment_shader_paths,
#ifdef GL_COMPUTE_SHADER
          compute_shader_paths,
#endif
          output_path) {
        vertex_shader_paths.description(
          "Path to existing vertex shader source file.");
#ifdef GL_GEOMETRY_SHADER
        geometry_shader_paths.description(
          "Path to existing geometry shader source file.");
#endif
#ifdef GL_TESS_CONTROL_SHADER
        tess_control_shader_paths.description(
          "Path to existing tessellation control shader source file.");
#endif
#ifdef GL_TESS_EVALUATION_SHADER
        tess_evaluation_shader_paths.description(
          "Path to existing tessellation evaluation shader source file.");
#endif
        fragment_shader_paths.description(
          "Path to existing fragment shader source file.");
#ifdef GL_COMPUTE_SHADER
        compute_shader_paths.description(
          "Path to existing compute shader source file.");
#endif
        output_path.description(
          "Output file path, or '-' for standard output.");
    }

    void print_usage(std::ostream& log) {
        all.print_usage(log, "bake_program_source");
    }

    auto check(std::ostream& log) -> bool {
        return all.validate(log);
    }

    auto parse(program_arg& arg, std::ostream& log) -> bool {
        return all.parse(arg, log);
    }
};
//------------------------------------------------------------------------------
void read_shader_source_texts(
  std::vector<file_contents>& source_texts,
  std::vector<GLenum>& shader_types,
  GLenum shader_type,
  const std::vector<valid_if_not_empty<string_view>>& paths) {

    for(const auto& path : paths) {
        source_texts.emplace_back(file_contents(path.value()));
        shader_types.push_back(shader_type);
    }
}
//------------------------------------------------------------------------------
void write_output(std::ostream& output, const options& opts) {
    std::vector<file_contents> source_texts;
    std::vector<GLenum> shader_types;

    read_shader_source_texts(
      source_texts, shader_types, GL_VERTEX_SHADER, opts.vertex_shader_paths);

#ifdef GL_GEOMETRY_SHADER
    read_shader_source_texts(
      source_texts,
      shader_types,
      GL_GEOMETRY_SHADER,
      opts.geometry_shader_paths);
#endif

#ifdef GL_TESS_CONTROL_SHADER
    read_shader_source_texts(
      source_texts,
      shader_types,
      GL_TESS_CONTROL_SHADER,
      opts.tess_control_shader_paths);
#endif

#ifdef GL_TESS_EVALUATION_SHADER
    read_shader_source_texts(
      source_texts,
      shader_types,
      GL_TESS_EVALUATION_SHADER,
      opts.tess_evaluation_shader_paths);
#endif

    read_shader_source_texts(
      source_texts,
      shader_types,
      GL_FRAGMENT_SHADER,
      opts.fragment_shader_paths);

#ifdef GL_COMPUTE_SHADER
    read_shader_source_texts(
      source_texts, shader_types, GL_COMPUTE_SHADER, opts.compute_shader_paths);
#endif

    std::vector<span_size_t> slens;
    slens.reserve(source_texts.size());

    auto required_size = span_size(
      sizeof(oglp::program_source_header) +
      source_texts.size() *
        (sizeof(memory::offset_ptr<oglp::shader_source_header>) +
         sizeof(oglp::shader_source_header)));

    for(auto& source_text : source_texts) {
        slens.push_back(source_text.block().size());
        required_size += slens.back() * 2;
    }

    memory::buffer buf;
    buf.resize(required_size);

    data_bake_arena bakery(buf);

    auto& prog_src_hdr = bakery.make<oglp::program_source_header>();

    auto ssh_ptrs =
      bakery.make_array<memory::offset_ptr<const oglp::shader_source_header>>(
        span_size(source_texts.size()));

    prog_src_hdr.shader_sources = ssh_ptrs;

    for(std_size_t i = 0; i < shader_types.size(); ++i) {
        auto& shdr_src_hdr = bakery.make<oglp::shader_source_header>();

        shdr_src_hdr.shader_type = shader_types[i];
        shdr_src_hdr.source_text = bakery.copy_array(
          memory::accomodate<const GLchar>(source_texts[i].block()));

        ssh_ptrs[i] = &shdr_src_hdr;
    }

    write_to_stream(output, bakery.baked_data());
}
//------------------------------------------------------------------------------
auto parse_options(const program_args& args, options& opts) -> int;
//------------------------------------------------------------------------------
auto run(const program_args& args) -> int {
    options opts;

    if(int err = parse_options(args, opts)) {
        return err;
    }

    if(are_equal(opts.output_path.value(), string_view("-"))) {
        write_output(std::cout, opts);
    } else {
        std::ofstream output_file(c_str(opts.output_path.value()));
        write_output(output_file, opts);
    }
    return 0;
}
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {

    try {
        return run(ctx.args());
    } catch(const std::exception& err) {
        std::cerr << "Error: " << err.what() << std::endl;
    }
    return 1;
}
//------------------------------------------------------------------------------
auto parse_argument(program_arg& a, options& opts) -> bool {

    if(!opts.parse(a, std::cerr)) {
        std::cerr << "Failed to parse argument '" << a.get() << "'"
                  << std::endl;
        return false;
    }
    return true;
}
//------------------------------------------------------------------------------
auto parse_options(const program_args& args, options& opts) -> int {

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
} // namespace eagine

auto main(int argc, const char** argv) -> int {
    eagine::main_ctx_options options;
    options.app_id = EAGINE_ID(BakeSLProg);
    options.logger_opts.default_no_log = true;
    return eagine::main_impl(argc, argv, options);
}
