//  File test/oglplus/enums/path_command_nv.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_path_command_nv

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_path_command_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_command_nv_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_command_nv x;
	(void)x;

#ifdef GL_ARC_TO_NV
	x = ev.arc_to_nv;
	BOOST_CHECK(x == ev.arc_to_nv);
# ifdef GL_CIRCULAR_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.circular_ccw_arc_to_nv);
# endif
# ifdef GL_CIRCULAR_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.circular_cw_arc_to_nv);
# endif
# ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
	BOOST_CHECK(x != ev.circular_tangent_arc_to_nv);
# endif
# ifdef GL_CLOSE_PATH_NV
	BOOST_CHECK(x != ev.close_path_nv);
# endif
# ifdef GL_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.cubic_curve_to_nv);
# endif
# ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_first_cubic_curve_to_nv);
# endif
# ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_last_cubic_curve_to_nv);
# endif
# ifdef GL_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.horizontal_line_to_nv);
# endif
# ifdef GL_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_ccw_arc_to_nv);
# endif
# ifdef GL_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_cw_arc_to_nv);
# endif
# ifdef GL_LINE_TO_NV
	BOOST_CHECK(x != ev.line_to_nv);
# endif
# ifdef GL_MOVE_TO_NV
	BOOST_CHECK(x != ev.move_to_nv);
# endif
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_CIRCULAR_CCW_ARC_TO_NV
	x = ev.circular_ccw_arc_to_nv;
	BOOST_CHECK(x == ev.circular_ccw_arc_to_nv);
# ifdef GL_CIRCULAR_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.circular_cw_arc_to_nv);
# endif
# ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
	BOOST_CHECK(x != ev.circular_tangent_arc_to_nv);
# endif
# ifdef GL_CLOSE_PATH_NV
	BOOST_CHECK(x != ev.close_path_nv);
# endif
# ifdef GL_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.cubic_curve_to_nv);
# endif
# ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_first_cubic_curve_to_nv);
# endif
# ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_last_cubic_curve_to_nv);
# endif
# ifdef GL_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.horizontal_line_to_nv);
# endif
# ifdef GL_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_ccw_arc_to_nv);
# endif
# ifdef GL_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_cw_arc_to_nv);
# endif
# ifdef GL_LINE_TO_NV
	BOOST_CHECK(x != ev.line_to_nv);
# endif
# ifdef GL_MOVE_TO_NV
	BOOST_CHECK(x != ev.move_to_nv);
# endif
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_CIRCULAR_CW_ARC_TO_NV
	x = ev.circular_cw_arc_to_nv;
	BOOST_CHECK(x == ev.circular_cw_arc_to_nv);
# ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
	BOOST_CHECK(x != ev.circular_tangent_arc_to_nv);
# endif
# ifdef GL_CLOSE_PATH_NV
	BOOST_CHECK(x != ev.close_path_nv);
# endif
# ifdef GL_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.cubic_curve_to_nv);
# endif
# ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_first_cubic_curve_to_nv);
# endif
# ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_last_cubic_curve_to_nv);
# endif
# ifdef GL_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.horizontal_line_to_nv);
# endif
# ifdef GL_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_ccw_arc_to_nv);
# endif
# ifdef GL_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_cw_arc_to_nv);
# endif
# ifdef GL_LINE_TO_NV
	BOOST_CHECK(x != ev.line_to_nv);
# endif
# ifdef GL_MOVE_TO_NV
	BOOST_CHECK(x != ev.move_to_nv);
# endif
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
	x = ev.circular_tangent_arc_to_nv;
	BOOST_CHECK(x == ev.circular_tangent_arc_to_nv);
# ifdef GL_CLOSE_PATH_NV
	BOOST_CHECK(x != ev.close_path_nv);
# endif
# ifdef GL_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.cubic_curve_to_nv);
# endif
# ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_first_cubic_curve_to_nv);
# endif
# ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_last_cubic_curve_to_nv);
# endif
# ifdef GL_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.horizontal_line_to_nv);
# endif
# ifdef GL_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_ccw_arc_to_nv);
# endif
# ifdef GL_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_cw_arc_to_nv);
# endif
# ifdef GL_LINE_TO_NV
	BOOST_CHECK(x != ev.line_to_nv);
