/**
 *  example oglplus/002_triangle.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

// clang-format off
#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>
#include "example.hpp"
// clang-format on

namespace eagine {
namespace oglp {

class example_triangle : public example {
    owned_shader_name vs;
    owned_shader_name fs;

public:
    example_triangle(const example_context& ctx) {
        auto& [gl, GL] = ctx.gl();

        gl.clear_color(0.4f, 0.4f, 0.4f, 0.0f);

        gl.create_shader(GL.vertex_shader) >> vs;
        gl.create_shader(GL.fragment_shader) >> fs;
    }

    void cleanup(const example_context& ctx) final {
        auto& gl = ctx.gl();

        gl.delete_shader(std::move(vs));
        gl.delete_shader(std::move(fs));
    }

    void resize(const example_context& ctx) final {
        auto& gl = ctx.gl();

        gl.viewport(ctx.state().width(), ctx.state().height());
    }

    void render(const example_context& ctx) final {
        auto& [gl, GL] = ctx.gl();

        gl.clear(GL.color_buffer_bit);
    }
};

std::unique_ptr<example> make_example(
  const example_args&, const example_context& ctx) {
    return {std::make_unique<example_triangle>(ctx)};
}

void adjust_params(example_params& params) {
    params.depth_buffer(false);
    params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) {
    return false;
}

} // namespace oglp
} // namespace eagine

