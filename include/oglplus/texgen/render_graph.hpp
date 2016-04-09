/**
 *  @file oglplus/texgen/render_graph.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_RENDER_GRAPH_1509260923_HPP
#define OGLPLUS_TEXGEN_RENDER_GRAPH_1509260923_HPP

#include "render_node.hpp"
#include <memory>
#include <string>
#include <map>

namespace oglplus {
namespace texgen {

class render_graph
{
private:
	typedef std::unique_ptr<node_intf> _node_ptr_t;
	std::map<std::string, _node_ptr_t> _nodes;
	std::unique_ptr<render_node> _render_node;
public:
	render_graph(void);
	~render_graph(void);

	void disconnect_all(void);

	void add_node(std::string name, std::unique_ptr<node_intf>&&);

	template <typename NodeType, typename ... P>
	NodeType& add_new_node(std::string name, P&& ... p)
	{
		NodeType* ptr = new NodeType(std::forward<P>(p)...);
		assert(ptr);
		add_node(std::move(name), _node_ptr_t(ptr));
		return *ptr;
	}

	render_node& renderer(void);

	void set_dimensions(valid_if_positive<int> w, valid_if_positive<int> h);

	void render(void);

	eagine::optional_reference_wrapper<node_intf>
	find_node(const std::string& node_name);

	eagine::optional_reference_wrapper<input_intf>
	find_node_input(const std::string& node_name, std::size_t index);

	eagine::optional_reference_wrapper<output_intf>
	find_node_output(const std::string& node_name, std::size_t index);

	eagine::optional_reference_wrapper<input_intf>
	find_node_input(const std::string& node_name, const cstr_ref& iname);

	eagine::optional_reference_wrapper<output_intf>
	find_node_output(const std::string& node_name, const cstr_ref& oname);

	bool connect_to_renderer(
		const std::string& node_name,
		std::size_t index
	);

	bool connect_to_renderer(const std::string& node_name)
	{
		return connect_to_renderer(node_name, 0);
	}

	bool connect(
		const std::string& output_node_name,
		std::size_t oindex,
		const std::string& input_node_name,
		std::size_t iindex
	);

	bool connect(
		const std::string& output_node_name,
		const std::string& input_node_name,
		std::size_t iindex
	);

	bool connect(
		const std::string& output_node_name,
		const cstr_ref& oname,
		const std::string& input_node_name,
		const cstr_ref& iname
	);

	bool connect(
		const std::string& output_node_name,
		const std::string& input_node_name,
		const cstr_ref& iname
	);

	bool connect(
		const std::string& output_node_name,
		const std::string& input_node_name
	);

	bool finalize(void);
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/render_graph.inl>
#endif

#endif // include guard
