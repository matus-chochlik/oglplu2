/// @example eagine/shape_topology.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/program_args.hpp>
#include <eagine/shapes/cube.hpp>
#include <eagine/shapes/icosahedron.hpp>
#include <eagine/shapes/sphere.hpp>
#include <eagine/shapes/topology.hpp>
#include <eagine/shapes/torus.hpp>
#include <iostream>

auto main(int argc, const char** argv) -> int {
    using namespace eagine;
    program_args args(argc, argv);

    std::shared_ptr<shapes::generator_base> gen;

    if(args.find("--torus")) {
        gen =
          shapes::unit_torus(shapes::vertex_attrib_kind::position, 5, 12, 0.5F);
    } else if(args.find("--sphere")) {
        gen = shapes::unit_sphere(shapes::vertex_attrib_kind::position, 5, 12);
    } else if(args.find("--cube")) {
        gen = shapes::unit_cube(shapes::vertex_attrib_kind::position);
    } else if(args.find("--icosahedron")) {
        gen = shapes::unit_icosahedron(shapes::vertex_attrib_kind::position);
    }

    if(!gen) {
        gen = shapes::unit_icosahedron(shapes::vertex_attrib_kind::position);
    }

    shapes::topology topo(gen);

    topo.print_dot(std::cout) << std::endl;
    return 0;
}
