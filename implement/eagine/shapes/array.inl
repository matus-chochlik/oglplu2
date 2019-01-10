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
span_size_t array_gen::vertex_count() {
    return delegated_gen::vertex_count() * _copies;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
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
                    dest[(i * n * m) + k] =
                      dest[k] + (_d[std_size(c)] * float(i));
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
EAGINE_LIB_FUNC
span_size_t array_gen::index_count() {
    return delegated_gen::index_count() * _copies;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
index_data_type array_gen::index_type() {
    if(delegated_gen::index_type() != index_data_type::none) {
        if(
          vertex_count() <
          span_size(std::numeric_limits<std::uint8_t>::max())) {
            return index_data_type::unsigned_8;
        }
        if(
          vertex_count() <
          span_size(std::numeric_limits<std::uint16_t>::max())) {
            return index_data_type::unsigned_16;
        }
        return index_data_type::unsigned_32;
    }
    return index_data_type::none;
}
//------------------------------------------------------------------------------
template <typename T>
void array_gen::_indices(span<T> dest) noexcept {
    const auto vc = delegated_gen::vertex_count();
    const auto ic = delegated_gen::index_count();
    const auto opri = limit_cast<T>(delegated_gen::vertex_count());
    const auto npri = limit_cast<T>(vertex_count());

    delegated_gen::indices(head(dest, ic));

    for(span_size_t i = 1; i < _copies; ++i) {
        const auto k = i * ic;
        const auto o = i * vc;
        for(span_size_t j = 0; j < ic; ++j) {
            auto idx = dest[j];
            if(idx >= opri) {
                idx = npri;
            }
            dest[k + j] = idx + limit_cast<T>(o);
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void array_gen::indices(span<std::uint8_t> dest) {
    _indices(dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void array_gen::indices(span<std::uint16_t> dest) {
    _indices(dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void array_gen::indices(span<std::uint32_t> dest) {
    _indices(dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t array_gen::operation_count() {
    const auto oc = delegated_gen::operation_count();
    if(oc == 1) {
        draw_operation op{};
        delegated_gen::instructions(cover_one(op));
        if(op.first == 0) {
            if(op.idx_type != index_data_type::none) {
                return 1;
            }
        }
    }
    return oc * _copies;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void array_gen::instructions(span<draw_operation> ops) {
    const auto oc = delegated_gen::operation_count();
    const auto ic = delegated_gen::index_count();
    const auto vc = delegated_gen::vertex_count();
    const auto opri = unsigned(vc);
    const auto npri = unsigned(vertex_count());
    const auto it = index_type();

    if(operation_count() == 1) {
        delegated_gen::instructions(head(ops, 1));
        draw_operation& op{ops[0]};
        op.count *= _copies;
        if(op.primitive_restart_index == opri) {
            op.primitive_restart_index = npri;
        }
        op.idx_type = it;
    } else {
        delegated_gen::instructions(head(ops, oc));

        if(it != index_data_type::none) {

            for(span_size_t o = 0; o < oc; ++o) {
                if(ops[o].primitive_restart_index == opri) {
                    ops[o].primitive_restart_index = npri;
                }
                ops[o].idx_type = it;
            }

            for(span_size_t i = 1; i < _copies; ++i) {
                const auto k = i * oc;
                const auto a = i * ic;
                for(span_size_t o = 0; o < oc; ++o) {
                    const auto l = k + o;
                    ops[l] = ops[o];
                    ops[l].first = ops[o].first + a;
                }
            }
        } else {

            for(span_size_t i = 1; i < _copies; ++i) {
                const auto k = i * oc;
                const auto a = i * vc;
                for(span_size_t o = 0; o < oc; ++o) {
                    const auto l = k + o;
                    ops[l] = ops[o];
                    ops[l].first = ops[o].first + a;
                }
            }
        }
    }
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
