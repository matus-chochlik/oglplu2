/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SHAPES_TOPOLOGY_HPP
#define EAGINE_SHAPES_TOPOLOGY_HPP

#include "gen_base.hpp"
#include <eagine/config/basic.hpp>
#include <eagine/flat_map.hpp>
#include <iosfwd>
#include <vector>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
struct topology_data;
class mesh_triangle;

/// @brief Class storing information about an edge between two mesh faces.
/// @ingroup  shapes
/// @see mesh_triangle
/// @see topology
class mesh_edge {
public:
    mesh_edge(
      mesh_triangle& a,
      std::uint8_t aeb,
      std::uint8_t aee,
      mesh_triangle& b,
      std::uint8_t beb,
      std::uint8_t bee) noexcept
      : _triangles{{&a, &b}}
      , _edge_indices{{aeb, aee, beb, bee}} {}

    /// @brief Returns one of the two adjacent triangle faces.
    /// @pre i >= 0 && i < 2
    auto triangle(span_size_t i) const noexcept -> const mesh_triangle& {
        EAGINE_ASSERT(i >= 0 && i < 2);
        return *_triangles[std_size(i)];
    }

    /// @brief Returns a pair of vertex indices (0,1 or 2) defining the i-th edge.
    /// @pre i >= 0 && i < 2
    auto edge_vertices(span_size_t i) const noexcept
      -> std::tuple<unsigned, unsigned> {
        EAGINE_ASSERT(i >= 0 && i < 2);
        return {
          _edge_indices[std_size(2 * i)], _edge_indices[std_size(2 * i + 1)]};
    }

private:
    std::array<mesh_triangle*, 2> _triangles;
    std::array<std::uint8_t, 4> _edge_indices;
};
//------------------------------------------------------------------------------
/// @brief Class storing information about a mesh tirangular face.
/// @ingroup  shapes
/// @see mesh_edge
/// @see topology
class mesh_triangle {
public:
    mesh_triangle(
      std::size_t tri_idx,
      unsigned a,
      unsigned b,
      unsigned c) noexcept
      : _tri_idx{tri_idx}
      , _indices{{a, b, c}} {}

    /// @brief Returns the index of this triangle within the mesh.
    auto index() const noexcept -> span_size_t {
        return span_size(_tri_idx);
    }

    static auto setup_adjacent(
      mesh_triangle& l,
      mesh_triangle& r,
      const topology_data& d) noexcept
      -> std::tuple<bool, std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t>;

    /// @brief Returns the v-th vertex index.
    /// @pre v >= 0 && v < 3
    auto vertex_index(span_size_t v) const noexcept {
        EAGINE_ASSERT(v >= 0 && v < 3);
        return _indices[std_size(v)];
    }

    /// @brief Returns the triangle adjacent through the v-th edge.
    /// @pre v >= 0 && v < 3
    /// @see opposite_vertex
    auto adjacent_triangle(span_size_t v) const noexcept
      -> const mesh_triangle* {
        EAGINE_ASSERT(v >= 0 && v < 3);
        return _adjacent[std_size(v)];
    }

    /// @brief Returns opposite vertex index (0,1 or 2) in the v-th adjacent triangle.
    /// @pre v >= 0 && v < 3
    /// @see adjacent_triangle
    /// @see opposite_index
    auto opposite_vertex(span_size_t v) const noexcept -> unsigned {
        EAGINE_ASSERT(v >= 0 && v < 3);
        return _opposite[std_size(v)];
    }

    /// @brief Returns the in-mesh index of the v-th adjacent vertex.
    /// @pre v >= 0 && v < 3
    /// @see opposite_vertex
    /// @see adjacent_triangle
    auto opposite_index(span_size_t v) const noexcept -> unsigned {
        if(auto tri{adjacent_triangle(v)}) {
            return extract(tri).vertex_index(opposite_vertex(v));
        }
        return _indices[(v + 2) % 3];
    }

private:
    auto curri(std::size_t i) const noexcept -> unsigned {
        return _indices[i];
    }

    static auto prevv(std::size_t i) noexcept -> unsigned {
        return (i + 2) % 3;
    }

    auto previ(std::size_t i) const noexcept -> unsigned {
        return _indices[prevv(i)];
    }

    static auto nextv(std::size_t i) noexcept -> unsigned {
        return (i + 1) % 3;
    }

    auto nexti(std::size_t i) const noexcept -> unsigned {
        return _indices[nextv(i)];
    }

    static auto narrow(std::size_t i) noexcept -> std::uint8_t {
        return limit_cast<std::uint8_t>(i);
    }

    std::size_t _tri_idx{~0U};
    std::array<unsigned, 3> _indices{};
    std::array<mesh_triangle*, 3> _adjacent{{nullptr, nullptr, nullptr}};
    std::array<std::uint8_t, 3> _opposite{{0, 0, 0}};
};
//------------------------------------------------------------------------------
/// @brief Class holding information about the topology of a generated shape.
/// @ingroup shapes
/// @see mesh_edge
/// @see mesh_triangle
class topology {
public:
    /// @brief Construction from a generator, drawing and attribute variant.
    topology(
      std::shared_ptr<generator> gen,
      drawing_variant var,
      vertex_attrib_variant vav)
      : _gen{std::move(gen)} {
        _scan_topology(var, vav);
    }

    /// @brief Construction from a shape generator.
    topology(const std::shared_ptr<generator>& gen)
      : topology{gen, gen->draw_variant(0), {vertex_attrib_kind::position}} {}

    /// @brief Returns the number of triangles in the mesh.
    auto triangle_count() const noexcept -> span_size_t {
        return span_size(_triangles.size());
    }

    /// @brief Returns the i-th triangle in the mesh.
    auto triangle(span_size_t i) const noexcept -> const mesh_triangle& {
        return _triangles[std_size(i)];
    }

    auto print_dot(std::ostream& out) const -> std::ostream&;

private:
    template <typename I>
    static auto to_index(I i) noexcept
      -> std::enable_if_t<std::is_integral_v<I>, unsigned> {
        return limit_cast<unsigned>(i);
    }

    void _scan_topology(drawing_variant var, vertex_attrib_variant vav);

    std::shared_ptr<generator> _gen;
    std::vector<mesh_triangle> _triangles;
    flat_map<std::tuple<unsigned, unsigned>, mesh_edge> _edges;
};
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/topology.inl>
#endif

#endif // EAGINE_SHAPES_TOPOLOGY_HPP
