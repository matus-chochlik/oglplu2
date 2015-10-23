/**
 *  @file oglplus/operations.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPERATIONS_1509260923_HPP
#define OGLPLUS_OPERATIONS_1509260923_HPP

#include "oper/capabilities.hpp"
#include "oper/viewport.hpp"
#include "oper/buffer_clearing.hpp"
#include "oper/prog_var_location.hpp"
#include "oper/drawing.hpp"
#include "oper/synchronization.hpp"

#include "oper/object_lifetime.hpp"
#include "vertex_array.hpp"
#include "buffer.hpp"
#include "texture.hpp"
#include "shader.hpp"
#include "program.hpp"

#include "oper/vertex_attrib.hpp"
#include "oper/uniform.hpp"

#ifdef GL_ARB_compatibility
#include "oper/compatibility.hpp"
#endif

namespace oglplus {

class operations
 : public oper::capability_state
 , public oper::viewport_state
 , public oper::buffer_clearing_state
 , public oper::buffer_clearing_ops
 , public oper::drawing_ops
 , public oper::synchronization

 , public oper::object_lifetime_ops
 , public oper::vertex_array_ops
 , public oper::buffer_ops
 , public oper::texture_ops
 , public oper::shader_ops
 , public oper::program_ops

 , public oper::prog_var_location_ops
 , public oper::vertex_attrib_ops
 , public oper::uniform_ops

#ifdef GL_ARB_compatibility
 , public oper::compatibility
#endif
{
public:
	static
	auto bind(vertex_array_name vao)
	noexcept
	{
		return bind_vertex_array(vao);
	}

	static
	auto bind(buffer_target tgt, buffer_name buf)
	noexcept
	{
		return bind_buffer(tgt, buf);
	}

	static
	auto bind(texture_target tgt, texture_name tex)
	noexcept
	{
		return bind_texture(tgt, tex);
	}

	static
	auto use(program_name prg)
	noexcept
	{
		return use_program(prg);
	}
};

} // namespace oglplus

#endif // include guard
