/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_identifier
#include <boost/test/unit_test.hpp>

#include <eagine/identifier.hpp>
#include "../random.hpp"

BOOST_AUTO_TEST_SUITE(identifier_tests)

static eagine::test_random_generator rg;

static void test_gen_ident(char* str, eagine::span_size_t n) {

	for(eagine::span_size_t i=0; i<n; ++i) {

		char& c = str[i];

		switch(rg.get_int(0, 9)) {
			case 0:
			case 1: c = rg.get_char('0', '9'); break;
			case 2:
			case 3:
			case 4:
			case 5: c = rg.get_char('A', 'Z'); break;
			case 6:
			case 7:
			case 8: c = rg.get_char('a', 'z'); break;
			case 9: c = rg.get_bool()?'-':'_'; break;
		}
	}
	str[n] = '\0';
}

BOOST_AUTO_TEST_CASE(identifier_aux_1)
{
	using eagine::span_size_t;
	using namespace eagine::_aux;

	for(char c : _6bit_dec_tab) {
		const auto i = span_size_t(c);
		BOOST_CHECK(_is_ident_char(i));
		BOOST_CHECK_EQUAL(_6bit_dec_tab[_6bit_enc_tab[i]], c);
		BOOST_CHECK_EQUAL(_6bit_round_trip(i), i);
	}
}

BOOST_AUTO_TEST_CASE(identifier_aux_2)
{
	using eagine::span_size_t;
	using eagine::std_size;

	for(int k=0; k<1000; ++k) {
		const span_size_t l = eagine::max_identifier_length;
		char name1[l+1];
		char name2[l+1];

		const span_size_t n = rg.get_span_size(0, l-1);
		test_gen_ident(name1, n);

		const eagine::identifier_t id =
			eagine::_aux::_enc_ident(name1, n);
		const span_size_t b =
			eagine::_aux::_dec_ident(id, name2, l);

		const std::string s1(name1+0, std_size(n-0));
		const std::string s2(name2+b, std_size(l-b));

		BOOST_CHECK_EQUAL(s1, s2);
	}
}

BOOST_AUTO_TEST_CASE(identifier_1)
{
	using eagine::span_size_t;
	using eagine::std_size;

	for(int k=0; k<1000; ++k) {
		const span_size_t l = eagine::max_identifier_length;
		char name1[l+1];
		char name2[l+1];

		const span_size_t n = rg.get_span_size(0, l-1);
		test_gen_ident(name1, n);

		const eagine::identifier_t id =
			eagine::encode_identifier(name1);
		const span_size_t b =
			eagine::decode_identifier(id, name2);

		const std::string s1(name1+0, std_size(n-0));
		const std::string s2(name2+b, std_size(l-b));

		BOOST_CHECK_EQUAL(s1, s2);
	}
}

BOOST_AUTO_TEST_CASE(identifier_2)
{
	using eagine::span_size_t;
	using eagine::std_size;

	for(int k=0; k<1000; ++k) {
		const span_size_t l = eagine::max_identifier_length;
		char name[l+1];

		const span_size_t n = rg.get_span_size(0, l-1);
		test_gen_ident(name, n);

		const eagine::identifier id{name};
		const std::string s1(name, std_size(n));
		const std::string s2 = id.str();

		BOOST_CHECK_EQUAL(s1, s2);
	}
}

BOOST_AUTO_TEST_CASE(identifier_3)
{
	using eagine::span_size_t;
	using eagine::std_size;

	for(int k=0; k<1000; ++k) {
		const span_size_t l = eagine::max_identifier_length;
		char name[l+1];

		const span_size_t n = rg.get_span_size(0, l-1);
		test_gen_ident(name, n);
		const std::string s1(name, std_size(n));

		const eagine::identifier id{s1};
		const std::string s2 = id.str();

		BOOST_CHECK_EQUAL(s1, s2);
	}
}

BOOST_AUTO_TEST_SUITE_END()
