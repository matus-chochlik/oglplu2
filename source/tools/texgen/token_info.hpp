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

#include <oglplus/utils/string_span.hpp>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
enum class token_kind {
    keyword,
    equals,
    semicolon,
    number,
    identifier,
    unknown
};

string_view token_description(token_kind);
//------------------------------------------------------------------------------
class token_info {
public:
private:
    token_kind _kind{token_kind::unknown};
};
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus

#endif // TEXGEN_TOKEN_INFO_HPP
