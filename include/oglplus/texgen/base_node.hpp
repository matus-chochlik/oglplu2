/**
 *  @file oglplus/texgen/base_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_BASE_NODE_HPP
#define OGLPLUS_TEXGEN_BASE_NODE_HPP

#include "base_output.hpp"
#include "interface.hpp"
#include <eagine/assert.hpp>
#include <eagine/maybe_unused.hpp>

namespace oglplus {
namespace texgen {

class base_node : public node_intf {
private:
    span_size_t _render_input{0};

public:
    base_node() noexcept = default;

    span_size_t input_count() override;

    input_intf& input(span_size_t) override;

    bool can_add_input() override;

    input_intf& add_input(string_view) override;

    span_size_t output_count() override;

    output_intf& output(span_size_t) override;

    void update_needed() override;

    void prepare() override;

    bool render(const render_params&) override;
};

class base_single_output_node : public base_node {
public:
    virtual base_output& single_output() = 0;

    string_view type_name() override;

    span_size_t output_count() override;

    output_intf& output(span_size_t index) override;
};

template <typename Output>
class single_output_node : public base_single_output_node {
protected:
    Output _output;

public:
    template <typename... P>
    single_output_node(P&&... p)
      : _output(*this, std::forward<P>(p)...) {
    }

    base_output& single_output() override {
        return _output;
    }
};

template <typename Output, typename T1, T1 Output::*Input1>
class unary_single_output_node : public single_output_node<Output> {
public:
    using single_output_node<Output>::single_output_node;

    span_size_t input_count() override {
        return 1;
    }

    input_intf& input(span_size_t index) override {
        EAGINE_MAYBE_UNUSED(index);
        EAGINE_ASSERT(index < input_count());
        return this->_output.*Input1;
    }
};

template <
  typename Output,
  typename T1,
  T1 Output::*Input1,
  typename T2,
  T2 Output::*Input2>
class binary_single_output_node : public single_output_node<Output> {
public:
    using single_output_node<Output>::single_output_node;

    span_size_t input_count() override {
        return 2;
    }

    input_intf& input(span_size_t index) override {
        EAGINE_ASSERT(index < input_count());
        return (index == 0) ? static_cast<input_intf&>(this->_output.*Input1)
                            : static_cast<input_intf&>(this->_output.*Input2);
    }
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/base_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_BASE_NODE_HPP
