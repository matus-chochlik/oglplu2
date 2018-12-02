/**
 *  @file eagine/bindump.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/memory/address.hpp>
#include <cctype>
#include <iomanip>
#include <iostream>

namespace eagine {
//------------------------------------------------------------------------------
// bindump::_to_bin_b
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void bindump::_to_bin_b(std::ostream& out, byte b) {
    static const char bd[2] = {'0', '1'};
    for(unsigned o = 0; o < 4; ++o) {
        byte c = (b >> ((4 - o - 1) * 2));
        out << " " << bd[(c >> 1) & 0x01] << bd[c & 0x01];
    }
}
//------------------------------------------------------------------------------
// ostream << bindump
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::ostream& operator<<(std::ostream& out, const bindump& hd) {
    out << std::endl;

    const byte* bgn = hd._mb.begin();
    const byte* end = hd._mb.end();
    const byte* row = memory::align_down(bgn, 4);

    while(row < end) {
        const auto adr = hd._offs ? memory::const_address(row)
                                  : memory::const_address(row - bgn);
        out << std::setw(20) << std::setfill('.');
        out << (static_cast<const void*>(adr.ptr()));
        out << "|";

        const byte* pos = row;
        for(unsigned b = 0; b < 4; ++b) {
            if(b != 0) {
                out << " ";
            }

            if(pos < bgn || pos >= end) {
                for(unsigned p = 0; p < 4; ++p) {
                    out << " ..";
                }
            } else {
                bindump::_to_bin_b(out, *pos);
            }
            ++pos;
        }

        out << " |";

        pos = row;
        for(unsigned b = 0; b < 4; ++b) {
            if(b != 0) {
                out << " ";
            }

            if(pos < bgn || pos >= end || !std::isprint(*pos)) {
                out << ".";
            } else {
                out << char(*pos);
            }
            ++pos;
        }

        row += 4;

        out << "|" << std::endl;
    }

    return out;
}
//------------------------------------------------------------------------------
} // namespace eagine
