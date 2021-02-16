/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_VECT_FILL_HPP
#define EAGINE_VECT_FILL_HPP

#include "data.hpp"

namespace eagine::vect {

template <typename T, int N, bool V>
struct fill {
    static auto apply(T v) noexcept -> data_t<T, N, V> {
        data_t<T, N, V> r;
        for(int i = 0; i < N; ++i) {
            r[i] = v;
        }
        return r;
    }
};

#if EAGINE_VECT_OPTS

template <typename T, bool V>
struct fill<T, 0, V> {
    static constexpr auto apply(T) noexcept {
        return data_t<T, 0, V>{};
    }
};

template <typename T, bool V>
struct fill<T, 1, V> {
    static constexpr auto apply(T v) noexcept {
        return data_t<T, 1, V>{v};
    }
};

template <typename T, bool V>
struct fill<T, 2, V> {
    static constexpr auto apply(T v) noexcept {
        return data_t<T, 2, V>{v, v};
    }
};

template <typename T, bool V>
struct fill<T, 3, V> {
    static constexpr auto apply(T v) noexcept {
        return data_t<T, 3, V>{v, v, v};
    }
};

template <typename T, bool V>
struct fill<T, 4, V> {
    static constexpr auto apply(T v) noexcept {
        return data_t<T, 4, V>{v, v, v, v};
    }
};

template <typename T, bool V>
struct fill<T, 8, V> {
    static constexpr auto apply(T v) noexcept {
        return data_t<T, 8, V>{v, v, v, v, v, v, v, v};
    }
};

#endif

} // namespace eagine::vect

#endif // EAGINE_VECT_FILL_HPP
