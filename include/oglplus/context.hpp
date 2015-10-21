/**
 *  @file oglplus/context.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CONTEXT_1509260923_HPP
#define OGLPLUS_CONTEXT_1509260923_HPP

#include "ctxt/capabilities.hpp"
#include "ctxt/viewport.hpp"
#include "ctxt/buffer_clearing.hpp"
#include "ctxt/prog_var_location.hpp"
#include "ctxt/drawing.hpp"
#include "ctxt/synchronization.hpp"

#include "ctxt/object_lifetime.hpp"
#include "vertex_array.hpp"
#include "buffer.hpp"
#include "texture.hpp"
#include "shader.hpp"
#include "program.hpp"

#include "ctxt/vertex_attrib.hpp"
#include "ctxt/uniform.hpp"

#ifdef GL_ARB_compatibility
#include "ctxt/compatibility.hpp"
#endif

namespace oglplus {

class context
 : public ctxt::capability_state
 , public ctxt::viewport_state
 , public ctxt::buffer_clearing_state
 , public ctxt::buffer_clearing_ops
 , public ctxt::drawing_ops
 , public ctxt::synchronization

 , public ctxt::object_lifetime_ops
 , public ctxt::vertex_array_ops
 , public ctxt::buffer_ops
 , public ctxt::texture_ops
 , public ctxt::shader_ops
 , public ctxt::program_ops

 , public ctxt::prog_var_location_ops
 , public ctxt::vertex_attrib_ops
 , public ctxt::uniform_ops

#ifdef GL_ARB_compatibility
 , public ctxt::compatibility
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
