/**
 *  @file eagine/shapes/array.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_ARRAY_HPP
#define EAGINE_SHAPES_ARRAY_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>
#include <array>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class array_gen : public delegated_gen {
private:
    std::array<float, 3> _d;
    span_size_t _copies;

    template <typename T>
    void _indices(span<T> dest) noexcept;

public:
    array_gen(
      std::unique_ptr<generator_intf>&& gen,
      std::array<float, 3> d,
      span_size_t n) noexcept
      : delegated_gen(std::move(gen))
      , _d{d}
      , _copies{n} {
    }

    span_size_t vertex_count() override;

    void attrib_values(vertex_attrib_kind, span<float>, span_size_t) override;

    index_data_type index_type() override;

    span_size_t index_count() override;

    void indices(span<std::uint8_t> dest) override;

    void indices(span<std::uint16_t> dest) override;

    void indices(span<std::uint32_t> dest) override;

    span_size_t operation_count() override;

    void instructions(span<draw_operation> ops) override;

    math::sphere<float, true> bounding_sphere() override;
};
//------------------------------------------------------------------------------
static inline auto array(
  std::unique_ptr<generator_intf>&& gen,
  std::array<float, 3> d,
  span_size_t count) noexcept {
    return std::make_unique<array_gen>(std::move(gen), d, count);
}
//------------------------------------------------------------------------------
static inline auto ortho_array_xyz(
  std::unique_ptr<generator_intf>&& gen,
  std::array<float, 3> d,
  std::array<span_size_t, 3> n) noexcept {
    const float z = 0.0f;
    return array(
      array(array(std::move(gen), {d[0], z, z}, n[0]), {z, d[1], z}, n[1]),
      {z, z, d[2]},
      n[2]);
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/array.inl>
#endif

#endif // EAGINE_SHAPES_ARRAY_HPP
