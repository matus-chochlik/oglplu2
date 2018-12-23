/**
 *  @file oalplus/al.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_HPP
#define OALPLUS_AL_HPP

#if defined(EAGINE_YCM)
#if __has_include(<AL/al.h>)
#include <AL/al.h>
#endif
#if __has_include(<AL/alc.h>)
#include <AL/alc.h>
#endif
#else // EAGINE_YCM
#include <AL/al.h>
#include <AL/alc.h>
#endif // EAGINE_YCM
// TODO

#endif // OALPLUS_AL_HPP
