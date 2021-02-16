/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SORTING_NETWORK_HPP
#define EAGINE_SORTING_NETWORK_HPP

#include "types.hpp"
#include <array>
#include <cstdint>
#include <type_traits>

namespace eagine {

class bitonic_sorting_network_base {
protected:
    static constexpr auto _next_log(std::size_t n, std::size_t pot = 1) noexcept
      -> std::size_t {
        return (n > pot) ? 1U + _next_log(n, pot << 1U) : 0U;
    }

    static constexpr auto _hlp(std::size_t n) noexcept -> std::size_t {
        return (n == 0) ? 0 : n + _hlp(n - 1);
    }

    template <std::size_t N>
    static void _fill_idx(std::array<std::size_t, N>* idx) noexcept {
        std::size_t r = 0;
        for(std::size_t k = 0, l = _next_log(N); k < l; ++k) {
            for(std::size_t m = 0; m <= k; ++m, ++r) {
                std::size_t d = 1U << (k - m);
                std::array<std::size_t, N>& row = idx[r];

                for(std::size_t i = 0; i < N; ++i) {
                    std::size_t inv = ((i >> k) & 2U) >> 1U;
                    std::size_t j = i + ((i & d) == 0 ? d : -d);

                    if(j >= N) {
                        j = i;
                    }
                    row[i] = (j << 1U) | inv;
                }
            }
        }
    }

public:
    static constexpr auto num_rounds_for(span_size_t n) noexcept
      -> span_size_t {
        return span_size(_hlp(_next_log(std_size(n))));
    }
};

template <span_size_t N>
class bitonic_sorting_network : public bitonic_sorting_network_base {
private:
    using _base = bitonic_sorting_network_base;
    using _idx_t =
      std::array<std::array<std::size_t, N>, _base::num_rounds_for(N)>;

    static auto _make_idx() {
        _idx_t result;
        _base::_fill_idx(result.data());
        return result;
    }

    static auto _get_idx() -> _idx_t& {
        static _idx_t idx = _make_idx();
        return idx;
    }

    static auto _c(span_size_t r, span_size_t i) -> std::size_t& {
        return _get_idx()[std_size(r)][std_size(i)];
    }

public:
    static constexpr auto size() noexcept -> span_size_t {
        return N;
    }

    static constexpr auto rounds() noexcept -> span_size_t {
        return _base::num_rounds_for(N);
    }

    static auto index(span_size_t r, span_size_t i) -> span_size_t {
        return span_size(_c(r, i) >> 1U);
    }

    static auto inv(span_size_t r, span_size_t i) -> bool {
        return (_c(r, i) & 1U) == 1U;
    }

    static auto min(span_size_t r, span_size_t i, span_size_t j) -> bool {
        return inv(r, i) ? (i > j) : (i < j);
    }

    static auto max(span_size_t r, span_size_t i, span_size_t j) -> bool {
        return inv(r, i) ? (i < j) : (i > j);
    }
};

template <span_size_t N>
struct manual_sorting_network_base {
    static constexpr bool is_specialized = false;
};

template <span_size_t N>
struct manual_sorting_network : manual_sorting_network_base<N> {
private:
    using _base = manual_sorting_network_base<N>;

public:
    static constexpr auto size() noexcept -> span_size_t {
        return N;
    }

    static constexpr auto
    min(span_size_t /*round*/, span_size_t i, span_size_t j) noexcept -> bool {
        return i < j;
    }

    static constexpr auto
    max(span_size_t /*round*/, span_size_t i, span_size_t j) noexcept -> bool {
        return i > j;
    }
};

template <>
struct manual_sorting_network_base<1> {
    static constexpr bool is_specialized = true;

    static constexpr auto rounds() noexcept -> span_size_t {
        return 1;
    }

    static constexpr auto
    index(span_size_t /*round*/, span_size_t /*elem*/) noexcept -> span_size_t {
        return 0;
    }
};

template <>
struct manual_sorting_network_base<2> {
    static constexpr bool is_specialized = true;

    static constexpr auto rounds() noexcept -> span_size_t {
        return 1;
    }

