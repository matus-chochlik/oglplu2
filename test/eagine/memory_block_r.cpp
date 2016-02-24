/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_memory_block
#include <boost/test/unit_test.hpp>

#include <eagine/memory_block.hpp>
#include <cstdlib>
#include <vector>

BOOST_AUTO_TEST_SUITE(memory_block_tests)

template <bool is_const>
void eagine_test_memory_block_0(void)
{
	using namespace eagine;

	basic_memory_block<is_const> bmb;

	BOOST_CHECK(!bool(bmb));
	BOOST_CHECK(!bmb);
	BOOST_CHECK(bmb.empty());
	BOOST_CHECK(bmb.size() == 0);
	BOOST_CHECK(bmb.begin() == bmb.end());
}

BOOST_AUTO_TEST_CASE(memory_block_0)
{
	using namespace eagine;

	eagine_test_memory_block_0<true>();
	eagine_test_memory_block_0<false>();
}

template <bool is_const>
void eagine_test_memory_block_1(void)
{
	using namespace eagine;

	basic_memory_block<false> bmb1;
	basic_memory_block<is_const> bmb2 = bmb1;

	BOOST_CHECK(!bool(bmb2));
	BOOST_CHECK(!bmb2);
	BOOST_CHECK(bmb2.empty());
	BOOST_CHECK(bmb2.size() == 0);
	BOOST_CHECK(bmb2.begin() == bmb2.end());
}

BOOST_AUTO_TEST_CASE(memory_block_1)
{
	using namespace eagine;

	eagine_test_memory_block_1<true>();
	eagine_test_memory_block_1<false>();
}

template <bool is_const>
void eagine_test_memory_block_2(void)
{
	using namespace eagine;

	int x;

	basic_memory_block<is_const> bmb = memory::block_of(x);

	BOOST_CHECK(bool(bmb));
	BOOST_CHECK(!!bmb);
	BOOST_CHECK(!bmb.empty());
	BOOST_CHECK(bmb.size() == sizeof(x));
	BOOST_CHECK(bmb.begin() != bmb.end());

	std::size_t s = 0;

	for(byte b : bmb) { ++s; (void)b; }

	BOOST_CHECK(bmb.size() == s);
}

BOOST_AUTO_TEST_CASE(memory_block_2)
{
	using namespace eagine;

	eagine_test_memory_block_2<true>();
	eagine_test_memory_block_2<false>();
}

template <bool is_const>
void eagine_test_memory_block_3(void)
{
	using namespace eagine;

	double x[42];

	basic_memory_block<is_const> bmb = memory::block_of(x);

	BOOST_CHECK(bool(bmb));
	BOOST_CHECK(!!bmb);
	BOOST_CHECK(!bmb.empty());
	BOOST_CHECK(bmb.size() == sizeof(x));
	BOOST_CHECK(bmb.begin() != bmb.end());

	std::size_t s = 0;

	for(byte b : bmb) { ++s; (void)b; }

	BOOST_CHECK(bmb.size() == s);
}

BOOST_AUTO_TEST_CASE(memory_block_3)
{
	using namespace eagine;

	eagine_test_memory_block_3<true>();
	eagine_test_memory_block_3<false>();
}

template <bool is_const>
void eagine_test_memory_block_4(void)
{
	using namespace eagine;

	double x[42];

	basic_memory_block<is_const> bmb(x, 42);

	BOOST_CHECK(bool(bmb));
	BOOST_CHECK(!!bmb);
	BOOST_CHECK(!bmb.empty());
	BOOST_CHECK(bmb.size() == sizeof(x));
	BOOST_CHECK(bmb.begin() != bmb.end());

	std::size_t s = 0;

	for(byte b : bmb) { ++s; (void)b; }

	BOOST_CHECK(bmb.size() == s);
}

BOOST_AUTO_TEST_CASE(memory_block_4)
{
	using namespace eagine;

	eagine_test_memory_block_4<true>();
	eagine_test_memory_block_4<false>();
}

template <bool is_const>
void eagine_test_memory_block_5(void)
{
	using namespace eagine;

	byte x[256];

	for(byte& b : x)
	{
		b = byte(std::rand() % 0xFF);
	}

	basic_memory_block<is_const> bmb = memory::block_of(x);

	BOOST_CHECK(bool(bmb));
	BOOST_CHECK(!!bmb);
	BOOST_CHECK(!bmb.empty());
	BOOST_ASSERT(bmb.size() == sizeof(x));

	for(std::size_t i=0; i<bmb.size(); ++i)
	{
		BOOST_CHECK_EQUAL(bmb.data()[i], x[i]);
	}
}

BOOST_AUTO_TEST_CASE(memory_block_5)
{
	using namespace eagine;

	eagine_test_memory_block_5<true>();
	eagine_test_memory_block_5<false>();
}

template <bool is_const>
void eagine_test_memory_block_6(void)
{
	using namespace eagine;

	unsigned x[10];

	basic_memory_block<is_const> bmb1 = memory::block_of(x);

	BOOST_CHECK(bool(bmb1));
	BOOST_CHECK(!!bmb1);
	BOOST_CHECK(!bmb1.empty());

	basic_memory_block<is_const> bmb2(std::move(bmb1));

	BOOST_CHECK(!bool(bmb1));
	BOOST_CHECK(!bmb1);
	BOOST_CHECK( bmb1.empty());
	BOOST_CHECK(!bmb2.empty());

	basic_memory_block<is_const> bmb3;

	BOOST_CHECK( bmb3.empty());

	bmb3 = std::move(bmb2);

	BOOST_CHECK( bmb2.empty());
	BOOST_CHECK(!bmb3.empty());

	basic_memory_block<is_const> bmb4 = memory_block_of(x);

	BOOST_CHECK(bmb1 == bmb2);
	BOOST_CHECK(bmb2 != bmb3);
	BOOST_CHECK(bmb3 == bmb4);
}

BOOST_AUTO_TEST_CASE(memory_block_6)
{
	using namespace eagine;

	eagine_test_memory_block_6<true>();
	eagine_test_memory_block_6<false>();
}

template <typename T>
void eagine_test_memory_block_7(void)
{
	using namespace eagine;

	std::vector<unsigned char> x(100 + std::rand() % 1000);

	memory_block b(x.data(), x.size());

	span<T> s = as_span_of<T>(b);

	BOOST_CHECK_EQUAL(s.size(), x.size()/sizeof(T));
}

BOOST_AUTO_TEST_CASE(memory_block_7)
{
	for(int i=0; i<100; ++i)
	{
		eagine_test_memory_block_7<char>();
		eagine_test_memory_block_7<short>();
		eagine_test_memory_block_7<float>();
		eagine_test_memory_block_7<int>();
		eagine_test_memory_block_7<long>();
		eagine_test_memory_block_7<double>();
	}
}

template <typename T>
void eagine_test_memory_block_8(void)
{
	using namespace eagine;

	std::vector<T> x(100 + std::rand() % 1000);

	memory_block b = eagine::memory::data_block_of(x);

	BOOST_CHECK_EQUAL(b.size(), x.size()*sizeof(T));
}

BOOST_AUTO_TEST_CASE(memory_block_8)
{
	for(int i=0; i<100; ++i)
	{
		eagine_test_memory_block_8<char>();
		eagine_test_memory_block_8<short>();
		eagine_test_memory_block_8<float>();
		eagine_test_memory_block_8<int>();
		eagine_test_memory_block_8<long>();
		eagine_test_memory_block_8<double>();
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
