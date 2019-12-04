/**
 *  @example eagine/units.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/tagged_quantity.hpp>
#include <eagine/units/dim/force.hpp>
#include <eagine/units/dim/pressure.hpp>
#include <eagine/units/strings.hpp>
#include <eagine/units/unit/si/force.hpp>
#include <eagine/units/unit/si/length.hpp>
#include <eagine/units/unit/si/pressure.hpp>
#include <iostream>

template <typename Unit>
using qty = eagine::tagged_quantity<float, Unit>;

template <typename Unit>
void print(const qty<Unit>& q) {

    std::cout << get_dim_name(q.unit()) << ": " << q.value() << " ["
              << get_unit_symbol(q.unit()) << "]\n";
}

int main() {
    using namespace eagine::units;

    qty<meter> l1{2.f};
    qty<meter> l2{3.f};
    qty<newton> f{12.f};
    qty<pascal> p = f / (l1 * l2);

    print(l1);
    print(l2);
    print(f);
    print(p);

    return 0;
}
