/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/assert.hpp>
#include <iostream>

namespace eagine::oglp {
//------------------------------------------------------------------------------
template <typename A>
inline shape_generator::shape_generator(
  const basic_gl_api<A>& api,
  std::shared_ptr<shapes::generator> gen)
  : _gen{std::move(gen)} {
    using shapes::generator_capability;
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
inline void shape_generator::attrib_data(
  shapes::vertex_attrib_variant vav,
  memory::block data) const {
    using shapes::attrib_data_type;

    switch(_gen->attrib_type(vav)) {
        case attrib_data_type::float_:
            _gen->attrib_values(
              vav, accomodate(data, type_identity<gl_types::float_type>()));
            break;
        case attrib_data_type::ubyte:
            _gen->attrib_values(
              vav, accomodate(data, type_identity<gl_types::ubyte_type>()));
            break;
        case attrib_data_type::uint_16: // TODO
        case attrib_data_type::uint_32: // TODO
        case attrib_data_type::int_16:  // TODO
        case attrib_data_type::int_32:  // TODO
        case attrib_data_type::none:
            break;
    }
}
//------------------------------------------------------------------------------
inline void shape_generator::index_data(
  shapes::drawing_variant dv,
  memory::block data) const {
    using shapes::index_data_type;

    switch(_gen->index_type()) {
        case index_data_type::unsigned_32:
            _gen->indices(dv, accomodate(data, type_identity<GLuint>()));
            break;
        case index_data_type::unsigned_16:
            _gen->indices(dv, accomodate(data, type_identity<GLushort>()));
            break;
        case index_data_type::unsigned_8:
            _gen->indices(dv, accomodate(data, type_identity<GLubyte>()));
            break;
        case index_data_type::none:
            break;
    }
}
//------------------------------------------------------------------------------
template <typename A>
inline void shape_generator::attrib_setup(
  const basic_gl_api<A>& api,
  vertex_array_name vao,
  buffer_name buf,
  vertex_attrib_location loc,
  shapes::vertex_attrib_variant vav,
  memory::buffer& temp) const {
    using shapes::attrib_data_type;
    auto& [gl, GL] = api;

    const auto size = attrib_data_block_size(vav);
    auto data = head(cover(temp.ensure(size)), size);
    attrib_data(vav, data);

    gl.bind_buffer(GL.array_buffer, buf);
    gl.buffer_data(GL.array_buffer, data, GL.static_draw);

    gl.vertex_attrib_pointer(
      loc,
      gl_types::int_type(values_per_vertex(vav)),
      attrib_type(api, vav),
      is_attrib_normalized(api, vav));

    if(gl.enable_vertex_array_attrib) {
        gl.enable_vertex_array_attrib(vao, loc);
    } else {
        gl.enable_vertex_attrib_array(loc);
    }
}
//------------------------------------------------------------------------------
inline auto shape_generator::operation_count(
  span<const shapes::drawing_variant> dvs) const -> span_size_t {
    auto result = 0;
    for(auto dv : dvs) {
        result += _gen->operation_count(dv);
    }
    return result;
}
//------------------------------------------------------------------------------
template <typename A>
inline void shape_generator::index_setup(
  const basic_gl_api<A>& api,
  buffer_name buf,
  shapes::drawing_variant dv,
  memory::buffer& temp) const {
    auto& [gl, GL] = api;

    const auto size = index_data_block_size(dv);
    auto data = head(cover(temp.ensure(size)), size);
    index_data(dv, data);

    gl.bind_buffer(GL.element_array_buffer, buf);
    gl.buffer_data(GL.element_array_buffer, data, GL.static_draw);
}
//------------------------------------------------------------------------------
template <typename A>
inline void shape_generator::index_setup(
  const basic_gl_api<A>& api,
  buffer_name buf,
  span<const shapes::drawing_variant> dvs,
  memory::buffer& temp) const {
    auto& [gl, GL] = api;

    // TODO: buffer_storage + buffer_sub_data if available
    span_size_t total_size = 0;
    for(auto dv : dvs) {
        const auto size = index_data_block_size(dv);
        auto data =
          head(skip(cover(temp.ensure(total_size + size)), total_size), size);
        index_data(dv, data);
        total_size += size;
    }

    auto data = head(cover(temp), total_size);

    gl.bind_buffer(GL.element_array_buffer, buf);
    gl.buffer_data(GL.element_array_buffer, data, GL.static_draw);
}
//------------------------------------------------------------------------------
template <typename A>
inline void shape_generator::instructions(
  const basic_gl_api<A>& api,
  shapes::drawing_variant dv,
  span<shape_draw_operation> ops) const {
    EAGINE_ASSERT(ops.size() >= operation_count(dv));

    std::vector<shapes::draw_operation> tmp(std_size(operation_count(dv)));
    _gen->instructions(dv, cover(tmp));

    for(decltype(tmp.size()) i = 0; i < tmp.size(); ++i) {
        ops[span_size(i)] = shape_draw_operation(api, tmp[i]);
    }
}
//------------------------------------------------------------------------------
template <typename A>
inline void shape_generator::instructions(
  const basic_gl_api<A>& api,
  span<const shapes::drawing_variant> dvs,
  span<shape_draw_subset> subs,
  span<shape_draw_operation> ops) const {

    EAGINE_ASSERT(dvs.size() <= subs.size());
    std::vector<shapes::draw_operation> tmp{};
    span_size_t total_count = 0;
    span_size_t elem_offset = 0;

    for(span_size_t s = 0; s < dvs.size(); ++s) {
        auto& dv = dvs[s];
        const auto count = operation_count(dv);

        EAGINE_ASSERT(ops.size() >= total_count + count);
        tmp.resize(std_size(count));

        _gen->instructions(dv, cover(tmp));

        for(decltype(tmp.size()) i = 0; i < tmp.size(); ++i) {
            const auto k = total_count + span_size(i);
            ops[k] = shape_draw_operation(api, tmp[i]);
            ops[k].offset_first(elem_offset);
        }

        auto& sub = subs[s];
        sub.first = total_count;
        sub.count = count;

        total_count += count;
        elem_offset += index_data_block_size(dv);
    }
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp
//------------------------------------------------------------------------------
