/**
 *  @file oglplus/texgen/render_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_RENDER_NODE_HPP
#define OGLPLUS_TEXGEN_RENDER_NODE_HPP

#include "../buffer.hpp"
#include "../program.hpp"
#include "../uniform.hpp"
#include "../vertex_array.hpp"
#include "base_node.hpp"
#include "fallback_input.hpp"
#include <eagine/valid_if/positive.hpp>

namespace eagine::oglp::texgen {

class render_node : public base_node {
private:
    input_with_const_default<float[4]> _input;

    owned<program_name> _prog;
    owned<buffer_name> _data;
    owned<vertex_array_name> _vao;

    uniform_location _voxel_size;

    void _init_screen();
    void _update_program();

    bool _needs_update{false};

    int _xdiv{1}, _ydiv{1}, _tile{0};

    unsigned _render_version{0};
    render_params _render_params{};

public:
    render_node();
    render_node(render_node&&) noexcept = default;
    render_node(const render_node&) = delete;
    render_node& operator=(render_node&&) = delete;
    render_node& operator=(const render_node&) = delete;
    ~render_node() override;

    std::ostream& make_fragment_shader_source(std::ostream&, compile_context&);

    void draw_screen();

    string_view type_name() override;

    span_size_t input_count() override;

    input_intf& input(span_size_t index) override;

    void update_needed() override;

    void update_if_needed();

    bool render(const render_params&) override;

    bool render();

    void set_divisions(
      const valid_if_positive<int>& xdiv, const valid_if_positive<int>& ydiv);

    void set_dimensions(
      const valid_if_positive<int>& width,
      const valid_if_positive<int>& height);
};

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/render_node.inl>
#endif

#endif // OGLPLUS_TEXGEN_RENDER_NODE_HPP