# endif
# ifdef GL_MOVE_TO_NV
	BOOST_CHECK(x != ev.move_to_nv);
# endif
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_CLOSE_PATH_NV
	x = ev.close_path_nv;
	BOOST_CHECK(x == ev.close_path_nv);
# ifdef GL_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.cubic_curve_to_nv);
# endif
# ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_first_cubic_curve_to_nv);
# endif
# ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_last_cubic_curve_to_nv);
# endif
# ifdef GL_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.horizontal_line_to_nv);
# endif
# ifdef GL_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_ccw_arc_to_nv);
# endif
# ifdef GL_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_cw_arc_to_nv);
# endif
# ifdef GL_LINE_TO_NV
	BOOST_CHECK(x != ev.line_to_nv);
# endif
# ifdef GL_MOVE_TO_NV
	BOOST_CHECK(x != ev.move_to_nv);
# endif
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_CUBIC_CURVE_TO_NV
	x = ev.cubic_curve_to_nv;
	BOOST_CHECK(x == ev.cubic_curve_to_nv);
# ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_first_cubic_curve_to_nv);
# endif
# ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_last_cubic_curve_to_nv);
# endif
# ifdef GL_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.horizontal_line_to_nv);
# endif
# ifdef GL_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_ccw_arc_to_nv);
# endif
# ifdef GL_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_cw_arc_to_nv);
# endif
# ifdef GL_LINE_TO_NV
	BOOST_CHECK(x != ev.line_to_nv);
# endif
# ifdef GL_MOVE_TO_NV
	BOOST_CHECK(x != ev.move_to_nv);
# endif
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
	x = ev.dup_first_cubic_curve_to_nv;
	BOOST_CHECK(x == ev.dup_first_cubic_curve_to_nv);
# ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.dup_last_cubic_curve_to_nv);
# endif
# ifdef GL_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.horizontal_line_to_nv);
# endif
# ifdef GL_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_ccw_arc_to_nv);
# endif
# ifdef GL_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_cw_arc_to_nv);
# endif
# ifdef GL_LINE_TO_NV
	BOOST_CHECK(x != ev.line_to_nv);
# endif
# ifdef GL_MOVE_TO_NV
	BOOST_CHECK(x != ev.move_to_nv);
# endif
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
	x = ev.dup_last_cubic_curve_to_nv;
	BOOST_CHECK(x == ev.dup_last_cubic_curve_to_nv);
# ifdef GL_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.horizontal_line_to_nv);
# endif
# ifdef GL_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_ccw_arc_to_nv);
# endif
# ifdef GL_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_cw_arc_to_nv);
# endif
# ifdef GL_LINE_TO_NV
	BOOST_CHECK(x != ev.line_to_nv);
# endif
# ifdef GL_MOVE_TO_NV
	BOOST_CHECK(x != ev.move_to_nv);
# endif
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_HORIZONTAL_LINE_TO_NV
	x = ev.horizontal_line_to_nv;
	BOOST_CHECK(x == ev.horizontal_line_to_nv);
# ifdef GL_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_ccw_arc_to_nv);
# endif
# ifdef GL_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_cw_arc_to_nv);
# endif
# ifdef GL_LINE_TO_NV
	BOOST_CHECK(x != ev.line_to_nv);
# endif
# ifdef GL_MOVE_TO_NV
	BOOST_CHECK(x != ev.move_to_nv);
# endif
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_LARGE_CCW_ARC_TO_NV
	x = ev.large_ccw_arc_to_nv;
	BOOST_CHECK(x == ev.large_ccw_arc_to_nv);
# ifdef GL_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.large_cw_arc_to_nv);
# endif
# ifdef GL_LINE_TO_NV
	BOOST_CHECK(x != ev.line_to_nv);
# endif
# ifdef GL_MOVE_TO_NV
	BOOST_CHECK(x != ev.move_to_nv);
