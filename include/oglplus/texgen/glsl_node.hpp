/**
 *  @file oglplus/texgen/glsl_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_GLSL_NODE_HPP
#define OGLPLUS_TEXGEN_GLSL_NODE_HPP

#include "fallback_input.hpp"
#include "multi_input_node.hpp"
#include <map>

namespace eagine::oglp::texgen {

class glsl_output : public multi_input_output {
private:
    friend class glsl_node;

    std::string _glsl;
    slot_data_type _type;

public:
    glsl_output(node_intf& parent, std::string, slot_data_type);

    glsl_output(node_intf& parent)
      : glsl_output(parent, "vec4(0.0)", slot_data_type::float_4) {}

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(std::ostream& out, compile_context& ctxt) override;
};

class glsl_node : public multi_input_node {
private:
    glsl_output _output;

public:
    glsl_node();

    glsl_output& single_output() override {
        return _output;
    }

    glsl_node& set_glsl(const std::string& glsl) {
        _output._glsl = glsl;
        return *this;
    }

    glsl_node& set_type(slot_data_type type) {
        _output._type = type;
        return *this;
    }
};

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/glsl_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_GLSL_NODE_HPP
