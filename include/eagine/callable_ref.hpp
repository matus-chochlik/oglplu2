/// @file eagine/callable_ref.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_CALLABLE_REF_HPP
#define EAGINE_CALLABLE_REF_HPP

#include "assert.hpp"
#include "mem_func_const.hpp"
#include "selector.hpp"
#include "type_traits.hpp"
#include <utility>

namespace eagine {

template <typename FuncSig, bool NoExcept>
class callable_ref_impl;

template <typename RV, typename... P, bool NE>
class callable_ref_impl<RV(P...) noexcept(NE), NE> {
private:
    void* _data{nullptr};
    void (*_func)() noexcept(NE){nullptr};

    using _func_t = void (*)() noexcept(NE);
    using _func_pt = RV (*)(P...) noexcept(NE);
    using _func_vpt = RV (*)(void*, P...) noexcept(NE);

    template <typename C>
    static auto _cls_fn_call_op(void* that, P... p) noexcept(NE) -> RV {
        EAGINE_ASSERT(that);
        C& obj = *(static_cast<C*>(that));

        // NOLINTNEXTLINE(hicpp-braces-around-statements,readability-braces-around-statements)
        if constexpr(std::is_void_v<RV>) {
            obj(std::forward<P>(p)...);
        } else {
            return obj(std::forward<P>(p)...);
        }
    }

    template <typename C>
    static auto _cls_fn_call_op_c(void* that, P... p) noexcept(NE) -> RV {
        EAGINE_ASSERT(that);
        const C& obj = *(static_cast<const C*>(that));

        // NOLINTNEXTLINE(hicpp-braces-around-statements,readability-braces-around-statements)
        if constexpr(std::is_void_v<RV>) {
            obj(std::forward<P>(p)...);
        } else {
            return obj(std::forward<P>(p)...);
        }
    }

public:
    using argument_tuple_type =
      std::tuple<std::remove_cv_t<std::remove_reference_t<P>>...>;

    static auto argument_tuple() noexcept {
        return argument_tuple_type{};
    }

    constexpr callable_ref_impl() noexcept = default;

    constexpr callable_ref_impl(callable_ref_impl&& temp) noexcept
      : _data{std::exchange(temp._data, nullptr)}
      , _func{std::exchange(temp._func, nullptr)} {}

    constexpr callable_ref_impl(const callable_ref_impl&) noexcept = default;

    constexpr auto operator=(callable_ref_impl&& temp) noexcept
      -> callable_ref_impl& {
        std::swap(temp._data, _data);
        std::swap(temp._func, _func);
        return *this;
    }
    constexpr auto operator=(const callable_ref_impl&) noexcept
      -> callable_ref_impl& = default;

    ~callable_ref_impl() noexcept = default;

    callable_ref_impl(RV (*func)(P...) noexcept(NE)) noexcept
      : _func(reinterpret_cast<_func_t>(func)) {}

    template <typename T>
    callable_ref_impl(T* data, RV (*func)(T*, P...) noexcept(NE)) noexcept
      : _data(static_cast<void*>(data))
      , _func(reinterpret_cast<_func_t>(func)) {
        EAGINE_ASSERT(_data != nullptr);
    }

    template <typename T>
    callable_ref_impl(T& data, RV (*func)(T*, P...) noexcept(NE)) noexcept
      : _data(static_cast<void*>(&data))
      , _func(reinterpret_cast<_func_t>(func)) {}

    template <
      typename C,
      typename = std::enable_if_t<!std::is_same_v<C, callable_ref_impl>>>
    callable_ref_impl(construct_from_t, C& obj) noexcept
      : _data(static_cast<void*>(&obj))
      , _func(reinterpret_cast<_func_t>(&_cls_fn_call_op<C>)) {}

    template <
      typename C,
      typename = std::enable_if_t<!std::is_same_v<C, callable_ref_impl>>>
    callable_ref_impl(construct_from_t, const C& obj) noexcept
      : _data(static_cast<void*>(const_cast<C*>(&obj)))
      , _func(reinterpret_cast<_func_t>(&_cls_fn_call_op_c<C>)) {}

    template <typename C, RV (C::*Ptr)(P...) noexcept(NE)>
    callable_ref_impl(
      C* obj,
      member_function_constant<RV (C::*)(P...) noexcept(NE), Ptr> mfc) noexcept
      : _data(static_cast<void*>(obj))
      , _func(reinterpret_cast<_func_t>(mfc.make_free())) {
        EAGINE_ASSERT(_data != nullptr);
        EAGINE_ASSERT(_func != nullptr);
    }

    template <typename C, RV (C::*Ptr)(P...) const noexcept(NE)>
    callable_ref_impl(
      const C* obj,
      member_function_constant<RV (C::*)(P...) const noexcept(NE), Ptr>
        mfc) noexcept
      : _data(static_cast<void*>(const_cast<C*>(obj)))
      , _func(reinterpret_cast<_func_t>(mfc.make_free())) {
        EAGINE_ASSERT(_data != nullptr);
        EAGINE_ASSERT(_func != nullptr);
    }

    constexpr auto is_valid() const noexcept {
        return _func != nullptr;
    }

    explicit constexpr operator bool() const noexcept {
        return is_valid();
    }

    template <typename... A>
    auto operator()(A&&... a) const -> RV {
        EAGINE_ASSERT(is_valid());
        if(_data == nullptr) {
            return (reinterpret_cast<_func_pt>(_func))(std::forward<A>(a)...);
        } else {
            return (reinterpret_cast<_func_vpt>(_func))(
              _data, std::forward<A>(a)...);
        }
    }
};

template <typename Sig>
using callable_ref = callable_ref_impl<Sig, is_noexcept_function_v<Sig>>;

} // namespace eagine

#endif // EAGINE_CALLABLE_REF_HPP
