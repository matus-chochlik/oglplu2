/// @file
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
// particles
//------------------------------------------------------------------------------
class particles {
public:
    void init(example&);
    void emit(example&);
    void draw(example&);

    static auto origin_loc() noexcept {
        return oglp::vertex_attrib_location{0};
    }

    static auto cursors_binding() noexcept {
        return 0U;
    }

    static auto random_binding() noexcept {
        return 0U;
    }

    static auto offsets_binding() noexcept {
        return 1U;
    }

    static auto velocities_binding() noexcept {
        return 2U;
    }

    static auto ages_binding() noexcept {
        return 3U;
    }

private:
    const unsigned _count{4096U};

    oglp::owned_vertex_array_name _vao;

    oglp::owned_buffer_name _origin;
    oglp::owned_buffer_name _cursors;
    oglp::owned_buffer_name _random;
    oglp::owned_buffer_name _offsets;
    oglp::owned_buffer_name _velocities;
    oglp::owned_buffer_name _ages;
};
//------------------------------------------------------------------------------
// programs
//------------------------------------------------------------------------------
class emit_program {
public:
    void init(example&);
    void prepare_frame(example&);
    void bind_random(example&, oglp::gl_types::uint_type);
    void bind_offsets(example&, oglp::gl_types::uint_type);
    void bind_velocities(example&, oglp::gl_types::uint_type);
    void bind_ages(example&, oglp::gl_types::uint_type);
    void use(example&);

private:
    oglp::owned_program_name _prog;
    oglp::uniform_location _emit_position_loc;
    oglp::uniform_location _delta_time_loc;
};
//------------------------------------------------------------------------------
class draw_program {
public:
    void init(example&);
    void prepare_frame(example&);
    void bind_origin_location(example&, oglp::vertex_attrib_location);
    void bind_offsets(example&, oglp::gl_types::uint_type);
    void bind_ages(example&, oglp::gl_types::uint_type);
    void use(example&);

private:
    oglp::owned_program_name _prog;
    oglp::uniform_location _projection_mat_loc;
    oglp::uniform_location _perspective_mat_loc;
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
