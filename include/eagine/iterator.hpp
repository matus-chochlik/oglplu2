/**
 *  @file eagine/utils/iterator.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ITERATOR_HPP
#define EAGINE_ITERATOR_HPP

#include <iterator>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T, typename Derived>
class basic_iterable_type {
protected:
    T _value{};

    constexpr auto self() noexcept -> Derived& {
        return *static_cast<Derived*>(this);
    }

public:
    using value_type = T;
    using difference_type = decltype(std::declval<T>() - std::declval<T>());

    constexpr basic_iterable_type() = default;

    constexpr basic_iterable_type(T value) noexcept
      : _value{value} {}

    explicit constexpr operator T() const noexcept {
        return _value;
    }

    constexpr auto operator++() noexcept -> auto& {
        ++_value;
        return self();
    }

    constexpr auto operator+=(difference_type d) noexcept -> auto& {
        _value += d;
        return self();
    }

    constexpr auto operator++(int) noexcept -> Derived {
        Derived res(self());
        ++_value;
        return res;
    }

    friend constexpr auto
    operator+(basic_iterable_type a, difference_type d) noexcept {
        Derived res(a.self());
        res += d;
        return res;
    }

    auto constexpr operator--() noexcept -> auto& {
        --_value;
        return self();
    }

    auto constexpr operator-=(difference_type d) noexcept -> auto& {
        _value -= d;
        return self();
    }

    auto constexpr operator--(int) noexcept -> Derived {
        Derived res(self());
        --_value;
        return res;
    }

    friend constexpr auto
    operator-(basic_iterable_type a, difference_type d) noexcept {
        Derived res(a.self());
        res -= d;
        return res;
    }

    constexpr friend auto
    operator-(basic_iterable_type a, basic_iterable_type b) noexcept
      -> difference_type {
        return a._value - b._value;
    }

    constexpr friend auto
    operator==(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value == b._value;
    }

    constexpr friend auto
    operator!=(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value != b._value;
    }

    constexpr friend auto
    operator<(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value < b._value;
    }

    constexpr friend auto
    operator<=(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value <= b._value;
    }

    constexpr friend auto
    operator>(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value > b._value;
    }

    constexpr friend auto
    operator>=(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value >= b._value;
    }
};
//------------------------------------------------------------------------------
template <typename T, typename Derived>
class basic_selfref_iterator : public basic_iterable_type<T, Derived> {
public:
    using reference = const T&;
    using pointer = const T*;
    using iterator_category = std::random_access_iterator_tag;

    using basic_iterable_type<T, Derived>::basic_iterable_type;

    constexpr auto operator*() const noexcept -> const T& {
        return this->_value;
    }
};
//------------------------------------------------------------------------------
template <typename T>
struct selfref_iterator : basic_selfref_iterator<T, selfref_iterator<T>> {
    using basic_selfref_iterator<T, selfref_iterator<T>>::basic_selfref_iterator;
};
//------------------------------------------------------------------------------
template <
  typename Iterator,
  typename T,
  typename S,
  typename Transform,
  typename Derived>
class basic_transforming_iterator
  : public basic_selfref_iterator<Iterator, Derived> {
private:
    using _base = basic_selfref_iterator<Iterator, Derived>;
    Transform _transf{};

    mutable S _tempval{};

    constexpr auto _base_iter() const noexcept -> const _base& {
        return *this;
    }

public:
    constexpr basic_transforming_iterator() = default;

    constexpr basic_transforming_iterator(Iterator iter, Transform transf)
      : _base{iter}
      , _transf{std::move(transf)} {}

    using value_type = T;
    using reference = const T&;
    using pointer = const T*;

    constexpr auto operator*() const -> const T& {
        _tempval = _transf(**_base_iter());
        return _tempval;
    }
};
//------------------------------------------------------------------------------
template <typename Iterator, typename T, typename Transform, typename Derived>
class basic_transforming_iterator<Iterator, T, T&, Transform, Derived>
  : public basic_selfref_iterator<Iterator, Derived> {
private:
    using _base = basic_selfref_iterator<Iterator, Derived>;
    Transform _transf{};

    auto _base_iter() const noexcept -> const _base& {
        return *this;
    }

public:
    constexpr basic_transforming_iterator() = default;

    constexpr basic_transforming_iterator(Iterator iter, Transform transf)
      : _base{iter}
      , _transf{std::move(transf)} {}

    using value_type = T;
    using reference = const T&;
    using pointer = const T*;

    constexpr auto operator*() -> T& {
        return _transf(**_base_iter());
    }

    constexpr auto operator*() const -> const T& {
        return _transf(**_base_iter());
    }
};
//------------------------------------------------------------------------------
template <typename Iterator, typename T, typename S, typename Transform>
struct transforming_iterator
  : basic_transforming_iterator<
      Iterator,
      T,
      S,
      Transform,
      transforming_iterator<Iterator, T, S, Transform>> {
    using basic_transforming_iterator<
      Iterator,
      T,
      S,
      Transform,
      transforming_iterator<Iterator, T, S, Transform>>::
      basic_transforming_iterator;
};
//------------------------------------------------------------------------------
template <typename Iterator, typename T, typename S, typename Derived>
class basic_noexcept_casting_iterator
  : public basic_transforming_iterator<
      Iterator,
      T,
      S,
      S (*)(typename std::iterator_traits<Iterator>::reference) noexcept,
      Derived> {
private:
    using _base = basic_transforming_iterator<
      Iterator,
      T,
      S,
      S (*)(typename std::iterator_traits<Iterator>::reference) noexcept,
      Derived>;

    static constexpr auto
    _cast(typename std::iterator_traits<Iterator>::reference r) noexcept -> S {
        return static_cast<S>(r);
    }

public:
    constexpr basic_noexcept_casting_iterator(Iterator iter)
      : _base{iter, &_cast} {}
};
//------------------------------------------------------------------------------
template <typename Iterator, typename T, typename S>
struct noexcept_casting_iterator
  : basic_noexcept_casting_iterator<
      Iterator,
      T,
      S,
      noexcept_casting_iterator<Iterator, T, S>> {
    using basic_noexcept_casting_iterator<
      Iterator,
      T,
      S,
      noexcept_casting_iterator<Iterator, T, S>>::basic_noexcept_casting_iterator;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_ITERATOR_HPP
