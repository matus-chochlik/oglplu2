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

/// @brief Declaration of compile-time member function pointer wrappers.
/// @ingroup functional
template <typename T, T Ptr>
struct member_function_constant;

/// @brief Implementation of compile-time member function pointer wrappers.
/// @ingroup functional
template <typename RV, typename C, typename... P, RV (C::*Ptr)(P...)>
struct member_function_constant<RV (C::*)(P...), Ptr> {

    /// @brief Alias for the member function pointer type.
    using pointer = RV (C::*)(P...);

    /// @brief Alias for corresponding free function pointer type.
    using free_pointer = RV (*)(C*, P...);

    /// @brief Alias for the function result type.
    using result_type = RV;

    /// @brief Alias for the class to which the member function belongs.
    using scope = C;

    /// @brief Alias for type indicating if the member function is const.
    using is_const = std::false_type;

    /// @brief Returns the member function pointer.
    /// @see free_func
    static constexpr auto get() noexcept -> pointer {
        return Ptr;
    }

    /// @brief A function that calls the member function on an instance of @p C.
    /// @see make_free
    static auto free_func(C* c, P... a) -> RV {
        return (c->*Ptr)(std::forward<P>(a)...);
    }

    /// @brief Returns pointer to a free function corresponding to the member function.
    /// @see get
    /// @see free_func
    static auto make_free() noexcept -> free_pointer {
        return &free_func;
    }
};

template <typename RV, typename C, typename... P, RV (C::*Ptr)(P...) const>
struct member_function_constant<RV (C::*)(P...) const, Ptr> {

    /// @brief Alias for the member function pointer type.
    using pointer = RV (C::*)(P...) const;

    /// @brief Alias for corresponding free function pointer type.
    using free_pointer = RV (*)(const C*, P...);

    /// @brief Alias for the function result type.
    using result_type = RV;

    /// @brief Alias for the class to which the member function belongs.
    using scope = C;

    /// @brief Alias for type indicating if the member function is const.
    using is_const = std::true_type;

    /// @brief Returns the member function pointer.
    /// @see free_func
    static constexpr auto get() noexcept -> pointer {
        return Ptr;
    }

    /// @brief A function that calls the member function on an instance of @p C.
    /// @see make_free
    static auto free_func(const C* c, P... a) -> RV {
        return (c->*Ptr)(std::forward<P>(a)...);
    }

    /// @brief Returns pointer to a free function corresponding to the member function.
    /// @see get
    /// @see free_func
    static auto make_free() noexcept -> free_pointer {
        return &free_func;
    }
};

template <typename RV, typename C, typename... P, RV (C::*Ptr)(P...) noexcept>
struct member_function_constant<RV (C::*)(P...) noexcept, Ptr> {

    /// @brief Alias for the member function pointer type.
    using pointer = RV (C::*)(P...) noexcept;

    /// @brief Alias for corresponding free function pointer type.
    using free_pointer = RV (*)(C*, P...) noexcept;

    /// @brief Alias for the function result type.
    using result_type = RV;

    /// @brief Alias for the class to which the member function belongs.
    using scope = C;

    /// @brief Alias for type indicating if the member function is const.
    using is_const = std::false_type;

    /// @brief Returns the member function pointer.
    /// @see free_func
    static constexpr auto get() noexcept -> pointer {
        return Ptr;
    }

    /// @brief A function that calls the member function on an instance of @p C.
    /// @see make_free
    static auto free_func(C* c, P... a) noexcept -> RV {
        return (c->*Ptr)(std::forward<P>(a)...);
    }

    /// @brief Returns pointer to a free function corresponding to the member function.
    /// @see get
    /// @see free_func
    static auto make_free() noexcept -> free_pointer {
        return &free_func;
    }
};

template <typename RV, typename C, typename... P, RV (C::*Ptr)(P...) const noexcept>
struct member_function_constant<RV (C::*)(P...) const noexcept, Ptr> {

    /// @brief Alias for the member function pointer type.
    using pointer = RV (C::*)(P...) const noexcept;

    /// @brief Alias for corresponding free function pointer type.
    using free_pointer = RV (*)(const C*, P...) noexcept;

    /// @brief Alias for the function result type.
    using result_type = RV;

    /// @brief Alias for the class to which the member function belongs.
    using scope = C;

    /// @brief Alias for type indicating if the member function is const.
    using is_const = std::true_type;

    /// @brief Returns the member function pointer.
    /// @see free_func
    static constexpr auto get() noexcept -> pointer {
        return Ptr;
    }

    /// @brief A function that calls the member function on an instance of @p C.
    /// @see make_free
    static auto free_func(const C* c, P... a) noexcept -> RV {
        return (c->*Ptr)(std::forward<P>(a)...);
    }

    /// @brief Returns pointer to a free function corresponding to the member function.
    /// @see get
    /// @see free_func
    static auto make_free() noexcept -> free_pointer {
        return &free_func;
    }
};

/// @brief Macro for instantiating the member_function_constant template.
/// @ingroup functional
/// @see EAGINE_MEM_FUNC_C
/// @see EAGINE_THIS_MEM_FUNC_T
#define EAGINE_MEM_FUNC_T(CLASS, FUNC) \
    ::eagine::member_function_constant<decltype(&CLASS::FUNC), &CLASS::FUNC>

/// @brief Macro for creating object of member_function_constant.
/// @ingroup functional
/// @see EAGINE_MEM_FUNC_T
/// @see EAGINE_THIS_MEM_FUNC_C
#define EAGINE_MEM_FUNC_C(CLASS, FUNC) \
    EAGINE_MEM_FUNC_T(CLASS, FUNC) {}

/// @brief Macro that in member function returns the type of the containing class.
/// @ingroup functional
#define EAGINE_THIS_T() std::remove_cv_t<std::remove_pointer_t<decltype(this)>>

/// @brief Macro for instantiating member_function_constant in member functions.
/// @ingroup functional
/// @see EAGINE_MEM_FUNC_T
/// @see EAGINE_THIS_T
#define EAGINE_THIS_MEM_FUNC_T(FUNC)    \
    ::eagine::member_function_constant< \
      decltype(&EAGINE_THIS_T()::FUNC), \
      &EAGINE_THIS_T()::FUNC>

/// @brief Macro for creating object of member_function_constant in member functions.
/// @ingroup functional
/// @see EAGINE_MEM_FUNC_C
/// @see EAGINE_THIS_T
#define EAGINE_THIS_MEM_FUNC_C(FUNC) \
    EAGINE_THIS_MEM_FUNC_T(FUNC) {}

} // namespace eagine

#endif // EAGINE_MEM_FUNC_CONST_HPP
