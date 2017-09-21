//  File implement/oalplus/enum/value_names_alc.inl
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oalplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//

#include <eagine/maybe_unused.hpp>
#ifdef _MSC_VER
#pragma warning ( push )
#pragma warning ( disable : 4065 )
#endif //_MSC_VER

namespace oalplus {

OALPLUS_LIB_FUNC
cstr_ref
get_enum_value_name(const any_enum_value_alc& aev)
noexcept
{
#ifdef ALC_FREQUENCY
	static const char s_FREQUENCY[10] =
		"FREQUENCY";
#endif
#ifdef ALC_INVALID_CONTEXT
	static const char s_INVALID_CONTEXT[16] =
		"INVALID_CONTEXT";
#endif
#ifdef ALC_INVALID_DEVICE
	static const char s_INVALID_DEVICE[15] =
		"INVALID_DEVICE";
#endif
#ifdef ALC_INVALID_ENUM
	static const char s_INVALID_ENUM[13] =
		"INVALID_ENUM";
#endif
#ifdef ALC_INVALID_VALUE
	static const char s_INVALID_VALUE[14] =
		"INVALID_VALUE";
#endif
#ifdef ALC_MONO_SOURCES
	static const char s_MONO_SOURCES[13] =
		"MONO_SOURCES";
#endif
#ifdef ALC_NO_ERROR
	static const char s_NO_ERROR[9] =
		"NO_ERROR";
#endif
#ifdef ALC_OUT_OF_MEMORY
	static const char s_OUT_OF_MEMORY[14] =
		"OUT_OF_MEMORY";
#endif
#ifdef ALC_REFRESH
	static const char s_REFRESH[8] =
		"REFRESH";
#endif
#ifdef ALC_STEREO_SOURCES
	static const char s_STEREO_SOURCES[15] =
		"STEREO_SOURCES";
#endif
#ifdef ALC_SYNC
	static const char s_SYNC[5] =
		"SYNC";
#endif

	switch(aev._type_id)
	{
		case 0: /* alc_error_code */
			switch(ALCenum(aev._value))
			{
#ifdef ALC_INVALID_CONTEXT
				case ALC_INVALID_CONTEXT:
					return {s_INVALID_CONTEXT, 15};
#endif
#ifdef ALC_INVALID_DEVICE
				case ALC_INVALID_DEVICE:
					return {s_INVALID_DEVICE, 14};
#endif
#ifdef ALC_INVALID_ENUM
				case ALC_INVALID_ENUM:
					return {s_INVALID_ENUM, 12};
#endif
#ifdef ALC_INVALID_VALUE
				case ALC_INVALID_VALUE:
					return {s_INVALID_VALUE, 13};
#endif
#ifdef ALC_NO_ERROR
				case ALC_NO_ERROR:
					return {s_NO_ERROR, 8};
#endif
#ifdef ALC_OUT_OF_MEMORY
				case ALC_OUT_OF_MEMORY:
					return {s_OUT_OF_MEMORY, 13};
#endif
				default:;
			}
			break;
		case 1: /* context_attrib */
			switch(ALCenum(aev._value))
			{
#ifdef ALC_FREQUENCY
				case ALC_FREQUENCY:
					return {s_FREQUENCY, 9};
#endif
#ifdef ALC_MONO_SOURCES
				case ALC_MONO_SOURCES:
					return {s_MONO_SOURCES, 12};
#endif
#ifdef ALC_REFRESH
				case ALC_REFRESH:
					return {s_REFRESH, 7};
#endif
#ifdef ALC_STEREO_SOURCES
				case ALC_STEREO_SOURCES:
					return {s_STEREO_SOURCES, 14};
#endif
#ifdef ALC_SYNC
				case ALC_SYNC:
					return {s_SYNC, 4};
#endif
				default:;
			}
			break;
	default:;
	}

	EAGINE_MAYBE_UNUSED(aev);
	return {};
}

} // namespace oalplus
#ifdef _MSC_VER
#pragma warning ( pop )
#endif //_MSC_VER
