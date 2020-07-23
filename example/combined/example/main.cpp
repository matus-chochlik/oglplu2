/**
 *  .file oglplus/example/main.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

// clang-format off
#include <eagine/main.hpp>
#include <oglplus/gl.hpp>
#include "../example.hpp"
#include "state.hpp"
#include "main.hpp"
// clang-format on

#include <eagine/program_args.hpp>
#include <eagine/logging/exception.hpp>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <map>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
bool parse_arg(program_arg& a, example_run_context&);
//------------------------------------------------------------------------------
std::unique_ptr<example_main_intf> choose_example_main_impl(
  const program_args&);
//------------------------------------------------------------------------------
int main(main_ctx& ctx) {
    auto& args = ctx.args();
    example_params params;
    example_state state;

    adjust_params(params);

    state.set_size(1024, 768);

    params.exec_command(ctx.exe_path());

    example_args eargs(args, ctx.log());
    example_run_context erc{ctx, eargs, params, state};

    for(auto a = args.first(); a; a = a.next()) {
        if(!parse_arg(a, erc)) {
            return 1;
        }
    }

    state.set_tiles(params.x_tiles(), params.y_tiles());

    return choose_example_main_impl(args)->run(erc);
}
//------------------------------------------------------------------------------
bool example_knows_arg(const program_arg& arg) {
    return is_example_param(example_arg(arg)) ||
           is_example_param(example_arg(arg.prev()));
}
//------------------------------------------------------------------------------
bool is_special_argument(const program_arg& arg);
//------------------------------------------------------------------------------
template <typename T>
bool consume_next_arg(
  program_arg& a, T& dest, string_view value_type, logger& log) {
    auto handle_missing = [&value_type, &log](const string_view arg_tag) {
        log.error("missing ${valueType} after '${argTag}'")
          .arg(EAGINE_ID(valueType), value_type)
          .arg(EAGINE_ID(argTag), arg_tag);
    };
    auto handle_invalid =
      [&value_type, &log](
        string_view arg_tag, string_view arg_val, string_view log_str) {
          log
            .error(
              "invalid ${valueType} '${argValue}' "
              "after '${argTag}': ${message}")
            .arg(EAGINE_ID(valueType), value_type)
            .arg(EAGINE_ID(argTag), arg_tag)
            .arg(EAGINE_ID(argValue), arg_val)
            .arg(EAGINE_ID(message), log_str);
      };
    return a.do_consume_next(dest, handle_missing, handle_invalid);
}
//------------------------------------------------------------------------------
bool parse_arg(program_arg& a, example_run_context& erc) {
    auto& log = erc.main.log();

    if(a == "--screenshot") {
        if(erc.params.doing_framedump()) {
            log.error("cannot specify --screenshot together with --framedump");
            return false;
        }
        valid_if_not_empty<string_view> path;
        if(consume_next_arg(a, path, "path", log)) {
            erc.params.screenshot_path(path);
        } else {
            return false;
        }
    } else if(a == "--framedump") {
        if(erc.params.doing_screenshot()) {
            log.error("cannot specify --screenshot together with --framedump");
            return false;
        }
        valid_if_not_empty<string_view> prefix;
        if(consume_next_arg(a, prefix, "prefix", log)) {
            erc.params.framedump_prefix(prefix);
        } else {
            return false;
        }
    } else if(a == "--fixed-fps") {
        valid_if_positive<float> fps;
        if(consume_next_arg(a, fps, "float", log)) {
            erc.params.fixed_fps(fps);
        } else {
            return false;
        }
    } else if(a == "--window-x") {
        int x = {};
        if(consume_next_arg(a, x, "integer", log)) {
            erc.params.window_x_pos(x);
        } else {
            return false;
        }
    } else if(a == "--window-y") {
        int y = {};
        if(consume_next_arg(a, y, "integer", log)) {
            erc.params.window_y_pos(y);
        } else {
            return false;
        }
    } else if(a == "--width") {
        valid_if_positive<int> w;
        if(consume_next_arg(a, w, "integer", log)) {
            erc.state.set_width(w);
        } else {
            return false;
        }
    } else if(a == "--height") {
        valid_if_positive<int> h;
        if(consume_next_arg(a, h, "integer", log)) {
            erc.state.set_height(h);
        } else {
            return false;
        }
    } else if(a == "--hd") {
        erc.state.set_size(1280, 720);
    } else if(a == "--full-hd") {
        erc.state.set_size(1920, 1080);
    } else if(a == "--x-tiles") {
        valid_if_positive<int> x;
        if(consume_next_arg(a, x, "integer", log)) {
            erc.params.x_tiles(x);
        } else {
            return false;
        }
    } else if(a == "--y-tiles") {
        valid_if_positive<int> y;
        if(consume_next_arg(a, y, "integer", log)) {
            erc.params.y_tiles(y);
        } else {
            return false;
        }
    } else if(a == "--demo") {
        erc.params.demo_mode(true);
    } else if(a == "--high-quality") {
        erc.params.high_quality(true);
    } else if(!(example_knows_arg(a) || is_special_argument(a))) {
        log.error("Unknown command-line option '${arg}'")
          .arg(EAGINE_ID(arg), a.get());
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
    return {
      {make_example_main_glx(),
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
} // namespace eagine

