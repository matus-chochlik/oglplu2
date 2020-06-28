/**
 *  @file eagine/scope_exit.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SCOPE_EXIT_HPP
#define EAGINE_SCOPE_EXIT_HPP

#include "callable_ref.hpp"
#include "nothing.hpp"
#include <exception>
#include <type_traits>

namespace eagine {

template <typename OnException = nothing_t>
class on_scope_exit {
public:
    using action_type = callable_ref<void()>;

private:
    action_type _action;

    void _invoke(std::true_type) const {
        if(_action) {
            if(std::uncaught_exceptions()) {
                try {
                    _action();
                } catch(...) {
                }
            }
        }
    }

    void _invoke(std::false_type) const {
        if(_action) {
            if(!std::uncaught_exceptions()) {
                _action();
            }
        }
    }

    void _invoke(nothing_t) const {
        if(_action) {
            _action();
        }
    }

public:
    on_scope_exit(action_type action) noexcept
      : _action(std::move(action)) {
    }

    template <typename Func>
    on_scope_exit(Func& action) noexcept
      : _action(action_type(action)) {
    }

    on_scope_exit(const on_scope_exit&) = delete;
    on_scope_exit& operator=(const on_scope_exit&) = delete;

    on_scope_exit(on_scope_exit&& temp) noexcept
      : on_scope_exit(temp.release()) {
    }
    on_scope_exit& operator=(on_scope_exit&&) = delete;

    ~on_scope_exit() noexcept(false) {
        _invoke(OnException());
    }

    action_type release() noexcept {
        return std::move(_action);
    }

    void cancel() noexcept {
        _action = {};
    }
};

template <typename Func, typename OnException = nothing_t>
class func_on_scope_exit {
private:
    Func _func;
    on_scope_exit<OnException> _ose;

public:
    func_on_scope_exit(Func func)
      : _func(func)
      , _ose(_func) {
    }

    void cancel() noexcept {
        _ose.cancel();
    }
};

template <typename Func>
static inline func_on_scope_exit<Func> finally(Func func) {
    return func;
}

} // namespace eagine

#endif // EAGINE_SCOPE_EXIT_HPP
