/**
 *  @file oglplus/oper/rasterization.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>
#include <oglplus/oper/numeric_queries.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<void>
rasterization_state::
front_face(face_orientation orientation)
noexcept {
	OGLPLUS_GLFUNC(FrontFace)(GLenum(orientation));
	OGLPLUS_VERIFY(FrontFace, gl_enum_value(orientation), debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<face_orientation>
rasterization_state::
get_front_face(void)
noexcept {
	return face_orientation(GLenum(numeric_queries::get_integer(
		numeric_query(GL_FRONT_FACE)
	)));
}
//------------------------------------------------------------------------------
inline
outcome<void>
rasterization_state::
cull_face(face mode)
noexcept {
	OGLPLUS_GLFUNC(CullFace)(GLenum(mode));
	OGLPLUS_VERIFY(CullFace, gl_enum_value(mode), debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<face>
rasterization_state::
get_cull_face_mode(void)
noexcept {
	return face(GLenum(numeric_queries::get_integer(
		numeric_query(GL_CULL_FACE_MODE)
	)));
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5)
inline
outcome<void>
rasterization_state::
clip_control(clip_origin origin, clip_depth_mode depth)
noexcept {
	OGLPLUS_GLFUNC(ClipControl)(GLenum(origin), GLenum(depth));
	OGLPLUS_VERIFY(ClipControl, gl_enum_value(origin), debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
rasterization_state::
depth_func(compare_function func)
noexcept {
	OGLPLUS_GLFUNC(DepthFunc)(GLenum(func));
	OGLPLUS_VERIFY(DepthFunc, gl_enum_value(func), debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<compare_function>
rasterization_state::
get_depth_func(void)
noexcept {
	return compare_function(GLenum(numeric_queries::get_integer(
		numeric_query(GL_DEPTH_FUNC)
	)));
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_1)
inline
outcome<void>
rasterization_state::
depth_range_f(GLfloat near, GLfloat far)
noexcept {
	OGLPLUS_GLFUNC(DepthRangef)(near, far);
	OGLPLUS_VERIFY_SIMPLE(DepthRangef, debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_DOUBLE)
inline
outcome<void>
rasterization_state::
depth_range(GLdouble near, GLdouble far)
noexcept {
	OGLPLUS_GLFUNC(DepthRange)(near, far);
	OGLPLUS_VERIFY_SIMPLE(DepthRange, debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
#ifdef GL_VERSION_3_0
inline
outcome<void>
rasterization_state::
polygon_mode(face side, oglplus::polygon_mode mode)
noexcept {
	OGLPLUS_GLFUNC(PolygonMode)(GLenum(side), GLenum(mode));
	OGLPLUS_VERIFY(PolygonMode, gl_enum_value(mode), debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
rasterization_state::
polygon_offset(GLfloat factor, GLfloat units)
noexcept {
	OGLPLUS_GLFUNC(PolygonOffset)(factor, units);
	OGLPLUS_VERIFY_SIMPLE(PolygonOffset, debug);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_6) || defined(GL_EXT_polygon_offset_clamp)
inline
outcome<void>
rasterization_state::
polygon_offset_clamp(GLfloat factor, GLfloat units, GLfloat clamp)
noexcept {
#if defined(GL_VERSION_4_6)
	OGLPLUS_GLFUNC(PolygonOffsetClamp)(factor, units, clamp);
	OGLPLUS_VERIFY_SIMPLE(PolygonOffsetClamp, debug);
#elif defined(GL_EXT_polygon_offset_clamp)
	OGLPLUS_GLFUNC(PolygonOffsetClampEXT)(factor, units, clamp);
	OGLPLUS_VERIFY_SIMPLE(PolygonOffsetClampEXT, debug);
#endif
	return {};
}
#endif
//------------------------------------------------------------------------------
inline
outcome<GLfloat>
rasterization_state::
get_polygon_offset_factor(void)
noexcept {
	return numeric_queries::get_float(
		numeric_query(GL_POLYGON_OFFSET_FACTOR)
	);
}
//------------------------------------------------------------------------------
inline
outcome<GLfloat>
rasterization_state::
get_polygon_offset_units(void)
noexcept {
	return numeric_queries::get_float(
		numeric_query(GL_POLYGON_OFFSET_UNITS)
	);
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_6) || defined(GL_EXT_polygon_offset_clamp)
inline
outcome<GLfloat>
rasterization_state::
get_polygon_offset_clamp(void)
noexcept {
#if defined(GL_POLYGON_OFFSET_CLAMP)
	return numeric_queries::get_float(
		numeric_query(GL_POLYGON_OFFSET_CLAMP)
	);
#elif defined(GL_POLYGON_OFFSET_CLAMP_EXT)
	return numeric_queries::get_float(
		numeric_query(GL_POLYGON_OFFSET_CLAMP_EXT)
	);
#endif
}
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
rasterization_state::
line_width(GLfloat value)
noexcept {
	OGLPLUS_GLFUNC(LineWidth)(value);
	OGLPLUS_VERIFY_SIMPLE(LineWidth, debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<GLfloat>
rasterization_state::
get_line_width(void)
noexcept {
	return numeric_queries::get_float(numeric_query(GL_LINE_WIDTH));
}
//------------------------------------------------------------------------------
#ifdef GL_VERSION_3_0
inline
outcome<void>
rasterization_state::
point_size(GLfloat value)
noexcept {
	OGLPLUS_GLFUNC(PointSize)(value);
	OGLPLUS_VERIFY_SIMPLE(PointSize, debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<GLfloat>
rasterization_state::
get_point_size(void)
noexcept {
	return numeric_queries::get_float(numeric_query(GL_POINT_SIZE));
}
//------------------------------------------------------------------------------
inline
outcome<void>
rasterization_state::
point_parameter(oglplus::point_parameter param, GLfloat value)
noexcept {
	OGLPLUS_GLFUNC(PointParameterf)(GLenum(param), value);
	OGLPLUS_VERIFY(PointParameterf, gl_enum_value(param), debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<GLfloat>
rasterization_state::
get_point_parameter(oglplus::point_parameter param)
noexcept {
	return numeric_queries::get_float(numeric_query(GLenum(param)));
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_2) || defined(GL_ARB_provoking_vertex)
inline
outcome<void>
rasterization_state::
provoking_vertex(provoke_mode mode)
noexcept {
	OGLPLUS_GLFUNC(ProvokingVertex)(GLenum(mode));
	OGLPLUS_VERIFY(ProvokingVertex, gl_enum_value(mode), debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<provoke_mode>
rasterization_state::
get_provoking_vertex(void)
noexcept {
	return provoke_mode(GLenum(numeric_queries::get_integer(
		numeric_query(GL_PROVOKING_VERTEX)
	)));
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_0)
inline
outcome<void>
rasterization_state::
min_sample_shading(GLfloat value)
noexcept {
	OGLPLUS_GLFUNC(MinSampleShading)(value);
	OGLPLUS_VERIFY_SIMPLE(MinSampleShading, debug);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<GLfloat>
rasterization_state::
get_min_sample_shading_value(void)
noexcept {
	return numeric_queries::get_float(
		numeric_query(GL_MIN_SAMPLE_SHADING_VALUE)
	);
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
