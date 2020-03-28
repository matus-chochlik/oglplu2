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

#include "iterator.hpp"
#include "range_types.hpp"
#include "span.hpp"
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

    explicit constexpr basic_owned_handle(Handle name) noexcept
      : base{name} {
    }

    Handle release() noexcept {
        return this->_release();
    }
};
//------------------------------------------------------------------------------
template <typename Iterator, typename BasicHandle>
struct basic_handle_wrapping_iterator;

template <typename Iterator, typename Tag, typename Handle, Handle invalid>
struct basic_handle_wrapping_iterator<
  Iterator,
  basic_handle<Tag, Handle, invalid>>
  : transforming_iterator<
      Iterator,
      basic_handle<Tag, Handle, invalid>,
      Handle,
      typename basic_handle<Tag, Handle, invalid>::transform> {
    using transforming_iterator<
      Iterator,
      basic_handle<Tag, Handle, invalid>,
      Handle,
      typename basic_handle<Tag, Handle, invalid>::transform>::
      transforming_iterator;
};
//------------------------------------------------------------------------------
template <typename BasicHandle, typename Container>
class basic_handle_container;

template <typename Tag, typename Handle, Handle invalid, typename Container>
class basic_handle_container<basic_handle<Tag, Handle, invalid>, Container> {
private:
    Container _handles;

    static constexpr void _invalidate_handles(Container& handles) {
        using std::begin;
        using std::end;
        using std::fill;
        fill(begin(handles), end(handles), invalid);
    }

    auto _release_handles() noexcept {
        Container handles{std::move(_handles)};
        _invalidate_handles(_handles);
        return handles;
    }

public:
    using basic_handle_type = basic_handle<Tag, Handle, invalid>;

    constexpr basic_handle_container() noexcept {
        _invalidate_handles(_handles);
    }

    basic_handle_container(const basic_handle_container&) = default;
    basic_handle_container& operator=(const basic_handle_container&) = default;

    basic_handle_container(basic_handle_container&& temp) noexcept
      : _handles{temp._release_handles()} {
    }

    basic_handle_container& operator=(basic_handle_container&& temp) noexcept {
        using std::swap;

        auto handles{temp._release_handles()};
        swap(handles, _handles);
        return *this;
    }

    ~basic_handle_container() noexcept = default;

    operator basic_handle_container<
      basic_handle_type,
      span<Handle>>() noexcept {
        return {cover(_handles)};
    }

    operator basic_handle_container<basic_handle_type, span<const Handle>>()
      const noexcept {
        return {view(_handles)};
    }

    constexpr bool empty() const noexcept {
        return _handles.empty();
    }

    constexpr auto size() const noexcept {
        return span_size(_handles.size());
    }

    constexpr auto operator[](span_size_t index) const noexcept {
        return basic_handle_type(_handles[range_index<Container>(index)]);
    }

    auto at(span_size_t index) const {
        return basic_handle_type(_handles.at(range_index<Container>(index)));
    }

    using const_iterator = basic_handle_wrapping_iterator<
      basic_handle_type,
      typename Container::const_iterator>;

    constexpr const_iterator begin() const noexcept {
        return {_handles.begin()};
    }

    constexpr const_iterator end() const noexcept {
        return {_handles.end()};
    }

    constexpr span<Handle> raw_handles() noexcept {
        return cover(_handles);
    }

    constexpr span<const Handle> raw_handles() const noexcept {
        return view(_handles);
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
using basic_handle_array =
  basic_handle_container<BasicHandle, std::array<BasicHandle, N>>;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_HANDLE_HPP
