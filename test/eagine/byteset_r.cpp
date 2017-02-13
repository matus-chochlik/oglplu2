/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_byteset

#include <eagine/byteset.hpp>

#include <cstring>
#include <boost/test/unit_test.hpp>
#include "../random.hpp"

BOOST_AUTO_TEST_SUITE(byteset_tests)

static eagine::test_random_generator rg;

constexpr const unsigned char bmin = 0x04;
constexpr const unsigned char bmax = 0x3F;

template <std::size_t N>
void do_test_byteset_1(const eagine::byteset<N>& bs)
{
	using namespace eagine;

	BOOST_CHECK_EQUAL(bs.size(), N);

	for(auto& b : bs) {
		BOOST_CHECK((b >= bmin) && (b <= bmax));
	}

	using iter = typename eagine::byteset<N>::const_iterator;
	for(iter i = bs.begin(); i!=bs.end(); ++i) {
		BOOST_CHECK((*i >= bmin) && (*i <= bmax));
	}

	using sz_t = typename eagine::byteset<N>::size_type;
	for(sz_t i = 0; i < bs.size(); ++i) {
		BOOST_CHECK((bs[i] >= bmin) && (bs[i] <= bmax));
	}
}

BOOST_AUTO_TEST_CASE(byteset_1)
{
	using namespace eagine;

	for(int i=0; i<100; ++i) {
		do_test_byteset_1(byteset<1>{
			rg.get_byte(bmin, bmax)
		});
		do_test_byteset_1(byteset<2>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_byteset_1(byteset<3>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_byteset_1(byteset<4>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_byteset_1(byteset<8>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_byteset_1(byteset<11>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_byteset_1(byteset<16>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
	}
}

template <std::size_t N>
void do_test_byteset_2(
	const eagine::byteset<N>& bs1,
	const eagine::byteset<N>& bs2
)
{
	using namespace eagine;

	BOOST_CHECK_EQUAL(
		(bs1 == bs2),
		(std::memcmp(bs1.data(), bs2.data(), N) == 0)
	);
	BOOST_CHECK_EQUAL(
		(bs1 != bs2),
		(std::memcmp(bs1.data(), bs2.data(), N) != 0)
	);
	BOOST_CHECK_EQUAL(
		(bs1 <  bs2),
		(std::memcmp(bs1.data(), bs2.data(), N) <  0)
	);
	BOOST_CHECK_EQUAL(
		(bs1 <= bs2),
		(std::memcmp(bs1.data(), bs2.data(), N) <= 0)
	);
	BOOST_CHECK_EQUAL(
		(bs1 >  bs2),
		(std::memcmp(bs1.data(), bs2.data(), N) >  0)
	);
	BOOST_CHECK_EQUAL(
		(bs1 >= bs2),
		(std::memcmp(bs1.data(), bs2.data(), N) >= 0)
	);
}

BOOST_AUTO_TEST_CASE(byteset_2)
{
	using namespace eagine;

	for(int i=0; i<100; ++i) {
		do_test_byteset_2(byteset<1>{
			rg.get_byte(bmin, bmax)
		},byteset<1>{
			rg.get_byte(bmin, bmax)
		});

		do_test_byteset_2(byteset<2>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		},byteset<2>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});

		do_test_byteset_2(byteset<4>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		},byteset<4>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});

		do_test_byteset_2(byteset<5>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		},byteset<5>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});

		do_test_byteset_2(byteset<13>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		},byteset<13>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
	}
}

BOOST_AUTO_TEST_SUITE_END()
