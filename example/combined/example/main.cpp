/**
 *  .file oglplus/example/main.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

// clang-format off
#include <oglplus/gl.hpp>
#include "../example.hpp"
#include "state.hpp"
#include "main.hpp"
// clang-format on

#include <eagine/program_args.hpp>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <map>
#include <vector>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
bool parse_arg(program_arg& a, example_state& state, example_params& params);
//------------------------------------------------------------------------------
std::unique_ptr<example_main_intf> choose_example_main_impl(
  const program_args&);
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine
//------------------------------------------------------------------------------
int main(int argc, const char** argv) {
    try {
        eagine::program_args args(argc, argv);

        using namespace eagine::oglp;

        example_params params;
        example_state state;

        adjust_params(params);

        state.set_size(800, 600);

        params.exec_command(args.command());

        for(auto a = args.first(); a; a = a.next()) {
            if(!parse_arg(a, state, params)) {
                return 1;
            }
        }

        state.set_tiles(params.x_tiles(), params.y_tiles());

        example_args eargs(args, std::cerr);

        return choose_example_main_impl(args)->run(eargs, params, state);
    } catch(std::runtime_error& sre) {
        std::cerr << "Runtime error: " << sre.what() << std::endl;
    } catch(std::exception& se) {
        std::cerr << "Unknown error: " << se.what() << std::endl;
    }
    return 1;
}
//------------------------------------------------------------------------------
namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
bool example_knows_arg(const program_arg& arg) {
    return is_example_param(example_arg(arg)) ||
           is_example_param(example_arg(arg.prev()));
}
//------------------------------------------------------------------------------
bool is_special_argument(const program_arg& arg);
//------------------------------------------------------------------------------
template <typename T, typename Errstr>
bool consume_next_arg(
  program_arg& a, T& dest, const char* value_type, Errstr& errstr) {
    auto handle_missing = [&value_type, &errstr](const string_view arg_tag) {
        errstr() << "Missing " << value_type << " after '" << arg_tag << "'."
                 << std::endl;
    };
    auto handle_invalid = [&value_type, &errstr](
                            const string_view arg_tag,
                            const string_view arg_val,
                            const string_view log_str) {
        errstr() << "Invalid " << value_type << " '" << arg_val << "' after '"
                 << arg_tag << "'. " << log_str << std::endl;
    };
    return a.do_consume_next(dest, handle_missing, handle_invalid);
}
//------------------------------------------------------------------------------
bool parse_arg(program_arg& a, example_state& state, example_params& params) {
    using namespace eagine;

    auto errstr = []() -> std::ostream& {
        return std::cerr << "oglplus-example: ";
    };

    if(a == "--screenshot") {
        if(params.doing_framedump()) {
            errstr() << "Cannot specify --screenshot "
                     << "together with --framedump." << std::endl;
            return false;
        }
        valid_if_not_empty<string_view> path;
        if(consume_next_arg(a, path, "path", errstr)) {
            params.screenshot_path(path);
        } else {
            return false;
        }
    } else if(a == "--framedump") {
        if(params.doing_screenshot()) {
            errstr() << "Cannot specify --framedump"
                     << "together with --screenshot ." << std::endl;
            return false;
        }
        valid_if_not_empty<string_view> prefix;
        if(consume_next_arg(a, prefix, "prefix", errstr)) {
            params.framedump_prefix(prefix);
        } else {
            return false;
        }
    } else if(a == "--fixed-fps") {
        valid_if_positive<float> fps;
        if(consume_next_arg(a, fps, "float", errstr)) {
            params.fixed_fps(fps);
        } else {
            return false;
        }
    } else if(a == "--window-x") {
        int x = {};
        if(consume_next_arg(a, x, "integer", errstr)) {
            params.window_x_pos(x);
        } else {
            return false;
        }
    } else if(a == "--window-y") {
        int y = {};
        if(consume_next_arg(a, y, "integer", errstr)) {
            params.window_y_pos(y);
        } else {
            return false;
        }
    } else if(a == "--width") {
        valid_if_positive<int> w;
        if(consume_next_arg(a, w, "integer", errstr)) {
            state.set_width(w);
        } else {
            return false;
        }
    } else if(a == "--height") {
        valid_if_positive<int> h;
        if(consume_next_arg(a, h, "integer", errstr)) {
            state.set_height(h);
        } else {
            return false;
        }
    } else if(a == "--hd") {
        state.set_size(1280, 720);
    } else if(a == "--full-hd") {
        state.set_size(1920, 1080);
    } else if(a == "--x-tiles") {
        valid_if_positive<int> x;
        if(consume_next_arg(a, x, "integer", errstr)) {
            params.x_tiles(x);
        } else {
            return false;
        }
    } else if(a == "--y-tiles") {
        valid_if_positive<int> y;
        if(consume_next_arg(a, y, "integer", errstr)) {
            params.y_tiles(y);
        } else {
            return false;
        }
    } else if(a == "--demo") {
        params.demo_mode(true);
    } else if(a == "--high-quality") {
        params.high_quality(true);
    } else if(!(example_knows_arg(a) || is_special_argument(a))) {
        errstr() << "Unknown command-line option '" << a.get() << "'."
                 << std::endl;
    }
    return true;
}
//------------------------------------------------------------------------------
std::unique_ptr<example_main_intf> make_example_main_glx();
std::unique_ptr<example_main_intf> make_example_main_glfw3();
std::unique_ptr<example_main_intf> make_example_main_glfw();
std::unique_ptr<example_main_intf> make_example_main_glut();
std::unique_ptr<example_main_intf> make_example_main_sdl();
//------------------------------------------------------------------------------
static inline auto choose_example_main_impls_from_args(
  const program_args& args) {
    std::map<int, std::unique_ptr<example_main_intf>> result;

    if(auto found{args.find("--use-glx")}) {
        result[found.position()] = make_example_main_glx();
    }
    if(auto found{args.find("--use-glfw3")}) {
        result[found.position()] = make_example_main_glfw3();
    }
    if(auto found{args.find("--use-glfw")}) {
        result[found.position()] = make_example_main_glfw();
    }
    if(auto found{args.find("--use-glut")}) {
        result[found.position()] = make_example_main_glut();
    }
    if(auto found{args.find("--use-sdl")}) {
        result[found.position()] = make_example_main_sdl();
    }
    return result;
}
//------------------------------------------------------------------------------
static inline std::array<std::unique_ptr<example_main_intf>, 5>
make_all_main_impls() {
    return {{make_example_main_glx(),
             make_example_main_glfw3(),
             make_example_main_glfw(),
             make_example_main_glut(),
             make_example_main_sdl()}};
}
//------------------------------------------------------------------------------
bool is_special_argument(const program_arg& arg) {
    return arg.is_tag("--use-glx") || arg.is_tag("--use-sdl") ||
           arg.is_tag("--use-glfw3") || arg.is_tag("--use-glfw") ||
           arg.is_tag("--use-glut");
}
//------------------------------------------------------------------------------
std::unique_ptr<example_main_intf> choose_example_main_impl(
  const program_args& args) {

    for(auto& [pos, pimpl] : choose_example_main_impls_from_args(args)) {
        EAGINE_MAYBE_UNUSED(pos);
        if(pimpl && pimpl->is_implemented()) {
            return std::move(pimpl);
        }
    }
    for(auto& pimpl : make_all_main_impls()) {
        if(pimpl && pimpl->is_implemented()) {
            return std::move(pimpl);
        }
    }

    throw std::runtime_error("no OpenGL window API available");
}
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

