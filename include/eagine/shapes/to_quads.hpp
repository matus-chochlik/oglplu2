/**
 *  @file eagine/shapes/to_quads.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_TO_QUADS_HPP
#define EAGINE_SHAPES_TO_QUADS_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>
#include <vector>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class to_quads_gen : public delegated_gen {
private:
    template <typename T>
    void _indices(span<T> dest) noexcept;

    std::vector<draw_operation> _ops;
    std::vector<std::uint32_t> _idx;

public:
    to_quads_gen(std::unique_ptr<generator_intf>&& gen) noexcept;

    span_size_t index_count() override;

    void indices(span<std::uint8_t> dest) override;

    void indices(span<std::uint16_t> dest) override;

    void indices(span<std::uint32_t> dest) override;

    span_size_t operation_count() override;

    void instructions(span<draw_operation> ops) override;
};
//------------------------------------------------------------------------------
static inline auto to_quads(std::unique_ptr<generator_intf>&& gen) noexcept {
    return std::unique_ptr<generator_intf>(new to_quads_gen(std::move(gen)));
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/shapes/to_quads.inl>
#endif

#endif // EAGINE_SHAPES_TO_QUADS_HPP
