/**
 *  @file oglplus/config/error.hpp
 *  @brief Error reporting-related compile-time configuration options
 *
 *  @author Matus Chochlik
 *
 *  Copyright 2010-2015 Matus Chochlik. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#pragma once
#ifndef OGLPLUS_CONFIG_ERROR_1107121519_HPP
#define OGLPLUS_CONFIG_ERROR_1107121519_HPP

#include "basic.hpp"

#ifndef OGLPLUS_ERROR_NO_GL_LIB
# define OGLPLUS_ERROR_NO_GL_LIB OGLPLUS_LOW_PROFILE
#endif

#ifndef OGLPLUS_ERROR_NO_GL_FUNC
# define OGLPLUS_ERROR_NO_GL_FUNC 0
#endif

#ifndef OGLPLUS_ERROR_NO_SRC_FILE
# define OGLPLUS_ERROR_NO_SRC_FILE OGLPLUS_LOW_PROFILE
#endif

#ifndef OGLPLUS_ERROR_NO_SRC_LINE
# define OGLPLUS_ERROR_NO_SRC_LINE OGLPLUS_LOW_PROFILE
#endif

#ifndef OGLPLUS_ERROR_NO_SRC_FUNC
# define OGLPLUS_ERROR_NO_SRC_FUNC OGLPLUS_LOW_PROFILE
#endif

#ifndef OGLPLUS_ERROR_NO_OBJ_NAME
# define OGLPLUS_ERROR_NO_OBJ_NAME 0
#endif

#ifndef OGLPLUS_ERROR_NO_SUB_NAME
# define OGLPLUS_ERROR_NO_SUB_NAME OGLPLUS_LOW_PROFILE
#endif

#ifndef OGLPLUS_ERROR_NO_INDEX
# define OGLPLUS_ERROR_NO_INDEX OGLPLUS_LOW_PROFILE
#endif

#ifndef OGLPLUS_ERROR_NO_ENUM_VALUE
# define OGLPLUS_ERROR_NO_ENUM_VALUE OGLPLUS_LOW_PROFILE
#endif

#endif // include guard