# endif
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_LARGE_CW_ARC_TO_NV
	x = ev.large_cw_arc_to_nv;
	BOOST_CHECK(x == ev.large_cw_arc_to_nv);
# ifdef GL_LINE_TO_NV
	BOOST_CHECK(x != ev.line_to_nv);
# endif
# ifdef GL_MOVE_TO_NV
	BOOST_CHECK(x != ev.move_to_nv);
# endif
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_LINE_TO_NV
	x = ev.line_to_nv;
	BOOST_CHECK(x == ev.line_to_nv);
# ifdef GL_MOVE_TO_NV
	BOOST_CHECK(x != ev.move_to_nv);
# endif
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_MOVE_TO_NV
	x = ev.move_to_nv;
	BOOST_CHECK(x == ev.move_to_nv);
# ifdef GL_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.quadratic_curve_to_nv);
# endif
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_QUADRATIC_CURVE_TO_NV
	x = ev.quadratic_curve_to_nv;
	BOOST_CHECK(x == ev.quadratic_curve_to_nv);
# ifdef GL_RECT_NV
	BOOST_CHECK(x != ev.rect_nv);
# endif
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RECT_NV
	x = ev.rect_nv;
	BOOST_CHECK(x == ev.rect_nv);
# ifdef GL_RELATIVE_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_arc_to_nv);
# endif
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_ARC_TO_NV
	x = ev.relative_arc_to_nv;
	BOOST_CHECK(x == ev.relative_arc_to_nv);
# ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	x = ev.relative_cubic_curve_to_nv;
	BOOST_CHECK(x == ev.relative_cubic_curve_to_nv);
# ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_horizontal_line_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	x = ev.relative_horizontal_line_to_nv;
	BOOST_CHECK(x == ev.relative_horizontal_line_to_nv);
# ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	x = ev.relative_large_ccw_arc_to_nv;
	BOOST_CHECK(x == ev.relative_large_ccw_arc_to_nv);
# ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_large_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	x = ev.relative_large_cw_arc_to_nv;
	BOOST_CHECK(x == ev.relative_large_cw_arc_to_nv);
# ifdef GL_RELATIVE_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_line_to_nv);
# endif
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_LINE_TO_NV
	x = ev.relative_line_to_nv;
	BOOST_CHECK(x == ev.relative_line_to_nv);
# ifdef GL_RELATIVE_MOVE_TO_NV
	BOOST_CHECK(x != ev.relative_move_to_nv);
# endif
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_MOVE_TO_NV
	x = ev.relative_move_to_nv;
	BOOST_CHECK(x == ev.relative_move_to_nv);
# ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	x = ev.relative_quadratic_curve_to_nv;
	BOOST_CHECK(x == ev.relative_quadratic_curve_to_nv);
# ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_ccw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	x = ev.relative_small_ccw_arc_to_nv;
	BOOST_CHECK(x == ev.relative_small_ccw_arc_to_nv);
# ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.relative_small_cw_arc_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	x = ev.relative_small_cw_arc_to_nv;
	BOOST_CHECK(x == ev.relative_small_cw_arc_to_nv);
# ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_cubic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	x = ev.relative_smooth_cubic_curve_to_nv;
	BOOST_CHECK(x == ev.relative_smooth_cubic_curve_to_nv);
# ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.relative_smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	x = ev.relative_smooth_quadratic_curve_to_nv;
	BOOST_CHECK(x == ev.relative_smooth_quadratic_curve_to_nv);
# ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.relative_vertical_line_to_nv);
# endif
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	x = ev.relative_vertical_line_to_nv;
	BOOST_CHECK(x == ev.relative_vertical_line_to_nv);
# ifdef GL_RESTART_PATH_NV
	BOOST_CHECK(x != ev.restart_path_nv);
# endif
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_RESTART_PATH_NV
	x = ev.restart_path_nv;
	BOOST_CHECK(x == ev.restart_path_nv);
