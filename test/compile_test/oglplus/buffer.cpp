/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/gl_fixed.hpp>
#include <oglplus/buffer.hpp>
#include "helper/object_c.hpp"

using namespace oglplus;

void oglplus_buffer_test_1(void)
{
	oglplus_object_name_test<buffer_name>();
	oglplus_object_test<buffer>();
}

void oglplus_buffer_test_ops1(void)
{
	using namespace oglplus;

	oper::buffer_ops gl;
	buffer buf;
	buffer_array<3> bufs;
	buffer_target tgt(GL_ARRAY_BUFFER);
	bound_buffer curbuf(tgt);
	buffer_data_spec data;
	buffer_size size;

	gl.bind_buffer(tgt, buf);
	gl.buffer_binding(tgt);
	gl.bind_buffer(tgt, bufs[0]);

	gl.buffer_data(tgt, data, buffer_usage(GL_STATIC_DRAW));
	gl.buffer_sub_data(tgt, size, data);
#if defined(GL_VERSION_3_1) || defined(GL_ARB_copy_buffer)
	gl.copy_buffer_sub_data(tgt, tgt, size, size, size);
#endif

	gl.buffer_size(tgt);
	gl.buffer_mapped(tgt);
	gl.buffer_usage(tgt);
#if defined(GL_VERSION_4_4) || defined(GL_ARB_buffer_storage)
	gl.buffer_storage(tgt, data, buffer_storage_bits());
	gl.buffer_immutable_storage(tgt);
	gl.buffer_storage_flags(tgt);
#endif

#if defined(GL_NV_shader_buffer_load)
	gl.make_buffer_resident(tgt, access_specifier(GL_READ_ONLY));
	gl.make_buffer_resident(buf, access_specifier(GL_READ_ONLY));
	gl.make_buffer_non_resident(tgt);
	gl.make_buffer_non_resident(buf);
	gl.is_buffer_resident(tgt);
	gl.is_buffer_resident(buf);
	gl.buffer_gpu_address(tgt);
	gl.buffer_gpu_address(buf);
#endif

	curbuf.data(data, buffer_usage(GL_STATIC_DRAW));
	curbuf.sub_data(size, data);
	curbuf.size();
	curbuf.mapped();
	curbuf.usage();
#if defined(GL_VERSION_4_4) || defined(GL_ARB_buffer_storage)
	curbuf.storage(data, buffer_storage_bits());
	curbuf.immutable_storage();
	curbuf.storage_flags();
#endif

#if defined(GL_NV_shader_buffer_load)
	curbuf.make_resident(access_specifier(GL_READ_ONLY));
	curbuf.make_non_resident();
	curbuf.is_resident();
	curbuf.gpu_address();
#endif

#if defined(GL_VERSION_4_3) || defined(GL_ARB_invalidate_subdata)
	gl.invalidate_buffer_data(buf);
	gl.invalidate_buffer_sub_data(buf, size, size);
#endif

#if defined(GL_VERSION_4_5) ||\
	defined(GL_ARB_direct_state_access) ||\
	defined(GL_EXT_direct_state_access)

	gl.buffer_data(buf, data, buffer_usage(GL_STATIC_DRAW));
	gl.buffer_sub_data(buf, size, data);
	gl.copy_buffer_sub_data(buf, buf, size, size, size);

	gl.buffer_size(buf);
	gl.buffer_mapped(buf);
	gl.buffer_usage(buf);
#if defined(GL_VERSION_4_4) || defined(GL_ARB_buffer_storage)
	gl.buffer_storage(buf, data, buffer_storage_bits());
	gl.buffer_immutable_storage(buf);
	gl.buffer_storage_flags(buf);
#endif

	buf.data(data, buffer_usage(GL_STATIC_DRAW));
	buf.sub_data(size, data);
	buf.size();
	buf.mapped();
	buf.usage();
#if defined(GL_VERSION_4_4) || defined(GL_ARB_buffer_storage)
	buf.storage(data, buffer_storage_bits());
	buf.immutable_storage();
	buf.storage_flags();
#endif

#if defined(GL_NV_shader_buffer_load)
	buf.make_resident(access_specifier(GL_READ_ONLY));
	buf.make_non_resident();
	buf.is_resident();
	buf.gpu_address();
#endif
#endif
}

// TODO
