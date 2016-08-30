/**
 *  @file eagine/network_sorter.hpp
 */

#ifndef EAGINE_NETWORK_SORTER_1512222148_HPP
#define EAGINE_NETWORK_SORTER_1512222148_HPP

#include "sorting_network.hpp"
#include <array>
#include <utility>
#include <cassert>

namespace eagine {

template <typename T, std::size_t N, typename Compare = std::less<T>>
class basic_network_sorter
{
private:
	Compare _before;
	sorting_network<N> _sn;

	inline
	const T& _min(const T& a, const T& b) const
	{
		return _before(a, b)?a:b;
	}

	inline
	const T& _max(const T& a, const T& b) const
	{
		return _before(a, b)?b:a;
	}

	inline
	const T& _min_max_fbk(const T& a, const T& b, bool min, bool max) const
	{
		return min?_min(a, b):max?_max(a, b):a;
	}
public:
	void single_sort_step(
		std::array<T, N>& src,
		std::array<T, N>& dst,
		std::size_t r,
		std::size_t i
	) const
	{
		std::size_t j = _sn.index(r, i);
		dst[i] = _min_max_fbk(src[i], src[j], (i < j), (i > j));
	}

	std::size_t size(void) const
	noexcept { return _sn.size(); }

	std::size_t rounds(void) const
	noexcept { return _sn.rounds(); }
};


template <typename T, std::size_t N, typename Compare = std::less<T>>
class network_sorter
 : basic_network_sorter<T, N, Compare>
{
private:
	std::size_t _round;
	std::array<std::array<T, N>, 2> _a;
public:
	constexpr inline
	network_sorter(std::array<T, N> a)
	 : _round{0}
	 , _a{{a, a}}
	{ }

	bool done(void) const
	noexcept { return _round >= this->rounds(); }

	bool next_round(void)
	noexcept
	{
		return !done() && (++_round < this->rounds());
	}

	network_sorter& sort_single(std::size_t r, std::size_t i)
	{
		std::size_t src = (r+0)%2;
		std::size_t dst = (r+1)%2;
		this->single_sort_step(_a[src], _a[dst], r, i);
		return *this;
	}

	network_sorter& sort_single(std::size_t i)
	{
		return sort_single(_round, i);
	}

	network_sorter& sort_round(void)
	{
		assert(!done());
		for(std::size_t i=0; i<N; ++i) {
			sort_single(i);
		}
		return *this;
	}

	network_sorter& sort(void)
	{
		while(sort_round().next_round()){ }
		return *this;
	}

	const std::array<T, N>& result(void) const
	noexcept { return _a[this->rounds()%2]; }

	const std::array<T, N>& operator()(void)
	{
		return sort().result();
	}
};

} // namespace eagine

#endif //include guard