# ifdef GL_SMALL_CCW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_ccw_arc_to_nv);
# endif
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_SMALL_CCW_ARC_TO_NV
	x = ev.small_ccw_arc_to_nv;
	BOOST_CHECK(x == ev.small_ccw_arc_to_nv);
# ifdef GL_SMALL_CW_ARC_TO_NV
	BOOST_CHECK(x != ev.small_cw_arc_to_nv);
# endif
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_SMALL_CW_ARC_TO_NV
	x = ev.small_cw_arc_to_nv;
	BOOST_CHECK(x == ev.small_cw_arc_to_nv);
# ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_cubic_curve_to_nv);
# endif
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	x = ev.smooth_cubic_curve_to_nv;
	BOOST_CHECK(x == ev.smooth_cubic_curve_to_nv);
# ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	BOOST_CHECK(x != ev.smooth_quadratic_curve_to_nv);
# endif
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	x = ev.smooth_quadratic_curve_to_nv;
	BOOST_CHECK(x == ev.smooth_quadratic_curve_to_nv);
# ifdef GL_VERTICAL_LINE_TO_NV
	BOOST_CHECK(x != ev.vertical_line_to_nv);
# endif
#endif

#ifdef GL_VERTICAL_LINE_TO_NV
	x = ev.vertical_line_to_nv;
	BOOST_CHECK(x == ev.vertical_line_to_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_command_nv_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_command_nv x;
	(void)x;

#ifdef GL_ARC_TO_NV
	x = ev.arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_CIRCULAR_CCW_ARC_TO_NV
	x = ev.circular_ccw_arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CIRCULAR_CCW_ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_CIRCULAR_CW_ARC_TO_NV
	x = ev.circular_cw_arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CIRCULAR_CW_ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
	x = ev.circular_tangent_arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CIRCULAR_TANGENT_ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_CLOSE_PATH_NV
	x = ev.close_path_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CLOSE_PATH_NV"
	) == 0);
#endif

#ifdef GL_CUBIC_CURVE_TO_NV
	x = ev.cubic_curve_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CUBIC_CURVE_TO_NV"
	) == 0);
#endif

#ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
	x = ev.dup_first_cubic_curve_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DUP_FIRST_CUBIC_CURVE_TO_NV"
	) == 0);
#endif

#ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
	x = ev.dup_last_cubic_curve_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"DUP_LAST_CUBIC_CURVE_TO_NV"
	) == 0);
#endif

#ifdef GL_HORIZONTAL_LINE_TO_NV
	x = ev.horizontal_line_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"HORIZONTAL_LINE_TO_NV"
	) == 0);
#endif

#ifdef GL_LARGE_CCW_ARC_TO_NV
	x = ev.large_ccw_arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LARGE_CCW_ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_LARGE_CW_ARC_TO_NV
	x = ev.large_cw_arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LARGE_CW_ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_LINE_TO_NV
	x = ev.line_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"LINE_TO_NV"
	) == 0);
#endif

#ifdef GL_MOVE_TO_NV
	x = ev.move_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"MOVE_TO_NV"
	) == 0);
#endif

#ifdef GL_QUADRATIC_CURVE_TO_NV
	x = ev.quadratic_curve_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"QUADRATIC_CURVE_TO_NV"
	) == 0);
#endif

#ifdef GL_RECT_NV
	x = ev.rect_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RECT_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_ARC_TO_NV
	x = ev.relative_arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	x = ev.relative_cubic_curve_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_CUBIC_CURVE_TO_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	x = ev.relative_horizontal_line_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_HORIZONTAL_LINE_TO_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	x = ev.relative_large_ccw_arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_LARGE_CCW_ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	x = ev.relative_large_cw_arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_LARGE_CW_ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_LINE_TO_NV
	x = ev.relative_line_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_LINE_TO_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_MOVE_TO_NV
	x = ev.relative_move_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_MOVE_TO_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	x = ev.relative_quadratic_curve_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_QUADRATIC_CURVE_TO_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	x = ev.relative_small_ccw_arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_SMALL_CCW_ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	x = ev.relative_small_cw_arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_SMALL_CW_ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	x = ev.relative_smooth_cubic_curve_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	x = ev.relative_smooth_quadratic_curve_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV"
	) == 0);
