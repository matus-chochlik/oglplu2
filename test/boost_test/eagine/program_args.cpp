/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/program_args.hpp>
#include <eagine/array_size.hpp>
#define BOOST_TEST_MODULE EAGINE_program_args
#include "../unit_test.inl"

BOOST_AUTO_TEST_SUITE(program_args_tests)

BOOST_AUTO_TEST_CASE(program_args_1)
{
	using namespace eagine;

	const char* argv[6] = {"cmd", "arg1", "arg2", "arg3", "arg4", "arg5"};

	program_args pa(array_size(argv), argv);

	BOOST_CHECK(!pa.empty());
	BOOST_CHECK_EQUAL(pa.size(), array_size(argv));

	int i=1;
	program_arg a = pa.first();

	while(a.is_valid())
	{
		BOOST_ASSERT(bool(a));
		BOOST_ASSERT(!!a);
		BOOST_ASSERT(i < int(array_size(argv)));
		BOOST_CHECK_EQUAL(a.get(), cstr_ref(argv[i]));
		BOOST_CHECK_EQUAL(a.get(), pa.get(i));
		BOOST_CHECK_EQUAL(a.get(), pa[i]);

		++i;
		a = a.next();
	}
}

BOOST_AUTO_TEST_SUITE_END()
