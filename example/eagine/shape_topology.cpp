/// @example eagine/shape_topology.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/shapes/icosahedron.hpp>
#include <eagine/shapes/topology.hpp>
#include <iostream>

auto main() -> int {
    using namespace eagine;

    shapes::topology topo(
      shapes::unit_icosahedron(shapes::vertex_attrib_kind::position));

    topo.print_dot(std::cout) << std::endl;
    return 0;
}
