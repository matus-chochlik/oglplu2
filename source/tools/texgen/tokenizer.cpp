/**
 *  @file texgen/tokenizer.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "tokenizer.hpp"
#include <eagine/memory/span_algo.hpp>
#include <cctype>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
tokenizer::tokenizer(input_stream input)
  : _input(std::move(input))
  , _ident_re(R"(^[_[:alpha:]][_[:alnum:]]*\b)")
  , _integer_re(
      R"(((0x[[:xdigit:]]+)|(0b[01]+)|([01234567]+)|(-?[1-9][[:digit:]]*)|0)\b)")
  , _float_re(R"(^-?[[:digit:]]+(\.[[:digit:]]+)\b)") {
}
//------------------------------------------------------------------------------
static inline bool is_word_boundary(char c) noexcept {

    return (c == char(0)) || std::isspace(c) ||
           memory::find_element(string_view(".,=(){};"), c);
}
//------------------------------------------------------------------------------
bool tokenizer::_match_char(token_info& token, char chr, token_kind kind) {

    if(_input.peek() == chr) {
        token.end(_input.location(1));
        token.kind(kind);
        _input.consume();
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
bool tokenizer::_match_str(
  token_info& token, string_view str, token_kind kind) {

    const auto len = str.size();
    if(are_equal(_input.head(len), str) && is_word_boundary(_input.peek(len))) {
        token.end(_input.location(len));
        token.kind(kind);
        return _input.consume(len);
    }

    return false;
}
//------------------------------------------------------------------------------
bool tokenizer::_match_re(
  token_info& token, const std::regex& re, token_kind kind) {

    std::match_results<
      input_stream::const_iterator,
      std::allocator<std::sub_match<input_stream::const_iterator>>>
      res;

    if(std::regex_search(_input.begin(), _input.end(), res, re)) {
        const auto len = span_size(res.length(0));
        token.end(_input.location(len));
        token.kind(kind);
        token.spelling(res.str(0));
        return _input.consume(len);
    }
    return false;
}
//------------------------------------------------------------------------------
bool tokenizer::get_next(token_info& token) {
    // eat spaces
    while(const char c = _input.peek()) {
        if(std::isspace(c)) {
            _input.consume();
        } else {
            break;
        }
    }

    token.begin(_input.location());

    // string literal
    if(_input.peek() == '"') {
        span_size_t i = 1;
        bool escape = false;
        while(true) {
            const char c = _input.peek(i);
            if(!c) {
                token.end(_input.location(i));
                token.kind(token_kind::unterminated_string);
                token.spelling(_input.head(i - 1));
                _input.consume(i);
                return true;
            }
            if((c == '"') && !escape) {
                const auto len = i + 1;
                token.end(_input.location(len));
                token.kind(token_kind::string);
                token.spelling(_input.head(len));
                _input.consume(len);
                return true;
            }

            escape = (_input.peek(i) == '\\') && !escape;
            ++i;
        }
    } else if(_match_char(token, '.', token_kind::dot)) {
        return true;
    } else if(_match_char(token, ',', token_kind::comma)) {
        return true;
    } else if(_match_char(token, '(', token_kind::left_paren)) {
        return true;
    } else if(_match_char(token, '[', token_kind::right_bracket)) {
        return true;
    } else if(_match_char(token, ']', token_kind::left_bracket)) {
        return true;
    } else if(_match_char(token, ')', token_kind::right_paren)) {
        return true;
    } else if(_match_char(token, '{', token_kind::left_brace)) {
        return true;
    } else if(_match_char(token, '}', token_kind::right_brace)) {
        return true;
    } else if(_match_char(token, '=', token_kind::equals)) {
        return true;
    } else if(_match_char(token, ';', token_kind::semicolon)) {
        return true;
    } else if(_match_str(token, "~>", token_kind::connect_l2r)) {
        return true;
    } else if(_match_str(token, "->", token_kind::connect_l2r)) {
        return true;
    } else if(_match_str(token, "<~", token_kind::connect_r2l)) {
        return true;
    } else if(_match_str(token, "<-", token_kind::connect_r2l)) {
        return true;
    } else if(_match_str(token, "render", token_kind::keyword_render)) {
        return true;
    } else if(_match_re(token, _ident_re, token_kind::identifier)) {
        return true;
    } else if(_match_re(token, _float_re, token_kind::float_literal)) {
        return true;
    } else if(_match_re(token, _integer_re, token_kind::integer_literal)) {
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
