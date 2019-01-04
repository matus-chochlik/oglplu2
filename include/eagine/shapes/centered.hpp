/**
 *  @file eagine/shapes/centered.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_CENTERED_HPP
#define EAGINE_SHAPES_CENTERED_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>
#include <eagine/math/functions.hpp>
#include <array>
#include <limits>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class centered_gen : public delegated_gen {

public:
    centered_gen(std::unique_ptr<generator_intf>&& gen) noexcept
      : delegated_gen(std::move(gen)) {
    }

    void attrib_values(vertex_attrib_kind attr, span<float> dest) override {

        delegated_gen::attrib_values(vertex_attrib_kind::position, dest);

        std::array<float, 4> min{std::numeric_limits<float>::max(),
                                 std::numeric_limits<float>::max(),
                                 std::numeric_limits<float>::max(),
                                 std::numeric_limits<float>::max()};

        std::array<float, 4> max{std::numeric_limits<float>::lowest(),
                                 std::numeric_limits<float>::lowest(),
                                 std::numeric_limits<float>::lowest(),
                                 std::numeric_limits<float>::lowest()};

        for(span_size_t v = 0, n = vertex_count(); v < n; ++v) {
            for(span_size_t c = 0, m = values_per_vertex(attr); c < m; ++c) {
                const auto k = std_size(c);

                min[k] = eagine::math::minimum(min[k], dest[v * m + c]);
                max[k] = eagine::math::maximum(max[k], dest[v * m + c]);
            }
        }

        std::array<float, 4> offs{{}};
        for(span_size_t c = 0, m = values_per_vertex(attr); c < m; ++c) {
            const auto k = std_size(c);
            offs[k] = (min[k] + max[k]) * 0.5f;
        }

        if(attr != vertex_attrib_kind::position) {
            delegated_gen::attrib_values(attr, dest);
        }

        const bool is_centered_attrib = attr == vertex_attrib_kind::position ||
                                        attr == vertex_attrib_kind::pivot;

        if(is_centered_attrib) {
            for(span_size_t v = 0, n = vertex_count(); v < n; ++v) {
                for(span_size_t c = 0, m = values_per_vertex(attr); c < m;
                    ++c) {
                    dest[v * m + c] -= offs[c];
                }
            }
        }
    }
};
//------------------------------------------------------------------------------
static inline auto center(std::unique_ptr<generator_intf>&& gen) noexcept {
    return std::unique_ptr<generator_intf>(new centered_gen(std::move(gen)));
}
//------------------------------------------------------------------------------

} // namespace shapes
} // namespace eagine

#endif // EAGINE_SHAPES_CENTERED_HPP
