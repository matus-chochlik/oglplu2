/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
// clang-format off
#include "helper/object_c.hpp"
#include <oglplus/gl_fixed.hpp>
#include <oglplus/vertex_array.hpp>
// clang-format on

using namespace oglplus;

void
oglplus_vertex_array_test_1(void) {
    oglplus_object_name_test<vertex_array_name>();
    oglplus_object_test<vertex_array>();
}

void
oglplus_vertex_array_test_ops1(void) {
    using namespace oglplus;

    oper::vertex_array_ops gl;
    vertex_array vao;
    vertex_array_array<4> vaos;
    bound_vertex_array curvao;
    vertex_attrib_location loc(0);
    buffer_name buf(0);
    buffer_size size;

    gl.bind_vertex_array(vao);
    gl.vertex_array_binding();
    gl.bind_vertex_array(vaos[0]);

    gl.enable_vertex_array_attrib(loc);
    gl.disable_vertex_array_attrib(loc);
    gl.vertex_array_attrib_pointer(
      loc, 1, data_type(GL_FLOAT), true, 0, nullptr);
    gl.vertex_array_attrib_i_pointer(loc, 1, data_type(GL_INT), 0, nullptr);
#if defined(GL_VERSION_4_3) || defined(GL_ARB_vertex_attrib_binding)
    gl.vertex_array_vertex_buffer(1, buf, size, size);
    gl.vertex_array_attrib_binding(loc, 1);
    gl.vertex_array_binding_divisor(1, 4);
    gl.vertex_array_attrib_format(loc, 1, data_type(GL_FLOAT), true, 0);
    gl.vertex_array_attrib_i_format(loc, 1, data_type(GL_INT), 0);
    gl.vertex_array_attrib_l_format(loc, 1, data_type(GL_DOUBLE), 0);
#endif

#if defined(GL_NV_vertex_buffer_unified_memory)
    gl.buffer_address_range(
      unified_array_address_nv(GL_ELEMENT_ARRAY_UNIFIED_NV),
      0,
      buffer_address(0),
      10);
#endif

    curvao.enable_attrib(loc);
    curvao.disable_attrib(loc);
    curvao.attrib_pointer(loc, 1, data_type(GL_FLOAT), true, 0, nullptr);
    curvao.attrib_i_pointer(loc, 1, data_type(GL_INT), 0, nullptr);
#if defined(GL_VERSION_4_3) || defined(GL_ARB_vertex_attrib_binding)
    curvao.attrib_format(loc, 1, data_type(GL_FLOAT), true, 0);
    curvao.attrib_i_format(loc, 1, data_type(GL_INT), 0);
    curvao.attrib_l_format(loc, 1, data_type(GL_DOUBLE), 0);
#endif

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access) || \
  defined(GL_EXT_direct_state_access)

    vertex_array_attrib vaa(vao, loc);

    gl.enable_vertex_array_attrib(vao, loc);
    gl.disable_vertex_array_attrib(vao, loc);

    vaa.enable();
    vaa.disable();

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access)
    gl.vertex_array_vertex_buffer(vao, 1, buf, size, size);
    gl.vertex_array_attrib_binding(vao, loc, 1);
    gl.vertex_array_binding_divisor(vao, 1, 4);
    gl.vertex_array_attrib_format(vao, loc, 1, data_type(GL_FLOAT), false, 0);
    gl.vertex_array_attrib_i_format(vao, loc, 1, data_type(GL_INT), 0);
    gl.vertex_array_attrib_l_format(vao, loc, 1, data_type(GL_DOUBLE), 0);

    vao.vertex_buffer(loc, buf, 0, 1);
    vao.attrib_format(loc, 1, data_type(GL_FLOAT), false, 0);
    vao.attrib_i_format(loc, 1, data_type(GL_INT), 0);
    vao.attrib_l_format(loc, 1, data_type(GL_DOUBLE), 0);

    vao.binding_divisor(1, 4);

    vaa.vertex_buffer(buf, 0, 1);
    vaa.format(1, data_type(GL_FLOAT), false, 0);
    vaa.i_format(1, data_type(GL_INT), 0);
    vaa.l_format(1, data_type(GL_FLOAT), 0);
#endif

#if defined(GL_EXT_direct_state_access)
    gl.vertex_array_attrib_offset(
      vao, buf, loc, 1, data_type(GL_FLOAT), true, 1, 0);
    gl.vertex_array_attrib_i_offset(
      vao, buf, loc, 1, data_type(GL_SHORT), 1, 0);

    vao.attrib_offset(buf, loc, 1, data_type(GL_FLOAT), true, 1, 0);
    vao.attrib_i_offset(buf, loc, 1, data_type(GL_SHORT), 1, 0);

    vaa.offset(buf, 1, data_type(GL_FLOAT), true, 1, 0);
    vaa.i_offset(buf, 1, data_type(GL_SHORT), 1, 0);
#endif

#endif
}

// TODO
