/**
 *  @file oglplus/texgen/fold_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_FOLD_NODE_HPP
#define OGLPLUS_TEXGEN_FOLD_NODE_HPP

#include "fallback_input.hpp"
#include "multi_input_node.hpp"
#include <map>

namespace eagine::oglp::texgen {

enum class fold_function {
    add,
    multiply,
    max,
    min
    // TODO
};

class fold_output : public multi_input_output {
private:
    friend class fold_node;

    fold_function _func;

public:
    fold_output(node_intf& parent, fold_function);

    fold_output(node_intf& parent)
      : fold_output(parent, fold_function::multiply) {}

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream& definitions(std::ostream& out, compile_context& ctxt) override;
};

class fold_node : public multi_input_node {
private:
    fold_output _output;

public:
    fold_node();

    fold_output& single_output() override {
        return _output;
    }

    fold_node& set_function(fold_function func) {
        _output._func = func;
        return *this;
    }
};

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/fold_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_FOLD_NODE_HPP
