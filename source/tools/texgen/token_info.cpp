/**
 *  @file texgen/token_info.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "token_info.hpp"

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
string_view token_description(token_kind kind) {
    switch(kind) {
        case token_kind::comment:
            return {"comment"};
        case token_kind::keyword:
            return {"keyword"};
        case token_kind::left_paren:
            return {"left parenthesis"};
        case token_kind::right_paren:
            return {"right parenthesis"};
        case token_kind::equals:
            return {"equals sign"};
        case token_kind::semicolon:
            return {"semicolon"};
        case token_kind::number:
            return {"numeric literal"};
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
} // namespace texgen
} // namespace oglplus
