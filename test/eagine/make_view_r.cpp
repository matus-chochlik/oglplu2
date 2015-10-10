/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_make_view
#include <boost/test/unit_test.hpp>

#include <eagine/make_view.hpp>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(make_view)

BOOST_AUTO_TEST_CASE(make_view_1)
{
	using namespace eagine;

	array_view<int> vi = eagine::make_view<int>();
	BOOST_CHECK(vi.size() == 0);

	array_view<const int> vci = eagine::make_view<const int>();
	BOOST_CHECK(vci.size() == 0);
}

BOOST_AUTO_TEST_CASE(make_view_2)
{
	using namespace eagine;

	float fv[5] = {1.f, 2.f, 3.f, 4.f, 5.f};

	array_view<float> vf = eagine::make_view(fv, 5);
	BOOST_CHECK(vf.size() == 5);
	BOOST_CHECK(vf.data() == fv);

	const float cfv[5] = {6.f, 7.f, 8.f, 9.f, 0.f};

	array_view<const float> vcf = eagine::make_view(cfv, 3);
	BOOST_CHECK(vcf.size() == 3);
	BOOST_CHECK(vcf.data() == cfv);
}

BOOST_AUTO_TEST_CASE(make_view_3)
{
	using namespace eagine;

	float fv[4] = {1.f, 2.f, 3.f, 4.f};

	array_view<float> vf = eagine::make_view(fv);
	BOOST_CHECK(vf.size() == sizeof(fv)/sizeof(fv[0]));
	BOOST_CHECK(vf.data() == fv);

	const float cfv[4] = {5.f, 6.f, 7.f, 8.f};

	array_view<const float> vcf = eagine::make_view(cfv);
	BOOST_CHECK(vcf.size() == sizeof(cfv)/sizeof(cfv[0]));
	BOOST_CHECK(vcf.data() == cfv);
}

// TODO

BOOST_AUTO_TEST_SUITE_END()
