/**
 *  @file eagine/biteset.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BITESET_1509260923_HPP
#define EAGINE_BITESET_1509260923_HPP

#include <eagine/byteset.hpp>
#include <eagine/int_constant.hpp>
#include <climits>

namespace eagine {

template <std::size_t N, std::size_t B, typename T = unsigned char>
class biteset {
private:
public:
	static constexpr const std::size_t _store_size =
		((N*B)/CHAR_BIT) + (((N*B)%CHAR_BIT != 0)?1:0);

	using _bytes_t = byteset<_store_size>;
	using _byte_t = typename _bytes_t::value_type;

	// the number of useful bits in T
	static constexpr const std::size_t _bite_s = B;
	// the number of bits in a byte
	static constexpr const std::size_t _byte_s = CHAR_BIT;
	// the number of all bits in T
	static constexpr const std::size_t _cell_s = sizeof(T)*CHAR_BIT;
public:
	static_assert(
		(B > 0),
		"bite size must be greater than zero"
	);
	static_assert(
		(N > 0),
		"bite count must be greater than zero"
	);
	static_assert(
		(_cell_s >= _bite_s),
		"bite with B bits size does not fit into type T"
	);
	static_assert(
		std::is_integral_v<T>,
		"T must be integral type"
	);

	using size_type = span_size_t;
	using value_type = T;

	constexpr
	biteset(void)
	noexcept
	 : _bytes{}
	{ }

	template <
		typename ... P,
		typename = std::enable_if_t<
			(sizeof...(P) == N) &&
			std::conjunction_v<
				std::true_type,
				std::is_convertible<P, T>...
			>
		>
	>
	explicit constexpr inline
	biteset(P ... p)
	noexcept
	 : _bytes{_make_bytes(T(p)...)}
	{ }

	constexpr inline
	size_type size(void) const
	noexcept { return N; }

	constexpr inline
	T operator [](size_type i) const
	noexcept { return _get_cell(std::size_t(i)); }

	constexpr
	const _bytes_t& bytes(void) const
	noexcept { return _bytes; }
private:
	_bytes_t _bytes;

	static constexpr inline
	std::size_t _min_s(std::size_t x, std::size_t y)
	noexcept { return (x < y) ? x : y; }

	static constexpr inline
	_byte_t _extract_init_bits(T init, std::size_t ofs, std::size_t len)
	noexcept {
		return	_byte_t(init >> (_bite_s-ofs-len))&
			_byte_t((1 << len)-1);
	}

	static constexpr inline
	T _extract_cell_bits(_byte_t by, std::size_t ofs, std::size_t len)
	noexcept {
		return	T(by >> (_byte_s-ofs-len))&
			T((1 << len)-1);
	}

	template <std::size_t L>
	static constexpr inline
	_byte_t _do_get_byte_bits(
		const T(&init)[N],
		_byte_t state,
		std::size_t bo, std::size_t bl,
		std::size_t bb, std::size_t be,
		std::size_t cb, std::size_t ce,
		size_constant<L>
	) noexcept {
		return _get_byte_bits(
			init,
			_byte_t(state << bl)|
			_extract_init_bits(cb<N?init[cb]:T(0), bo, bl),
			bb+bl, be,
			cb+1, ce,
			size_constant<L+1>{}
		);
	}

	template <std::size_t L>
	constexpr inline
	T _do_get_cell_bits(
		T state,
		std::size_t bo, std::size_t bl,
		std::size_t bb, std::size_t be,
		std::size_t cb, std::size_t ce,
		size_constant<L>
	) const noexcept {
		return _get_cell_bits(
			T(state << bl)|
			_extract_cell_bits(_bytes[size_type(cb)], bo, bl),
			bb+bl, be,
			cb+1, ce,
			size_constant<L+1>{}
		);
	}

	static constexpr inline
	_byte_t _get_byte_bits(
		const T(&)[N],
		_byte_t state,
		std::size_t, std::size_t,
		std::size_t, std::size_t,
		size_constant<_byte_s>
	) noexcept { return state; }

	template <std::size_t L>
	static constexpr inline
	_byte_t _get_byte_bits(
		const T(&init)[N],
		_byte_t state,
		std::size_t bb, std::size_t be,
		std::size_t cb, std::size_t ce,
		size_constant<L> l
	) noexcept {
		return (bb >= be)?state:_do_get_byte_bits(
			init, state,
			(bb-cb*_bite_s),
			_min_s((be-bb),(_bite_s-(bb-cb*_bite_s))),
			bb, be, cb, ce, l
		);
	}

	static constexpr inline
	T _get_cell_bits(
		T state,
		std::size_t, std::size_t,
		std::size_t, std::size_t,
		size_constant<_byte_s>
	) noexcept { return state; }

	template <std::size_t L>
	constexpr inline
	T _get_cell_bits(
		T state,
		std::size_t bb, std::size_t be,
		std::size_t cb, std::size_t ce,
		size_constant<L> l
	) const noexcept {
		return (bb >= be)?state:_do_get_cell_bits(
			state,
			(bb-cb*_byte_s),
			_min_s((be-bb),(_byte_s-(bb-cb*_byte_s))),
			bb, be, cb, ce, l
		);
	}

	static constexpr inline
	_byte_t _get_byte_bits(
		const T(&init)[N],
		std::size_t bb,
		std::size_t be
	) noexcept {
		return _get_byte_bits(
			init, _byte_t(0),
			bb, be,
			bb/_bite_s, be/_bite_s,
			size_constant<1>{}
		);
	}

	constexpr inline
	T _get_cell_bits(
		std::size_t bb,
		std::size_t be
	) const noexcept {
		return _get_cell_bits(
			_byte_t(0),
			bb, be,
			bb/_byte_s, be/_byte_s,
			size_constant<1>{}
		);
	}

	static constexpr inline
	_byte_t _get_byte(const T(&init)[N], std::size_t i)
	noexcept {
		return	(B == _byte_s)?
			_byte_t(init[i]):
			_get_byte_bits(
				init,
				(i+0)*_byte_s,
				(i+1)*_byte_s
			);
	}

	constexpr inline
	T _get_cell(std::size_t i) const
	noexcept {
		return	(B == _byte_s)?
			T(_bytes[size_type(i)]):
			_get_cell_bits(
				(i+0)*_bite_s,
				(i+1)*_bite_s
			);
	}

	template <std::size_t ... I>
	static constexpr inline
	_bytes_t _do_make_bytes(
		const T(&init)[N],
		std::index_sequence<I...>
	) noexcept { return _bytes_t{_get_byte(init, size_constant<I>{})...}; }

	template <typename ... P>
	static constexpr inline
	_bytes_t _make_bytes(P ... p)
	noexcept {
		return _do_make_bytes(
			{T(p)...},
			std::make_index_sequence<_store_size>{}
		);
	}
};

} // namespace eagine

#endif // include guard
