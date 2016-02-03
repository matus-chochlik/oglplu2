//  File implement/oalplus/enum/value_range.inl
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
get_enum_value_range(const any_enum_class& aec)
noexcept
{
	switch(aec._type_id)
	{
		case 0: /* al_error_code */
		{
			static const ALenum vr[] = {
#ifdef AL_INVALID_ENUM
				AL_INVALID_ENUM,
#endif
#ifdef AL_INVALID_NAME
				AL_INVALID_NAME,
#endif
#ifdef AL_INVALID_OPERATION
				AL_INVALID_OPERATION,
#endif
#ifdef AL_INVALID_VALUE
				AL_INVALID_VALUE,
#endif
#ifdef AL_NO_ERROR
				AL_NO_ERROR,
#endif
#ifdef AL_OUT_OF_MEMORY
				AL_OUT_OF_MEMORY,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 1: /* buffer_parameter */
		{
			static const ALenum vr[] = {
#ifdef AL_BITS
				AL_BITS,
#endif
#ifdef AL_CHANNELS
				AL_CHANNELS,
#endif
#ifdef AL_FREQUENCY
				AL_FREQUENCY,
#endif
#ifdef AL_SIZE
				AL_SIZE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 2: /* data_format */
		{
			static const ALenum vr[] = {
#ifdef AL_FORMAT_MONO16
				AL_FORMAT_MONO16,
#endif
#ifdef AL_FORMAT_MONO8
				AL_FORMAT_MONO8,
#endif
#ifdef AL_FORMAT_STEREO16
				AL_FORMAT_STEREO16,
#endif
#ifdef AL_FORMAT_STEREO8
				AL_FORMAT_STEREO8,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 3: /* distance_model */
		{
			static const ALenum vr[] = {
#ifdef AL_EXPONENT_DISTANCE
				AL_EXPONENT_DISTANCE,
#endif
#ifdef AL_EXPONENT_DISTANCE_CLAMPED
				AL_EXPONENT_DISTANCE_CLAMPED,
#endif
#ifdef AL_INVERSE_DISTANCE
				AL_INVERSE_DISTANCE,
#endif
#ifdef AL_INVERSE_DISTANCE_CLAMPED
				AL_INVERSE_DISTANCE_CLAMPED,
#endif
#ifdef AL_LINEAR_DISTANCE
				AL_LINEAR_DISTANCE,
#endif
#ifdef AL_LINEAR_DISTANCE_CLAMPED
				AL_LINEAR_DISTANCE_CLAMPED,
#endif
#ifdef AL_NONE
				AL_NONE,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 4: /* source_state */
		{
			static const ALenum vr[] = {
#ifdef AL_INITIAL
				AL_INITIAL,
#endif
#ifdef AL_PAUSED
				AL_PAUSED,
#endif
#ifdef AL_PLAYING
				AL_PLAYING,
#endif
#ifdef AL_STOPPED
				AL_STOPPED,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 5: /* source_type */
		{
			static const ALenum vr[] = {
#ifdef AL_STATIC
				AL_STATIC,
#endif
#ifdef AL_STREAMING
				AL_STREAMING,
#endif
#ifdef AL_UNDETERMINED
				AL_UNDETERMINED,
#endif
				0
			};
			return {vr, sizeof(vr)/sizeof(vr[0])-1};
		}
		case 6: /* string_query */
		{
			static const ALenum vr[] = {
#ifdef AL_EXTENSIONS
				AL_EXTENSIONS,
#endif
#ifdef AL_RENDERER
				AL_RENDERER,
#endif
#ifdef AL_VENDOR
				AL_VENDOR,
#endif
#ifdef AL_VERSION
				AL_VERSION,
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
