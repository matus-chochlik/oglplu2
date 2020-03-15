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
#include "enum_class.hpp"
#include "extract.hpp"
#include "identity.hpp"
#include "int_constant.hpp"
#include "is_within_limits.hpp"
#include "nothing.hpp"
#include "string_span.hpp"
#include "valid_if/always.hpp"
#include "valid_if/never.hpp"
#include <tuple>
#include <type_traits>

namespace eagine {
//------------------------------------------------------------------------------
struct c_api_constant_base {
public:
    constexpr c_api_constant_base(string_view name) noexcept
      : _name{name} {
    }

    constexpr string_view name() const noexcept {
        return _name;
    }

private:
    string_view _name{};
};
//------------------------------------------------------------------------------
template <typename T, typename Tag = nothing_t, bool is_indexed = false>
struct no_c_api_constant
  : c_api_constant_base
  , no_enum_value<T, Tag> {
public:
    template <typename ApiTraits, typename Api>
    constexpr no_c_api_constant(string_view name, ApiTraits&, Api&) noexcept
      : c_api_constant_base{name} {
    }

    template <typename I>
    constexpr std::
      enable_if_t<(is_indexed && std::is_integral_v<I>), no_enum_value<T, Tag>>
      operator+(I) const noexcept {
        return {};
    }
};
//------------------------------------------------------------------------------
template <
  typename ClassList,
  typename T,
  T value,
  typename Tag = nothing_t,
  bool is_indexed = false>
struct static_c_api_constant
  : c_api_constant_base
  , enum_value<T, ClassList, Tag> {
public:
    template <typename ApiTraits, typename Api>
    constexpr static_c_api_constant(string_view name, ApiTraits&, Api&) noexcept
      : c_api_constant_base{name}
      , enum_value<T, ClassList, Tag>{value} {
    }

    template <typename I>
    constexpr std::enable_if_t<
      (is_indexed && std::is_integral_v<I>),
      enum_value<T, ClassList, Tag>>
    operator+(I index) const noexcept {
        using O = std::conditional_t<
          std::is_signed_v<T>,
          std::make_signed_t<I>,
          std::make_unsigned_t<I>>;
        return {limit_cast<T>(value + limit_cast<O>(index))};
    }
};
//------------------------------------------------------------------------------
template <
  typename ClassList,
  typename T,
  typename Tag = nothing_t,
  bool is_indexed = false>
struct dynamic_c_api_constant
  : c_api_constant_base
  , opt_enum_value<T, ClassList, Tag> {
public:
    using tag_type = Tag;

    template <typename ApiTraits, typename Api>
    constexpr dynamic_c_api_constant(
      string_view name, ApiTraits& traits, Api& api) noexcept
      : c_api_constant_base{name}
      , opt_enum_value<T, ClassList, Tag>{
          traits.load_constant(api, name, identity<T>())} {
    }

    template <typename I>
    constexpr std::enable_if_t<
      (is_indexed && std::is_integral_v<I>),
      opt_enum_value<T, ClassList, Tag>>
    operator+(I index) const noexcept {
        using O = std::conditional_t<
          std::is_signed_v<T>,
          std::make_signed_t<I>,
          std::make_unsigned_t<I>>;
        return {limit_cast<T>(this->value + limit_cast<O>(index))};
    }
};
//------------------------------------------------------------------------------
template <typename ClassList, typename Constant, typename Tag, bool is_indexed>
struct get_opt_c_api_constant;

template <
  typename ClassList,
  typename T,
  T value,
  typename Tag,
  bool is_indexed>
struct get_opt_c_api_constant<
  ClassList,
  std::integral_constant<T, value>,
  Tag,
  is_indexed>
  : identity<static_c_api_constant<ClassList, T, value, Tag, is_indexed>> {};

template <typename ClassList, typename T, typename Tag, bool is_indexed>
struct get_opt_c_api_constant<ClassList, identity<T>, Tag, is_indexed>
  : identity<dynamic_c_api_constant<ClassList, T, Tag, is_indexed>> {};

template <
  typename ClassList,
  typename Constant,
  typename Tag = nothing_t,
  bool is_indexed = false>
using opt_c_api_constant =
  typename get_opt_c_api_constant<ClassList, Constant, Tag, is_indexed>::type;
//------------------------------------------------------------------------------
template <typename Result, typename Info>
class api_no_result;
template <typename Result, typename Info>
class api_result;
template <typename Result, typename Info>
class api_opt_result;
//------------------------------------------------------------------------------
template <typename Result>
class api_no_result_value {
public:
    constexpr api_no_result_value() noexcept = default;

protected:
    template <typename Info, typename Transform>
    auto _transformed(
      const api_no_result<Result, Info>& src, Transform& transform) const {
        using T = decltype(transform(std::declval<Result>()));
        api_no_result<T, Info> result{};
        static_cast<Info&>(result) = static_cast<const Info&>(src);
        return result;
    }
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
protected:
    template <typename Info, typename Transform>
    auto _transformed(
      const api_no_result<void, Info>& src, Transform& transform) const {
        using T = decltype(transform());
        api_no_result<T, Info> result{};
        static_cast<Info&>(result) = static_cast<const Info&>(src);
        return result;
    }
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

