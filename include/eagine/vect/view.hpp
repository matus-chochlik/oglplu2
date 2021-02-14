/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_VECT_VIEW_HPP
#define EAGINE_VECT_VIEW_HPP

#include "../span.hpp"
#include "data.hpp"

namespace eagine::vect {

template <typename T, int N, bool V>
struct view {
private:
    static auto _addr(const data_t<T, N, V>& d, std::false_type) noexcept
      -> const T* {
        return static_cast<const T*>(d._v);
    }

    static auto _addr(const data_t<T, N, V>& d, std::true_type) noexcept
      -> const T* {
        // TODO: strict aliasing, launder?
        return reinterpret_cast<const T*>(&d);
    }

public:
    static auto apply(const data_t<T, N, V>& d) noexcept -> span<const T> {
        static_assert(sizeof(T[N]) == sizeof(data_t<T, N, V>));
        return {_addr(d, has_vect_data<T, N, V>()), N};
    }

    template <int M>
    static auto apply(const data_t<T, N, V> (&d)[M]) noexcept -> span<const T> {
        static_assert(sizeof(T[N][M]) == sizeof(data_t<T, N, V>[M]));
        return {_addr(d[0], has_vect_data<T, N, V>()), N * M};
    }
};

} // namespace eagine::vect

#endif // EAGINE_VECT_VIEW_HPP
