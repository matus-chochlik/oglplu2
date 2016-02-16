/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OALPLUS_context_attribs
#include <boost/test/unit_test.hpp>

#include <oalplus/al.hpp>
#include <oalplus/context_attribs.hpp>
#include <oalplus/enum/value_defs_alc.inl>

BOOST_AUTO_TEST_SUITE(context_attribs_tests)

BOOST_AUTO_TEST_CASE(context_attribs_1)
{
	using namespace oalplus;

	enum_values_alc ALC;

	context_attribs<0> a0;
	BOOST_CHECK_EQUAL(a0.size(), 1);
	BOOST_CHECK_EQUAL(a0.size(), a0.get().size());

	context_attribs<2> a2 = a0+(ALC.frequency|22000);
	BOOST_CHECK_EQUAL(a2.size(), 3);
	BOOST_CHECK_EQUAL(a2.size(), a2.get().size());

	context_attribs<4> a4 = a2+(ALC.refresh|1000);
	BOOST_CHECK_EQUAL(a4.size(), 5);
	BOOST_CHECK_EQUAL(a4.size(), a4.get().size());

	context_attribs<6> a6 = a4+(ALC.stereo_sources|10);
	BOOST_CHECK_EQUAL(a6.size(), 7);
	BOOST_CHECK_EQUAL(a6.size(), a6.get().size());

	context_attribs<8> a8 = a6+(ALC.mono_sources|5);
	BOOST_CHECK_EQUAL(a8.size(), 9);
	BOOST_CHECK_EQUAL(a8.size(), a8.get().size());

	context_attribs<10> a10 = a8+(ALC.sync|true);
	BOOST_CHECK_EQUAL(a10.size(), 11);
	BOOST_CHECK_EQUAL(a10.size(), a10.get().size());

	const ALint cmp [11] = {
		ALC_FREQUENCY, 22000,
		ALC_REFRESH, 1000,
		ALC_STEREO_SOURCES, 10,
		ALC_MONO_SOURCES, 5,
		ALC_SYNC, ALC_TRUE,
		0
	};

	for(int i=0; i<11; ++i)
	{
		BOOST_CHECK_EQUAL(a10.get()[i], cmp[i]);
	}

}

BOOST_AUTO_TEST_SUITE_END()

// TODO
