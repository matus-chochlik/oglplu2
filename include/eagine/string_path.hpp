/**
 *  @file eagine/string_path.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STRING_PATH_1509260923_HPP
#define EAGINE_STRING_PATH_1509260923_HPP

#include "string_list.hpp"
#include "memory_block.hpp"
#include "span.hpp"
#include <string>

namespace eagine {

class basic_string_path
{
private:
	std::size_t _size;
	std::string _str;

	inline
	span<const char> _sub(std::size_t i) const
	noexcept
	{
		return {_str.data()+i, span_size_type(_str.size()-i)};
	}

	inline
	span<const char> _sub(std::size_t i, std::size_t l) const
	noexcept
	{
		return {_str.data()+i, span_size_type(l)};
	}

	template <typename Int>
	static inline
	std::string _encode_str_len(Int len)
	{
		return mbs::encode_code_point(mbs::code_point_t(len)).value();
	}

	static inline
	std::size_t _decode_len_len(const span<const char>& elen)
	{
		return std::size_t(mbs::decode_sequence_length(elen).value());
	}

	static inline
	std::size_t _decode_str_len(const span<const char>& elen, std::size_t l)
	{
		return std::size_t(mbs::do_decode_code_point(elen, l));
	}

	std::size_t _rseek_seq_head(std::size_t i) const
	{
		do { assert(i > 0); --i; }
		while(!mbs::is_valid_head_byte(byte(_str[i])));
		return i;
	}

	template <typename Str>
	void _init(const span<Str>& names)
	{
		std::size_t len = std::size_t(2*names.size());
		for(const span<const char>& name : names)
		{
			len += size_type(name.size());
		}
		_str.reserve(len);

		for(const span<const char>& name : names)
		{
			push_back(name);
		}
		assert(_str.size() == len);
	}

	static inline
	span<const char> _fix(span<const char> str)
	noexcept
	{
		while(str.size() > 0)
		{
			if(str[str.size()-1] == '\0')
			{
				str = span<const char>(str.data(),str.size()-1);
			}
			else break;
		}
		return str;
	}

	template <typename ... Str>
	static inline
	std::array<span<const char>,sizeof...(Str)>
	_pack_names(const Str&... n)
	noexcept
	{
		return {{_fix(n)...}};
	}
public:
	typedef span<const char> value_type;
	typedef span<const char> str_span;
	typedef std::size_t size_type;
	typedef string_list::iterator<const char*> iterator;
	typedef string_list::rev_iterator<const char*> reverse_iterator;

	basic_string_path(void)
	noexcept
	 : _size(0)
	{ }

	basic_string_path(const basic_string_path&) = default;
	basic_string_path(basic_string_path&&) = default;
	basic_string_path& operator = (const basic_string_path&) = default;
	basic_string_path& operator = (basic_string_path&&) = default;

	basic_string_path(const basic_string_path& a,const basic_string_path& b)
	 : _size(a._size + b._size)
	 , _str(a._str + b._str)
	{ }

	basic_string_path(const span<const str_span>& names)
	 : _size(0)
	{ _init(names); }

	template <std::size_t N>
	basic_string_path(const std::array<str_span, N>& names)
	 : basic_string_path(as_span(names))
	{ }

	template <typename ... Str>
	basic_string_path(const str_span& name, const Str& ... names)
	 : basic_string_path(_pack_names(name, as_span(names)...))
	{ }

	friend
	bool operator == (const basic_string_path& a,const basic_string_path& b)
	noexcept
	{
		return a._str == b._str;
	}

	friend
	bool operator != (const basic_string_path& a,const basic_string_path& b)
	noexcept
	{
		return a._str != b._str;
	}

	friend
	bool operator <  (const basic_string_path& a,const basic_string_path& b)
	noexcept
	{
		return a._str <  b._str;
	}

	friend
	basic_string_path
	operator + (const basic_string_path& a, const basic_string_path& b)
	noexcept
	{
		return basic_string_path(a, b);
	}

	bool empty(void) const
	noexcept
	{
		assert((size() == 0) == _str.empty());
		return _str.empty();
	}

	size_type size(void) const
	noexcept
	{
		return _size;
	}

	static
	size_type required_bytes(size_type l)
	noexcept
	{
		using namespace mbs;
		return l+2*required_sequence_length(code_point_t(l)).value();
	}

	static
	size_type required_bytes(str_span str)
	noexcept
	{
		return required_bytes(size_type(str.size()));
	}

	void reserve_bytes(size_type s)
	{
		_str.reserve(s);
	}

	str_span front(void) const
	noexcept
	{
		assert(!empty());
		std::size_t i = 0;
		span<const char> elen = _sub(i);
		std::size_t k = _decode_len_len(elen);
		std::size_t l = _decode_str_len(elen, k);
		return _sub(k, l);
	}

	str_span back(void) const
	noexcept
	{
		assert(!empty());
		std::size_t i = _rseek_seq_head(_str.size());
		span<const char> elen = _sub(i);
		std::size_t k = _decode_len_len(elen);
		std::size_t l = _decode_str_len(elen, k);
		return _sub(i-l, l);
	}

	void push_back(str_span name)
	{
		name = _fix(name);
		std::string elen = _encode_str_len(name.size());
		_str.append(elen);
		_str.append(name.data(), std::string::size_type(name.size()));
		_str.append(elen);
		++_size;
	}

	void pop_back(void)
	{
		assert(!empty());
		std::size_t i = _rseek_seq_head(_str.size());
		span<const char> elen = _sub(i);
		std::size_t k = _decode_len_len(elen);
		std::size_t l = _decode_str_len(elen, k);
		assert(i >= k+l);
		_str.resize(i-k-l);
		--_size;
	}

	iterator begin(void) const
	noexcept
	{
		return empty()?
			iterator():
			iterator(_str.data());
	}

	iterator end(void) const
	noexcept
	{
		return empty()?
			iterator():
			iterator(_str.data()+_str.size());
	}

	reverse_iterator rbegin(void) const
	noexcept
	{
		return empty()?
			reverse_iterator():
			reverse_iterator(_str.data()+_str.size()-1);
	}

	reverse_iterator rend(void) const
	noexcept
	{
		return empty()?
			reverse_iterator():
			reverse_iterator(_str.data()-1);
	}

	template <typename Func>
	void for_each_elem(Func func) const
	{
		string_list::for_each_elem(as_span(_str), func);
	}

	template <typename Func>
	void for_each(Func func) const
	{
		string_list::for_each(as_span(_str), func);
	}

	template <typename Func>
	void rev_for_each_elem(Func func) const
	{
		string_list::rev_for_each_elem(as_span(_str), func);
	}

	template <typename Func>
	void rev_for_each(Func func) const
	{
		string_list::rev_for_each(as_span(_str), func);
	}

	std::string as_string(const str_span& sep) const
	{
		return string_list::join(as_span(_str), sep);
	}

	memory::const_block block(void)
	noexcept
	{
		return memory::const_block(_str.data(), _str.size());
	}
};

} // namespace eagine

#endif // include guard
