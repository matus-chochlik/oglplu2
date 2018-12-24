/**
 *  @file eagine/callable_composer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_CALLABLE_COMPOSER_HPP
#define EAGINE_CALLABLE_COMPOSER_HPP

#include <utility>

namespace eagine {

template <typename... Func>
struct callable_composer;

template <typename Func>
struct callable_composer<Func> : Func {
    callable_composer(const Func& func)
      : Func{func} {
    }

    callable_composer(Func&& func)
      : Func{std::move(func)} {
    }

    using Func::operator();
};

template <typename Func, typename... Funcs>
struct callable_composer<Func, Funcs...>
  : Func
  , callable_composer<Funcs...> {
    template <typename... F>
    callable_composer(const Func& func, F&&... funcs)
      : Func{func}
      , callable_composer<Funcs...>{std::forward<Funcs>(funcs)...} {
    }

    template <typename... F>
    callable_composer(Func&& func, F&&... funcs)
      : Func{std::move(func)}
      , callable_composer<Funcs...>{std::forward<Funcs>(funcs)...} {
    }

    using Func::operator();
    using callable_composer<Funcs...>::operator();
};

template <typename... Funcs>
static inline callable_composer<Funcs...> compose_callables(Funcs&&... funcs) {
    return {funcs...};
}

} // namespace eagine

#endif // EAGINE_CALLABLE_COMPOSER_HPP
