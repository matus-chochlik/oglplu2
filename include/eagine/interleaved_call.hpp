/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_INTERLEAVED_CALL_HPP
#define EAGINE_INTERLEAVED_CALL_HPP

#include <utility>

namespace eagine {

template <typename Func, typename SepFunc>
class interleaved_call {
private:
    Func _func;
    SepFunc _sep_func;
    bool _first{true};

public:
    interleaved_call(Func func, SepFunc sep_func)
      : _func(func)
      , _sep_func(sep_func) {}

    template <typename... P>
    auto operator()(P&&... p) {
        if(!_first) {
            _sep_func();
        } else {
            _first = false;
        }
        return _func(std::forward<P>(p)...);
    }
};

template <typename Func, typename SepFunc>
static inline auto make_interleaved(Func func, SepFunc sep_func)
  -> interleaved_call<Func, SepFunc> {
    return {func, sep_func};
}

} // namespace eagine

#endif // EAGINE_INTERLEAVED_CALL_HPP
