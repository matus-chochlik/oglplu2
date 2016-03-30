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

#include "../config/basic.hpp"
#include "../utils/cstr_ref.hpp"
#include <memory>
#include <cstddef>
#include <iosfwd>

namespace oglplus {
namespace texgen {

enum class slot_data_type
{
	float_, float_2, float_3, float_4,
	int_, int_2, int_3, int_4,
	bool_, bool_2, bool_3, bool_4 
};

struct input_intf;
struct output_intf;
struct node_intf;

class compile_context_impl;

class compile_context
{
private:
	std::unique_ptr<compile_context_impl> _pimpl;

	const compile_context_impl& _impl(void) const
	noexcept;

	compile_context_impl& _impl(void)
	noexcept;
public:
	compile_context(void);

	unsigned glsl_version(void) const;

	void add_tag(const cstr_ref& tag);
	bool has_tag(const cstr_ref& tag) const
	noexcept;
};

struct input_intf
{
	virtual
	~input_intf(void)
	noexcept { }

	virtual
	cstr_ref name(void) const
	noexcept = 0;

	virtual
	bool accepts_value_type(slot_data_type) const
	noexcept = 0;

	virtual
	bool is_connected(output_intf&)
	noexcept = 0;

	virtual
	bool connect(output_intf&) = 0;

	virtual
	bool disconnect(output_intf&) = 0;

	virtual
	void update_needed(void) = 0;
};

struct output_intf
{
	virtual
	~output_intf(void)
	noexcept { }

	virtual
	cstr_ref name(void) const
	noexcept = 0;

	virtual
	slot_data_type value_type(void) const
	noexcept = 0;

	virtual
	std::ostream& definitions(std::ostream&, compile_context&) = 0;

	virtual
	std::ostream& expression(std::ostream&, compile_context&) = 0;

	virtual
	bool is_connected(input_intf&)
	noexcept = 0;

	virtual
	bool connect(input_intf&) = 0;

	virtual
	bool disconnect(input_intf&) = 0;

	virtual
	void notify_connected(void) = 0;
};

struct node_intf
{
	virtual
	~node_intf(void)
	noexcept { }

	virtual
	std::size_t input_count(void) const
	noexcept = 0;

	virtual
	input_intf& input(std::size_t)
	noexcept = 0;

	virtual
	std::size_t output_count(void) const
	noexcept = 0;

	virtual
	output_intf& output(std::size_t)
	noexcept = 0;

	virtual
	cstr_ref type_name(void) const
	noexcept = 0;

	virtual
	void update_needed(void) = 0;
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

	cstr_ref name(void) const
	noexcept
	{
		return _impl().name();
	}

	bool accepts_value_type(slot_data_type type) const
	noexcept
	{
		return _impl().accepts_value_type(type);
	}

	bool is_connected(output_slot& output)
	noexcept;

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

	const output_intf& _impl(void) const
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

	cstr_ref name(void) const
	noexcept
	{
		return _impl().name();
	}

	slot_data_type value_type(void) const
	noexcept
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

	bool is_connected(input_slot&)
	noexcept;

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
