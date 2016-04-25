//  File test/oglplus/enums/path_parameter_nv.cpp
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
#define BOOST_TEST_MODULE OGLPLUS_path_parameter_nv

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_path_parameter_nv_tests)

BOOST_AUTO_TEST_CASE(enum_path_parameter_nv_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_parameter_nv x;
	(void)x;

#ifdef GL_PATH_CLIENT_LENGTH_NV
	x = ev.path_client_length_nv;
	BOOST_CHECK(x == ev.path_client_length_nv);
# ifdef GL_PATH_COMMAND_COUNT_NV
	BOOST_CHECK(x != ev.path_command_count_nv);
# endif
# ifdef GL_PATH_COMPUTED_LENGTH_NV
	BOOST_CHECK(x != ev.path_computed_length_nv);
# endif
# ifdef GL_PATH_COORD_COUNT_NV
	BOOST_CHECK(x != ev.path_coord_count_nv);
# endif
# ifdef GL_PATH_DASH_ARRAY_COUNT_NV
	BOOST_CHECK(x != ev.path_dash_array_count_nv);
# endif
# ifdef GL_PATH_DASH_OFFSET_NV
	BOOST_CHECK(x != ev.path_dash_offset_nv);
# endif
# ifdef GL_PATH_DASH_OFFSET_RESET_NV
	BOOST_CHECK(x != ev.path_dash_offset_reset_nv);
# endif
# ifdef GL_PATH_FILL_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_fill_bounding_box_nv);
# endif
# ifdef GL_PATH_FILL_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_fill_cover_mode_nv);
# endif
# ifdef GL_PATH_FILL_MASK_NV
	BOOST_CHECK(x != ev.path_fill_mask_nv);
# endif
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
# ifdef GL_PATH_INITIAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_initial_dash_cap_nv);
# endif
# ifdef GL_PATH_INITIAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_initial_end_cap_nv);
# endif
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_COMMAND_COUNT_NV
	x = ev.path_command_count_nv;
	BOOST_CHECK(x == ev.path_command_count_nv);
# ifdef GL_PATH_COMPUTED_LENGTH_NV
	BOOST_CHECK(x != ev.path_computed_length_nv);
# endif
# ifdef GL_PATH_COORD_COUNT_NV
	BOOST_CHECK(x != ev.path_coord_count_nv);
# endif
# ifdef GL_PATH_DASH_ARRAY_COUNT_NV
	BOOST_CHECK(x != ev.path_dash_array_count_nv);
# endif
# ifdef GL_PATH_DASH_OFFSET_NV
	BOOST_CHECK(x != ev.path_dash_offset_nv);
# endif
# ifdef GL_PATH_DASH_OFFSET_RESET_NV
	BOOST_CHECK(x != ev.path_dash_offset_reset_nv);
# endif
# ifdef GL_PATH_FILL_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_fill_bounding_box_nv);
# endif
# ifdef GL_PATH_FILL_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_fill_cover_mode_nv);
# endif
# ifdef GL_PATH_FILL_MASK_NV
	BOOST_CHECK(x != ev.path_fill_mask_nv);
# endif
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
# ifdef GL_PATH_INITIAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_initial_dash_cap_nv);
# endif
# ifdef GL_PATH_INITIAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_initial_end_cap_nv);
# endif
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_COMPUTED_LENGTH_NV
	x = ev.path_computed_length_nv;
	BOOST_CHECK(x == ev.path_computed_length_nv);
# ifdef GL_PATH_COORD_COUNT_NV
	BOOST_CHECK(x != ev.path_coord_count_nv);
# endif
# ifdef GL_PATH_DASH_ARRAY_COUNT_NV
	BOOST_CHECK(x != ev.path_dash_array_count_nv);
# endif
# ifdef GL_PATH_DASH_OFFSET_NV
	BOOST_CHECK(x != ev.path_dash_offset_nv);
# endif
# ifdef GL_PATH_DASH_OFFSET_RESET_NV
	BOOST_CHECK(x != ev.path_dash_offset_reset_nv);
# endif
# ifdef GL_PATH_FILL_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_fill_bounding_box_nv);
# endif
# ifdef GL_PATH_FILL_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_fill_cover_mode_nv);
# endif
# ifdef GL_PATH_FILL_MASK_NV
	BOOST_CHECK(x != ev.path_fill_mask_nv);
# endif
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
# ifdef GL_PATH_INITIAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_initial_dash_cap_nv);
# endif
# ifdef GL_PATH_INITIAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_initial_end_cap_nv);
# endif
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_COORD_COUNT_NV
	x = ev.path_coord_count_nv;
	BOOST_CHECK(x == ev.path_coord_count_nv);
# ifdef GL_PATH_DASH_ARRAY_COUNT_NV
	BOOST_CHECK(x != ev.path_dash_array_count_nv);
# endif
# ifdef GL_PATH_DASH_OFFSET_NV
	BOOST_CHECK(x != ev.path_dash_offset_nv);
# endif
# ifdef GL_PATH_DASH_OFFSET_RESET_NV
	BOOST_CHECK(x != ev.path_dash_offset_reset_nv);
# endif
# ifdef GL_PATH_FILL_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_fill_bounding_box_nv);
# endif
# ifdef GL_PATH_FILL_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_fill_cover_mode_nv);
# endif
# ifdef GL_PATH_FILL_MASK_NV
	BOOST_CHECK(x != ev.path_fill_mask_nv);
# endif
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
# ifdef GL_PATH_INITIAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_initial_dash_cap_nv);
# endif
# ifdef GL_PATH_INITIAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_initial_end_cap_nv);
# endif
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_DASH_ARRAY_COUNT_NV
	x = ev.path_dash_array_count_nv;
	BOOST_CHECK(x == ev.path_dash_array_count_nv);
# ifdef GL_PATH_DASH_OFFSET_NV
	BOOST_CHECK(x != ev.path_dash_offset_nv);
# endif
# ifdef GL_PATH_DASH_OFFSET_RESET_NV
	BOOST_CHECK(x != ev.path_dash_offset_reset_nv);
# endif
# ifdef GL_PATH_FILL_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_fill_bounding_box_nv);
# endif
# ifdef GL_PATH_FILL_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_fill_cover_mode_nv);
# endif
# ifdef GL_PATH_FILL_MASK_NV
	BOOST_CHECK(x != ev.path_fill_mask_nv);
# endif
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
# ifdef GL_PATH_INITIAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_initial_dash_cap_nv);
# endif
# ifdef GL_PATH_INITIAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_initial_end_cap_nv);
# endif
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_DASH_OFFSET_NV
	x = ev.path_dash_offset_nv;
	BOOST_CHECK(x == ev.path_dash_offset_nv);
# ifdef GL_PATH_DASH_OFFSET_RESET_NV
	BOOST_CHECK(x != ev.path_dash_offset_reset_nv);
# endif
# ifdef GL_PATH_FILL_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_fill_bounding_box_nv);
# endif
# ifdef GL_PATH_FILL_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_fill_cover_mode_nv);
# endif
# ifdef GL_PATH_FILL_MASK_NV
	BOOST_CHECK(x != ev.path_fill_mask_nv);
# endif
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
# ifdef GL_PATH_INITIAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_initial_dash_cap_nv);
# endif
# ifdef GL_PATH_INITIAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_initial_end_cap_nv);
# endif
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_DASH_OFFSET_RESET_NV
	x = ev.path_dash_offset_reset_nv;
	BOOST_CHECK(x == ev.path_dash_offset_reset_nv);
# ifdef GL_PATH_FILL_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_fill_bounding_box_nv);
# endif
# ifdef GL_PATH_FILL_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_fill_cover_mode_nv);
# endif
# ifdef GL_PATH_FILL_MASK_NV
	BOOST_CHECK(x != ev.path_fill_mask_nv);
# endif
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
# ifdef GL_PATH_INITIAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_initial_dash_cap_nv);
# endif
# ifdef GL_PATH_INITIAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_initial_end_cap_nv);
# endif
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_FILL_BOUNDING_BOX_NV
	x = ev.path_fill_bounding_box_nv;
	BOOST_CHECK(x == ev.path_fill_bounding_box_nv);
# ifdef GL_PATH_FILL_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_fill_cover_mode_nv);
# endif
# ifdef GL_PATH_FILL_MASK_NV
	BOOST_CHECK(x != ev.path_fill_mask_nv);
# endif
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
# ifdef GL_PATH_INITIAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_initial_dash_cap_nv);
# endif
# ifdef GL_PATH_INITIAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_initial_end_cap_nv);
# endif
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_FILL_COVER_MODE_NV
	x = ev.path_fill_cover_mode_nv;
	BOOST_CHECK(x == ev.path_fill_cover_mode_nv);
# ifdef GL_PATH_FILL_MASK_NV
	BOOST_CHECK(x != ev.path_fill_mask_nv);
# endif
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
# ifdef GL_PATH_INITIAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_initial_dash_cap_nv);
# endif
# ifdef GL_PATH_INITIAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_initial_end_cap_nv);
# endif
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_FILL_MASK_NV
	x = ev.path_fill_mask_nv;
	BOOST_CHECK(x == ev.path_fill_mask_nv);
# ifdef GL_PATH_FILL_MODE_NV
	BOOST_CHECK(x != ev.path_fill_mode_nv);
# endif
# ifdef GL_PATH_INITIAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_initial_dash_cap_nv);
# endif
# ifdef GL_PATH_INITIAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_initial_end_cap_nv);
# endif
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_FILL_MODE_NV
	x = ev.path_fill_mode_nv;
	BOOST_CHECK(x == ev.path_fill_mode_nv);
# ifdef GL_PATH_INITIAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_initial_dash_cap_nv);
# endif
# ifdef GL_PATH_INITIAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_initial_end_cap_nv);
# endif
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_INITIAL_DASH_CAP_NV
	x = ev.path_initial_dash_cap_nv;
	BOOST_CHECK(x == ev.path_initial_dash_cap_nv);
# ifdef GL_PATH_INITIAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_initial_end_cap_nv);
# endif
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_INITIAL_END_CAP_NV
	x = ev.path_initial_end_cap_nv;
	BOOST_CHECK(x == ev.path_initial_end_cap_nv);
# ifdef GL_PATH_JOIN_STYLE_NV
	BOOST_CHECK(x != ev.path_join_style_nv);
# endif
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_JOIN_STYLE_NV
	x = ev.path_join_style_nv;
	BOOST_CHECK(x == ev.path_join_style_nv);
# ifdef GL_PATH_MITER_LIMIT_NV
	BOOST_CHECK(x != ev.path_miter_limit_nv);
# endif
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_MITER_LIMIT_NV
	x = ev.path_miter_limit_nv;
	BOOST_CHECK(x == ev.path_miter_limit_nv);
# ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_object_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	x = ev.path_object_bounding_box_nv;
	BOOST_CHECK(x == ev.path_object_bounding_box_nv);
# ifdef GL_PATH_STROKE_BOUND_NV
	BOOST_CHECK(x != ev.path_stroke_bound_nv);
# endif
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_STROKE_BOUND_NV
	x = ev.path_stroke_bound_nv;
	BOOST_CHECK(x == ev.path_stroke_bound_nv);
# ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	BOOST_CHECK(x != ev.path_stroke_bounding_box_nv);
# endif
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	x = ev.path_stroke_bounding_box_nv;
	BOOST_CHECK(x == ev.path_stroke_bounding_box_nv);
# ifdef GL_PATH_STROKE_COVER_MODE_NV
	BOOST_CHECK(x != ev.path_stroke_cover_mode_nv);
# endif
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_STROKE_COVER_MODE_NV
	x = ev.path_stroke_cover_mode_nv;
	BOOST_CHECK(x == ev.path_stroke_cover_mode_nv);
# ifdef GL_PATH_STROKE_MASK_NV
	BOOST_CHECK(x != ev.path_stroke_mask_nv);
# endif
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_STROKE_MASK_NV
	x = ev.path_stroke_mask_nv;
	BOOST_CHECK(x == ev.path_stroke_mask_nv);
# ifdef GL_PATH_STROKE_WIDTH_NV
	BOOST_CHECK(x != ev.path_stroke_width_nv);
# endif
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_STROKE_WIDTH_NV
	x = ev.path_stroke_width_nv;
	BOOST_CHECK(x == ev.path_stroke_width_nv);
# ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_dash_cap_nv);
# endif
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	x = ev.path_terminal_dash_cap_nv;
	BOOST_CHECK(x == ev.path_terminal_dash_cap_nv);
# ifdef GL_PATH_TERMINAL_END_CAP_NV
	BOOST_CHECK(x != ev.path_terminal_end_cap_nv);
# endif
#endif

#ifdef GL_PATH_TERMINAL_END_CAP_NV
	x = ev.path_terminal_end_cap_nv;
	BOOST_CHECK(x == ev.path_terminal_end_cap_nv);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_parameter_nv_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_parameter_nv x;
	(void)x;

#ifdef GL_PATH_CLIENT_LENGTH_NV
	x = ev.path_client_length_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_CLIENT_LENGTH_NV"
	) == 0);
