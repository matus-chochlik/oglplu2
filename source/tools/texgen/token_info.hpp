/**
 *  @file texgen/token_info.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEXGEN_TOKEN_INFO_HPP // NOLINT(llvm-header-guard)
#define TEXGEN_TOKEN_INFO_HPP

#include "input_location.hpp"
#include <eagine/compare.hpp>
#include <eagine/string_span.hpp>

namespace eagine {
namespace oglp::texgen {
//------------------------------------------------------------------------------
enum class token_kind {
    comment,
    keyword_render,
    dot,
    comma,
    left_paren,
    right_paren,
    left_bracket,
    right_bracket,
    left_brace,
    right_brace,
    equals,
    connect_l2r,
    connect_r2l,
    semicolon,
    integer_literal,
    float_literal,
    string,
    unterminated_string,
    identifier,
    unknown
};
//------------------------------------------------------------------------------
auto token_description(token_kind) -> string_view;
//------------------------------------------------------------------------------
class token_info {
public:
    auto clear() -> auto& {
        _kind = token_kind::unknown;
        _bgn_loc = {};
        _end_loc = {};
        _spelling.clear();
        return *this;
    }

    auto kind(token_kind k) noexcept -> auto& {
        _kind = k;
        return *this;
    }

    auto kind() const noexcept -> token_kind {
        return _kind;
    }

    auto begin(input_location loc) -> auto& {
        _bgn_loc = loc;
        return *this;
    }

    auto end(input_location loc) -> auto& {
        _end_loc = loc;
        return *this;
    }

    auto spelling(string_view str) -> auto& {
        _spelling = to_string(str);
        return *this;
    }

    auto spelling() const noexcept -> string_view {
        return {_spelling};
    }

    auto description() const noexcept -> string_view {
        return token_description(_kind);
    }

private:
    token_kind _kind{token_kind::unknown};
    input_location _bgn_loc{};
    input_location _end_loc{};
    std::string _spelling;
};
//------------------------------------------------------------------------------
} // namespace oglp::texgen
//------------------------------------------------------------------------------
template <>
struct equal_cmp<oglp::texgen::token_kind, oglp::texgen::token_info> {
    static inline auto check(
      oglp::texgen::token_kind kind,
      const oglp::texgen::token_info& info) noexcept {
        return kind == info.kind();
    }
};
//------------------------------------------------------------------------------
template <>
struct equal_cmp<oglp::texgen::token_info, oglp::texgen::token_kind> {
    static inline auto check(
      const oglp::texgen::token_info& info,
      oglp::texgen::token_kind kind) noexcept {
        return info.kind() == kind;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine
//------------------------------------------------------------------------------

#endif // TEXGEN_TOKEN_INFO_HPP
