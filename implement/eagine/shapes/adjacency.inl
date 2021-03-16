/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/assert.hpp>
#include <eagine/math/functions.hpp>
#include <eagine/memory/span_algo.hpp>
#include <vector>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto triangle_adjacency_gen::_topology(drawing_variant var) noexcept
  -> topology& {
    auto pos = _topologies.find(var);
    if(pos == _topologies.end()) {
        pos = _topologies.emplace(var, delegated_gen::base_generator()).first;
    }
    return pos->second;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto triangle_adjacency_gen::index_count(const topology& topo) -> span_size_t {
    return topo.triangle_count() * 6;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto triangle_adjacency_gen::index_count(drawing_variant var) -> span_size_t {
    return index_count(_topology(var));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto triangle_adjacency_gen::index_type(const topology&) -> index_data_type {
    const auto count = delegated_gen::vertex_count();
    if(count > 65535) {
        return index_data_type::unsigned_32;
    }
    if(count > 255) {
        return index_data_type::unsigned_16;
    }
    return index_data_type::unsigned_8;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto triangle_adjacency_gen::index_type(drawing_variant var)
  -> index_data_type {
    return index_type(_topology(var));
}
//------------------------------------------------------------------------------
template <typename T>
void triangle_adjacency_gen::_indices(
  drawing_variant var,
  span<T> dest) noexcept {
    auto& topo = _topology(var);
    EAGINE_ASSERT(index_count(topo) <= dest.size());

    span_size_t i = 0;
    for(auto t : integer_range(topo.triangle_count())) {
        auto& tri = topo.triangle(t);
        for(auto v : integer_range(3)) {
            dest[i++] = tri.vertex_index(v);
            dest[i++] = tri.opposite_index(v);
        }
    }
    EAGINE_ASSERT(i == index_count(topo));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void triangle_adjacency_gen::indices(
  drawing_variant var,
  span<std::uint8_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void triangle_adjacency_gen::indices(
  drawing_variant var,
  span<std::uint16_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void triangle_adjacency_gen::indices(
  drawing_variant var,
  span<std::uint32_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto triangle_adjacency_gen::operation_count(drawing_variant) -> span_size_t {
    return 1;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void triangle_adjacency_gen::instructions(
  drawing_variant var,
  span<draw_operation> ops) {
    EAGINE_ASSERT(!ops.empty());

    auto& topo = _topology(var);
    auto& op = ops[0];

    op = {};
    op.first = 0;
    op.count = index_count(topo);
    op.phase = 0;
    op.mode = primitive_type::triangles_adjacency;
    op.idx_type = index_type(topo);
    op.cw_face_winding = true;
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
