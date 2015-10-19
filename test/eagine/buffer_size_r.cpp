/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_buffer_size
#include <boost/test/unit_test.hpp>

#include <eagine/buffer_size.hpp>
#include <eagine/make_view.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(buffer_size)

static inline
std::size_t get_n(void)
{
	return std::size_t(std::rand() % 1000000);
}

BOOST_AUTO_TEST_CASE(buffer_size_1)
{
	using namespace eagine;

	eagine::buffer_size<int> s0;
	BOOST_CHECK(int(s0) == 0);
	BOOST_CHECK(long(s0) == 0l);
	BOOST_CHECK(std::size_t(s0) == 0u);

	eagine::buffer_size<int> s1(12345);
	BOOST_CHECK(int(s1) == 12345);
	BOOST_CHECK(long(s1) == 12345l);
	BOOST_CHECK(std::size_t(s1) == 12345u);
}

BOOST_AUTO_TEST_CASE(buffer_size_2)
{
	using namespace eagine;
	std::size_t n;
	{
		n = get_n();
		eagine::buffer_size<int> st(identity<char>(), n);
		BOOST_CHECK(int(st) == int(sizeof(char)*n));
	}
	{
		n = get_n();
		eagine::buffer_size<int> st(identity<short>(), n);
		BOOST_CHECK(int(st) == int(sizeof(short)*n));
	}
	{
		n = get_n();
		eagine::buffer_size<int> st(identity<unsigned>(), n);
		BOOST_CHECK(int(st) == int(sizeof(unsigned)*n));
	}
	{
		n = get_n();
		eagine::buffer_size<int> st(identity<long>(), n);
		BOOST_CHECK(int(st) == int(sizeof(long)*n));
	}
	{
		n = get_n();
		eagine::buffer_size<int> st(identity<float>(), n);
		BOOST_CHECK(int(st) == int(sizeof(float)*n));
	}
}

BOOST_AUTO_TEST_CASE(buffer_size_3)
{
	using namespace eagine;
	std::size_t n;
	{
		n = get_n();
		eagine::buffer_size<unsigned> st(identity<char>(), n);
		BOOST_CHECK(unsigned(st) == unsigned(sizeof(char)*n));
	}
	{
		n = get_n();
		eagine::buffer_size<unsigned> st(identity<short>(), n);
		BOOST_CHECK(unsigned(st) == unsigned(sizeof(short)*n));
	}
	{
		n = get_n();
		eagine::buffer_size<unsigned> st(identity<int>(), n);
		BOOST_CHECK(unsigned(st) == unsigned(sizeof(int)*n));
	}
	{
		n = get_n();
		eagine::buffer_size<unsigned> st(identity<long>(), n);
		BOOST_CHECK(unsigned(st) == unsigned(sizeof(long)*n));
	}
	{
		n = get_n();
		eagine::buffer_size<unsigned> st(identity<float>(), n);
		BOOST_CHECK(unsigned(st) == unsigned(sizeof(float)*n));
	}
}

BOOST_AUTO_TEST_CASE(buffer_size_4)
{
	using namespace eagine;
	{
		const char bla[4] = "bla";
		eagine::buffer_size<int> st(make_view(bla));
		BOOST_CHECK(int(st) == int(sizeof(char)*4));
	}
	{
		const unsigned short csv[7] = {1,2,3,4,5,6,7};
		eagine::buffer_size<long> st(make_view(csv));
		BOOST_CHECK(long(st) == long(sizeof(short)*7));
	}
	{
		const int civ[10] = {0,1,2,3,4,5,6,7,8,9};
		eagine::buffer_size<unsigned> st(make_view(civ));
		BOOST_CHECK(unsigned(st) == unsigned(sizeof(int)*10));
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
