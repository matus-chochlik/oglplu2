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

template <std::size_t N>
void do_test_byteset_1(const eagine::byteset<N>& bs)
{
	using namespace eagine;

	BOOST_CHECK_EQUAL(bs.size(), N);

	for(auto& b : bs) {
		BOOST_CHECK((b >= 0x00) && (b <= 0xFF));
	}

	using iter = typename eagine::byteset<N>::const_iterator;
	for(iter i = bs.begin(); i!=bs.end(); ++i) {
		BOOST_CHECK((*i >= 0x00) && (*i <= 0xFF));
	}

	using sz_t = typename eagine::byteset<N>::size_type;
	for(sz_t i = 0; i < bs.size(); ++i) {
		BOOST_CHECK((bs[i] >= 0x00) && (bs[i] <= 0xFF));
	}
}

BOOST_AUTO_TEST_CASE(byteset_1)
{
	using namespace eagine;

	for(int i=0; i<100; ++i) {
		do_test_byteset_1(byteset<1>{
			rg.get_byte(0x00, 0xFF)
		});
		do_test_byteset_1(byteset<2>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		});
		do_test_byteset_1(byteset<3>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		});
		do_test_byteset_1(byteset<4>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		});
		do_test_byteset_1(byteset<8>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		});
		do_test_byteset_1(byteset<11>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		});
		do_test_byteset_1(byteset<16>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
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
			rg.get_byte(0x00, 0xFF)
		},byteset<1>{
			rg.get_byte(0x00, 0xFF)
		});

		do_test_byteset_2(byteset<2>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		},byteset<2>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		});

		do_test_byteset_2(byteset<4>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		},byteset<4>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		});

		do_test_byteset_2(byteset<5>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		},byteset<5>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		});

		do_test_byteset_2(byteset<13>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		},byteset<13>{
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF),
			rg.get_byte(0x00, 0xFF)
		});
	}
}

BOOST_AUTO_TEST_SUITE_END()
