/**
 *  @file oglplus/error/info.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace oglplus {
//------------------------------------------------------------------------------
constexpr inline
GLuint
error_info::
invalid_gl_obj_name(void)
noexcept
{
	return ~GLuint(0);
}
//------------------------------------------------------------------------------
constexpr inline
error_info::
error_info(GLenum gl_err_code)
noexcept
 : _gl_err_code(gl_err_code)
#if! OGLPLUS_ERROR_NO_GL_LIB
 , _gl_lb_name(nullptr)
#endif
#if! OGLPLUS_ERROR_NO_GL_FUNC
 , _gl_fn_name(nullptr)
#endif
#if! OGLPLUS_ERROR_NO_SRC_FUNC
 , _src_func(nullptr)
#endif
#if! OGLPLUS_ERROR_NO_SRC_FILE
 , _src_file(nullptr)
#endif
#if! OGLPLUS_ERROR_NO_SRC_LINE
 , _src_line(0)
#endif
#if !OGLPLUS_ERROR_NO_OBJ_NAME
 , _obj_name(invalid_gl_obj_name())
#endif
#if !OGLPLUS_ERROR_NO_SUB_NAME
 , _sub_name(invalid_gl_obj_name())
#endif
{ }
//------------------------------------------------------------------------------
inline
error_info&
error_info::
gl_error_code(GLenum gl_err_code)
noexcept
{
	_gl_err_code = gl_err_code;
	return *this;
}
//------------------------------------------------------------------------------
inline
GLenum
error_info::
gl_error_code(void) const
noexcept
{
	return _gl_err_code;
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
gl_library_name(const char* gl_lb_name)
noexcept
{
#if! OGLPLUS_ERROR_NO_GL_LIB
	_gl_lb_name = gl_lb_name;
#else
	(void)gl_lib_name;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
const char*
error_info::
gl_library_name(void) const
noexcept
{
#if! OGLPLUS_ERROR_NO_GL_LIB
	return _gl_lb_name;
#else
	return nullptr;
#endif
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
gl_function_name(const char* gl_fn_name)
noexcept
{
#if! OGLPLUS_ERROR_NO_GL_FUNC
	_gl_fn_name = gl_fn_name;
#else
	(void)gl_fn_name;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
const char*
error_info::
gl_function_name(void) const
noexcept
{
#if! OGLPLUS_ERROR_NO_GL_FUNC
	return _gl_fn_name;
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
#if! OGLPLUS_ERROR_NO_SRC_FUNC
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
#if! OGLPLUS_ERROR_NO_SRC_FUNC
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
#if! OGLPLUS_ERROR_NO_SRC_FILE
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
#if! OGLPLUS_ERROR_NO_SRC_FILE
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
#if! OGLPLUS_ERROR_NO_SRC_LINE
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
#if! OGLPLUS_ERROR_NO_SRC_LINE
	return _src_line;
#else
	return 0u;
#endif
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
gl_object_name(GLuint obj_name)
noexcept
{
#if !OGLPLUS_ERROR_NO_OBJ_NAME
	_obj_name = obj_name;
#else
	(void)obj_name;
#endif
	return *this;
}
//------------------------------------------------------------------------------
template <typename ObjTag>
inline
error_info&
error_info::
gl_object(const object_names<ObjTag, GLuint>& obj)
noexcept
{
#if !OGLPLUS_ERROR_NO_OBJ_NAME
	return gl_object_name(get_raw_name(obj));
#else
	(void)obj;
	return *this;
#endif
}
//------------------------------------------------------------------------------
inline
GLuint
error_info::
gl_object_name(void) const
noexcept
{
#if !OGLPLUS_ERROR_NO_OBJ_NAME
	return _obj_name;
#else
	return invalid_gl_obj_name();
#endif
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
gl_subject_name(GLuint sub_name)
noexcept
{
#if !OGLPLUS_ERROR_NO_SUB_NAME
	_sub_name = sub_name;
#else
	(void)sub_name;
#endif
	return *this;
}
//------------------------------------------------------------------------------
template <typename ObjTag>
inline
error_info&
error_info::
gl_subject(const object_names<ObjTag, GLuint>& sub)
noexcept
{
#if !OGLPLUS_ERROR_NO_SUB_NAME
	return gl_subject_name(get_raw_name(sub));
#else
	(void)sub;
	return *this;
#endif
}
//------------------------------------------------------------------------------
inline
GLuint
error_info::
gl_subject_name(void) const
noexcept
{
#if !OGLPLUS_ERROR_NO_SUB_NAME
	return _sub_name;
#else
	return invalid_gl_obj_name();
#endif
}
//------------------------------------------------------------------------------
} // namespace oglplus
