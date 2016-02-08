/**
 *  @file oalplus/error/info_alc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ERROR_INFO_ALC_1509260923_HPP
#define OALPLUS_ERROR_INFO_ALC_1509260923_HPP

#include "info_base.hpp"
#include "../utils/enum_class.hpp"

namespace oalplus {

class error_info_alc
 : public error_info_base<error_info_alc>
{
private:
#if !OALPLUS_ERROR_NO_DEVICE
	::ALCdevice* _device;
#endif

#if !OALPLUS_ERROR_NO_CONTEXT
	::ALCcontext* _context;
#endif
public:
	constexpr
	error_info_alc(ALCdevice* device, ALenum alc_err_code)
	noexcept;

	constexpr
	error_info_alc(void)
	noexcept
	 : error_info_alc(nullptr, ALenum(AL_NONE))
	{ }

	constexpr
	error_info_alc& no_info(void)
	noexcept
	{
		return *this;
	}

	error_info_alc& alc_device(::ALCdevice* dev)
	noexcept;

	::ALCdevice* alc_device(void) const
	noexcept;

	error_info_alc& alc_context(const ::ALCcontext* ctx)
	noexcept;

	const ::ALCcontext* alc_context(void) const
	noexcept;
};

} // namespace oalplus

#include <oalplus/error/info_alc.inl>

#endif // include guard
