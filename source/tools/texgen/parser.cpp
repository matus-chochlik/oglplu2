/**
 *  @file texgen/parser.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "parser.hpp"
#include "token_stream.hpp"

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
void parser::begin() {
    _actions.begin();
}
//------------------------------------------------------------------------------
static auto parse_render_expr(token_stream& tokens, semantic_actions&) -> bool {
    if(
      auto rndr_ident = tokens.follows(
        {token_kind::keyword_render,
         token_kind::left_paren,
         token_kind::identifier,
         token_kind::right_paren})) {
    }
    return false;
}
//------------------------------------------------------------------------------
static auto parse_statement(token_stream& tokens, semantic_actions& actions)
  -> bool {
    if(parse_render_expr(tokens, actions)) {
    }
    return false;
}
//------------------------------------------------------------------------------
void parser::parse(input_stream input) {
    token_stream tokens(std::move(input));
    while(true) {
        if(!parse_statement(tokens, _actions)) {
            break;
        }
    }
}
//------------------------------------------------------------------------------
void parser::finish() {
    _actions.finish();
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
