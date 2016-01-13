/**
 *  @file oglplus/shape/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPE_DRAWING_1509260923_HPP
#define OGLPLUS_SHAPE_DRAWING_1509260923_HPP

#include <eagine/shapes/drawing.hpp>
#include "../config/basic.hpp"
#include "../utils/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace shape {

class draw_operation
{
private
	static
	primitive_type
	_translate(eagine::shape::primitive_type)
	noexcept;

	static
	data_type
	_translate(eagine::shape::index_type)
	noexcept;

	static
	GLuint
	_byte_mult(eagine::shape::index_type)
	noexcept;

	primitive_type _mode;
	data_type _idx_type;
	GLuint _first;
	GLuint _count;
	GLuint _phase;
	GLuint _primitive_restart_index;
	bool _primitive_restart;

public:
	constexpr
	draw_operation(void)
	noexcept
	 : _mode(primitive_type(GL_NONE))
	 , _idx_type(data_type(GL_NONE))
	 , _first(0)
	 , _count(0)
	 , _phase(0)
	 , _primitive_restart_index(0)
	 , _primitive_restart(false)
	{ }

	bool indexed(void) const
	noexcept;

	draw_operation(const eagine::shape::draw_operation& draw_op)
	noexcept;

	outcome<void> draw(void) const
	noexcept;
};

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/shape/drawing.inl>
#endif

} // namespace shape
} // namespace oglplus

#endif // include guard
