/**
 *  @file eagine/c_api_wrap.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_C_API_WRAP_HPP
#define EAGINE_C_API_WRAP_HPP

#include "identity.hpp"
#include "int_constant.hpp"
#include "string_span.hpp"
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename ApiTraits, typename Signature>
using c_api_function_ptr =
  typename ApiTraits::template function_pointer<Signature>::type;
//------------------------------------------------------------------------------
template <typename ApiTraits, typename T>
using c_api_transform_rv =
  typename ApiTraits::template transform_return_value<T>::type;
//------------------------------------------------------------------------------
template <typename ApiTraits, typename T>
using c_api_transform_param =
  typename ApiTraits::template transform_parameter<T>::type;
//------------------------------------------------------------------------------
template <typename ApiTraits, typename Signature>
class unimplemented_c_api_function;
//------------------------------------------------------------------------------
template <
  typename ApiTraits,
  typename Signature,
  c_api_function_ptr<ApiTraits, Signature> function>
class static_c_api_function;
//------------------------------------------------------------------------------
template <typename ApiTraits, typename Signature>
class dynamic_c_api_function;
//------------------------------------------------------------------------------
template <typename ApiTraits, bool IsImplemented>
class c_api_function_base : public bool_constant<IsImplemented> {
public:
    constexpr c_api_function_base(string_view name) noexcept
      : _name{name} {
    }

    constexpr bool is_implemented() const noexcept {
        return IsImplemented;
    }

    constexpr operator bool() const noexcept {
        return IsImplemented;
    }
    constexpr bool operator!() const noexcept {
        return !IsImplemented;
    }

    constexpr string_view name() const noexcept {
        return _name;
    }

private:
    const string_view _name{};
};
//------------------------------------------------------------------------------
template <typename ApiTraits, typename RV, typename... Params>
class unimplemented_c_api_function<ApiTraits, RV(Params...)>
  : public c_api_function_base<ApiTraits, false> {
    using base = c_api_function_base<ApiTraits, false>;

public:
    constexpr unimplemented_c_api_function(string_view name, const ApiTraits&)
      : base(name) {
    }

    template <typename... Args>
    constexpr std::enable_if_t<
      sizeof...(Params) == sizeof...(Args),
      c_api_transform_rv<ApiTraits, RV>>
    operator()(Args&&...) const noexcept {
        return ApiTraits::fallback(identity<RV>());
    }
};
//------------------------------------------------------------------------------
template <
  typename ApiTraits,
  typename RV,
  typename... Params,
  c_api_function_ptr<ApiTraits, RV(Params...)> function>
class static_c_api_function<ApiTraits, RV(Params...), function>
  : public c_api_function_base<ApiTraits, true> {
    using base = c_api_function_base<ApiTraits, true>;

public:
    constexpr static_c_api_function(string_view name, const ApiTraits&)
      : base(name) {
    }

    template <typename... Args>
    constexpr std::enable_if_t<
      sizeof...(Params) == sizeof...(Args),
      c_api_transform_rv<ApiTraits, RV>>
    operator()(Args&&... args) const noexcept {
        return ApiTraits::call(function, std::forward<Args>(args)...);
    }
};
//------------------------------------------------------------------------------
template <typename ApiTraits, typename RV, typename... Params>
class dynamic_c_api_function<ApiTraits, RV(Params...)>
  : public c_api_function_base<ApiTraits, true> {

    using base = c_api_function_base<ApiTraits, true>;
    using function_pointer = c_api_function_ptr<ApiTraits, RV(Params...)>;

public:
    constexpr dynamic_c_api_function(string_view name, ApiTraits& traits)
      : base(name)
      , _function{traits.load_function(name, identity<RV(Params...)>())} {
    }

    constexpr operator bool() const noexcept {
        return bool(_function);
    }
    constexpr bool operator!() const noexcept {
        return !_function;
    }

    template <typename... Args>
    constexpr std::enable_if_t<
      sizeof...(Params) == sizeof...(Args),
      c_api_transform_rv<ApiTraits, RV>>
    operator()(Args&&... args) const noexcept {
        if(_function) {
            return ApiTraits::call(_function, std::forward<Args>(args)...);
        }
        return ApiTraits::fallback(identity<RV>());
    }

private:
    function_pointer _function{nullptr};
};
//------------------------------------------------------------------------------
template <
  typename ApiTraits,
  typename Signature,
  c_api_function_ptr<ApiTraits, Signature> function,
  bool IsAvailable>
using opt_c_api_function = std::conditional_t<
  IsAvailable,
  std::conditional_t<
    bool(function),
    static_c_api_function<ApiTraits, Signature, function>,
    dynamic_c_api_function<ApiTraits, Signature>>,
  unimplemented_c_api_function<ApiTraits, Signature>>;
//------------------------------------------------------------------------------

} // namespace eagine

#endif // EAGINE_C_API_WRAP_HPP

