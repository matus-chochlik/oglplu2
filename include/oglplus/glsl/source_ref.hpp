/**
 *  @file oglplus/glsl/source_ref.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GLSL_SOURCE_REF_1509260923_HPP
#define OGLPLUS_GLSL_SOURCE_REF_1509260923_HPP

#include <cassert>
#include <cstddef>
#include "../utils/types.hpp"

namespace oglplus {

class glsl_source_ref {
private:
    GLsizei _count;
    const GLchar** _parts;
    const GLint* _lengths;

public:
    glsl_source_ref(span_size_t n, const GLchar** ps, const GLint* ls) noexcept
      : _count(GLsizei(n))
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

} // namespace oglplus

#endif // include guard
