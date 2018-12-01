/**
 *  @file eagine/is_within_limits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <limits>
#include "int_constant.hpp"

#ifndef EAGINE_IS_WITHIN_LIMITS_1509260923_HPP
#define EAGINE_IS_WITHIN_LIMITS_1509260923_HPP

namespace eagine {

template <typename Dst, typename Src>
struct implicitly_within_limits
  : bool_constant<(
      ((std::is_integral_v<Dst> && std::is_integral_v<Src>)
        || (std::is_floating_point_v<Dst> && std::is_floating_point_v<Src>))
      && (std::is_signed_v<Dst> == std::is_signed_v<Src>)&&(
           sizeof(Dst) >= sizeof(Src)))> {};

template <typename Dst>
struct implicitly_within_limits<Dst, bool> : std::is_integral<Dst> {};

template <typename Dst,
  typename Src,
  bool DIsInt,
  bool SIsInt,
  bool DIsSig,
  bool SIsSig>
struct within_limits_num {
    static constexpr inline bool check(Src) noexcept {
        return implicitly_within_limits<Dst, Src>::value;
    }
};

template <typename Dst, typename Src, bool IsInt, bool IsSig>
struct within_limits_num<Dst, Src, IsInt, IsInt, IsSig, IsSig> {
    static constexpr inline bool check(Src value) noexcept {
        using dnl = std::numeric_limits<Dst>;

        return (dnl::min() <= value) && (value <= dnl::max());
    }
};

template <typename Dst, typename Src, bool IsInt>
struct within_limits_num<Dst, Src, IsInt, IsInt, false, true> {
    static constexpr inline bool check(Src value) noexcept {
        using dnl = std::numeric_limits<Dst>;

        return (value < Src(0)) ? false : (value < dnl::max());
    }
};

template <typename Dst, typename Src, bool IsInt>
struct within_limits_num<Dst, Src, IsInt, IsInt, true, false> {
    static constexpr inline bool check(Src value) noexcept {
        using dnl = std::numeric_limits<Dst>;

        return (value < dnl::max());
    }
};

template <typename Dst, typename Src>
struct within_limits
  : within_limits_num<Dst,
      Src,
      std::is_integral_v<Dst>,
      std::is_integral_v<Src>,
      std::is_signed_v<Dst>,
      std::is_signed_v<Src>> {};

template <typename T>
struct within_limits<T, T> {
    static constexpr inline bool check(T&) noexcept {
        return true;
    }
};

template <typename Dst, typename Src>
static constexpr inline bool
is_within_limits(Src value) noexcept {
    return implicitly_within_limits<Dst, Src>::value
           || within_limits<Dst, Src>::check(value);
}

} // namespace eagine

#endif // EAGINE_IS_WITHIN_LIMITS_1509260923_HPP
