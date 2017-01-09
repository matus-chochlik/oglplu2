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
		str[i] = rg.get_char_from(eagine::_aux::_6bit_dec_tab);
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

BOOST_AUTO_TEST_CASE(identifier_tag_1)
{
	using namespace eagine;

	BOOST_CHECK_EQUAL(tag_name(EAGINE_TAG(A)), "A");
	BOOST_CHECK_EQUAL(tag_name(EAGINE_TAG(BC)), "BC");
	BOOST_CHECK_EQUAL(tag_name(EAGINE_TAG(CDE)), "CDE");
	BOOST_CHECK_EQUAL(tag_name(EAGINE_TAG(DEFG)), "DEFG");
	BOOST_CHECK_EQUAL(tag_name(EAGINE_TAG(EFGHI)), "EFGHI");
	BOOST_CHECK_EQUAL(tag_name(EAGINE_TAG(FGHIJK)), "FGHIJK");
	BOOST_CHECK_EQUAL(tag_name(EAGINE_TAG(GHIJKLM)), "GHIJKLM");
	BOOST_CHECK_EQUAL(tag_name(EAGINE_TAG(HIJKLMNO)), "HIJKLMNO");
	BOOST_CHECK_EQUAL(tag_name(EAGINE_TAG(IJKLMNOPQ)), "IJKLMNOPQ");
	BOOST_CHECK_EQUAL(tag_name(EAGINE_TAG(JKLMNOPQRS)), "JKLMNOPQRS");
}

BOOST_AUTO_TEST_CASE(identifier_tag_2)
{
	using namespace eagine;
	using id = eagine::identifier;

	BOOST_CHECK_EQUAL(id(EAGINE_TAG(A)).str(), "A");
	BOOST_CHECK_EQUAL(id(EAGINE_TAG(BC)).str(), "BC");
	BOOST_CHECK_EQUAL(id(EAGINE_TAG(CDE)).str(), "CDE");
	BOOST_CHECK_EQUAL(id(EAGINE_TAG(DEFG)).str(), "DEFG");
	BOOST_CHECK_EQUAL(id(EAGINE_TAG(EFGHI)).str(), "EFGHI");
	BOOST_CHECK_EQUAL(id(EAGINE_TAG(FGHIJK)).str(), "FGHIJK");
	BOOST_CHECK_EQUAL(id(EAGINE_TAG(GHIJKLM)).str(), "GHIJKLM");
	BOOST_CHECK_EQUAL(id(EAGINE_TAG(HIJKLMNO)).str(), "HIJKLMNO");
	BOOST_CHECK_EQUAL(id(EAGINE_TAG(IJKLMNOPQ)).str(), "IJKLMNOPQ");
	BOOST_CHECK_EQUAL(id(EAGINE_TAG(JKLMNOPQRS)).str(), "JKLMNOPQRS");
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

		BOOST_CHECK(id.has_value());
		BOOST_CHECK(bool(id));
		BOOST_CHECK(!!id);

		BOOST_CHECK_EQUAL(s1, s2);
	}

	const eagine::identifier id;
	BOOST_CHECK(!id.has_value());
	BOOST_CHECK(!bool(id));
	BOOST_CHECK(!id);

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
