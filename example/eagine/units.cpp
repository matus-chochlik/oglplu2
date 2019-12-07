/**
 *  @example eagine/units.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/tagged_quantity.hpp>
#include <eagine/units/strings.hpp>
#include <eagine/units/unit/si.hpp>
#include <iostream>

template <typename Unit>
using qty = eagine::tagged_quantity<float, Unit>;

template <typename Unit>
void print(const qty<Unit>& q) {
    using eagine::units::get_name;
    using eagine::units::get_name_form;
    using eagine::units::get_symbol;

    const auto dim = get_dimension(q.unit());
    std::cout << get_name(dim) << " (" << get_name_form(dim)
              << "): " << q.value() << " [" << get_symbol(q.unit()) << " ("
              << get_name_form(q.unit()) << ")]\n";
}

int main() {
    using namespace eagine::units;

    qty<meter> x{2.f};
    qty<meter> y{3.f};
    qty<meter> z{4.f};
    qty<newton> f{12.f};
    qty<second> t{6.f};
    auto a = x * y;
    auto v = a * z;
    auto s = f / a;
    auto e = v * s;
    auto p = e / t;

    print(x);
    print(y);
    print(a);
    print(v);
    print(t);
    print(f);
    print(s);
    print(e);
    print(p);

    return 0;
}
