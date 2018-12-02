/**
 *  @file eagine/network_sorter.hpp
 */

#ifndef EAGINE_NETWORK_SORTER_1512222148_HPP
#define EAGINE_NETWORK_SORTER_1512222148_HPP

#include <array>
#include <cassert>
#include <utility>
#include "sorting_network.hpp"

namespace eagine {

template <
  typename T,
  std::size_t N,
  typename Compare = std::less<T>,
  typename Network = sorting_network<N>>
class basic_network_sorter {
private:
    Compare _before;
    Network _sn;

    inline const T& _min(const T& a, const T& b) const {
        return _before(a, b) ? a : b;
    }

    inline const T& _max(const T& a, const T& b) const {
        return _before(a, b) ? b : a;
    }

    inline const T& _min_max_cpy(
      const T& a, const T& b, bool min, bool max) const {
        return min ? _min(a, b) : max ? _max(a, b) : a;
    }

public:
    void single_sort_step(
      std::array<T, N>& src,
      std::array<T, N>& dst,
      span_size_t r,
      span_size_t i) const {
        span_size_t j = _sn.index(r, i);
        dst[std_size(i)] = _min_max_cpy(
          src[std_size(i)],
          src[std_size(j)],
          _sn.min(r, i, j),
          _sn.max(r, i, j));
    }

    span_size_t size() const noexcept {
        return _sn.size();
    }

    span_size_t rounds() const noexcept {
        return _sn.rounds();
    }
};

template <
  typename T,
  std::size_t N,
  typename Compare = std::less<T>,
  typename Network = sorting_network<N>>
class network_sorter : basic_network_sorter<T, N, Compare, Network> {
private:
    span_size_t _round;
    std::array<std::array<T, N>, 2> _a;

public:
    constexpr inline network_sorter(std::array<T, N> a)
      : _round{0}
      , _a{{a, a}} {
    }

    using basic_network_sorter<T, N, Compare, Network>::rounds;

    bool done() const noexcept {
        return _round >= rounds();
    }

    bool next_round() noexcept {
        return !done() && (++_round < rounds());
    }

    network_sorter& sort_single(span_size_t r, span_size_t i) {
        span_size_t src = (r + 0) % 2;
        span_size_t dst = (r + 1) % 2;
        this->single_sort_step(_a[std_size(src)], _a[std_size(dst)], r, i);
        return *this;
    }

    network_sorter& sort_single(span_size_t i) {
        return sort_single(_round, i);
    }

    network_sorter& sort_round() {
        assert(!done());
        for(span_size_t i = 0; i < span_size(N); ++i) {
            sort_single(i);
        }
        return *this;
    }

    network_sorter& sort() {
        while(sort_round().next_round()) {
        }
        return *this;
    }

    const std::array<T, N>& result() const noexcept {
        return _a[rounds() % 2];
    }

    const std::array<T, N>& operator()() {
        return sort().result();
    }
};

} // namespace eagine

#endif // include guard
