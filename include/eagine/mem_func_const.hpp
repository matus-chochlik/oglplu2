/**
 *  @file eagine/mem_func_const.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEM_FUNC_CONST_1509260923_HPP
#define EAGINE_MEM_FUNC_CONST_1509260923_HPP

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

    static constexpr pointer get() noexcept {
        return Ptr;
    }

    static RV free_func(C* c, P... a) {
        return (c->*Ptr)(std::forward<P>(a)...);
    }

    static free_pointer make_free() noexcept {
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

    static constexpr pointer get() noexcept {
        return Ptr;
    }

    static RV free_func(const C* c, P... a) {
        return (c->*Ptr)(std::forward<P>(a)...);
    }

    static free_pointer make_free() noexcept {
        return &free_func;
    }
};

} // namespace eagine

#endif // include guard
