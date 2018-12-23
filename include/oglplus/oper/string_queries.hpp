/**
 *  @file oglplus/oper/string_queries.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_STRING_QUERIES_HPP
#define OGLPLUS_OPER_STRING_QUERIES_HPP

#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/gl_func.hpp"
#include "../utils/string_span.hpp"

namespace oglplus {
namespace oper {

struct string_queries {
    static outcome<string_view> get_string(string_query query) noexcept;

    static outcome<string_view> get_string(
      string_query query, GLuint index) noexcept;

    static outcome<string_view> get_extension_name(GLuint index) noexcept;
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/string_queries.inl>

#endif // OGLPLUS_OPER_STRING_QUERIES_HPP
