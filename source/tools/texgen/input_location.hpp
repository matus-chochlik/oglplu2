/**
 *  @file texgen/input_location.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEXGEN_INPUT_LOCATION_HPP
#define TEXGEN_INPUT_LOCATION_HPP

#include <eagine/types.hpp>

namespace eagine {
namespace oglp {
namespace texgen {
//------------------------------------------------------------------------------
class input_location {
public:
    input_location() noexcept = default;
    input_location(span_size_t line, span_size_t column) noexcept
      : _line{line}
      , _column{column} {
    }

    span_size_t line() const noexcept {
        return _line;
    }

    span_size_t column() const noexcept {
        return _column;
    }

    friend input_location operator+(const input_location& l, char c) noexcept {
        if(c == '\n') {
            return {l.line() + 1, 0};
        }
        return {l.line(), l.column() + 1};
    }

private:
    span_size_t _line{0};
    span_size_t _column{0};
};
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglp
} // namespace eagine

#endif // TEXGEN_INPUT_LOCATION_HPP
