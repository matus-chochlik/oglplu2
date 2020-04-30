/**
 *  example combined/014_voronoi/resources.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include "../example/context.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
// random texture
//------------------------------------------------------------------------------
class random_texture {
private:
    owned_texture_name random;

public:
    void init(example_context& ctx);
};
//------------------------------------------------------------------------------
// voronoi program
//------------------------------------------------------------------------------
class voronoi_program {
private:
    owned_shader_name vs;
    owned_shader_name fs;

public:
    owned_program_name prog;
    uniform_location offset_loc;
    uniform_location scale_loc;

    void init(example_context& ctx);
};
//------------------------------------------------------------------------------
// screen geometry
//------------------------------------------------------------------------------
class screen_geometry {
private:
    owned_vertex_array_name vao;

    owned_buffer_name positions;
    owned_buffer_name tex_coords;

public:
    vertex_attrib_location position_loc{0};
    vertex_attrib_location tex_coord_loc{1};

    void init(example_context& ctx);
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine
