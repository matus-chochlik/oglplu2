/**
 *  @file oglplus/texgen/coord_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_COORD_NODE_HPP
#define OGLPLUS_TEXGEN_COORD_NODE_HPP

#include "base_node.hpp"

namespace eagine::oglp::texgen {

enum class coord_type { normalized, frag_coord };

class coord_output : public base_output {
private:
    friend class coord_node;

    coord_type _type;

    string_view _func_name() const;

public:
    coord_output(node_intf& parent, coord_type);

    coord_output(node_intf& parent)
      : coord_output(parent, coord_type::normalized) {}

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(std::ostream& out, compile_context& ctxt) override;
};

class coord_node : public single_output_node<coord_output> {
public:
    coord_node& set_type(coord_type type) {
        _output._type = type;
        return *this;
    }
};

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/coord_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_COORD_NODE_HPP
