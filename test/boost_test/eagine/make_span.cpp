/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/span.hpp>
#define BOOST_TEST_MODULE EAGINE_make_span
#include "../unit_test_begin.inl"

#include <array>
#include <vector>

BOOST_AUTO_TEST_SUITE(make_span_tests)

static eagine::test_random_generator rg;

BOOST_AUTO_TEST_CASE(make_span_ptr_size) {
    using namespace eagine;

    float fv[5] = {1.f, 2.f, 3.f, 4.f, 5.f};

    span<float> vf = make_span(fv, 5);
    BOOST_CHECK(vf.size() == 5);
    BOOST_CHECK(vf.data() == fv);

    const float cfv[5] = {6.f, 7.f, 8.f, 9.f, 0.f};

    span<const float> vcf = make_span(cfv, 3);
    BOOST_CHECK(vcf.size() == 3);
    BOOST_CHECK(vcf.data() == cfv);
}

BOOST_AUTO_TEST_CASE(make_span_carray) {
    using namespace eagine;

    float fv[4] = {1.f, 2.f, 3.f, 4.f};

    span<float> vf = make_span(fv);
    BOOST_CHECK(vf.size() == sizeof(fv) / sizeof(fv[0]));
    BOOST_CHECK(vf.data() == fv);

    const float cfv[4] = {5.f, 6.f, 7.f, 8.f};

    span<const float> vcf = make_span(cfv);
    BOOST_CHECK(vcf.size() == sizeof(cfv) / sizeof(cfv[0]));
    BOOST_CHECK(vcf.data() == cfv);
}

BOOST_AUTO_TEST_CASE(make_span_init_list) {
    using namespace eagine;

    span<const float> vf = make_span({1.f, 2.f, 3.f, 4.f});
    BOOST_CHECK(vf.size() == 4);
    BOOST_CHECK(vf[0] == 1.f);
    BOOST_CHECK(vf[1] == 2.f);
    BOOST_CHECK(vf[2] == 3.f);
    BOOST_CHECK(vf[3] == 4.f);
}

BOOST_AUTO_TEST_CASE(make_span_std_vector) {
    using namespace eagine;

    std::vector<int> v;

    for(int i = 0, n = rg.get_int(10, 100); i < n; ++i) {
	v.push_back(rg.get_any<int>());
    }

    span<int> vi = make_span(v);
    BOOST_CHECK_EQUAL(vi.size(), v.size());

    for(std::size_t l = 0; l < v.size(); ++l) {
	BOOST_CHECK(vi[span_size(l)] == v[l]);
    }

    const std::vector<int>& vr = v;

    span<const int> cvi = make_span(vr);
    BOOST_CHECK_EQUAL(cvi.size(), vr.size());

    for(std::size_t l = 0; l < vr.size(); ++l) {
	BOOST_CHECK(cvi[span_size(l)] == vr[l]);
    }
}

BOOST_AUTO_TEST_CASE(make_span_std_array) {
    using namespace eagine;

    std::array<int, 100> a;

    for(std::size_t l = 0; l < a.size(); ++l) {
	a[l] = rg.get_any<int>();
    }

    span<int> vi = make_span(a);
    BOOST_CHECK_EQUAL(vi.size(), a.size());

    for(std::size_t l = 0; l < a.size(); ++l) {
	BOOST_CHECK(vi[span_size(l)] == a[l]);
    }

    const std::array<int, 100>& ar = a;

    span<const int> cvi = make_span(ar);
    BOOST_CHECK_EQUAL(cvi.size(), ar.size());

    for(std::size_t l = 0; l < ar.size(); ++l) {
	BOOST_CHECK(cvi[span_size(l)] == ar[l]);
    }
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
