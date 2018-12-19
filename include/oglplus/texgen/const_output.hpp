/**
 *  @file oglplus/texgen/const_output.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_CONST_OUTPUT_1509260923_HPP
#define OGLPLUS_TEXGEN_CONST_OUTPUT_1509260923_HPP

#include "base_output.hpp"
#include "param_format.hpp"
#include <array>
#include <type_traits>

namespace oglplus {
namespace texgen {

template <typename T>
class constant_output;

class constant_output_base : public base_output {
public:
    constant_output_base(constant_output_base&&) = default;

    constant_output_base(node_intf& parent) noexcept
      : base_output(parent) {
    }

    string_view type_name() noexcept override {
        return string_view("Const");
    }

    render_param_bits required_params() override {
        return render_param_bits();
    }
};

template <typename T, span_size_t N>
class constant_output<T[N]> : public constant_output_base {
private:
    std::array<T, N> _coords;

public:
    constant_output(constant_output&&) = default;

    constant_output(node_intf& parent) noexcept
      : constant_output_base(parent)
      , _coords{} {
    }

    template <typename... P, typename = std::enable_if_t<sizeof...(P) == N>>
    constant_output(node_intf& parent, P... coords) noexcept
      : constant_output_base(parent)
      , _coords{{T(coords)...}} {
    }

    template <typename... P, typename = std::enable_if_t<sizeof...(P) == N>>
    void set(P... coords) noexcept {
        _coords = std::array<T, N>{{T(coords)...}};
    }

    bool set_default_value(span_size_t c, float v) override {
        if(c < N) {
            _coords[std_size(c)] = T(v);
            return true;
        }
        return false;
    }

    slot_data_type value_type() noexcept override {
        return get_data_type_v<T[N]>;
    }

    std::ostream& expression(std::ostream& out, compile_context&) override {
        out << data_type_name(value_type());
        out << "(";
        out << _coords[0];
        for(span_size_t i = 1; i < N; ++i) {
            out << ", " << _coords[std_size(i)];
        }
        return out << ")";
    }
};

} // namespace texgen
} // namespace oglplus

#endif // include guard
