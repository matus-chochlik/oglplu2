/**
 *  @file eagine/range_algo.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_RANGE_ALGO_1509260923_HPP
#define EAGINE_RANGE_ALGO_1509260923_HPP

#include "valid_if.hpp"
#include "count.hpp"

namespace eagine {
namespace ranges {

template <typename Range1, typename Range2>
static inline
bool equal(const Range1& rng1, const Range2& rng2)
noexcept
{
	return rng1 == rng2;
}

template <typename Range>
static inline
Range subrange(
	const Range& rng,
	valid_range_position<Range> bgn,
	valid_range_position<Range> end
)
{
	return {rng.data()+bgn.value(rng), end.value(rng)-bgn.value(rng)};
}

template <typename Range>
static inline
Range slice(
	const Range& rng,
	valid_if_nonnegative<typename Range::size_type> pos,
	valid_if_nonnegative<typename Range::size_type> len
)
{
	if(pos.value() > rng.size())
	{
		pos = rng.size();
	}
	if(len.value() > rng.size()-pos.value())
	{
		len = rng.size()-pos.value();
	}
	return subrange<Range>(rng, pos.value(), pos.value()+len.value());
}

template <typename Range>
static inline
Range slice(
	const Range& rng,
	valid_if_nonnegative<typename Range::size_type> pos
)
{
	if(pos.value() > rng.size())
	{
		pos = rng.size();
	}
	return subrange<Range>(rng, pos.value(), rng.size());
}

template <typename Range>
static inline
Range head(
	const Range& rng,
	valid_if_nonnegative<typename Range::size_type> len
)
{
	return slice(rng, 0, len);
}

template <typename Range>
static inline
Range tail(
	const Range& rng,
	valid_if_nonnegative<typename Range::size_type> len
)
{
	if(len.value() > rng.size())
	{
		len = rng.size();
	}
	return slice(rng, rng.size()-len.value(), len);
}

template <typename Range1, typename Range2>
static inline
bool starts_with(const Range1& rng, const Range2& with)
{
	return equal(head(rng, with.size()), with);
}

template <typename Range1, typename Range2>
static inline
bool ends_with(const Range1& rng, const Range2& with)
{
	return equal(tail(rng, with.size()), with);
}

template <typename Range1, typename Range2>
static inline
valid_if<
	typename Range1::size_type,
	valid_flag_policy
> find_pos(const Range1& where, const Range2& what)
{
	const auto lt = what.size();
	if(lt > 0)
	{
		const auto ls = where.size();
		if(ls > 0)
		{

			if(ls >= lt)
			{
				typename Range1::size_type p = 0;
				const typename Range1::size_type n = ls-lt+1;

				while(p != n)
				{
					if(equal(slice(where, p, lt), what))
					{
						return {p, true};
					}
					++p;
				}
			}
		}
		return {ls, false};
	}
	return {0, true};
}

template <typename Range1, typename Range2>
static inline
valid_if<
	typename Range1::size_type,
	valid_flag_policy
> rfind_pos(const Range1& where, const Range2& what)
{
	const auto lt = what.size();
	if(lt > 0)
	{
		const auto ls = where.size();
		if(ls > 0)
		{

			if(ls >= lt)
			{
				typename Range1::size_type p = ls-lt;

				while(p >= 0)
				{
					if(equal(slice(where, p, lt), what))
					{
						return {p, true};
					}
					--p;
				}
			}
		}
		return {ls, false};
	}
	return {0, true};
}

template <typename Range1, typename Range2>
static inline
bool contains(const Range1& where, const Range2& what)
{
	return find_pos(where, what).is_valid();
}

template <typename Range1, typename Range2>
static inline
Range1 find(const Range1& where, const Range2& what)
{
	if(auto pos = find_pos(where, what))
	{
		return slice(where, pos.value());
	}
	return {};
}

template <typename Range1, typename Range2>
static inline
Range1 strip_prefix(const Range1& rng, const Range2& prefix)
{
	typename Range1::size_type ofs = 0;
	if(starts_with(rng, prefix))
	{
		ofs = prefix.size();
	}
	return slice(rng, ofs);
}

template <typename Range1, typename Range2>
static inline
Range1 strip_suffix(const Range1& rng, const Range2& suffix)
{
	typename Range1::size_type ofs = rng.size();
	if(ends_with(rng, suffix))
	{
		ofs = ofs-suffix.size();
	}
	return slice(rng, 0, ofs);
}

template <typename Range1, typename Range2>
static inline
Range1 slice_before(const Range1& rng, const Range2& what)
{
	return slice(rng, 0, find_pos(rng, what).value_or(rng.size()));
}

template <typename Range1, typename Range2>
static inline
Range1 slice_before_last(const Range1& rng, const Range2& what)
{
	return slice(rng, 0, rfind_pos(rng, what).value_or(0));
}

template <typename Range1, typename Range2>
static inline
Range1 slice_after(const Range1& rng, const Range2& what)
{
	if(auto pos = find_pos(rng, what))
	{
		return slice(rng, pos.value()+what.size());
	}
	return {};
}

template <typename Range1, typename Range2>
static inline
Range1 slice_after_last(const Range1& rng, const Range2& what)
{
	if(auto pos = rfind_pos(rng, what))
	{
		return slice(rng, pos.value()+what.size());
	}
	return {};
}

template <typename Range1, typename Range2, typename Range3>
static inline
Range1 slice_between(const Range1& rng, const Range2& bgn, const Range3& end)
{
	if(auto bpos = find_pos(rng, bgn))
	{
		if(auto epos=find_pos(slice(rng, bpos.value()+bgn.size()), end))
		{
			return slice(rng, bpos.value()+bgn.size(),epos.value());
		}
	}
	return {};
}


template <typename Range1, typename Range2, typename Range3>
static inline
Range1 slice_inside(const Range1& rng, const Range2& bgn, const Range3& end)
{
	if(auto bpos = find_pos(rng, bgn))
	{
		if(auto epos = rfind_pos(rng, end))
		{
			if(bpos.value()+bgn.size() < epos.value())
			{
				return slice(
					rng,
					bpos.value()+bgn.size(),
					epos.value()-bgn.size()-1
				);
			}
		}
	}
	return {};
}

template <typename Range1, typename Range2, typename UnaryOperation>
static inline
UnaryOperation for_each_delimited(
	const Range1& str,
	const Range2& delim,
	UnaryOperation unary_op
)
{
	Range1 tmp = str;
	while(auto p = find_pos(tmp, delim))
	{
		unary_op(head(tmp, p.value()));
		tmp = slice(tmp, p.value()+delim.size());
	}
	unary_op(tmp);
	return unary_op;
}

template <typename Range1, typename Range2>
static inline
std::size_t count_delimited(const Range1& where, const Range2& delim)
{
	return for_each_delimited(where, delim, count_t<std::size_t>());
}

template <
	typename BackInsertionSequence,
	typename Range1,
	typename Range2,
	typename Transform
>
static inline
BackInsertionSequence& split_into(
	BackInsertionSequence& dest,
	const Range1& rng,
	const Range2& delim,
	Transform transform
)
{
	for_each_delimited(
		rng, delim,
		[&dest, &transform](const auto& x)
		{
			dest.push_back(transform(x));
		}
	);
	return dest;
}

template <
	typename BackInsertionSequence,
	typename Range1,
	typename Range2
>
static inline
BackInsertionSequence& split_into(
	BackInsertionSequence& dest,
	const Range1& rng,
	const Range2& delim
)
{
	return split_into(
		dest, rng, delim,
		[](const auto& x)
		{
			return typename BackInsertionSequence::value_type(x);
		}
	);
}

template <
	typename BackInsertionSequence,
	typename Range1,
	typename Range2,
	typename Transform
>
static inline
BackInsertionSequence split(
	const Range1& rng,
	const Range2& delim,
	Transform transform
)
{
	BackInsertionSequence result;
	return std::move(split_into(result, rng, delim, transform));
}

template <
	typename BackInsertionSequence,
	typename Range1,
	typename Range2
>
static inline
BackInsertionSequence split(const Range1& rng, const Range2& delim)
{
	BackInsertionSequence result;
	return std::move(split_into(result, rng, delim));
}

} // namespace ranges
} // namespace eagine

#endif // include guard