    static constexpr auto
    index(span_size_t /*round*/, span_size_t elem) noexcept -> span_size_t {
        return elem == 0 ? 1 : 0;
    }
};

template <>
struct manual_sorting_network_base<3> {
    static constexpr bool is_specialized = true;

    static constexpr auto rounds() noexcept -> span_size_t {
        return 3;
    }

    static constexpr span_size_t idx[3][3] = {{1, 0, 2}, {0, 2, 1}, {1, 0, 2}};

    static constexpr auto index(span_size_t round, span_size_t elem) noexcept
      -> span_size_t {
        return idx[round][elem];
    }
};

constexpr span_size_t manual_sorting_network_base<3>::idx[3][3];

template <>
struct manual_sorting_network_base<4> {
    static constexpr bool is_specialized = true;

    static constexpr auto size() noexcept -> span_size_t {
        return 4;
    }

    static constexpr auto rounds() noexcept -> span_size_t {
        return 3;
    }

    static constexpr span_size_t idx[3][4] = {
      {1, 0, 3, 2},
      {2, 3, 0, 1},
      {0, 2, 1, 3}};

    static constexpr auto index(span_size_t round, span_size_t elem) noexcept
      -> span_size_t {
        return idx[round][elem];
    }
};

constexpr span_size_t manual_sorting_network_base<4>::idx[3][4];

template <>
struct manual_sorting_network_base<5> {
    static constexpr bool is_specialized = true;

    static constexpr auto size() noexcept -> span_size_t {
        return 5;
    }

    static constexpr auto rounds() noexcept -> span_size_t {
        return 5;
    }

    static constexpr span_size_t idx[5][5] = {
      {1, 0, 3, 2, 4},
      {0, 3, 4, 1, 2},
      {2, 4, 0, 3, 1},
      {0, 2, 1, 4, 3},
      {0, 1, 3, 2, 4}};

    static constexpr auto index(span_size_t round, span_size_t elem) noexcept
      -> span_size_t {
        return idx[round][elem];
    }
};

constexpr span_size_t manual_sorting_network_base<5>::idx[5][5];

template <>
struct manual_sorting_network_base<6> {
    static constexpr bool is_specialized = true;

    static constexpr auto size() noexcept -> span_size_t {
        return 6;
    }

    static constexpr auto rounds() noexcept -> span_size_t {
        return 5;
    }

    static constexpr span_size_t idx[5][6] = {
      {1, 0, 3, 2, 5, 4},
      {2, 4, 0, 5, 1, 3},
      {1, 0, 3, 2, 5, 4},
      {0, 2, 1, 4, 3, 5},
      {0, 1, 3, 2, 4, 5}};

    static constexpr auto index(span_size_t round, span_size_t elem) noexcept
      -> span_size_t {
        return idx[round][elem];
    }
};

constexpr span_size_t manual_sorting_network_base<6>::idx[5][6];

template <>
struct manual_sorting_network_base<7> {
    static constexpr bool is_specialized = true;

    static constexpr auto size() noexcept -> span_size_t {
        return 7;
    }

    static constexpr auto rounds() noexcept -> span_size_t {
        return 6;
    }

    static constexpr span_size_t idx[6][7] = {
      {1, 0, 3, 2, 5, 4, 6},
      {2, 3, 0, 1, 6, 5, 4},
      {4, 5, 6, 3, 0, 1, 2},
      {0, 4, 2, 6, 1, 5, 3},
      {0, 1, 4, 5, 2, 3, 6},
      {0, 2, 1, 4, 3, 6, 5}};

    static constexpr auto index(span_size_t round, span_size_t elem) noexcept
      -> span_size_t {
        return idx[round][elem];
    }
};

constexpr span_size_t manual_sorting_network_base<7>::idx[6][7];

template <>
struct manual_sorting_network_base<8> {
    static constexpr bool is_specialized = true;

    static constexpr auto size() noexcept -> span_size_t {
        return 8;
    }

    static constexpr auto rounds() noexcept -> span_size_t {
        return 6;
    }

    static constexpr span_size_t idx[6][8] = {
      {1, 0, 3, 2, 5, 4, 7, 6},
      {2, 3, 0, 1, 6, 7, 4, 5},
      {4, 2, 1, 7, 0, 6, 5, 3},
      {0, 5, 6, 3, 4, 1, 2, 7},
      {0, 1, 4, 5, 2, 3, 6, 7},
      {0, 2, 1, 4, 3, 6, 5, 7}};