#endif

#ifdef GL_PATH_COMMAND_COUNT_NV
	x = ev.path_command_count_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_COMMAND_COUNT_NV"
	) == 0);
#endif

#ifdef GL_PATH_COMPUTED_LENGTH_NV
	x = ev.path_computed_length_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_COMPUTED_LENGTH_NV"
	) == 0);
#endif

#ifdef GL_PATH_COORD_COUNT_NV
	x = ev.path_coord_count_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_COORD_COUNT_NV"
	) == 0);
#endif

#ifdef GL_PATH_DASH_ARRAY_COUNT_NV
	x = ev.path_dash_array_count_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_DASH_ARRAY_COUNT_NV"
	) == 0);
#endif

#ifdef GL_PATH_DASH_OFFSET_NV
	x = ev.path_dash_offset_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_DASH_OFFSET_NV"
	) == 0);
#endif

#ifdef GL_PATH_DASH_OFFSET_RESET_NV
	x = ev.path_dash_offset_reset_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_DASH_OFFSET_RESET_NV"
	) == 0);
#endif

#ifdef GL_PATH_FILL_BOUNDING_BOX_NV
	x = ev.path_fill_bounding_box_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_FILL_BOUNDING_BOX_NV"
	) == 0);
#endif

#ifdef GL_PATH_FILL_COVER_MODE_NV
	x = ev.path_fill_cover_mode_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_FILL_COVER_MODE_NV"
	) == 0);
