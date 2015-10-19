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
#include <vector>
#include <array>

BOOST_AUTO_TEST_SUITE(make_view)

BOOST_AUTO_TEST_CASE(make_view_default)
{
	using namespace eagine;

	array_view<int> vi = eagine::make_view<int>();
	BOOST_CHECK(vi.size() == 0);

	array_view<const int> vci = eagine::make_view<const int>();
	BOOST_CHECK(vci.size() == 0);
}

BOOST_AUTO_TEST_CASE(make_view_ptr_size)
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

BOOST_AUTO_TEST_CASE(make_view_carray)
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

BOOST_AUTO_TEST_CASE(make_view_init_list)
{
	using namespace eagine;

	array_view<const float> vf = eagine::make_view({1.f, 2.f, 3.f, 4.f});
	BOOST_CHECK(vf.size() == 4);
	BOOST_CHECK(vf[0] == 1.f);
	BOOST_CHECK(vf[1] == 2.f);
	BOOST_CHECK(vf[2] == 3.f);
	BOOST_CHECK(vf[3] == 4.f);
}

BOOST_AUTO_TEST_CASE(make_view_std_vector)
{
	using namespace eagine;

	std::vector<int> v;

	for(int i=0, n=10+std::rand()%100; i<n; ++i)
	{	
		v.push_back(std::rand());
	}

	array_view<int> vi = eagine::make_view(v);
	BOOST_CHECK(vi.size() == v.size());

	for(std::size_t l=0; l<v.size(); ++l)
	{
		BOOST_CHECK(vi[l] == v[l]);
	}

	const std::vector<int>& vr = v;

	array_view<const int> cvi = eagine::make_view(vr);
	BOOST_CHECK(cvi.size() == vr.size());

	for(std::size_t l=0; l<vr.size(); ++l)
	{
		BOOST_CHECK(cvi[l] == vr[l]);
	}
}

BOOST_AUTO_TEST_CASE(make_view_std_array)
{
	using namespace eagine;

	std::array<int, 100> a;

	for(std::size_t l=0; l<a.size(); ++l)
	{	
		a[l] = std::rand();
	}

	array_view<int> vi = eagine::make_view(a);
	BOOST_CHECK(vi.size() == a.size());

	for(std::size_t l=0; l<a.size(); ++l)
	{
		BOOST_CHECK(vi[l] == a[l]);
	}

	const std::array<int, 100>& ar = a;

	array_view<const int> cvi = eagine::make_view(ar);
	BOOST_CHECK(cvi.size() == ar.size());

	for(std::size_t l=0; l<ar.size(); ++l)
	{
		BOOST_CHECK(cvi[l] == ar[l]);
	}
}

BOOST_AUTO_TEST_SUITE_END()
