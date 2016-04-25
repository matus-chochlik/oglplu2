/**
 *  @file oglplus/error/info.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/enum/types.hpp>
#include <string>
#include <vector>
#endif

#ifndef GL_SHADER
#define GL_SHADER 0x82E1
#endif

#ifndef GL_PROGRAM
#define GL_PROGRAM 0x82E2
#endif

#ifndef GL_PROGRAM_PIPELINE
#define GL_PROGRAM_PIPELINE 0x82E4
#endif

namespace oglplus {
//------------------------------------------------------------------------------
#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
//------------------------------------------------------------------------------
#if !OGLPLUS_ERROR_NO_EXTENDED_INFO
//------------------------------------------------------------------------------
struct extended_error_info
{
#if !OGLPLUS_ERROR_NO_SUBJECT
	any_object_name _sub_name;
#endif

#if !OGLPLUS_ERROR_NO_INFO_LOG
	std::string _info_log;
#endif

#if !OGLPLUS_ERROR_NO_IDENTIFIER
	std::string _identifier;
#endif

	extended_error_info(void)
	noexcept
	{ }
};
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
extended_error_info&
error_info::
_ext_info(void) const
noexcept
{
	if(!_ext_info_ptr)
	{
		try { _ext_info_ptr.reset(new extended_error_info()); }
		catch(...) { }
	}
	if(!_ext_info_ptr)
	{
		static extended_error_info fbk;
		return fbk;
	}
	return *_ext_info_ptr;
}
//------------------------------------------------------------------------------
#endif // NO_EXTENDED_INFO
//------------------------------------------------------------------------------
#endif // LINK_LIBRARY
//------------------------------------------------------------------------------
inline
error_info::
error_info(GLenum gl_err_code)
noexcept
 : _gl_err_code(gl_err_code)
 , _ext_info_ptr()
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
#if !OGLPLUS_ERROR_NO_OBJECT
 , _obj_name()
#endif
#if !OGLPLUS_ERROR_NO_INDEX
 , _index(invalid_index())
#endif
#if !OGLPLUS_ERROR_NO_ENUM_VALUE
 , _enum_val()
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
	(void)gl_lb_name;
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
gl_object(const any_object_name& obj_name)
noexcept
{
#if !OGLPLUS_ERROR_NO_OBJECT
	_obj_name = obj_name;
#else
	(void)obj_name;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
gl_object_binding(const any_object_type&, const any_enum_value&)
noexcept
{
	// TODO
	return *this;
}
//------------------------------------------------------------------------------
inline
any_object_name
error_info::
gl_object(void) const
noexcept
{
#if !OGLPLUS_ERROR_NO_OBJECT
	return _obj_name;
#else
	return any_object_name();
#endif
}
//------------------------------------------------------------------------------
#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
error_info&
error_info::
gl_subject_binding(const any_object_type&, const any_enum_value&)
noexcept
{
	// TODO
	return *this;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
error_info&
error_info::
gl_subject(const any_object_name& sub_name)
noexcept
{
#if !OGLPLUS_ERROR_NO_SUBJECT
	_ext_info()._sub_name = sub_name;
#else
	(void)sub_name;
#endif
	return *this;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
any_object_name
error_info::
gl_subject(void) const
noexcept
{
#if !OGLPLUS_ERROR_NO_SUBJECT
	return _ext_info()._sub_name;
#else
	return any_object_name();
#endif
}
//------------------------------------------------------------------------------
#endif // LINK_LIBRARY
//------------------------------------------------------------------------------
inline
error_info&
error_info::
gl_index(GLuint idx)
noexcept
{
#if !OGLPLUS_ERROR_NO_INDEX
	_index = idx;
#else
	(void)idx;
#endif
	return *this;
}
//------------------------------------------------------------------------------
inline
GLuint
error_info::
gl_index(void) const
noexcept
{
#if !OGLPLUS_ERROR_NO_INDEX
	return _index;
#else
	return invalid_index();
#endif
}
//------------------------------------------------------------------------------
inline
error_info&
error_info::
gl_enum_value(const any_enum_value& enum_val)
noexcept
{
#if !OGLPLUS_ERROR_NO_ENUM_VALUE
	_enum_val = enum_val;
#else
	(void)enum_val;
#endif
	return *this;
}
//------------------------------------------------------------------------------
#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
//------------------------------------------------------------------------------
inline
error_info&
error_info::
gl_enum_value(const any_indexed_enum_value& enum_val)
noexcept
{
#if !OGLPLUS_ERROR_NO_ENUM_VALUE
	_enum_val = indexed_value_base(enum_val.base());
#endif
#if !OGLPLUS_ERROR_NO_INDEX
	_index = GLuint(enum_val.index());
#endif
	(void)enum_val;
	return *this;
}
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
inline
const any_enum_value&
error_info::
gl_enum_value(void) const
noexcept
{
#if !OGLPLUS_ERROR_NO_ENUM_VALUE
	return _enum_val;
#else
	static any_enum_value enum_val;
	return enum_val;
#endif
}
//------------------------------------------------------------------------------
#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
error_info&
error_info::
identifier(const cstring_span<>& ident)
noexcept
{
#if !OGLPLUS_ERROR_NO_IDENTIFIER
	try { _ext_info()._identifier.assign(ident.begin(), ident.end()); }
	catch(...) { }
#else
	(void)ident;
#endif
	return *this;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstring_span<>
error_info::
identifier(void) const
noexcept
{
#if !OGLPLUS_ERROR_NO_IDENTIFIER
	return _ext_info()._identifier;
#else
	return {};
#endif
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
error_info&
error_info::
info_log(const cstring_span<>& log)
noexcept
{
#if !OGLPLUS_ERROR_NO_INFO_LOG
	try { _ext_info()._info_log.assign(log.begin(), log.end()); }
	catch(...) { }
#else
	(void)log;
#endif
	return *this;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
error_info&
error_info::
info_log_of(const any_object_name& obj)
noexcept
{
#if !OGLPLUS_ERROR_NO_INFO_LOG
	PFNGLGETPROGRAMIVPROC _GetObjectiv = nullptr;
	PFNGLGETPROGRAMINFOLOGPROC _GetObjectInfoLog = nullptr;

	if(obj._type == GL_SHADER)
	{
		_GetObjectiv = glGetShaderiv;
		_GetObjectInfoLog = glGetShaderInfoLog;
	}
	else if(obj._type == GL_PROGRAM)
	{
		_GetObjectiv = glGetProgramiv;
		_GetObjectInfoLog = glGetProgramInfoLog;
	}
	else if(obj._type == GL_PROGRAM_PIPELINE)
	{
		_GetObjectiv = glGetProgramPipelineiv;
		_GetObjectInfoLog = glGetProgramPipelineInfoLog;
	}

	if(_GetObjectiv && _GetObjectInfoLog)
	{
		GLint len = 0;
		_GetObjectiv(get_raw_name(obj), GL_INFO_LOG_LENGTH, &len);
		if(len > 0)
		{
			std::vector<GLchar> tmp(std::size_t(len+1), '\0');
			_GetObjectInfoLog(
				get_raw_name(obj),
				len,
				nullptr,
				tmp.data()
			);
			if(glGetError() == GL_NO_ERROR && tmp.front() != '\0')
			{
				info_log(tmp);
			}
		}
	}
#else
	(void)log;
#endif
	return *this;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstring_span<>
error_info::
info_log(void) const
noexcept
{
#if !OGLPLUS_ERROR_NO_INFO_LOG
	return {_ext_info()._info_log};
#else
	return {};
#endif
}
//------------------------------------------------------------------------------
#endif // LINK_LIBRARY
//------------------------------------------------------------------------------
} // namespace oglplus
