/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_mp_strings_test
#include <boost/test/unit_test.hpp>

#include <eagine/mp_strings.hpp>
#include <cstring>

BOOST_AUTO_TEST_SUITE(mp_strings_tests)

BOOST_AUTO_TEST_CASE(mp_strings_subscript)
{
	using namespace eagine;

	typedef mp_int_to_string_t<-1234567890> d;
	typedef mp_translate_t<d, mp_subscript> s;

	BOOST_CHECK(std::strcmp(s::value, "₋₁₂₃₄₅₆₇₈₉₀") == 0);
}

BOOST_AUTO_TEST_CASE(mp_strings_superscript)
{
	using namespace eagine;

	typedef mp_int_to_string_t<-1234567890> d;
	typedef mp_concat_t<
		mp_string<'n','1','=','('>, d, mp_string<')','+','i'>> x;
	typedef mp_translate_t<x, mp_superscript> s;

	BOOST_CHECK(std::strcmp(s::value, "ⁿ¹⁼⁽⁻¹²³⁴⁵⁶⁷⁸⁹⁰⁾⁺ⁱ") == 0);
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
