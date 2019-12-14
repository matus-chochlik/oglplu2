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

#include "assert.hpp"
#include "identity.hpp"
#include "int_constant.hpp"
#include "string_span.hpp"
#include "valid_if/always.hpp"
#include "valid_if/never.hpp"
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
template <typename Result>
class api_no_result_value {
public:
    constexpr api_no_result_value() noexcept = default;
};

template <typename Result>
static constexpr inline Result& extract(api_no_result_value<Result>&) noexcept {
    EAGINE_UNREACHABLE();
    return *static_cast<Result*>(nullptr);
}

template <typename Result>
static constexpr inline const Result& extract(
  const api_no_result_value<Result>&) noexcept {
    EAGINE_UNREACHABLE();
    return *static_cast<const Result*>(nullptr);
}
//------------------------------------------------------------------------------
template <>
class api_no_result_value<void> {
public:
};
//------------------------------------------------------------------------------
template <typename Result, typename Info>
class api_no_result
  : public Info
  , public api_no_result_value<Result> {
    using base = api_no_result_value<Result>;

public:
    using base::base;

    explicit constexpr operator bool() const noexcept {
        return false;
    }

    constexpr bool operator!() const noexcept {
        return true;
    }
};
//------------------------------------------------------------------------------
template <typename Result>
class api_result_value {
public:
    constexpr api_result_value() noexcept = default;

    constexpr api_result_value(Result value) noexcept
      : _value{std::move(value)} {
    }

    Result _value{};
};

template <typename Result>
static constexpr Result extract(api_result_value<Result>&& res) noexcept {
    return std::move(res._value);
}

template <typename Result>
static constexpr Result& extract(api_result_value<Result>& res) noexcept {
    return res._value;
}

template <typename Result>
static constexpr const Result& extract(
  const api_result_value<Result>& res) noexcept {
    return res._value;
}
//------------------------------------------------------------------------------
template <>
class api_result_value<void> {
public:
};
//------------------------------------------------------------------------------
template <typename Result, typename Info>
class api_result
  : public Info
  , public api_result_value<Result> {
    using base = api_result_value<Result>;

public:
    using base::base;

    explicit constexpr operator bool() const noexcept {
        return true;
    }

    constexpr bool operator!() const noexcept {
        return false;
    }
};
//------------------------------------------------------------------------------
template <typename Result>
class api_opt_result_value {
public:
    constexpr api_opt_result_value() noexcept = default;

    constexpr api_opt_result_value(Result value, bool valid) noexcept
      : _value{std::move(value)}
      , _valid{valid} {
    }

    constexpr bool is_valid() const noexcept {
        return _valid;
    }

    friend constexpr Result extract(api_opt_result_value&& res) noexcept {
        return EAGINE_CONSTEXPR_ASSERT(res._valid, std::move(res._value));
    }

    friend constexpr Result& extract(api_opt_result_value& res) noexcept {
        return EAGINE_CONSTEXPR_ASSERT(res._valid, res._value);
    }

    friend constexpr const Result& extract(
      const api_opt_result_value& res) noexcept {
        return EAGINE_CONSTEXPR_ASSERT(res._valid, res._value);
    }

private:
    Result _value{};
    bool _valid{false};
};
//------------------------------------------------------------------------------
template <>
class api_opt_result_value<void> {
public:
    constexpr api_opt_result_value() noexcept = default;

    constexpr api_opt_result_value(bool valid) noexcept
      : _valid{valid} {
    }

private:
    bool _valid{false};
};
//------------------------------------------------------------------------------
template <typename Result, typename Info>
class api_opt_result
  : public Info
  , public api_opt_result_value<Result> {
    using base = api_opt_result_value<Result>;

public:
    using base::base;

    explicit constexpr operator bool() const noexcept {
        return this->is_valid();
    }

    constexpr bool operator!() const noexcept {
        return !this->is_valid();
    }
};
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
struct default_c_api_traits {
    template <typename Tag, typename Signature>
    using function_pointer = std::add_pointer<Signature>;

