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
	span_size_t _size;
	std::string _str;

	template <typename Str>
	void _init(const span<Str>& names)
	{
		span_size_t len = 2*names.size();
		for(const auto& name : names) {
			len += span_size(name.size());
		}
		_str.reserve(std_size(len));

		for(const auto& name : names) {
			push_back(name);
		}
		assert(span_size(_str.size()) == len);
	}

	static inline
	cstring_span _fix(cstring_span str)
	noexcept {
		while(str.size() > 0) {
			if(str[str.size()-1] == '\0') {
				str = cstring_span(
					str.data(),
					str.size()-1
				);
			}
			else break;
		}
		return str;
	}

	template <typename ... Str>
	static inline
	std::array<cstring_span,sizeof...(Str)>
	_pack_names(const Str&... n)
	noexcept { return {{_fix(n)...}}; }
public:
	typedef cstring_span value_type;
	typedef cstring_span str_span;
	typedef span_size_t size_type;
	typedef string_list::iterator<const char*> iterator;
	typedef string_list::rev_iterator<const char*> reverse_iterator;

	basic_string_path(void)
	noexcept
	 : _size{0}
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
	 : basic_string_path(make_span(names))
	{ }

	template <typename ... Str>
	basic_string_path(const str_span& name, const Str& ... names)
	 : basic_string_path(_pack_names(name, make_span(names)...))
	{ }

	friend
	bool operator == (const basic_string_path& a,const basic_string_path& b)
	noexcept { return a._str == b._str; }

	friend
	bool operator != (const basic_string_path& a,const basic_string_path& b)
	noexcept { return a._str != b._str; }

	friend
	bool operator <  (const basic_string_path& a,const basic_string_path& b)
	noexcept { return a._str <  b._str; }

	friend
	bool operator <= (const basic_string_path& a,const basic_string_path& b)
	noexcept { return a._str <= b._str; }

	friend
	bool operator >  (const basic_string_path& a,const basic_string_path& b)
	noexcept { return a._str >  b._str; }

	friend
	bool operator >= (const basic_string_path& a,const basic_string_path& b)
	noexcept { return a._str >= b._str; }

	friend
	basic_string_path
	operator + (const basic_string_path& a, const basic_string_path& b)
	noexcept { return basic_string_path(a, b); }

	bool empty(void) const
	noexcept {
		assert((size() == 0) == _str.empty());
		return _str.empty();
	}

	void clear(void) {
		_size = 0;
		_str.clear();
	}

	size_type size(void) const
	noexcept { return _size; }

	static
	size_type required_bytes(size_type l)
	noexcept {
		using namespace mbs;
		return l+2*required_sequence_length(code_point_t(l)).value();
	}

	static
	size_type required_bytes(str_span str)
	noexcept { return required_bytes(size_type(str.size())); }

	void reserve_bytes(size_type s) { _str.reserve(std_size(s)); }

	str_span front(void) const
	noexcept {
		assert(!empty());
		return string_list::front_value(_str);
	}

	str_span back(void) const
	noexcept {
		assert(!empty());
		return string_list::back_value(_str);
	}

	void push_back(str_span name) {
		string_list::push_back(_str, _fix(name));
		++_size;
	}

	void push_back_elem(const string_list::element& elem) {
		_str.append(elem.data(), std_size(elem.size()));
		++_size;
	}

	void pop_back(void) {
		assert(!empty());
		_str.resize(string_list::pop_back(_str).size());
		--_size;
	}

	iterator begin(void) const
	noexcept {
		return empty()?
			iterator():
			iterator(_str.data());
	}

	iterator end(void) const
	noexcept {
		return empty()?
			iterator():
			iterator(_str.data()+_str.size());
	}

	reverse_iterator rbegin(void) const
	noexcept {
		return empty()?
			reverse_iterator():
			reverse_iterator(_str.data()+_str.size()-1);
	}

	reverse_iterator rend(void) const
	noexcept {
		return empty()?
			reverse_iterator():
			reverse_iterator(_str.data()-1);
	}

	template <typename Func>
	void for_each_elem(Func func) const {
		string_list::for_each_elem(make_span(_str), func);
	}

	template <typename Func>
	void for_each(Func func) const {
		string_list::for_each(make_span(_str), func);
	}

	template <typename Func>
	void rev_for_each_elem(Func func) const {
		string_list::rev_for_each_elem(make_span(_str), func);
	}

	template <typename Func>
	void rev_for_each(Func func) const {
		string_list::rev_for_each(make_span(_str), func);
	}

	std::string as_string(const str_span& sep, bool trail_sep) const {
		return string_list::join(make_span(_str), sep, trail_sep);
	}

	memory::const_block block(void)
	noexcept {
		return memory::const_block(
			_str.data(),
			span_size(_str.size())
		);
	}
};

} // namespace eagine

#endif // include guard
