/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/memory/span_algo.hpp>

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
default_keyboard_layout::default_keyboard_layout(const float shift) {
    // first row
    add_key_coord('`', {0.F, 0.F, 0.F});
    add_key_coord('~', {0.F, 0.F, shift});
    add_key_coord('1', {1.F, 0.F, 0.F});
    add_key_coord('!', {1.F, 0.F, shift});
    add_key_coord('2', {2.F, 0.F, 0.F});
    add_key_coord('@', {2.F, 0.F, shift});
    add_key_coord('3', {3.F, 0.F, 0.F});
    add_key_coord('#', {3.F, 0.F, shift});
    add_key_coord('4', {4.F, 0.F, 0.F});
    add_key_coord('$', {4.F, 0.F, shift});
    add_key_coord('5', {5.F, 0.F, 0.F});
    add_key_coord('%', {5.F, 0.F, shift});
    add_key_coord('6', {6.F, 0.F, 0.F});
    add_key_coord('^', {6.F, 0.F, shift});
    add_key_coord('7', {7.F, 0.F, 0.F});
    add_key_coord('&', {7.F, 0.F, shift});
    add_key_coord('8', {8.F, 0.F, 0.F});
    add_key_coord('*', {8.F, 0.F, shift});
    add_key_coord('9', {9.F, 0.F, 0.F});
    add_key_coord('(', {9.F, 0.F, shift});
    add_key_coord('0', {10.F, 0.F, 0.F});
    add_key_coord(')', {10.F, 0.F, shift});
    add_key_coord('-', {11.F, 0.F, 0.F});
    add_key_coord('_', {11.F, 0.F, shift});
    add_key_coord('=', {11.F, 0.F, 0.F});
    add_key_coord('+', {11.F, 0.F, shift});
    // second row
    add_key_coord('q', {1.5F, 1.F, 0.F});
    add_key_coord('Q', {1.5F, 1.F, shift});
    add_key_coord('w', {2.5F, 1.F, 0.F});
    add_key_coord('W', {2.5F, 1.F, shift});
    add_key_coord('e', {3.5F, 1.F, 0.F});
    add_key_coord('E', {3.5F, 1.F, shift});
    add_key_coord('r', {4.5F, 1.F, 0.F});
    add_key_coord('R', {4.5F, 1.F, shift});
    add_key_coord('t', {5.5F, 1.F, 0.F});
    add_key_coord('T', {5.5F, 1.F, shift});
    add_key_coord('y', {6.5F, 1.F, 0.F});
    add_key_coord('Y', {6.5F, 1.F, shift});
    add_key_coord('u', {7.5F, 1.F, 0.F});
    add_key_coord('U', {7.5F, 1.F, shift});
    add_key_coord('i', {8.5F, 1.F, 0.F});
    add_key_coord('I', {8.5F, 1.F, shift});
    add_key_coord('o', {9.5F, 1.F, 0.F});
    add_key_coord('O', {9.5F, 1.F, shift});
    add_key_coord('p', {10.5F, 1.F, 0.F});
    add_key_coord('P', {10.5F, 1.F, shift});
    add_key_coord('[', {11.5F, 1.F, 0.F});
    add_key_coord('{', {11.5F, 1.F, shift});
    add_key_coord(']', {12.5F, 1.F, 0.F});
    add_key_coord('}', {12.5F, 1.F, shift});
    add_key_coord('\\', {14.F, 1.F, 0.F});
    add_key_coord('|', {14.F, 1.F, shift});
    // third row
    add_key_coord('a', {1.7F, 2.F, 0.F});
    add_key_coord('A', {1.7F, 2.F, shift});
    add_key_coord('s', {2.7F, 2.F, 0.F});
    add_key_coord('S', {2.7F, 2.F, shift});
    add_key_coord('d', {3.7F, 2.F, 0.F});
    add_key_coord('D', {3.7F, 2.F, shift});
    add_key_coord('f', {4.7F, 2.F, 0.F});
    add_key_coord('F', {4.7F, 2.F, shift});
    add_key_coord('g', {5.7F, 2.F, 0.F});
    add_key_coord('G', {5.7F, 2.F, shift});
    add_key_coord('h', {6.7F, 2.F, 0.F});
    add_key_coord('H', {6.7F, 2.F, shift});
    add_key_coord('j', {7.7F, 2.F, 0.F});
    add_key_coord('J', {7.7F, 2.F, shift});
    add_key_coord('k', {8.7F, 2.F, 0.F});
    add_key_coord('K', {8.7F, 2.F, shift});
    add_key_coord('l', {9.7F, 2.F, 0.F});
    add_key_coord('L', {9.7F, 2.F, shift});
    add_key_coord(';', {10.7F, 2.F, 0.F});
    add_key_coord(':', {10.7F, 2.F, shift});
    add_key_coord('\'', {11.7F, 2.F, 0.F});
    add_key_coord('"', {11.7F, 2.F, shift});
    // fourth row
    add_key_coord('z', {2.3F, 3.F, 0.F});
    add_key_coord('Z', {2.3F, 3.F, shift});
    add_key_coord('x', {3.3F, 3.F, 0.F});
    add_key_coord('X', {3.3F, 3.F, shift});
    add_key_coord('c', {4.3F, 3.F, 0.F});
    add_key_coord('C', {4.3F, 3.F, shift});
    add_key_coord('v', {5.3F, 3.F, 0.F});
    add_key_coord('V', {5.3F, 3.F, shift});
    add_key_coord('b', {6.3F, 3.F, 0.F});
    add_key_coord('B', {6.3F, 3.F, shift});
    add_key_coord('n', {7.3F, 3.F, 0.F});
    add_key_coord('N', {7.3F, 3.F, shift});
    add_key_coord('m', {8.3F, 3.F, 0.F});
    add_key_coord('M', {8.3F, 3.F, shift});
    add_key_coord(',', {9.3F, 3.F, 0.F});
    add_key_coord('<', {9.3F, 3.F, shift});
    add_key_coord('.', {10.3F, 3.F, 0.F});
    add_key_coord('>', {10.3F, 3.F, shift});
    add_key_coord('/', {11.3F, 3.F, 0.F});
    add_key_coord('?', {11.3F, 3.F, shift});
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto keyboard_distance::operator()(string_view ls, string_view rs) const
  -> float {
    return memory::basic_edit_distance<float>(ls, rs, [&](char lc, char rc) {
        if(lc == rc) {
            return 0.F;
        }
        const auto pos = _key_dist.find(std::pair<char, char>{lc, rc});
        if(pos != _key_dist.end()) {
            return pos->second;
        }
        return 5.F;
    });
}
//------------------------------------------------------------------------------
} // namespace eagine
