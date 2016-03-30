/**
 *  @file oglplus/texgen/base_output.inl
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
OGLPLUS_LIB_FUNC
cstr_ref
base_output::name(void) const
noexcept
{
	return cstr_ref("Output");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
base_output::definitions(std::ostream& out, compile_context&)
{
	return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_output::is_connected(input_intf& input)
noexcept
{
	return _inputs.find(&input) != _inputs.end();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_output::connect(input_intf& input)
{
	if(input.accepts_value_type(value_type()))
	{
		assert(!is_connected(input));
		_inputs.insert(&input);
		return true;
	}
	return false;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
bool
base_output::disconnect(input_intf& input)
{
	assert(is_connected(input));
	_inputs.erase(&input);
	return true;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
base_output::notify_connected(void)
{
	for(auto* input : _inputs)
	{
		assert(input != nullptr);
		input->update_needed();
	}
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::intptr_t
base_output::get_id(void) const
noexcept
{
	return reinterpret_cast<std::intptr_t>(this);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
base_output::append_id(std::ostream& out, const cstr_ref& name) const
{
	out << "oglptg" << name;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
void
base_output::append_id(std::ostream& out) const
{
	append_id(out, type_name());
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------

