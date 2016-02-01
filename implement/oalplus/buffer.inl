/**
 *  @file oalplus/buffer.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oalplus/utils/al_func.hpp>

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
