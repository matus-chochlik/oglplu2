/**
 *  @file eglplus/config/basic.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_CONFIG_BASIC_1509260923_HPP
#define EGLPLUS_CONFIG_BASIC_1509260923_HPP

// TODO

#ifndef EGLPLUS_LINK_LIBRARY
#define EGLPLUS_LINK_LIBRARY 0
#endif

#if EGLPLUS_LINK_LIBRARY
#define EGLPLUS_LIB_FUNC
#else
#define EGLPLUS_LIB_FUNC inline
#endif

#endif // include guard
