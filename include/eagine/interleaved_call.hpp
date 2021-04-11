/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_INTERLEAVED_CALL_HPP
#define EAGINE_INTERLEAVED_CALL_HPP

#include "branch_predict.hpp"
#include <utility>

namespace eagine {

/// @brief Callable class that interleaves calls to a function with a separator function.
/// @ingroup functional
template <typename Func, typename SepFunc>
class interleaved_call {
public:
    /// @brief Construction from the base function and the separator function.
    interleaved_call(Func func, SepFunc sep_func)
      : _func(func)
      , _sep_func(sep_func) {}

    /// @brief The function call operator.
    template <typename... P>
    auto operator()(P&&... p) {
        if(EAGINE_LIKELY(!_first)) {
            _sep_func();
        } else {
            _first = false;
        }
        return _func(std::forward<P>(p)...);
    }

private:
    Func _func;
    SepFunc _sep_func;
    bool _first{true};
};

template <typename Func, typename SepFunc>
interleaved_call(Func func, SepFunc sep_func)
  -> interleaved_call<Func, SepFunc>;

} // namespace eagine

#endif // EAGINE_INTERLEAVED_CALL_HPP
