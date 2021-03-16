/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SHAPES_ADJACENCY_HPP
#define EAGINE_SHAPES_ADJACENCY_HPP

#include "delegated.hpp"
#include "topology.hpp"
#include <eagine/config/basic.hpp>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
/// @brief Generator modifier adding triangle adjacency to drawing instructions
/// @ingroup shapes
/// @see triangle_adjacency
class triangle_adjacency_gen : public delegated_gen {
public:
    triangle_adjacency_gen(
      std::shared_ptr<generator> gen,
      drawing_variant var) noexcept
      : delegated_gen{std::move(gen)} {
        _topology(var);
    }

    triangle_adjacency_gen(std::shared_ptr<generator> gen) noexcept
      : triangle_adjacency_gen{std::move(gen), 0} {}

    auto index_type(const topology&) -> index_data_type;
    auto index_type(drawing_variant) -> index_data_type override;

    auto index_count(const topology&) -> span_size_t;
    auto index_count(drawing_variant) -> span_size_t override;

    void indices(drawing_variant, span<std::uint8_t> dest) override;

    void indices(drawing_variant, span<std::uint16_t> dest) override;

    void indices(drawing_variant, span<std::uint32_t> dest) override;

    auto operation_count(drawing_variant) -> span_size_t override;

    void instructions(drawing_variant, span<draw_operation> ops) override;

private:
    auto _topology(drawing_variant var) noexcept -> topology&;

    template <typename T>
    void _indices(drawing_variant, span<T> dest) noexcept;

    flat_map<drawing_variant, topology> _topologies;
};
//------------------------------------------------------------------------------
/// @brief Constructs instances of triangle_adjacency_gen modifier.
/// @ingroup shapes
static inline auto add_triangle_adjacency(
  std::shared_ptr<generator> gen,
  drawing_variant var) noexcept {
    return std::make_unique<triangle_adjacency_gen>(std::move(gen), var);
}
//------------------------------------------------------------------------------
/// @brief Constructs instances of triangle_adjacency_gen modifier.
/// @ingroup shapes
static inline auto
add_triangle_adjacency(std::shared_ptr<generator> gen) noexcept {
    return std::make_unique<triangle_adjacency_gen>(std::move(gen));
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/adjacency.inl>
#endif

#endif // EAGINE_SHAPES_ADJACENCY_HPP
