//  File implement/oalplus/enum/value_names.inl
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
#pragma warning(push)
#pragma warning(disable : 4065)
#endif //_MSC_VER

namespace oalplus {

OALPLUS_LIB_FUNC
string_view get_enum_value_name( // NOLINT(hicpp-function-size)

  const any_enum_value& aev) noexcept {
#ifdef AL_BITS
    static const char* s_BITS = "BITS";
#endif
#ifdef AL_CHANNELS
    static const char* s_CHANNELS = "CHANNELS";
#endif
#ifdef AL_EXPONENT_DISTANCE
    static const char* s_EXPONENT_DISTANCE = "EXPONENT_DISTANCE";
#endif
#ifdef AL_EXPONENT_DISTANCE_CLAMPED
    static const char* s_EXPONENT_DISTANCE_CLAMPED =
      "EXPONENT_DISTANCE_CLAMPED";
#endif
#ifdef AL_EXTENSIONS
    static const char* s_EXTENSIONS = "EXTENSIONS";
#endif
#ifdef AL_FORMAT_MONO16
    static const char* s_FORMAT_MONO16 = "FORMAT_MONO16";
#endif
#ifdef AL_FORMAT_MONO8
    static const char* s_FORMAT_MONO8 = "FORMAT_MONO8";
#endif
#ifdef AL_FORMAT_STEREO16
    static const char* s_FORMAT_STEREO16 = "FORMAT_STEREO16";
#endif
#ifdef AL_FORMAT_STEREO8
    static const char* s_FORMAT_STEREO8 = "FORMAT_STEREO8";
#endif
#ifdef AL_FREQUENCY
    static const char* s_FREQUENCY = "FREQUENCY";
#endif
#ifdef AL_INITIAL
    static const char* s_INITIAL = "INITIAL";
#endif
#ifdef AL_INVALID_ENUM
    static const char* s_INVALID_ENUM = "INVALID_ENUM";
#endif
#ifdef AL_INVALID_NAME
    static const char* s_INVALID_NAME = "INVALID_NAME";
#endif
#ifdef AL_INVALID_OPERATION
    static const char* s_INVALID_OPERATION = "INVALID_OPERATION";
#endif
#ifdef AL_INVALID_VALUE
    static const char* s_INVALID_VALUE = "INVALID_VALUE";
#endif
#ifdef AL_INVERSE_DISTANCE
    static const char* s_INVERSE_DISTANCE = "INVERSE_DISTANCE";
#endif
#ifdef AL_INVERSE_DISTANCE_CLAMPED
    static const char* s_INVERSE_DISTANCE_CLAMPED = "INVERSE_DISTANCE_CLAMPED";
#endif
#ifdef AL_LINEAR_DISTANCE
    static const char* s_LINEAR_DISTANCE = "LINEAR_DISTANCE";
#endif
#ifdef AL_LINEAR_DISTANCE_CLAMPED
    static const char* s_LINEAR_DISTANCE_CLAMPED = "LINEAR_DISTANCE_CLAMPED";
#endif
#ifdef AL_NONE
    static const char* s_NONE = "NONE";
#endif
#ifdef AL_NO_ERROR
    static const char* s_NO_ERROR = "NO_ERROR";
#endif
#ifdef AL_OUT_OF_MEMORY
    static const char* s_OUT_OF_MEMORY = "OUT_OF_MEMORY";
#endif
#ifdef AL_PAUSED
    static const char* s_PAUSED = "PAUSED";
#endif
#ifdef AL_PLAYING
    static const char* s_PLAYING = "PLAYING";
#endif
#ifdef AL_RENDERER
    static const char* s_RENDERER = "RENDERER";
#endif
#ifdef AL_SIZE
    static const char* s_SIZE = "SIZE";
#endif
#ifdef AL_STATIC
    static const char* s_STATIC = "STATIC";
#endif
#ifdef AL_STOPPED
    static const char* s_STOPPED = "STOPPED";
#endif
#ifdef AL_STREAMING
    static const char* s_STREAMING = "STREAMING";
#endif
#ifdef AL_UNDETERMINED
    static const char* s_UNDETERMINED = "UNDETERMINED";
#endif
#ifdef AL_VENDOR
    static const char* s_VENDOR = "VENDOR";
#endif
#ifdef AL_VERSION
    static const char* s_VERSION = "VERSION";
#endif

    switch(aev._type_id) {
        case 0: /* al_error_code */
            switch(ALenum(aev._value)) {
#ifdef AL_INVALID_ENUM
                case AL_INVALID_ENUM:
                    return {s_INVALID_ENUM, 12};
#endif
#ifdef AL_INVALID_NAME
                case AL_INVALID_NAME:
                    return {s_INVALID_NAME, 12};
#endif
#ifdef AL_INVALID_OPERATION
                case AL_INVALID_OPERATION:
                    return {s_INVALID_OPERATION, 17};
#endif
#ifdef AL_INVALID_VALUE
                case AL_INVALID_VALUE:
                    return {s_INVALID_VALUE, 13};
#endif
#ifdef AL_NO_ERROR
                case AL_NO_ERROR:
                    return {s_NO_ERROR, 8};
#endif
#ifdef AL_OUT_OF_MEMORY
                case AL_OUT_OF_MEMORY:
                    return {s_OUT_OF_MEMORY, 13};
#endif
                default:;
            }
            break;
        case 1: /* buffer_parameter */
            switch(ALenum(aev._value)) {
#ifdef AL_BITS
                case AL_BITS:
                    return {s_BITS, 4};
#endif
#ifdef AL_CHANNELS
                case AL_CHANNELS:
                    return {s_CHANNELS, 8};
#endif
#ifdef AL_FREQUENCY
                case AL_FREQUENCY:
                    return {s_FREQUENCY, 9};
#endif
#ifdef AL_SIZE
                case AL_SIZE:
                    return {s_SIZE, 4};
#endif
                default:;
            }
            break;
        case 2: /* data_format */
            switch(ALenum(aev._value)) {
#ifdef AL_FORMAT_MONO16
                case AL_FORMAT_MONO16:
                    return {s_FORMAT_MONO16, 13};
#endif
#ifdef AL_FORMAT_MONO8
                case AL_FORMAT_MONO8:
                    return {s_FORMAT_MONO8, 12};
#endif
#ifdef AL_FORMAT_STEREO16
                case AL_FORMAT_STEREO16:
                    return {s_FORMAT_STEREO16, 15};
#endif
#ifdef AL_FORMAT_STEREO8
                case AL_FORMAT_STEREO8:
                    return {s_FORMAT_STEREO8, 14};
#endif
                default:;
            }
            break;
        case 3: /* distance_model */
            switch(ALenum(aev._value)) {
#ifdef AL_EXPONENT_DISTANCE
                case AL_EXPONENT_DISTANCE:
                    return {s_EXPONENT_DISTANCE, 17};
#endif
#ifdef AL_EXPONENT_DISTANCE_CLAMPED
                case AL_EXPONENT_DISTANCE_CLAMPED:
                    return {s_EXPONENT_DISTANCE_CLAMPED, 25};
#endif
#ifdef AL_INVERSE_DISTANCE
                case AL_INVERSE_DISTANCE:
                    return {s_INVERSE_DISTANCE, 16};
#endif
#ifdef AL_INVERSE_DISTANCE_CLAMPED
                case AL_INVERSE_DISTANCE_CLAMPED:
                    return {s_INVERSE_DISTANCE_CLAMPED, 24};
#endif
#ifdef AL_LINEAR_DISTANCE
                case AL_LINEAR_DISTANCE:
                    return {s_LINEAR_DISTANCE, 15};
#endif
#ifdef AL_LINEAR_DISTANCE_CLAMPED
                case AL_LINEAR_DISTANCE_CLAMPED:
                    return {s_LINEAR_DISTANCE_CLAMPED, 23};
#endif
#ifdef AL_NONE
                case AL_NONE:
                    return {s_NONE, 4};
#endif
                default:;
            }
            break;
        case 4: /* source_state */
            switch(ALenum(aev._value)) {
#ifdef AL_INITIAL
                case AL_INITIAL:
                    return {s_INITIAL, 7};
#endif
#ifdef AL_PAUSED
                case AL_PAUSED:
                    return {s_PAUSED, 6};
#endif
#ifdef AL_PLAYING
                case AL_PLAYING:
                    return {s_PLAYING, 7};
#endif
#ifdef AL_STOPPED
                case AL_STOPPED:
                    return {s_STOPPED, 7};
#endif
                default:;
            }
            break;
        case 5: /* source_type */
            switch(ALenum(aev._value)) {
#ifdef AL_STATIC
                case AL_STATIC:
                    return {s_STATIC, 6};
#endif
#ifdef AL_STREAMING
                case AL_STREAMING:
                    return {s_STREAMING, 9};
#endif
#ifdef AL_UNDETERMINED
                case AL_UNDETERMINED:
                    return {s_UNDETERMINED, 12};
#endif
                default:;
            }
            break;
        case 6: /* string_query */
            switch(ALenum(aev._value)) {
#ifdef AL_EXTENSIONS
                case AL_EXTENSIONS:
                    return {s_EXTENSIONS, 10};
#endif
#ifdef AL_RENDERER
                case AL_RENDERER:
                    return {s_RENDERER, 8};
#endif
#ifdef AL_VENDOR
                case AL_VENDOR:
                    return {s_VENDOR, 6};
#endif
#ifdef AL_VERSION
                case AL_VERSION:
                    return {s_VERSION, 7};
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
#pragma warning(pop)
#endif //_MSC_VER
