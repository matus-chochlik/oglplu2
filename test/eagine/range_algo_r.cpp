/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_range_algo
#include <boost/test/unit_test.hpp>

#include <eagine/range_algo.hpp>
#include <eagine/span.hpp>
#include <eagine/cstr_ref.hpp>
#include <cstdlib>
#include <vector>

BOOST_AUTO_TEST_SUITE(range_algo_tests)

template <typename T>
void test_range_slice_r_p_s_1(
	eagine::span<T> rng,
	eagine::span_size_type p,
	eagine::span_size_type s
)
{
	using namespace eagine;

	span<T> slc = ranges::slice(rng, p, s);

	span_size_type n = slc.size();

	BOOST_CHECK(slc.size() <= rng.size());
	BOOST_CHECK(slc.size() <= s);

	for(span_size_type i=0; i<n; ++i)
	{
		BOOST_CHECK_EQUAL(rng[p+i], slc[i]);
	}
}

template <typename T>
void test_range_slice_r_p_s_1(eagine::span<T> rng)
{
	using namespace eagine;

	test_range_slice_r_p_s_1(rng, 0, 0);
	test_range_slice_r_p_s_1(rng, 0, rng.size()/2);
	test_range_slice_r_p_s_1(rng, 0, rng.size());
	test_range_slice_r_p_s_1(rng, 0, rng.size()*2);

	test_range_slice_r_p_s_1(rng, rng.size()/2, 0);
	test_range_slice_r_p_s_1(rng, rng.size()/2, rng.size()/2);
	test_range_slice_r_p_s_1(rng, rng.size()/2, rng.size());
	test_range_slice_r_p_s_1(rng, rng.size()/2, rng.size()*2);

	test_range_slice_r_p_s_1(rng, rng.size()*2, 0);
	test_range_slice_r_p_s_1(rng, rng.size()*2, rng.size()/2);
	test_range_slice_r_p_s_1(rng, rng.size()*2, rng.size());
	test_range_slice_r_p_s_1(rng, rng.size()*2, rng.size()*2);

	for(int i=0; i<100; ++i)
	{
		test_range_slice_r_p_s_1(
			rng,
			span_size_type(std::rand()%(rng.size()*2)),
			span_size_type(std::rand()%(rng.size()*2))
		);
	}
}

template <typename T>
void test_range_slice_r_p_s_1(T min, T max)
{
	for(int i=0; i<10; ++i)
	{
		std::vector<T> v(20+std::rand()%80);
		for(T& x : v)
		{
			x = T(min + (std::rand()%(max-min)));
		}
		test_range_slice_r_p_s_1(eagine::as_span(v));
	}
}

BOOST_AUTO_TEST_CASE(range_algo_slice_r_p_s_1)
{
	using namespace eagine;

	test_range_slice_r_p_s_1<char>('A','Z');
	test_range_slice_r_p_s_1<int>(-100000, 100000);
}

template <typename T>
void test_range_slice_r_p_1(eagine::span<T> rng, eagine::span_size_type p)
{
	using namespace eagine;

	span<T> slc = ranges::slice(rng, p);

	span_size_type n = slc.size();

	BOOST_CHECK(slc.size() <= rng.size());

	for(span_size_type i=0; i<n; ++i)
	{
		BOOST_CHECK_EQUAL(rng[p+i], slc[i]);
	}
}

template <typename T>
void test_range_slice_r_p_1(eagine::span<T> rng)
{
	using namespace eagine;

	test_range_slice_r_p_1(rng, 0);
	test_range_slice_r_p_1(rng, rng.size()/2);
	test_range_slice_r_p_1(rng, rng.size());
	test_range_slice_r_p_1(rng, rng.size()*2);

	for(int i=0; i<100; ++i)
	{
		test_range_slice_r_p_1(
			rng,
			span_size_type(std::rand()%(rng.size()*2))
		);
	}
}

template <typename T>
void test_range_slice_r_p_1(T min, T max)
{
	for(int i=0; i<10; ++i)
	{
		std::vector<T> v(20+std::rand()%80);
		for(T& x : v)
		{
			x = T(min + (std::rand()%(max-min)));
		}
		test_range_slice_r_p_1(eagine::as_span(v));
	}
}

BOOST_AUTO_TEST_CASE(range_algo_slice_r_p_1)
{
	using namespace eagine;

	test_range_slice_r_p_1<char>('A','Z');
	test_range_slice_r_p_1<int>(-100000, 100000);
}

template <typename T>
void test_range_head_1(eagine::span<T> rng, eagine::span_size_type l)
{
	using namespace eagine;

	span<T> rng2 = ranges::head(rng, l);

	span_size_type n = rng2.size();

	BOOST_CHECK(rng2.size() <= rng.size());

	for(span_size_type i=0; i<n; ++i)
	{
		BOOST_CHECK_EQUAL(rng[i], rng2[i]);
	}
}

template <typename T>
void test_range_head_1(eagine::span<T> rng)
{
	using namespace eagine;

	test_range_head_1(rng, 0);
	test_range_head_1(rng, rng.size()/2);
	test_range_head_1(rng, rng.size());
	test_range_head_1(rng, rng.size()*2);

	for(int i=0; i<100; ++i)
	{
		test_range_head_1(
			rng,
			span_size_type(std::rand()%(rng.size()*2))
		);
	}
}

template <typename T>
void test_range_head_1(T min, T max)
{
	for(int i=0; i<10; ++i)
	{
		std::vector<T> v(20+std::rand()%80);
		for(T& x : v)
		{
			x = T(min + (std::rand()%(max-min)));
		}
		test_range_head_1(eagine::as_span(v));
	}
}

BOOST_AUTO_TEST_CASE(range_algo_head_1)
{
	using namespace eagine;

	test_range_head_1<char>('A','Z');
	test_range_head_1<int>(-100000, 100000);
}

template <typename T>
void test_range_tail_1(eagine::span<T> rng, eagine::span_size_type l)
{
	using namespace eagine;

	span<T> rng2 = ranges::tail(rng, l);

	span_size_type n = rng2.size();

	BOOST_CHECK(rng2.size() <= rng.size());

	span_size_type p = rng.size() - l;
	if(p < 0) p = 0;

	for(span_size_type i=0; i<n; ++i)
	{
		BOOST_CHECK_EQUAL(rng[p+i], rng2[i]);
	}
}

template <typename T>
void test_range_tail_1(eagine::span<T> rng)
{
	using namespace eagine;

	test_range_tail_1(rng, 0);
	test_range_tail_1(rng, rng.size()/2);
	test_range_tail_1(rng, rng.size());
	test_range_tail_1(rng, rng.size()*2);

	for(int i=0; i<100; ++i)
	{
		test_range_tail_1(
			rng,
			span_size_type(std::rand()%(rng.size()*2))
		);
	}
}

template <typename T>
void test_range_tail_1(T min, T max)
{
	for(int i=0; i<10; ++i)
	{
		std::vector<T> v(20+std::rand()%80);
		for(T& x : v)
		{
			x = T(min + (std::rand()%(max-min)));
		}
		test_range_tail_1(eagine::as_span(v));
	}
}

BOOST_AUTO_TEST_CASE(range_algo_tail_1)
{
	using namespace eagine;

	test_range_tail_1<char>('A','Z');
	test_range_tail_1<int>(-100000, 100000);
}

BOOST_AUTO_TEST_SUITE_END()
