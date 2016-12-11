/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_memoized
#include <boost/test/unit_test.hpp>

#include <eagine/memoized.hpp>
#include "../random.hpp"

BOOST_AUTO_TEST_SUITE(memoized_tests)

static eagine::test_random_generator rg;

unsigned long fib_calc(unsigned long n)
{
	unsigned long m[3] = {1,1,2};
	if (n < 3) return m[n];
	short i = 0;
	while(true)
	{
		m[i%3] = m[(i+1)%3]+m[(i+2)%3];
		if(n <= 3) break;
		++i;
		--n;
	}
	return m[i%3];
}

BOOST_AUTO_TEST_CASE(memoized_fib)
{
	using namespace eagine;

	typedef unsigned long N;

	memoized<N(N)> fib_memo(
		[](N _n, eagine::memoized<N(N)>& m) -> N {
			if(_n < 2) return 1;
			return m(_n, [](N n, auto& f){return f(n-2)+f(n-1);});
		}
	);

	for(int j=0; j<20; ++j)
	{
		for(unsigned long i=0; i<90; ++i)
		{
			BOOST_CHECK_EQUAL(fib_calc(i), fib_memo(i));
		}
		if(j%3 == 1) fib_memo.clear();
	}

	unsigned long f[90];
	for(unsigned long i=0; i<90; ++i)
	{
		f[i] = fib_memo(i);
	}

	for(unsigned long i=0; i<90; ++i)
	{
		BOOST_CHECK_EQUAL(f[i], fib_memo(i));
	}

	for(unsigned long i=0; i<90; ++i)
	{
		fib_memo.reset(i);
	}

	for(unsigned long i=0; i<90; ++i)
	{
		BOOST_CHECK_EQUAL(f[i], fib_memo(i));
	}
}

unsigned long fact_calc(unsigned n)
{
	unsigned long r = n;
	while(n-- > 1) r *= n;
	return r;
}

BOOST_AUTO_TEST_CASE(memoized_fact)
{
	typedef unsigned M;
	typedef unsigned long N;

	using namespace eagine;

	memoized<N(M)> fact_memo(
		[](M _n, eagine::memoized<N(M)>& m) -> N {
			if(_n < 2) return _n;
			return m(_n, [](M n, auto& f){return n*f(n-1);});
		}
	);
	for(int j=0; j<20; ++j)
	{
		for(unsigned i=0; i<22; ++i)
		{
			BOOST_CHECK_EQUAL(fact_calc(i), fact_memo(i));
		}
		if(j%7 == 1) fact_memo.clear();
	}
}

unsigned long exp_calc(unsigned x, unsigned e)
{
	unsigned long r = 1;
	while(e-- > 0) r *= x;
	return r;
}

BOOST_AUTO_TEST_CASE(memoized_exp)
{
	using namespace eagine;

	typedef unsigned M;
	typedef unsigned long N;

	memoized<N(M,M)> exp_memo(
		[](M _x, M _e, eagine::memoized<N(M,M)>& m) -> N {
			if(_e == 0) return 1;
			auto l = [](M x, M e, auto& f){return x*f(x,e-1);};
			return m(_x, _e, l);
		}
	);

	for(int j=0; j<10; ++j)
	{
		for(unsigned i=0; i<64; ++i)
		{
			BOOST_CHECK_EQUAL(exp_calc(2,i), exp_memo(2,i));
		}
	}

	for(int j=0; j<1000; ++j)
	{
		unsigned x = rg.get_uint(0, 20);
		unsigned e = rg.get_uint(0, 20-x);
		BOOST_CHECK_EQUAL(exp_calc(x,e), exp_memo(x,e));
	}
}

BOOST_AUTO_TEST_SUITE_END()
