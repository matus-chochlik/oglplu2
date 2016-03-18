/**
 *  @file eagine/string_list.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STRING_LIST_1509260923_HPP
#define EAGINE_STRING_LIST_1509260923_HPP

#include "multi_byte_seq.hpp"
#include <iterator>
#include <string>
#include <cassert>

namespace eagine {
namespace string_list {

static inline
span_size_type
value_length_size(const span<const char>& elem)
noexcept
{
	return span_size_type(mbs::decode_sequence_length(elem).value());
}

static inline
span_size_type
value_size(const span<const char>& elem, span_size_type l)
noexcept
{
	return span_size_type(mbs::do_decode_code_point(elem, std::size_t(l)));
}

template <typename Func>
static inline
void for_each_elem(const span<const char>& str, Func func)
noexcept
{
	typedef span<const char> S;
	span_size_type i = 0;
	bool first = true;
	while(i < str.size())
	{
		S sub(str.data()+i, str.size()-i);
		span_size_type ls = value_length_size(sub);
		span_size_type vs = value_size(sub, ls);
		func(S(str.data()+i, ls+vs+ls), vs, ls, first);
		i += ls+vs+ls;
		first = false;
	}
}

template <typename Func>
static inline
void for_each(const span<const char>& str, Func func)
noexcept
{
	typedef span<const char> S;
	auto adapted_func = [&func](
		const S& elem,
		span_size_type vs,
		span_size_type ls,
		bool
	) { func(S(elem.data()+ls, vs)); };
	for_each_elem(str, adapted_func);
}

template <typename Func>
static inline
void rev_for_each_elem(const span<const char>& str, Func func)
noexcept
{
	typedef span<const char> S;
	span_size_type i = str.size()-1;
	bool first = true;
	while(i > 0)
	{
		while(!mbs::is_valid_head_byte(byte(str[i])))
		{
			assert(i > 0);
			--i;
		}

		S sub(str.data()+i, str.size()-i);
		span_size_type ls = value_length_size(sub);
		span_size_type vs = value_size(sub, ls);
		func(S(str.data()+i-vs-ls, ls+vs+ls), vs, ls, first);
		i -= vs+ls+1;
		first = false;
	}
}

template <typename Func>
static inline
void rev_for_each(const span<const char>& str, Func func)
noexcept
{
	typedef span<const char> S;
	auto adapted_func = [&func](
		const S& elem,
		span_size_type vs,
		span_size_type ls,
		bool
	) { func(S(elem.data()+ls, vs)); };
	rev_for_each_elem(str, adapted_func);
}

static inline
std::string
join(const span<const char>& str, const span<const char>& sep)
{
	span_size_type slen = sep.size();
	span_size_type len = 0;
	auto get_len = [&len,slen](
		const span<const char>&,
		span_size_type vs,
		span_size_type,
		bool first
	)
	{
		if(!first) len += slen;
		len += vs;
	};
	for_each_elem(str, get_len);

	std::string res;
	res.reserve(std::size_t(len));

	auto fill = [&res,sep](
		const span<const char>& elem,
		span_size_type vs,
		span_size_type ls,
		bool first
	)
	{
		if(!first) res.append(sep.data(), std::size_t(sep.size()));
		res.append(elem.data()+ls, std::size_t(vs));
	};
	for_each_elem(str, fill);
	assert(res.size() == std::size_t(len));

	return std::move(res);
}

template <typename Iter>
class iterator
{
private:
	Iter _pos;
	mutable span<const char> _tmp;

	byte _b(void) const
	noexcept
	{
		assert(_pos != nullptr);
		return byte(*_pos);
	}

	std::size_t _len_len(void) const
	noexcept
	{
		byte b = _b();
		assert(mbs::is_valid_head_byte(b));
		return mbs::do_decode_sequence_length(b).value();
	}

	std::size_t _val_len(std::size_t ll) const
	noexcept
	{
		span<const char> el(_pos, span_size_type(ll));
		return mbs::do_decode_code_point(el,ll); 
	}

	void _update(void) const
	{
		if(_pos != nullptr && (_tmp.size() == 0))
		{
			std::size_t ll = _len_len();
			std::size_t vl = _val_len(ll);
			_tmp = span<const char>{_pos+ll, span_size_type(vl)};
		}
	}
public:
	typedef std::ptrdiff_t difference_type;
	typedef span<const char> value_type;
	typedef const value_type& reference;
	typedef const value_type* pointer;
	typedef std::forward_iterator_tag iterator_category;

	iterator(void)
	noexcept
	 : _pos(nullptr)
	{ }

	iterator(Iter pos)
	noexcept
	 : _pos(pos)
	{ }

	friend
	bool operator == (iterator a, iterator b)
	noexcept
	{
		return a._pos == b._pos;
	}

	friend
	bool operator != (iterator a, iterator b)
	noexcept
	{
		return a._pos != b._pos;
	}

	friend
	bool operator <  (iterator a, iterator b)
	noexcept
	{
		return a._pos <  b._pos;
	}

	reference operator * (void) const
	noexcept
	{
		assert(_pos != nullptr);
		_update();
		return _tmp;
	}

	pointer operator -> (void) const
	noexcept
	{
		assert(_pos != nullptr);
		_update();
		return &_tmp;
	}

	iterator&
	operator ++ (void)
	noexcept
	{
		assert(_pos != nullptr);
		std::size_t ll = _len_len();
		std::size_t vl = _val_len(ll);
		_pos += ll+vl+ll;
		_tmp = span<const char>();
		return *this;
	}

	iterator
	operator ++ (int)
	noexcept
	{
		iterator result = *this;
		++(*this);
		return result;
	}
};

template <typename Iter>
class rev_iterator
{
private:
	mutable Iter _pos;
	mutable span<const char> _tmp;

	byte _b(void) const
	noexcept
	{
		assert(_pos != nullptr);
		return byte(*_pos);
	}

	void _rseek_head(void) const
	noexcept
	{
		assert(_pos != nullptr);
		while(!mbs::is_valid_head_byte(_b()))
		{ --_pos; };
	}

	std::size_t _len_len(void) const
	noexcept
	{
		byte b = _b();
		assert(mbs::is_valid_head_byte(b));
		return mbs::do_decode_sequence_length(b).value();
	}

	std::size_t _val_len(std::size_t ll) const
	noexcept
	{
		span<const char> el(_pos, span_size_type(ll));
		return mbs::do_decode_code_point(el,ll); 
	}

	void _update(void) const
	{
		if(_pos != nullptr && (_tmp.size() == 0))
		{
			_rseek_head();
			std::size_t ll = _len_len();
			std::size_t vl = _val_len(ll);
			_tmp = span<const char>{_pos-vl, span_size_type(vl)};
		}
	}
public:
	typedef std::ptrdiff_t difference_type;
	typedef span<const char> value_type;
	typedef const value_type& reference;
	typedef const value_type* pointer;
	typedef std::forward_iterator_tag iterator_category;

	rev_iterator(void)
	noexcept
	 : _pos(nullptr)
	{ }

	rev_iterator(Iter pos)
	noexcept
	 : _pos(pos)
	{ }

	friend
	bool operator == (rev_iterator a, rev_iterator b)
	noexcept
	{
		return a._pos == b._pos;
	}

	friend
	bool operator != (rev_iterator a, rev_iterator b)
	noexcept
	{
		return a._pos != b._pos;
	}

	friend
	bool operator <  (rev_iterator a, rev_iterator b)
	noexcept
	{
		return a._pos >  b._pos;
	}

	reference operator * (void) const
	noexcept
	{
		assert(_pos != nullptr);
		_update();
		return _tmp;
	}

	pointer operator -> (void) const
	noexcept
	{
		assert(_pos != nullptr);
		_update();
		return &_tmp;
	}

	rev_iterator&
	operator ++ (void)
	noexcept
	{
		assert(_pos != nullptr);
		_rseek_head();
		std::size_t ll = _len_len();
		std::size_t vl = _val_len(ll);
		_pos -= ll+vl+1;
		_tmp = span<const char>();
		return *this;
	}

	rev_iterator
	operator ++ (int)
	noexcept
	{
		rev_iterator result = *this;
		++(*this);
		return result;
	}
};

} // namespace string_list
} // namespace eagine

#endif // include guard
