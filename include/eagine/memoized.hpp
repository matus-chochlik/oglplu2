/**
 *  @file eagine/memoized.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMOIZED_1509260923_HPP
#define EAGINE_MEMOIZED_1509260923_HPP

#include "callable_ref.hpp"
#include <map>
#include <tuple>

namespace eagine {

template <typename F>
class memoized;

template <typename R, typename... P>
class memoized<R(P...)> {
private:
    typedef std::tuple<P...> T;
    typedef std::pair<T, R> E;
    std::map<T, R> _memo;
    callable_ref<R(P..., memoized&)> _func;

public:
    template <typename Func>
    memoized(Func&& func)
      : _func(std::forward<Func>(func)) {
    }

    template <typename F>
    R operator()(P... p, const F& f) {
        T t(p...);
        auto i = _memo.find(t);
        if(i == _memo.end()) {
            i = _memo.insert(E(t, f(p..., *this))).first;
        }
        return i->second;
    }

    R operator()(P... p) {
        return _func(p..., *this);
    }

    void reset(P... p) {
        _memo.erase(T(p...));
    }

    void clear() {
        _memo.clear();
    }
};

} // namespace eagine

#endif // include guard
