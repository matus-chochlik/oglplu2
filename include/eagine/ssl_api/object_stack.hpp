/**
 *  @file eagine/ssl_api/object_stack.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_SSL_API_OBJECT_STACK_HPP
#define EAGINE_SSL_API_OBJECT_STACK_HPP

#include "../assert.hpp"
#include "object_handle.hpp"
#include <utility>

namespace eagine {
namespace sslp {
//------------------------------------------------------------------------------
template <typename Handle>
class object_stack;
//------------------------------------------------------------------------------
template <typename Tag>
class object_stack<basic_handle<Tag, nothing_t*, nullptr>> {
public:
    constexpr int size() const noexcept {
        return 0;
    }

    constexpr object_stack& push(basic_handle<Tag, nothing_t*, nullptr>) {
        return *this;
    }

    constexpr object_stack& pop() {
        return *this;
    }

    constexpr basic_handle<Tag, nothing_t*, nullptr> get(int) {
        return {};
    }

    constexpr nothing_t* native() const noexcept {
        return nullptr;
    }
};
//------------------------------------------------------------------------------
#if EAGINE_HAS_SSL
//------------------------------------------------------------------------------
template <typename Tag>
struct stack_api;
//------------------------------------------------------------------------------
template <>
struct stack_api<x509_tag> {
    using stack_type = STACK_OF(X509);
    using element_type = ::X509;

    static auto* unpack(x509 obj) noexcept {
        return static_cast<::X509*>(obj);
    }

    static auto* new_null() noexcept {
        return sk_X509_new_null();
    }

    static auto free(stack_type* h) noexcept {
        return sk_X509_free(h);
    }

    static auto num(stack_type* h) noexcept {
        return sk_X509_num(h);
    }

    static auto push(stack_type* h, element_type* e) noexcept {
        return sk_X509_push(h, e);
    }

    static auto push_up_ref(stack_type* h, element_type* e) noexcept {
        X509_up_ref(e);
        return sk_X509_push(h, e);
    }

    static auto* pop(stack_type* h) noexcept {
        return sk_X509_pop(h);
    }

    static auto pop_free(stack_type* h) noexcept {
        return sk_X509_pop_free(h, &X509_free);
    }

    static auto set(stack_type* h, int i, element_type* e) noexcept {
        return sk_X509_set(h, i, e);
    }

    static auto* value(stack_type* h, int i) noexcept {
        return sk_X509_value(h, i);
    }
};
//------------------------------------------------------------------------------
// object_stack_base
//------------------------------------------------------------------------------
template <typename Handle>
class object_stack_base;

template <typename Tag, typename T>
class object_stack_base<basic_handle<Tag, T*, nullptr>> : stack_api<Tag> {
protected:
    typename stack_api<Tag>::stack_type* _top{nullptr};

    const stack_api<Tag>& _api() const noexcept {
        return *this;
    }

    object_stack_base(typename stack_api<Tag>::stack_type* top) noexcept
      : _top{top} {
    }

    bool _idx_ok(int i) const noexcept {
        return (i >= 0) && (i < size());
    }

    ~object_stack_base() noexcept = default;

public:
    using wrapper = basic_handle<Tag, T*, nullptr>;

    object_stack_base(object_stack_base&& temp) noexcept
      : _top{temp._top} {
        temp._top = nullptr;
    }

    object_stack_base(const object_stack_base&) = delete;

    object_stack_base& operator=(object_stack_base&& temp) noexcept {
        using std::swap;
        swap(_top, temp._top);
        return *this;
    }

    object_stack_base& operator=(const object_stack_base&) = delete;

    int size() const noexcept {
        return _api().num(_top);
    }

    auto get(int pos) {
        EAGINE_ASSERT(_idx_ok(pos));
        return wrapper{_api().value(_top, pos)};
    }

    auto* native() const noexcept {
        return _top;
    }
};
//------------------------------------------------------------------------------
// object_stack
//------------------------------------------------------------------------------
template <typename Tag, typename T>
class object_stack<basic_handle<Tag, T*, nullptr>>
  : object_stack_base<basic_handle<Tag, T*, nullptr>> {

    using base = object_stack_base<basic_handle<Tag, T*, nullptr>>;
    using base::_api;
    using base::_idx_ok;

public:
    using wrapper = basic_handle<Tag, T*, nullptr>;

    object_stack() noexcept
      : base{_api().new_null()} {
    }

    object_stack(object_stack&&) noexcept = delete;
    object_stack(const object_stack&) = delete;
    object_stack& operator=(object_stack&&) noexcept = default;
    object_stack& operator=(const object_stack&) = delete;

    ~object_stack() noexcept {
        _api.free()(this->_top);
    }

    object_stack& push(wrapper obj) {
        _api().push(this->_top, _api().unpack(obj));
        return *this;
    }

    auto pop() {
        return wrapper{_api().pop(this->_top)};
    }
};
//------------------------------------------------------------------------------
// object_stack owned
//------------------------------------------------------------------------------
template <typename Tag, typename T>
class object_stack<basic_owned_handle<Tag, T*, nullptr>>
  : object_stack_base<basic_handle<Tag, T*, nullptr>> {

    using base = object_stack_base<basic_handle<Tag, T*, nullptr>>;
    using base::_api;
    using base::_idx_ok;

public:
    using wrapper = basic_owned_handle<Tag, T*, nullptr>;

    object_stack() noexcept
      : base{_api().new_null()} {
    }

    object_stack(object_stack&&) noexcept = delete;
    object_stack(const object_stack&) = delete;
    object_stack& operator=(object_stack&&) noexcept = default;
    object_stack& operator=(const object_stack&) = delete;

    ~object_stack() noexcept {
        _api.pop_free()(this->_top);
    }

    object_stack& push(wrapper&& obj) {
        _api().push_up_ref(this->_top, _api().unpack(obj.release()));
        return *this;
    }

    auto pop() {
        return wrapper{_api().pop(this->_top)};
    }
};
#endif
//------------------------------------------------------------------------------
} // namespace sslp
} // namespace eagine

#endif // EAGINE_SSL_API_OBJECT_STACK_HPP
