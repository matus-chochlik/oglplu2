/**
 *  @file texgen/token_info.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEXGEN_TOKEN_INFO_HPP
#define TEXGEN_TOKEN_INFO_HPP

#include "input_location.hpp"
#include <oglplus/utils/string_span.hpp>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
enum class token_kind {
    comment,
    keyword,
    equals,
    semicolon,
    number,
    string,
    unterminated_string,
    identifier,
    unknown
};
//------------------------------------------------------------------------------
string_view token_description(token_kind);
//------------------------------------------------------------------------------
class token_info {
public:
    token_info& clear() {
        _kind = token_kind::unknown;
        _bgn_loc = {};
        _end_loc = {};
        _spelling.clear();
        return *this;
    }

    token_info& kind(token_kind k) noexcept {
        _kind = k;
        return *this;
    }

    token_kind kind() const noexcept {
        return _kind;
    }

    token_info& begin(input_location loc) {
        _bgn_loc = std::move(loc);
        return *this;
    }

    token_info& end(input_location loc) {
        _end_loc = std::move(loc);
        return *this;
    }

    token_info& spelling(string_view str) {
        _spelling = to_string(str);
        return *this;
    }

    string_view spelling() const noexcept {
        return {_spelling};
    }

    string_view description() const noexcept {
        return token_description(_kind);
    }

private:
    token_kind _kind{token_kind::unknown};
    input_location _bgn_loc{};
    input_location _end_loc{};
    std::string _spelling;
};
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus

#endif // TEXGEN_TOKEN_INFO_HPP
