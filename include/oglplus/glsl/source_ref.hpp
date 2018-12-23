/**
 *  @file oglplus/glsl/source_ref.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GLSL_SOURCE_REF_HPP
#define OGLPLUS_GLSL_SOURCE_REF_HPP

#include "../utils/string_span.hpp"
#include "../utils/types.hpp"
#include <cassert>
#include <cstddef>

namespace oglplus {
//------------------------------------------------------------------------------
class glsl_source_ref {
private:
    const GLchar* _part = nullptr;
    const GLint _length = 0;
    GLsizei _count = 0;
    const GLchar** _parts = nullptr;
    const GLint* _lengths = nullptr;

public:
    constexpr glsl_source_ref(const GLchar* part, GLint length) noexcept
      : _part{part}
      , _length{length}
      , _count{1}
      , _parts{&_part}
      , _lengths{&_length} {
    }

    constexpr glsl_source_ref(string_view source_str) noexcept
      : glsl_source_ref(
          accomodate<const GLchar>(source_str).data(),
          eagine::limit_cast<GLint>(source_str.size())) {
    }

    glsl_source_ref(span_size_t n, const GLchar** ps, const GLint* ls) noexcept
      : _count(eagine::limit_cast<GLsizei>(n))
      , _parts(ps)
      , _lengths(ls) {
        assert(_count >= 0);
        assert(_parts != nullptr);
    }

    inline GLsizei count() const noexcept {
        return _count;
    }

    inline const GLchar** parts() const noexcept {
        return _parts;
    }

    inline const GLint* lengths() const noexcept {
        return _lengths;
    }
};
//------------------------------------------------------------------------------
} // namespace oglplus

#endif // OGLPLUS_GLSL_SOURCE_REF_HPP
