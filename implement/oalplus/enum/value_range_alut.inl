//  File implement/oalplus/enum/value_range_alut.inl
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

namespace oalplus {

OALPLUS_LIB_FUNC
std::pair<const void*, span_size_t>
get_enum_value_range(const any_enum_class_alut& aec) noexcept {
    switch(aec._type_id) {
        case 0: /* alut_error_code */
        {
            static const ALenum vr[] = {
#ifdef ALUT_ERROR_ALC_ERROR_ON_ENTRY
              ALUT_ERROR_ALC_ERROR_ON_ENTRY,
#endif
#ifdef ALUT_ERROR_AL_ERROR_ON_ENTRY
              ALUT_ERROR_AL_ERROR_ON_ENTRY,
#endif
#ifdef ALUT_ERROR_BUFFER_DATA
              ALUT_ERROR_BUFFER_DATA,
#endif
#ifdef ALUT_ERROR_CLOSE_DEVICE
              ALUT_ERROR_CLOSE_DEVICE,
#endif
#ifdef ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA
              ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA,
#endif
#ifdef ALUT_ERROR_CREATE_CONTEXT
              ALUT_ERROR_CREATE_CONTEXT,
#endif
#ifdef ALUT_ERROR_DESTROY_CONTEXT
              ALUT_ERROR_DESTROY_CONTEXT,
#endif
#ifdef ALUT_ERROR_GEN_BUFFERS
              ALUT_ERROR_GEN_BUFFERS,
#endif
#ifdef ALUT_ERROR_INVALID_ENUM
              ALUT_ERROR_INVALID_ENUM,
#endif
#ifdef ALUT_ERROR_INVALID_OPERATION
              ALUT_ERROR_INVALID_OPERATION,
#endif
#ifdef ALUT_ERROR_INVALID_VALUE
              ALUT_ERROR_INVALID_VALUE,
#endif
#ifdef ALUT_ERROR_IO_ERROR
              ALUT_ERROR_IO_ERROR,
#endif
#ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
              ALUT_ERROR_MAKE_CONTEXT_CURRENT,
#endif
#ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
              ALUT_ERROR_NO_CURRENT_CONTEXT,
#endif
#ifdef ALUT_ERROR_NO_ERROR
              ALUT_ERROR_NO_ERROR,
#endif
#ifdef ALUT_ERROR_OPEN_DEVICE
              ALUT_ERROR_OPEN_DEVICE,
#endif
#ifdef ALUT_ERROR_OUT_OF_MEMORY
              ALUT_ERROR_OUT_OF_MEMORY,
#endif
#ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
              ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE,
#endif
#ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
              ALUT_ERROR_UNSUPPORTED_FILE_TYPE,
#endif
              0};
            return {vr, sizeof(vr) / sizeof(vr[0]) - 1};
        }
        default:;
    }

    EAGINE_MAYBE_UNUSED(aec);
    return {nullptr, 0};
}

} // namespace oalplus
