/**
 *  @file oalplus/buffer.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oalplus/utils/al_func.hpp>
#include <cassert>

namespace oalplus {
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
buffer_data(
	buffer_name buf,
	data_format format,
	const buffer_data_spec& data,
	ALsizei frequency
) noexcept
{
	OALPLUS_ALFUNC(BufferData)(
		get_raw_name(buf),
		ALenum(format),
		data.data(),
		ALsizei(data.size()),
		frequency
	);
	OALPLUS_VERIFY(
		BufferData,
		al_enum_value(format).
		al_object(buf),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
get_buffer_iv(
	buffer_name buf,
	buffer_parameter param,
	span<ALint> values
) noexcept
{
	assert(values.size() > 0);
	OALPLUS_ALFUNC(GetBufferiv)(
		get_raw_name(buf),
		ALenum(param),
		values.data()
	);
	OALPLUS_VERIFY(
		GetBufferiv,
		al_enum_value(param).
		al_object(buf),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
get_buffer_fv(
	buffer_name buf,
	buffer_parameter param,
	span<ALfloat> values
) noexcept
{
	assert(values.size() > 0);
	OALPLUS_ALFUNC(GetBufferfv)(
		get_raw_name(buf),
		ALenum(param),
		values.data()
	);
	OALPLUS_VERIFY(
		GetBufferfv,
		al_enum_value(param).
		al_object(buf),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<ALint>
buffer_ops::
buffer_size(buffer_name buf)
noexcept
{
	ALint result = 0;
	return get_buffer_iv(
		buf,
		buffer_parameter(AL_SIZE),
		{&result, 1}
	), result;
}
//------------------------------------------------------------------------------
inline
outcome<ALint>
buffer_ops::
buffer_bits(buffer_name buf)
noexcept
{
	ALint result = 0;
	return get_buffer_iv(
		buf,
		buffer_parameter(AL_BITS),
		{&result, 1}
	), result;
}
//------------------------------------------------------------------------------
inline
outcome<ALint>
buffer_ops::
buffer_channels(buffer_name buf)
noexcept
{
	ALint result = 0;
	return get_buffer_iv(
		buf,
		buffer_parameter(AL_CHANNELS),
		{&result, 1}
	), result;
}
//------------------------------------------------------------------------------
inline
outcome<ALfloat>
buffer_ops::
buffer_frequency(buffer_name buf)
noexcept
{
	ALfloat result = 0.f;
	return get_buffer_fv(
		buf,
		buffer_parameter(AL_FREQUENCY),
		{&result, 1}
	), result;
}
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::buffer>::
_gen(span<ALuint> names)
noexcept
{
	OALPLUS_ALFUNC(GenBuffers)(
		ALsizei(names.size()),
		names.data()
	);
	OALPLUS_VERIFY_SIMPLE(GenBuffers,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::buffer>::
_delete(span<ALuint> names)
noexcept
{
	OALPLUS_ALFUNC(DeleteBuffers)(
		ALsizei(names.size()),
		names.data()
	);
	OALPLUS_VERIFY_SIMPLE(DeleteBuffers,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<bool>
obj_gen_del_ops<tag::buffer>::
_is_a(ALuint name)
noexcept
{
	ALboolean res = OALPLUS_ALFUNC(IsBuffer)(name);
	OALPLUS_VERIFY_SIMPLE(IsBuffer,debug);
	return res == AL_TRUE;
}
//------------------------------------------------------------------------------
} // namespace oalplus
