/**
 *  @file eagine/sorting_network.hpp
 */

#ifndef EAGINE_SORTING_NETWORK_1512222148_HPP
#define EAGINE_SORTING_NETWORK_1512222148_HPP

#include <cstdint>

namespace eagine {

template <std::size_t N>
struct sorting_network;

template <>
struct sorting_network<1>
{
	static constexpr inline
	std::size_t size(void)
	noexcept { return 1; }

	static constexpr inline
	std::size_t rounds(void)
	noexcept { return 1; }

	static constexpr inline
	std::size_t index(std::size_t /*round*/, std::size_t /*elem*/)
	noexcept { return 0; }
};

template <>
struct sorting_network<2>
{
	static constexpr inline
	std::size_t size(void)
	noexcept { return 2; }

	static constexpr inline
	std::size_t rounds(void)
	noexcept { return 1; }

	static constexpr inline
	std::size_t index(std::size_t /*round*/, std::size_t elem)
	noexcept { return elem==0?1:0; }
};

template <>
struct sorting_network<3>
{
	static constexpr inline
	std::size_t size(void)
	noexcept { return 3; }

	static constexpr inline
	std::size_t rounds(void)
	noexcept { return 3; }

	static inline
	std::size_t index(std::size_t round, std::size_t elem)
	noexcept {
		static std::size_t idx[3][3] = {{1, 0, 2},{0, 2, 1},{1, 0, 2}};
		return idx[round][elem];
	}
};

template <>
struct sorting_network<4>
{
	static constexpr inline
	std::size_t size(void)
	noexcept { return 4; }

	static constexpr inline
	std::size_t rounds(void)
	noexcept { return 3; }

	static inline
	std::size_t index(std::size_t round, std::size_t elem)
	noexcept {
		static std::size_t idx[3][4] = {
			{1, 0, 3, 2},
			{2, 3, 0, 1},
			{0, 2, 1, 3}
		};
		return idx[round][elem];
	}
};

} // namespace eagine

#endif //include guard

