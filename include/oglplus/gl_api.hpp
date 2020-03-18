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

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
class gl_api
  : protected gl_api_traits
  , public basic_gl_api<gl_api_traits>
  , public basic_gl_constants<gl_api_traits> {
public:
    gl_api(gl_api_traits traits)
      : gl_api_traits{std::move(traits)}
      , basic_gl_api<gl_api_traits>{*static_cast<gl_api_traits*>(this)}
      , basic_gl_constants<gl_api_traits>{
          *static_cast<gl_api_traits*>(this),
          *static_cast<basic_gl_api<gl_api_traits>*>(this)} {
    }

    gl_api()
      : gl_api{gl_api_traits{}} {
    }

    basic_gl_api<gl_api_traits>& operations() noexcept {
        return *this;
    }

    const basic_gl_api<gl_api_traits>& operations() const noexcept {
        return *this;
    }

    basic_gl_api<gl_api_traits>& operator()() noexcept {
        return *this;
    }

    const basic_gl_api<gl_api_traits>& operator()() const noexcept {
        return *this;
    }

    basic_gl_constants<gl_api_traits>& constants() noexcept {
        return *this;
    }

    const basic_gl_constants<gl_api_traits>& constants() const noexcept {
        return *this;
    }

    basic_gl_constants<gl_api_traits>& operator~() noexcept {
        return *this;
    }

    const basic_gl_constants<gl_api_traits>& operator~() const noexcept {
        return *this;
    }
};

template <std::size_t I>
typename std::tuple_element<I, gl_api>::type& get(gl_api& x) noexcept {
    return x;
}

template <std::size_t I>
const typename std::tuple_element<I, gl_api>::type& get(
  const gl_api& x) noexcept {
    return x;
}
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

// NOLINTNEXTLINE(cert-dcl58-cpp)
namespace std {

template <>
struct tuple_size<eagine::oglp::gl_api>
  : public std::integral_constant<std::size_t, 2> {};

template <>
struct tuple_element<0, eagine::oglp::gl_api> {
    using type = eagine::oglp::basic_gl_api<eagine::oglp::gl_api_traits>;
};

template <>
struct tuple_element<1, eagine::oglp::gl_api> {
    using type = eagine::oglp::basic_gl_constants<eagine::oglp::gl_api_traits>;
};

} // namespace std

#endif // OGLPLUS_GL_API_HPP

