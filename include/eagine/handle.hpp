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

#include "span.hpp"
#include "wrapping_container.hpp"
#include <array>

namespace eagine {
//------------------------------------------------------------------------------
template <typename Tag, typename Handle, Handle invalid = ~Handle(0)>
class basic_handle {
public:
    using tag_type = Tag;
    using handle_type = Handle;

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

    explicit constexpr operator Handle() const noexcept {
        return _name;
    }

    struct transform {
        constexpr auto operator()(Handle hndl) noexcept {
            return basic_handle<Tag, Handle, invalid>{hndl};
        }
    };

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

    explicit constexpr basic_owned_handle(base adopted) noexcept
      : base{adopted} {
    }

    explicit constexpr basic_owned_handle(Handle name) noexcept
      : base{name} {
    }

    Handle release() noexcept {
        return this->_release();
    }
};
//------------------------------------------------------------------------------
template <typename BasicHandle, typename Container>
class basic_handle_container;

template <typename Tag, typename Handle, Handle invalid, typename Container>
class basic_handle_container<basic_handle<Tag, Handle, invalid>, Container>
  : public basic_wrapping_container<
      Container,
      basic_handle<Tag, Handle, invalid>,
      Handle,
      invalid> {
    using base = basic_wrapping_container<
      Container,
      basic_handle<Tag, Handle, invalid>,
      Handle,
      invalid>;

public:
    using base::base;

    constexpr auto raw_handles() noexcept {
        return this->raw_items();
    }

    constexpr auto raw_handles() const noexcept {
        return this->raw_items();
    }
};
//------------------------------------------------------------------------------
template <typename BasicHandle>
using basic_handle_span =
  basic_handle_container<BasicHandle, span<typename BasicHandle::handle_type>>;

template <typename BasicHandle>
using basic_handle_view = basic_handle_container<
  BasicHandle,
  span<const typename BasicHandle::handle_type>>;

template <typename BasicHandle, std::size_t N>
using basic_handle_array = basic_handle_container<
  BasicHandle,
  std::array<typename BasicHandle::handle_type, N>>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_HANDLE_HPP
