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
		named_string_type type,
		cstring_span<> name,
		cstring_span<> value
	) noexcept
	{
		OGLPLUS_GLFUNC(NamedStringARB)(
			GLenum(type),
			GLint(name.size()),
			name.data(),
			GLint(value.size()),
			value.data()
		);
		OGLPLUS_VERIFY_SIMPLE(NamedStringARB,always);
		return {};
	}

	static
	outcome<void>
	delete_named_string(cstring_span<> name)
	noexcept
	{
		OGLPLUS_GLFUNC(DeleteNamedStringARB)(
			GLint(name.size()),
			name.data()
		);
		OGLPLUS_VERIFY_SIMPLE(DeleteNamedStringARB,always);
		return {};
	}

	static
	outcome<boolean>
	is_named_string(cstring_span<> name)
	noexcept
	{
		GLboolean result = OGLPLUS_GLFUNC(IsNamedStringARB)(
			GLint(name.size()),
			name.data()
		);
		OGLPLUS_VERIFY_SIMPLE(IsNamedStringARB,always);
		return {boolean(result)};
	}

	static
	outcome<void>
	get_named_string_iv(
		cstring_span<> name,
		named_string_param param,
		span<GLint> values
	) noexcept
	{
		assert(values.size() > 0);
		OGLPLUS_GLFUNC(GetNamedStringivARB)(
			GLint(name.size()),
			name.data(),
			GLenum(param),
			values.data()
		);
		OGLPLUS_VERIFY_SIMPLE(GetNamedStringivARB,always);
		return {};
	}

	static
	outcome<GLint>
	named_string_length(cstring_span<> name)
	noexcept
	{
		GLint result = 0;
		return get_named_string_iv(
			name,
			named_string_param(GL_NAMED_STRING_LENGTH_ARB),
			{&result, 1}
		), result;
	}

	static
	outcome<named_string_type>
	named_string_type(cstring_span<> name)
	noexcept
	{
		GLint result = 0;
		return get_named_string_iv(
			name,
			named_string_param(GL_NAMED_STRING_TYPE_ARB),
			{&result, 1}
		), oglplus::named_string_type(GLenum(result));
	}

	static
	outcome<GLint>
	get_named_string(cstring_span<> name, span<GLchar> buf)
	noexcept
	{
		GLint reallen = 0;
		OGLPLUS_GLFUNC(GetNamedStringARB)(
			GLint(name.size()),
			name.data(),
			GLsizei(buf.size()),
			&reallen,
			buf.data()
		);
		OGLPLUS_VERIFY_SIMPLE(GetNamedStringARB,always);
		return {reallen};
	}
#endif
};

} // namespace oper
} // namespace oglplus

#endif // include guard