#endif

#ifdef GL_PATH_FILL_MASK_NV
	x = ev.path_fill_mask_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_FILL_MASK_NV"
	) == 0);
#endif

#ifdef GL_PATH_FILL_MODE_NV
	x = ev.path_fill_mode_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_FILL_MODE_NV"
	) == 0);
#endif

#ifdef GL_PATH_INITIAL_DASH_CAP_NV
	x = ev.path_initial_dash_cap_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_INITIAL_DASH_CAP_NV"
	) == 0);
#endif

#ifdef GL_PATH_INITIAL_END_CAP_NV
	x = ev.path_initial_end_cap_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_INITIAL_END_CAP_NV"
	) == 0);
#endif

#ifdef GL_PATH_JOIN_STYLE_NV
	x = ev.path_join_style_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_JOIN_STYLE_NV"
	) == 0);
#endif

#ifdef GL_PATH_MITER_LIMIT_NV
	x = ev.path_miter_limit_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_MITER_LIMIT_NV"
	) == 0);
#endif

#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	x = ev.path_object_bounding_box_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_OBJECT_BOUNDING_BOX_NV"
	) == 0);
#endif

#ifdef GL_PATH_STROKE_BOUND_NV
	x = ev.path_stroke_bound_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_STROKE_BOUND_NV"
	) == 0);
