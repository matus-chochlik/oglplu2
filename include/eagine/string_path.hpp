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

#include "config/basic.hpp"
#include "multi_byte_seq.hpp"
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
	typedef span<const char> reference;
	typedef std::size_t size_type;

	basic_string_path(void)
	noexcept
	 : _size(0)
	{ }

	basic_string_path(const basic_string_path&) = default;
	basic_string_path(basic_string_path&&) = default;
	basic_string_path& operator = (const basic_string_path&) = default;
	basic_string_path& operator = (basic_string_path&&) = default;

	basic_string_path(const span<const reference>& names)
	 : _size(0)
	{ _init(names); }

	template <std::size_t N>
	basic_string_path(const std::array<reference, N>& names)
	 : basic_string_path(as_span(names))
	{ }

	template <typename ... Str>
	basic_string_path(const reference& name, const Str& ... names)
	 : basic_string_path(_pack_names(name, as_span(names)...))
	{ }

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

	reference front(void) const
	noexcept
	{
		assert(!empty());
		std::size_t i = 0;
		span<const char> elen = _sub(i);
		std::size_t k = _decode_len_len(elen);
		std::size_t l = _decode_str_len(elen, k);
		return _sub(k, l);
	}

	reference back(void) const
	noexcept
	{
		assert(!empty());
		std::size_t i = _rseek_seq_head(_str.size());
		span<const char> elen = _sub(i);
		std::size_t k = _decode_len_len(elen);
		std::size_t l = _decode_str_len(elen, k);
		return _sub(i-l, l);
	}

	void push_back(reference name)
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

	template <typename Func>
	void for_each_elem(Func func)
	{
		std::size_t i = 0;
		bool first = true;
		while(i < _str.size())
		{
			span<const char> elen = _sub(i);
			std::size_t k = _decode_len_len(elen);
			std::size_t l = _decode_str_len(elen, k);
			i += k;
			func(_sub(i-k, l+k), l, k, first);
			i += l+k;
			first = false;
		}
	}

	template <typename Func>
	void for_each(Func func)
	{
		auto adapted_func =
		[&func](reference elem, std::size_t l, std::size_t k, bool)
		{
			func(reference(elem.data()+k, span_size_type(l)));
		};
		for_each_elem(adapted_func);
	}

	template <typename Func>
	void rev_for_each_elem(Func func)
	{
		std::size_t i = _str.size();
		bool first = true;
		while(i > 0)
		{
			i = _rseek_seq_head(i);

			span<const char> elen = _sub(i);
			std::size_t k = _decode_len_len(elen);
			std::size_t l = _decode_str_len(elen, k);
			i -= l;
			func(_sub(i-k, l+k), l, k, first);
			i -= k;
			first = false;
		}
	}

	template <typename Func>
	void rev_for_each(Func func)
	{
		auto adapted_func =
		[&func](reference elem, std::size_t l, std::size_t k, bool)
		{
			func(reference(elem.data()+k, span_size_type(l)));
		};
		rev_for_each_elem(adapted_func);
	}

	std::string as_string(const reference& sep)
	{
		typedef std::size_t S;
		std::size_t slen = S(sep.size());
		std::size_t len = 0;
		auto get_len =
		[&len,slen](reference, std::size_t l, std::size_t, bool f)
		{
			if(!f) len += slen;
			len += l;
		};
		for_each_elem(get_len);

		std::string res;
		res.reserve(len);

		auto fill =
		[&res,sep](reference elem, std::size_t l, std::size_t k, bool f)
		{
			if(!f) res.append(sep.data(), S(sep.size()));
			res.append(elem.data()+k, l);
		};
		for_each_elem(fill);
		assert(res.size() == len);

		return std::move(res);
	}

	memory::const_block block(void)
	noexcept
	{
		return memory::const_block(_str.data(), _str.size());
	}
};



} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
//#include <eagine/string_path.inl>
#endif

#endif // include guard
