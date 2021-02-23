/// @file
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

/// @brief Declaration of class template storing a reference to a callable object.
/// @ingroup functional
/// @see callable_ref
template <typename FuncSig, bool NoExcept>
class basic_callable_ref;

/// @brief Implementation of class template storing a reference to a callable object.
/// @ingroup functional
/// @see callable_ref
///
/// Unlike std::function basic_callable_ref does not do any conversion on
/// the parameters or return values, the referenced callable must match,
/// and it does not copy the callable, it must remain in scope while the
/// reference is used.
template <typename RV, typename... P, bool NE>
class basic_callable_ref<RV(P...) noexcept(NE), NE> {
public:
    /// @brief Alias for the callable's argument type tuple.
    using argument_tuple_type =
      std::tuple<std::remove_cv_t<std::remove_reference_t<P>>...>;

    /// @brief Creates a default-constructed instance of argument_type_tuple.
    static auto argument_tuple() noexcept -> argument_tuple_type {
        return {};
    }

    /// @brief Default constructor.
    /// @post !is_valid
    constexpr basic_callable_ref() noexcept = default;

    /// @brief Move constructor.
    constexpr basic_callable_ref(basic_callable_ref&& temp) noexcept
      : _data{std::exchange(temp._data, nullptr)}
      , _func{std::exchange(temp._func, nullptr)} {}

    /// @brief Copy constructor.
    constexpr basic_callable_ref(const basic_callable_ref&) noexcept = default;

    /// @brief Move assignment operator.
    constexpr auto operator=(basic_callable_ref&& temp) noexcept
      -> basic_callable_ref& {
        std::swap(temp._data, _data);
        std::swap(temp._func, _func);
        return *this;
    }

    /// @brief Copy assignment operator.
    constexpr auto operator=(const basic_callable_ref&) noexcept
      -> basic_callable_ref& = default;

    ~basic_callable_ref() noexcept = default;

    /// @brief Construction from a pointer to function.
    basic_callable_ref(RV (*func)(P...) noexcept(NE)) noexcept
      : _func{reinterpret_cast<_func_t>(func)} {}

    /// @brief Construction from pointers to an object and a function.
    template <typename T>
    basic_callable_ref(T* data, RV (*func)(T*, P...) noexcept(NE)) noexcept
      : _data{static_cast<void*>(data)}
      , _func{reinterpret_cast<_func_t>(func)} {
        EAGINE_ASSERT(_data != nullptr);
    }

    /// @brief Construction from a reference to an object and a pointer to function.
    template <typename T>
    basic_callable_ref(T& data, RV (*func)(T*, P...) noexcept(NE)) noexcept
      : _data(static_cast<void*>(&data))
      , _func(reinterpret_cast<_func_t>(func)) {}

    /// @brief Construction a reference to object with a call operator.
    template <
      typename C,
      typename = std::enable_if_t<!std::is_same_v<C, basic_callable_ref>>>
    basic_callable_ref(construct_from_t, C& obj) noexcept
      : _data(static_cast<void*>(&obj))
      , _func(reinterpret_cast<_func_t>(&_cls_fn_call_op<C>)) {}

    /// @brief Construction a const reference to object with a call operator.
    template <
      typename C,
      typename = std::enable_if_t<!std::is_same_v<C, basic_callable_ref>>>
    basic_callable_ref(construct_from_t, const C& obj) noexcept
      : _data(static_cast<void*>(const_cast<C*>(&obj)))
      , _func(reinterpret_cast<_func_t>(&_cls_fn_call_op_c<C>)) {}

    /// @brief Construction a pointer to object and member function constant.
    template <typename C, RV (C::*Ptr)(P...) noexcept(NE)>
    basic_callable_ref(
      C* obj,
      member_function_constant<RV (C::*)(P...) noexcept(NE), Ptr> mfc) noexcept
      : _data(static_cast<void*>(obj))
      , _func(reinterpret_cast<_func_t>(mfc.make_free())) {
        EAGINE_ASSERT(_data != nullptr);
        EAGINE_ASSERT(_func != nullptr);
    }

    /// @brief Construction a pointer to const object and member function constant.
    template <typename C, RV (C::*Ptr)(P...) const noexcept(NE)>
    basic_callable_ref(
      const C* obj,
      member_function_constant<RV (C::*)(P...) const noexcept(NE), Ptr>
        mfc) noexcept
      : _data(static_cast<void*>(const_cast<C*>(obj)))
      , _func(reinterpret_cast<_func_t>(mfc.make_free())) {
        EAGINE_ASSERT(_data != nullptr);
        EAGINE_ASSERT(_func != nullptr);
    }

    /// @brief Indicates if this object stores a valid callable reference.
    constexpr auto is_valid() const noexcept {
        return _func != nullptr;
    }

    /// @brief Indicates if this object stores a valid callable reference.
    /// @see is_valid
    explicit constexpr operator bool() const noexcept {
        return is_valid();
    }

    /// @brief Call operator.
    /// @pre is_valid()
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
};

/// @brief Alias for callable object references.
/// @ingroup functional
template <typename Sig>
using callable_ref = basic_callable_ref<Sig, is_noexcept_function_v<Sig>>;

} // namespace eagine

#endif // EAGINE_CALLABLE_REF_HPP