#endif

#ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	x = ev.path_stroke_bounding_box_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_STROKE_BOUNDING_BOX_NV"
	) == 0);
#endif

#ifdef GL_PATH_STROKE_COVER_MODE_NV
	x = ev.path_stroke_cover_mode_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_STROKE_COVER_MODE_NV"
	) == 0);
#endif

#ifdef GL_PATH_STROKE_MASK_NV
	x = ev.path_stroke_mask_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_STROKE_MASK_NV"
	) == 0);
#endif

#ifdef GL_PATH_STROKE_WIDTH_NV
	x = ev.path_stroke_width_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_STROKE_WIDTH_NV"
	) == 0);
#endif

#ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	x = ev.path_terminal_dash_cap_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_TERMINAL_DASH_CAP_NV"
	) == 0);
#endif

#ifdef GL_PATH_TERMINAL_END_CAP_NV
	x = ev.path_terminal_end_cap_nv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PATH_TERMINAL_END_CAP_NV"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_path_parameter_nv_range)
{
	using namespace oglplus;
	auto count = enum_value_range<path_parameter_nv>().size();

#ifdef GL_PATH_CLIENT_LENGTH_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_CLIENT_LENGTH_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_COMMAND_COUNT_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_COMMAND_COUNT_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_COMPUTED_LENGTH_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_COMPUTED_LENGTH_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_COORD_COUNT_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_COORD_COUNT_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_DASH_ARRAY_COUNT_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_DASH_ARRAY_COUNT_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_DASH_OFFSET_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_DASH_OFFSET_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_DASH_OFFSET_RESET_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_DASH_OFFSET_RESET_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_FILL_BOUNDING_BOX_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_FILL_BOUNDING_BOX_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_FILL_COVER_MODE_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_FILL_COVER_MODE_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_FILL_MASK_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_FILL_MASK_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_FILL_MODE_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_FILL_MODE_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_INITIAL_DASH_CAP_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_INITIAL_DASH_CAP_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_INITIAL_END_CAP_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_INITIAL_END_CAP_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_JOIN_STYLE_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_JOIN_STYLE_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_MITER_LIMIT_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_MITER_LIMIT_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_OBJECT_BOUNDING_BOX_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_STROKE_BOUND_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_STROKE_BOUND_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_STROKE_BOUNDING_BOX_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_STROKE_COVER_MODE_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_STROKE_COVER_MODE_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_STROKE_MASK_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_STROKE_MASK_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_STROKE_WIDTH_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_STROKE_WIDTH_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_TERMINAL_DASH_CAP_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_TERMINAL_DASH_CAP_NV)
	) != r.end());
}
#endif

