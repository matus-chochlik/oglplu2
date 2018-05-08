/**
 *  @file eagine/fixed_size_str.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_FIXED_SIZE_STR_1509260923_HPP
#define EAGINE_FIXED_SIZE_STR_1509260923_HPP

#include "cstr_ref.hpp"
#include "int_constant.hpp"
#include "types.hpp"
#include <cstring>

namespace eagine {

template <span_size_t N>
class fixed_size_string {
private:
    static_assert(N > 0, "Zero-length fixed size strings are not supported");

    char _str[N];

    template <span_size_t>
    friend class fixed_size_string;

public:
    fixed_size_string(void) noexcept {
	std::memset(_str, '\0', N);
    }

    template <typename... C, typename = std::enable_if_t<sizeof...(C) == N>>
    constexpr inline fixed_size_string(C... c) noexcept
      : _str{c...} {
    }

    fixed_size_string(const char (&s)[N]) noexcept {
	std::strncpy(_str, s, N);
	assert(_str[N - 1] == '\0');
    }

    template <span_size_t N1,
      span_size_t N2,
      typename = std::enable_if_t<N1 + N2 == N + 1>>
    fixed_size_string(const fixed_size_string<N1>& s1,
      const fixed_size_string<N2>& s2) noexcept {
	std::strncpy(_str, s1._str, N1);
	std::strncpy(_str + N1 - 1, s2._str, N2);
    }

    typedef span_size_t size_type;
    typedef char* iterator;
    typedef const char* const_iterator;

    bool empty(void) const noexcept {
	return _str[0] == '\0';
    }

    span_size_t size(void) const noexcept {
	return N - 1;
    }

    const char* data(void) const noexcept {
	return _str;
    }

    const char* c_str(void) const noexcept {
	assert(_str[N - 1] == '\0');
	return data();
    }

    iterator begin(void) noexcept {
	return _str;
    }

    const_iterator begin(void) const noexcept {
	return _str;
    }

    iterator end(void) noexcept {
	return _str + N - 1;
    }

    const_iterator end(void) const noexcept {
	return _str + N - 1;
    }

    cstr_ref ref(void) const noexcept {
	return cstr_ref(_str, N - 1);
    }

    operator cstr_ref(void) const noexcept {
	return ref();
    }
};

template <span_size_t N>
static inline fixed_size_string<N>
make_fixed_size_string(const char (&str)[N]) noexcept {
    return fixed_size_string<N>(str);
}

template <span_size_t N1, span_size_t N2>
static inline fixed_size_string<N1 + N2 - 1>
operator+(
  const fixed_size_string<N1>& s1, const fixed_size_string<N2>& s2) noexcept {
    return fixed_size_string<N1 + N2 - 1>(s1, s2);
}

template <int I>
static inline auto
to_fixed_size_string(
  int_constant<I>, std::enable_if_t<(I >= 0) && (I < 10)>* = 0) noexcept {
    return fixed_size_string<2>(char('0' + I), '\0');
}

template <int I>
static inline auto
to_fixed_size_string(int_constant<I>, std::enable_if_t<(I > 9)>* = 0) noexcept {
    return to_fixed_size_string(int_constant<I / 10>())
	   + fixed_size_string<2>(char('0' + I % 10), '\0');
}

template <int I>
static inline auto
to_fixed_size_string(int_constant<I>, std::enable_if_t<(I < 0)>* = 0) noexcept {
    return fixed_size_string<2>("-") + to_fixed_size_string(int_constant<-I>());
}

} // namespace eagine

#endif // include guard
