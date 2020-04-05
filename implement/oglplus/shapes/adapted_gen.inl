/**
 *  @file oglplus/shapes/adapted_gen.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>
#include <iostream>

namespace eagine {
namespace oglp {
namespace shapes {
//------------------------------------------------------------------------------
template <typename A>
inline adapted_generator::adapted_generator(
  const basic_gl_api<A>& api,
  std::unique_ptr<eagine::shapes::generator_intf>&& gen)
  : _gen{std::move(gen)} {
    using eagine::shapes::generator_capability;
    auto& GL = api.constants();

    if(GL.triangle_fan) {
        _gen->enable(generator_capability::element_fans);
    }
    if(GL.triangle_strip) {
        _gen->enable(generator_capability::element_strips);
    }
    if(GL.primitive_restart) {
        _gen->enable(generator_capability::primitive_restart);
    }
}
//------------------------------------------------------------------------------
inline void adapted_generator::attrib_data(
  eagine::shapes::vertex_attrib_kind attrib,
  span_size_t variant_index,
  memory::block data) const {
    using eagine::shapes::attrib_data_type;

    switch(_gen->attrib_type(attrib, variant_index)) {
        case attrib_data_type::float_:
            _gen->attrib_values(
              attrib,
              variant_index,
              accomodate(data, identity<gl_types::float_type>()));
            break;
        case attrib_data_type::none:
            break;
    }
}
//------------------------------------------------------------------------------
inline void adapted_generator::index_data(memory::block data) const {
    using eagine::shapes::index_data_type;

    switch(_gen->index_type()) {
        case index_data_type::unsigned_32:
            _gen->indices(accomodate(data, identity<GLuint>()));
            break;
        case index_data_type::unsigned_16:
            _gen->indices(accomodate(data, identity<GLushort>()));
            break;
        case index_data_type::unsigned_8:
            _gen->indices(accomodate(data, identity<GLubyte>()));
            break;
        case index_data_type::none:
            break;
    }
}
//------------------------------------------------------------------------------
template <typename A>
inline void adapted_generator::attrib_setup(
  const basic_gl_api<A>& api,
  vertex_array_name vao,
  buffer_name buf,
  vertex_attrib_location loc,
  eagine::shapes::vertex_attrib_kind attrib,
  span_size_t variant_index,
  memory::buffer& temp) const {
    using eagine::shapes::attrib_data_type;
    auto& [gl, GL] = api;

    const auto size = attrib_data_block_size(attrib, variant_index);
    auto data = head(cover(temp.ensure(size)), size);
    attrib_data(attrib, variant_index, data);

    gl.bind_buffer(GL.array_buffer, buf);
    gl.buffer_data(GL.array_buffer, data, GL.static_draw);

    gl.vertex_attrib_pointer(
      loc,
      values_per_vertex(attrib, variant_index),
      attrib_type(api, attrib, variant_index),
      is_attrib_normalized(api, attrib, variant_index));

    if(gl.enable_vertex_array_attrib) {
        gl.enable_vertex_array_attrib(vao, loc);
    } else {
        gl.enable_vertex_attrib_array(loc);
    }
}
//------------------------------------------------------------------------------
template <typename A>
inline void adapted_generator::instructions(
  const basic_gl_api<A>& api, span<draw_operation> ops) const {
    EAGINE_ASSERT(ops.size() >= operation_count());

    std::vector<eagine::shapes::draw_operation> tmp(
      std_size(operation_count()));
    _gen->instructions(cover(tmp));

    for(decltype(tmp.size()) i = 0; i < tmp.size(); ++i) {
        ops[span_size(i)] = draw_operation(api, tmp[i]);
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace oglp
} // namespace eagine
//------------------------------------------------------------------------------
