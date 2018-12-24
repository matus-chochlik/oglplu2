//  File include/oalplus/enum/values_alut.hpp
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
#ifndef OALPLUS_ALUT_ENUM_VALUES_HPP
#define OALPLUS_ALUT_ENUM_VALUES_HPP

#include "../utils/mp_list.hpp"
#include "types_alut.hpp"

namespace oalplus {
struct enum_values_alut {

#ifdef ALUT_ERROR_AL_ERROR_ON_ENTRY
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_al_error_on_entry = {ALUT_ERROR_AL_ERROR_ON_ENTRY};
#endif

#ifdef ALUT_ERROR_ALC_ERROR_ON_ENTRY
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_alc_error_on_entry = {ALUT_ERROR_ALC_ERROR_ON_ENTRY};
#endif

#ifdef ALUT_ERROR_BUFFER_DATA
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_buffer_data = {ALUT_ERROR_BUFFER_DATA};
#endif

#ifdef ALUT_ERROR_CLOSE_DEVICE
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_close_device = {ALUT_ERROR_CLOSE_DEVICE};
#endif

#ifdef ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_corrupt_or_truncated_data = {ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA};
#endif

#ifdef ALUT_ERROR_CREATE_CONTEXT
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_create_context = {ALUT_ERROR_CREATE_CONTEXT};
#endif

#ifdef ALUT_ERROR_DESTROY_CONTEXT
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_destroy_context = {ALUT_ERROR_DESTROY_CONTEXT};
#endif

#ifdef ALUT_ERROR_GEN_BUFFERS
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_gen_buffers = {ALUT_ERROR_GEN_BUFFERS};
#endif

#ifdef ALUT_ERROR_INVALID_ENUM
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_invalid_enum = {ALUT_ERROR_INVALID_ENUM};
#endif

#ifdef ALUT_ERROR_INVALID_OPERATION
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_invalid_operation = {ALUT_ERROR_INVALID_OPERATION};
#endif

#ifdef ALUT_ERROR_INVALID_VALUE
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_invalid_value = {ALUT_ERROR_INVALID_VALUE};
#endif

#ifdef ALUT_ERROR_IO_ERROR
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_io_error = {ALUT_ERROR_IO_ERROR};
#endif

#ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_make_context_current = {ALUT_ERROR_MAKE_CONTEXT_CURRENT};
#endif

#ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_no_current_context = {ALUT_ERROR_NO_CURRENT_CONTEXT};
#endif

#ifdef ALUT_ERROR_NO_ERROR
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_no_error = {ALUT_ERROR_NO_ERROR};
#endif

#ifdef ALUT_ERROR_OPEN_DEVICE
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_open_device = {ALUT_ERROR_OPEN_DEVICE};
#endif

#ifdef ALUT_ERROR_OUT_OF_MEMORY
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_out_of_memory = {ALUT_ERROR_OUT_OF_MEMORY};
#endif

#ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_unsupported_file_subtype = {ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE};
#endif

#ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
    static constexpr const enum_value<ALenum, mp_list<oalplus::alut_error_code>>
      error_unsupported_file_type = {ALUT_ERROR_UNSUPPORTED_FILE_TYPE};
#endif

}; // struct enum_values
} // namespace oalplus

#endif // OALPLUS_ALUT_ENUM_VALUES_HPP
