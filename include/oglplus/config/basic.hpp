/**
 *  @file oglplus/config/basic.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CONFIG_BASIC_1509260923_HPP
#define OGLPLUS_CONFIG_BASIC_1509260923_HPP

#ifndef OGLPLUS_NO_SITE_CONFIG
#include <oglplus/config/site.hpp>
#endif

#ifndef OGLPLUS_LOW_PROFILE
#define OGLPLUS_LOW_PROFILE 0
#endif

#ifndef OGLPLUS_NO_LIMIT_CHECKS
#define OGLPLUS_NO_LIMIT_CHECKS OGLPLUS_LOW_PROFILE
#endif

#ifndef OGLPLUS_LINK_LIBRARY
#define OGLPLUS_LINK_LIBRARY 0
#endif

#if OGLPLUS_LINK_LIBRARY
#define OGLPLUS_LIB_FUNC
#else
#define OGLPLUS_LIB_FUNC inline
#endif

#endif // include guard
