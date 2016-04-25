/**
 *  @file oalplus/error/info_base.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace oalplus {
//------------------------------------------------------------------------------
template <typename Derived>
constexpr inline
error_info_base<Derived>::
error_info_base(ALenum al_err_code)
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
{ }
//------------------------------------------------------------------------------
template <typename Derived>
inline
Derived&
error_info_base<Derived>::
al_error_code(ALenum al_err_code)
noexcept
{
	_al_err_code = al_err_code;
	return _self();
}
//------------------------------------------------------------------------------
template <typename Derived>
inline
ALenum
error_info_base<Derived>::
al_error_code(void) const
noexcept
{
	return _al_err_code;
}
//------------------------------------------------------------------------------
template <typename Derived>
inline
Derived&
error_info_base<Derived>::
al_library_name(const char* al_lb_name)
noexcept
{
#if! OALPLUS_ERROR_NO_AL_LIB
	_al_lb_name = al_lb_name;
#else
	(void)al_lib_name;
#endif
	return _self();
}
//------------------------------------------------------------------------------
template <typename Derived>
inline
const char*
error_info_base<Derived>::
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
template <typename Derived>
inline
Derived&
error_info_base<Derived>::
al_function_name(const char* al_fn_name)
noexcept
{
#if! OALPLUS_ERROR_NO_AL_FUNC
	_al_fn_name = al_fn_name;
#else
	(void)al_fn_name;
#endif
	return _self();
}
//------------------------------------------------------------------------------
template <typename Derived>
inline
const char*
error_info_base<Derived>::
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
template <typename Derived>
inline
Derived&
error_info_base<Derived>::
source_function(const char* src_func)
noexcept
{
#if! OALPLUS_ERROR_NO_SRC_FUNC
	_src_func = src_func;
#else
	(void)src_func;
#endif
	return _self();
}
//------------------------------------------------------------------------------
template <typename Derived>
inline
const char*
error_info_base<Derived>::
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
template <typename Derived>
inline
Derived&
error_info_base<Derived>::
source_file(const char* src_file)
noexcept
{
#if! OALPLUS_ERROR_NO_SRC_FILE
	_src_file = src_file;
#else
	(void)src_file;
#endif
	return _self();
}
//------------------------------------------------------------------------------
template <typename Derived>
inline
const char*
error_info_base<Derived>::
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
template <typename Derived>
inline
Derived&
error_info_base<Derived>::
source_line(unsigned src_line)
noexcept
{
#if! OALPLUS_ERROR_NO_SRC_LINE
	_src_line = src_line;
#else
	(void)src_line;
#endif
	return _self();
}
//------------------------------------------------------------------------------
template <typename Derived>
inline
unsigned
error_info_base<Derived>::
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
} // namespace oalplus
