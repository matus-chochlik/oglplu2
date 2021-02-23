/// @example application/032_translucent_arrow/resources.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef OGLPLUS_EXAMPLE_RESOURCES_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_RESOURCES_HPP

#include <oglplus/gl.hpp>
#include <oglplus/gl_api.hpp>

#include <eagine/application/fwd.hpp>
#include <eagine/cleanup_group.hpp>
#include <eagine/quantities.hpp>
#include <oglplus/math/primitives.hpp>
#include <oglplus/shapes/drawing.hpp>

namespace eagine::application {
//------------------------------------------------------------------------------
// programs
//------------------------------------------------------------------------------
class depth_program {
private:
    oglp::owned_program_name prog;

    oglp::uniform_location camera_loc;

public:
    void init(execution_context&, video_context&, cleanup_group&);
    void set_projection(video_context& ctx, orbiting_camera& camera);
    void update(video_context&);

    void bind_position_location(video_context&, oglp::vertex_attrib_location);
};
//------------------------------------------------------------------------------
class draw_program {
private:
    oglp::owned_program_name prog;

    oglp::uniform_location camera_loc;
    oglp::uniform_location light_pos_loc;
    oglp::uniform_location depth_tex_loc;

    radians_t<float> rad{0.F};

public:
    void init(execution_context&, video_context&, cleanup_group&);
    void set_depth_texture(video_context& ctx, oglp::gl_types::int_type);
    void set_projection(video_context&, orbiting_camera& camera);
    void update(execution_context&, video_context&);

    void bind_position_location(video_context&, oglp::vertex_attrib_location);
    void bind_normal_location(video_context& ctx, oglp::vertex_attrib_location);
};
//------------------------------------------------------------------------------
// geometry
//------------------------------------------------------------------------------
class arrow_geometry {
private:
    oglp::owned_vertex_array_name vao;

    oglp::owned_buffer_name positions;
    oglp::owned_buffer_name normals;
    oglp::owned_buffer_name indices;

    std::vector<oglp::shape_draw_operation> ops;

    oglp::sphere bound_sphere;

public:
    void init(execution_context&, video_context&, cleanup_group&);
    void draw(video_context&);

    auto bounding_sphere() noexcept {
        return bound_sphere;
    }

    static auto position_loc() noexcept {
        return oglp::vertex_attrib_location{0};
    }

    static auto normal_loc() noexcept {
        return oglp::vertex_attrib_location{1};
    }
};
//------------------------------------------------------------------------------
class depth_texture {
private:
    oglp::gl_types::int_type tex_unit{0};
    oglp::owned_texture_name tex{};

public:
    void init(execution_context&, video_context&, cleanup_group&);
    void reshape(video_context&);
    void copy_from_fb(video_context&);

    auto texture_unit() const noexcept {
        return tex_unit;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
