/**
 *  @file oalplus/error/handling_alc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ERROR_HANDLING_ALC_1509260923_HPP
#define OALPLUS_ERROR_HANDLING_ALC_1509260923_HPP

#include "error_alc.hpp"
#include "../utils/deferred_handler.hpp"

namespace oalplus {

template <typename ErrorInfo>
[[noreturn]] static inline
void handle_alc_error(ErrorInfo& info)
{
	throw error_alc(std::move(info));
}

static inline constexpr
bool is_alc_error(ALenum ec)
noexcept
{
	return ec != AL_NO_ERROR;
}

struct alc_error_handling_policy
{
	static
	bool is_valid(const error_info_alc& info)
	noexcept
	{
		return is_alc_error(info.al_error_code());
	}

	[[noreturn]] static
	void invoke(error_info_alc& info)
	{
		handle_alc_error(info);
	}

	static
	void cancel(error_info_alc& info)
	noexcept
	{
		info.al_error_code(AL_NO_ERROR);
	}
};

using deferred_error_handler_alc = deferred_handler<
	error_info_alc,
	alc_error_handling_policy
>;

} // namespace oalplus

#ifndef OALPLUS_ALC_GET_ERROR
#define OALPLUS_ALC_GET_ERROR(DEVICE) ::alcGetError(DEVICE)
#endif

#define OALPLUS_RETURN_ALC_HANDLER_IF(\
	CONDITION,\
	DEVICE,\
	ERROR_CODE,\
	ERROR_INFO,\
	SEVERITY\
)\
{\
	ALenum oalplus_error_code##__LINE__ = ERROR_CODE;\
	if(CONDITION(oalplus_error_code##__LINE__))\
	{\
		return oalplus::deferred_error_handler_alc(std::move(\
			oalplus::error_info_alc(\
				DEVICE,\
				oalplus_error_code##__LINE__\
			)\
				.ERROR_INFO\
				.source_file(__FILE__)\
				.source_line(__LINE__)\
		));\
	}\
}

#define OALPLUS_RETURN_HANDLER_IF_ALC_ERROR(\
	DEVICE,\
	ERROR_CODE,\
	ERROR_INFO,\
	SEVERITY\
) OALPLUS_RETURN_ALC_HANDLER_IF(\
	oalplus::is_alc_error,\
	DEVICE,\
	ERROR_CODE,\
	ERROR_INFO,\
	SEVERITY\
)

#define OALPLUS_VERIFY_ALC(\
	ALFUNC,\
	DEVICE,\
	ERROR_INFO,\
	SEVERITY\
) OALPLUS_RETURN_HANDLER_IF_ALC_ERROR(\
	DEVICE,\
	OALPLUS_ALC_GET_ERROR(DEVICE),\
	ERROR_INFO.al_library_name("ALC").\
	ERROR_INFO.al_function_name(#ALFUNC),\
	SEVERITY\
)

#define OALPLUS_VERIFY_SIMPLE_ALC(ALCFUNC, DEVICE, SEVERITY)\
	OALPLUS_VERIFY_ALC(ALCFUNC, DEVICE, no_info(), SEVERITY)

#endif // include guard
