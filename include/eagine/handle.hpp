/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_HANDLE_HPP
#define EAGINE_HANDLE_HPP

#include "span.hpp"
#include "wrapping_container.hpp"
#include <array>

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Non-owning wrapper for C-API opaque handle types.
/// @ingroup c_api_wrap
/// @tparam Tag type distinguisihing various handler with the same underlying type.
/// @tparam Handle the underlying handle type.
/// @tparam invalid the invalid value for this particular handle type.
/// @see basic_owned_handle
template <typename Tag, typename Handle, Handle invalid = ~Handle(0)>
class basic_handle {
public:
    /// @brief Alias for the tag type.
    using tag_type = Tag;

    /// @brief Alias for the underlying handle type.
    using handle_type = Handle;

    ~basic_handle() noexcept = default;

    /// @brief Default constructor.
    /// @post !is_valid()
    constexpr basic_handle() noexcept = default;

    /// @brief Move constructor.
    constexpr basic_handle(basic_handle&& tmp) noexcept
      : _name{tmp._release()} {}

    /// @brief Move assignment operator.
    auto operator=(basic_handle&& tmp) noexcept -> auto& {
        _name = tmp._release();
        return *this;
    }

    /// @brief Copy constructor.
    constexpr basic_handle(const basic_handle&) noexcept = default;

    /// @brief Copy assignment operator.
    auto operator=(const basic_handle&) noexcept -> basic_handle& = default;

    /// @brief Construction from the underlying handle type.
    explicit constexpr basic_handle(Handle name) noexcept
      : _name{name} {}

    /// @brief Indicates if this instance contains a valid handle.
    constexpr auto is_valid() const noexcept -> bool {
        return _name != invalid;
    }

    /// @brief Indicates if this instance contains a valid handle.
    /// @see is_valid
    explicit constexpr operator bool() const noexcept {
        return is_valid();
    }

    /// @brief Explicit conversion to the underlying handle type.
    explicit constexpr operator Handle() const noexcept {
        return _name;
    }

    struct transform {
        constexpr auto operator()(Handle hndl) noexcept {
            return basic_handle<Tag, Handle, invalid>{hndl};
        }
    };

protected:
    auto _release() noexcept {
        return std::exchange(_name, invalid);
    }

private:
    Handle _name{invalid};
};
//------------------------------------------------------------------------------
/// @brief Owning wrapper for C-API opaque handle types.
/// @ingroup c_api_wrap
/// @tparam Tag type distinguisihing various handler with the same underlying type.
/// @tparam Handle the underlying handle type.
/// @tparam invalid the invalid value for this particular handle type.
/// @see basic_handle
template <typename Tag, typename Handle, Handle invalid = ~Handle(0)>
class basic_owned_handle : public basic_handle<Tag, Handle, invalid> {
    using base = basic_handle<Tag, Handle, invalid>;

public:
    ~basic_owned_handle() noexcept = default;

    /// @brief Default constructor.
    /// @post !is_valid()
    constexpr basic_owned_handle() noexcept = default;

    /// @brief Move constructor.
    constexpr basic_owned_handle(basic_owned_handle&& tmp) noexcept
      : base{tmp.release()} {}

    /// @brief Move assignment operator.
    auto operator=(basic_owned_handle&& tmp) noexcept -> auto& {
        *static_cast<base*>(this) = static_cast<base&&>(tmp);
        return *this;
    }

    /// @brief Copy constructor.
    basic_owned_handle(const basic_owned_handle&) = delete;

    /// @brief Copy assignment operator.
    auto operator=(const basic_owned_handle&) = delete;

    /// @brief Constructor adopting a non-owning handle wrapper.
    explicit constexpr basic_owned_handle(base adopted) noexcept
      : base{adopted} {}

    /// @brief Constructor adopting an underlying handle value.
    explicit constexpr basic_owned_handle(Handle name) noexcept
      : base{name} {}

    /// @brief Releases the underlying handle value.
    /// @post !is_valid()
    auto release() noexcept -> Handle {
        return this->_release();
    }
};
//------------------------------------------------------------------------------
template <typename BasicHandle, typename Container>
class basic_handle_container;

/// @brief Basic template for C-API opaque handle containers and ranges.
/// @ingroup c_api_wrap
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

    /// @brief Returns the raw handles.
    constexpr auto raw_handles() noexcept {
        return this->raw_items();
    }

    /// @brief Returns the raw handles.
    constexpr auto raw_handles() const noexcept {
        return this->raw_items();
    }
};
//------------------------------------------------------------------------------
/// @brief Alias for basic handle container based on non-const span.
/// @ingroup c_api_wrap
template <typename BasicHandle>
using basic_handle_span =
  basic_handle_container<BasicHandle, span<typename BasicHandle::handle_type>>;

/// @brief Alias for basic handle container based on const span.
/// @ingroup c_api_wrap
template <typename BasicHandle>
using basic_handle_view = basic_handle_container<
  BasicHandle,
  span<const typename BasicHandle::handle_type>>;

/// @brief Alias for basic handle container based on std::array.
/// @ingroup c_api_wrap
template <typename BasicHandle, std::size_t N>
using basic_handle_array = basic_handle_container<
  BasicHandle,
  std::array<typename BasicHandle::handle_type, N>>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_HANDLE_HPP
