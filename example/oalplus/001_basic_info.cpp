/**
 *  example oalplus/001_basic_info.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oalplus/al.hpp>
#include <oalplus/alc_api.hpp>
#include <iostream>

auto main() -> int {
    using namespace eagine;
    using namespace eagine::oalp;

    alc_api alc;

    std::cout << "Default playback device: "
              << extract_or(alc.get_default_device_specifier(), "N/A")
              << std::endl;

    std::cout << "Default capture device: "
              << extract_or(alc.get_capture_default_device_specifier(), "N/A")
              << std::endl;

    std::cout << "ALC version: "
              << extract_or(alc.get_integer(alc.major_version), 0) << "."
              << extract_or(alc.get_integer(alc.minor_version), 0) << std::endl;

    return 0;
}
