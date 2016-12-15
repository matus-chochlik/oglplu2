/**
 *  @file oglplus/texgen/interface.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_INTERFACE_1509260923_HPP
#define OGLPLUS_TEXGEN_INTERFACE_1509260923_HPP

#include "../utils/types.hpp"
#include "data_type.hpp"
#include "render_params.hpp"
#include <eagine/valid_if/between.hpp>
#include <eagine/optional_ref.hpp>
#include <cstddef>
#include <iosfwd>

namespace oglplus {
namespace texgen {

struct constant_intf;
struct input_intf;
struct output_intf;
struct node_intf;

class compile_context_impl;

class compile_context
{
private:
	compile_context_impl* _pimpl;

	const compile_context_impl& _impl(void) const
	noexcept;

	compile_context_impl& _impl(void)
	noexcept;
public:
	compile_context(void);
	compile_context(const compile_context&) = delete;
	~compile_context(void);

	unsigned glsl_version(void) const;

	void add_tag(const cstr_ref& tag);
	bool has_tag(const cstr_ref& tag) const
	noexcept;

	void remember_constant(const constant_intf&);
	bool remembers_constant(const constant_intf&) const
	noexcept;

	void remember_output(const output_intf&);
	bool remembers_output(const output_intf&) const
	noexcept;
};

struct constant_intf
{
	virtual
	~constant_intf(void) = default;

	virtual
	cstr_ref name(void) const
	noexcept = 0;

	virtual
	slot_data_type value_type(void) = 0;

	virtual
	std::ostream& definitions(std::ostream&, compile_context&) = 0;

	virtual
	std::ostream& expression(std::ostream&, compile_context&) = 0;
};

struct input_intf
{
	input_intf(void) = default;
	input_intf(input_intf&&) = default;
	input_intf(const input_intf&) = default;

	virtual
	~input_intf(void)
	noexcept { }

	virtual
	cstr_ref name(void)
	noexcept = 0;

	virtual
	bool accepts_value_type(slot_data_type) = 0;

	virtual
	std::ostream& definitions(std::ostream&, compile_context&) = 0;

	virtual
	std::ostream& expression(std::ostream&, compile_context&) = 0;

	virtual
	bool is_connected(void) = 0;

	virtual
	bool is_connected(output_intf&) = 0;

	virtual
	bool can_connect(output_intf&) = 0;

	virtual
	bool connect(output_intf&) = 0;

	virtual
	void disconnect(void) = 0;

	virtual
	bool disconnect(output_intf&) = 0;

	virtual
	output_intf& connected_output(void) = 0;

	virtual
	bool set_default_value(
		eagine::valid_if_between<unsigned, 0, 3> c,
		float v
	) = 0;

	bool set_default(float x)
	{
		return	set_default_value(0, x);
	}

	bool set_default(float x, float y)
	{
		return	set_default_value(0, x)&&
			set_default_value(1, y);
	}

	bool set_default(float x, float y, float z)
	{
		return	set_default_value(0, x)&&
			set_default_value(1, y)&&
			set_default_value(2, z);
	}

	bool set_default(float x, float y, float z, float w)
	{
		return	set_default_value(0, x)&&
			set_default_value(1, y)&&
			set_default_value(3, z)&&
			set_default_value(4, w);
	}

	virtual
	void update_needed(void) = 0;

	virtual
	void prepare_connected(void) = 0;

	virtual
	bool render_connected(const render_params&) = 0;
};

struct output_intf
{
	output_intf(void) = default;
	output_intf(output_intf&&) = default;
	output_intf(const output_intf&) = default;

	virtual
	~output_intf(void)
	noexcept { }

	virtual
	cstr_ref name(void)
	noexcept = 0;

	virtual
	slot_data_type value_type(void) = 0;

	virtual
	render_param_bits required_params(void) = 0;

	virtual
	bool needs_params(void)
	{
		return bool(required_params());
	}

	virtual
	std::ostream& definitions(std::ostream&, compile_context&) = 0;

	virtual
	std::ostream& expression(std::ostream&, compile_context&) = 0;

	virtual
	bool is_connected(input_intf&) = 0;

	virtual
	bool connect(input_intf&) = 0;

	virtual
	bool disconnect(input_intf&) = 0;

	virtual
	void disconnect_all(void) = 0;

	virtual
	void notify_connected(void) = 0;

	virtual
	void prepare_parent(void) = 0;

	virtual
	bool render_parent(const render_params&) = 0;
};

bool connect_output_to_input(output_intf& output, input_intf& input);
bool disconnect_output_from_input(output_intf& output, input_intf& input);

struct node_intf
{
	virtual
	~node_intf(void)
	noexcept { }

	virtual
	span_size_t input_count(void) = 0;

	virtual
	input_intf& input(span_size_t) = 0;

	virtual
	eagine::optional_reference_wrapper<input_intf>
	input_by_name(const cstr_ref&);

	virtual
	bool can_add_input(void) = 0;

	virtual
	input_intf& add_input(const cstr_ref&) = 0;

	std::ostream& input_definitions(std::ostream&, compile_context&);

	virtual
	span_size_t output_count(void) = 0;

	virtual
	output_intf& output(span_size_t) = 0;

	virtual
	eagine::optional_reference_wrapper<output_intf>
	output_by_name(const cstr_ref&);

	void disconnect_all(void);

	virtual
	cstr_ref type_name(void) = 0;

	virtual
	void update_needed(void) = 0;

	virtual
	void prepare(void) = 0;

	virtual
	bool render(const render_params&) = 0;
};

class input_slot;
class output_slot;

class input_slot
{
private:
	friend class output_slot;
	input_intf* _pimpl;

	input_intf& _impl(void)
	noexcept
	{
		assert(is_valid());
		return *_pimpl;
	}

	const input_intf& _impl(void) const
	noexcept
	{
		assert(is_valid());
		return *_pimpl;
	}
public:
	input_slot(void) = default;

	input_slot(input_intf& impl)
	 : _pimpl(&impl)
	{ }

	bool is_valid(void) const
	noexcept
	{
		return _pimpl != nullptr;
	}

	explicit inline
	operator bool(void) const
	noexcept
	{
		return is_valid();
	}

	bool operator !(void) const
	noexcept
	{
		return !is_valid();
	}

	friend
	bool operator == (const input_slot& a, const input_slot& b)
	noexcept
	{
		return a.is_valid() && b.is_valid() && (a._pimpl == b._pimpl);
	}

	friend
	bool operator != (const input_slot& a, const input_slot& b)
	noexcept
	{
		return a.is_valid() && b.is_valid() && (a._pimpl != b._pimpl);
	}

	friend
	bool operator < (const input_slot& a, const input_slot& b)
	noexcept
	{
		return a.is_valid() && b.is_valid() && (a._pimpl <  b._pimpl);
	}

	cstr_ref name(void)
	noexcept
	{
		return _impl().name();
	}

	bool accepts_value_type(slot_data_type type)
	{
		return _impl().accepts_value_type(type);
	}

	bool is_connected(output_slot& output);

	bool connect(output_slot& output);
	bool disconnect(output_slot& output);
};

class output_slot
{
private:
	friend class input_slot;
	output_intf* _pimpl;

	output_intf& _impl(void)
	noexcept
	{
		assert(is_valid());
		return *_pimpl;
	}
public:
	output_slot(void) = default;

	output_slot(output_intf& impl)
	 : _pimpl(&impl)
	{ }

	bool is_valid(void) const
	noexcept
	{
		return _pimpl != nullptr;
	}

	explicit inline
	operator bool(void) const
	noexcept
	{
		return is_valid();
	}

	bool operator !(void) const
	noexcept
	{
		return !is_valid();
	}

	friend
	bool operator == (const output_slot& a, const output_slot& b)
	noexcept
	{
		return a.is_valid() && b.is_valid() && (a._pimpl == b._pimpl);
	}

	friend
	bool operator != (const output_slot& a, const output_slot& b)
	noexcept
	{
		return a.is_valid() && b.is_valid() && (a._pimpl != b._pimpl);
	}

	friend
	bool operator < (const output_slot& a, const output_slot& b)
	noexcept
	{
		return a.is_valid() && b.is_valid() && (a._pimpl <  b._pimpl);
	}

	cstr_ref name(void)
	noexcept
	{
		return _impl().name();
	}

	slot_data_type value_type(void)
	{
		return _impl().value_type();
	}

	std::ostream& definitions(std::ostream& out, compile_context& ctxt)
	{
		return _impl().definitions(out, ctxt);
	}

	std::ostream& expression(std::ostream& out, compile_context& ctxt)
	{
		return _impl().expression(out, ctxt);
	}

	bool is_connected(input_slot&);

	bool connect(input_slot&);
	bool disconnect(input_slot&);

	void notify_connected(void)
	{
		_impl().notify_connected();
	}
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/interface.inl>
#endif

#endif // include guard
