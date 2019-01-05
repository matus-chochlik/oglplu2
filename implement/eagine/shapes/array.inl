/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/memory/span_algo.hpp>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
index_data_type array_gen::index_type() {
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
//------------------------------------------------------------------------------
void array_gen::attrib_values(vertex_attrib_kind attr, span<float> dest) {

    const auto n = delegated_gen::vertex_count();
    const auto m = values_per_vertex(attr);

    delegated_gen::attrib_values(attr, head(dest, n * m));

    const bool is_translated_attrib =
      attr == vertex_attrib_kind::position || attr == vertex_attrib_kind::pivot;

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
//------------------------------------------------------------------------------
void array_gen::indices(span<unsigned> dest) {

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
//------------------------------------------------------------------------------
void array_gen::instructions(span<draw_operation> ops) {
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
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
