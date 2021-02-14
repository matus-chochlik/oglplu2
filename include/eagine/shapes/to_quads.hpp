/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SHAPES_TO_QUADS_HPP
#define EAGINE_SHAPES_TO_QUADS_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class to_quads_gen : public delegated_gen {
private:
    template <typename T>
    void _indices(drawing_variant, span<T> dest) noexcept;

public:
    to_quads_gen(std::unique_ptr<generator_intf>&& gen) noexcept
      : delegated_gen(std::move(gen)) {}

    auto index_count(drawing_variant) -> span_size_t override;

    void indices(drawing_variant, span<std::uint8_t> dest) override;

    void indices(drawing_variant, span<std::uint16_t> dest) override;

    void indices(drawing_variant, span<std::uint32_t> dest) override;

    auto operation_count(drawing_variant) -> span_size_t override;

    void instructions(drawing_variant, span<draw_operation> ops) override;
};
//------------------------------------------------------------------------------
static inline auto to_quads(std::unique_ptr<generator_intf>&& gen) noexcept {
    return std::make_unique<to_quads_gen>(std::move(gen));
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/to_quads.inl>
#endif

#endif // EAGINE_SHAPES_TO_QUADS_HPP
