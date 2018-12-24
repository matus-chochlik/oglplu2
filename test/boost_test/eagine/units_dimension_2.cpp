/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/units/dimension.hpp>
#include <eagine/units/dimensionless.hpp>

#include <eagine/units/dim/acceleration.hpp>
#include <eagine/units/dim/angular_velocity.hpp>
#include <eagine/units/dim/area.hpp>
#include <eagine/units/dim/energy.hpp>
#include <eagine/units/dim/force.hpp>
#include <eagine/units/dim/mass_density.hpp>
#include <eagine/units/dim/momentum.hpp>
#include <eagine/units/dim/power.hpp>
#include <eagine/units/dim/pressure.hpp>
#include <eagine/units/dim/velocity.hpp>
#include <eagine/units/dim/volume.hpp>

#include <eagine/units/dim/electric_charge.hpp>
#include <eagine/units/dim/electric_tension.hpp>
#include <eagine/units/dim/electrical_capacitance.hpp>
#include <eagine/units/dim/electrical_conductance.hpp>
#include <eagine/units/dim/electrical_resistance.hpp>
#include <eagine/units/dim/inductance.hpp>
#include <eagine/units/dim/magnetic_field_strength.hpp>
#include <eagine/units/dim/magnetic_flux.hpp>

#include <eagine/units/dim/frequency.hpp>
#include <eagine/units/dim/radioactivity.hpp>
#define BOOST_TEST_MODULE EAGINE_units_dimension_2
#include "../unit_test_begin.inl"

#include <type_traits>

BOOST_AUTO_TEST_SUITE(units_dimension_tests_2)

struct area_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::area()) ==
          get_pow_of_dim(BD(), eagine::units::length()) +
            get_pow_of_dim(BD(), eagine::units::length()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_area) {
    using namespace eagine::units;

    base::for_each_dim(area_base_dim_tester());
}

struct volume_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::volume()) ==
          get_pow_of_dim(BD(), eagine::units::length()) +
            get_pow_of_dim(BD(), eagine::units::length()) +
            get_pow_of_dim(BD(), eagine::units::length()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::volume()) ==
          get_pow_of_dim(BD(), eagine::units::area()) +
            get_pow_of_dim(BD(), eagine::units::length()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_volume) {
    using namespace eagine::units;

    base::for_each_dim(volume_base_dim_tester());
}

struct mass_density_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::mass_density()) ==
          get_pow_of_dim(BD(), eagine::units::mass()) -
            get_pow_of_dim(BD(), eagine::units::volume()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::mass_density()) ==
          get_pow_of_dim(BD(), eagine::units::mass()) -
            get_pow_of_dim(BD(), eagine::units::length()) -
            get_pow_of_dim(BD(), eagine::units::length()) -
            get_pow_of_dim(BD(), eagine::units::length()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_mass_density) {
    using namespace eagine::units;

    base::for_each_dim(mass_density_base_dim_tester());
}

struct velocity_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::velocity()) ==
          get_pow_of_dim(BD(), eagine::units::length()) -
            get_pow_of_dim(BD(), eagine::units::time()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_velocity) {
    using namespace eagine::units;

    base::for_each_dim(velocity_base_dim_tester());
}

struct angular_velocity_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::angular_velocity()) ==
          get_pow_of_dim(BD(), eagine::units::angle()) -
            get_pow_of_dim(BD(), eagine::units::time()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_angular_velocity) {
    using namespace eagine::units;

    base::for_each_dim(angular_velocity_base_dim_tester());
}

struct acceleration_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::acceleration()) ==
          get_pow_of_dim(BD(), eagine::units::velocity()) -
            get_pow_of_dim(BD(), eagine::units::time()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::acceleration()) ==
          get_pow_of_dim(BD(), eagine::units::length()) -
            get_pow_of_dim(BD(), eagine::units::time()) -
            get_pow_of_dim(BD(), eagine::units::time()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_acceleration) {
    using namespace eagine::units;

    base::for_each_dim(acceleration_base_dim_tester());
}

