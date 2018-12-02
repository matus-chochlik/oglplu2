/**
 *  @file oglplus/oper/rasterization.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_RASTERIZATION_1509260923_HPP
#define OGLPLUS_OPER_RASTERIZATION_1509260923_HPP

#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"

namespace oglplus {
namespace oper {

struct rasterization_state {
    static outcome<void> front_face(face_orientation orientation) noexcept;

    static outcome<face_orientation> get_front_face() noexcept;

    static outcome<void> cull_face(face mode) noexcept;

    static outcome<face> get_cull_face_mode() noexcept;

#if defined(GL_VERSION_4_5)
    static outcome<void>
    clip_control(clip_origin origin, clip_depth_mode depth) noexcept;
#endif

    static outcome<void> depth_func(compare_function func) noexcept;

    static outcome<compare_function> get_depth_func() noexcept;

#if defined(GL_VERSION_4_1)
    static outcome<void> depth_range_f(GLfloat near, GLfloat far) noexcept;
#endif

#if defined(GL_DOUBLE)
    static outcome<void> depth_range(GLdouble near, GLdouble far) noexcept;

    static outcome<void>
    depth_range(GLuint index, GLdouble near, GLdouble far) noexcept;
#endif

#if defined(GL_VERSION_3_0)
    static outcome<void>
    polygon_mode(face side, oglplus::polygon_mode mode) noexcept;

    // TODO getter
#endif

    static outcome<void> polygon_offset(GLfloat factor, GLfloat units) noexcept;

#if defined(GL_VERSION_4_6) || defined(GL_EXT_polygon_offset_clamp)
    static outcome<void>
    polygon_offset_clamp(GLfloat factor, GLfloat units, GLfloat clamp) noexcept;
#endif

    static outcome<GLfloat> get_polygon_offset_factor() noexcept;

    static outcome<GLfloat> get_polygon_offset_units() noexcept;

#if defined(GL_VERSION_4_6) || defined(GL_EXT_polygon_offset_clamp)
    static outcome<GLfloat> get_polygon_offset_clamp() noexcept;
#endif

    static outcome<void> line_width(GLfloat value) noexcept;

    static outcome<GLfloat> get_line_width() noexcept;

#if defined(GL_VERSION_3_0)
    static outcome<void> point_size(GLfloat value) noexcept;

    static outcome<GLfloat> get_point_size() noexcept;

    static outcome<void>
    point_parameter(oglplus::point_parameter param, GLfloat value) noexcept;

    static outcome<GLfloat>
    get_point_parameter(oglplus::point_parameter param) noexcept;
#endif

#if defined(GL_VERSION_3_2) || defined(GL_ARB_provoking_vertex)
    static outcome<void> provoking_vertex(provoke_mode mode) noexcept;

    static outcome<provoke_mode> get_provoking_vertex() noexcept;
#endif

#if defined(GL_VERSION_4_0)
    static outcome<void> min_sample_shading(GLfloat value) noexcept;

    static outcome<GLfloat> get_min_sample_shading_value() noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/rasterization.inl>

#endif // include guard
