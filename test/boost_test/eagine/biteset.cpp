/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/biteset.hpp>
#define BOOST_TEST_MODULE EAGINE_biteset
#include "../unit_test_begin.inl"

#include <algorithm>

BOOST_AUTO_TEST_SUITE(biteset_tests)

static eagine::test_random_generator rg;

constexpr const unsigned char bmin = 0x02;
constexpr const unsigned char bmax = 0x0F;

template <std::size_t N, std::size_t B>
void do_test_biteset_1(const eagine::biteset<N, B>& bs)
{
	using namespace eagine;

	BOOST_CHECK_EQUAL(bs.size(), N);

	using sz_t = typename eagine::biteset<N, B>::size_type;
	for(sz_t i = 0; i < bs.size(); ++i) {
		BOOST_CHECK((bs[i] >= bmin) && (bs[i] <= bmax));
	}
}

template <std::size_t B>
void test_biteset_1(void) {
	using namespace eagine;

	for(int i=0; i<100; ++i) {
		do_test_biteset_1(biteset<1, B>{
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_1(biteset<2, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_1(biteset<3, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_1(biteset<4, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_1(biteset<8, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_1(biteset<11, B>{
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
		do_test_biteset_1(biteset<16, B>{
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

BOOST_AUTO_TEST_CASE(biteset_1)
{
	test_biteset_1<4>();
	test_biteset_1<5>();
	test_biteset_1<6>();
	test_biteset_1<7>();
	test_biteset_1<8>();
	test_biteset_1<9>();
	test_biteset_1<11>();
}

template <std::size_t N, std::size_t B>
void do_test_biteset_2(
	const eagine::biteset<N, B>& bs1,
	const eagine::biteset<N, B>& bs2
)
{
	using namespace eagine;

	BOOST_CHECK_EQUAL(
		(bs1 == bs2),
		(bs1.bytes() == bs2.bytes())
	);
	BOOST_CHECK_EQUAL(
		(bs1 != bs2),
		(bs1.bytes() != bs2.bytes())
	);
	BOOST_CHECK_EQUAL(
		(bs1 <  bs2),
		(bs1.bytes() <  bs2.bytes())
	);
	BOOST_CHECK_EQUAL(
		(bs1 <= bs2),
		(bs1.bytes() <= bs2.bytes())
	);
	BOOST_CHECK_EQUAL(
		(bs1 >  bs2),
		(bs1.bytes() >  bs2.bytes())
	);
	BOOST_CHECK_EQUAL(
		(bs1 >= bs2),
		(bs1.bytes() >= bs2.bytes())
	);
}

template <std::size_t B>
void test_biteset_2(void)
{
	using namespace eagine;

	for(int i=0; i<100; ++i) {
		do_test_biteset_2(biteset<1, B>{
			rg.get_byte(bmin, bmax)
		},biteset<1, B>{
			rg.get_byte(bmin, bmax)
		});

		do_test_biteset_2(biteset<2, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		},biteset<2, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});

		do_test_biteset_2(biteset<4, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		},biteset<4, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});

		do_test_biteset_2(biteset<5, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		},biteset<5, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});

		do_test_biteset_2(biteset<13, B>{
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
		},biteset<13, B>{
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

BOOST_AUTO_TEST_CASE(biteset_2)
{
	test_biteset_2<4>();
	test_biteset_2<5>();
	test_biteset_2<6>();
	test_biteset_2<7>();
	test_biteset_2<8>();
	test_biteset_2<9>();
	test_biteset_2<13>();
}

template <std::size_t N, std::size_t B, typename T>
void do_test_biteset_3(eagine::biteset<N, B, T>&& bs)
{
	using namespace eagine;
	using sz_t = typename eagine::biteset<N, B>::size_type;

	eagine::biteset<N, B, T> bs2;

	sz_t i;
	for(i = 0; i < bs.size(); ++i) {
		bs2.set(i, bs.get(i));
	}

	i = 0;
	for(T c : bs2) {
		BOOST_CHECK_EQUAL(c, bs[i++]);
	}

	BOOST_CHECK(bs == bs2);

	for(i = 0; i < bs.size(); ++i) {
		T v = T((i+1) % (1<<B));
		bs.set(i, v); 
		BOOST_CHECK_EQUAL(bs.get(i), v);
	}

	for(i = 0; i < bs.size(); ++i) {
		T v = T((i+1) % (1<<B));
		bs[i] = v;
		BOOST_CHECK_EQUAL(bs.get(i), v);
	}

	i = 0;
	for(auto c : bs) {
		T v = T(++i % (1<<B));
		BOOST_CHECK_EQUAL(c, v);
		v = T((i*7) % (1<<B));
		c = v;
		BOOST_CHECK_EQUAL(c, v);
	}

	for(i = 0; i < bs.size(); ++i) {
		T v = T((i+1)*7 % (1<<B));
		BOOST_CHECK_EQUAL(bs.get(i), v);
	}
}

template <std::size_t B>
void test_biteset_3(void)
{
	using namespace eagine;

	for(int i=0; i<100; ++i) {
		do_test_biteset_3(biteset<1, B>{
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_3(biteset<2, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_3(biteset<3, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_3(biteset<4, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_3(biteset<5, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_3(biteset<8, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_3(biteset<13, B>{
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
		do_test_biteset_3(biteset<15, B>{
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

BOOST_AUTO_TEST_CASE(biteset_3)
{
	test_biteset_3<4>();
	test_biteset_3<5>();
	test_biteset_3<6>();
	test_biteset_3<7>();
	test_biteset_3<8>();
	test_biteset_3<9>();
	test_biteset_3<12>();
}

template <std::size_t N, std::size_t B, typename T>
void do_test_biteset_4(eagine::biteset<N, B, T>&& bs)
{
	std::sort(bs.begin(), bs.end());

	const eagine::biteset<N, B, T>& cbs = bs;

	BOOST_CHECK(std::is_sorted(cbs.begin(), cbs.end()));
}

template <std::size_t B>
void test_biteset_4(void)
{
	using namespace eagine;

	for(int i=0; i<100; ++i) {
		do_test_biteset_4(biteset<1, B>{
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_4(biteset<2, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_4(biteset<3, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_4(biteset<4, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_4(biteset<5, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_4(biteset<8, B>{
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax),
			rg.get_byte(bmin, bmax)
		});
		do_test_biteset_4(biteset<13, B>{
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
		do_test_biteset_4(biteset<15, B>{
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

BOOST_AUTO_TEST_CASE(biteset_4)
{
	test_biteset_4<4>();
	test_biteset_4<5>();
	test_biteset_4<6>();
	test_biteset_4<7>();
	test_biteset_4<8>();
	test_biteset_4<9>();
	test_biteset_4<13>();
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
