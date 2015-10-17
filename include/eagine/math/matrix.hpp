/**
 *  @file eagine/math/matrix.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_MATRIX_1509260923_HPP
#define EAGINE_MATH_MATRIX_1509260923_HPP

#include "vector.hpp"
#include "../int_sequence.hpp"

namespace eagine {
namespace math {

template <typename T, unsigned C, unsigned R, bool RM, bool V>
struct matrix
{
	typedef matrix type;

	typedef typename vect::data<T, RM?C:R, V>::type _vT;

	template <unsigned ... U>
	using _useq = integer_sequence<unsigned, U...>;

	template <unsigned N>
	using _make_useq = make_integer_sequence<unsigned, N>;

	_vT _v[RM?R:C];

	template <typename P, unsigned ... I>
	static inline
	matrix _from_hlp(const P* dt, std::size_t sz, _useq<I...>)
	noexcept
	{
		return matrix{{
			vect::from_array<T, RM?C:R, V>::apply(
				dt+I*(RM?C:R),
				sz-I*(RM?C:R)
			)...
		}};
	}

	template <typename P>
	static inline
	matrix from(const P* dt, std::size_t sz)
	noexcept
	{
		return _from_hlp(dt, sz, _make_useq<RM?R:C>());
	}

	template <typename P, unsigned M, unsigned N, bool W, unsigned ... I>
	static inline
	matrix _from_hlp(const matrix<P,M,N,RM,W>& m, _useq<I...>)
	noexcept
	{
		return matrix{{
			vect::cast<
				P,(RM?M:N),W,
				T,(RM?C:R),V
			>::apply(m._v[I],T(0))...
		}};
	}

	template <typename P, unsigned M, unsigned N, bool W>
	static inline
	typename std::enable_if<(C<=M)&&(R<=N), matrix>::type
	from(const matrix<P,M,N,RM,W>& m)
	noexcept
	{
		return _from_hlp(m, _make_useq<RM?R:C>());
	}

	inline
	const vector<T, RM?C:R, V> operator [] (unsigned i) const
	noexcept
	{
		return vector<T, RM?C:R, V>{_v[i]};
	}
};

template <typename T, unsigned C, unsigned R, bool RM, bool V>
static constexpr inline
unsigned rows(const matrix<T, C, R, RM, V>&)
noexcept
{
	return R;
}

template <typename T, unsigned C, unsigned R, bool RM, bool V>
static constexpr inline
unsigned columns(const matrix<T, C, R, RM, V>&)
noexcept
{
	return C;
}

template <typename T, unsigned C, unsigned R, bool RM, bool V>
static constexpr inline
bool row_major(const matrix<T, C, R, RM, V>&)
noexcept
{
	return RM;
}

template <typename T, unsigned N, bool RM, bool V>
static constexpr inline
unsigned dimension(const matrix<T, N, N, RM, V>&)
noexcept
{
	return N;
}

// get (Column-major)
template <unsigned CI, unsigned RI, typename T, unsigned C, unsigned R, bool V>
static constexpr inline
typename std::enable_if<(CI<C && RI<R), T>::type
get(const matrix<T, C, R,false, V>& m)
noexcept
{
	return m._v[CI][RI];
}

// get (Row-major)
template <unsigned CI, unsigned RI, typename T, unsigned C, unsigned R, bool V>
static constexpr inline
typename std::enable_if<(CI<C && RI<R), T>::type
get(const matrix<T, C, R, true, V>& m)
noexcept
{
	return m._v[RI][CI];
}

// get (Column-major, run-time)
template <typename T, unsigned C, unsigned R, bool V>
static constexpr inline
T get(const matrix<T, C, R,false, V>& m, unsigned ci, unsigned ri)
noexcept
{
	assert(ci<C && ri<R);
	return m._v[ci][ri];
}

// get (Row-major, run-time)
template <typename T, unsigned C, unsigned R, bool V>
static constexpr inline
T get(const matrix<T, C, R, true, V>& m, unsigned ci, unsigned ri)
noexcept
{
	assert(ci<C && ri<R);
	return m._v[ri][ci];
}

// set (Column-major)
template <unsigned CI, unsigned RI, typename T, unsigned C, unsigned R, bool V>
static inline
typename std::enable_if<(CI<C && RI<R), void>::type
set(matrix<T, C, R,false, V>& m, T v)
noexcept
{
	m._v[CI][RI] = v;
}

// get (Row-major)
template <unsigned CI, unsigned RI, typename T, unsigned C, unsigned R, bool V>
static inline
typename std::enable_if<(CI<C && RI<R), void>::type
set(matrix<T, C, R, true, V>& m, T v)
noexcept
{
	m._v[RI][CI] = v;
}

// get (Column-major, run-time)
template <typename T, unsigned C, unsigned R, bool V>
static inline
void set(matrix<T, C, R,false, V>& m, unsigned ci, unsigned ri, T v)
noexcept
{
	assert(ci<C && ri<R);
	m._v[ci][ri] = v;
}

// get (Row-major, run-time)
template <typename T, unsigned C, unsigned R, bool V>
static inline
void set(matrix<T, C, R, true, V>& m, unsigned ci, unsigned ri, T v)
noexcept
{
	assert(ci<C && ri<R);
	m._v[ri][ci] = v;
}

// transpose_tpl helper 4x4 matrix
template <bool DstRM, typename T, bool V>
static inline
matrix<T, 4, 4, DstRM, V>
transpose_tpl_hlp(
	const typename vect::data<T, 4, V>::type& q0,
	const typename vect::data<T, 4, V>::type& q1,
	const typename vect::data<T, 4, V>::type& q2,
	const typename vect::data<T, 4, V>::type& q3
) noexcept
{
	return matrix<T, 4, 4, DstRM, V>{{
		vect::shuffle2<T, 4, V>::template apply<0,2,4,6>(q0, q2),
		vect::shuffle2<T, 4, V>::template apply<1,3,5,7>(q0, q2),
		vect::shuffle2<T, 4, V>::template apply<0,2,4,6>(q1, q3),
		vect::shuffle2<T, 4, V>::template apply<1,3,5,7>(q1, q3)
	}};
}

// transpose_tpl 4x4 matrix
template <bool DstRM, bool SrcRM, typename T, bool V>
static inline
matrix<T, 4, 4, DstRM, V>
transpose_tpl(const matrix<T, 4, 4, SrcRM,V>& m)
noexcept
{
	return transpose_tpl_hlp<DstRM, T, V>(
		vect::shuffle2<T,4,V>::template apply<0,1,4,5>(m._v[0],m._v[1]),
		vect::shuffle2<T,4,V>::template apply<2,3,6,7>(m._v[0],m._v[1]),
		vect::shuffle2<T,4,V>::template apply<0,1,4,5>(m._v[2],m._v[3]),
		vect::shuffle2<T,4,V>::template apply<2,3,6,7>(m._v[2],m._v[3])
	);
}

// transpose_tpl
template <bool DstRM, bool SrcRM, typename T, unsigned C, unsigned R, bool V>
static inline
matrix<T, (DstRM==SrcRM?R:C), (DstRM==SrcRM?C:R), DstRM, V>
transpose_tpl(const matrix<T, C, R, SrcRM, V>& m)
noexcept
{
	static const bool S = (DstRM != SrcRM);
	matrix<T, (S?C:R), (S?R:C), DstRM, V> r;

	for(unsigned i=0; i<C; ++i)
	for(unsigned j=0; j<R; ++j)
	{
		set(r, S?i:j, S?j:i, get(m,i,j));
	}

	return r;
}

// transpose
template <typename T, unsigned C, unsigned R, bool RM, bool V>
static inline
matrix<T, R, C, RM, V>
transpose(const matrix<T, C, R, RM, V>& m)
noexcept
{
	return transpose_tpl<RM, RM, T>(m);
}

// reordered matrix trait
template <typename X>
struct reordered_matrix;

// reordered matrix
template <typename T, unsigned C, unsigned R, bool RM, bool V>
struct reordered_matrix<matrix<T, C, R, RM, V>>
 : matrix<T, R, C,!RM, V>
{ };

// reorder
template <typename T, unsigned C, unsigned R, bool RM, bool V>
static inline
matrix<T, C, R,!RM, V>
reorder(const matrix<T, C, R, RM, V>& m)
noexcept
{
	return transpose_tpl<!RM, RM, T>(m);
}

// make_row_major
template <typename T, unsigned C, unsigned R, bool V>
static constexpr inline
matrix<T, C, R, true,V>
make_row_major(matrix<T, C, R, true, V> m)
noexcept
{
	return m;
}

// make_row_major
template <typename T, unsigned C, unsigned R, bool V>
static inline
matrix<T, C, R, true,V>
make_row_major(const matrix<T, C, R,false, V>& m)
noexcept
{
	return reorder(m);
}

// make_column_major
template <typename T, unsigned C, unsigned R, bool V>
static constexpr inline
matrix<T, C, R,false,V>
make_column_major(matrix<T, C, R,false, V> m)
noexcept
{
	return m;
}

// make_column_major
template <typename T, unsigned C, unsigned R, bool V>
static inline
matrix<T, C, R,false,V>
make_column_major(const matrix<T, C, R, true, V>& m)
noexcept
{
	return reorder(m);
}

} // namespace math

template <typename T, unsigned C, unsigned R, bool RM, bool V>
struct is_known_vector_type<math::matrix<T, C, R, RM, V>>
 : std::is_scalar<T>
{ };

template <typename T, unsigned C, unsigned R, bool RM, bool V>
struct canonical_compound_type<math::matrix<T, C, R, RM, V>>
 : identity<typename std::remove_cv<T[C][R]>::type>
{ };

template <typename T, unsigned C, unsigned R, bool RM, bool V>
struct compound_view_maker<math::matrix<T, C, R, RM, V>>
{
	inline
	auto operator()(const math::matrix<T, C, R, RM, V>& m) const
	noexcept
	{
		return vect::view<T, RM?C:R, V>::apply(m._v);
	}
};

template <typename T, unsigned C, unsigned R, bool RM, bool V>
struct is_row_major<math::matrix<T,C,R,RM,V>>
 : std::integral_constant<bool, RM>
{ };

} // namespace eagine

#endif //include guard

