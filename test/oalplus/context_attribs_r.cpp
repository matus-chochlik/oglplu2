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

	typedef context_attrib_value cav;
	enum_values_alc ALC;

	context_attribs<0> a0;
	BOOST_CHECK_EQUAL(a0.size(), 1);
	BOOST_CHECK_EQUAL(a0.size(), a0.get().size());

	context_attribs<2> a2 = a0.append(cav(ALC.refresh,3000));
	BOOST_CHECK_EQUAL(a2.size(), 3);
	BOOST_CHECK_EQUAL(a2.size(), a2.get().size());


	context_attribs<4> a4 = a2.append(cav(ALC.frequency,44000));
	BOOST_CHECK_EQUAL(a4.size(), 5);
	BOOST_CHECK_EQUAL(a4.size(), a4.get().size());

	context_attribs<6> a6 = a4.append(cav(ALC.mono_sources,5));
	BOOST_CHECK_EQUAL(a6.size(), 7);
	BOOST_CHECK_EQUAL(a6.size(), a6.get().size());

	context_attribs<8> a8 = a6.append(cav(ALC.stereo_sources,6));
	BOOST_CHECK_EQUAL(a8.size(), 9);
	BOOST_CHECK_EQUAL(a8.size(), a8.get().size());

	context_attribs<10> a10 = a8.append(cav(ALC.sync,ALC_FALSE));
	BOOST_CHECK_EQUAL(a10.size(), 11);
	BOOST_CHECK_EQUAL(a10.size(), a10.get().size());

	const ALint cmp [11] = {
		ALC_REFRESH, 3000,
		ALC_FREQUENCY, 44000,
		ALC_MONO_SOURCES, 5,
		ALC_STEREO_SOURCES, 6,
		ALC_SYNC, ALC_FALSE,
		0
	};

	for(int i=0; i<11; ++i)
	{
		BOOST_CHECK_EQUAL(a10.get()[i], cmp[i]);
	}

}

BOOST_AUTO_TEST_CASE(context_attribs_2)
{
	using namespace oalplus;

	enum_values_alc ALC;

	context_attribs<0> a0;
	BOOST_CHECK_EQUAL(a0.size(), 1);
	BOOST_CHECK_EQUAL(a0.size(), a0.get().size());

	context_attribs<2> a2 = a0.append(ALC.frequency|11000);
	BOOST_CHECK_EQUAL(a2.size(), 3);
	BOOST_CHECK_EQUAL(a2.size(), a2.get().size());

	context_attribs<4> a4 = a2.append(ALC.refresh|2000);
	BOOST_CHECK_EQUAL(a4.size(), 5);
	BOOST_CHECK_EQUAL(a4.size(), a4.get().size());

	context_attribs<6> a6 = a4.append(ALC.stereo_sources|3);
	BOOST_CHECK_EQUAL(a6.size(), 7);
	BOOST_CHECK_EQUAL(a6.size(), a6.get().size());

	context_attribs<8> a8 = a6.append(ALC.mono_sources|9);
	BOOST_CHECK_EQUAL(a8.size(), 9);
	BOOST_CHECK_EQUAL(a8.size(), a8.get().size());

	context_attribs<10> a10 = a8.append(ALC.sync|false);
	BOOST_CHECK_EQUAL(a10.size(), 11);
	BOOST_CHECK_EQUAL(a10.size(), a10.get().size());

	const ALint cmp [11] = {
		ALC_FREQUENCY, 11000,
		ALC_REFRESH, 2000,
		ALC_STEREO_SOURCES, 3,
		ALC_MONO_SOURCES, 9,
		ALC_SYNC, ALC_FALSE,
		0
	};

	for(int i=0; i<11; ++i)
	{
		BOOST_CHECK_EQUAL(a10.get()[i], cmp[i]);
	}

}

BOOST_AUTO_TEST_CASE(context_attribs_3)
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
