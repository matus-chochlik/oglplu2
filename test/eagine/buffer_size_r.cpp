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
#include <eagine/span.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(buffer_size_tests)

static inline
std::size_t get_n(void)
{
	return std::size_t(std::rand() % 1000000);
}

BOOST_AUTO_TEST_CASE(buffer_size_1)
{
	using namespace eagine;

	buffer_size<int> s0;
	BOOST_CHECK_EQUAL(int(s0), 0);
	BOOST_CHECK_EQUAL(long(s0), 0l);
	BOOST_CHECK_EQUAL(std::size_t(s0), 0u);

	buffer_size<int> s1(12345);
	BOOST_CHECK_EQUAL(int(s1), 12345);
	BOOST_CHECK_EQUAL(long(s1), 12345l);
	BOOST_CHECK_EQUAL(std::size_t(s1), 12345u);
}

BOOST_AUTO_TEST_CASE(buffer_size_2)
{
	using namespace eagine;
	std::size_t n;
	{
		n = get_n();
		buffer_size<int> st(identity<char>(), n);
		BOOST_CHECK_EQUAL(st.get(), int(sizeof(char)*n));
		BOOST_CHECK_EQUAL(int(st), int(sizeof(char)*n));
	}
	{
		n = get_n();
		buffer_size<int> st(identity<short>(), n);
		BOOST_CHECK_EQUAL(st.get(), int(sizeof(short)*n));
		BOOST_CHECK_EQUAL(int(st), int(sizeof(short)*n));
	}
	{
		n = get_n();
		buffer_size<int> st(identity<unsigned>(), n);
		BOOST_CHECK_EQUAL(st.get(), int(sizeof(unsigned)*n));
		BOOST_CHECK_EQUAL(int(st), int(sizeof(unsigned)*n));
	}
	{
		n = get_n();
		buffer_size<int> st(identity<long>(), n);
		BOOST_CHECK_EQUAL(st.get(), int(sizeof(long)*n));
		BOOST_CHECK_EQUAL(int(st), int(sizeof(long)*n));
	}
	{
		n = get_n();
		buffer_size<int> st(identity<float>(), n);
		BOOST_CHECK_EQUAL(st.get(), int(sizeof(float)*n));
		BOOST_CHECK_EQUAL(int(st), int(sizeof(float)*n));
	}
}

BOOST_AUTO_TEST_CASE(buffer_size_3)
{
	using namespace eagine;
	std::size_t n;
	{
		n = get_n();
		buffer_size<unsigned> st(identity<char>(), n);
		BOOST_CHECK_EQUAL(unsigned(st), unsigned(sizeof(char)*n));
	}
	{
		n = get_n();
		buffer_size<unsigned> st(identity<short>(), n);
		BOOST_CHECK_EQUAL(unsigned(st), unsigned(sizeof(short)*n));
	}
	{
		n = get_n();
		buffer_size<unsigned> st(identity<int>(), n);
		BOOST_CHECK_EQUAL(unsigned(st), unsigned(sizeof(int)*n));
	}
	{
		n = get_n();
		buffer_size<unsigned> st(identity<long>(), n);
		BOOST_CHECK_EQUAL(unsigned(st), unsigned(sizeof(long)*n));
	}
	{
		n = get_n();
		buffer_size<unsigned> st(identity<float>(), n);
		BOOST_CHECK_EQUAL(unsigned(st), unsigned(sizeof(float)*n));
	}
}

BOOST_AUTO_TEST_CASE(buffer_size_4)
{
	using namespace eagine;
	{
		const char bla[4] = "bla";
		buffer_size<int> st(as_span(bla));
		BOOST_CHECK_EQUAL(st.get(), int(sizeof(char)*4));
		BOOST_CHECK_EQUAL(int(st), int(sizeof(char)*4));
	}
	{
		const unsigned short csv[7] = {1,2,3,4,5,6,7};
		buffer_size<long> st(as_span(csv));
		BOOST_CHECK_EQUAL(st.get(), long(sizeof(short)*7));
		BOOST_CHECK_EQUAL(long(st), long(sizeof(short)*7));
	}
	{
		const int civ[10] = {0,1,2,3,4,5,6,7,8,9};
		buffer_size<unsigned> st(as_span(civ));
		BOOST_CHECK_EQUAL(st.get(), unsigned(sizeof(int)*10));
		BOOST_CHECK_EQUAL(unsigned(st), unsigned(sizeof(int)*10));
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
