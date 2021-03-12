/// @example application/040_metaballs/resources.hpp
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
#include <oglplus/shapes/drawing.hpp>

namespace eagine::application {
class example;
//------------------------------------------------------------------------------
// volume_domain
//------------------------------------------------------------------------------
class volume_domain {
public:
    void init(example&);
    void compute(example&);
    void draw(example&);

    constexpr auto plane_count() const noexcept -> int {
        return 64;
    }

    constexpr auto div_count() const noexcept -> int {
        return plane_count() - 1;
    }

    constexpr auto cube_count() const noexcept -> int {
        return div_count() * div_count() * div_count();
    }

    constexpr auto vertex_count() const noexcept -> int {
        return plane_count() * plane_count() * plane_count();
    }

    static auto corner_loc() noexcept {
        return oglp::vertex_attrib_location{0};
    }

    static auto field_binding() noexcept {
        return 0U;
    }

    static auto metaballs_binding() noexcept {
        return 1U;
    }

    static auto configs_binding() noexcept {
        return 2U;
    }

private:
    oglp::owned_vertex_array_name _tetrahedrons;
    oglp::owned_buffer_name _corners;
    oglp::owned_buffer_name _indices;

    oglp::owned_buffer_name _field;
    oglp::owned_buffer_name _metaballs;
    oglp::owned_buffer_name _configs;
};
//------------------------------------------------------------------------------
// programs
//------------------------------------------------------------------------------
class metaball_program {
public:
    void init(example&);
    void prepare_frame(example&);
    void use(example&);

    void bind_metaballs(example&, oglp::gl_types::uint_type);

private:
    oglp::owned_program_name _prog;
};
//------------------------------------------------------------------------------
class field_program {
public:
    void init(example&);
    void prepare_frame(example&);
    void use(example&);

    void bind_field(example&, oglp::gl_types::uint_type);
    void bind_metaballs(example&, oglp::gl_types::uint_type);
    void set_plane_count(example&, oglp::gl_types::int_type);

private:
    oglp::owned_program_name _prog;
    oglp::uniform_location _plane_count_loc;
};
//------------------------------------------------------------------------------
class surface_program {
public:
    void init(example&);
    void prepare_frame(example&);
    void bind_corner_location(example&, oglp::vertex_attrib_location);
    void use(example&);

    void bind_field(example&, oglp::gl_types::uint_type);
    void bind_configs(example&, oglp::gl_types::uint_type);
    void set_plane_count(example&, oglp::gl_types::int_type);
    void set_div_count(example&, oglp::gl_types::int_type);

private:
    oglp::owned_program_name _prog;
    oglp::uniform_location _camera_mat_loc;
    oglp::uniform_location _perspective_mat_loc;
    oglp::uniform_location _plane_count_loc;
    oglp::uniform_location _div_count_loc;
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
