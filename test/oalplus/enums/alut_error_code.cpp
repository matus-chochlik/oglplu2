//  File test/oalplus/enums/alut_error_code.cpp
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
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OALPLUS_alut_error_code

#include <boost/test/unit_test.hpp>
#include "common_alut.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_alut_error_code_tests)

BOOST_AUTO_TEST_CASE(enum_alut_error_code_values)
{
	using namespace oalplus;
	enum_values_alut ev;
	(void)ev;
	alut_error_code x;
	(void)x;

#ifdef ALUT_ERROR_AL_ERROR_ON_ENTRY
	x = ev.error_al_error_on_entry;
	BOOST_CHECK(x == ev.error_al_error_on_entry);
# ifdef ALUT_ERROR_ALC_ERROR_ON_ENTRY
	BOOST_CHECK(x != ev.error_alc_error_on_entry);
# endif
# ifdef ALUT_ERROR_BUFFER_DATA
	BOOST_CHECK(x != ev.error_buffer_data);
# endif
# ifdef ALUT_ERROR_CLOSE_DEVICE
	BOOST_CHECK(x != ev.error_close_device);
# endif
# ifdef ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA
	BOOST_CHECK(x != ev.error_corrupt_or_truncated_data);
# endif
# ifdef ALUT_ERROR_CREATE_CONTEXT
	BOOST_CHECK(x != ev.error_create_context);
# endif
# ifdef ALUT_ERROR_DESTROY_CONTEXT
	BOOST_CHECK(x != ev.error_destroy_context);
# endif
# ifdef ALUT_ERROR_GEN_BUFFERS
	BOOST_CHECK(x != ev.error_gen_buffers);
# endif
# ifdef ALUT_ERROR_INVALID_ENUM
	BOOST_CHECK(x != ev.error_invalid_enum);
# endif
# ifdef ALUT_ERROR_INVALID_OPERATION
	BOOST_CHECK(x != ev.error_invalid_operation);
# endif
# ifdef ALUT_ERROR_INVALID_VALUE
	BOOST_CHECK(x != ev.error_invalid_value);
# endif
# ifdef ALUT_ERROR_IO_ERROR
	BOOST_CHECK(x != ev.error_io_error);
# endif
# ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	BOOST_CHECK(x != ev.error_make_context_current);
# endif
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_ALC_ERROR_ON_ENTRY
	x = ev.error_alc_error_on_entry;
	BOOST_CHECK(x == ev.error_alc_error_on_entry);
# ifdef ALUT_ERROR_BUFFER_DATA
	BOOST_CHECK(x != ev.error_buffer_data);
# endif
# ifdef ALUT_ERROR_CLOSE_DEVICE
	BOOST_CHECK(x != ev.error_close_device);
# endif
# ifdef ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA
	BOOST_CHECK(x != ev.error_corrupt_or_truncated_data);
# endif
# ifdef ALUT_ERROR_CREATE_CONTEXT
	BOOST_CHECK(x != ev.error_create_context);
# endif
# ifdef ALUT_ERROR_DESTROY_CONTEXT
	BOOST_CHECK(x != ev.error_destroy_context);
# endif
# ifdef ALUT_ERROR_GEN_BUFFERS
	BOOST_CHECK(x != ev.error_gen_buffers);
# endif
# ifdef ALUT_ERROR_INVALID_ENUM
	BOOST_CHECK(x != ev.error_invalid_enum);
# endif
# ifdef ALUT_ERROR_INVALID_OPERATION
	BOOST_CHECK(x != ev.error_invalid_operation);
# endif
# ifdef ALUT_ERROR_INVALID_VALUE
	BOOST_CHECK(x != ev.error_invalid_value);
# endif
# ifdef ALUT_ERROR_IO_ERROR
	BOOST_CHECK(x != ev.error_io_error);
# endif
# ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	BOOST_CHECK(x != ev.error_make_context_current);
# endif
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_BUFFER_DATA
	x = ev.error_buffer_data;
	BOOST_CHECK(x == ev.error_buffer_data);
# ifdef ALUT_ERROR_CLOSE_DEVICE
	BOOST_CHECK(x != ev.error_close_device);
# endif
# ifdef ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA
	BOOST_CHECK(x != ev.error_corrupt_or_truncated_data);
# endif
# ifdef ALUT_ERROR_CREATE_CONTEXT
	BOOST_CHECK(x != ev.error_create_context);
# endif
# ifdef ALUT_ERROR_DESTROY_CONTEXT
	BOOST_CHECK(x != ev.error_destroy_context);
# endif
# ifdef ALUT_ERROR_GEN_BUFFERS
	BOOST_CHECK(x != ev.error_gen_buffers);
# endif
# ifdef ALUT_ERROR_INVALID_ENUM
	BOOST_CHECK(x != ev.error_invalid_enum);
# endif
# ifdef ALUT_ERROR_INVALID_OPERATION
	BOOST_CHECK(x != ev.error_invalid_operation);
# endif
# ifdef ALUT_ERROR_INVALID_VALUE
	BOOST_CHECK(x != ev.error_invalid_value);
# endif
# ifdef ALUT_ERROR_IO_ERROR
	BOOST_CHECK(x != ev.error_io_error);
# endif
# ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	BOOST_CHECK(x != ev.error_make_context_current);
# endif
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_CLOSE_DEVICE
	x = ev.error_close_device;
	BOOST_CHECK(x == ev.error_close_device);
# ifdef ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA
	BOOST_CHECK(x != ev.error_corrupt_or_truncated_data);
# endif
# ifdef ALUT_ERROR_CREATE_CONTEXT
	BOOST_CHECK(x != ev.error_create_context);
# endif
# ifdef ALUT_ERROR_DESTROY_CONTEXT
	BOOST_CHECK(x != ev.error_destroy_context);
# endif
# ifdef ALUT_ERROR_GEN_BUFFERS
	BOOST_CHECK(x != ev.error_gen_buffers);
# endif
# ifdef ALUT_ERROR_INVALID_ENUM
	BOOST_CHECK(x != ev.error_invalid_enum);
# endif
# ifdef ALUT_ERROR_INVALID_OPERATION
	BOOST_CHECK(x != ev.error_invalid_operation);
# endif
# ifdef ALUT_ERROR_INVALID_VALUE
	BOOST_CHECK(x != ev.error_invalid_value);
# endif
# ifdef ALUT_ERROR_IO_ERROR
	BOOST_CHECK(x != ev.error_io_error);
# endif
# ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	BOOST_CHECK(x != ev.error_make_context_current);
# endif
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA
	x = ev.error_corrupt_or_truncated_data;
	BOOST_CHECK(x == ev.error_corrupt_or_truncated_data);
# ifdef ALUT_ERROR_CREATE_CONTEXT
	BOOST_CHECK(x != ev.error_create_context);
# endif
# ifdef ALUT_ERROR_DESTROY_CONTEXT
	BOOST_CHECK(x != ev.error_destroy_context);
# endif
# ifdef ALUT_ERROR_GEN_BUFFERS
	BOOST_CHECK(x != ev.error_gen_buffers);
# endif
# ifdef ALUT_ERROR_INVALID_ENUM
	BOOST_CHECK(x != ev.error_invalid_enum);
# endif
# ifdef ALUT_ERROR_INVALID_OPERATION
	BOOST_CHECK(x != ev.error_invalid_operation);
# endif
# ifdef ALUT_ERROR_INVALID_VALUE
	BOOST_CHECK(x != ev.error_invalid_value);
# endif
# ifdef ALUT_ERROR_IO_ERROR
	BOOST_CHECK(x != ev.error_io_error);
# endif
# ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	BOOST_CHECK(x != ev.error_make_context_current);
# endif
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_CREATE_CONTEXT
	x = ev.error_create_context;
	BOOST_CHECK(x == ev.error_create_context);
# ifdef ALUT_ERROR_DESTROY_CONTEXT
	BOOST_CHECK(x != ev.error_destroy_context);
# endif
# ifdef ALUT_ERROR_GEN_BUFFERS
	BOOST_CHECK(x != ev.error_gen_buffers);
# endif
# ifdef ALUT_ERROR_INVALID_ENUM
	BOOST_CHECK(x != ev.error_invalid_enum);
# endif
# ifdef ALUT_ERROR_INVALID_OPERATION
	BOOST_CHECK(x != ev.error_invalid_operation);
# endif
# ifdef ALUT_ERROR_INVALID_VALUE
	BOOST_CHECK(x != ev.error_invalid_value);
# endif
# ifdef ALUT_ERROR_IO_ERROR
	BOOST_CHECK(x != ev.error_io_error);
# endif
# ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	BOOST_CHECK(x != ev.error_make_context_current);
# endif
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_DESTROY_CONTEXT
	x = ev.error_destroy_context;
	BOOST_CHECK(x == ev.error_destroy_context);
# ifdef ALUT_ERROR_GEN_BUFFERS
	BOOST_CHECK(x != ev.error_gen_buffers);
# endif
# ifdef ALUT_ERROR_INVALID_ENUM
	BOOST_CHECK(x != ev.error_invalid_enum);
# endif
# ifdef ALUT_ERROR_INVALID_OPERATION
	BOOST_CHECK(x != ev.error_invalid_operation);
# endif
# ifdef ALUT_ERROR_INVALID_VALUE
	BOOST_CHECK(x != ev.error_invalid_value);
# endif
# ifdef ALUT_ERROR_IO_ERROR
	BOOST_CHECK(x != ev.error_io_error);
# endif
# ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	BOOST_CHECK(x != ev.error_make_context_current);
# endif
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_GEN_BUFFERS
	x = ev.error_gen_buffers;
	BOOST_CHECK(x == ev.error_gen_buffers);
# ifdef ALUT_ERROR_INVALID_ENUM
	BOOST_CHECK(x != ev.error_invalid_enum);
# endif
# ifdef ALUT_ERROR_INVALID_OPERATION
	BOOST_CHECK(x != ev.error_invalid_operation);
# endif
# ifdef ALUT_ERROR_INVALID_VALUE
	BOOST_CHECK(x != ev.error_invalid_value);
# endif
# ifdef ALUT_ERROR_IO_ERROR
	BOOST_CHECK(x != ev.error_io_error);
# endif
# ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	BOOST_CHECK(x != ev.error_make_context_current);
# endif
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_INVALID_ENUM
	x = ev.error_invalid_enum;
	BOOST_CHECK(x == ev.error_invalid_enum);
# ifdef ALUT_ERROR_INVALID_OPERATION
	BOOST_CHECK(x != ev.error_invalid_operation);
# endif
# ifdef ALUT_ERROR_INVALID_VALUE
	BOOST_CHECK(x != ev.error_invalid_value);
# endif
# ifdef ALUT_ERROR_IO_ERROR
	BOOST_CHECK(x != ev.error_io_error);
# endif
# ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	BOOST_CHECK(x != ev.error_make_context_current);
# endif
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_INVALID_OPERATION
	x = ev.error_invalid_operation;
	BOOST_CHECK(x == ev.error_invalid_operation);
# ifdef ALUT_ERROR_INVALID_VALUE
	BOOST_CHECK(x != ev.error_invalid_value);
# endif
# ifdef ALUT_ERROR_IO_ERROR
	BOOST_CHECK(x != ev.error_io_error);
# endif
# ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	BOOST_CHECK(x != ev.error_make_context_current);
# endif
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_INVALID_VALUE
	x = ev.error_invalid_value;
	BOOST_CHECK(x == ev.error_invalid_value);
# ifdef ALUT_ERROR_IO_ERROR
	BOOST_CHECK(x != ev.error_io_error);
# endif
# ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	BOOST_CHECK(x != ev.error_make_context_current);
# endif
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_IO_ERROR
	x = ev.error_io_error;
	BOOST_CHECK(x == ev.error_io_error);
# ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	BOOST_CHECK(x != ev.error_make_context_current);
# endif
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	x = ev.error_make_context_current;
	BOOST_CHECK(x == ev.error_make_context_current);
# ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	BOOST_CHECK(x != ev.error_no_current_context);
# endif
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	x = ev.error_no_current_context;
	BOOST_CHECK(x == ev.error_no_current_context);
# ifdef ALUT_ERROR_NO_ERROR
	BOOST_CHECK(x != ev.error_no_error);
# endif
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_NO_ERROR
	x = ev.error_no_error;
	BOOST_CHECK(x == ev.error_no_error);
# ifdef ALUT_ERROR_OPEN_DEVICE
	BOOST_CHECK(x != ev.error_open_device);
# endif
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_OPEN_DEVICE
	x = ev.error_open_device;
	BOOST_CHECK(x == ev.error_open_device);
# ifdef ALUT_ERROR_OUT_OF_MEMORY
	BOOST_CHECK(x != ev.error_out_of_memory);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_OUT_OF_MEMORY
	x = ev.error_out_of_memory;
	BOOST_CHECK(x == ev.error_out_of_memory);
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	BOOST_CHECK(x != ev.error_unsupported_file_subtype);
# endif
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	x = ev.error_unsupported_file_subtype;
	BOOST_CHECK(x == ev.error_unsupported_file_subtype);
# ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	BOOST_CHECK(x != ev.error_unsupported_file_type);
# endif
#endif

#ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	x = ev.error_unsupported_file_type;
	BOOST_CHECK(x == ev.error_unsupported_file_type);
#endif
}

