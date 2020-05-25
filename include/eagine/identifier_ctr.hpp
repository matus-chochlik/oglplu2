/**
 *  @file eagine/identifier_ctr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_IDENTIFIER_CTR_HPP
#define EAGINE_IDENTIFIER_CTR_HPP

#include "identifier.hpp"
#include "types.hpp"

namespace eagine {
//------------------------------------------------------------------------------
static inline auto byte_to_identifier(byte b) noexcept {
    static const char hd[16] = {'0',
                                '1',
                                '2',
                                '3',
                                '4',
                                '5',
                                '6',
                                '7',
                                '8',
                                '9',
                                'a',
                                'b',
                                'c',
                                'd',
                                'e',
                                'f'};
    const char src[5] = {
      '0', 'x', hd[std_size((b >> 4) & 0xFU)], hd[std_size(b & 0xFU)], '\0'};
    return identifier{src};
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_IDENTIFIER_T_HPP