#ifdef GL_PATH_TERMINAL_END_CAP_NV
{
	--count;
	auto r = enum_value_range<path_parameter_nv>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		path_parameter_nv(GL_PATH_TERMINAL_END_CAP_NV)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_path_parameter_nv_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	path_parameter_nv x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_PATH_CLIENT_LENGTH_NV
	x = ev.path_client_length_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_client_length_nv);
#endif

#ifdef GL_PATH_COMMAND_COUNT_NV
	x = ev.path_command_count_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_command_count_nv);
#endif

#ifdef GL_PATH_COMPUTED_LENGTH_NV
	x = ev.path_computed_length_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_computed_length_nv);
#endif

#ifdef GL_PATH_COORD_COUNT_NV
	x = ev.path_coord_count_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_coord_count_nv);
#endif

#ifdef GL_PATH_DASH_ARRAY_COUNT_NV
	x = ev.path_dash_array_count_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_dash_array_count_nv);
#endif

#ifdef GL_PATH_DASH_OFFSET_NV
	x = ev.path_dash_offset_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_dash_offset_nv);
#endif

#ifdef GL_PATH_DASH_OFFSET_RESET_NV
	x = ev.path_dash_offset_reset_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_dash_offset_reset_nv);
#endif

#ifdef GL_PATH_FILL_BOUNDING_BOX_NV
	x = ev.path_fill_bounding_box_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_fill_bounding_box_nv);
#endif

#ifdef GL_PATH_FILL_COVER_MODE_NV
	x = ev.path_fill_cover_mode_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_fill_cover_mode_nv);
#endif

#ifdef GL_PATH_FILL_MASK_NV
	x = ev.path_fill_mask_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_fill_mask_nv);
#endif

#ifdef GL_PATH_FILL_MODE_NV
	x = ev.path_fill_mode_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_fill_mode_nv);
#endif

#ifdef GL_PATH_INITIAL_DASH_CAP_NV
	x = ev.path_initial_dash_cap_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_initial_dash_cap_nv);
#endif

#ifdef GL_PATH_INITIAL_END_CAP_NV
	x = ev.path_initial_end_cap_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_initial_end_cap_nv);
#endif

#ifdef GL_PATH_JOIN_STYLE_NV
	x = ev.path_join_style_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_join_style_nv);
#endif

#ifdef GL_PATH_MITER_LIMIT_NV
	x = ev.path_miter_limit_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_miter_limit_nv);
#endif

#ifdef GL_PATH_OBJECT_BOUNDING_BOX_NV
	x = ev.path_object_bounding_box_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_object_bounding_box_nv);
#endif

#ifdef GL_PATH_STROKE_BOUND_NV
	x = ev.path_stroke_bound_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_stroke_bound_nv);
#endif

#ifdef GL_PATH_STROKE_BOUNDING_BOX_NV
	x = ev.path_stroke_bounding_box_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_stroke_bounding_box_nv);
#endif

#ifdef GL_PATH_STROKE_COVER_MODE_NV
	x = ev.path_stroke_cover_mode_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_stroke_cover_mode_nv);
#endif

#ifdef GL_PATH_STROKE_MASK_NV
	x = ev.path_stroke_mask_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_stroke_mask_nv);
#endif

#ifdef GL_PATH_STROKE_WIDTH_NV
	x = ev.path_stroke_width_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_stroke_width_nv);
#endif

#ifdef GL_PATH_TERMINAL_DASH_CAP_NV
	x = ev.path_terminal_dash_cap_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_terminal_dash_cap_nv);
#endif

#ifdef GL_PATH_TERMINAL_END_CAP_NV
	x = ev.path_terminal_end_cap_nv;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.path_terminal_end_cap_nv);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
