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
 : error_info_base<error_info>(al_err_code)
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
