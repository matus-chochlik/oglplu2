/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEM_FUNC_CONST_HPP
#define EAGINE_MEM_FUNC_CONST_HPP

#include <utility>

namespace eagine {

template <typename T, T Ptr>
struct member_function_constant;

template <typename RV, typename C, typename... P, RV (C::*Ptr)(P...)>
struct member_function_constant<RV (C::*)(P...), Ptr> {
    using pointer = RV (C::*)(P...);
    using free_pointer = RV (*)(C*, P...);
    using result_type = RV;
    using scope = C;
    using is_const = std::false_type;

    static constexpr auto get() noexcept -> pointer {
        return Ptr;
    }

    static auto free_func(C* c, P... a) -> RV {
        return (c->*Ptr)(std::forward<P>(a)...);
    }

    static auto make_free() noexcept -> free_pointer {
        return &free_func;
    }
};

template <typename RV, typename C, typename... P, RV (C::*Ptr)(P...) const>
struct member_function_constant<RV (C::*)(P...) const, Ptr> {
    using pointer = RV (C::*)(P...) const;
    using free_pointer = RV (*)(const C*, P...);
    using result_type = RV;
    using scope = C;
    using is_const = std::true_type;

    static constexpr auto get() noexcept -> pointer {
        return Ptr;
    }

    static auto free_func(const C* c, P... a) -> RV {
        return (c->*Ptr)(std::forward<P>(a)...);
    }

    static auto make_free() noexcept -> free_pointer {
        return &free_func;
    }
};

template <typename RV, typename C, typename... P, RV (C::*Ptr)(P...) noexcept>
struct member_function_constant<RV (C::*)(P...) noexcept, Ptr> {
    using pointer = RV (C::*)(P...) noexcept;
    using free_pointer = RV (*)(C*, P...) noexcept;
    using result_type = RV;
    using scope = C;
    using is_const = std::false_type;

    static constexpr auto get() noexcept -> pointer {
        return Ptr;
    }

    static auto free_func(C* c, P... a) noexcept -> RV {
        return (c->*Ptr)(std::forward<P>(a)...);
    }

    static auto make_free() noexcept -> free_pointer {
        return &free_func;
    }
};

template <typename RV, typename C, typename... P, RV (C::*Ptr)(P...) const noexcept>
struct member_function_constant<RV (C::*)(P...) const noexcept, Ptr> {
    using pointer = RV (C::*)(P...) const noexcept;
    using free_pointer = RV (*)(const C*, P...) noexcept;
    using result_type = RV;
    using scope = C;
    using is_const = std::true_type;

    static constexpr auto get() noexcept -> pointer {
        return Ptr;
    }

    static auto free_func(const C* c, P... a) noexcept -> RV {
        return (c->*Ptr)(std::forward<P>(a)...);
    }

    static auto make_free() noexcept -> free_pointer {
        return &free_func;
    }
};

#define EAGINE_MEM_FUNC_T(CLASS, FUNC) \
    ::eagine::member_function_constant<decltype(&CLASS::FUNC), &CLASS::FUNC>
#define EAGINE_MEM_FUNC_C(CLASS, FUNC) \
    EAGINE_MEM_FUNC_T(CLASS, FUNC) {}

#define EAGINE_THIS_T() std::remove_cv_t<std::remove_pointer_t<decltype(this)>>

#define EAGINE_THIS_MEM_FUNC_T(FUNC)    \
    ::eagine::member_function_constant< \
      decltype(&EAGINE_THIS_T()::FUNC), \
      &EAGINE_THIS_T()::FUNC>
#define EAGINE_THIS_MEM_FUNC_C(FUNC) \
    EAGINE_THIS_MEM_FUNC_T(FUNC) {}

} // namespace eagine

#endif // EAGINE_MEM_FUNC_CONST_HPP
