/**
 *  @file eagine/config/basic.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_CONFIG_BASIC_HPP
#define EAGINE_CONFIG_BASIC_HPP

#if __has_include(<eagine/config/site.hpp>)
#include <eagine/config/site.hpp>
#endif

#ifndef EAGINE_LOW_PROFILE
#define EAGINE_LOW_PROFILE 0
#endif

#ifndef EAGINE_DEBUG
#define EAGINE_DEBUG 1
#endif

#ifndef EAGINE_USE_ZLIB
#define EAGINE_USE_ZLIB 0
#endif

#ifndef EAGINE_USE_RYML
#define EAGINE_USE_RYML 0
#endif

#ifndef EAGINE_USE_OPENSSL
#define EAGINE_USE_OPENSSL 0
#endif

#ifndef EAGINE_USE_BACKTRACE
#define EAGINE_USE_BACKTRACE 0
#endif

#ifndef EAGINE_USE_STACKTRACE
#define EAGINE_USE_STACKTRACE 0
#endif

#ifndef EAGINE_USE_BOOST_SPIRIT
#define EAGINE_USE_BOOST_SPIRIT 1
#endif

#ifndef EAGINE_LINK_LIBRARY
#define EAGINE_LINK_LIBRARY 0
#endif

#if EAGINE_LINK_LIBRARY
#define EAGINE_LIB_FUNC
#else
#define EAGINE_LIB_FUNC inline
#endif

#endif // EAGINE_CONFIG_BASIC_HPP
