/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/integer_range.hpp>
#include <eagine/main_ctx.hpp>
#include <eagine/program_args.hpp>
#include <eagine/valid_if/one_of.hpp>
#include <eagine/valid_if/positive.hpp>
#include <oglplus/gl.hpp>
#include <oglplus/utils/image_file_io.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>

namespace eagine {
//------------------------------------------------------------------------------
struct options {

    program_parameter<string_view> output_path;
    program_parameter<std::vector<string_view>> input_paths;
    program_parameter<valid_if_one_of<int, 4>> rank;
    program_parameter<valid_if_positive<int>> width;
    program_parameter<valid_if_positive<int>> height;
    program_option verbosity;

    program_parameters all;

    options()
      : output_path{"-o", "--output", "a.oglptex"}
      , input_paths{"-i", "--input"}
      , rank{"-r", "--rank", 4}
      , width{"-w", "--width", 256}
      , height{"-h", "--height", 256}
      , verbosity{"-v", "--verbose"}
      , all{output_path, input_paths, rank, width, height, verbosity} {}

    void print_usage(std::ostream& log) {
        log << "bake_tiling_image options" << std::endl;
        log << "  options:" << std::endl;
        log << "   -o|--output PATH: Output file path ";
        log << "or '-' for stdout." << std::endl;
        log << "   -i|--input PATH: Input file path " << std::endl;
        log << "   -r|--rank N: Tiling rank." << std::endl;
        log << "   -w|--width N: Output image width." << std::endl;
        log << "   -h|--height N: Output image height." << std::endl;
    }

    auto check(std::ostream& log) const -> bool {
        return all.validate(log);
    }

    auto parse(program_arg& a, std::ostream& log) -> bool {
        return a.parse_param(output_path, log) ||
               a.parse_param(input_paths, log) || a.parse_param(rank, log) ||
               a.parse_param(width, log) || a.parse_param(height, log) ||
               a.parse_param(verbosity, log);
    }
};
//------------------------------------------------------------------------------
auto translate(char c, const options& opts) -> int {
    // TODO: other ranks
    EAGINE_ASSERT(opts.rank.value() == 4);

    if(opts.rank.value() == 4) {
        if(c >= '0' && c <= '9') {
            return char(c - '0');
        }
        if(c >= 'A' && c <= 'F') {
            return char(c - 'A' + 10);
        }
        if(c >= 'a' && c <= 'f') {
            return char(c - 'a' + 10);
        }
    }
    return c;
}
//------------------------------------------------------------------------------
auto write_output(std::ostream& output, const options& opts) -> int {
    auto& input_paths = opts.input_paths.value();
    if(input_paths.empty()) {
        std::cerr << "error: no inputs" << std::endl;
        return 3;
    }

    oglp::image_data_header hdr{
      opts.width, opts.height, limit_cast<int>(input_paths.size()), 1};
    hdr.format = GL_RED_INTEGER;
    hdr.internal_format = GL_R8UI;
    hdr.data_type = GL_UNSIGNED_BYTE;

    const auto size = span_size(opts.width.value() * opts.height.value()) *
                      span_size(input_paths.size());

    oglp::write_and_pad_texture_image_data_header(output, hdr, size);

    for(auto input_path : input_paths) {
        std::ifstream input{c_str(input_path)};
        char c{};
        for(const int y : integer_range(opts.height.value())) {
            for(const int x : integer_range(opts.width.value())) {
                if(!(input >> c).good()) {
                    std::cerr << "error: failed to read from input file '"
                              << input_path << "' at position " << x << "," << y
                              << std::endl;
                    return 4;
                }
                output.put(translate(c, opts));
            }
        }
    }

    return 0;
}
//------------------------------------------------------------------------------
auto parse_options(const program_args& args, options& opts) -> int;
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    try {
        options opts;

        if(auto err{parse_options(ctx.args(), opts)}) {
            return err;
        }

        if(are_equal(opts.output_path.value(), string_view("-"))) {
            return write_output(std::cout, opts);
        } else {
            std::ofstream output_file(c_str(opts.output_path.value()));
            return write_output(output_file, opts);
        }
    } catch(const std::exception& err) {
        std::cerr << "error: " << err.what() << std::endl;
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
    options.app_id = EAGINE_ID(BakeTlngI);
    options.logger_opts.default_no_log = true;
    return eagine::main_impl(argc, argv, options);
}
