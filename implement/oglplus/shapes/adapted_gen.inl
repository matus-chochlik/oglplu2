/**
 *  @file oglplus/shapes/adapted_gen.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>
#include <vector>

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
    const basic_gl_constants<A>& GL = api;

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
void adapted_generator::instructions(
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