struct momentum_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::momentum()) ==
          get_pow_of_dim(BD(), eagine::units::velocity()) +
            get_pow_of_dim(BD(), eagine::units::mass()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_momentum) {
    using namespace eagine::units;

    base::for_each_dim(momentum_base_dim_tester());
}

struct force_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::force()) ==
          get_pow_of_dim(BD(), eagine::units::acceleration()) +
            get_pow_of_dim(BD(), eagine::units::mass()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::force()) ==
          get_pow_of_dim(BD(), eagine::units::velocity()) +
            get_pow_of_dim(BD(), eagine::units::mass()) -
            get_pow_of_dim(BD(), eagine::units::time()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_force) {
    using namespace eagine::units;

    base::for_each_dim(force_base_dim_tester());
}

struct energy_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::energy()) ==
          get_pow_of_dim(BD(), eagine::units::force()) +
            get_pow_of_dim(BD(), eagine::units::length()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::energy()) ==
          get_pow_of_dim(BD(), eagine::units::length()) -
            get_pow_of_dim(BD(), eagine::units::time()) +
            get_pow_of_dim(BD(), eagine::units::length()) -
            get_pow_of_dim(BD(), eagine::units::time()) +
            get_pow_of_dim(BD(), eagine::units::mass()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_energy) {
    using namespace eagine::units;

    base::for_each_dim(energy_base_dim_tester());
}

struct power_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::power()) ==
          get_pow_of_dim(BD(), eagine::units::energy()) -
            get_pow_of_dim(BD(), eagine::units::time()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::power()) ==
          get_pow_of_dim(BD(), eagine::units::area()) +
            get_pow_of_dim(BD(), eagine::units::mass()) -
            get_pow_of_dim(BD(), eagine::units::time()) * 3);
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_power) {
    using namespace eagine::units;

    base::for_each_dim(power_base_dim_tester());
}

struct pressure_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::pressure()) ==
          get_pow_of_dim(BD(), eagine::units::force()) -
            get_pow_of_dim(BD(), eagine::units::area()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::pressure()) ==
          get_pow_of_dim(BD(), eagine::units::velocity()) +
            get_pow_of_dim(BD(), eagine::units::mass()) -
            get_pow_of_dim(BD(), eagine::units::time()) -
            get_pow_of_dim(BD(), eagine::units::area()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_pressure) {
    using namespace eagine::units;

    base::for_each_dim(pressure_base_dim_tester());
}

struct electric_charge_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::electric_charge()) ==
          get_pow_of_dim(BD(), eagine::units::electric_current()) +
            get_pow_of_dim(BD(), eagine::units::time()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_electric_charge) {
    using namespace eagine::units;

    base::for_each_dim(electric_charge_base_dim_tester());
}

struct electric_tension_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::electric_tension()) ==
          get_pow_of_dim(BD(), eagine::units::power()) -
            get_pow_of_dim(BD(), eagine::units::electric_current()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::electric_tension()) ==
          get_pow_of_dim(BD(), eagine::units::length()) * 2 +
            get_pow_of_dim(BD(), eagine::units::mass()) -
            get_pow_of_dim(BD(), eagine::units::time()) * 3 -
            get_pow_of_dim(BD(), eagine::units::electric_current()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_electric_tension) {
    using namespace eagine::units;

    base::for_each_dim(electric_tension_base_dim_tester());
}

struct electrical_capacitance_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::electrical_capacitance()) ==
          get_pow_of_dim(BD(), eagine::units::electric_charge()) -
            get_pow_of_dim(BD(), eagine::units::electric_tension()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::electrical_capacitance()) ==
          get_pow_of_dim(BD(), eagine::units::electric_current()) * 2 -
            get_pow_of_dim(BD(), eagine::units::length()) * 2 -
            get_pow_of_dim(BD(), eagine::units::mass()) +
            get_pow_of_dim(BD(), eagine::units::time()) * 4);
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_electrical_capacitance) {
    using namespace eagine::units;

    base::for_each_dim(electrical_capacitance_base_dim_tester());
}

