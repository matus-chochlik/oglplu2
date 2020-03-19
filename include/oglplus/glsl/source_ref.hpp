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

#include "../gl_api/config.hpp"
#include <eagine/assert.hpp>
#include <eagine/string_span.hpp>
#include <cstddef>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
class glsl_source_ref {
private:
    using char_type = gl_types::char_type;
    using int_type = gl_types::int_type;
    using sizei_type = gl_types::sizei_type;

    const char_type* _part = nullptr;
    const int_type _length = 0;
    sizei_type _count = 0;
    const char_type** _parts = nullptr;
    const int_type* _lengths = nullptr;

public:
    constexpr glsl_source_ref(const char_type* part, int_type length) noexcept
      : _part{part}
      , _length{length}
      , _count{1}
      , _parts{&_part}
      , _lengths{&_length} {
    }

    constexpr glsl_source_ref(string_view source_str) noexcept
      : glsl_source_ref(
          memory::accomodate<const char_type>(source_str).data(),
          eagine::limit_cast<int_type>(source_str.size())) {
    }

    glsl_source_ref(
      span_size_t n, const char_type** ps, const int_type* ls) noexcept
      : _count(eagine::limit_cast<sizei_type>(n))
      , _parts(ps)
      , _lengths(ls) {
        EAGINE_ASSERT(_count >= 0);
        EAGINE_ASSERT(_parts != nullptr);
    }

    inline sizei_type count() const noexcept {
        return _count;
    }

    inline const char_type** parts() const noexcept {
        return _parts;
    }

    inline const int_type* lengths() const noexcept {
        return _lengths;
    }
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GLSL_SOURCE_REF_HPP
