/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_WRAPPING_CONTAINER_HPP
#define EAGINE_WRAPPING_CONTAINER_HPP

#include "iterator.hpp"
#include "range_types.hpp"
#include "span.hpp"
#include "types.hpp"

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Template used in implementation of containers with wrapped elements.
template <
  typename Container,
  typename Wrapper,
  typename T,
  T initial = T{},
  typename Transform = typename Wrapper::transform>
class basic_wrapping_container : private Transform {
public:
    using wrapper_type = Wrapper;

    /// @brief Alias for the const iterator type.
    using const_iterator = transforming_iterator<
      typename Container::const_iterator,
      Wrapper,
      T,
      Transform>;

    /// @brief Default constructor.
    constexpr explicit basic_wrapping_container() noexcept {
        _initialize(_items);
    }

    /// @brief Resizing constructor.
    constexpr explicit basic_wrapping_container(
      typename Container::size_type count) {
        _items.resize(count);
        _initialize(_items);
    }

    /// @brief Move constructible.
    basic_wrapping_container(basic_wrapping_container&& temp) noexcept
      : _items{temp._release_items()} {}

    /// @brief Copy constructible.
    constexpr basic_wrapping_container(const basic_wrapping_container&) =
      default;

    /// @brief Move assignable.
    auto operator=(basic_wrapping_container&& temp) noexcept
      -> basic_wrapping_container& {
        using std::swap;

        auto items{temp._release_items()};
        swap(items, _items);
        return *this;
    }

    /// @brief Copy assignable.
    constexpr auto operator=(const basic_wrapping_container&)
      -> basic_wrapping_container& = default;

    ~basic_wrapping_container() noexcept = default;

    /// @brief Implicit conversion to mutable view container.
    constexpr operator basic_wrapping_container<
      span<T>,
      Wrapper,
      T,
      initial,
      Transform>() noexcept {
        return {cover(_items)};
    }

    /// @brief Implicit conversion to const view container.
    constexpr operator basic_wrapping_container<
      span<const T>,
      Wrapper,
      T,
      initial,
      Transform>() noexcept {
        return {view(_items)};
    }

    /// @brief Indicates if this container is empty.
    /// @see size
    constexpr auto empty() const noexcept -> bool {
        return _items.empty();
    }

    /// @brief Returns the number of elements in this container.
    /// @see empty
    constexpr auto size() const noexcept {
        return span_size(_items.size());
    }

    /// @brief Subscript access.
    /// @pre index < size()
    constexpr auto operator[](span_size_t index) const noexcept {
        return _transf()(_items[range_index<Container>(index)]);
    }

    /// @brief Access the element at the specified index.
    constexpr auto at(span_size_t index) const {
        return _transf()(_items.at(range_index<Container>(index)));
    }

    /// @brief Returns an iterator to the first element in this container.
    constexpr auto begin() const noexcept -> const_iterator {
        return {_items.begin()};
    }

    /// @brief Returns an iterator past  the last element in this container.
    constexpr auto end() const noexcept -> const_iterator {
        return {_items.end()};
    }

    /// @brief Returns view of the elements as they are stored, without transfomation.
    constexpr auto raw_items() noexcept {
        if constexpr(std::is_const_v<typename Container::value_type>) {
            return view(_items);
        } else {
            return cover(_items);
        }
    }

    /// @brief Returns view of the elements as they are stored, without transfomation.
    constexpr auto raw_items() const noexcept {
        return view(_items);
    }

private:
    constexpr auto _transf() const noexcept -> const Transform& {
        return *this;
    }

    Container _items{};

    static constexpr void _initialize(Container& items) {
        using std::begin;
        using std::end;
        using std::fill;
        fill(begin(items), end(items), initial);
    }

    auto _release_items() noexcept {
        Container items{std::move(_items)};
        _intialize(_items);
        return items;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_WRAPPING_CONTAINER_HPP
