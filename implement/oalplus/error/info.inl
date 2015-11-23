/**
 *  @file oalplus/error/info.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace oalplus {
//------------------------------------------------------------------------------
constexpr inline
error_info::
error_info(ALenum al_err_code)
noexcept
 : _al_err_code(al_err_code)
#if! OALPLUS_ERROR_NO_AL_LIB
 , _al_lb_name(nullptr)
#endif
#if! OALPLUS_ERROR_NO_AL_FUNC
 , _al_fn_name(nullptr)
#endif
#if! OALPLUS_ERROR_NO_SRC_FUNC
 , _src_func(nullptr)
#endif
#if! OALPLUS_ERROR_NO_SRC_FILE
 , _src_file(nullptr)
#endif
#if! OALPLUS_ERROR_NO_SRC_LINE
 , _src_line(0)
#endif
#if !OALPLUS_ERROR_NO_OBJECT
 , _obj_name()
#endif
#if !OALPLUS_ERROR_NO_INDEX
 , _index(~ALuint(0))
#endif
#if !OALPLUS_ERROR_NO_ENUM_VALUE
 , _enum_val()
#endif
{ }
//------------------------------------------------------------------------------
inline
error_info&
error_info::
al_error_code(ALenum al_err_code)
noexcept
{
	_al_err_code = al_err_code;
	return *this;
}
//------------------------------------------------------------------------------
inline
ALenum
error_info::
al_error_code(void) const
noexcept
{
	return _al_err_code;
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
al_library_name(const char* al_lb_name)
noexcept
{
#if! OALPLUS_ERROR_NO_AL_LIB
	_al_lb_name = al_lb_name;
#else
	(void)al_lib_name;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
const char*
error_info::
al_library_name(void) const
noexcept
{
#if! OALPLUS_ERROR_NO_AL_LIB
	return _al_lb_name;
#else
	return nullptr;
#endif
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
al_function_name(const char* al_fn_name)
noexcept
{
#if! OALPLUS_ERROR_NO_AL_FUNC
	_al_fn_name = al_fn_name;
#else
	(void)al_fn_name;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
const char*
error_info::
al_function_name(void) const
noexcept
{
#if! OALPLUS_ERROR_NO_AL_FUNC
	return _al_fn_name;
#else
	return nullptr;
#endif
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
source_function(const char* src_func)
noexcept
{
#if! OALPLUS_ERROR_NO_SRC_FUNC
	_src_func = src_func;
#else
	(void)src_func;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
const char*
error_info::
source_function(void) const
noexcept
{
#if! OALPLUS_ERROR_NO_SRC_FUNC
	return _src_func;
#else
	return nullptr;
#endif
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
source_file(const char* src_file)
noexcept
{
#if! OALPLUS_ERROR_NO_SRC_FILE
	_src_file = src_file;
#else
	(void)src_file;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
const char*
error_info::
source_file(void) const
noexcept
{
#if! OALPLUS_ERROR_NO_SRC_FILE
	return _src_file;
#else
	return nullptr;
#endif
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
source_line(unsigned src_line)
noexcept
{
#if! OALPLUS_ERROR_NO_SRC_LINE
	_src_line = src_line;
#else
	(void)src_line;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
unsigned
error_info::
source_line(void) const
noexcept
{
#if! OALPLUS_ERROR_NO_SRC_LINE
	return _src_line;
#else
	return 0u;
#endif
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
al_object(const any_object_name& obj_name)
noexcept
{
#if !OALPLUS_ERROR_NO_OBJECT
	_obj_name = obj_name;
#else
	(void)obj_name;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
any_object_name
error_info::
al_object(void) const
noexcept
{
#if !OALPLUS_ERROR_NO_OBJECT
	return _obj_name;
#else
	return invalid_al_obj_name();
#endif
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
index(ALuint idx)
noexcept
{
#if !OALPLUS_ERROR_NO_INDEX
	_index = idx;
#else
	(void)idx;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
ALuint
error_info::
index(void) const
noexcept
{
#if !OALPLUS_ERROR_NO_INDEX
	return _index;
#else
	return ~ALuint(0);
#endif
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
al_enum_value(const any_enum_value& enum_val)
noexcept
{
#if !OALPLUS_ERROR_NO_ENUM_VALUE
	_enum_val = enum_val;
#else
	(void)enum_val;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
const any_enum_value&
error_info::
al_enum_value(void) const
noexcept
{
#if !OALPLUS_ERROR_NO_ENUM_VALUE
	return _enum_val;
#else
	static any_enum_value enum_val;
	return enum_val;
#endif
}
//------------------------------------------------------------------------------
} // namespace oalplus
