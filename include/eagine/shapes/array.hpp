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
#include <eagine/memory/span_algo.hpp>
#include <array>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
class array_gen : public delegated_gen {
private:
    std::array<float, 3> _d;
    span_size_t _copies;

public:
    array_gen(
      std::unique_ptr<generator_intf>&& gen,
      std::array<float, 3> d,
      span_size_t n) noexcept
      : delegated_gen(std::move(gen))
      , _d{d}
      , _copies{n} {
    }

    span_size_t vertex_count() override {
        return delegated_gen::vertex_count() * _copies;
    }

    span_size_t index_count() override {
        return delegated_gen::index_count() * _copies;
    }

    span_size_t operation_count() override {
        return delegated_gen::operation_count() * _copies;
    }

    index_data_type index_type() override {
        if(delegated_gen::index_type() != index_data_type::none) {
            if(delegated_gen::vertex_count() < span_size(1 << 8)) {
                return index_data_type::unsigned_byte;
            }
            if(delegated_gen::vertex_count() < span_size(1 << 16)) {
                return index_data_type::unsigned_short;
            }
            return index_data_type::unsigned_int;
        }
        return index_data_type::none;
    }

    void attrib_values(vertex_attrib_kind attr, span<float> dest) override {

        const auto n = delegated_gen::vertex_count();
        const auto m = values_per_vertex(attr);

        delegated_gen::attrib_values(attr, head(dest, n * m));

        const bool is_translated_attrib =
          attr == vertex_attrib_kind::position ||
          attr == vertex_attrib_kind::pivot;

        if(is_translated_attrib) {
            for(span_size_t i = 1; i < _copies; ++i) {
                for(span_size_t v = 0; v < n; ++v) {
                    for(span_size_t c = 0; c < m; ++c) {

                        const auto k = v * m + c;
                        dest[(i * n * m) + k] = dest[k] + (_d[c] * float(i));
                    }
                }
            }
        } else {
            const auto l = n * m;
            for(span_size_t i = 1; i < _copies; ++i) {
                copy(head(dest, l), slice(dest, i * l, l));
            }
        }
    }

    void indices(span<unsigned> dest) override {

        const auto n = delegated_gen::index_count();
        const auto opri = unsigned(n);
        const auto npri = unsigned(index_count());

        delegated_gen::indices(head(dest, n));

        for(span_size_t i = 1; i < _copies; ++i) {
            const auto k = i * n;
            for(span_size_t j = 0; j < n; ++j) {
                auto idx = dest[j];
                if(idx >= opri) {
                    idx = npri;
                }
                dest[k + j] = idx + limit_cast<unsigned>(k);
            }
        }
    }

    void instructions(span<draw_operation> ops) override {
        const auto n = delegated_gen::operation_count();

        delegated_gen::instructions(head(ops, n));

        if(index_type() != index_data_type::none) {
            const auto p = delegated_gen::index_count();
            const auto opri = unsigned(p);
            const auto npri = unsigned(index_count());

            for(span_size_t o = 0; o < n; ++o) {
                if(ops[o].primitive_restart_index == opri) {
                    ops[o].primitive_restart_index = npri;
                }
            }

            for(span_size_t i = 1; i < _copies; ++i) {
                const auto k = i * n;
                const auto a = i * p;
                for(span_size_t o = 0; o < n; ++o) {
                    const auto l = k + o;
                    ops[l] = ops[o];
                    ops[l].first = ops[o].first + a;
                }
            }
        } else {
            const auto p = delegated_gen::vertex_count();

            for(span_size_t i = 1; i < _copies; ++i) {
                const auto k = i * n;
                const auto a = i * p;
                for(span_size_t o = 0; o < n; ++o) {
                    const auto l = k + o;
                    ops[l] = ops[o];
                    ops[l].first = ops[o].first + a;
                }
            }
        }
    }
};
//------------------------------------------------------------------------------
static inline auto array(
  std::unique_ptr<generator_intf>&& gen,
  std::array<float, 3> d,
  span_size_t count) noexcept {
    return std::unique_ptr<generator_intf>(
      new array_gen(std::move(gen), d, count));
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

#endif // EAGINE_SHAPES_ARRAY_HPP