struct electrical_conductance_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::electrical_conductance()) ==
          get_pow_of_dim(BD(), eagine::units::electric_current()) -
            get_pow_of_dim(BD(), eagine::units::electric_tension()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::electrical_conductance()) ==
          get_pow_of_dim(BD(), eagine::units::electric_current()) * 2 -
            get_pow_of_dim(BD(), eagine::units::length()) * 2 -
            get_pow_of_dim(BD(), eagine::units::mass()) +
            get_pow_of_dim(BD(), eagine::units::time()) * 3);
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_electrical_conductance) {
    using namespace eagine::units;

    base::for_each_dim(electrical_conductance_base_dim_tester());
}

struct electrical_resistance_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::electrical_resistance()) ==
          get_pow_of_dim(BD(), eagine::units::electric_tension()) -
            get_pow_of_dim(BD(), eagine::units::electric_current()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::electrical_resistance()) ==
          get_pow_of_dim(BD(), eagine::units::dimensionless()) -
            get_pow_of_dim(BD(), eagine::units::electrical_conductance()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_electrical_resistance) {
    using namespace eagine::units;

    base::for_each_dim(electrical_resistance_base_dim_tester());
}

struct magnetic_flux_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::magnetic_flux()) ==
          get_pow_of_dim(BD(), eagine::units::energy()) -
            get_pow_of_dim(BD(), eagine::units::electric_current()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::magnetic_flux()) ==
          get_pow_of_dim(BD(), eagine::units::electric_tension()) +
            get_pow_of_dim(BD(), eagine::units::time()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::magnetic_flux()) ==
          get_pow_of_dim(BD(), eagine::units::length()) * 2 -
            get_pow_of_dim(BD(), eagine::units::time()) * 2 +
            get_pow_of_dim(BD(), eagine::units::mass()) -
            get_pow_of_dim(BD(), eagine::units::electric_current()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_magnetic_flux) {
    using namespace eagine::units;

    base::for_each_dim(magnetic_flux_base_dim_tester());
}

struct magnetic_field_strength_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::magnetic_field_strength()) ==
          get_pow_of_dim(BD(), eagine::units::magnetic_flux()) -
            get_pow_of_dim(BD(), eagine::units::area()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::magnetic_field_strength()) ==
          get_pow_of_dim(BD(), eagine::units::mass()) -
            get_pow_of_dim(BD(), eagine::units::electric_current()) -
            get_pow_of_dim(BD(), eagine::units::time()) * 2);
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_magnetic_field_strength) {
    using namespace eagine::units;

    base::for_each_dim(magnetic_field_strength_base_dim_tester());
}

struct inductance_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::inductance()) ==
          get_pow_of_dim(BD(), eagine::units::magnetic_flux()) -
            get_pow_of_dim(BD(), eagine::units::electric_current()));
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::inductance()) ==
          get_pow_of_dim(BD(), eagine::units::length()) * 2 -
            get_pow_of_dim(BD(), eagine::units::time()) * 2 +
            get_pow_of_dim(BD(), eagine::units::mass()) -
            get_pow_of_dim(BD(), eagine::units::electric_current()) * 2);
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_inductance) {
    using namespace eagine::units;

    base::for_each_dim(inductance_base_dim_tester());
}

struct frequency_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::frequency()) ==
          get_pow_of_dim(BD(), eagine::units::number_of_cycles()) -
            get_pow_of_dim(BD(), eagine::units::time()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_frequency) {
    using namespace eagine::units;

    base::for_each_dim(frequency_base_dim_tester());
}

struct radioactivity_base_dim_tester {
    template <typename BD>
    void operator()(BD) const {
        BOOST_CHECK(
          get_pow_of_dim(BD(), eagine::units::radioactivity()) ==
          get_pow_of_dim(BD(), eagine::units::number_of_decays()) -
            get_pow_of_dim(BD(), eagine::units::time()));
    }
};

BOOST_AUTO_TEST_CASE(unit_dimensions_radioactivity) {
    using namespace eagine::units;

    base::for_each_dim(radioactivity_base_dim_tester());
}

// TODO

BOOST_AUTO_TEST_SUITE_END()

#include "../unit_test_end.inl"
