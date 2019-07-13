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
#include <eagine/memory/span_algo.hpp>
#include <eagine/valid_if/decl.hpp>
#include <vector>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
class token_stream {
public:
    token_stream(input_stream input)
      : _tokenizer(std::move(input)) {
    }

    span<const token_info> head(span_size_t length = 1) {
        _ensure_cached(length);
        return eagine::memory::head(view(_tokens), length);
    }

    bool consume(span_size_t length = 1);

    span<const token_info> follows(span<const token_kind> kinds) {
        const auto h = head(kinds.size());
        if(eagine::are_equal(h, kinds)) {
            return h;
        }
        return {};
    }

    span<const token_info> follows(std::initializer_list<token_kind> kinds) {
        return follows(view(kinds));
    }

    span<const token_info> follows(token_kind kind) {
        return follows(eagine::view_one(kind));
    }

private:
    bool _ensure_cached(span_size_t count);

    tokenizer _tokenizer;
    std::vector<token_info> _tokens;
};
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus

#endif // TEXGEN_TOKEN_STREAM_HPP