    template <typename Transform>
    auto transformed(Transform transform) const {
        return this->_transformed(*this, transform);
    }
};
//------------------------------------------------------------------------------
template <typename Result, typename Info>
struct ok_traits<api_no_result<Result, Info>> {
    static constexpr const Info& nok_info(
      const api_no_result<Result, Info>& r) noexcept {
        return r;
    }
};
//------------------------------------------------------------------------------
template <typename Result, typename Info, typename Fallback>
static constexpr inline Result extract_or(
  const api_no_result<Result, Info>&, Fallback&& fallback) noexcept {
    EAGINE_UNREACHABLE();
    return {std::forward<Fallback>(fallback)};
}
//------------------------------------------------------------------------------
template <typename Result>
class api_result_value {
public:
    constexpr api_result_value() noexcept(noexcept(Result{})) = default;

    constexpr api_result_value(Result value) noexcept
      : _value{std::move(value)} {
    }

protected:
    template <typename Info, typename Transform>
    auto _transformed(
      const api_result<Result, Info>& src, Transform& transform) const {
        using T = decltype(transform(std::declval<Result>()));
        api_result<T, Info> result{transform(_value)};
        static_cast<Info&>(result) = static_cast<const Info&>(src);
        return result;
    }

public:
    Result _value{};
};

template <typename Result>
static constexpr Result extract(api_result_value<Result>&& result) noexcept {
    return std::move(result._value);
}

template <typename Result>
static constexpr Result& extract(api_result_value<Result>& result) noexcept {
    return result._value;
}

template <typename Result>
static constexpr const Result& extract(
  const api_result_value<Result>& result) noexcept {
    return result._value;
}
//------------------------------------------------------------------------------
template <>
class api_result_value<void> {
protected:
    template <typename Info, typename Transform>
    auto _transformed(
      const api_result<void, Info>& src, Transform& transform) const {
        using T = decltype(transform());
        api_result<T, Info> result{transform()};
        static_cast<Info&>(result) = static_cast<const Info&>(src);
        return result;
    }
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
        return bool(*static_cast<const Info*>(this));
    }

    constexpr bool operator!() const noexcept {
        return !(*static_cast<const Info*>(this));
    }

    template <typename Transform>
    auto transformed(Transform transform) const {
        return this->_transformed(*this, transform);
    }
};
//------------------------------------------------------------------------------
template <typename Result, typename Info>
struct ok_traits<api_result<Result, Info>> {
    static constexpr const Info& nok_info(
      const api_result<Result, Info>& r) noexcept {
        return r;
    }
};
//------------------------------------------------------------------------------
template <typename Result, typename Info, typename Fallback>
static constexpr inline Result extract_or(
  const api_result<Result, Info>& result, Fallback&& fallback) noexcept {
    if(result) {
        return extract(result);
    }
    return {std::forward<Fallback>(fallback)};
}
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

protected:
    template <typename Info, typename Transform>
    auto _transformed(
      const api_opt_result<Result, Info>& src, Transform& transform) const {
        using T = decltype(transform(std::declval<Result>()));
        api_opt_result<T, Info> result{transform(_value), src.is_valid()};
        static_cast<Info&>(result) = static_cast<const Info&>(src);
        return result;
    }