#endif

#ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	x = ev.relative_vertical_line_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RELATIVE_VERTICAL_LINE_TO_NV"
	) == 0);
#endif

#ifdef GL_RESTART_PATH_NV
	x = ev.restart_path_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"RESTART_PATH_NV"
	) == 0);
#endif

#ifdef GL_SMALL_CCW_ARC_TO_NV
	x = ev.small_ccw_arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SMALL_CCW_ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_SMALL_CW_ARC_TO_NV
	x = ev.small_cw_arc_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SMALL_CW_ARC_TO_NV"
	) == 0);
#endif

#ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	x = ev.smooth_cubic_curve_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SMOOTH_CUBIC_CURVE_TO_NV"
	) == 0);
#endif

#ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	x = ev.smooth_quadratic_curve_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SMOOTH_QUADRATIC_CURVE_TO_NV"
	) == 0);
#endif

#ifdef GL_VERTICAL_LINE_TO_NV
	x = ev.vertical_line_to_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"VERTICAL_LINE_TO_NV"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_command_nv_range)
{
	using namespace oglplus;
	auto count = enum_value_range<path_command_nv>().size();

#ifdef GL_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_CIRCULAR_CCW_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_CIRCULAR_CCW_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_CIRCULAR_CW_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_CIRCULAR_CW_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_CIRCULAR_TANGENT_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_CLOSE_PATH_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_CLOSE_PATH_NV)
	) != r.end());
}
#endif

#ifdef GL_CUBIC_CURVE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_CUBIC_CURVE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_DUP_FIRST_CUBIC_CURVE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_DUP_LAST_CUBIC_CURVE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_HORIZONTAL_LINE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_HORIZONTAL_LINE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_LARGE_CCW_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_LARGE_CCW_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_LARGE_CW_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_LARGE_CW_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_LINE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_LINE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_MOVE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_MOVE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_QUADRATIC_CURVE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_QUADRATIC_CURVE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RECT_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RECT_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_CUBIC_CURVE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_HORIZONTAL_LINE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_LARGE_CCW_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_LARGE_CW_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_LINE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_LINE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_MOVE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_MOVE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_QUADRATIC_CURVE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_SMALL_CCW_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_SMALL_CW_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RELATIVE_VERTICAL_LINE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_RESTART_PATH_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_RESTART_PATH_NV)
	) != r.end());
}
#endif

#ifdef GL_SMALL_CCW_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_SMALL_CCW_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_SMALL_CW_ARC_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_SMALL_CW_ARC_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_SMOOTH_CUBIC_CURVE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_SMOOTH_QUADRATIC_CURVE_TO_NV)
	) != r.end());
}
#endif

#ifdef GL_VERTICAL_LINE_TO_NV
{
	--count;
	auto r = enum_value_range<path_command_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_command_nv(GL_VERTICAL_LINE_TO_NV)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_command_nv_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_command_nv x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_ARC_TO_NV
	x = ev.arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.arc_to_nv);
#endif

#ifdef GL_CIRCULAR_CCW_ARC_TO_NV
	x = ev.circular_ccw_arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.circular_ccw_arc_to_nv);
#endif

#ifdef GL_CIRCULAR_CW_ARC_TO_NV
	x = ev.circular_cw_arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.circular_cw_arc_to_nv);
#endif

#ifdef GL_CIRCULAR_TANGENT_ARC_TO_NV
	x = ev.circular_tangent_arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.circular_tangent_arc_to_nv);
#endif

#ifdef GL_CLOSE_PATH_NV
	x = ev.close_path_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.close_path_nv);
#endif

#ifdef GL_CUBIC_CURVE_TO_NV
	x = ev.cubic_curve_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.cubic_curve_to_nv);
#endif

#ifdef GL_DUP_FIRST_CUBIC_CURVE_TO_NV
	x = ev.dup_first_cubic_curve_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.dup_first_cubic_curve_to_nv);
#endif

