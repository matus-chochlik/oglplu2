/**
 *  @file eagine/protected_member.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_PROTECTED_MEMBER_HPP
#define EAGINE_PROTECTED_MEMBER_HPP

#include "identity.hpp"
#include <utility>

namespace eagine {

template <typename T, typename Selector = identity<T>>
class protected_member {
private:
    T _member;

protected:
    template <typename... P>
    protected_member(P&&... p)
      : _member(std::forward<P>(p)...) {}

public:
    auto get_the_member(Selector = Selector()) noexcept -> T& {
        return _member;
    }

    auto get_the_member(Selector = Selector()) const noexcept -> const T& {
        return _member;
    }
};

template <typename Selector, typename T>
static inline auto get_member(
  protected_member<T, Selector>& pm,
  Selector selector = Selector()) noexcept -> T& {
    return pm.get_the_member(selector);
}

template <typename Selector, typename T>
static inline auto get_member(
  const protected_member<T, Selector>& pm,
  Selector selector = Selector()) noexcept -> const T& {
    return pm.get_the_member(selector);
}

} // namespace eagine

#endif // EAGINE_PROTECTED_MEMBER_HPP
