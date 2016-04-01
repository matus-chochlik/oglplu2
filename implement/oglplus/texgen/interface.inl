/**
 *  @file oglplus/texgen/interface.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <set>
#include <string>
#include <cassert>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
class compile_context_impl
{
private:
	unsigned _glsl_version;

	std::set<std::string> _tags;
public:
	compile_context_impl(void)
	 : _glsl_version(150)
	{ }

	unsigned glsl_version(void) const
	noexcept
	{
		return _glsl_version;
	}

	void add_tag(const std::string& tag)
	{
		_tags.insert(tag);
	}

	bool has_tag(const std::string& tag) const
	noexcept
	{
		return _tags.find(tag) != _tags.end();
	}
};
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
const compile_context_impl&
compile_context::_impl(void) const
noexcept
{
	assert(_pimpl != nullptr);
	return *_pimpl;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
compile_context_impl&
compile_context::_impl(void)
noexcept
{
	assert(_pimpl != nullptr);
	return *_pimpl;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
compile_context::compile_context(void)
 : _pimpl(new compile_context_impl())
{ }
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
unsigned
compile_context::glsl_version(void) const
{
	return _impl().glsl_version();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
compile_context::add_tag(const cstr_ref& tag)
{
	_impl().add_tag(std::string(
		tag.data(),
		std::string::size_type(tag.size())
	));
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
compile_context::has_tag(const cstr_ref& tag) const
noexcept
{
	return _impl().has_tag(std::string(
		tag.data(),
		std::string::size_type(tag.size())
	));
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
input_slot::is_connected(output_slot& output)
{
	return _impl().is_connected(output._impl());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
input_slot::connect(output_slot& output)
{
	return _impl().connect(output._impl());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
input_slot::disconnect(output_slot& output)
{
	return _impl().disconnect(output._impl());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
output_slot::is_connected(input_slot& input)
{
	return _impl().is_connected(input._impl());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
output_slot::connect(input_slot& input)
{
	return _impl().connect(input._impl());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
output_slot::disconnect(input_slot& input)
{
	return _impl().disconnect(input._impl());
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void connect_output_to_input(output_intf& output, input_intf& input)
{
	output.connect(input);
	input.connect(output);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

