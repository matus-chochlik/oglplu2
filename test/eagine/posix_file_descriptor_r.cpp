/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_posix_file_descriptor
#include <boost/test/unit_test.hpp>

#include <eagine/config/platform.hpp>
#if EAGINE_POSIX
#include <eagine/posix/file_descriptor.hpp>
#endif

BOOST_AUTO_TEST_SUITE(posix_file_descriptor_tests)

#if EAGINE_POSIX

BOOST_AUTO_TEST_CASE(posix_file_descriptor_1)
{
	using namespace eagine;

	posix::file_descriptor fd;

	BOOST_CHECK(!fd.is_valid());
	BOOST_CHECK(!bool(fd));
	BOOST_CHECK(!fd);

	posix::file_descriptor fdc = fd;

	BOOST_CHECK(!fdc.is_valid());
	BOOST_CHECK(!bool(fdc));
	BOOST_CHECK(!fdc);
}

BOOST_AUTO_TEST_CASE(posix_file_descriptor_2)
{
	using namespace eagine;

	for(int i=0; i<3; ++i)
	{
		posix::file_descriptor fd(i);

		BOOST_CHECK(fd.is_valid());
		BOOST_CHECK(bool(fd));
		BOOST_CHECK(!!fd);
		BOOST_CHECK_EQUAL(get_raw_fd(fd), i);

		posix::file_descriptor fdc1 = fd;

		BOOST_CHECK(fdc1.is_valid());
		BOOST_CHECK(bool(fdc1));
		BOOST_CHECK(!!fdc1);
		BOOST_CHECK_EQUAL(get_raw_fd(fdc1), i);

		posix::file_descriptor fdc2, fdc3;

		BOOST_CHECK(!fdc2.is_valid());
		BOOST_CHECK(!bool(fdc2));
		BOOST_CHECK(!fdc2);

		fdc2 = fdc1;

		BOOST_CHECK(fdc2.is_valid());
		BOOST_CHECK(bool(fdc2));
		BOOST_CHECK(!!fdc2);
		BOOST_CHECK_EQUAL(get_raw_fd(fdc2), i);

		fdc3 = std::move(fdc1);

		BOOST_CHECK(!fdc1.is_valid());
		BOOST_CHECK(!bool(fdc1));
		BOOST_CHECK(!fdc1);

		BOOST_CHECK(fdc3.is_valid());
		BOOST_CHECK(bool(fdc3));
		BOOST_CHECK(!!fdc3);
		BOOST_CHECK_EQUAL(get_raw_fd(fdc3), i);
	}
}

BOOST_AUTO_TEST_CASE(posix_file_descriptor_3)
{
	using namespace eagine;

	for(int i=0; i<3; ++i)
	{
		posix::file_descriptor fd(i);

		posix::owned_file_descriptor fdc1(dup(fd));

		BOOST_CHECK(fdc1.is_valid());
		BOOST_CHECK(bool(fdc1));
		BOOST_CHECK(!!fdc1);

		BOOST_CHECK(get_raw_fd(fd) != get_raw_fd(fdc1));

		posix::owned_file_descriptor fdc2(dup(fdc1));

		BOOST_CHECK(fdc2.is_valid());
		BOOST_CHECK(bool(fdc2));
		BOOST_CHECK(!!fdc2);

		posix::close(fdc1);

		BOOST_CHECK(!fdc1.is_valid());
		BOOST_CHECK(!bool(fdc1));
		BOOST_CHECK(!fdc1);

		BOOST_CHECK(fdc2.is_valid());
		BOOST_CHECK(bool(fdc2));
		BOOST_CHECK(!!fdc2);

		posix::owned_file_descriptor fdc3(std::move(fdc2));

		BOOST_CHECK(!fdc2.is_valid());
		BOOST_CHECK(!bool(fdc2));
		BOOST_CHECK(!fdc2);

		BOOST_CHECK(fdc3.is_valid());
		BOOST_CHECK(bool(fdc3));
		BOOST_CHECK(!!fdc3);

		posix::close(fdc3);
	}
}

// TODO: read write

#else // EAGINE_POSIX

BOOST_AUTO_TEST_CASE(dummy_test_case) { }

#endif // EAGINE_POSIX

BOOST_AUTO_TEST_SUITE_END()
