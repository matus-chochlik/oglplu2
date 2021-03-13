/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/assert.hpp>
#include <iostream>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
struct topology_data {
    unsigned values_per_vertex{0U};
    std::vector<float> vertex_values;
    std::vector<unsigned> vertex_indices;
    std::vector<draw_operation> operations;

    auto values_of(unsigned i) const noexcept {
        EAGINE_ASSERT(values_per_vertex > 0);
        return head(
          skip(view(vertex_values), span_size(values_per_vertex * i)),
          span_size(values_per_vertex));
    }

    auto is_same_vertex(unsigned i, unsigned j) const noexcept -> bool {
        return (i == j) || are_equal(values_of(i), values_of(j));
    }
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto mesh_triangle::setup_adjacent(
  mesh_triangle& l,
  mesh_triangle& r,
  const topology_data& d) noexcept
  -> std::tuple<bool, std::uint8_t, std::uint8_t> {
    EAGINE_ASSERT(l.index() != r.index());
    for(auto i : integer_range(std_size(3))) {
        for(auto j : integer_range(std_size(3))) {
            if(d.is_same_vertex(l.curri(i), r.curri(j))) {
                if(d.is_same_vertex(l.previ(i), r.previ(j))) {
                    l._adjacent[prevv(i)] = &r;
                    l._opposite[prevv(i)] = narrow(nextv(j));
                    r._adjacent[prevv(j)] = &l;
                    r._opposite[prevv(j)] = narrow(nextv(i));
                    return {true, narrow(prevv(i)), narrow(prevv(j))};
                } else if(d.is_same_vertex(l.previ(i), r.nexti(j))) {
                    l._adjacent[prevv(i)] = &r;
                    l._opposite[prevv(i)] = narrow(nextv(j));
                    r._adjacent[j] = &l;
                    r._opposite[j] = narrow(nextv(i));
                    return {true, narrow(prevv(i)), narrow(j)};
                } else if(d.is_same_vertex(l.nexti(i), r.previ(j))) {
                    l._adjacent[i] = &r;
                    l._opposite[i] = narrow(nextv(j));
                    r._adjacent[prevv(j)] = &l;
                    r._opposite[prevv(j)] = narrow(prevv(i));
                    return {true, narrow(i), narrow(prevv(j))};
                } else if(d.is_same_vertex(l.nexti(i), r.nexti(j))) {
                    l._adjacent[i] = &r;
                    l._opposite[i] = narrow(prevv(j));
                    r._adjacent[j] = &l;
                    r._opposite[j] = narrow(prevv(i));
                    return {true, narrow(i), narrow(j)};
                }
            }
        }
    }
    return {false, 0U, 0U};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto topology::print_dot(std::ostream& out) const -> std::ostream& {
    out << "graph MeshTopology {\n";
    out << "splines=true;\n";
    out << "overlap=voronoi;\n";
    out << "node [shape=egg];\n";

    for(const auto& tri : _triangles) {
        const auto i = tri.index();
        out << "t" << i << " [label=\"" << i << "\"];\n";
    }

    out << "node [shape=point];\n";
    for(const auto& [idxt, edg] : _edges) {
        auto [lidx, ridx] = idxt;

        out << "et" << lidx << "t" << ridx << ";\n";

        for(auto t : integer_range(std_size(2))) {
            out << "et" << lidx << "t" << ridx << " -- "
                << "t" << edg.triangle(t).index()
                << "[label=" << edg.edge_index(t) << "];\n";
        }
    }
    out << "}";
    return out;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void topology::_scan_topology(drawing_variant var, vertex_attrib_variant vav) {
    topology_data data;
    data.values_per_vertex = std_size(_gen->values_per_vertex(vav));

    data.vertex_values.resize(std_size(_gen->value_count(vav)));
    _gen->attrib_values(vav, cover(data.vertex_values));

    data.vertex_indices.resize(std_size(_gen->index_count(var)));
    _gen->indices(var, cover(data.vertex_indices));

    data.operations.resize(std_size(_gen->operation_count(var)));
    _gen->instructions(var, cover(data.operations));
    for(auto& operation : data.operations) {
        if(operation.mode == primitive_type::triangles) {
            if(operation.idx_type == index_data_type::none) {
                for(span_size_t i = 0; i < operation.count; i += 3) {
                    _triangles.emplace_back(
                      _triangles.size(),
                      to_index(operation.first + i + 0),
                      to_index(operation.first + i + 1),
                      to_index(operation.first + i + 2));
                }
            } else {
                for(span_size_t i = 0; i < operation.count; i += 3) {
                    _triangles.emplace_back(
                      _triangles.size(),
                      data.vertex_indices[std_size(operation.first + i + 0)],
                      data.vertex_indices[std_size(operation.first + i + 1)],
                      data.vertex_indices[std_size(operation.first + i + 2)]);
                }
            }
        }
    }

    for(auto& ltri : _triangles) {
        const auto lidx = ltri.index();
        for(auto& rtri : _triangles) {
            const auto ridx = rtri.index();
            if(lidx < ridx) {
                auto key =
                  std::make_tuple(std::min(lidx, ridx), std::max(lidx, ridx));
                if(_edges.find(key) == _edges.end()) {
                    auto [should_add, leidx, reidx] =
                      mesh_triangle::setup_adjacent(ltri, rtri, data);
                    if(should_add) {
                        _edges.emplace(
                          key, mesh_edge{ltri, leidx, rtri, reidx});
                    }
                }
            }
        }
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
