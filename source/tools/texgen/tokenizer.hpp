/**
 *  @file texgen/tokenizer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEXGEN_TOKENIZER_HPP // NOLINT(llvm-header-guard)
#define TEXGEN_TOKENIZER_HPP

#include "input_stream.hpp"
#include "token_info.hpp"
#include <regex>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
class tokenizer {
public:
    tokenizer(input_stream input);

    auto get_next(token_info&) -> bool;

private:
    auto _match_char(token_info&, char chr, token_kind) -> bool;
    auto _match_str(token_info&, string_view str, token_kind) -> bool;
    auto _match_re(token_info&, const std::regex&, token_kind) -> bool;

    input_stream _input;

    std::regex _ident_re;
    std::regex _integer_re;
    std::regex _float_re;
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen

#endif // TEXGEN_TOKENIZER_HPP
