/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/callable_ref.hpp>
#define BOOST_TEST_MODULE EAGINE_callable_ref
#include "../unit_test.inl"

#include <type_traits>

float foo(float a, float b, float c)
{
	return (a-b)/(a+c);
}

struct bar
{
	int i;

	int foo(int j) const
	{
		return i+j;
	}

	float foo(float j, float k, float l) const
	{
		return (i+j)/(k-l);
	}

	static
	float foo(bar* b, float j, float k, float l)
	{
		return b->foo(j,k,l);
	}

	float operator ()(float a, float b, float c)
	{
		return foo(a,b,c);
	}
};

struct baz
{
	int i;

	baz& inc(void)
	{
		++i;
		return *this;
	}

	baz& add(int c)
	{
		i += c;
		return *this;
	}
};

BOOST_AUTO_TEST_SUITE(callable_ref_tests)

BOOST_AUTO_TEST_CASE(callable_ref_foo_0)
{
	using namespace eagine;

	callable_ref<float(float, float, float)> cr0;

	BOOST_CHECK(bool(cr0) == false);
	BOOST_CHECK(!(cr0) == true);
}

BOOST_AUTO_TEST_CASE(callable_ref_foo_1)
{
	using namespace eagine;

	callable_ref<float(float, float, float)> cr1(&::foo);

	BOOST_CHECK(bool(cr1) == true);
	BOOST_CHECK(!(cr1) == false);

	BOOST_CHECK_EQUAL(cr1(234.5f,345.6f,456.7f), foo(234.5f,345.6f,456.7f));
}

BOOST_AUTO_TEST_CASE(callable_ref_foo_2)
{
	using namespace eagine;

	bar br{123};

	callable_ref<float(float, float, float)> cr2(&br, &bar::foo);

	BOOST_CHECK(bool(cr2) == true);
	BOOST_CHECK(!(cr2) == false);

	BOOST_CHECK_EQUAL(cr2(234.5f,345.6f,456.7f), bar::foo(&br, 234.5f,345.6f,456.7f));
}

BOOST_AUTO_TEST_CASE(callable_ref_foo_3)
{
	using namespace eagine;

	bar br{123};

	callable_ref<float(float, float, float)> cr3(br, &bar::foo);

	BOOST_CHECK(bool(cr3) == true);
	BOOST_CHECK(!(cr3) == false);

	BOOST_CHECK_EQUAL(cr3(345.6f,456.7f,567.8f), bar::foo(&br, 345.6f,456.7f,567.8f));
}

BOOST_AUTO_TEST_CASE(callable_ref_foo_4)
{
	using namespace eagine;

	bar br{123};

	callable_ref<float(float, float, float)> cr4(br);

	BOOST_CHECK(bool(cr4) == true);
	BOOST_CHECK(!(cr4) == false);

	BOOST_CHECK_EQUAL(cr4(456.7f,567.8f,678.9f), br(456.7f,567.8f,678.9f));
}

BOOST_AUTO_TEST_CASE(callable_ref_foo_5)
{
	using namespace eagine;

	bar br{123};

	callable_ref<float(float, float, float)> cr5(
		&br,
		member_function_constant<
			float(bar::*)(float,float,float) const,
			&bar::foo
		>()
	);

	BOOST_CHECK(bool(cr5) == true);
	BOOST_CHECK(!(cr5) == false);

	BOOST_CHECK_EQUAL(cr5(567.8f,678.9f,789.0f), br.foo(567.8f,678.9f,789.0f));
}

BOOST_AUTO_TEST_CASE(callable_ref_baz_1)
{
	using namespace eagine;

	baz bz{2};
	callable_ref<baz&(void)> cr(
		&bz,
		member_function_constant<baz&(baz::*)(void), &baz::inc>()
	);

	BOOST_CHECK(bool(cr) == true);
	BOOST_CHECK(!(cr) == false);

	BOOST_CHECK_EQUAL(bz.i, 2);
	cr();
	BOOST_CHECK_EQUAL(bz.i, 3);
	cr();
	BOOST_CHECK_EQUAL(bz.i, 4);
}

BOOST_AUTO_TEST_CASE(callable_ref_baz_2)
{
	using namespace eagine;

	baz bz{3};

	callable_ref<baz&(int)> cr(
		&bz,
		member_function_constant<baz&(baz::*)(int), &baz::add>()
	);

	BOOST_CHECK(bool(cr) == true);
	BOOST_CHECK(!(cr) == false);

	BOOST_CHECK_EQUAL(bz.i, 3);
	cr(3);
	BOOST_CHECK_EQUAL(bz.i, 6);
	cr(2);
	BOOST_CHECK_EQUAL(bz.i, 8);
}

BOOST_AUTO_TEST_SUITE_END()
