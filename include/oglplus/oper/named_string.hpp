/**
 *  @file oglplus/oper/named_string.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_NAMED_STRING_1509260923_HPP
#define OGLPLUS_OPER_NAMED_STRING_1509260923_HPP

#ifdef GL_ARB_shading_language_include
#include "../utils/gl_func.hpp"
#include "../utils/span.hpp"
#include "../utils/boolean.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"
#endif

namespace oglplus {
namespace oper {

struct named_string_state
{
#ifdef GL_ARB_shading_language_include
	static
	outcome<void>
	named_string(
		oglplus::named_string_type type,
		cstring_span name,
		cstring_span value
	) noexcept;

	static
	outcome<void>
	delete_named_string(cstring_span name)
	noexcept;

	static
	outcome<boolean>
	is_named_string(cstring_span name)
	noexcept;

	static
	outcome<void>
	get_named_string_iv(
		cstring_span name,
		named_string_param param,
		span<GLint> values
	) noexcept;

	static
	outcome<GLint>
	get_named_string_length(cstring_span name)
	noexcept;

	static
	outcome<named_string_type>
	get_named_string_type(cstring_span name)
	noexcept;

	static
	outcome<GLint>
	get_named_string(cstring_span name, span<GLchar> buf)
	noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/named_string.inl>

#endif // include guard