    static constexpr auto index(span_size_t round, span_size_t elem) noexcept
      -> span_size_t {
        return idx[round][elem];
    }
};

constexpr span_size_t manual_sorting_network_base<8>::idx[6][8];

template <>
struct manual_sorting_network_base<9> {
    static constexpr bool is_specialized = true;

    static constexpr auto size() noexcept -> span_size_t {
        return 9;
    }

    static constexpr auto rounds() noexcept -> span_size_t {
        return 7;
    }

    static constexpr span_size_t idx[7][9] = {
      {7, 6, 5, 4, 3, 2, 1, 0, 8},
      {3, 2, 1, 0, 7, 5, 8, 4, 6},
      {1, 0, 6, 4, 3, 8, 2, 7, 5},
      {0, 2, 1, 5, 6, 3, 4, 8, 7},
      {0, 3, 4, 1, 2, 7, 6, 5, 8},
      {1, 0, 3, 2, 5, 4, 7, 6, 8},
      {0, 1, 2, 4, 3, 6, 5, 7, 8}};

    static constexpr auto index(span_size_t round, span_size_t elem) noexcept
      -> span_size_t {
        return idx[round][elem];
    }
};

constexpr span_size_t manual_sorting_network_base<9>::idx[7][9];

template <>
struct manual_sorting_network_base<10> {
    static constexpr bool is_specialized = true;

    static constexpr auto size() noexcept -> span_size_t {
        return 10;
    }

    static constexpr auto rounds() noexcept -> span_size_t {
        return 7;
    }

    static constexpr span_size_t idx[7][10] = {
      {1, 0, 3, 2, 5, 4, 7, 6, 9, 8},
      {5, 8, 6, 7, 9, 0, 2, 3, 1, 4},
      {2, 4, 0, 6, 1, 8, 3, 9, 5, 7},
      {1, 0, 7, 5, 6, 3, 4, 2, 9, 8},
      {0, 3, 4, 1, 2, 7, 8, 5, 6, 9},
      {0, 2, 1, 4, 3, 6, 5, 8, 7, 9},
      {0, 1, 3, 2, 5, 4, 7, 6, 8, 9},
    };

    static constexpr auto index(span_size_t round, span_size_t elem) noexcept
      -> span_size_t {
        return idx[round][elem];
    }
};

constexpr span_size_t manual_sorting_network_base<10>::idx[7][10];

template <>
struct manual_sorting_network_base<11> {
    static constexpr bool is_specialized = true;

    static constexpr auto size() noexcept -> span_size_t {
        return 11;
    }

    static constexpr auto rounds() noexcept -> span_size_t {
        return 8;
    }

    static constexpr span_size_t idx[8][11] = {
      {0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
      {6, 4, 3, 2, 1, 5, 0, 10, 9, 8, 7},
      {1, 0, 5, 4, 3, 2, 6, 8, 7, 10, 9},
      {2, 5, 0, 3, 6, 1, 4, 7, 9, 8, 10},
      {0, 8, 3, 2, 7, 9, 10, 4, 1, 5, 6},
      {0, 4, 2, 5, 1, 3, 9, 8, 7, 6, 10},
      {0, 2, 1, 4, 3, 7, 8, 5, 6, 9, 10},
      {0, 1, 3, 2, 5, 4, 7, 6, 8, 9, 10},
    };

    static constexpr auto index(span_size_t round, span_size_t elem) noexcept
      -> span_size_t {
        return idx[round][elem];
    }
};

constexpr span_size_t manual_sorting_network_base<11>::idx[8][11];

template <>
struct manual_sorting_network_base<12> {
    static constexpr bool is_specialized = true;

    static constexpr auto size() noexcept -> span_size_t {
        return 12;
    }

    static constexpr auto rounds() noexcept -> span_size_t {
        return 8;
    }

