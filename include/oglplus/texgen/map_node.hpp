/**
 *  @file oglplus/texgen/map_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_MAP_NODE_HPP
#define OGLPLUS_TEXGEN_MAP_NODE_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace oglplus {
namespace texgen {

class map_output : public base_output {
public:
    input_with_const_default<float[4]> input;
    input_with_const_default<float[3]> coord;

    map_output(node_intf& parent);

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream&
    definitions(std::ostream& out, compile_context& ctxt) override;
};

class map_node
  : public binary_single_output_node<
      map_output,
      decltype(map_output::input),
      &map_output::input,
      decltype(map_output::coord),
      &map_output::coord> {
public:
    map_node& set_coord(float x, float y, float z) {
        _output.coord.fallback().set(x, y, z);
        return *this;
    }
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/map_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_MAP_NODE_HPP
