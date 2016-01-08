/**
 *  @file eagine/mp_strings.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MP_STRINGS_1509260923_HPP
#define EAGINE_MP_STRINGS_1509260923_HPP

#include "mp_string.hpp"

namespace eagine {

template <char C>
struct mp_superscript;

template <char C>
using mp_superscript_t = typename mp_superscript<C>::type;

template <>
struct mp_superscript<'i'>
 : mp_string<char(0xE2),char(0x81),char(0xB1)>
{ };

template <>
struct mp_superscript<'n'>
 : mp_string<char(0xE2),char(0x81),char(0xBF)>
{ };

template <>
struct mp_superscript<'+'>
 : mp_string<char(0xE2),char(0x81),char(0xBA)>
{ };

template <>
struct mp_superscript<'-'>
 : mp_string<char(0xE2),char(0x81),char(0xBB)>
{ };

template <>
struct mp_superscript<'='>
 : mp_string<char(0xE2),char(0x81),char(0xBC)>
{ };

template <>
struct mp_superscript<'('>
 : mp_string<char(0xE2),char(0x81),char(0xBD)>
{ };

template <>
struct mp_superscript<')'>
 : mp_string<char(0xE2),char(0x81),char(0xBE)>
{ };

template <>
struct mp_superscript<'0'>
 : mp_string<char(0xE2),char(0x81),char(0xB0)>
{ };

template <>
struct mp_superscript<'1'>
 : mp_string<char(0xC2),char(0xB9)>
{ };

template <>
struct mp_superscript<'2'>
 : mp_string<char(0xC2),char(0xB2)>
{ };

template <>
struct mp_superscript<'3'>
 : mp_string<char(0xC2),char(0xB3)>
{ };

template <>
struct mp_superscript<'4'>
 : mp_string<char(0xE2),char(0x81),char(0xB4)>
{ };

template <>
struct mp_superscript<'5'>
 : mp_string<char(0xE2),char(0x81),char(0xB5)>
{ };

template <>
struct mp_superscript<'6'>
 : mp_string<char(0xE2),char(0x81),char(0xB6)>
{ };

template <>
struct mp_superscript<'7'>
 : mp_string<char(0xE2),char(0x81),char(0xB7)>
{ };

template <>
struct mp_superscript<'8'>
 : mp_string<char(0xE2),char(0x81),char(0xB8)>
{ };

template <>
struct mp_superscript<'9'>
 : mp_string<char(0xE2),char(0x81),char(0xB9)>
{ };

// mp_subscript
template <char C>
struct mp_subscript;

template <char C>
using mp_subscript_t = typename mp_subscript<C>::type;

template <>
struct mp_subscript<'0'>
 : mp_string<char(0xE2),char(0x82),char(0x80)>
{ };

template <>
struct mp_subscript<'1'>
 : mp_string<char(0xE2),char(0x82),char(0x81)>
{ };

template <>
struct mp_subscript<'2'>
 : mp_string<char(0xE2),char(0x82),char(0x82)>
{ };

template <>
struct mp_subscript<'3'>
 : mp_string<char(0xE2),char(0x82),char(0x83)>
{ };

template <>
struct mp_subscript<'4'>
 : mp_string<char(0xE2),char(0x82),char(0x84)>
{ };

template <>
struct mp_subscript<'5'>
 : mp_string<char(0xE2),char(0x82),char(0x85)>
{ };

template <>
struct mp_subscript<'6'>
 : mp_string<char(0xE2),char(0x82),char(0x86)>
{ };

template <>
struct mp_subscript<'7'>
 : mp_string<char(0xE2),char(0x82),char(0x87)>
{ };

template <>
struct mp_subscript<'8'>
 : mp_string<char(0xE2),char(0x82),char(0x88)>
{ };

template <>
struct mp_subscript<'9'>
 : mp_string<char(0xE2),char(0x82),char(0x89)>
{ };

template <>
struct mp_subscript<'+'>
 : mp_string<char(0xE2),char(0x82),char(0x8A)>
{ };

template <>
struct mp_subscript<'-'>
 : mp_string<char(0xE2),char(0x82),char(0x8B)>
{ };

} // namespace eagine

#endif // include guard
