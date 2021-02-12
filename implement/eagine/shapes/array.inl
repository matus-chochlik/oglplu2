/// @file eagine/shapes/array.inl
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/memory/span_algo.hpp>

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto array_gen::vertex_count() -> span_size_t {
    return delegated_gen::vertex_count() * _copies;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void array_gen::attrib_values(vertex_attrib_variant vav, span<float> dest) {

    const auto n = delegated_gen::vertex_count();
    const auto m = values_per_vertex(vav);

    delegated_gen::attrib_values(vav, head(dest, n * m));

    const bool is_translated_attrib = vav == vertex_attrib_kind::position ||
                                      vav == vertex_attrib_kind::pivot ||
                                      vav == vertex_attrib_kind::pivot_pivot ||
                                      vav == vertex_attrib_kind::vertex_pivot;

    if(is_translated_attrib) {
        for(auto i : integer_range(1, _copies)) {
            for(auto v : integer_range(n)) {
                for(auto c : integer_range(m)) {

                    const auto k = v * m + c;
                    dest[(i * n * m) + k] =
                      dest[k] + (_d[std_size(c)] * float(i));
                }
            }
        }
    } else {
        const auto l = n * m;
        for(auto i : integer_range(1, _copies)) {
            copy(head(dest, l), slice(dest, i * l, l));
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto array_gen::index_count(drawing_variant var) -> span_size_t {
    return delegated_gen::index_count(var) * _copies;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto array_gen::index_type(drawing_variant var) -> index_data_type {
    if(delegated_gen::index_type(var) != index_data_type::none) {
        if(vertex_count() < span_size(std::numeric_limits<std::uint8_t>::max())) {
            return index_data_type::unsigned_8;
        }
        if(vertex_count() < span_size(std::numeric_limits<std::uint16_t>::max())) {
            return index_data_type::unsigned_16;
        }
        return index_data_type::unsigned_32;
    }
    return index_data_type::none;
}
//------------------------------------------------------------------------------
template <typename T>
void array_gen::_indices(drawing_variant var, span<T> dest) noexcept {
    const auto vc = delegated_gen::vertex_count();
    const auto ic = delegated_gen::index_count(var);
    const auto opri = limit_cast<T>(delegated_gen::vertex_count());
    const auto npri = limit_cast<T>(vertex_count());

    delegated_gen::indices(var, head(dest, ic));

    for(auto i : integer_range(1, _copies)) {
        const auto k = i * ic;
        const auto o = i * vc;
        for(auto j : integer_range(ic)) {
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
void array_gen::indices(drawing_variant var, span<std::uint8_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void array_gen::indices(drawing_variant var, span<std::uint16_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void array_gen::indices(drawing_variant var, span<std::uint32_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto array_gen::operation_count(drawing_variant var) -> span_size_t {
    const auto oc = delegated_gen::operation_count(var);
    if(oc == 1) {
        draw_operation op{};
        delegated_gen::instructions(var, cover_one(op));
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
void array_gen::instructions(drawing_variant var, span<draw_operation> ops) {
    const auto oc = delegated_gen::operation_count(var);
    const auto ic = delegated_gen::index_count(var);
    const auto vc = delegated_gen::vertex_count();
    const auto opri = unsigned(vc);
    const auto npri = unsigned(vertex_count());
    const auto it = index_type(var);

    if(operation_count(var) == 1) {
        delegated_gen::instructions(var, head(ops, 1));
        draw_operation& op{ops[0]};
        op.count *= _copies;
        if(op.primitive_restart_index == opri) {
            op.primitive_restart_index = npri;
        }
        op.idx_type = it;
    } else {
        delegated_gen::instructions(var, head(ops, oc));

        if(it != index_data_type::none) {

            for(auto o : integer_range(oc)) {
                if(ops[o].primitive_restart_index == opri) {
                    ops[o].primitive_restart_index = npri;
                }
                ops[o].idx_type = it;
            }

            for(auto i : integer_range(1, _copies)) {
                const auto k = i * oc;
                const auto a = i * ic;
                for(auto o : integer_range(oc)) {
                    const auto l = k + o;
                    ops[l] = ops[o];
                    ops[l].first = ops[o].first + a;
                }
            }
        } else {

            for(auto i : integer_range(1, _copies)) {
                const auto k = i * oc;
                const auto a = i * vc;
                for(auto o : integer_range(oc)) {
                    const auto l = k + o;
                    ops[l] = ops[o];
                    ops[l].first = ops[o].first + a;
                }
            }
        }
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto array_gen::bounding_sphere() -> math::sphere<float, true> {
    using std::pow;
    using std::sqrt;

    const auto v = math::tvec<float, 3, true>{_d[0], _d[1], _d[2]};
    const auto c = float(_copies);
    const auto l = length(v);
    const auto bs = delegated_gen::bounding_sphere();

    return {bs.center() + c * 0.5F * v, bs.radius() + c * 0.5F * l};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine
