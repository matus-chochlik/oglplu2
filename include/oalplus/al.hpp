/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_AL_HPP
#define OALPLUS_AL_HPP

#include "config/basic.hpp"

#if defined(EAGINE_YCM)
#if __has_include(<AL/al.h>)
#include <AL/al.h>
#endif
#if __has_include(<AL/alc.h>)
#include <AL/alc.h>
#endif
#if __has_include(<AL/alut.h>)
#include <AL/alut.h>
#endif
#else // EAGINE_YCM
#if OALPLUS_AL_H_FOUND
#include <AL/al.h>
#endif // OALPLUS_AL_H_FOUND
#if OALPLUS_ALC_H_FOUND
#include <AL/alc.h>
#endif // OALPLUS_ALC_H_FOUND
#if OALPLUS_ALUT_H_FOUND
#include <AL/alut.h>
#endif // OALPLUS_ALUT_H_FOUND
#endif // EAGINE_YCM

#endif // OALPLUS_AL_HPP