BOOST_AUTO_TEST_CASE(enum_alut_error_code_names)
{
	using namespace oalplus;
	enum_values_alut ev;
	(void)ev;
	alut_error_code x;
	(void)x;

#ifdef ALUT_ERROR_AL_ERROR_ON_ENTRY
	x = ev.error_al_error_on_entry;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_AL_ERROR_ON_ENTRY"
	) == 0);
#endif

#ifdef ALUT_ERROR_ALC_ERROR_ON_ENTRY
	x = ev.error_alc_error_on_entry;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_ALC_ERROR_ON_ENTRY"
	) == 0);
#endif

#ifdef ALUT_ERROR_BUFFER_DATA
	x = ev.error_buffer_data;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_BUFFER_DATA"
	) == 0);
#endif

#ifdef ALUT_ERROR_CLOSE_DEVICE
	x = ev.error_close_device;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_CLOSE_DEVICE"
	) == 0);
#endif

#ifdef ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA
	x = ev.error_corrupt_or_truncated_data;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_CORRUPT_OR_TRUNCATED_DATA"
	) == 0);
#endif

#ifdef ALUT_ERROR_CREATE_CONTEXT
	x = ev.error_create_context;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_CREATE_CONTEXT"
	) == 0);
#endif

#ifdef ALUT_ERROR_DESTROY_CONTEXT
	x = ev.error_destroy_context;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_DESTROY_CONTEXT"
	) == 0);
