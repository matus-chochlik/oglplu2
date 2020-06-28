/**
 *  @file eagine/identifier_ctr.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
identifier byte_to_identifier(byte b) noexcept {
    // clang-format off
    static const char hd[16] = {
		'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    // clang-format on
    const char src[5] = {
      '0',
      'x',
      hd[std_size((b >> 4) & 0xFU)], // NOLINT(hicpp-signed-bitwise)
      hd[std_size(b & 0xFU)],        // NOLINT(hicpp-signed-bitwise)
      '\0'};
    return identifier{src};
}
//------------------------------------------------------------------------------
template <std::size_t L>
static identifier _ident_dec_to_str(int i, char (&tmp)[L]) noexcept {
    tmp[L - 1] = '\0';
    std::size_t l = L - 1;
    while(l-- > 0) {
        tmp[l] = char(i % 10 + '0');
        i /= 10;
    }
    return identifier{tmp};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
identifier dec_to_identifier(int i) noexcept {
    EAGINE_ASSERT(i >= 0);
    if(i < 10) {
        char tmp[2];
        return _ident_dec_to_str(i, tmp);
    }
    if(i < 100) {
        char tmp[3];
        return _ident_dec_to_str(i, tmp);
    }
    if(i < 1000) {
        char tmp[4];
        return _ident_dec_to_str(i, tmp);
    }
    if(i < 10000) {
        char tmp[5];
        return _ident_dec_to_str(i, tmp);
    }
    if(i < 100000) {
        char tmp[6];
        return _ident_dec_to_str(i, tmp);
    }
    if(i < 1000000) {
        char tmp[7];
        return _ident_dec_to_str(i, tmp);
    }
    if(i < 10000000) {
        char tmp[8];
        return _ident_dec_to_str(i, tmp);
    }
    if(i < 100000000) {
        char tmp[9];
        return _ident_dec_to_str(i, tmp);
    }
    if(i < 1000000000) {
        char tmp[10];
        return _ident_dec_to_str(i, tmp);
    }
    char tmp[11];
    return _ident_dec_to_str(i, tmp);
}
//------------------------------------------------------------------------------
} // namespace eagine
