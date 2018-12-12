/**
 *  @file oglplus/texgen/uniform_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_UNIFORM_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_UNIFORM_NODE_1509260923_HPP

#include "../uniform.hpp"
#include "base_node.hpp"
#include "base_output.hpp"

namespace oglplus {
namespace texgen {

class uniform_output : public base_output {
private:
    friend class uniform_node;

    slot_data_type _value_type;
    uniform_location _location;

public:
    uniform_output(node_intf& parent, slot_data_type type);

    void bind_location();

    uniform_location get_location() const {
        return _location;
    }

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream&
    definitions(std::ostream& out, compile_context& ctxt) override;
};

class uniform_node : public single_output_node<uniform_output> {
public:
    uniform_node(slot_data_type);
    uniform_node();

    uniform_node& set_value_type(slot_data_type type) {
        _output._value_type = type;
        return *this;
    }

    template <typename T>
    uniform_node& set_value_type() {
        set_value_type(get_data_type_v<T>);
        return *this;
    }

    uniform_location get_uniform_location() const {
        return _output.get_location();
    }

    void prepare() override;
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/uniform_node.inl>
#endif

#endif // include guard
