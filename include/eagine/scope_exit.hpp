/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SCOPE_EXIT_HPP
#define EAGINE_SCOPE_EXIT_HPP

#include "callable_ref.hpp"
#include "nothing.hpp"
#include <exception>
#include <type_traits>

namespace eagine {

/// @brief Class executing a specified action on scope exit.
/// @ingroup functional
/// @see func_on_scope_exit
/// @see finally
template <typename OnException = nothing_t>
class on_scope_exit {
public:
    /// @brief The callable action type.
    using action_type = callable_ref<void()>;

    /// @brief Construction intializing with the specified action.
    on_scope_exit(action_type action) noexcept
      : _action(std::move(action)) {}

    /// @brief Construction intializing with the specified action.
    template <typename Func>
    on_scope_exit(Func& action) noexcept
      : _action(construct_from, action) {}

    /// @brief Move constructor.
    on_scope_exit(on_scope_exit&& temp) noexcept
      : on_scope_exit(temp.release()) {}

    /// @brief Not copy constructible.
    on_scope_exit(const on_scope_exit&) = delete;

    /// @brief Not move constructible.
    auto operator=(on_scope_exit&&) = delete;

    /// @brief Not copy constructible.
    auto operator=(const on_scope_exit&) = delete;

    /// @brief Invokes the stored action, unless it was released or cancelled.
    /// @see release
    /// @see cancel
    ~on_scope_exit() noexcept(false) {
        _invoke(OnException());
    }

    /// @brief Indicates if there is any on-scope-exit action.
    /// @see release
    /// @see cancel
    auto is_active() const noexcept -> bool {
        return _action.is_valid();
    }

    /// @brief Moves out and returns the stored action.
    /// @post !is_active()
    /// @see cancel
    /// @see is_active
    auto release() noexcept -> action_type {
        return std::move(_action);
    }

    /// @brief Resets the stored action to empty default.
    /// @post !is_active()
    /// @see release
    /// @see is_active
    void cancel() noexcept {
        _action = {};
    }

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
};

/// @brief Class storing a callable object and an instance of on_scope_exit.
/// @ingroup functional
/// @tparam Func type of the callable function object.
/// @see on_scope_exit
/// @see finally
///
/// This class stores a copy of the specified callable object and an instance
/// of on_scope_exit referencing and invoking the callable when desctoyed.
///
/// @note Do not use directly, use the finally function to construct.
template <typename Func, typename OnException = nothing_t>
class func_on_scope_exit {
private:
    Func _func;
    on_scope_exit<OnException> _ose;

public:
    /// @brief Initialization from the specified callable object.
    func_on_scope_exit(Func func)
      : _func(std::move(func))
      , _ose(_func) {}

    /// @brief Cancels this on scope exit action.
    void cancel() noexcept {
        _ose.cancel();
    }
};

/// @brief Function constructing on-scope-exit actions.
/// @ingroup functional
///
/// This function takes the specified callable argument and creates an object
/// which when destroyed, typically when leaving scope block, invokes the callable.
template <typename Func>
[[nodiscard]] static inline auto finally(Func func)
  -> func_on_scope_exit<Func> {
    return func;
}

} // namespace eagine

#endif // EAGINE_SCOPE_EXIT_HPP
