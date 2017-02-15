/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/mem_func_const.hpp>
#define BOOST_TEST_MODULE EAGINE_mem_func_const
#include "../unit_test.inl"

#include <type_traits>

struct bar
{
	int i;

	int foo(int j) const
	{
		return i+j;
	}

	float foo(int j, float k)
	{
		return (i+j)/k;
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
};

BOOST_AUTO_TEST_SUITE(mem_func_const_tests)

BOOST_AUTO_TEST_CASE(mem_func_const_pointer_get)
{
	using namespace eagine;

	typedef member_function_constant<int(bar::*)(int) const, &bar::foo> fubar1;
	typedef member_function_constant<float(bar::*)(int,float), &bar::foo> fubar2;
	typedef member_function_constant<baz&(baz::*)(void), &baz::inc> incbaz;

	fubar1::pointer pfubar1 = fubar1::get();
	fubar2::pointer pfubar2 = fubar2::get();
	incbaz::pointer pincbaz = incbaz::get();

	bar br{432};

	BOOST_CHECK_EQUAL(((br).*(pfubar1))(543), 432+543);
	BOOST_CHECK_EQUAL(((br).*(pfubar2))(543, 654.3f), (432+543)/654.3f);

	baz bz{1};

	BOOST_CHECK_EQUAL(bz.i, 1);
	((bz).*(pincbaz))();
	BOOST_CHECK_EQUAL(bz.i, 2);

}

BOOST_AUTO_TEST_CASE(mem_func_const_scope)
{
	using namespace eagine;

	typedef member_function_constant<int(bar::*)(int) const, &bar::foo> fubar1;
	typedef member_function_constant<float(bar::*)(int,float), &bar::foo> fubar2;
	typedef member_function_constant<baz&(baz::*)(void), &baz::inc> incbaz;

	BOOST_CHECK(( std::is_same<bar, fubar1::scope>::value));
	BOOST_CHECK(( std::is_same<bar, fubar2::scope>::value));
	BOOST_CHECK((!std::is_same<baz, fubar1::scope>::value));
	BOOST_CHECK((!std::is_same<baz, fubar2::scope>::value));
	BOOST_CHECK((!std::is_same<bar, incbaz::scope>::value));
	BOOST_CHECK(( std::is_same<baz, incbaz::scope>::value));
}

BOOST_AUTO_TEST_CASE(mem_func_const_make_free)
{
	using namespace eagine;

	typedef member_function_constant<int(bar::*)(int) const, &bar::foo> fubar1;
	typedef member_function_constant<float(bar::*)(int,float), &bar::foo> fubar2;
	typedef member_function_constant<baz&(baz::*)(void), &baz::inc> incbaz;

	bar br{123};

	BOOST_CHECK_EQUAL(fubar1::make_free()(&br, 234), 123+234);
	BOOST_CHECK_EQUAL(fubar2::make_free()(&br, 234, 345.6f), (123+234)/345.6f);

	baz bz{1};
	BOOST_CHECK_EQUAL(bz.i, 1);
	incbaz::make_free()(&bz);
	BOOST_CHECK_EQUAL(bz.i, 2);

}

BOOST_AUTO_TEST_SUITE_END()
