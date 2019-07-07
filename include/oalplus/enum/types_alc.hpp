//  File include/oalplus/enum/types_alc.hpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oalplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#ifndef OALPLUS_ALC_ENUM_TYPES_HPP // NOLINT(llvm-header-guard)
#define OALPLUS_ALC_ENUM_TYPES_HPP

#include "../utils/enum_class.hpp"

namespace oalplus {

struct alc_error_code : enum_class_alc<alc_error_code, ALCenum, 0> {
    using enum_class::enum_class;
};

struct context_attrib : enum_class_alc<context_attrib, ALCenum, 1> {
    using enum_class::enum_class;
};

} // namespace oalplus

#endif // OALPLUS_ALC_ENUM_TYPES_HPP
