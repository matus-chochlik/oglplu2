/**
 *  @file oglplus/path_nv_spec.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PATH_NV_SPEC_1509260923_HPP
#define OGLPLUS_PATH_NV_SPEC_1509260923_HPP

#ifndef GL_NV_path_rendering
#error NV_path_rendering API is not defined
#endif

#include <cassert>
#include <vector>
#include "enum/types.hpp"

namespace oglplus {
namespace oper {

struct path_nv_ops;

} // namespace oper

template <typename CoordType>
class path_nv_spec {
private:
    std::vector<GLubyte> _commands;
    std::vector<CoordType> _coords;

    friend oper::path_nv_ops;

    typedef CoordType T;

    path_nv_spec& _add(GLubyte command) {
        _commands.push_back(command);

        return *this;
    }

    path_nv_spec& _add(GLubyte command, T coord) {
        _commands.push_back(command);
        _coords.push_back(coord);

        return *this;
    }

    path_nv_spec& _append(GLubyte command, span<const T> coords) {
        _commands.push_back(command);
        _coords.insert(_coords.end(), coords.begin(), coords.end());

        return *this;
    }

    template <typename... C>
    path_nv_spec& _add(GLubyte command, C... c) {
        const std::size_t N = sizeof...(C);
        const T coords[N] = {T(c)...};
        return _append(command, coords);
    }

public:
    path_nv_spec() = default;
    path_nv_spec(path_nv_spec&&) = default;
    path_nv_spec& operator=(path_nv_spec&&) = default;

    path_nv_spec(std::size_t cmd_cap, std::size_t coord_cap) {
        _commands.reserve(cmd_cap);
        _coords.reserve(coord_cap);
    }

    path_nv_spec& add(path_command_nv command, span<const T> coords) {
        return _append(GLubyte(command), coords);
    }

    path_nv_spec& close() {
        return _add(GL_CLOSE_PATH_NV);
    }

    path_nv_spec& restart() {
        return _add(GL_RESTART_PATH_NV);
    }

    path_nv_spec& move_to(T c0, T c1) {
        return _add(GL_MOVE_TO_NV, c0, c1);
    }

    path_nv_spec& relative_move_to(T c0, T c1) {
        return _add(GL_RELATIVE_MOVE_TO_NV, c0, c1);
    }

    path_nv_spec& line_to(T c0, T c1) {
        return _add(GL_LINE_TO_NV, c0, c1);
    }

    path_nv_spec& relative_line_to(T c0, T c1) {
        return _add(GL_RELATIVE_LINE_TO_NV, c0, c1);
    }

    path_nv_spec& horizontal_line_to(T c0) {
        return _add(GL_HORIZONTAL_LINE_TO_NV, c0);
    }

    path_nv_spec& relative_horizontal_line_to(T c0) {
        return _add(GL_RELATIVE_HORIZONTAL_LINE_TO_NV, c0);
    }

    path_nv_spec& vertical_line_to(T c0) {
        return _add(GL_VERTICAL_LINE_TO_NV, c0);
    }

    path_nv_spec& relative_vertical_line_to(T c0) {
        return _add(GL_RELATIVE_VERTICAL_LINE_TO_NV, c0);
    }

    path_nv_spec& quadratic_curve_to(T c0, T c1, T c2, T c3) {
        return _add(GL_QUADRATIC_CURVE_TO_NV, c0, c1, c2, c3);
    }

    path_nv_spec& relative_quadratic_curve_to(T c0, T c1, T c2, T c3) {
        return _add(GL_RELATIVE_QUADRATIC_CURVE_TO_NV, c0, c1, c2, c3);
    }

    path_nv_spec& cubic_curve_to(T c0, T c1, T c2, T c3) {
        return _add(GL_CUBIC_CURVE_TO_NV, c0, c1, c2, c3);
    }

    path_nv_spec& relative_cubic_curve_to(T c0, T c1, T c2, T c3, T c4, T c5) {
        return _add(GL_RELATIVE_CUBIC_CURVE_TO_NV, c0, c1, c2, c3, c4, c5);
    }

    path_nv_spec& smooth_quadratic_curve_to(T c0, T c1) {
        return _add(GL_SMOOTH_QUADRATIC_CURVE_TO_NV, c0, c1);
    }

    path_nv_spec& relative_smooth_quadratic_curve_to(T c0, T c1) {
        return _add(GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV, c0, c1);
    }

    path_nv_spec& smooth_cubic_curve_to(T c0, T c1, T c2, T c3) {
        return _add(GL_SMOOTH_CUBIC_CURVE_TO_NV, c0, c1, c2, c3);
    }

    path_nv_spec& relative_smooth_cubic_curve_to(T c0, T c1, T c2, T c3) {
        return _add(GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV, c0, c1, c2, c3);
    }

    path_nv_spec& small_ccw_arc_to(T c0, T c1, T c2, T c3, T c4) {
        return _add(GL_SMALL_CCW_ARC_TO_NV, c0, c1, c2, c3, c4);
    }

    path_nv_spec& relative_small_ccw_arc_to(T c0, T c1, T c2, T c3, T c4) {
        return _add(GL_RELATIVE_SMALL_CCW_ARC_TO_NV, c0, c1, c2, c3, c4);
    }

    path_nv_spec& small_cw_arc_to(T c0, T c1, T c2, T c3, T c4) {
        return _add(GL_SMALL_CW_ARC_TO_NV, c0, c1, c2, c3, c4);
    }

    path_nv_spec& relative_small_cw_arc_to(T c0, T c1, T c2, T c3, T c4) {
        return _add(GL_RELATIVE_SMALL_CW_ARC_TO_NV, c0, c1, c2, c3, c4);
    }

    path_nv_spec& large_ccw_arc_to(T c0, T c1, T c2, T c3, T c4) {
        return _add(GL_LARGE_CCW_ARC_TO_NV, c0, c1, c2, c3, c4);
    }

    path_nv_spec& relative_large_ccw_arc_to(T c0, T c1, T c2, T c3, T c4) {
        return _add(GL_RELATIVE_LARGE_CCW_ARC_TO_NV, c0, c1, c2, c3, c4);
    }

    path_nv_spec& large_cw_arc_to(T c0, T c1, T c2, T c3, T c4) {
        return _add(GL_LARGE_CW_ARC_TO_NV, c0, c1, c2, c3, c4);
    }

    path_nv_spec& relative_large_cw_arc_to(T c0, T c1, T c2, T c3, T c4) {
        return _add(GL_RELATIVE_LARGE_CW_ARC_TO_NV, c0, c1, c2, c3, c4);
    }

    path_nv_spec& circular_ccw_arc_to(T c0, T c1, T c2, T c3, T c4) {
        return _add(GL_CIRCULAR_CCW_ARC_TO_NV, c0, c1, c2, c3, c4);
    }

    path_nv_spec& circular_cw_arc_to(T c0, T c1, T c2, T c3, T c4) {
        return _add(GL_CIRCULAR_CW_ARC_TO_NV, c0, c1, c2, c3, c4);
    }

    path_nv_spec& circular_tangent_arc_to(T c0, T c1, T c2, T c3, T c4) {
        return _add(GL_CIRCULAR_TANGENT_ARC_TO_NV, c0, c1, c2, c3, c4);
    }

    path_nv_spec& arc_to(T c0, T c1, T c2, T c3, T c4, T c5, T c6) {
        return _add(GL_ARC_TO_NV, c0, c1, c2, c3, c4, c5, c6);
    }

    path_nv_spec& relative_arc_to(T c0, T c1, T c2, T c3, T c4, T c5, T c6) {
        return _add(GL_RELATIVE_ARC_TO_NV, c0, c1, c2, c3, c4, c5, c6);
    }

    path_nv_spec& dup_first_cubic_curve_to(T c0, T c1, T c2, T c3) {
        return _add(GL_DUP_FIRST_CUBIC_CURVE_TO_NV, c0, c1, c2, c3);
    }

    path_nv_spec& dup_last_cubic_curve_to(T c0, T c1, T c2, T c3) {
        return _add(GL_DUP_LAST_CUBIC_CURVE_TO_NV, c0, c1, c2, c3);
    }

    path_nv_spec& rect(T c0, T c1, T c2, T c3) {
        return _add(GL_RECT_NV, c0, c1, c2, c3);
    }

#if defined(GL_NV_path_rendering_shared_edge)
    path_nv_spec& shared_edge() {
        assert(!_commands.empty());
        _commands.back() |= GL_SHARED_EDGE_NV;
        return *this;
    }
#endif
};

} // namespace oglplus

#endif // include guard
