/**
 *  @file oglplus/error/info.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ERROR_INFO_1509260923_HPP
#define OGLPLUS_ERROR_INFO_1509260923_HPP

#include "../object/fwd.hpp"

namespace oglplus {

class error_info
{
private:
	GLenum _gl_err_code;

	const char* _gl_lb_name;
	const char* _gl_fn_name;
	const char* _src_file;
	unsigned _src_line;

	GLuint _obj_name;
	GLuint _sub_name;
public:
	constexpr
	error_info(GLenum gl_err_code)
	noexcept
	 : _gl_err_code(gl_err_code)
	 , _gl_lb_name("")
	 , _gl_fn_name("")
	 , _src_file("")
	 , _src_line(0)
	 , _obj_name(~GLuint(0))
	 , _sub_name(~GLuint(0))
	{ }

	constexpr
	error_info(void)
	noexcept
	 : error_info(GLenum(GL_NO_ERROR))
	{ }

	error_info& no_info(void)
	noexcept
	{
		return *this;
	}

	error_info& gl_error_code(GLenum gl_err_code)
	noexcept
	{
		_gl_err_code = gl_err_code;
		return *this;
	}

	GLenum gl_error_code(void) const
	noexcept
	{
		return _gl_err_code;
	}

	error_info& gl_library_name(const char* gl_lb_name)
	noexcept
	{
		_gl_lb_name = gl_lb_name;
		return *this;
	}

	const char* gl_library_name(void) const
	noexcept
	{
		return _gl_lb_name;
	}

	error_info& gl_function_name(const char* gl_fn_name)
	noexcept
	{
		_gl_fn_name = gl_fn_name;
		return *this;
	}

	const char* gl_function_name(void) const
	noexcept
	{
		return _gl_fn_name;
	}

	error_info& source_file(const char* src_file)
	noexcept
	{
		_src_file = src_file;
		return *this;
	}

	const char* source_file(void) const
	noexcept
	{
		return _src_file;
	}

	error_info& source_line(unsigned src_line)
	noexcept
	{
		_src_line = src_line;
		return *this;
	}

	unsigned source_line(void) const
	noexcept
	{
		return _src_line;
	}

	error_info& object_name(GLuint obj_name)
	noexcept
	{
		_obj_name = obj_name;
		return *this;
	}

	template <typename ObjTag, typename Storage>
	error_info& object(const object_names<ObjTag, Storage>& obj)
	noexcept
	{
		return object_name(get_raw_name(obj));
	}

	GLuint object_name(void) const
	noexcept
	{
		return _obj_name;
	}

	error_info& subject_name(GLuint sub_name)
	noexcept
	{
		_sub_name = sub_name;
		return *this;
	}

	template <typename ObjTag, typename Storage>
	error_info& subject(const object_names<ObjTag, Storage>& sub)
	noexcept
	{
		return subject_name(get_raw_name(sub));
	}

	GLuint subject_name(void) const
	noexcept
	{
		return _sub_name;
	}
};

} // namespace oglplus

#endif // include guard
