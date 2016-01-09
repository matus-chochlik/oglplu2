/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_buffer_data
#include <boost/test/unit_test.hpp>

#include <eagine/buffer_data.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(buffer_data_tests)

BOOST_AUTO_TEST_CASE(buffer_data_1)
{
	using namespace eagine;

	buffer_data_spec<int> bd;
	BOOST_CHECK(bd.empty());
	BOOST_CHECK(int(bd.size()) == 0);
	BOOST_CHECK(long(bd.size()) == 0l);
	BOOST_CHECK(std::size_t(bd.size()) == 0u);
}

BOOST_AUTO_TEST_CASE(buffer_data_2)
{
	using namespace eagine;

	{
		const long clv[8] = {0,1,2,3,4,5,6,7};

		buffer_data_spec<int> bd(clv);
		BOOST_CHECK(!bd.empty());
		BOOST_CHECK(bd.data() != nullptr);
		BOOST_CHECK(bd.data() == static_cast<const void*>(clv));
		BOOST_CHECK(int(bd.size()) == int(sizeof(long)*8));
		BOOST_CHECK(unsigned(bd.size()) == unsigned(sizeof(long)*8));
	}

	{
		float fv[10] = {0,1,2,3,4,5,6,7,8,9};

		buffer_data_spec<long> bd(fv);
		BOOST_CHECK(!bd.empty());
		BOOST_CHECK(bd.data() != nullptr);
		BOOST_CHECK(bd.data() == static_cast<const void*>(fv));
		BOOST_CHECK(long(bd.size()) == long(sizeof(float)*10));
	}
}

BOOST_AUTO_TEST_CASE(buffer_data_3)
{
	using namespace eagine;

	{
		buffer_data_spec<int> bd;
		span<const byte> v = bd.view();

		BOOST_CHECK(v.begin() == v.end());
	}

	{
		const short csv[8] = {0,1,2,3,4,5,6,7};

		buffer_data_spec<short> bd(csv);
		span<const byte> v = bd.view();

		BOOST_CHECK(v.begin() != v.end());
	}

	{
		double fv[9] = {1,2,3,4,5,6,7,8,9};

		buffer_data_spec<unsigned> bd(fv);
		span<const byte> v = bd.view();

		BOOST_CHECK(v.begin() != v.end());
	}
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
