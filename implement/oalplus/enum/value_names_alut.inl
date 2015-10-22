//  File implement/oalplus/enum/value_names_alut.inl
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
cstr_ref
get_enum_value_name(const any_enum_value_alut& aev)
noexcept
{
#ifdef ALUT_ERROR_ALC_ERROR_ON_ENTRY
	static const char s_ERROR_ALC_ERROR_ON_ENTRY[25] = 
		"ERROR_ALC_ERROR_ON_ENTRY";
#endif
#ifdef ALUT_ERROR_AL_ERROR_ON_ENTRY
	static const char s_ERROR_AL_ERROR_ON_ENTRY[24] = 
		"ERROR_AL_ERROR_ON_ENTRY";
#endif
#ifdef ALUT_ERROR_BUFFER_DATA
	static const char s_ERROR_BUFFER_DATA[18] = 
		"ERROR_BUFFER_DATA";
#endif
#ifdef ALUT_ERROR_CLOSE_DEVICE
	static const char s_ERROR_CLOSE_DEVICE[19] = 
		"ERROR_CLOSE_DEVICE";
#endif
#ifdef ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA
	static const char s_ERROR_CORRUPT_OR_TRUNCATED_DATA[32] = 
		"ERROR_CORRUPT_OR_TRUNCATED_DATA";
#endif
#ifdef ALUT_ERROR_CREATE_CONTEXT
	static const char s_ERROR_CREATE_CONTEXT[21] = 
		"ERROR_CREATE_CONTEXT";
#endif
#ifdef ALUT_ERROR_DESTROY_CONTEXT
	static const char s_ERROR_DESTROY_CONTEXT[22] = 
		"ERROR_DESTROY_CONTEXT";
#endif
#ifdef ALUT_ERROR_GEN_BUFFERS
	static const char s_ERROR_GEN_BUFFERS[18] = 
		"ERROR_GEN_BUFFERS";
#endif
#ifdef ALUT_ERROR_INVALID_ENUM
	static const char s_ERROR_INVALID_ENUM[19] = 
		"ERROR_INVALID_ENUM";
#endif
#ifdef ALUT_ERROR_INVALID_OPERATION
	static const char s_ERROR_INVALID_OPERATION[24] = 
		"ERROR_INVALID_OPERATION";
#endif
#ifdef ALUT_ERROR_INVALID_VALUE
	static const char s_ERROR_INVALID_VALUE[20] = 
		"ERROR_INVALID_VALUE";
#endif
#ifdef ALUT_ERROR_IO_ERROR
	static const char s_ERROR_IO_ERROR[15] = 
		"ERROR_IO_ERROR";
#endif
#ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
	static const char s_ERROR_MAKE_CONTEXT_CURRENT[27] = 
		"ERROR_MAKE_CONTEXT_CURRENT";
#endif
#ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
	static const char s_ERROR_NO_CURRENT_CONTEXT[25] = 
		"ERROR_NO_CURRENT_CONTEXT";
#endif
#ifdef ALUT_ERROR_NO_ERROR
	static const char s_ERROR_NO_ERROR[15] = 
		"ERROR_NO_ERROR";
#endif
#ifdef ALUT_ERROR_OPEN_DEVICE
	static const char s_ERROR_OPEN_DEVICE[18] = 
		"ERROR_OPEN_DEVICE";
#endif
#ifdef ALUT_ERROR_OUT_OF_MEMORY
	static const char s_ERROR_OUT_OF_MEMORY[20] = 
		"ERROR_OUT_OF_MEMORY";
#endif
#ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
	static const char s_ERROR_UNSUPPORTED_FILE_SUBTYPE[31] = 
		"ERROR_UNSUPPORTED_FILE_SUBTYPE";
#endif
#ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
	static const char s_ERROR_UNSUPPORTED_FILE_TYPE[28] = 
		"ERROR_UNSUPPORTED_FILE_TYPE";
#endif

	switch(aev._type_id)
	{
		case 0: /* alut_error_code */
			switch(ALenum(aev._value))
			{
#ifdef ALUT_ERROR_ALC_ERROR_ON_ENTRY
				case ALUT_ERROR_ALC_ERROR_ON_ENTRY:
					return {s_ERROR_ALC_ERROR_ON_ENTRY, 24};
#endif
#ifdef ALUT_ERROR_AL_ERROR_ON_ENTRY
				case ALUT_ERROR_AL_ERROR_ON_ENTRY:
					return {s_ERROR_AL_ERROR_ON_ENTRY, 23};
#endif
#ifdef ALUT_ERROR_BUFFER_DATA
				case ALUT_ERROR_BUFFER_DATA:
					return {s_ERROR_BUFFER_DATA, 17};
#endif
#ifdef ALUT_ERROR_CLOSE_DEVICE
				case ALUT_ERROR_CLOSE_DEVICE:
					return {s_ERROR_CLOSE_DEVICE, 18};
#endif
#ifdef ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA
				case ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA:
					return {s_ERROR_CORRUPT_OR_TRUNCATED_DATA, 31};
#endif
#ifdef ALUT_ERROR_CREATE_CONTEXT
				case ALUT_ERROR_CREATE_CONTEXT:
					return {s_ERROR_CREATE_CONTEXT, 20};
#endif
#ifdef ALUT_ERROR_DESTROY_CONTEXT
				case ALUT_ERROR_DESTROY_CONTEXT:
					return {s_ERROR_DESTROY_CONTEXT, 21};
#endif
#ifdef ALUT_ERROR_GEN_BUFFERS
				case ALUT_ERROR_GEN_BUFFERS:
					return {s_ERROR_GEN_BUFFERS, 17};
#endif
#ifdef ALUT_ERROR_INVALID_ENUM
				case ALUT_ERROR_INVALID_ENUM:
					return {s_ERROR_INVALID_ENUM, 18};
#endif
#ifdef ALUT_ERROR_INVALID_OPERATION
				case ALUT_ERROR_INVALID_OPERATION:
					return {s_ERROR_INVALID_OPERATION, 23};
#endif
#ifdef ALUT_ERROR_INVALID_VALUE
				case ALUT_ERROR_INVALID_VALUE:
					return {s_ERROR_INVALID_VALUE, 19};
#endif
#ifdef ALUT_ERROR_IO_ERROR
				case ALUT_ERROR_IO_ERROR:
					return {s_ERROR_IO_ERROR, 14};
#endif
#ifdef ALUT_ERROR_MAKE_CONTEXT_CURRENT
				case ALUT_ERROR_MAKE_CONTEXT_CURRENT:
					return {s_ERROR_MAKE_CONTEXT_CURRENT, 26};
#endif
#ifdef ALUT_ERROR_NO_CURRENT_CONTEXT
				case ALUT_ERROR_NO_CURRENT_CONTEXT:
					return {s_ERROR_NO_CURRENT_CONTEXT, 24};
#endif
#ifdef ALUT_ERROR_NO_ERROR
				case ALUT_ERROR_NO_ERROR:
					return {s_ERROR_NO_ERROR, 14};
#endif
#ifdef ALUT_ERROR_OPEN_DEVICE
				case ALUT_ERROR_OPEN_DEVICE:
					return {s_ERROR_OPEN_DEVICE, 17};
#endif
#ifdef ALUT_ERROR_OUT_OF_MEMORY
				case ALUT_ERROR_OUT_OF_MEMORY:
					return {s_ERROR_OUT_OF_MEMORY, 19};
#endif
#ifdef ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE
				case ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE:
					return {s_ERROR_UNSUPPORTED_FILE_SUBTYPE, 30};
#endif
#ifdef ALUT_ERROR_UNSUPPORTED_FILE_TYPE
				case ALUT_ERROR_UNSUPPORTED_FILE_TYPE:
					return {s_ERROR_UNSUPPORTED_FILE_TYPE, 27};
#endif
				default:;
			}
			break;
	default:;
	}

	(void)aev;
	return {};
}

} // namespace oalplus
