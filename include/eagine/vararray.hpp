/// @file eagine/vararray.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VARARRAY_HPP
#define EAGINE_VARARRAY_HPP

#include <cstdint>
#include <type_traits>

namespace eagine {

// basic_vararray
template <typename T, typename S>
class basic_vararray {
public:
    using value_type = T;
    using size_type = S;

    using alloc_unit_t = std::conditional_t<alignof(T) >= alignof(S), T, S>;

    static std::size_t alloc_unit_c(std::size_t n) noexcept {
        if(alignof(T) >= alignof(S)) {
            return n + (sizeof(S) / sizeof(T)) +
                   ((sizeof(S) % sizeof(T)) ? 1 : 0);
        } else {
            return 1 + ((n * sizeof(T)) / sizeof(S)) +
                   (((n * sizeof(T)) % sizeof(S)) ? 1 : 0);
        }
    }

private:
    const size_type _size = 0;
    value_type _data[1] = {};

public:
    constexpr basic_vararray() noexcept = default;

    static std::size_t instance_size(size_type n) noexcept {
        return alloc_unit_c(n) * sizeof(alloc_unit_t);
    }

    std::size_t instance_size() const noexcept {
        return instance_size(_size);
    }

    size_type size() const noexcept {
        return _size;
    }

    using iterator = T*;
    using const_iterator = const T*;

    iterator begin() noexcept {
        return _data;
    }

    iterator end() noexcept {
        return begin() + size();
    }

    const_iterator begin() const noexcept {
        return _data;
    }

    const_iterator end() const noexcept {
        return begin() + size();
    }
};

template <typename T>
using vararray = basic_vararray<T, std::size_t>;

// basic_vararray_store
template <typename T, typename S, S N>
class basic_vararray_store {
private:
    const S _size = N;
    T _data[N] = {};

public:
    constexpr basic_vararray_store() noexcept = default;

    operator basic_vararray<T, S> &() {
        return *reinterpret_cast<basic_vararray<T, S>*>(this);
    }

    operator const basic_vararray<T, S> &() const {
        return *reinterpret_cast<const basic_vararray<T, S>*>(this);
    }
};

template <typename T, std::size_t N>
using vararray_store = basic_vararray_store<T, std::size_t, N>;

} // namespace eagine

#endif // EAGINE_VARARRAY_HPP
