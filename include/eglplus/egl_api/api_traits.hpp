/**
 *  @file eglplus/egl_api/api_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EGLPLUS_EGL_API_API_TRAITS_HPP
#define EGLPLUS_EGL_API_API_TRAITS_HPP

#include "result.hpp"

namespace eagine {
namespace eglp {
//------------------------------------------------------------------------------
class egl_api_traits : public default_c_api_traits {
public:
    template <typename R>
    using no_result = egl_no_result<R>;
    template <typename R>
    using result = egl_result<R>;
    template <typename R>
    using opt_result = egl_opt_result<R>;

private:
};
//------------------------------------------------------------------------------
} // namespace eglp
} // namespace eagine

#endif // EGLPLUS_EGL_API_API_TRAITS_HPP

