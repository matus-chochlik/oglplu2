/**
 *  @file oglplus/buffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_BUFFER_1509260923_HPP
#define OGLPLUS_BUFFER_1509260923_HPP

#include "buffer_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/gl_func.hpp"
#include "utils/buffer_size.hpp"
#include "utils/buffer_data.hpp"
#include "utils/boolean.hpp"

namespace oglplus {

binding_query
get_binding_query(buffer_target tgt)
noexcept;

namespace oper {

struct buffer_ops
{
	static
	outcome<void>
	bind_buffer(buffer_target target, buffer_name buf)
	noexcept;

	static
	outcome<buffer_name>
	buffer_binding(buffer_target target)
	noexcept;

	static
	outcome<void>
	bind_buffer_base(
		buffer_indexed_target target,
		GLuint index,
		buffer_name buf
	) noexcept;

	static
	outcome<void>
	get_buffer_parameter_iv(
		buffer_target tgt,
		oglplus::buffer_parameter param,
		array_view<GLint> values
	) noexcept;

	static
	outcome<void>
	get_buffer_parameter_i64v(
		buffer_target tgt,
		oglplus::buffer_parameter param,
		array_view<GLint64> values
	) noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	get_buffer_parameter_iv(
		buffer_name buf,
		oglplus::buffer_parameter param,
		array_view<GLint> values
	) noexcept;
#endif

#if defined(GL_VERSION_4_5)
	static
	outcome<void>
	get_buffer_parameter_i64v(
		buffer_name buf,
		oglplus::buffer_parameter param,
		array_view<GLint64> values
	) noexcept;
#endif

	template <typename R, typename T, typename BNT>
	static
	outcome<R>
	return_buffer_parameter_i(BNT bnt, buffer_parameter parameter)
	noexcept;

	template <typename BNT>
	static
	outcome<GLint>
	buffer_size(BNT bnt)
	noexcept;

	template <typename BNT>
	static
	outcome<boolean>
	buffer_mapped(BNT bnt)
	noexcept;

	template <typename BNT>
	static
	outcome<boolean>
	buffer_immutable_storage(BNT bnt)
	noexcept;

	template <typename BNT>
	static
	outcome<oglplus::buffer_usage>
	buffer_usage(BNT bnt)
	noexcept;

	template <typename BNT>
	static
	outcome<enum_bitfield<buffer_storage_bits>>
	buffer_storage_flags(BNT bnt)
	noexcept;

	static
	outcome<void>
	buffer_data(
		buffer_target target,
		const buffer_data_spec& data,
		oglplus::buffer_usage usage
	) noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	buffer_data(
		buffer_name buf,
		const buffer_data_spec& data,
		oglplus::buffer_usage usage
	) noexcept;
#endif

	static
	outcome<void>
	buffer_sub_data(
		buffer_target target,
		oglplus::buffer_size offset,
		const buffer_data_spec& data
	) noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	buffer_sub_data(
		buffer_name buf,
		oglplus::buffer_size offset,
		const buffer_data_spec& data
	) noexcept;
#endif

#if defined(GL_VERSION_3_1) || defined(GL_ARB_copy_buffer)
	static
	outcome<void>
	copy_buffer_sub_data(
		buffer_target read_target,
		buffer_target write_target,
		oglplus::buffer_size read_offset,
		oglplus::buffer_size write_offset,
		oglplus::buffer_size size
	) noexcept;

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
	static
	outcome<void>
	copy_buffer_sub_data(
		buffer_name read_buffer,
		buffer_name write_buffer,
		oglplus::buffer_size read_offset,
		oglplus::buffer_size write_offset,
		oglplus::buffer_size size
	) noexcept;
#endif
#endif

#if defined(GL_VERSION_4_3) || defined(GL_ARB_invalidate_subdata)
	static
	outcome<void>
	invalidate_buffer_data(buffer_name buf)
	noexcept;

	static
	outcome<void>
	invalidate_buffer_sub_data(
		buffer_name buf,
		oglplus::buffer_size offset,
		oglplus::buffer_size size
	) noexcept;
#endif
};

} // namespace oper

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
template <>
struct obj_dsa_ops<buffer_name>
 : obj_zero_dsa_ops<buffer_name>
{
	typedef oper::buffer_ops _ops;

	outcome<obj_dsa_ops&>
	data(const buffer_data_spec& data, buffer_usage usage)
	noexcept
	{
		return {_ops::buffer_data(*this, data, usage), *this};
	}

	outcome<obj_dsa_ops&>
	sub_data(buffer_size offset, const buffer_data_spec& data)
	noexcept
	{
		return {_ops::buffer_sub_data(*this, offset, data), *this};
	}

#if defined(GL_VERSION_4_3) || defined(GL_ARB_invalidate_subdata)
	outcome<obj_dsa_ops&>
	invalidate_data(void)
	noexcept
	{
		return {_ops::invalidate_buffer_data(*this), *this};
	}

	outcome<obj_dsa_ops&>
	invalidate_sub_data(buffer_size offset, buffer_size size)
	noexcept
	{
		return {
			_ops::invalidate_buffer_sub_data( *this, offset, size),
			*this
		};
	}
#endif

	outcome<GLint>
	size(void) const
	noexcept
	{
		return _ops::buffer_size(*this);
	}

	outcome<boolean>
	mapped(void) const
	noexcept
	{
		return _ops::buffer_mapped(*this);
	}

	outcome<boolean>
	immutable_storage(void) const
	noexcept
	{
		return _ops::buffer_immutable_storage(*this);
	}

	outcome<buffer_usage>
	usage(void) const
	noexcept
	{
		return _ops::buffer_usage(*this);
	}

	outcome<enum_bitfield<buffer_storage_bits>>
	storage_flags(void) const
	noexcept
	{
		return _ops::buffer_storage_flags(*this);
	}
};
#endif

template <>
struct obj_gen_del_ops<tag::buffer>
{
	static
	deferred_error_handler
	_gen(array_view<GLuint> names)
	noexcept;

	static
	deferred_error_handler
	_delete(array_view<GLuint> names)
	noexcept;

	static
	outcome<boolean> _is_a(GLuint name)
	noexcept;
};

using buffer = object_owner<tag::buffer>;

static const object_zero_and_ops<tag::buffer>
	no_buffer = {};

} // namespace oglplus

#include <oglplus/buffer.inl>

#endif // include guard
