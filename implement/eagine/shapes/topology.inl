/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/assert.hpp>
#include <eagine/math/tvec.hpp>
#include <iostream>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
struct topology_data {
    unsigned values_per_vertex{0U};
    std::vector<float> vertex_values;
    std::vector<unsigned> indices;
    std::vector<draw_operation> operations;

    auto values_of(unsigned i) const noexcept {
        EAGINE_ASSERT(values_per_vertex > 0);
        return head(
          skip(view(vertex_values), span_size(values_per_vertex * i)),
          span_size(values_per_vertex));
    }

    auto to_vec(span<const float> v) const noexcept {
        return math::tvec<float, 3, true>{v[0], v[1], v[2]};
    }

    auto vec_of(unsigned i) const noexcept {
        return to_vec(values_of(i));
    }

    auto distance_delta(const mesh_triangle& tri) const noexcept -> float {
        const auto a = vec_of(tri.vertex_index(0));
        const auto b = vec_of(tri.vertex_index(1));
        const auto c = vec_of(tri.vertex_index(2));
        return 0.1F *
               std::min(
                 std::min(distance(a, b), distance(b, c)), distance(a, c));
    }

    auto have_same_position(unsigned i, unsigned j, float delta) const noexcept
      -> bool {
        const auto p = vec_of(i);
        const auto q = vec_of(j);
        return distance(p, q) < delta;
    }

    auto is_same_vertex(unsigned i, unsigned j, float delta) const noexcept
      -> bool {
        return (i == j) || have_same_position(i, j, delta);
    }
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto mesh_triangle::setup_adjacent(
  mesh_triangle& l,
  mesh_triangle& r,
  const topology_data& topo) noexcept
  -> std::tuple<bool, std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t> {
    EAGINE_ASSERT(l.index() != r.index());
    const auto delta = topo.distance_delta(l);
    for(auto i : integer_range(std_size(3))) {
        for(auto j : integer_range(std_size(3))) {
            if(topo.is_same_vertex(l.curri(i), r.curri(j), delta)) {
                if(topo.is_same_vertex(l.previ(i), r.previ(j), delta)) {
                    l._adjacent[prevv(i)] = &r;
                    l._opposite[prevv(i)] = narrow(nextv(j));
                    r._adjacent[prevv(j)] = &l;
                    r._opposite[prevv(j)] = narrow(nextv(i));
                    return {
                      true,
                      narrow(prevv(i)),
                      narrow(i),
                      narrow(prevv(j)),
                      narrow(j)};
                } else if(topo.is_same_vertex(l.previ(i), r.nexti(j), delta)) {
                    l._adjacent[prevv(i)] = &r;
                    l._opposite[prevv(i)] = narrow(prevv(j));
                    r._adjacent[j] = &l;
                    r._opposite[j] = narrow(nextv(i));
                    return {
                      true,
                      narrow(prevv(i)),
                      narrow(i),
                      narrow(j),
                      narrow(nextv(j))};
                } else if(topo.is_same_vertex(l.nexti(i), r.previ(j), delta)) {
                    l._adjacent[i] = &r;
                    l._opposite[i] = narrow(nextv(j));
                    r._adjacent[prevv(j)] = &l;
                    r._opposite[prevv(j)] = narrow(prevv(i));
                    return {
                      true,
                      narrow(i),
                      narrow(nextv(i)),
                      narrow(prevv(j)),
                      narrow(j)};
                } else if(topo.is_same_vertex(l.nexti(i), r.nexti(j), delta)) {
                    l._adjacent[i] = &r;
                    l._opposite[i] = narrow(prevv(j));
                    r._adjacent[j] = &l;
                    r._opposite[j] = narrow(prevv(i));
                    return {
                      true,
                      narrow(i),
                      narrow(nextv(i)),
                      narrow(j),
                      narrow(nextv(j))};
                }
            }
        }
    }
    return {false, 0U, 0U, 0U, 0U};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto topology::print_dot(std::ostream& out) const -> std::ostream& {
    out << "graph MeshTopology {\n";
    out << "overlap=voronoi;\n";
    out << "node [shape=triangle];\n";

    for(const auto& tri : _triangles) {
        const auto i = tri.index();
        out << "t" << i << " [label=\"" << i << "\"];\n";
    }

    out << "node [shape=point];\n";
    for(const auto& [idxt, edg] : _edges) {
        auto [lidx, ridx] = idxt;

        out << "et" << lidx << "t" << ridx << ";\n";

        for(auto t : integer_range(std_size(2))) {
            auto [bi, ei] = edg.edge_vertices(t);
            auto& tri = edg.triangle(t);
            out << "et" << lidx << "t" << ridx << " -- "
                << "t" << tri.index() << "[label=\"<" << bi << "," << ei
                << ">\\n[" << tri.vertex_index(bi) << ","
                << tri.vertex_index(ei) << "]"
                << "\"];\n";
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

    data.indices.resize(std_size(_gen->index_count(var)));
    _gen->indices(var, cover(data.indices));

    data.operations.resize(std_size(_gen->operation_count(var)));
    _gen->instructions(var, cover(data.operations));

    for(auto& operation : data.operations) {
        const bool indexed = operation.idx_type != index_data_type::none;
        span_size_t i;

        auto is_pri = [&]() {
            return indexed &&
                   data.indices[i] == operation.primitive_restart_index;
        };

        auto add_triangle = [&](int a, int b, int c) {
            if(indexed) {
                _triangles.emplace_back(
                  _triangles.size(),
                  data.indices[std_size(operation.first + i + a)],
                  data.indices[std_size(operation.first + i + b)],
                  data.indices[std_size(operation.first + i + c)]);
            } else {
                _triangles.emplace_back(
                  _triangles.size(),
                  to_index(operation.first + i + a),
                  to_index(operation.first + i + b),
                  to_index(operation.first + i + c));
            }
        };

        if(operation.mode == primitive_type::triangles) {
            for(i = 0; i < operation.count; i += 3) {
                if(operation.cw_face_winding) {
                    add_triangle(0, 1, 2);
                } else {
                    add_triangle(0, 2, 1);
                }
            }
        } else if(operation.mode == primitive_type::triangle_strip) {
            for(i = 2; i < operation.count; i += 2) {
                if(is_pri()) {
                    ++i;
                    continue;
                }
                if(operation.cw_face_winding) {
                    add_triangle(-2, -1, 0);
                    add_triangle(0, -1, 1);
                } else {
                    add_triangle(-1, -2, 0);
                    add_triangle(-1, 0, 1);
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
                    auto [should_add, leb, lee, reb, ree] =
                      mesh_triangle::setup_adjacent(ltri, rtri, data);
                    if(should_add) {
                        _edges.emplace(
                          key, mesh_edge{ltri, leb, lee, rtri, reb, ree});
                    }
                }
            }
        }
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
