/**
 *  @file oglplus/oper/internal_format_queries.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_INTERNAL_FORMAT_QUERIES_1509260923_HPP
#define OGLPLUS_OPER_INTERNAL_FORMAT_QUERIES_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../utils/span.hpp"
#include "../utils/boolean.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

struct internal_format_queries
{
#if defined(GL_VERSION_4_2)
	static
	outcome<void>
	get_internal_format_iv(
		internal_format_target target,
		pixel_data_internal_format iformat,
		internal_format_parameter param,
		span<GLint> data
	) noexcept;
#endif

#if defined(GL_VERSION_4_3)
	static
	outcome<void>
	get_internal_format_i64v(
		internal_format_target target,
		pixel_data_internal_format iformat,
		internal_format_parameter param,
		span<GLint64> data
	) noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/internal_format_queries.inl>

#endif // include guard
