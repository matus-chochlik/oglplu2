//  File implement/oalplus/enum_value_range_alc.inl
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

namespace oalplus {

OALPLUS_LIB_FUNC
std::pair<const void*, std::size_t>
get_enum_value_range(const any_enum_class_alc& aec)
noexcept
{
	switch(aec._type_id)
	{
		case 0: /* alc_error_code */
		{
			static const ALCenum vr[] = {
#ifdef ALC_INVALID_CONTEXT
				ALC_INVALID_CONTEXT,
#endif
#ifdef ALC_INVALID_DEVICE
				ALC_INVALID_DEVICE,
#endif
#ifdef ALC_INVALID_ENUM
				ALC_INVALID_ENUM,
#endif
#ifdef ALC_INVALID_VALUE
				ALC_INVALID_VALUE,
#endif
#ifdef ALC_NO_ERROR
				ALC_NO_ERROR,
#endif
#ifdef ALC_OUT_OF_MEMORY
				ALC_OUT_OF_MEMORY,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 1: /* context_attrib */
		{
			static const ALCenum vr[] = {
#ifdef ALC_FREQUENCY
				ALC_FREQUENCY,
#endif
#ifdef ALC_MONO_SOURCES
				ALC_MONO_SOURCES,
#endif
#ifdef ALC_REFRESH
				ALC_REFRESH,
#endif
#ifdef ALC_STEREO_SOURCES
				ALC_STEREO_SOURCES,
#endif
#ifdef ALC_SYNC
				ALC_SYNC,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
	default:;
	}

	(void)aec;
	return {nullptr, 0};
}

} // namespace oalplus
