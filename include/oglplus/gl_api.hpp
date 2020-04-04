/**
 *  @file oglplus/gl_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_HPP
#define OGLPLUS_GL_API_HPP

#include "gl_api/api.hpp"
#include "gl_api/api_traits.hpp"
#include "gl_api/constants.hpp"
#include "gl_api_fwd.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_gl_api
  : protected ApiTraits
  , public basic_gl_operations<ApiTraits>
  , public basic_gl_constants<ApiTraits> {
public:
    basic_gl_api(ApiTraits traits)
      : ApiTraits{std::move(traits)}
      , basic_gl_operations<ApiTraits>{*static_cast<ApiTraits*>(this)}
      , basic_gl_constants<ApiTraits>{
          *static_cast<ApiTraits*>(this),
          *static_cast<basic_gl_operations<ApiTraits>*>(this)} {
    }

    basic_gl_api()
      : basic_gl_api{ApiTraits{}} {
    }

    basic_gl_operations<ApiTraits>& operations() noexcept {
        return *this;
    }

    const basic_gl_operations<ApiTraits>& operations() const noexcept {
        return *this;
    }

    basic_gl_operations<ApiTraits>& operator()() noexcept {
        return *this;
    }

    const basic_gl_operations<ApiTraits>& operator()() const noexcept {
        return *this;
    }

    basic_gl_constants<ApiTraits>& constants() noexcept {
        return *this;
    }

    const basic_gl_constants<ApiTraits>& constants() const noexcept {
        return *this;
    }

    basic_gl_constants<ApiTraits>& operator~() noexcept {
        return *this;
    }

    const basic_gl_constants<ApiTraits>& operator~() const noexcept {
        return *this;
    }
};

template <std::size_t I, typename ApiTraits>
typename std::tuple_element<I, basic_gl_api<ApiTraits>>::type& get(
  basic_gl_api<ApiTraits>& x) noexcept {
    return x;
}

template <std::size_t I, typename ApiTraits>
const typename std::tuple_element<I, basic_gl_api<ApiTraits>>::type& get(
  const basic_gl_api<ApiTraits>& x) noexcept {
    return x;
}
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct tuple_size<eagine::oglp::basic_gl_api<ApiTraits>>
  : public std::integral_constant<std::size_t, 2> {};

template <typename ApiTraits>
struct tuple_element<0, eagine::oglp::basic_gl_api<ApiTraits>> {
    using type = eagine::oglp::basic_gl_operations<ApiTraits>;
};

template <typename ApiTraits>
struct tuple_element<1, eagine::oglp::basic_gl_api<ApiTraits>> {
    using type = eagine::oglp::basic_gl_constants<ApiTraits>;
};
//------------------------------------------------------------------------------
} // namespace std

#endif // OGLPLUS_GL_API_HPP

