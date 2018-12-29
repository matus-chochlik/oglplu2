/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/math/coordinates.hpp>
#define BOOST_TEST_MODULE EAGINE_math_functions
#include "../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(math_function_tests)

static eagine::test_random_generator rg;

template <typename T, bool V>
static inline void test_eagine_math_coord_spherical_cartesian_roundtrip() {
    using namespace eagine::math;
    using eagine::radians_;
    using std::abs;

    for(int i = 0; i < 1000; ++i) {

        auto azim = radians_(rg.get<T>(-T(pi), T(pi)));
        auto elev = radians_(rg.get<T>(-T(pi / 2), T(pi / 2)));

        unit_spherical_coordinates<T, V> orig(azim, elev);
        auto calc = to_unit_spherical(to_cartesian(orig));

        BOOST_CHECK_CLOSE(
          orig.elevation().value(), calc.elevation().value(), 0.1);
        const auto diff = abs(elev.value()) - T(90);
        if(diff > T(0)) {
            BOOST_CHECK_CLOSE(
              orig.azimuth().value(), calc.azimuth().value(), 0.1);
        }
    }
}

BOOST_AUTO_TEST_CASE(math_coord_spherical_cartesian_roundtrip) {
    test_eagine_math_coord_spherical_cartesian_roundtrip<float, true>();
    test_eagine_math_coord_spherical_cartesian_roundtrip<float, false>();
    test_eagine_math_coord_spherical_cartesian_roundtrip<double, true>();
    test_eagine_math_coord_spherical_cartesian_roundtrip<double, false>();
}

template <typename T, bool V>
static inline void test_eagine_math_coord_cartesian_spherical_roundtrip() {
    using namespace eagine::math;
    using std::abs;

    for(int i = 0; i < 1000; ++i) {

        auto x = rg.get<T>(-1, 1);
        auto y = rg.get<T>(-1, 1);
        auto z = rg.get<T>(-1, 1);

        auto orig = normalized(vector<T, 3, V>::make(x, y, z));
        auto calc = to_cartesian(to_unit_spherical(orig));

        BOOST_CHECK_CLOSE(orig.x(), calc.x(), 0.1);
        BOOST_CHECK_CLOSE(orig.y(), calc.y(), 0.1);
        BOOST_CHECK_CLOSE(orig.z(), calc.z(), 0.1);
    }
}

BOOST_AUTO_TEST_CASE(math_coord_cartesian_spherical_roundtrip) {
    test_eagine_math_coord_cartesian_spherical_roundtrip<float, true>();
    test_eagine_math_coord_cartesian_spherical_roundtrip<float, false>();
    test_eagine_math_coord_cartesian_spherical_roundtrip<double, true>();
    test_eagine_math_coord_cartesian_spherical_roundtrip<double, false>();
}

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
