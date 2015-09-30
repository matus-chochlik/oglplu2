/**
 *  @file oglplus/error/handling.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ERROR_HANDLING_1509260923_HPP
#define OGLPLUS_ERROR_HANDLING_1509260923_HPP

#include "info.hpp"
#include "../utils/deferred_handler.hpp"
#include <stdexcept>

namespace oglplus {

class error
 : public std::runtime_error
{
private:
	error_info _info;

	static
	std::string _make_msg(error_info& info);
public:
	error(error_info&& info);

	const error_info& info(void) const
	noexcept
	{
		return _info;
	}
};

template <typename ErrorInfo>
[[noreturn]]
static inline
void handle_gl_error(ErrorInfo& info)
{
	throw error(std::move(info));
}

static inline constexpr
bool is_gl_error(GLenum ec)
noexcept
{
	return ec != GL_NO_ERROR;
}

using deferred_error_handler = deferred_handler<error_info>;

} // namespace oglplus

#include <oglplus/error/handling.inl>

#define OGLPLUS_RETURN_HANDLER_IF(\
	CONDITION,\
	ERROR_CODE,\
	ERROR_INFO,\
	SEVERITY\
)\
{\
	GLenum oglplus_error_code##__LINE__ = ERROR_CODE;\
	if(CONDITION(oglplus_error_code##__LINE__))\
	{\
		return oglplus::make_deferred_handler(\
			&oglplus::handle_gl_error,\
			oglplus::error_info(oglplus_error_code##__LINE__)\
				.ERROR_INFO\
				.source_file(__FILE__)\
				.source_line(__LINE__)\
		);\
	}\
}

#define OGLPLUS_RETURN_HANDLER_IF_GL_ERROR(\
	ERROR_CODE,\
	ERROR_INFO,\
	SEVERITY\
) OGLPLUS_RETURN_HANDLER_IF(\
	oglplus::is_gl_error,\
	ERROR_CODE,\
	ERROR_INFO,\
	SEVERITY\
)

#define OGLPLUS_VERIFY(\
	GLFUNC,\
	ERROR_INFO,\
	SEVERITY\
) OGLPLUS_RETURN_HANDLER_IF_GL_ERROR(\
	::glGetError(),\
	ERROR_INFO.gl_function_name(#GLFUNC),\
	SEVERITY\
)

#define OGLPLUS_VERIFY_SIMPLE(GLFUNC, SEVERITY)\
	OGLPLUS_VERIFY(GLFUNC, no_info(), SEVERITY)

#endif // include guard
