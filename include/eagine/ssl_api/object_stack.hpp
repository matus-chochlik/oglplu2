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

    constexpr object_stack& set(int, basic_handle<Tag, nothing_t*, nullptr>) {
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
template <>
class object_stack<x509> {
    static auto* _unpack(x509 obj) noexcept {
        return static_cast<::X509*>(obj);
    }

public:
    object_stack() noexcept
      : _top{sk_X509_new_null()} {
    }

    object_stack(object_stack&& temp) noexcept
      : _top{temp._top} {
        temp._top = nullptr;
    }

    object_stack(const object_stack&) = delete;

    object_stack& operator=(object_stack&& temp) noexcept {
        using std::swap;
        swap(_top, temp._top);
        return *this;
    }

    object_stack& operator=(const object_stack&) = delete;

    ~object_stack() noexcept {
        sk_X509_free(_top);
    }

    int size() const noexcept {
        return sk_X509_num(_top);
    }

    object_stack& push(x509 obj) {
        sk_X509_push(_top, _unpack(obj));
        return *this;
    }

    object_stack& pop() {
        sk_X509_pop(_top);
        return *this;
    }

    object_stack& set(int pos, x509 obj) {
        EAGINE_ASSERT(pos < size());
        sk_X509_set(_top, pos, _unpack(obj));
        return *this;
    }

    x509 get(int pos) {
        EAGINE_ASSERT(pos < size());
        return x509{sk_X509_value(_top, pos)};
    }

    STACK_OF(X509) * native() const noexcept {
        return _top;
    }

private:
    STACK_OF(X509) * _top{nullptr};
};
#endif
//------------------------------------------------------------------------------
} // namespace sslp
} // namespace eagine

#endif // EAGINE_SSL_API_OBJECT_STACK_HPP
