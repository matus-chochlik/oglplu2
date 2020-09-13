/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/units/base_dim.hpp>
#define BOOST_TEST_MODULE EAGINE_units_base_dim
#include "../unit_test_begin.inl"

#include <algorithm>

BOOST_AUTO_TEST_SUITE(units_base_dim_tests)

BOOST_AUTO_TEST_CASE(units_base_dim_number) {
    using namespace eagine::units;

    int dim_nums[] = {
      get_number(base::angle()),
      get_number(base::solid_angle()),
      get_number(base::length()),
      get_number(base::mass()),
      get_number(base::time()),
      get_number(base::temperature()),
      get_number(base::electric_current()),
      get_number(base::number_of_cycles()),
      get_number(base::number_of_decays()),
      get_number(base::luminous_intensity()),
      get_number(base::amount_of_substance()),
      get_number(base::amount_of_information())};

    using std::begin;
    using std::end;
    using std::unique;

    BOOST_CHECK(unique(begin(dim_nums), end(dim_nums)) == end(dim_nums));
}

// TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