#ifdef GL_DUP_LAST_CUBIC_CURVE_TO_NV
	x = ev.dup_last_cubic_curve_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.dup_last_cubic_curve_to_nv);
#endif

#ifdef GL_HORIZONTAL_LINE_TO_NV
	x = ev.horizontal_line_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.horizontal_line_to_nv);
#endif

#ifdef GL_LARGE_CCW_ARC_TO_NV
	x = ev.large_ccw_arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.large_ccw_arc_to_nv);
#endif

#ifdef GL_LARGE_CW_ARC_TO_NV
	x = ev.large_cw_arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.large_cw_arc_to_nv);
#endif

#ifdef GL_LINE_TO_NV
	x = ev.line_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.line_to_nv);
#endif

#ifdef GL_MOVE_TO_NV
	x = ev.move_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.move_to_nv);
#endif

#ifdef GL_QUADRATIC_CURVE_TO_NV
	x = ev.quadratic_curve_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.quadratic_curve_to_nv);
#endif

#ifdef GL_RECT_NV
	x = ev.rect_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.rect_nv);
#endif

#ifdef GL_RELATIVE_ARC_TO_NV
	x = ev.relative_arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_arc_to_nv);
#endif

#ifdef GL_RELATIVE_CUBIC_CURVE_TO_NV
	x = ev.relative_cubic_curve_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_cubic_curve_to_nv);
#endif

#ifdef GL_RELATIVE_HORIZONTAL_LINE_TO_NV
	x = ev.relative_horizontal_line_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_horizontal_line_to_nv);
#endif

#ifdef GL_RELATIVE_LARGE_CCW_ARC_TO_NV
	x = ev.relative_large_ccw_arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_large_ccw_arc_to_nv);
#endif

#ifdef GL_RELATIVE_LARGE_CW_ARC_TO_NV
	x = ev.relative_large_cw_arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_large_cw_arc_to_nv);
#endif

#ifdef GL_RELATIVE_LINE_TO_NV
	x = ev.relative_line_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_line_to_nv);
#endif

#ifdef GL_RELATIVE_MOVE_TO_NV
	x = ev.relative_move_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_move_to_nv);
#endif

#ifdef GL_RELATIVE_QUADRATIC_CURVE_TO_NV
	x = ev.relative_quadratic_curve_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_quadratic_curve_to_nv);
#endif

#ifdef GL_RELATIVE_SMALL_CCW_ARC_TO_NV
	x = ev.relative_small_ccw_arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_small_ccw_arc_to_nv);
#endif

#ifdef GL_RELATIVE_SMALL_CW_ARC_TO_NV
	x = ev.relative_small_cw_arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_small_cw_arc_to_nv);
#endif

#ifdef GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV
	x = ev.relative_smooth_cubic_curve_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_smooth_cubic_curve_to_nv);
#endif

#ifdef GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV
	x = ev.relative_smooth_quadratic_curve_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_smooth_quadratic_curve_to_nv);
#endif

#ifdef GL_RELATIVE_VERTICAL_LINE_TO_NV
	x = ev.relative_vertical_line_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.relative_vertical_line_to_nv);
#endif

#ifdef GL_RESTART_PATH_NV
	x = ev.restart_path_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.restart_path_nv);
#endif

#ifdef GL_SMALL_CCW_ARC_TO_NV
	x = ev.small_ccw_arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.small_ccw_arc_to_nv);
#endif

#ifdef GL_SMALL_CW_ARC_TO_NV
	x = ev.small_cw_arc_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.small_cw_arc_to_nv);
#endif

#ifdef GL_SMOOTH_CUBIC_CURVE_TO_NV
	x = ev.smooth_cubic_curve_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.smooth_cubic_curve_to_nv);
#endif

#ifdef GL_SMOOTH_QUADRATIC_CURVE_TO_NV
	x = ev.smooth_quadratic_curve_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.smooth_quadratic_curve_to_nv);
#endif

#ifdef GL_VERTICAL_LINE_TO_NV
	x = ev.vertical_line_to_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.vertical_line_to_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
