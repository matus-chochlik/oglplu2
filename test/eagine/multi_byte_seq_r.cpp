/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE EAGINE_multi_byte_seq
#include <boost/test/unit_test.hpp>

#include <eagine/multi_byte_seq.hpp>
#include <vector>
#include <cstdlib>

BOOST_AUTO_TEST_SUITE(multi_byte_seq_tests)

BOOST_AUTO_TEST_CASE(multi_byte_seq_1)
{
	using namespace eagine;

	std::vector<byte> bytes;

	mbs::code_point_t cp = 0, cp2;

	for(std::size_t l=1; l<=6; ++l)
	{
		bytes.resize(l);
		while(cp < mbs::max_code_point(l))
		{
			BOOST_CHECK(mbs::encode_code_point(cp, as_span(bytes)));
			BOOST_CHECK(mbs::is_valid_encoding(as_span(bytes)));

			cp2 = mbs::decode_code_point(as_span(bytes)).value();

			BOOST_CHECK_EQUAL(cp, cp2);

			cp += 1+mbs::code_point_t(std::rand())%(l*l*l*l);
		}
	}
}

BOOST_AUTO_TEST_CASE(multi_byte_seq_2)
{
	using namespace eagine;

	std::vector<mbs::code_point> cps, cps2;
	std::vector<byte> bytes;

	for(int i=0; i<10000; ++i)
	{
		std::size_t len = std::size_t(1+std::rand()%100);
		cps.resize(len);

		for(mbs::code_point& cp : cps)
		{
			do { cp = mbs::code_point_t(std::rand()); }
			while(!cp.is_valid());
		}

		bytes.resize(mbs::encoding_bytes_required(as_span(cps)).value());

		BOOST_CHECK(mbs::encode_code_points(as_span(cps), as_span(bytes)));

		BOOST_ASSERT(mbs::is_valid_encoding(as_span(bytes)));

		cps2.resize(mbs::decoding_code_points_required(as_span(bytes)).value());

		BOOST_ASSERT(cps.size() == cps2.size());

		BOOST_CHECK(mbs::decode_code_points(as_span(bytes), as_span(cps2)));

		BOOST_CHECK(as_span(cps) == as_span(cps2));
	}

}

BOOST_AUTO_TEST_SUITE_END()
