/**
 *  @file eagine/smart_callable.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_SMART_CALLABLE_HPP
#define EAGINE_SMART_CALLABLE_HPP

#include "args_within_limits.hpp"
#include "assert.hpp"
#include "valid_if/decl.hpp"

namespace eagine {
//------------------------------------------------------------------------------
template <bool Asserting, typename Callable>
class smart_callable;
//------------------------------------------------------------------------------
template <bool Asserting, typename RV, typename... Params>
class smart_callable_base;
//------------------------------------------------------------------------------
template <typename RV, typename... Params>
class smart_callable_base<false, RV, Params...> {
protected:
    template <typename Callable, typename... Args>
    static constexpr auto _invoke(Callable& callable, Args&&... args) {
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#endif
        using ORV = optionally_valid<RV>;
        return args_within_limits_of<Params...>(args...)
                 ? ORV{callable(std::forward<Args>(args)...)}
                 : ORV{};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
    }
};
//------------------------------------------------------------------------------
template <typename RV, typename... Params>
class smart_callable_base<true, RV, Params...> {
protected:
    template <typename Callable, typename... Args>
    static constexpr auto _invoke(Callable& callable, Args&&... args) {
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"
#pragma clang diagnostic ignored "-Wsign-conversion"
#endif
        EAGINE_ASSERT(args_within_limits_of<Params...>(args...));
        return callable(std::forward<Args>(args)...);
#ifdef __clang__
#pragma clang diagnostic pop
#endif
    }
};
//------------------------------------------------------------------------------
template <bool Asseting, typename RV, typename... Params>
class smart_callable<Asseting, RV (*)(Params...)>
  : public smart_callable_base<Asseting, RV, Params...> {
public:
    constexpr smart_callable(RV (*function)(Params...)) noexcept
      : _function{function} {}

    template <typename... Args>
    constexpr auto operator()(Args&&... args) const {
        this->_invoke(_function, std::forward<Args>(args)...);
    }

private:
    RV (*_function)(Params...) = nullptr;
};
//------------------------------------------------------------------------------
template <typename RV, typename... Params>
static constexpr smart_callable<false, RV (*)(Params...)>
smart_call(RV (*function)(Params...)) noexcept {
    return {function};
}
//------------------------------------------------------------------------------
template <typename RV, typename... Params>
static constexpr smart_callable<true, RV (*)(Params...)>
safe_call(RV (*function)(Params...)) noexcept {
    return {function};
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SMART_CALLABLE_HPP
