/**
 *  @file oglplus/texgen/newton_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_NEWTON_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_NEWTON_NODE_1509260923_HPP

#include "base_node.hpp"

namespace oglplus {
namespace texgen {

enum class newton_function { xe3minus1, xe4minus1 };

class newton_output : public base_output {
private:
    friend class newton_node;

    newton_function _function;

    string_view _func_name() const;

public:
    newton_output(node_intf& parent, newton_function);

    newton_output(node_intf& parent)
      : newton_output(parent, newton_function::xe3minus1) {
    }

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream&
    definitions(std::ostream& out, compile_context& ctxt) override;
};

class newton_node : public single_output_node<newton_output> {
public:
    newton_node& set_function(newton_function function) {
        _output._function = function;
        return *this;
    }
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/newton_node.inl>
#endif

#endif // include guard
