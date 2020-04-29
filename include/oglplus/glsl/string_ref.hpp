/**
 *  @file oglplus/glsl/string_ref.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GLSL_STRING_REF_HPP
#define OGLPLUS_GLSL_STRING_REF_HPP

#include "source_ref.hpp"
#include <eagine/memory/block.hpp>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
class glsl_string_ref {
private:
    using char_type = gl_types::char_type;
    using int_type = gl_types::int_type;

    mutable const char_type* _src_str{};
    int_type _length{};

public:
    glsl_string_ref(const char* src_str, span_size_t n) noexcept
      : _src_str(static_cast<const char_type*>(src_str))
      , _length(int_type(n == 0 ? 0 : (src_str[n - 1] == '\0' ? n - 1 : n))) {
    }

    explicit glsl_string_ref(string_view str) noexcept
      : glsl_string_ref(str.data(), str.size()) {
    }

    explicit glsl_string_ref(memory::const_block blk) noexcept
      : glsl_string_ref(as_chars(blk)) {
    }

    operator glsl_source_ref() const noexcept {
        return glsl_source_ref(1, &_src_str, &_length);
    }
};
//------------------------------------------------------------------------------
class glsl_literal : public glsl_string_ref {
public:
    template <span_size_t N>
    glsl_literal(const char (&src_str)[N]) noexcept
      : glsl_string_ref(static_cast<const char*>(src_str), N) {
    }
};
//------------------------------------------------------------------------------
static inline glsl_string_ref operator"" _glsl(
  const char* src_str, std::size_t n) noexcept {
    return {src_str, span_size(n)};
}
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GLSL_STRING_REF_HPP
