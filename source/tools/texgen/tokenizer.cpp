/**
 *  @file texgen/tokenizer.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "tokenizer.hpp"
#include <cctype>

namespace oglplus {
namespace texgen {
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
                token.end(_input.location(i + 1));
                token.kind(token_kind::string);
                token.spelling(_input.head(i));
                _input.consume(i + 1);
                return true;
            }

            escape = (_input.peek(i) == '\\') && !escape;
            ++i;
        }
    } else if(_input.peek() == ';') {
        token.end(_input.location(1));
        token.kind(token_kind::semicolon);
        _input.consume();
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