#endif

#ifdef ALUT_ERROR_GEN_BUFFERS
	x = ev.error_gen_buffers;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_GEN_BUFFERS"
	) == 0);
#endif

#ifdef ALUT_ERROR_INVALID_ENUM
	x = ev.error_invalid_enum;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_INVALID_ENUM"
	) == 0);
#endif

#ifdef ALUT_ERROR_INVALID_OPERATION
	x = ev.error_invalid_operation;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_INVALID_OPERATION"
	) == 0);
#endif

#ifdef ALUT_ERROR_INVALID_VALUE
	x = ev.error_invalid_value;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_INVALID_VALUE"
	) == 0);
#endif

#ifdef ALUT_ERROR_IO_ERROR
	x = ev.error_io_error;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_IO_ERROR"
	) == 0);
#endif

#ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	x = ev.error_make_context_current;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_MAKE_CONTEXT_CURRENT"
	) == 0);
#endif

#ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	x = ev.error_no_current_context;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_NO_CURRENT_CONTEXT"
	) == 0);
#endif

#ifdef ALUT_ERROR_NO_ERROR
	x = ev.error_no_error;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_NO_ERROR"
	) == 0);
#endif

#ifdef ALUT_ERROR_OPEN_DEVICE
	x = ev.error_open_device;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_OPEN_DEVICE"
	) == 0);
