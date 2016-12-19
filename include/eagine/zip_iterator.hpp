/**
 *  @file eagine/zip_iterator.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ZIP_ITERATOR_1509260923_HPP
#define EAGINE_ZIP_ITERATOR_1509260923_HPP

#include <tuple>
#include <iterator>
#include "type_traits.hpp"
#include "int_sequence.hpp"

namespace eagine {

template <typename ... Iter>
class zip_iterator
{
private:
	using _idx_seq = std::make_index_sequence<sizeof...(Iter)>;
	using _iters_t = std::tuple<Iter...>;
	_iters_t _iters;

	template <std::size_t ... I>
	static inline
	auto _tie_deref(const _iters_t& a, std::index_sequence<I...>) {
		return std::tie(*std::get<I>(a)...);
	}

	template <typename IT, std::size_t ... I>
	static inline
	auto _tie_deref(IT& a, std::index_sequence<I...>) {
		return std::tie(*std::get<I>(a)...);
	}

	template <typename IT, typename Func, std::size_t ... I>
	static constexpr inline
	auto _fold_or_2(
		IT& a, IT& b,
		Func func,
		std::index_sequence<I...>
	) { return (... || func(std::get<I>(a), std::get<I>(b))); }

	template <typename IT, typename Func, std::size_t ... I>
	static constexpr inline
	auto _fold_and_2(
		IT& a, IT& b,
		Func func,
		std::index_sequence<I...>
	) { return (... && func(std::get<I>(a), std::get<I>(b))); }

	template <typename IT, typename Func, std::size_t ... I>
	static inline
	void _for_each_1(
		IT& a,
		Func func,
		std::index_sequence<I...>
	) { return (... , func(std::get<I>(a))); }
public:
	using difference_type = std::ptrdiff_t;

	constexpr
	zip_iterator(Iter ... iters)
	 : _iters(iters...)
	{ }

	friend
	bool operator == (const zip_iterator& a, const zip_iterator& b) {
		return _fold_and_2(
			a._iters, b._iters,
			[](auto ia, auto ib) { return ia == ib; },
			_idx_seq{}
		);
	}

	friend
	bool operator != (const zip_iterator& a, const zip_iterator& b) {
		return _fold_or_2(
			a._iters, b._iters,
			[](auto ia, auto ib) { return ia != ib; },
			_idx_seq{}
		);
	}
	
	zip_iterator& operator ++ (void) {
		_for_each_1(
			_iters,
			[](auto& i) { ++i; },
			_idx_seq{}
		);
		return *this;
	}

	auto operator * (void) const {
		return _tie_deref(_iters, _idx_seq{});
	}

	auto operator * (void) {
		return _tie_deref(_iters, _idx_seq{});
	}
};

template <typename ... Iter>
static inline
zip_iterator<Iter...> zip_iters(Iter ... i) {
	return {i...};
}

template <typename ... Range>
class zipped_range_refs
{
private:
	using _idx_seq = std::make_index_sequence<sizeof...(Range)>;
	using _rrefs_t = std::tuple<Range&...>;
	_rrefs_t _rrefs;

	template <typename RR, std::size_t ... I>
	static inline
	auto _zip_bgn(RR& r, std::index_sequence<I...>) {
		using std::begin;
		return zip_iters(std::begin(std::get<I>(r))...);
	}

	template <typename RR, std::size_t ... I>
	static inline
	auto _zip_end(RR& r, std::index_sequence<I...>) {
		using std::end;
		return zip_iters(std::end(std::get<I>(r))...);
	}
public:
	zipped_range_refs(Range& ... ranges)
	noexcept
	 : _rrefs(ranges...)
	{ }

	auto begin(void) { return _zip_bgn(_rrefs, _idx_seq{}); }
	auto begin(void) const { return _zip_bgn(_rrefs, _idx_seq{}); }

	auto end (void) { return _zip_end(_rrefs, _idx_seq{}); }
	auto end (void) const { return _zip_end(_rrefs, _idx_seq{}); }
};

template <typename ... Range>
static inline
zipped_range_refs<Range...> zip_ranges(Range& ... ranges)
noexcept { return {ranges...}; }

} // namespace eagine

#endif // include guard
