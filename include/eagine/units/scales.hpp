/**
 *  @file eagine/unit/scales.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UNITS_SCALES_1512222148_HPP
#define EAGINE_UNITS_SCALES_1512222148_HPP

#include <cmath>

namespace eagine {
namespace units {
namespace scales {

template <typename X>
struct scale_name;

template <typename X>
struct scale_symbol;

template <typename X>
struct scale_of
{
	typedef typename X::scale type;
};

template <typename X>
using scale_of_t = typename scale_of<X>::type;

struct one
{
	typedef one type;

	template <typename T>
	static constexpr inline
	T mul(T v)
	{
		return v;
	}

	template <typename T>
	static constexpr inline
	T div(T v)
	{
		return v;
	}
};

template <>
struct scale_name<one>
{
	static constexpr const char mp_str[] = "";
};
template <>
struct scale_symbol<one>
{
	static constexpr const char mp_str[] = "";
};

template <>
struct scale_of<nothing_t>
 : one
{ };

template <int I>
struct constant
{
	typedef constant type;

	template <typename T>
	static constexpr inline
	auto mul(T v)
	{
		return v*I;
	}

	template <typename T>
	static constexpr inline
	auto div(T v)
	{
		return v/float(I);
	}
};

template <int Num, int Den>
struct rational
{
	typedef rational type;

	template <typename T>
	static constexpr inline
	auto mul(T v)
	{
		return (v*Num)/float(Den);
	}

	template <typename T>
	static constexpr inline
	auto div(T v)
	{
		return (v*Den)/float(Num);
	}
};

template <int X, int Y>
struct power
{
	typedef power type;

	template <typename T>
	static constexpr inline
	auto mul(T v)
	{
		using std::pow;
		return v*pow(X, Y);
	}

	template <typename T>
	static constexpr inline
	auto div(T v)
	{
		using std::pow;
		return v/pow(X, Y);
	}
};

template <typename S>
struct inverted
{
	typedef inverted type;

	template <typename T>
	static constexpr inline
	auto mul(T v)
	{
		return S::div(v);
	}

	template <typename T>
	static constexpr inline
	auto div(T v)
	{
		return S::mul(v);
	}
};

template <typename S1, typename S2>
struct multiplied
{
	typedef multiplied type;

	template <typename T>
	static constexpr inline
	auto mul(T v)
	{
		return S2::mul(S1::mul(v));
	}

	template <typename T>
	static constexpr inline
	auto div(T v)
	{
		return S2::div(S1::div(v));
	}
};

template <typename S1, typename S2>
struct divided
{
	typedef divided type;

	template <typename T>
	static constexpr inline
	auto mul(T v)
	{
		return S2::div(S1::mul(v));
	}

	template <typename T>
	static constexpr inline
	auto div(T v)
	{
		return S2::mul(S1::div(v));
	}
};

template <typename S1, typename S2>
struct recombined
 : multiplied<S1, S2>
{
	typedef recombined type;
};

// nano
typedef power<1000,-3> nano;

template <>
struct scale_name<nano>
{
	static constexpr const char mp_str[] = "nano";
};
template <>
struct scale_symbol<nano>
{
	static constexpr const char mp_str[] = "n";
};

// micro
typedef power<1000,-2> micro;

template <>
struct scale_name<micro>
{
	static constexpr const char mp_str[] = "micro";
};
template <>
struct scale_symbol<micro>
{
	static constexpr const char mp_str[3] = {char(0xCE), char(0xBC), '\0'};
};

// milli
typedef power<1000,-1> milli;

template <>
struct scale_name<milli>
{
	static constexpr const char mp_str[] = "milli";
};
template <>
struct scale_symbol<milli>
{
	static constexpr const char mp_str[] = "m";
};

// centi
typedef power<10,-2> centi;

template <>
struct scale_name<centi>
{
	static constexpr const char mp_str[] = "centi";
};
template <>
struct scale_symbol<centi>
{
	static constexpr const char mp_str[] = "c";
};

// deci
typedef power<10,-1> deci;

template <>
struct scale_name<deci>
{
	static constexpr const char mp_str[] = "deci";
};
template <>
struct scale_symbol<deci>
{
	static constexpr const char mp_str[] = "d";
};

// deca
typedef power<10, 1> deca;

template <>
struct scale_name<deca>
{
	static constexpr const char mp_str[] = "deca";
};
template <>
struct scale_symbol<deca>
{
	static constexpr const char mp_str[] = "dc";
};

// hecto
typedef power<10, 2> hecto;

template <>
struct scale_name<hecto>
{
	static constexpr const char mp_str[] = "hecto";
};
template <>
struct scale_symbol<hecto>
{
	static constexpr const char mp_str[] = "h";
};

// kilo
typedef power<1000, 1> kilo;

template <>
struct scale_name<kilo>
{
	static constexpr const char mp_str[] = "kilo";
};
template <>
struct scale_symbol<kilo>
{
	static constexpr const char mp_str[] = "k";
};

// mega
typedef power<1000, 2> mega;

template <>
struct scale_name<mega>
{
	static constexpr const char mp_str[] = "mega";
};
template <>
struct scale_symbol<mega>
{
	static constexpr const char mp_str[] = "M";
};

// giga
typedef power<1000, 3> giga;

template <>
struct scale_name<giga>
{
	static constexpr const char mp_str[] = "giga";
};
template <>
struct scale_symbol<giga>
{
	static constexpr const char mp_str[] = "G";
};

// tera
typedef power<1000, 4> tera;

template <>
struct scale_name<tera>
{
	static constexpr const char mp_str[] = "tera";
};
template <>
struct scale_symbol<tera>
{
	static constexpr const char mp_str[] = "T";
};

// kibi
typedef power<1024, 1> kibi;

template <>
struct scale_name<kibi>
{
	static constexpr const char mp_str[] = "kibi";
};
template <>
struct scale_symbol<kibi>
{
	static constexpr const char mp_str[] = "Ki";
};

// mebi
typedef power<1024, 2> mebi;

template <>
struct scale_name<mebi>
{
	static constexpr const char mp_str[] = "mebi";
};
template <>
struct scale_symbol<mebi>
{
	static constexpr const char mp_str[] = "Mi";
};

// gibi
typedef power<1024, 3> gibi;

template <>
struct scale_name<gibi>
{
	static constexpr const char mp_str[] = "gibi";
};
template <>
struct scale_symbol<gibi>
{
	static constexpr const char mp_str[] = "Gi";
};

// tebi
typedef power<1024, 4> tebi;

template <>
struct scale_name<tebi>
{
	static constexpr const char mp_str[] = "tebi";
};
template <>
struct scale_symbol<tebi>
{
	static constexpr const char mp_str[] = "Ti";
};

// pi
struct pi
{
	typedef pi type;

	template <typename T>
	static constexpr inline
	auto mul(T v)
	{
#ifdef M_PI
		return v*M_PI;
#else
		return v*3.14159265358979323846;
#endif
	}

	template <typename T>
	static constexpr inline
	auto div(T v)
	{
#ifdef M_PI
		return v/M_PI;
#else
		return v/3.14159265358979323846;
#endif
	}
};

template <>
struct scale_name<pi>
{
	static constexpr const char mp_str[3] = {char(0xCF), char(0x80), '\0'};
};
template <>
struct scale_symbol<pi>
{
	static constexpr const char mp_str[] = {char(0xCF), char(0x80), '\0'};
};

} // namespace scales
} // namespace units
} // namespace eagine

#endif //include guard

