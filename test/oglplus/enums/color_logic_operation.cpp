//  File test/oglplus/enums/color_logic_operation.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_color_logic_operation

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_color_logic_operation)

BOOST_AUTO_TEST_CASE(enum_color_logic_operation_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	color_logic_operation x;
	(void)x;

#ifdef GL_AND
	x = ev.and_;
	BOOST_CHECK(x == ev.and_);
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_AND_INVERTED
	x = ev.and_inverted;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
	BOOST_CHECK(x == ev.and_inverted);
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_AND_REVERSE
	x = ev.and_reverse;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
	BOOST_CHECK(x == ev.and_reverse);
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_CLEAR
	x = ev.clear;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
	BOOST_CHECK(x == ev.clear);
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_COPY
	x = ev.copy;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
	BOOST_CHECK(x == ev.copy);
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_COPY_INVERTED
	x = ev.copy_inverted;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
	BOOST_CHECK(x == ev.copy_inverted);
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_EQUIV
	x = ev.equiv;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
	BOOST_CHECK(x == ev.equiv);
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_INVERT
	x = ev.invert;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
	BOOST_CHECK(x == ev.invert);
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_NAND
	x = ev.nand;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
	BOOST_CHECK(x == ev.nand);
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_NOOP
	x = ev.noop;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
	BOOST_CHECK(x == ev.noop);
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_NOR
	x = ev.nor;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
	BOOST_CHECK(x == ev.nor);
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_OR
	x = ev.or_;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
	BOOST_CHECK(x == ev.or_);
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_OR_INVERTED
	x = ev.or_inverted;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
	BOOST_CHECK(x == ev.or_inverted);
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_OR_REVERSE
	x = ev.or_reverse;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
	BOOST_CHECK(x == ev.or_reverse);
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_SET
	x = ev.set;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
	BOOST_CHECK(x == ev.set);
# ifdef GL_XOR
	BOOST_CHECK(x != ev.xor_);
# endif
#endif

#ifdef GL_XOR
	x = ev.xor_;
# ifdef GL_AND
	BOOST_CHECK(x != ev.and_);
# endif
# ifdef GL_AND_INVERTED
	BOOST_CHECK(x != ev.and_inverted);
# endif
# ifdef GL_AND_REVERSE
	BOOST_CHECK(x != ev.and_reverse);
# endif
# ifdef GL_CLEAR
	BOOST_CHECK(x != ev.clear);
# endif
# ifdef GL_COPY
	BOOST_CHECK(x != ev.copy);
# endif
# ifdef GL_COPY_INVERTED
	BOOST_CHECK(x != ev.copy_inverted);
# endif
# ifdef GL_EQUIV
	BOOST_CHECK(x != ev.equiv);
# endif
# ifdef GL_INVERT
	BOOST_CHECK(x != ev.invert);
# endif
# ifdef GL_NAND
	BOOST_CHECK(x != ev.nand);
# endif
# ifdef GL_NOOP
	BOOST_CHECK(x != ev.noop);
# endif
# ifdef GL_NOR
	BOOST_CHECK(x != ev.nor);
# endif
# ifdef GL_OR
	BOOST_CHECK(x != ev.or_);
# endif
# ifdef GL_OR_INVERTED
	BOOST_CHECK(x != ev.or_inverted);
# endif
# ifdef GL_OR_REVERSE
	BOOST_CHECK(x != ev.or_reverse);
# endif
# ifdef GL_SET
	BOOST_CHECK(x != ev.set);
# endif
	BOOST_CHECK(x == ev.xor_);
#endif
}

BOOST_AUTO_TEST_CASE(enum_color_logic_operation_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	color_logic_operation x;
	(void)x;

#ifdef GL_AND
	x = ev.and_;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"AND"
	) == 0);
#endif

#ifdef GL_AND_INVERTED
	x = ev.and_inverted;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"AND_INVERTED"
	) == 0);
#endif

#ifdef GL_AND_REVERSE
	x = ev.and_reverse;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"AND_REVERSE"
	) == 0);
#endif

#ifdef GL_CLEAR
	x = ev.clear;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"CLEAR"
	) == 0);
#endif

#ifdef GL_COPY
	x = ev.copy;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COPY"
	) == 0);
#endif

#ifdef GL_COPY_INVERTED
	x = ev.copy_inverted;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"COPY_INVERTED"
	) == 0);
#endif

#ifdef GL_EQUIV
	x = ev.equiv;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"EQUIV"
	) == 0);
#endif

#ifdef GL_INVERT
	x = ev.invert;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"INVERT"
	) == 0);
#endif

#ifdef GL_NAND
	x = ev.nand;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NAND"
	) == 0);
#endif

#ifdef GL_NOOP
	x = ev.noop;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NOOP"
	) == 0);
#endif

#ifdef GL_NOR
	x = ev.nor;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"NOR"
	) == 0);
#endif

#ifdef GL_OR
	x = ev.or_;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OR"
	) == 0);
#endif

#ifdef GL_OR_INVERTED
	x = ev.or_inverted;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OR_INVERTED"
	) == 0);
#endif

#ifdef GL_OR_REVERSE
	x = ev.or_reverse;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"OR_REVERSE"
	) == 0);
#endif

#ifdef GL_SET
	x = ev.set;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"SET"
	) == 0);
#endif

#ifdef GL_XOR
	x = ev.xor_;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"XOR"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_color_logic_operation_range)
{
	using namespace oglplus;
	color_logic_operation x;
	(void)x;
	auto count = enum_value_range(x).size();

#ifdef GL_AND
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_AND
	) != r.end());
}
#endif

#ifdef GL_AND_INVERTED
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_AND_INVERTED
	) != r.end());
}
#endif

#ifdef GL_AND_REVERSE
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_AND_REVERSE
	) != r.end());
}
#endif

#ifdef GL_CLEAR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_CLEAR
	) != r.end());
}
#endif

#ifdef GL_COPY
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_COPY
	) != r.end());
}
#endif

#ifdef GL_COPY_INVERTED
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_COPY_INVERTED
	) != r.end());
}
#endif

#ifdef GL_EQUIV
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_EQUIV
	) != r.end());
}
#endif

#ifdef GL_INVERT
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_INVERT
	) != r.end());
}
#endif

#ifdef GL_NAND
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_NAND
	) != r.end());
}
#endif

#ifdef GL_NOOP
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_NOOP
	) != r.end());
}
#endif

#ifdef GL_NOR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_NOR
	) != r.end());
}
#endif

#ifdef GL_OR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_OR
	) != r.end());
}
#endif

#ifdef GL_OR_INVERTED
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_OR_INVERTED
	) != r.end());
}
#endif

#ifdef GL_OR_REVERSE
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_OR_REVERSE
	) != r.end());
}
#endif

#ifdef GL_SET
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_SET
	) != r.end());
}
#endif

#ifdef GL_XOR
{
	--count;
	array_view<const GLenum> r = enum_value_range(x);
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		GL_XOR
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_SUITE_END()
