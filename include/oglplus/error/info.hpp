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
#include "../config/error.hpp"

namespace oglplus {

class error_info
{
private:
	GLenum _gl_err_code;

#if! OGLPLUS_ERROR_NO_GL_LIB
	const char* _gl_lb_name;
#endif

#if! OGLPLUS_ERROR_NO_GL_FUNC
	const char* _gl_fn_name;
#endif

#if! OGLPLUS_ERROR_NO_SRC_FUNC
	const char* _src_func;
#endif

#if! OGLPLUS_ERROR_NO_SRC_FILE
	const char* _src_file;
#endif

#if! OGLPLUS_ERROR_NO_SRC_LINE
	unsigned _src_line;
#endif

#if !OGLPLUS_ERROR_NO_OBJ_NAME
	GLuint _obj_name;
#endif

#if !OGLPLUS_ERROR_NO_SUB_NAME
	GLuint _sub_name;
#endif
public:
	static constexpr
	GLuint invalid_gl_obj_name(void)
	noexcept;

	constexpr
	error_info(GLenum gl_err_code)
	noexcept;

	constexpr
	error_info(void)
	noexcept
	 : error_info(GLenum(GL_NONE))
	{ }

	constexpr
	error_info& no_info(void)
	noexcept
	{
		return *this;
	}

	error_info& gl_error_code(GLenum gl_err_code)
	noexcept;

	GLenum gl_error_code(void) const
	noexcept;

	error_info& gl_library_name(const char* gl_lb_name)
	noexcept;

	const char* gl_library_name(void) const
	noexcept;

	error_info& gl_function_name(const char* gl_fn_name)
	noexcept;

	const char* gl_function_name(void) const
	noexcept;

	error_info& source_function(const char* src_func)
	noexcept;

	const char* source_function(void) const
	noexcept;

	error_info& source_file(const char* src_file)
	noexcept;

	const char* source_file(void) const
	noexcept;

	error_info& source_line(unsigned src_line)
	noexcept;

	unsigned source_line(void) const
	noexcept;

	error_info& gl_object_name(GLuint obj_name)
	noexcept;

	template <typename ObjTag>
	error_info& gl_object(const object_names<ObjTag, GLuint>& obj)
	noexcept;

	GLuint gl_object_name(void) const
	noexcept;

	error_info& gl_subject_name(GLuint sub_name)
	noexcept;

	template <typename ObjTag>
	error_info& gl_subject(const object_names<ObjTag, GLuint>& sub)
	noexcept;

	GLuint gl_subject_name(void) const
	noexcept;
};

} // namespace oglplus

#include <oglplus/error/info.inl>

#endif // include guard
