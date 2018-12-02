/**
 *  @file eagine/utils/iterator.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UTILS_ITERATOR_1509260923_HPP
#define EAGINE_UTILS_ITERATOR_1509260923_HPP

#include <iterator>

namespace eagine {

template <typename T, typename Derived>
class basic_iterable_type {
protected:
    T _value;

    Derived& self() noexcept {
        return *static_cast<Derived*>(this);
    }

public:
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;

    basic_iterable_type() = default;

    constexpr basic_iterable_type(T value) noexcept
      : _value(value) {
    }

    explicit constexpr operator T() const noexcept {
        return _value;
    }

    Derived& operator++() noexcept {
        ++_value;
        return self();
    }

    Derived& operator+=(difference_type d) noexcept {
        _value += d;
        return self();
    }

    Derived operator++(int) noexcept {
        Derived res(self());
        ++_value;
        return res;
    }

    friend Derived
    operator+(basic_iterable_type a, difference_type d) noexcept {
        Derived res(a.self());
        res += d;
        return res;
    }

    Derived& operator--() noexcept {
        --_value;
        return self();
    }

    Derived& operator-=(difference_type d) noexcept {
        _value -= d;
        return self();
    }

    Derived operator--(int) noexcept {
        Derived res(self());
        --_value;
        return res;
    }

    friend Derived
    operator-(basic_iterable_type a, difference_type d) noexcept {
        Derived res(a.self());
        res -= d;
        return res;
    }

    constexpr friend difference_type
    operator-(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value - b._value;
    }

    constexpr friend bool
    operator==(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value == b._value;
    }

    constexpr friend bool
    operator!=(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value != b._value;
    }

    constexpr friend bool
    operator<(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value < b._value;
    }

    constexpr friend bool
    operator<=(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value <= b._value;
    }

    constexpr friend bool
    operator>(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value > b._value;
    }

    constexpr friend bool
    operator>=(basic_iterable_type a, basic_iterable_type b) noexcept {
        return a._value >= b._value;
    }
};

template <typename T, typename Derived>
class basic_selfref_iterator : public basic_iterable_type<T, Derived> {
public:
    typedef const T& reference;
    typedef const T* pointer;
    typedef std::random_access_iterator_tag iterator_category;

    using basic_iterable_type<T, Derived>::basic_iterable_type;

    const T& operator*() const noexcept {
        return this->_value;
    }
};

template <typename T>
struct selfref_iterator : basic_selfref_iterator<T, selfref_iterator<T>> {
    using basic_selfref_iterator<T, selfref_iterator<T>>::
      basic_selfref_iterator;
};

template <
  typename Iterator,
  typename T,
  typename S,
  typename Transform,
  typename Derived>
class basic_transforming_iterator
  : public basic_selfref_iterator<Iterator, Derived> {
private:
    typedef basic_selfref_iterator<Iterator, Derived> _base;
    Transform _transf;

    mutable S _tempval;

    const _base& _base_iter() const noexcept {
        return *this;
    }

public:
    basic_transforming_iterator() = default;

    basic_transforming_iterator(Iterator iter, Transform transf)
      : _base(iter)
      , _transf(transf)
      , _tempval() {
    }

    typedef T value_type;
    typedef const T& reference;
    typedef const T* pointer;

    const T& operator*() const {
        _tempval = _transf(**_base_iter());
        return _tempval;
    }
};

template <typename Iterator, typename T, typename Transform, typename Derived>
class basic_transforming_iterator<Iterator, T, T&, Transform, Derived>
  : public basic_selfref_iterator<Iterator, Derived> {
private:
    typedef basic_selfref_iterator<Iterator, Derived> _base;
    Transform _transf;

    const _base& _base_iter() const noexcept {
        return *this;
    }

public:
    basic_transforming_iterator() = default;

    basic_transforming_iterator(Iterator iter, Transform transf)
      : _base(iter)
      , _transf(transf) {
    }

    typedef T value_type;
    typedef const T& reference;
    typedef const T* pointer;

    T& operator*() {
        return _transf(**_base_iter());
    }

    const T& operator*() const {
        return _transf(**_base_iter());
    }
};

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

template <typename Iterator, typename T, typename S, typename Derived>
class basic_noexcept_casting_iterator
  : public basic_transforming_iterator<
      Iterator,
      T,
      S,
      S (*)(typename std::iterator_traits<Iterator>::reference) noexcept,
      Derived> {
private:
    typedef basic_transforming_iterator<
      Iterator,
      T,
      S,
      S (*)(typename std::iterator_traits<Iterator>::reference) noexcept,
      Derived>
      _base;

    static S
    _cast(typename std::iterator_traits<Iterator>::reference r) noexcept {
        return static_cast<S>(r);
    }

public:
    basic_noexcept_casting_iterator(Iterator iter)
      : _base(iter, &_cast) {
    }
};

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
      noexcept_casting_iterator<Iterator, T, S>>::
      basic_noexcept_casting_iterator;
};

} // namespace eagine

#endif // include guard
