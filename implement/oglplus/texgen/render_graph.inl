/**
 *  @file oglplus/texgen/render_graph.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>
#include <iostream>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
render_graph::render_graph()
  : _render_node(new render_node()) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
render_graph::~render_graph() {
    disconnect_all();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void render_graph::disconnect_all() {
    for(std::unique_ptr<node_intf>& node : _anon_nodes) {
        EAGINE_ASSERT(node);
        node->disconnect_all();
    }
    for(auto& p : _nodes) {
        std::unique_ptr<node_intf>& node = p.second;
        EAGINE_ASSERT(node);
        node->disconnect_all();
    }
    renderer().disconnect_all();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void render_graph::add_anonymous_node(std::unique_ptr<node_intf>&& node) {
    _anon_nodes.push_back(std::move(node));
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void render_graph::add_node(
  std::string name, std::unique_ptr<node_intf>&& node) {
    _nodes[std::move(name)] = std::move(node);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
render_node& render_graph::renderer() {
    EAGINE_ASSERT(_render_node);
    return *_render_node;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void render_graph::set_dimensions(
  const eagine::valid_if_positive<int>& w,
  const eagine::valid_if_positive<int>& h) {
    renderer().set_dimensions(w, h);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void render_graph::render() {
    renderer().render();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<node_intf> render_graph::find_node(
  const std::string& node_name) {
    auto pos = _nodes.find(node_name);
    if(pos != _nodes.end()) {
        std::unique_ptr<node_intf>& node = pos->second;
        EAGINE_ASSERT(node);
        return *node.get();
    }
    return eagine::nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<input_intf> render_graph::find_node_input(
  node_intf& node, span_size_t index) {
    if(index < node.input_count()) {
        return node.input(index);
    }
    return nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<output_intf> render_graph::find_node_output(
  node_intf& node, span_size_t index) {
    if(index < node.output_count()) {
        return node.output(index);
    }
    return nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<input_intf> render_graph::find_node_input(
  node_intf& node, string_view iname) {
    return node.input_by_name(iname);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<output_intf> render_graph::find_node_output(
  node_intf& node, string_view oname) {
    return node.output_by_name(oname);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<input_intf> render_graph::find_node_input(
  const std::string& node_name, span_size_t index) {
    if(auto node = find_node(node_name)) {
        return find_node_input(node.get(), index);
    }
    return nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<output_intf> render_graph::find_node_output(
  const std::string& node_name, span_size_t index) {
    if(auto node = find_node(node_name)) {
        return find_node_output(node.get(), index);
    }
    return nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<input_intf> render_graph::find_node_input(
  const std::string& node_name, string_view iname) {
    if(auto node = find_node(node_name)) {
        return find_node_input(node.get(), iname);
    }
    return nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<output_intf> render_graph::find_node_output(
  const std::string& node_name, string_view oname) {
    if(auto node = find_node(node_name)) {
        return find_node_output(node.get(), oname);
    }
    return nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::connect_to_renderer(output_intf& output) {
    return connect(output, renderer().input(0));
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::connect_to_renderer(node_intf& node, span_size_t index) {
    if(auto out = find_node_output(node, index)) {
        return connect_to_renderer(out.get());
    }
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::connect_to_renderer(
  const std::string& node_name, span_size_t index) {
    if(auto out = find_node_output(node_name, index)) {
        return connect_to_renderer(out.get());
    }
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::connect(output_intf& out, input_intf& inp) {
    return connect_output_to_input(out, inp);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::connect(
  node_intf& output_node,
  span_size_t oindex,
  node_intf& input_node,
  span_size_t iindex) {
    if(auto out = find_node_output(output_node, oindex)) {
        if(auto inp = find_node_input(input_node, iindex)) {
            return connect(out.get(), inp.get());
        }
    }
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::connect(
  node_intf& output_node,
  string_view oname,
  node_intf& input_node,
  string_view iname) {
    if(auto out = find_node_output(output_node, oname)) {
        if(auto inp = find_node_input(input_node, iname)) {
            return connect(out.get(), inp.get());
        }
    }
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::connect(
  node_intf& output_node, node_intf& input_node, string_view iname) {
    if(auto out = find_node_output(output_node, 0)) {
        if(auto inp = find_node_input(input_node, iname)) {
            return connect(out.get(), inp.get());
        }
    }
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::connect(
  const std::string& output_node_name,
  span_size_t oindex,
  const std::string& input_node_name,
  span_size_t iindex) {
    if(auto out = find_node(output_node_name)) {
        if(auto inp = find_node(input_node_name)) {
            return connect(out.get(), oindex, inp.get(), iindex);
        }
    }
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::connect(
  const std::string& output_node_name,
  const std::string& input_node_name,
  span_size_t iindex) {
    return connect(output_node_name, 0, input_node_name, iindex);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::connect(
  const std::string& output_node_name,
  string_view oname,
  const std::string& input_node_name,
  string_view iname) {
    if(auto out = find_node_output(output_node_name, oname)) {
        if(auto inp = find_node_input(input_node_name, iname)) {
            return connect(out.get(), inp.get());
        }
    }
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::connect(
  const std::string& output_node_name,
  const std::string& input_node_name,
  string_view iname) {
    if(auto out = find_node_output(output_node_name, 0)) {
        if(auto inp = find_node_input(input_node_name, iname)) {
            return connect(out.get(), inp.get());
        }
    }
    return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::connect(
  const std::string& output_node_name, const std::string& input_node_name) {
    return connect(output_node_name, 0, input_node_name, 0);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool render_graph::finalize() {
    renderer().update_if_needed();
    return true;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
