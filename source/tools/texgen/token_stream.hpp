/**
 *  @file texgen/token_stream.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEXGEN_TOKEN_STREAM_HPP // NOLINT(llvm-header-guard)
#define TEXGEN_TOKEN_STREAM_HPP

#include "tokenizer.hpp"
#include <eagine/memory/span_algo.hpp>
#include <eagine/valid_if/decl.hpp>
#include <vector>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
class token_stream {
public:
    token_stream(input_stream input)
      : _tokenizer(std::move(input)) {}

    auto head(span_size_t length = 1) -> span<const token_info> {
        _ensure_cached(length);
        return memory::head(view(_tokens), length);
    }

    auto consume(span_size_t length = 1) -> bool;

    auto follows(span<const token_kind> kinds) -> span<const token_info> {
        const auto h = head(kinds.size());
        if(are_equal(h, kinds)) {
            return h;
        }
        return {};
    }

    auto follows(std::initializer_list<token_kind> kinds)
      -> span<const token_info> {
        return follows(view(kinds));
    }

    auto follows(token_kind kind) -> span<const token_info> {
        return follows(view_one(kind));
    }

private:
    auto _ensure_cached(span_size_t count) -> bool;

    tokenizer _tokenizer;
    std::vector<token_info> _tokens;
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen

#endif // TEXGEN_TOKEN_STREAM_HPP
