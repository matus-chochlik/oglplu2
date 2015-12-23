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

struct one
{
	typedef one type;

	static constexpr int value = 1;
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

template <int Num, int Den>
struct rational
{
	typedef rational type;

	struct _impl
	{
		template <typename T>
		friend constexpr inline
		auto operator*(T v, _impl)
		noexcept
		{
			return (v*Num)/Den;
		}

		template <typename T>
		friend constexpr inline
		auto operator/(T v, _impl)
		noexcept
		{
			return (v*Den)/Num;
		}
	};
	static constexpr _impl value = {};
};

typedef rational<1, 1000000000> nano;

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

typedef rational<1, 1000000> micro;

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

typedef rational<1, 1000> milli;

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

typedef rational<1, 100> centi;

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

typedef rational<1, 10> deci;

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

typedef rational<10, 1> deca;

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

typedef rational<100, 1> hecto;

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

typedef rational<1000, 1> kilo;

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

typedef rational<1000000, 1> mega;

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

typedef rational<1000000000, 1> giga;

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

struct pi
{
	typedef pi type;

	struct _impl
	{
		template <typename T>
		friend constexpr inline
		auto operator*(T v,_impl)
		noexcept
		{
			return v*M_PI;
		}

		template <typename T>
		friend constexpr inline
		auto operator/(T v,_impl)
		noexcept
		{
			return v/M_PI;
		}
	};
	static constexpr _impl value = {};
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

template <typename S>
struct inverted
{
	typedef inverted type;

	struct _impl
	{
		template <typename T>
		friend constexpr inline
		auto operator*(T v,_impl)
		noexcept
		{
			return v/S::value;
		}

		template <typename T>
		friend constexpr inline
		auto operator/(T v,_impl)
		noexcept
		{
			return v*S::value;
		}
	};

	static constexpr _impl value = {};
};

template <typename S1, typename S2>
struct multiplied
{
	typedef multiplied type;

	struct _impl
	{
		template <typename T>
		friend constexpr inline
		auto operator*(T v,_impl)
		noexcept
		{
			return (v*S1::value)*S2::value;
		}

		template <typename T>
		friend constexpr inline
		auto operator/(T v,_impl)
		noexcept
		{
			return (v/S1::value)/S2::value;
		}
	};

	static constexpr _impl value = {};
};

template <typename S1, typename S2>
struct divided
{
	typedef divided type;

	struct _impl
	{
		template <typename T>
		friend constexpr inline
		auto operator*(T v,_impl)
		noexcept
		{
			return (v*S1::value)/S2::value;
		}

		template <typename T>
		friend constexpr inline
		auto operator/(T v,_impl)
		noexcept
		{
			return (v/S1::value)*S2::value;
		}
	};

	static constexpr _impl value = {};
};

} // namespace scales
} // namespace units
} // namespace eagine

#endif //include guard

