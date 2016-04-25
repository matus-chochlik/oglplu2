/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_posix_dir_descriptor
#include <boost/test/unit_test.hpp>

#include <eagine/config/platform.hpp>
#if EAGINE_POSIX
#include <eagine/posix/dir_descriptor.hpp>
#endif

BOOST_AUTO_TEST_SUITE(posix_dir_descriptor_tests)

#if EAGINE_POSIX

BOOST_AUTO_TEST_CASE(posix_dir_descriptor_1)
{
	using namespace eagine;

	posix::dir_descriptor dd;

	BOOST_CHECK(!dd.is_valid());
	BOOST_CHECK(!bool(dd));
	BOOST_CHECK(!dd);

	posix::dir_descriptor ddc = dd;

	BOOST_CHECK(!ddc.is_valid());
	BOOST_CHECK(!bool(ddc));
	BOOST_CHECK(!ddc);
}

BOOST_AUTO_TEST_CASE(posix_dir_descriptor_2)
{
	using namespace eagine;

	std::intptr_t fake_dp[3] = {16, 32, 64};
	::DIR** dp = reinterpret_cast< ::DIR**>(fake_dp);

	for(int i=0; i<3; ++i)
	{
		posix::dir_descriptor dd(dp[i]);

		BOOST_CHECK(dd.is_valid());
		BOOST_CHECK(bool(dd));
		BOOST_CHECK(!!dd);
		BOOST_CHECK_EQUAL(get_raw_dp(dd), dp[i]);

		posix::dir_descriptor ddc1 = dd;

		BOOST_CHECK(ddc1.is_valid());
		BOOST_CHECK(bool(ddc1));
		BOOST_CHECK(!!ddc1);
		BOOST_CHECK_EQUAL(get_raw_dp(ddc1), dp[i]);

		posix::dir_descriptor ddc2, ddc3;

		BOOST_CHECK(!ddc2.is_valid());
		BOOST_CHECK(!bool(ddc2));
		BOOST_CHECK(!ddc2);

		ddc2 = ddc1;

		BOOST_CHECK(ddc2.is_valid());
		BOOST_CHECK(bool(ddc2));
		BOOST_CHECK(!!ddc2);
		BOOST_CHECK_EQUAL(get_raw_dp(ddc2), dp[i]);

		ddc3 = std::move(ddc1);

		BOOST_CHECK(!ddc1.is_valid());
		BOOST_CHECK(!bool(ddc1));
		BOOST_CHECK(!ddc1);

		BOOST_CHECK(ddc3.is_valid());
		BOOST_CHECK(bool(ddc3));
		BOOST_CHECK(!!ddc3);
		BOOST_CHECK_EQUAL(get_raw_dp(ddc3), dp[i]);
	}
}

#else // EAGINE_POSIX

BOOST_AUTO_TEST_CASE(dummy_test_case) { }

#endif // EAGINE_POSIX

BOOST_AUTO_TEST_SUITE_END()
