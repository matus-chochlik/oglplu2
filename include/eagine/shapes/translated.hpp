/**
 *  @file eagine/shapes/translated.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_TRANSLATED_HPP
#define EAGINE_SHAPES_TRANSLATED_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>
#include <array>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class translated_gen : public delegated_gen {
private:
    std::array<float, 3> _d;

public:
    translated_gen(
      std::unique_ptr<generator_intf>&& gen, std::array<float, 3> d) noexcept
      : delegated_gen(std::move(gen))
      , _d{d} {
    }

    void attrib_values(vertex_attrib_kind attr, span<float> dest) override {
        delegated_gen::attrib_values(attr, dest);

        const bool is_translated_attrib =
          attr == vertex_attrib_kind::position ||
          attr == vertex_attrib_kind::pivot;

        if(is_translated_attrib) {
            for(span_size_t v = 0, n = vertex_count(); v < n; ++v) {
                for(span_size_t c = 0, m = values_per_vertex(attr); c < m;
                    ++c) {
                    dest[v * m + c] += _d[c];
                }
            }
        }
    }
};
//------------------------------------------------------------------------------
static inline auto translate(
  std::unique_ptr<generator_intf>&& gen, std::array<float, 3> d) noexcept {
    return std::unique_ptr<generator_intf>(
      new translated_gen(std::move(gen), d));
}
//------------------------------------------------------------------------------

} // namespace shapes
} // namespace eagine

#endif // EAGINE_SHAPES_TRANSLATED_HPP
