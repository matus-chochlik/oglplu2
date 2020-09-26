/**
 *  @file eagine/network_sorter.hpp
 */

#ifndef EAGINE_NETWORK_SORTER_HPP
#define EAGINE_NETWORK_SORTER_HPP

#include "assert.hpp"
#include "memory/span_algo.hpp"
#include "sorting_network.hpp"
#include "span.hpp"
#include <array>
#include <utility>

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

    auto _min(const T& a, const T& b) const -> const T& {
        return _before(a, b) ? a : b;
    }

    auto _max(const T& a, const T& b) const -> const T& {
        return _before(a, b) ? b : a;
    }

    auto _min_max_cpy(const T& a, const T& b, bool min, bool max) const
      -> const T& {
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

    auto size() const noexcept -> span_size_t {
        return _sn.size();
    }

    auto rounds() const noexcept -> span_size_t {
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
    span_size_t _round{0};
    std::array<std::array<T, N>, 2> _a;

public:
    constexpr inline network_sorter(std::array<T, N> a)
      : _a{{a, a}} {}

    using basic_network_sorter<T, N, Compare, Network>::rounds;

    auto done() const noexcept -> bool {
        return _round >= rounds();
    }

    auto next_round() noexcept -> bool {
        return !done() && (++_round < rounds());
    }

    auto sort_single(span_size_t r, span_size_t i) -> auto& {
        span_size_t src = (r + 0) % 2;
        span_size_t dst = (r + 1) % 2;
        this->single_sort_step(_a[std_size(src)], _a[std_size(dst)], r, i);
        return *this;
    }

    auto sort_single(span_size_t i) -> auto& {
        return sort_single(_round, i);
    }

    auto sort_round() -> auto& {
        EAGINE_ASSERT(!done());
        for(span_size_t i = 0; i < span_size(N); ++i) {
            sort_single(i);
        }
        return *this;
    }

    auto sort() -> auto& {
        while(sort_round().next_round()) {
        }
        return *this;
    }

    auto result() const noexcept -> const std::array<T, N>& {
        return _a[rounds() % 2];
    }

    auto operator()() -> const std::array<T, N>& {
        return sort().result();
    }
};

template <std::size_t N, typename Cmp, typename T, typename P, typename S>
auto network_sort(memory::basic_span<T, P, S> spn)
  -> memory::basic_span<T, P, S> {
    EAGINE_ASSERT(spn.size() == span_size_t(N));
    using memory::copy;
    std::array<T, N> init{};
    copy(spn, cover(init));
    network_sorter<T, N, Cmp> sorter(std::move(init));
    return copy(view(sorter.sort().result()), spn);
}

} // namespace eagine

#endif // EAGINE_NETWORK_SORTER_HPP
