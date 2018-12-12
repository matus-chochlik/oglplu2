/**
 *  @file oglplus/texgen/honeycomb_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_HONEYCOMB_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_HONEYCOMB_NODE_1509260923_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace oglplus {
namespace texgen {

enum class honeycomb_direction { vertical, horizontal };

enum class honeycomb_output_type { cell_coord, cell_center, distance };

class honeycomb_output : public base_output {
private:
    input_with_const_default<float[2]>& _cells;
    honeycomb_direction& _direction;
    honeycomb_output_type _type;

    string_view type_abbr() const;

public:
    honeycomb_output(
      node_intf& parent,
      input_with_const_default<float[2]>&,
      honeycomb_direction& direction,
      honeycomb_output_type type);

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream&
    definitions(std::ostream& out, compile_context& ctxt) override;

    std::ostream& expression(std::ostream& out, compile_context& ctxt) override;
};

class honeycomb_node : public base_node {
private:
    input_with_const_default<float[2]> _cells;
    honeycomb_direction _direction;

    honeycomb_output _cell_coord;
    honeycomb_output _cell_center;
    honeycomb_output _distance;

public:
    honeycomb_node();

    honeycomb_node& set_cell_count(float x, float y) {
        _cells.fallback().set(x, y);
        return *this;
    }

    string_view type_name() override;

    span_size_t input_count() override;

    input_intf& input(span_size_t index) override;

    span_size_t output_count() override;

    output_intf& output(span_size_t index) override;
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/honeycomb_node.inl>
#endif

#endif // include guard
