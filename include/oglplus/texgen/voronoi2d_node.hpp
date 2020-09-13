/**
 *  @file oglplus/texgen/voronoi2d_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_VORONOI2D_NODE_HPP
#define OGLPLUS_TEXGEN_VORONOI2D_NODE_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace eagine::oglp::texgen {

enum class voronoi_output_type {
    distance1,
    distance2,
    distance3,
    cell_coord,
    cell_center,
    input_cell_center
};

class voronoi2d_output : public base_output {
private:
    input_with_const_default<float[2]>& _input;
    input_with_const_default<float[2]>& _cells;
    voronoi_output_type _type;

    short order() const;

    string_view type_abbr() const;

public:
    voronoi2d_output(
      node_intf& parent,
      input_with_const_default<float[2]>&,
      input_with_const_default<float[2]>&,
      voronoi_output_type type);

    string_view type_name() override;

    string_view name() noexcept override;

    slot_data_type value_type() override;

    std::ostream& definitions(std::ostream& out, compile_context& ctxt) override;

    std::ostream& expression(std::ostream& out, compile_context& ctxt) override;
};

class voronoi2d_node : public base_node {
private:
    input_with_const_default<float[2]> _input;
    input_with_const_default<float[2]> _cells;

    voronoi2d_output _distance1;
    voronoi2d_output _distance2;
    voronoi2d_output _distance3;
    voronoi2d_output _cell_coord;
    voronoi2d_output _cell_center;
    voronoi2d_output _input_cell_center;

public:
    voronoi2d_node();

    voronoi2d_node& set_cell_count(float x, float y) {
        _cells.fallback().set(x, y);
        return *this;
    }

    string_view type_name() override;

    span_size_t input_count() override;

    input_intf& input(span_size_t index) override;

    span_size_t output_count() override;

    output_intf& output(span_size_t index) override;
};

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/voronoi2d_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_VORONOI2D_NODE_HPP
