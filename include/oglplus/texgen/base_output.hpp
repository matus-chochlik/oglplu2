/**
 *  @file oglplus/texgen/base_output.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_BASE_OUTPUT_HPP
#define OGLPLUS_TEXGEN_BASE_OUTPUT_HPP

#include "interface.hpp"
#include "param_format.hpp"
#include <set>

namespace eagine {
namespace oglp {
namespace texgen {

class base_output : public output_intf {
private:
    node_intf& _parent;
    std::set<input_intf*> _inputs;

protected:
    std::ostream& input_defs(std::ostream&, compile_context&);
    std::ostream& opening_expr(std::ostream&, compile_context&);
    std::ostream& closing_expr(std::ostream&, compile_context&);

    bool already_defined(compile_context&);

public:
    base_output(node_intf& parent) noexcept
      : _parent(parent) {
    }

    node_intf& parent() noexcept {
        return _parent;
    }

    virtual string_view type_name() = 0;

    string_view name() noexcept override;

    render_param_bits required_params() override;

    std::ostream& definitions(std::ostream&, compile_context&) override;

    std::ostream& expression(std::ostream&, compile_context&) override;

    bool is_connected(input_intf&) override;

    bool connect(input_intf&) override;

    bool disconnect(input_intf&) override;

    void disconnect_all() override;

    virtual bool set_default_value(span_size_t, float) {
        return false;
    }

    void notify_connected() override;

    void prepare_parent() override;

    bool render_parent(const render_params&) override;

    std::intptr_t get_id() const noexcept;

    void append_id(std::ostream&, string_view);
    void append_id(std::ostream&);
};

namespace expr {
struct output_id {
    output_intf& output;
    compile_context& context;
};
std::ostream& operator<<(std::ostream& out, const output_id&);
} // namespace expr
} // namespace texgen
} // namespace oglp
} // namespace eagine

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/base_output.inl>
#endif

#endif // OGLPLUS_TEXGEN_BASE_OUTPUT_HPP
