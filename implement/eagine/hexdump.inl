/// @file eagine/hexdump.inl
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/memory/address.hpp>
#include <eagine/span.hpp>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace eagine {
//------------------------------------------------------------------------------
// _hexdump_to_hex_b
//------------------------------------------------------------------------------
template <typename Putter>
void _hexdump_to_hex_b(Putter& put_char, byte b) {
    static const char hd[16] = {
      '0',
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
    put_char(' ');
    // NOLINTNEXTLINE(hicpp-signed-bitwise)
    put_char(hd[(b >> 4U) & 0x0FU]);
    put_char(hd[b & 0x0FU]);
}
//------------------------------------------------------------------------------
template <typename Getter, typename Putter>
void _hexdump_do_hex_dump(span_size_t bgn, Getter get_byte, Putter put_char) {

    bool done = false;
    span_size_t row = bgn - (bgn % 16);

    bool row_none[16]{};
    byte row_byte[16]{};

    while(!done) {
        span_size_t pos = row;
        bool empty_row = true;
        for(int b = 0; b < 16; ++b) {
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
        for(int b = 0; b < 16; ++b) {
            if(b == 8) {
                put_char(' ');
            }

            if(row_none[b]) {
                put_char(' ');
                put_char('.');
                put_char('.');
            } else {
                _hexdump_to_hex_b(put_char, row_byte[b]);
            }
            ++pos;
        }

        put_char(' ');
        put_char('|');

        pos = row;
        for(span_size_t b = 0; b < 16; ++b) {
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

        row += 16;
        put_char('|');
        put_char('\n');
    }
}
//------------------------------------------------------------------------------
// ostream << hexdump
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void hexdump::apply(
  hexdump::byte_getter get_byte,
  hexdump::char_putter put_char) {

    _hexdump_do_hex_dump(0, get_byte, put_char);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto operator<<(std::ostream& out, const hexdump& hd) -> std::ostream& {
    out << std::endl;

    span_size_t i = 0;

    _hexdump_do_hex_dump(
      memory::const_address(hd._mb.begin()).value(),
      make_span_getter(i, hd._mb),
      [&out](char c) { out << c; });
    return out << std::flush;
}
//------------------------------------------------------------------------------
} // namespace eagine
