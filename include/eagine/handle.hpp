/**
 *  @file eagine/handle.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_HANDLE_HPP
#define EAGINE_HANDLE_HPP

namespace eagine {
//------------------------------------------------------------------------------
template <typename Tag, typename Handle, Handle invalid = ~Handle(0)>
class basic_handle {
public:
    ~basic_handle() noexcept = default;
    constexpr basic_handle() noexcept = default;
    constexpr basic_handle(basic_handle&& tmp) noexcept
      : _name{tmp._release()} {
    }
    basic_handle& operator=(basic_handle&& tmp) noexcept {
        _name = tmp._release();
        return *this;
    }
    constexpr basic_handle(const basic_handle&) noexcept = default;
    basic_handle& operator=(const basic_handle&) noexcept = default;

    explicit constexpr basic_handle(Handle name) noexcept
      : _name{name} {
    }

    explicit constexpr operator bool() const noexcept {
        return _name != invalid;
    }

    constexpr bool operator!() const noexcept {
        return _name == invalid;
    }

protected:
    Handle _release() noexcept {
        Handle result = _name;
        _name = invalid;
        return result;
    }

    Handle _name{invalid};
};
//------------------------------------------------------------------------------
template <typename Tag, typename Handle, Handle invalid = ~Handle(0)>
class basic_owned_handle : public basic_handle<Tag, Handle, invalid> {
    using base = basic_handle<Tag, Handle, invalid>;

public:
    ~basic_owned_handle() noexcept = default;
    constexpr basic_owned_handle() noexcept = default;
    constexpr basic_owned_handle(basic_owned_handle&& tmp) noexcept
      : base{tmp.release()} {
    }
    basic_owned_handle& operator=(basic_owned_handle&& tmp) noexcept {
        *static_cast<base*>(this) = static_cast<base&&>(tmp);
        return *this;
    }
    basic_owned_handle(const basic_owned_handle&) = delete;
    basic_owned_handle& operator=(const basic_owned_handle&) = delete;

    explicit constexpr basic_owned_handle(Handle name) noexcept
      : base{name} {
    }

    Handle release() noexcept {
        return this->_release();
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_HANDLE_HPP
