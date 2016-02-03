/**
 *  @file oalplus/buffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_BUFFER_1509260923_HPP
#define OALPLUS_BUFFER_1509260923_HPP

#include "buffer_name.hpp"
#include "enum/types.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "utils/buffer_data.hpp"
#include "utils/span.hpp"

namespace oalplus {

namespace oper {

struct buffer_ops
{
	static
	outcome<void>
	buffer_data(
		buffer_name buf,
		data_format format,
		const buffer_data_spec& data,
		ALsizei frequency
	) noexcept;

	static
	outcome<void>
	get_buffer_iv(
		buffer_name buf,
		buffer_parameter param,
		span<ALint> values
	) noexcept;

	static
	outcome<void>
	get_buffer_fv(
		buffer_name buf,
		buffer_parameter param,
		span<ALfloat> values
	) noexcept;

	static
	outcome<ALint>
	buffer_size(buffer_name buf)
	noexcept;

	static
	outcome<ALint>
	buffer_bits(buffer_name buf)
	noexcept;

	static
	outcome<ALint>
	buffer_channels(buffer_name buf)
	noexcept;

	static
	outcome<ALfloat>
	buffer_frequency(buffer_name buf)
	noexcept;

};

} // namespace oper

template <>
struct obj_gen_del_ops<tag::buffer>
{
	static
	deferred_error_handler
	_gen(span<ALuint> names)
	noexcept;

	static
	deferred_error_handler
	_delete(span<ALuint> names)
	noexcept;

	static
	outcome<bool> _is_a(ALuint name)
	noexcept;
};

using buffer = object_owner<tag::buffer>;

} // namespace oalplus

#include <oalplus/buffer.inl>

#endif // include guard
