/**
 *  @file eagine/unit/scales.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_SCALES_HPP
#define EAGINE_UNITS_SCALES_HPP

#include "../math/constants.hpp"
#include "../nothing.hpp"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif

namespace eagine::units {
namespace scales {
//------------------------------------------------------------------------------
template <typename X>
struct scale_of {
    using type = typename X::scale;
};
//------------------------------------------------------------------------------
template <typename X>
using scale_of_t = typename scale_of<X>::type;

struct one {
    using type = one;

    template <typename T>
    static constexpr auto to_base(T v) {
        return v;
    }

    template <typename T>
    static constexpr auto from_base(T v) {
        return v;
    }
};
//------------------------------------------------------------------------------
template <>
struct scale_of<nothing_t> : one {};

template <int I>
struct constant {
    using type = constant;

    template <typename T>
    static constexpr auto to_base(T v) {
        return v * I;
    }

    template <typename T>
    static constexpr auto from_base(T v) {
        return v / float(I);
    }
};
//------------------------------------------------------------------------------
template <int Num, int Den>
struct rational {
    using type = rational;

    template <typename T>
    static constexpr auto to_base(T v) {
        return (v * Num) / float(Den);
    }

    template <typename T>
    static constexpr auto from_base(T v) {
        return (v * Den) / float(Num);
    }
};
//------------------------------------------------------------------------------
template <int X, int Y>
struct power {
    using type = power;

    template <typename T>
    static constexpr auto to_base(T v) {
        using std::pow;
        return v * pow(X, Y);
    }

    template <typename T>
    static constexpr auto from_base(T v) {
        using std::pow;
        return v / pow(X, Y);
    }
};
//------------------------------------------------------------------------------
template <typename S>
struct inverted {
    using type = inverted;

    template <typename T>
    static constexpr auto to_base(T v) {
        return S::from_base(v);
    }

    template <typename T>
    static constexpr auto from_base(T v) {
        return S::to_base(v);
    }
};
//------------------------------------------------------------------------------
template <typename S1, typename S2>
struct multiplied {
    using type = multiplied;

    template <typename T>
    static constexpr auto to_base(T v) {
        return S2::to_base(S1::to_base(v));
    }

    template <typename T>
    static constexpr auto from_base(T v) {
        return S2::from_base(S1::from_base(v));
    }
};
//------------------------------------------------------------------------------
template <typename S1, typename S2>
struct divided {
    using type = divided;

    template <typename T>
    static constexpr auto to_base(T v) {
        return S2::from_base(S1::to_base(v));
    }

    template <typename T>
    static constexpr auto from_base(T v) {
        return S2::to_base(S1::from_base(v));
    }
};
//------------------------------------------------------------------------------
template <typename S1, typename S2>
struct recombined : multiplied<S1, S2> {
    using type = recombined;
};
//------------------------------------------------------------------------------
// nano
using nano = power<1000, -3>;
// micro
using micro = power<1000, -2>;
// milli
using milli = power<1000, -1>;
// centi
using centi = power<10, -2>;
// deci
using deci = power<10, -1>;
// deca
using deca = power<10, 1>;
// hecto
using hecto = power<10, 2>;
// kilo
using kilo = power<1000, 1>;
// mega
using mega = power<1000, 2>;
// giga
using giga = power<1000, 3>;
// tera
using tera = power<1000, 4>;
// kibi
using kibi = power<1024, 1>;
// mebi
using mebi = power<1024, 2>;
// gibi
using gibi = power<1024, 3>;
// tebi
using tebi = power<1024, 4>;
// pi
struct pi {
    using type = pi;

    template <typename T>
    static constexpr auto to_base(T v) {
        return v * math::pi;
    }

    template <typename T>
    static constexpr auto from_base(T v) {
        return v / math::pi;
    }
};
//------------------------------------------------------------------------------
} // namespace scales
//------------------------------------------------------------------------------
template <>
struct name_of<scales::one> {
    static constexpr const char mp_str[] = "";
};
template <>
struct symbol_of<scales::one> {
    static constexpr const char mp_str[] = "";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::nano> {
    static constexpr const char mp_str[] = "nano";
};
template <>
struct symbol_of<scales::nano> {
    static constexpr const char mp_str[] = "n";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::micro> {
    static constexpr const char mp_str[] = "micro";
};
template <>
struct symbol_of<scales::micro> {
    static constexpr const char mp_str[3] = {char(0xCE), char(0xBC), '\0'};
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::milli> {
    static constexpr const char mp_str[] = "milli";
};
template <>
struct symbol_of<scales::milli> {
    static constexpr const char mp_str[] = "m";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::centi> {
    static constexpr const char mp_str[] = "centi";
};
template <>
struct symbol_of<scales::centi> {
    static constexpr const char mp_str[] = "c";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::deci> {
    static constexpr const char mp_str[] = "deci";
};
template <>
struct symbol_of<scales::deci> {
    static constexpr const char mp_str[] = "d";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::deca> {
    static constexpr const char mp_str[] = "deca";
};
template <>
struct symbol_of<scales::deca> {
    static constexpr const char mp_str[] = "dc";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::hecto> {
    static constexpr const char mp_str[] = "hecto";
};
template <>
struct symbol_of<scales::hecto> {
    static constexpr const char mp_str[] = "h";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::kilo> {
    static constexpr const char mp_str[] = "kilo";
};
template <>
struct symbol_of<scales::kilo> {
    static constexpr const char mp_str[] = "k";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::mega> {
    static constexpr const char mp_str[] = "mega";
};
template <>
struct symbol_of<scales::mega> {
    static constexpr const char mp_str[] = "M";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::giga> {
    static constexpr const char mp_str[] = "giga";
};
template <>
struct symbol_of<scales::giga> {
    static constexpr const char mp_str[] = "G";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::tera> {
    static constexpr const char mp_str[] = "tera";
};
template <>
struct symbol_of<scales::tera> {
    static constexpr const char mp_str[] = "T";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::kibi> {
    static constexpr const char mp_str[] = "kibi";
};
template <>
struct symbol_of<scales::kibi> {
    static constexpr const char mp_str[] = "Ki";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::mebi> {
    static constexpr const char mp_str[] = "mebi";
};
template <>
struct symbol_of<scales::mebi> {
    static constexpr const char mp_str[] = "Mi";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::gibi> {
    static constexpr const char mp_str[] = "gibi";
};
template <>
struct symbol_of<scales::gibi> {
    static constexpr const char mp_str[] = "Gi";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::tebi> {
    static constexpr const char mp_str[] = "tebi";
};
template <>
struct symbol_of<scales::tebi> {
    static constexpr const char mp_str[] = "Ti";
};
//------------------------------------------------------------------------------
template <>
struct name_of<scales::pi> {
    static constexpr const char mp_str[3] = {char(0xCF), char(0x80), '\0'};
};
template <>
struct symbol_of<scales::pi> {
    static constexpr const char mp_str[] = {char(0xCF), char(0x80), '\0'};
};
//------------------------------------------------------------------------------
} // namespace eagine::units

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // EAGINE_UNITS_SCALES_HPP
