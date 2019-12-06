/**
 *  @file eagine/bindump.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/memory/address.hpp>
#include <eagine/span.hpp>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace eagine {
//------------------------------------------------------------------------------
// _bindump_to_bin_b
//------------------------------------------------------------------------------
template <typename Putter>
void _bindump_to_bin_b(Putter& put_char, byte b) {
    static const char bd[2] = {'0', '1'};
    for(unsigned o = 0; o < 4; ++o) {
        byte c = (b >> ((4 - o - 1) * 2));
        put_char(' ');
        put_char(bd[(c >> 1) & 0x01]);
        put_char(bd[c & 0x01]);
    }
}
//------------------------------------------------------------------------------
template <typename Getter, typename Putter>
void _bindump_do_bin_dump(span_size_t bgn, Getter get_byte, Putter put_char) {

    bool done = false;
    span_size_t row = bgn - (bgn % 4);

    bool row_none[4]{};
    byte row_byte[4]{};

    while(!done) {
        span_size_t pos = row;
        bool empty_row = true;
        for(int b = 0; b < 4; ++b) {
            if(pos < bgn || done) {
                row_none[b] = true;
            } else {
                if(auto got = get_byte()) {
                    row_none[b] = false;
                    row_byte[b] = got.value();
                    empty_row = false;
                } else {
                    row_none[b] = true;
                    done = true;
                }
            }
            ++pos;
        }
        if(empty_row) {
            break;
        }

        std::stringstream temp;
        temp << std::setw(20) << std::setfill('.');
        temp << std::hex << row;
        for(char c : temp.str()) {
            put_char(c);
        }
        put_char('|');

        pos = row;
        for(int b = 0; b < 4; ++b) {
            if(b == 8) {
                put_char(' ');
            }

            if(row_none[b]) {
                put_char(' ');
                put_char('.');
                put_char('.');
            } else {
                put_char(' ');
                _bindump_to_bin_b(put_char, row_byte[b]);
            }
            ++pos;
        }

        put_char(' ');
        put_char('|');

        pos = row;
        for(span_size_t b = 0; b < 4; ++b) {
            if(b == 8) {
                put_char(' ');
            }

            if(row_none[b] || !std::isprint(row_byte[b])) {
                put_char('.');
            } else {
                put_char(char(row_byte[b]));
            }
            ++pos;
        }

        row += 4;
        put_char('|');
        put_char('\n');
    }
}
//------------------------------------------------------------------------------
// ostream << bindump
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void bindump::apply(
  bindump::byte_getter get_byte, bindump::char_putter put_char) {

    _bindump_do_bin_dump(0, get_byte, put_char);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::ostream& operator<<(std::ostream& out, const bindump& hd) {
    out << std::endl;

    span_size_t i = 0;

    _bindump_do_bin_dump(
      memory::const_address(hd._mb.begin()).value(),
      make_span_getter(i, hd._mb),
      [&out](char c) { out << c; });
    return out << std::flush;
}
//------------------------------------------------------------------------------
} // namespace eagine
