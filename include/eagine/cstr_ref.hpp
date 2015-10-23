/**
 *  @file eagine/utils/cstr_ref.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_UTILS_CSTR_REF_1509260923_HPP
#define EAGINE_UTILS_CSTR_REF_1509260923_HPP

#include "string_view.hpp"
#include <cstring>
#include <cassert>
#include <iosfwd>

namespace eagine {

class cstr_ref
 : public cstring_view<>
{
private:
	static
	std::false_type _is_v_c(...);

	template <typename C, typename VT = typename C::value_type>
	static
	std::true_type _is_v_c(
		C*,
		const VT* (C::*)(void) const = &C::data,
		std::size_t (C::*)(void) const = &C::size
	);

	template <typename X>
	struct _is_compatible_container
	 : decltype(_is_v_c(static_cast<X*>(nullptr)))
	{ };
public:
	cstr_ref(void) = default;

	cstr_ref(const char* cstr, std::size_t n)
	noexcept
	 : cstring_view<>(cstr, (n > 0 && cstr[n-1] == '\0')?n-1:n)
	{ }

	template <std::size_t N>
	cstr_ref(const char (&cstr)[N])
	noexcept
	 : cstr_ref(cstr, N)
	{ }

	explicit
	cstr_ref(const char* cstr)
	noexcept
	 : cstr_ref(cstr, std::strlen(cstr))
	{ }

	template <
		typename Container,
		typename = typename std::enable_if<
			_is_compatible_container<Container>::value
		>::type
	>
	cstr_ref(const Container& cont)
	noexcept
	 : cstr_ref(cont.data(), cont.size())
	{ }

	bool empty(void) const
	noexcept
	{
		return size() == 0u;
	}

	const char* c_str(void) const
	noexcept
	{
		if(data() == nullptr)
		{
			return "";
		}
		assert(data()[size()] == '\0');
		return data();
	}

	template <typename Out>
	void write_to_stream(Out& out) const
	{
		if(!empty())
		{
			out.write(data(), std::streamsize(size()));
		}
	}
};

static inline
std::ostream& operator << (std::ostream& out, const cstr_ref& str)
{
	str.write_to_stream(out);
	return out;
}

} // namespace eagine

#endif // include guard