    template <typename Tag, typename Signature>
    std::add_pointer_t<Signature> load_function(
      Tag, string_view, identity<Signature>) {
        return nullptr;
    }

    template <typename Tag, typename RV>
    static constexpr RV fallback(Tag, identity<RV>) {
        return {};
    }

    template <typename Tag>
    static constexpr void fallback(Tag, identity<void>) {
    }

    template <typename RV, typename Tag, typename... Params, typename... Args>
    static constexpr RV call_static(
      Tag, RV (*function)(Params...), Args&&... args) {
        return function(std::forward<Args>(args)...);
    }

    template <typename RV, typename Tag, typename... Params, typename... Args>
    static constexpr RV call_dynamic(
      Tag tag, RV (*function)(Params...), Args&&... args) {
        if(function) {
            return function(std::forward<Args>(args)...);
        }
        return fallback(tag, identity<RV>());
    }

    template <typename RV>
    using no_result = never_valid<RV>;

    template <typename RV>
    using opt_result = optionally_valid<RV>;

    template <typename RV>
    using result = always_valid<RV>;
};
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
    template <typename Api>
    constexpr unimplemented_c_api_function(
      string_view name, const ApiTraits&, Api&)
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
    template <typename Api>
    constexpr static_c_api_function(string_view name, const ApiTraits&, Api&)
      : base(name) {
    }

    template <typename... Args>
    constexpr std::enable_if_t<sizeof...(Params) == sizeof...(Args), RV>
    operator()(Args&&... args) const noexcept {
        return ApiTraits::call_static(
          Tag(), function, std::forward<Args>(args)...);
    }
};
//------------------------------------------------------------------------------
template <typename ApiTraits, typename Tag, typename RV, typename... Params>
class dynamic_c_api_function<ApiTraits, Tag, RV(Params...)>
  : public c_api_function_base<ApiTraits, true> {

    using base = c_api_function_base<ApiTraits, true>;
    using function_pointer = c_api_function_ptr<ApiTraits, Tag, RV(Params...)>;

public:
    template <typename Api>
    constexpr dynamic_c_api_function(string_view name, ApiTraits& traits, Api&)
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
        return ApiTraits::call_dynamic(
          Tag(), _function, std::forward<Args>(args)...);
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
protected:
    template <typename RV, typename... Params, typename... Args>
    static constexpr typename ApiTraits::template no_result<RV> call(
      const unimplemented_c_api_function<ApiTraits, Tag, RV(Params...)>&,
      Args&&...) noexcept {
        return {};
    }

    template <
      typename RV,
      typename... Params,
      typename... Args,
      RV (*Func)(Params...)>
    static constexpr typename ApiTraits::template result<RV> call(
      static_c_api_function<ApiTraits, Tag, RV(Params...), Func>& function,
      Args&&... args) noexcept {
        return {std::move(function(std::forward<Args>(args)...))};
    }

    template <typename... Params, typename... Args, void (*Func)(Params...)>
    static constexpr typename ApiTraits::template result<void> call(
      static_c_api_function<ApiTraits, Tag, void(Params...), Func>& function,
      Args&&... args) noexcept {
        function(std::forward<Args>(args)...);
        return {};
    }

    template <typename RV, typename... Params, typename... Args>
    static constexpr typename ApiTraits::template opt_result<RV> call(
      dynamic_c_api_function<ApiTraits, Tag, RV(Params...)>& function,
      Args&&... args) noexcept {
        return {
          std::move(function(std::forward<Args>(args)...)), bool(function)};
    }

    template <typename... Params, typename... Args>
    static constexpr typename ApiTraits::template opt_result<void> call(
      dynamic_c_api_function<ApiTraits, Tag, void(Params...)>& function,
      Args&&... args) noexcept {
        function(std::forward<Args>(args)...);
        return {bool(function)};
    }

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

