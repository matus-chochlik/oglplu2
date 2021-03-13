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
/// @see shapes
class mesh_edge {
public:
    mesh_edge(
      mesh_triangle& a,
      std::uint8_t ae,
      mesh_triangle& b,
      std::uint8_t be) noexcept
      : _triangles{{&a, &b}}
      , _edge_indices{{ae, be}} {}

    /// @brief Returns one of the two adjacent triangle faces.
    /// @pre i < 2
    auto triangle(std::size_t i) const noexcept -> const mesh_triangle& {
        EAGINE_ASSERT(i < 2);
        return *_triangles[i];
    }

    /// @brief Returns the edge index in the i-th adjacent triangles.
    /// @pre i < 2
    auto edge_index(std::size_t i) const noexcept -> unsigned {
        EAGINE_ASSERT(i < 2);
        return _edge_indices[i];
    }

private:
    std::array<mesh_triangle*, 2> _triangles;
    std::array<std::uint8_t, 2> _edge_indices;
};
//------------------------------------------------------------------------------
class mesh_triangle {
public:
    mesh_triangle(
      std::size_t tri_idx,
      unsigned a,
      unsigned b,
      unsigned c) noexcept
      : _tri_idx{tri_idx}
      , _indices{{a, b, c}} {}

    auto index() const noexcept {
        return _tri_idx;
    }

    static auto setup_adjacent(
      mesh_triangle& l,
      mesh_triangle& r,
      const topology_data& d) noexcept
      -> std::tuple<bool, std::uint8_t, std::uint8_t>;

    auto adjacent_triangle(std::size_t v) const noexcept
      -> const mesh_triangle* {
        EAGINE_ASSERT(v < 3);
        return _adjacent[v];
    }

    auto opposite_vertex(std::size_t v) const noexcept -> unsigned {
        EAGINE_ASSERT(v < 3);
        return _opposite[v];
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
class topology {
public:
    topology(
      std::shared_ptr<generator_base> gen,
      drawing_variant var,
      vertex_attrib_variant vav)
      : _gen{std::move(gen)} {
        _scan_topology(var, vav);
    }

    topology(const std::shared_ptr<generator_base>& gen)
      : topology{gen, gen->draw_variant(0), {vertex_attrib_kind::position}} {}

    auto print_dot(std::ostream& out) const -> std::ostream&;

private:
    template <typename I>
    static auto to_index(I i) noexcept
      -> std::enable_if_t<std::is_integral_v<I>, unsigned> {
        return limit_cast<unsigned>(i);
    }

    void _scan_topology(drawing_variant var, vertex_attrib_variant vav);

    std::shared_ptr<generator_base> _gen;
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
