/**
 *  example oglplus/031_texgen.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

// clang-format off
#include <oglplus/gl.hpp>
#include <oglplus/constants.hpp>
#include <oglplus/operations.hpp>

#include <oglplus/texgen/render_graph.hpp>
#include <oglplus/texgen/sphere_coord_node.hpp>
#include <oglplus/texgen/random_node.hpp>
#include <oglplus/texgen/map_node.hpp>
#include <oglplus/texgen/wrap_node.hpp>
#include <oglplus/texgen/glsl_node.hpp>
#include <oglplus/texgen/border2d_node.hpp>
#include <oglplus/texgen/voronoi2d_node.hpp>
#include <oglplus/texgen/stripes_node.hpp>
#include <oglplus/texgen/combine_node.hpp>
#include <oglplus/texgen/uniform_node.hpp>
#include <oglplus/texgen/offset_node.hpp>

#include "example.hpp"
// clang-format on

namespace oglplus {

class example_render_graph : public texgen::render_graph {
public:
    uniform<GLfloat> offset_loc;

    example_render_graph(void) {
        using namespace texgen;

        add_new<sphere_coord_node>("sphere_coords");
        add_new<glsl_node>("circle_coords")
          .set_type(slot_data_type::float_2)
          .set_glsl("vec2(${Input}.x, sqrt(${Input}.w))");
        connect("sphere_coords", "circle_coords");

        add_new<random_node>("noise");
        add_new<wrap_node>("coord_wrap").set_mode(wrap_mode::repeat);

        add_new<map_node>("noise_map");
        connect("noise", "noise_map", "Input");
        connect("coord_wrap", "noise_map", "Coord");

        add_new<voronoi2d_node>("cells");
        connect("noise_map", "cells");

        add_new<map_node>("pattern_coords");

        connect("cells", "CCtr", "pattern_coords", "Input");
        connect("circle_coords", "pattern_coords", "Coord");

        add_new<stripes_node>("stripes");
        add_new<map_node>("stripes_map");

        connect("stripes", "stripes_map", "Input");
        connect("pattern_coords", "stripes_map", "Coord");

        add_new<border2d_node>("stripe_borders");
        connect("stripes_map", "stripe_borders");

        add_new<border2d_node>("cell_borders");
        connect("pattern_coords", "cell_borders");

        add_new<glsl_node>("cell_edges")
          .set_type(slot_data_type::float_)
          .set_glsl("sign(${Input}.g)");
        connect("cell_borders", "cell_edges");

        add_new<combine_node>("combine");
        connect("stripe_borders", "combine", "Red");
        connect("cell_edges", "combine", "Green");
        connect("stripes_map", "combine", "Blue");

        add_new<glsl_node>("final")
          .set_type(slot_data_type::float_3)
          .set_glsl("vec3(${^}.x+${^}.y*0.2+${^}.z*0.3)");

        connect("combine", "final");

        add_new<offset_node>("offset");

        uniform_node& uoffset =
          add_new<uniform_node>("uoffset").set_value_type<float[2]>();

        connect("final", "offset");
        connect("uoffset", "offset", "Offset");

        connect_to_renderer("offset");

        finalize();

        offset_loc = uoffset.get_uniform_location();
    }
};

class example_texgen : public example {
private:
    constants GL;
    operations gl;

    example_render_graph erg;

    GLfloat offset_x, offset_y;

public:
    example_texgen(void)
      : offset_x(-0.25f)
      , offset_y(-0.25f) {
        gl.uniform(erg.offset_loc, offset_x, offset_y);
        gl.disable(GL.depth_test);
    }

    void pointer_motion(const example_state_view& state) override {
        if(state.pointer_dragging()) {
            offset_x -= state.norm_pointer_x().delta();
            offset_y -= state.norm_pointer_y().delta();
            gl.uniform(erg.offset_loc, offset_x, offset_y);
        }
    }

    void resize(const example_state_view& state) override {
        gl.viewport(0, 0, state.width(), state.height());
        erg.set_dimensions(state.width(), state.height());
    }

    void user_idle(const example_state_view& state) override {
        if(state.user_idle_time() > seconds_(1)) {
            const float s = value(state.frame_duration()) * 60;
            const float t = value(state.exec_time());
            const float r = float(1.1f + std::sin(t * 1.618f));

            const float dest_offset_x = float(std::sin(t) * r);
            const float dest_offset_y = float(std::cos(t) * r);
            const float c = 0.02f * s;

            offset_x = c * dest_offset_x + (1 - c) * offset_x;
            offset_y = c * dest_offset_y + (1 - c) * offset_y;
            gl.uniform(erg.offset_loc, offset_x, offset_y);
        }
    }

    seconds_t<float> default_timeout(void) override {
        return seconds_(20);
    }

    void render(const example_state_view& /*state*/) override {
        erg.render();
    }
};

std::unique_ptr<example> make_example(
  const example_args&, const example_params&, const example_state_view&) {
    return std::unique_ptr<example>(new example_texgen());
}

void adjust_params(example_params& params) {
    params.depth_buffer(false);
    params.stencil_buffer(false);
}

bool is_example_param(const example_arg&) {
    return false;
}

} // namespace oglplus
