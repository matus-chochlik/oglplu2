/**
 *  @file oalplus/config/basic.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_CONFIG_BASIC_HPP
#define OALPLUS_CONFIG_BASIC_HPP

// TODO
#ifndef OALPLUS_LOW_PROFILE
#define OALPLUS_LOW_PROFILE 0
#endif

#ifndef OALPLUS_LINK_LIBRARY
#define OALPLUS_LINK_LIBRARY 0
#endif

#if OALPLUS_LINK_LIBRARY
#define OALPLUS_LIB_FUNC
#else
#define OALPLUS_LIB_FUNC inline
#endif

#endif // OALPLUS_CONFIG_BASIC_HPP
