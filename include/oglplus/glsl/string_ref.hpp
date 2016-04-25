/**
 *  @file oglplus/glsl/source_ref.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GLSL_STRING_REF_1509260923_HPP
#define OGLPLUS_GLSL_STRING_REF_1509260923_HPP

#include "source_ref.hpp"

namespace oglplus {

class glsl_string_ref
{
private:
	mutable const GLchar* _src_str;
	GLint _length;
public:
	glsl_string_ref(const char* src_str, std::size_t n)
	noexcept
	 : _src_str(static_cast<const GLchar*>(src_str))
	 , _length(GLint(n==0?0:(src_str[n-1]=='\0'?n-1:n)))
	{ }

	template <typename String>
	explicit
	glsl_string_ref(const String& str)
	noexcept
	 : glsl_string_ref(str.data(), std::size_t(str.size()))
	{ }

	operator glsl_source_ref (void) const
	noexcept
	{
		return glsl_source_ref(1, &_src_str, &_length);
	}
};

class glsl_literal
 : public glsl_string_ref
{
public:
	template <std::size_t N>
	glsl_literal(const char (&src_str)[N])
	noexcept
	 : glsl_string_ref(src_str, N)
	{ }
};

static inline
glsl_string_ref operator "" _glsl(const char* src_str, std::size_t n)
noexcept
{
	return {src_str, n};
}

} // namespace oglplus

#endif // include guard
