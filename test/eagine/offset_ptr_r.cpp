/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_offset_ptr
#include <boost/test/unit_test.hpp>

#include <eagine/offset_ptr.hpp>
#include <string>
#include <cstring>


BOOST_AUTO_TEST_SUITE(offset_ptr_tests)

BOOST_AUTO_TEST_CASE(offset_ptr_default_ctr)
{
	using namespace eagine;

	offset_ptr<double> p0;

	BOOST_CHECK_EQUAL(bool(p0), false);
	BOOST_CHECK_EQUAL(!p0, true);
	BOOST_CHECK_EQUAL(!!p0, false);

	BOOST_CHECK(p0.get() == nullptr);
	BOOST_CHECK(p0.addr() == memory::const_address());
	BOOST_CHECK(p0.addr().value() == 0);
	BOOST_CHECK(static_cast<double*>(p0) == p0.get());
}

BOOST_AUTO_TEST_CASE(offset_ptr_2)
{
	using namespace eagine;

	std::string str("blahbleh");

	offset_ptr<const std::string> ps(&str);

	BOOST_CHECK_EQUAL(bool(ps), true);
	BOOST_CHECK_EQUAL(!ps, false);
	BOOST_CHECK_EQUAL(!!ps, true);

	BOOST_ASSERT(ps.get() == &str);
	BOOST_CHECK(ps.addr() == memory::const_address(&str));
	BOOST_CHECK(static_cast<const std::string*>(ps) == ps.get());

	BOOST_CHECK_EQUAL(*ps, str);
	BOOST_CHECK_EQUAL(ps->size(), str.size());
}

BOOST_AUTO_TEST_CASE(offset_ptr_3)
{
	using namespace eagine;

	std::string str("foobarbaz");
	offset_ptr<std::string> ops(&str);

	offset_ptr<std::string> ps(ops);

	BOOST_CHECK_EQUAL(bool(ps), true);
	BOOST_CHECK_EQUAL(!ps, false);
	BOOST_CHECK_EQUAL(!!ps, true);

	BOOST_CHECK(ps.addr() == ops.addr());
	BOOST_ASSERT(ps.get() == &str);
	BOOST_CHECK(ps.addr() == memory::const_address(&str));
	BOOST_CHECK(static_cast<const std::string*>(ps) == ps.get());

	BOOST_CHECK_EQUAL(*ps, str);
	BOOST_CHECK_EQUAL(ps->size(), str.size());
}

BOOST_AUTO_TEST_CASE(offset_array_default_ctr)
{
	using namespace eagine;

	offset_array<long> a0;

	BOOST_CHECK(a0.data() == nullptr);
	BOOST_CHECK(a0.addr() == memory::const_address());
	BOOST_CHECK(a0.size() == 0);
	BOOST_CHECK(a0.begin() == a0.end());
}

BOOST_AUTO_TEST_CASE(offset_array_2)
{
	using namespace eagine;

	double da[10] = {0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};

	offset_array<double> ad(da, 10);

	BOOST_CHECK(ad.data() == da);
	BOOST_CHECK(ad.addr() == memory::const_address(da));
	BOOST_CHECK(ad.size() == 10);
	BOOST_CHECK(ad.begin() != ad.end());

	offset_array<double>::size_type i = 0;
	for(double d : ad)
	{
		BOOST_CHECK_EQUAL(d, i);
		++i;
	}

	for(i=0; i<10; ++i)
	{
		BOOST_CHECK_EQUAL(ad[i], i);
	}
}

BOOST_AUTO_TEST_CASE(offset_array_3)
{
	using namespace eagine;

	const char* cstr = "FooBarBazBlah";

	offset_array<const char> acc(cstr, std::strlen(cstr));

	BOOST_CHECK(acc.data() == cstr);
	BOOST_CHECK(acc.addr() == memory::const_address(cstr));
	BOOST_CHECK(acc.size() == std::strlen(cstr));
	BOOST_CHECK(acc.begin() != acc.end());

	offset_array<double>::size_type i = 0;
	for(char c : acc)
	{
		BOOST_CHECK_EQUAL(c, cstr[i]);
		++i;
	}

	for(i=0; i<acc.size(); ++i)
	{
		BOOST_CHECK_EQUAL(acc[i], cstr[i]);
	}
}

BOOST_AUTO_TEST_CASE(offset_array_4)
{
	using namespace eagine;

	int ia[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

	const offset_array<int> cai(ia, 20);

	BOOST_CHECK(cai.data() == ia);
	BOOST_CHECK(cai.addr() == memory::const_address(ia));
	BOOST_CHECK(cai.size() == 20);
	BOOST_CHECK(cai.begin() != cai.end());

	offset_array<double>::size_type i = 0;
	for(int x: cai)
	{
		BOOST_CHECK_EQUAL(x, ++i);
	}

	for(i=0; i<cai.size(); ++i)
	{
		BOOST_CHECK_EQUAL(cai[i], ia[i]);
	}
}

// TODO
BOOST_AUTO_TEST_SUITE_END()
