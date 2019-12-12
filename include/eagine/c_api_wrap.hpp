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
template <typename ApiTraits, typename Tag, typename Signature>
using c_api_function_ptr =
  typename ApiTraits::template function_pointer<Tag, Signature>::type;
//------------------------------------------------------------------------------
template <typename ApiTraits, typename Tag, typename Signature>
class unimplemented_c_api_function;
//------------------------------------------------------------------------------
template <
  typename ApiTraits,
  typename Tag,
  typename Signature,
  c_api_function_ptr<ApiTraits, Tag, Signature> function>
class static_c_api_function;
//------------------------------------------------------------------------------
template <typename ApiTraits, typename Tag, typename Signature>
class dynamic_c_api_function;
//------------------------------------------------------------------------------
template <typename Api, typename ApiTraits, typename Tag>
class derived_c_api_function;
//------------------------------------------------------------------------------
template <typename ApiTraits, bool IsAvailable>
class c_api_function_base : public bool_constant<IsAvailable> {
public:
    constexpr c_api_function_base(string_view name) noexcept
      : _name{name} {
    }

    constexpr explicit operator bool() const noexcept {
        return IsAvailable;
    }
    constexpr bool operator!() const noexcept {
        return !IsAvailable;
    }

    constexpr string_view name() const noexcept {
        return _name;
    }

private:
    const string_view _name{};
};
//------------------------------------------------------------------------------
template <typename ApiTraits, typename Tag, typename RV, typename... Params>
class unimplemented_c_api_function<ApiTraits, Tag, RV(Params...)>
  : public c_api_function_base<ApiTraits, false> {
    using base = c_api_function_base<ApiTraits, false>;

public:
    constexpr unimplemented_c_api_function(string_view name, const ApiTraits&)
      : base(name) {
    }

    template <typename... Args>
    constexpr std::enable_if_t<sizeof...(Params) == sizeof...(Args), RV>
    operator()(Args&&...) const noexcept {
        return ApiTraits::fallback(Tag(), identity<RV>());
    }
};
//------------------------------------------------------------------------------
template <
  typename ApiTraits,
  typename Tag,
  typename RV,
  typename... Params,
  c_api_function_ptr<ApiTraits, Tag, RV(Params...)> function>
class static_c_api_function<ApiTraits, Tag, RV(Params...), function>
  : public c_api_function_base<ApiTraits, true> {
    using base = c_api_function_base<ApiTraits, true>;

public:
    constexpr static_c_api_function(string_view name, const ApiTraits&)
      : base(name) {
    }

    template <typename... Args>
    constexpr std::enable_if_t<sizeof...(Params) == sizeof...(Args), RV>
    operator()(Args&&... args) const noexcept {
        return ApiTraits::call(Tag(), function, std::forward<Args>(args)...);
    }
};
//------------------------------------------------------------------------------
template <typename ApiTraits, typename Tag, typename RV, typename... Params>
class dynamic_c_api_function<ApiTraits, Tag, RV(Params...)>
  : public c_api_function_base<ApiTraits, true> {

    using base = c_api_function_base<ApiTraits, true>;
    using function_pointer = c_api_function_ptr<ApiTraits, Tag, RV(Params...)>;

public:
    constexpr dynamic_c_api_function(string_view name, ApiTraits& traits)
      : base(name)
      , _function{
          traits.load_function(Tag(), name, identity<RV(Params...)>())} {
    }

    constexpr explicit operator bool() const noexcept {
        return bool(_function);
    }
    constexpr bool operator!() const noexcept {
        return !_function;
    }

    template <typename... Args>
    constexpr std::enable_if_t<sizeof...(Params) == sizeof...(Args), RV>
    operator()(Args&&... args) const noexcept {
        return EAGINE_CONSTEXPR_ASSERT(
          _function,
          ApiTraits::call(Tag(), _function, std::forward<Args>(args)...));
    }

private:
    function_pointer _function{nullptr};
};
//------------------------------------------------------------------------------
#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Waddress"
#endif

template <
  typename ApiTraits,
  typename Tag,
  typename Signature,
  c_api_function_ptr<ApiTraits, Tag, Signature> function,
  bool IsAvailable>
using opt_c_api_function = std::conditional_t<
  IsAvailable,
  std::conditional_t<
    bool(function),
    static_c_api_function<ApiTraits, Tag, Signature, function>,
    dynamic_c_api_function<ApiTraits, Tag, Signature>>,
  unimplemented_c_api_function<ApiTraits, Tag, Signature>>;

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
//------------------------------------------------------------------------------
template <typename Api, typename ApiTraits, typename Tag>
class derived_c_api_function {
public:
    constexpr derived_c_api_function(
      string_view name, ApiTraits&, Api& parent) noexcept
      : _name{name}
      , _parent{parent} {
    }

    constexpr string_view name() const noexcept {
        return _name;
    }

protected:
    constexpr Api& api() const noexcept {
        return _parent;
    }

private:
    const string_view _name{};
    Api& _parent;
};
//------------------------------------------------------------------------------

} // namespace eagine

#endif // EAGINE_C_API_WRAP_HPP

