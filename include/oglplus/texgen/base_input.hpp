/**
 *  @file oglplus/texgen/base_input.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_BASE_INPUT_HPP
#define OGLPLUS_TEXGEN_BASE_INPUT_HPP

#include "interface.hpp"

namespace oglplus {
namespace texgen {

class base_input : public input_intf {
private:
    node_intf& _parent;
    string_view _name;
    output_intf* _output;

public:
    base_input(base_input&&) = default;

    base_input(node_intf& par_node, string_view name_str) noexcept
      : _parent(par_node)
      , _name(name_str)
      , _output(nullptr) {
    }

    ~base_input() noexcept override;

    node_intf& parent() noexcept {
        return _parent;
    }

    void set_name(string_view name) noexcept {
        _name = name;
    }

    string_view name() noexcept override;

    bool is_connected() noexcept override;

    bool is_connected(output_intf&) override;

    bool can_connect(output_intf&) override;

    bool do_connect(output_intf&);

    bool connect(output_intf&) override;

    void disconnect() override;

    bool disconnect(output_intf&) override;

    output_intf& connected_output() override;

    bool set_default_value(
      eagine::valid_if_between<span_size_t, 0, 3> cmp, float val) override;

    void update_needed() override;

    void prepare_connected() override;

    bool render_connected(const render_params&) override;
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/base_input.inl>
#endif

#endif // OGLPLUS_TEXGEN_BASE_INPUT_HPP
