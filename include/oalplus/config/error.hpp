/**
 *  @file oalplus/config/error.hpp
 *  @brief Error reporting-related compile-time configuration options
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2015 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#pragma once
#ifndef OALPLUS_CONFIG_ERROR_1107121519_HPP
#define OALPLUS_CONFIG_ERROR_1107121519_HPP

#include "basic.hpp"

#ifndef OALPLUS_ERROR_NO_AL_LIB
# define OALPLUS_ERROR_NO_AL_LIB OALPLUS_LOW_PROFILE
#endif

#ifndef OALPLUS_ERROR_NO_AL_FUNC
# define OALPLUS_ERROR_NO_AL_FUNC 0
#endif

#ifndef OALPLUS_ERROR_NO_SRC_FILE
# define OALPLUS_ERROR_NO_SRC_FILE OALPLUS_LOW_PROFILE
#endif

#ifndef OALPLUS_ERROR_NO_SRC_LINE
# define OALPLUS_ERROR_NO_SRC_LINE OALPLUS_LOW_PROFILE
#endif

#ifndef OALPLUS_ERROR_NO_SRC_FUNC
# define OALPLUS_ERROR_NO_SRC_FUNC 1
#endif

#ifndef OALPLUS_ERROR_NO_OBJECT
# define OALPLUS_ERROR_NO_OBJECT 0
#endif

#ifndef OALPLUS_ERROR_NO_INDEX
# define OALPLUS_ERROR_NO_INDEX OALPLUS_LOW_PROFILE
#endif

#ifndef OALPLUS_ERROR_NO_ENUM_VALUE
# define OALPLUS_ERROR_NO_ENUM_VALUE OALPLUS_LOW_PROFILE
#endif

#ifndef OALPLUS_ERROR_NO_CONTEXT
# define OALPLUS_ERROR_NO_CONTEXT 1
#endif

#ifndef OALPLUS_ERROR_NO_DEVICE
# define OALPLUS_ERROR_NO_DEVICE 0
#endif

#endif // include guard
