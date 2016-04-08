/**
 *  @file oglplus/texgen/render_graph.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <iostream>
#include <cassert>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
render_graph::render_graph(void)
 : _render_node(new render_node())
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
render_graph::~render_graph(void)
{
	disconnect_all();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
render_graph::disconnect_all(void)
{
	for(auto& p : _nodes)
	{
		std::unique_ptr<node_intf>& node = p.second;
		assert(node);
		node->disconnect_all();
	}
	renderer().disconnect_all();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
render_graph::
add_node(std::string name, std::unique_ptr<node_intf>&& node)
{
	_nodes[name] = std::move(node);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
render_node&
render_graph::renderer(void)
{
	assert(_render_node);
	return *_render_node;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
render_graph::
set_dimensions(valid_if_positive<int> w, valid_if_positive<int> h)
{
	renderer().set_dimensions(w, h);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
render_graph::render(void)
{
	renderer().render();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<node_intf>
render_graph::
find_node(const std::string& node_name)
{
	auto pos = _nodes.find(node_name);
	if(pos != _nodes.end())
	{
		std::unique_ptr<node_intf>& node = pos->second;
		assert(node);
		return *node.get();
	}
	return eagine::nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<input_intf>
render_graph::
find_node_input(const std::string& node_name, std::size_t index)
{
	if(auto node = find_node(node_name))
	{
		if(index < node.get().input_count())
		{
			return node.get().input(index);
		}
	}
	return nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<output_intf>
render_graph::
find_node_output(const std::string& node_name, std::size_t index)
{
	if(auto node = find_node(node_name))
	{
		if(index < node.get().output_count())
		{
			return node.get().output(index);
		}
	}
	return nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<input_intf>
render_graph::
find_node_input(const std::string& node_name, const cstr_ref& iname)
{
	if(auto node = find_node(node_name))
	{
		return node.get().input_by_name(iname);
	}
	return nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
eagine::optional_reference_wrapper<output_intf>
render_graph::
find_node_output(const std::string& node_name, const cstr_ref& oname)
{
	if(auto node = find_node(node_name))
	{
		return node.get().output_by_name(oname);
	}
	return nothing;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
render_graph::
connect_to_renderer(const std::string& node_name, std::size_t index)
{
	if(auto out = find_node_output(node_name, index))
	{
		return connect_output_to_input(
			out.get(),
			renderer().input(0)
		);
	}
	return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
render_graph::connect(
	const std::string& output_node_name,
	std::size_t oindex,
	const std::string& input_node_name,
	std::size_t iindex
)
{
	if(auto out = find_node_output(output_node_name, oindex))
	{
		if(auto inp = find_node_input(input_node_name, iindex))
		{
			return connect_output_to_input(
				out.get(),
				inp.get()
			);
		}
	}
	return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
render_graph::connect(
	const std::string& output_node_name,
	const std::string& input_node_name,
	std::size_t iindex
)
{
	return connect(output_node_name, 0, input_node_name, iindex);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
render_graph::connect(
	const std::string& output_node_name,
	const cstr_ref& oname,
	const std::string& input_node_name,
	const cstr_ref& iname
)
{
	if(auto out = find_node_output(output_node_name, oname))
	{
		if(auto inp = find_node_input(input_node_name, iname))
		{
			return connect_output_to_input(
				out.get(),
				inp.get()
			);
		}
	}
	return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
render_graph::connect(
	const std::string& output_node_name,
	const std::string& input_node_name,
	const cstr_ref& iname
)
{
	if(auto out = find_node_output(output_node_name, 0))
	{
		if(auto inp = find_node_input(input_node_name, iname))
		{
			return connect_output_to_input(
				out.get(),
				inp.get()
			);
		}
	}
	return false;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

