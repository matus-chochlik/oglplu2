/// @file texgen/token_info.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include "token_info.hpp"

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
auto token_description(token_kind kind) -> string_view {
    switch(kind) {
        case token_kind::comment:
            return {"comment"};
        case token_kind::keyword_render:
            return {"'render' keyword"};
        case token_kind::dot:
            return {"dot operator"};
        case token_kind::comma:
            return {"comma"};
        case token_kind::left_paren:
            return {"left parenthesis"};
        case token_kind::right_paren:
            return {"right parenthesis"};
        case token_kind::left_brace:
            return {"left brace"};
        case token_kind::right_brace:
            return {"right brace"};
        case token_kind::left_bracket:
            return {"left bracket"};
        case token_kind::right_bracket:
            return {"right bracket"};
        case token_kind::equals:
            return {"equals sign"};
        case token_kind::connect_l2r:
            return {"connect left-to-right operator"};
        case token_kind::connect_r2l:
            return {"connect right-to-leftoperator"};
        case token_kind::semicolon:
            return {"semicolon"};
        case token_kind::integer_literal:
            return {"integer literal"};
        case token_kind::float_literal:
            return {"floating-point literal"};
        case token_kind::string:
            return {"string literal"};
        case token_kind::unterminated_string:
            return {"unterminated string literal"};
        case token_kind::identifier:
            return {"identifier"};
        case token_kind::unknown:
            return {"unknown token"};
    }
    return {};
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