public:
    Result _value{};
    bool _valid{false};
};

template <typename Result>
static constexpr inline Result extract(
  api_opt_result_value<Result>&& result) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(result._valid, std::move(result._value));
}

template <typename Result>
static constexpr inline Result& extract(
  api_opt_result_value<Result>& result) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(result._valid, result._value);
}

template <typename Result>
static constexpr inline const Result& extract(
  const api_opt_result_value<Result>& result) noexcept {
    return EAGINE_CONSTEXPR_ASSERT(result._valid, result._value);
}
//------------------------------------------------------------------------------
template <>
class api_opt_result_value<void> {
public:
    constexpr api_opt_result_value() noexcept = default;

    constexpr api_opt_result_value(bool valid) noexcept
      : _valid{valid} {
    }

protected:
    template <typename Info, typename Transform>
    auto _transformed(
      const api_opt_result<void, Info>& src, Transform& transform) const {
        using T = decltype(transform());
        api_opt_result<T, Info> result{transform(), src.is_valid()};
        static_cast<Info&>(result) = static_cast<const Info&>(src);
        return result;
    }

public:
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
        return this->is_valid() && bool(*static_cast<const Info*>(this));
    }

    constexpr bool operator!() const noexcept {
        return !this->is_valid() || !(*static_cast<const Info*>(this));
    }

    template <typename Transform>
    auto transformed(Transform transform) const {
        return this->_transformed(*this, transform);
    }
};
//------------------------------------------------------------------------------
template <typename Result, typename Info>
struct ok_traits<api_opt_result<Result, Info>> {
    static constexpr const Info& nok_info(
      const api_opt_result<Result, Info>& r) noexcept {
        return r;
    }
};
//------------------------------------------------------------------------------
template <typename Result, typename Info, typename Fallback>
static constexpr inline Result extract_or(
  const api_opt_result<Result, Info>& result, Fallback&& fallback) noexcept {
    if(result) {
        return extract(result);
    }
    return {std::forward<Fallback>(fallback)};
}
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

    template <typename Api, typename Type>
    std::tuple<Type, bool> load_constant(Api&, string_view, identity<Type>) {
        return {{}, false};
    }

    template <typename Api, typename Tag, typename Signature>
    std::add_pointer_t<Signature> link_function(
      Api&, Tag, string_view, identity<Signature>) {
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
    constexpr dynamic_c_api_function(
      string_view name, ApiTraits& traits, Api& api)
      : base(name)
      , _function{
          traits.link_function(api, Tag(), name, identity<RV(Params...)>())} {
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
template <
  typename ApiTraits,
  typename Tag,
  typename Signature,
  c_api_function_ptr<ApiTraits, Tag, Signature> function,
  bool IsAvailable,
  bool IsStatic>
using opt_c_api_function = std::conditional_t<
  IsAvailable,
  std::conditional_t<
    IsStatic,
    static_c_api_function<ApiTraits, Tag, Signature, function>,
    dynamic_c_api_function<ApiTraits, Tag, Signature>>,
  unimplemented_c_api_function<ApiTraits, Tag, Signature>>;
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

    template <typename RV, typename... Params>
    static constexpr typename ApiTraits::template result<RV> fake(
      const unimplemented_c_api_function<ApiTraits, Tag, RV(Params...)>&,
      RV fallback) noexcept {
        return {std::move(fallback)};
    }

    template <
      typename RV,
      typename... Params,
      RV (*Func)(Params...),
      typename F>
    static constexpr typename ApiTraits::template result<RV> fake(
      const static_c_api_function<ApiTraits, Tag, RV(Params...), Func>&,
      F&& fallback) noexcept {
        return {std::forward<F>(fallback)};
    }

    template <typename RV, typename... Params, typename F>
    static constexpr typename ApiTraits::template result<RV> fake(
      const dynamic_c_api_function<ApiTraits, Tag, RV(Params...)>&,
      F&& fallback) noexcept {
        return {std::forward<F>(fallback)};
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