    static constexpr span_size_t idx[8][12] = {
      {6, 7, 8, 9, 10, 11, 0, 1, 2, 3, 4, 5},
      {3, 4, 5, 0, 1, 2, 9, 10, 11, 6, 7, 8},
      {1, 0, 2, 6, 5, 4, 3, 8, 7, 9, 11, 10},
      {0, 2, 1, 4, 3, 8, 7, 6, 5, 10, 9, 11},
      {1, 0, 9, 6, 5, 4, 3, 8, 7, 2, 11, 10},
      {0, 3, 6, 1, 7, 9, 2, 4, 10, 5, 8, 11},
      {0, 1, 3, 2, 6, 7, 4, 5, 9, 8, 10, 11},
      {0, 1, 2, 4, 3, 6, 5, 8, 7, 9, 10, 11}};

    static constexpr auto index(span_size_t round, span_size_t elem) noexcept
      -> span_size_t {
        return idx[round][elem];
    }
};

constexpr span_size_t manual_sorting_network_base<12>::idx[8][12];

template <>
struct manual_sorting_network_base<14> {
    static constexpr bool is_specialized = true;

    static constexpr auto size() noexcept -> span_size_t {
        return 14;
    }

    static constexpr auto rounds() noexcept -> span_size_t {
        return 9;
    }

    static constexpr span_size_t idx[9][14] = {
      {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
      {5, 4, 3, 2, 1, 0, 6, 7, 13, 12, 11, 10, 9, 8},
      {1, 0, 2, 6, 5, 4, 3, 10, 9, 8, 7, 11, 13, 12},
      {0, 7, 8, 4, 3, 11, 12, 1, 2, 10, 9, 5, 6, 13},
      {3, 2, 1, 0, 9, 8, 7, 6, 5, 4, 13, 12, 11, 10},
      {1, 0, 3, 2, 8, 7, 9, 5, 4, 6, 11, 10, 13, 12},
      {0, 2, 1, 5, 6, 3, 4, 9, 10, 7, 8, 12, 11, 13},
      {0, 1, 2, 4, 3, 6, 5, 8, 7, 10, 9, 11, 12, 13},
      {0, 1, 3, 2, 5, 4, 7, 6, 9, 8, 11, 10, 12, 13}};

    static constexpr auto index(span_size_t round, span_size_t elem) noexcept
      -> span_size_t {
        return idx[round][elem];
    }
};

constexpr span_size_t manual_sorting_network_base<14>::idx[9][14];

template <>
struct manual_sorting_network_base<16> {
    static constexpr bool is_specialized = true;

    static constexpr auto size() noexcept -> span_size_t {
        return 16;
    }

    static constexpr auto rounds() noexcept -> span_size_t {
        return 9;
    }

    static constexpr span_size_t idx[9][16] = {
      {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
      {7, 6, 5, 4, 3, 2, 1, 0, 15, 14, 13, 12, 11, 10, 9, 8},
      {3, 2, 1, 0, 7, 6, 5, 4, 11, 10, 9, 8, 15, 14, 13, 12},
      {1, 0, 8, 9, 5, 4, 12, 13, 2, 3, 11, 10, 6, 7, 15, 14},
      {0, 4, 3, 2, 1, 10, 9, 8, 7, 6, 5, 14, 13, 12, 11, 15},
      {0, 2, 1, 4, 3, 9, 8, 10, 6, 5, 7, 12, 11, 14, 13, 15},
      {0, 1, 3, 2, 6, 7, 4, 5, 10, 11, 8, 9, 13, 12, 14, 15},
      {0, 1, 2, 3, 5, 4, 7, 6, 9, 8, 11, 10, 12, 13, 14, 15},
      {0, 1, 2, 4, 3, 6, 5, 8, 7, 11, 9, 12, 11, 13, 14, 15}};

    static constexpr auto index(span_size_t round, span_size_t elem) noexcept
      -> span_size_t {
        return idx[round][elem];
    }
};

constexpr span_size_t manual_sorting_network_base<16>::idx[9][16];

template <span_size_t N>
struct sorting_network
  : std::conditional_t<
      manual_sorting_network<N>::is_specialized,
      manual_sorting_network<N>,
      bitonic_sorting_network<N>> {};

} // namespace eagine

#endif // EAGINE_SORTING_NETWORK_HPP
