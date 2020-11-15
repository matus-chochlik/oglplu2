/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/main_ctx.hpp>
#include <eagine/program_args.hpp>
#include <eagine/valid_if/positive.hpp>
#include <oglplus/gl.hpp>
#include <oglplus/utils/image_file_io.hpp>
#include <climits>
#include <fstream>
#include <random>

namespace eagine {
//------------------------------------------------------------------------------
struct options {
    using _str_param_t = program_parameter<string_view>;
    using _pos_int_t = valid_if_positive<GLsizei>;
    using _int_param_t = program_parameter<_pos_int_t>;
    using _int_alias_t = program_parameter_alias<_pos_int_t>;
    using _opt_param_t = program_option;

    _str_param_t output_path;
    _int_param_t components;
    _int_alias_t format;
    _int_param_t width;
    _int_param_t height;
    _int_param_t depth;
    _opt_param_t verbosity;

    program_parameters all;

    options()
      : output_path("-o", "--output", "a.oglptex")
      , components("-c", "--components", 1)
      , format("-f", "--format", components)
      , width("-w", "--width", 256)
      , height("-h", "--height", 256)
      , depth("-d", "--depth", 1)
      , verbosity("-v", "--verbose")
      , all(output_path, components, width, height, depth, verbosity) {}

    void print_usage(std::ostream& log) {
        log << "bake_noise_image options" << std::endl;
        log << "  options:" << std::endl;
        log << "   -o|--output PATH: Output file path "
               "or '-' for stdout."
            << std::endl;
        log << "   -c|--components N: Number of components.";
        log << std::endl;
        log << "   -f|--format FORMAT: Output format." << std::endl;
        log << "     FORMAT is one of the following:" << std::endl;
        log << "       R8" << std::endl;
        log << "       RG8" << std::endl;
        log << "       RGB8" << std::endl;
        log << "       RGBB8" << std::endl;
        log << "   -w|--width N: Output image width." << std::endl;
        log << "   -h|--height N: Output image height." << std::endl;
        log << "   -d|--depth N: Output image depth." << std::endl;
    }

    auto check(std::ostream& log) const -> bool {
        return all.validate(log);
    }

    auto parse(program_arg& a, std::ostream& log) -> bool {
        const string_view fmtnamevals[] = {"R8", "RG8", "RGB8", "RGBA8"};
        const span<const string_view> fmtnames = view(fmtnamevals);

        const GLsizei cmpbytevals[] = {1, 2, 3, 4};
        const span<const GLsizei> cmpbytes = view(cmpbytevals);

        return a.parse_param(output_path, log) ||
               a.parse_param(components, cmpbytes, log) ||
               a.parse_param(format, fmtnames, cmpbytes, log) ||
               a.parse_param(width, log) || a.parse_param(height, log) ||
               a.parse_param(depth, log) || a.parse_param(verbosity, log);
    }
};
//------------------------------------------------------------------------------
void write_output(std::ostream& output, const options& opts) {
    oglp::image_data_header hdr(opts.width, opts.height, opts.depth);
    switch(opts.components.value()) {
        case 1:
            hdr.format = GL_RED;
            hdr.internal_format = GL_R8;
            break;
        case 2:
            hdr.format = GL_RG;
            hdr.internal_format = GL_RG8;
            break;
        case 3:
            hdr.format = GL_RGB;
            hdr.internal_format = GL_RGB8;
            break;
        case 4:
            hdr.format = GL_RGBA;
            hdr.internal_format = GL_RGBA8;
            break;
    };

    hdr.data_type = GL_UNSIGNED_BYTE;

    const auto size = span_size(
      opts.width.value() * opts.height.value() * opts.depth.value() *
      opts.components.value());

    oglp::write_and_pad_texture_image_data_header(output, hdr, size);

    const unsigned mask = ((1U << unsigned(CHAR_BIT)) - 1U);

    std::random_device rd;
    std::independent_bits_engine<std::mt19937, CHAR_BIT, unsigned> ibe(rd());

    for(span_size_t i = 0; i < size; ++i) {
        output.put(char(ibe() & mask));
    }
}
//------------------------------------------------------------------------------
auto parse_options(const program_args& args, options& opts) -> int;
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    try {
        options opts;

        if(int err = parse_options(ctx.args(), opts)) {
            return err;
        }

        if(are_equal(opts.output_path.value(), string_view("-"))) {
            write_output(std::cout, opts);
        } else {
            std::ofstream output_file(c_str(opts.output_path.value()));
            write_output(output_file, opts);
        }
    } catch(std::exception& err) {
        std::cerr << "what: " << err.what() << std::endl;
    }
    return 0;
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

    for(program_arg a = args.first(); a; a = a.next()) {

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
        return 2;
    }

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine

auto main(int argc, const char** argv) -> int {
    eagine::main_ctx_options options;
    options.app_id = EAGINE_ID(BakeNoisI);
    options.logger_opts.default_no_log = true;
    return eagine::main_impl(argc, argv, options);
}
