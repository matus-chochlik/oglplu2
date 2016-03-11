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

#include "config/platform.hpp"
#include "string_span.hpp"
#include <cstring>
#include <cassert>
#include <iosfwd>
#if EAGINE_APPLE
#include <ostream>
#endif

namespace eagine {

#ifdef __clang__ // TODO: throw this out once GSL is fixed
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wsign-conversion"
#endif

class cstr_ref
 : public cstring_span<>
{
private:
	typedef cstring_span<> _base;

	static
	std::false_type _is_v_c(...);

	template <
		typename C,
		typename VT = typename C::value_type,
		typename ST = typename C::size_type
	>
	static
	std::true_type _is_v_c(
		C*,
		const VT* (C::*)(void) const = &C::data,
		ST (C::*)(void) const = &C::size
	);

	template <typename X>
	struct _is_compatible_container
	 : decltype(_is_v_c(static_cast<X*>(nullptr)))
	{ };
public:
	cstr_ref(void) = default;

	cstr_ref(const char* cstr, span_size_type n)
	noexcept
	 : _base(cstr, (n > 0 && cstr[n-1]=='\0')?n-1:n)
	{ }

	template <std::size_t N>
	cstr_ref(const char (&cstr)[N])
	noexcept
	 : cstr_ref(cstr, span_size_type(N))
	{ }

	explicit
	cstr_ref(const char* cstr)
	noexcept
	 : cstr_ref(cstr, span_size_type(std::strlen(cstr)))
	{ }

	template <
		typename Container,
		typename = std::enable_if_t<
			_is_compatible_container<Container>::value
		>
	>
	explicit
	cstr_ref(const Container& cont)
	noexcept
	 : cstr_ref(cont.data(), span_size_type(cont.size()))
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

#ifdef __clang__
#pragma clang diagnostic pop
#endif

static inline
std::ostream& operator << (std::ostream& out, const cstr_ref& str)
{
	str.write_to_stream(out);
	return out;
}

} // namespace eagine

#endif // include guard
