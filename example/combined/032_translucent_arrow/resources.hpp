/**
 *  example combined/032_translucent_arrow/resources.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_EXAMPLE_RESOURCES_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_RESOURCES_HPP

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/quantities.hpp>
#include <oglplus/math/primitives.hpp>
#include <oglplus/shapes/drawing.hpp>

namespace eagine {
class example_context;
namespace oglp {
class example_orbiting_camera;
//------------------------------------------------------------------------------
// programs
//------------------------------------------------------------------------------
class depth_program {
private:
    owned_program_name prog;

    uniform_location camera_loc;

public:
    void init(example_context& ctx);
    void set_projection(
      const example_context& ctx,
      const example_orbiting_camera& camera);
    void update(const example_context& ctx);

    void bind_position_location(
      const example_context& ctx,
      vertex_attrib_location loc);
};
//------------------------------------------------------------------------------
class draw_program {
private:
    owned_program_name prog;

    uniform_location camera_loc;
    uniform_location light_pos_loc;
    uniform_location depth_tex_loc;

    radians_t<float> rad{0.F};

public:
    void init(example_context& ctx);
    void set_depth_texture(const example_context& ctx, gl_types::int_type);
    void set_projection(
      const example_context& ctx,
      const example_orbiting_camera& camera);
    void update(const example_context& ctx);

    void bind_position_location(
      const example_context& ctx,
      vertex_attrib_location loc);

    void bind_normal_location(
      const example_context& ctx,
      vertex_attrib_location loc);
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class arrow_geometry {
private:
    owned_vertex_array_name vao;

    owned_buffer_name positions;
    owned_buffer_name normals;
    owned_buffer_name indices;

    std::vector<shape_draw_operation> ops;

    sphere bound_sphere;

public:
    void init(example_context& ctx);
    void draw(const example_context& ctx);

    auto bounding_sphere() noexcept {
        return bound_sphere;
    }

    static auto position_loc() noexcept {
        return vertex_attrib_location{0};
    }

    static auto normal_loc() noexcept {
        return vertex_attrib_location{1};
    }
};
//------------------------------------------------------------------------------
class depth_texture {
private:
    gl_types::int_type tex_unit{0};
    owned_texture_name tex{};

public:
    void init(example_context& ctx);
    void reshape(const example_context& ctx);
    void copy_from_fb(const example_context& ctx);

    auto texture_unit() const noexcept {
        return tex_unit;
    }
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif