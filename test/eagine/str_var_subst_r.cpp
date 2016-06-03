/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_str_var_subst
#include <boost/test/unit_test.hpp>

#include <eagine/str_var_subst.hpp>

BOOST_AUTO_TEST_SUITE(str_var_subst_tests)

BOOST_AUTO_TEST_CASE(str_var_subst_1)
{
	using namespace eagine;

	std::map<std::string, std::string> empty;

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string(), empty),
		std::string()
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("abcdefgh{ijk}lmn"), empty),
		std::string("abcdefgh{ijk}lmn")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("abcdefgh${ijk}lmn"), empty),
		std::string("abcdefghlmn")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("abcdefgh${}lmn"), empty),
		std::string("abcdefgh${}lmn")
	);
}

BOOST_AUTO_TEST_CASE(str_var_subst_2)
{
	using namespace eagine;

	std::map<std::string, std::string> dict;
	dict["A"] = "1";
	dict["B"] = "2";
	dict["C"] = "3";
	dict["D"] = "4";

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string(), dict),
		std::string()
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("a{bc{defg}h{ijk}l}mn"), dict),
		std::string("a{bc{defg}h{ijk}l}mn")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("bla+ble$"), dict),
		std::string("bla+ble$")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("$bla+ble"), dict),
		std::string("$bla+ble")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("$bla$ble$"), dict),
		std::string("$bla$ble$")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("{${A}+${B}}"), dict),
		std::string("{1+2}")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("{${E}+${F}}"), dict),
		std::string("{+}")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("{${E}+${F}}"), dict, false),
		std::string("{+}")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("{${E}+${F}}"), dict, true),
		std::string("{${E}+${F}}")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("${A}_${B}-${C}+${D}"), dict),
		std::string("1_2-3+4")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("${A}_${E}_${D}"), dict, true),
		std::string("1_${E}_4")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("${A}_${E}_${D}"), dict,false),
		std::string("1__4")
	);
}

BOOST_AUTO_TEST_CASE(str_var_subst_3)
{
	using namespace eagine;

	std::map<std::string, std::string> dict;
	dict["A"] = "1";
	dict["B"] = "2";
	dict["1+2"] = "C";
	dict["C"] = "3";
	dict["2+2"] = "D";
	dict["D"] = "4";
	dict["4-3"] = "A";

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string(), dict),
		std::string()
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(
			std::string("${${B}+${B}}"),
			dict
		), std::string("D")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(
			std::string("${${A}+${B}}"),
			dict
		), std::string("C")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(
			std::string("${${${${B}+${B}}}-${${${A}+${B}}}}"),
			dict
		), std::string("A")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(
			std::string("${${${${${B}+${B}}}-${${${A}+${B}}}}}"),
			dict
		), std::string("1")
	);
}

BOOST_AUTO_TEST_CASE(str_var_subst_4)
{
	using namespace eagine;

	string_variable_map vars;
	vars	.set("A", "1")
		.set("B", "2")
		.set("C", "3")
		.set("D", "4")
		.set("1+2", "C")
		.set("2+2", "D")
		.set("4-3", "A");

	BOOST_CHECK_EQUAL(
		vars.subst_variables(
			std::string("${${${${${B}+${B}}}-${${${A}+${B}}}}}")
		), std::string("1")
	);
}

BOOST_AUTO_TEST_CASE(str_var_subst_5)
{
	using namespace eagine;

	std::vector<std::string> ss{"A", "B", "C", "D", "E"};

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string(), ss),
		std::string()
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("${1}${2}${3}${4}${5}"), ss),
		std::string("ABCDE")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("${1}${3}${5}${7}"), ss),
		std::string("ACE")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("${1}${3}${5}${7}"), ss, true),
		std::string("ACE${7}")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("${1}${1}${1}${1}${1}"), ss),
		std::string("AAAAA")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("${7}${11}${13}"), ss),
		std::string()
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("${7}${11}${13}"), ss, true),
		std::string("${7}${11}${13}")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("${4}${2}${1}${3}${5}"), ss),
		std::string("DBACE")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("<${0}>"), ss),
		std::string("<>")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("-${6}-"), ss),
		std::string("--")
	);

	BOOST_CHECK_EQUAL(
		substitute_variables(std::string("${2}-${5}-${2}-${5}"), ss),
		std::string("B-E-B-E")
	);
}

BOOST_AUTO_TEST_SUITE_END()
