/**
 *  @file oglplus/shapes/drawing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_DRAWING_1509260923_HPP
#define OGLPLUS_SHAPES_DRAWING_1509260923_HPP

#include <eagine/shapes/drawing.hpp>
#include "../config/basic.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace shapes {

class draw_operation
{
private:
	static
	primitive_type
	_translate(eagine::shapes::primitive_type)
	noexcept;

	static
	data_type
	_translate(eagine::shapes::index_data_type)
	noexcept;

	static
	GLuint
	_byte_mult(eagine::shapes::index_data_type)
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

	draw_operation(const eagine::shapes::draw_operation& draw_op)
	noexcept;

	outcome<void> draw(void) const
	noexcept;
};

} // namespace shapes
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/shapes/drawing.inl>
#endif

#endif // include guard