#endif

#ifdef ALUT_ERROR_OUT_OF_MEMORY
	x = ev.error_out_of_memory;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_OUT_OF_MEMORY"
	) == 0);
#endif

#ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	x = ev.error_unsupported_file_subtype;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_UNSUPPORTED_FILE_SUBTYPE"
	) == 0);
#endif

#ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	x = ev.error_unsupported_file_type;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"ERROR_UNSUPPORTED_FILE_TYPE"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_alut_error_code_range)
{
	using namespace oalplus;
	auto count = enum_value_range<alut_error_code>().size();

#ifdef ALUT_ERROR_AL_ERROR_ON_ENTRY
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_AL_ERROR_ON_ENTRY)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_ALC_ERROR_ON_ENTRY
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_ALC_ERROR_ON_ENTRY)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_BUFFER_DATA
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_BUFFER_DATA)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_CLOSE_DEVICE
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_CLOSE_DEVICE)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_CREATE_CONTEXT
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_CREATE_CONTEXT)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_DESTROY_CONTEXT
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_DESTROY_CONTEXT)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_GEN_BUFFERS
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_GEN_BUFFERS)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_INVALID_ENUM
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_INVALID_ENUM)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_INVALID_OPERATION
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_INVALID_OPERATION)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_INVALID_VALUE
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_INVALID_VALUE)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_IO_ERROR
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_IO_ERROR)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_MAKE_CONTEXT_CURRENT)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_NO_CURRENT_CONTEXT)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_NO_ERROR
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_NO_ERROR)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_OPEN_DEVICE
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_OPEN_DEVICE)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_OUT_OF_MEMORY
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_OUT_OF_MEMORY)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE)
	) != r.end());
}
#endif

#ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
{
	--count;
	auto r = enum_value_range<alut_error_code>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		alut_error_code(ALUT_ERROR_UNSUPPORTED_FILE_TYPE)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_alut_error_code_any)
{
	using namespace oalplus;
	enum_values_alut ev;
	(void)ev;
	alut_error_code x, y;
	(void)x;
	(void)y;
	any_enum_value_alut a;
	(void)a;

#ifdef ALUT_ERROR_AL_ERROR_ON_ENTRY
	x = ev.error_al_error_on_entry;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_al_error_on_entry);
#endif

#ifdef ALUT_ERROR_ALC_ERROR_ON_ENTRY
	x = ev.error_alc_error_on_entry;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_alc_error_on_entry);
#endif

#ifdef ALUT_ERROR_BUFFER_DATA
	x = ev.error_buffer_data;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_buffer_data);
#endif

#ifdef ALUT_ERROR_CLOSE_DEVICE
	x = ev.error_close_device;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_close_device);
#endif

#ifdef ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA
	x = ev.error_corrupt_or_truncated_data;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_corrupt_or_truncated_data);
#endif

#ifdef ALUT_ERROR_CREATE_CONTEXT
	x = ev.error_create_context;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_create_context);
#endif

#ifdef ALUT_ERROR_DESTROY_CONTEXT
	x = ev.error_destroy_context;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_destroy_context);
#endif

#ifdef ALUT_ERROR_GEN_BUFFERS
	x = ev.error_gen_buffers;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_gen_buffers);
#endif

#ifdef ALUT_ERROR_INVALID_ENUM
	x = ev.error_invalid_enum;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_invalid_enum);
#endif

#ifdef ALUT_ERROR_INVALID_OPERATION
	x = ev.error_invalid_operation;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_invalid_operation);
#endif

#ifdef ALUT_ERROR_INVALID_VALUE
	x = ev.error_invalid_value;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_invalid_value);
#endif

#ifdef ALUT_ERROR_IO_ERROR
	x = ev.error_io_error;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_io_error);
#endif

#ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	x = ev.error_make_context_current;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_make_context_current);
#endif

#ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	x = ev.error_no_current_context;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_no_current_context);
#endif

#ifdef ALUT_ERROR_NO_ERROR
	x = ev.error_no_error;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_no_error);
#endif

#ifdef ALUT_ERROR_OPEN_DEVICE
	x = ev.error_open_device;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_open_device);
#endif

#ifdef ALUT_ERROR_OUT_OF_MEMORY
	x = ev.error_out_of_memory;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_out_of_memory);
#endif

#ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	x = ev.error_unsupported_file_subtype;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_unsupported_file_subtype);
#endif

#ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	x = ev.error_unsupported_file_type;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.error_unsupported_file_type);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
