/**
 *  @file texgen/token_stream.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "token_stream.hpp"

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
bool token_stream::_ensure_cached(span_size_t count) {
    while(span_size(_tokens.size()) < count) {
        token_info token{};
        if(_tokenizer.get_next(token)) {
            _tokens.emplace_back(std::move(token));
        } else {
            break;
        }
    }
    return span_size(_tokens.size()) >= count;
}
//------------------------------------------------------------------------------
bool token_stream::consume(span_size_t length) {
    if(_ensure_cached(length)) {
        _tokens.erase(_tokens.begin(), _tokens.begin() + length);
        return true;
    }
    _tokens.clear();
    return false;
}
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen
