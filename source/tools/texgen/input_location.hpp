/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef TEXGEN_INPUT_LOCATION_HPP // NOLINT(llvm-header-guard)
#define TEXGEN_INPUT_LOCATION_HPP

#include <eagine/types.hpp>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
class input_location {
public:
    input_location() noexcept = default;
    input_location(span_size_t line, span_size_t column) noexcept
      : _line{line}
      , _column{column} {}

    auto line() const noexcept -> span_size_t {
        return _line;
    }

    auto column() const noexcept -> span_size_t {
        return _column;
    }

    friend auto operator+(const input_location& l, char c) noexcept
      -> input_location {
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
} // namespace eagine::oglp::texgen

#endif // TEXGEN_INPUT_LOCATION_HPP
