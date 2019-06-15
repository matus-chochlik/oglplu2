/**
 *  @file texgen/token_stream.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEXGEN_TOKEN_STREAM_HPP
#define TEXGEN_TOKEN_STREAM_HPP

#include "tokenizer.hpp"
#include <vector>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
class token_stream {
public:
    token_stream(tokenizer a_tokenizer)
      : _tokenizer(std::move(a_tokenizer)) {
    }

    bool empty() noexcept {
        return _tokens.empty();
    }

    explicit operator bool() noexcept {
        return !empty();
    }

    bool operator!() noexcept {
        return empty();
    }

private:
    tokenizer _tokenizer;
    std::vector<token_info> _tokens;
};
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus

#endif // TEXGEN_TOKEN_STREAM_HPP
