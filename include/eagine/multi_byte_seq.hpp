/**
 *  @file eagine/multi_byte_seq.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MULTI_BYTE_SEQ_1509260923_HPP
#define EAGINE_MULTI_BYTE_SEQ_1509260923_HPP

#include "valid_if.hpp"
#include "types.hpp"
#include "span.hpp"
#include <cstdint>
#include <string>

namespace eagine {
namespace mbs {

typedef std::uint32_t code_point_t;
typedef valid_if_less_than<code_point_t, 0x7FFFFFFF> code_point;

static constexpr inline
code_point_t max_code_point(std::size_t len)
noexcept
{
	return	len==1?	0x0000007F: //  7b
		len==2? 0x000007FF: // 11b
		len==3? 0x0000FFFF: // 16b
		len==4? 0x001FFFFF: // 21b
		len==5? 0x03FFFFFF: // 26b
		len==6? 0x7FFFFFFF: // 31b
			0x00000000;
}

static constexpr inline
auto head_data_bitshift(std::size_t len)
noexcept
{
	return (len-1)*6;
}

static constexpr inline
auto tail_data_bitshift(std::size_t idx, std::size_t len)
noexcept
{
	return (len-idx-1)*6;
}

static constexpr inline
byte head_length_mask(std::size_t len)
noexcept
{
	return	len==1?	0x80:
		len==2?	0xE0:
		len==3?	0xF0:
		len==4?	0xF8:
		len==5?	0xFC:
		len==6?	0xFE:
			0x00;
}

static constexpr inline
byte head_data_mask(std::size_t len)
noexcept 
{
	return ~head_length_mask(len);
}

static constexpr inline
byte tail_data_mask(void)
noexcept 
{
	return 0x3F;
}

static constexpr inline
byte head_code(std::size_t len)
noexcept
{
	return (head_length_mask(len) << 1) & 0xFF;
}

static constexpr inline
byte tail_code(void)
noexcept
{
	return 0x80;
}

static inline
valid_if_between<std::size_t, 1u, 6u>
required_sequence_length(code_point_t cp)
noexcept
{
	for(std::size_t l=1; l<=6; ++l)
	{
		if(cp < max_code_point(l))
		{
			return l;
		}
	}
	return 0;
}

static inline
valid_if_between<std::size_t, 1u, 6u>
do_decode_sequence_length(byte b)
noexcept
{
	for(std::size_t l=1; l<=6; ++l)
	{
		if((b & head_length_mask(l)) == head_code(l))
		{
			return l;
		}
	}
	return 0;
}

template <typename B>
static inline
valid_if_between<std::size_t, 1u, 6u>
decode_sequence_length(const span<const B>& seq)
noexcept
{
	assert(seq.size() > 0);
	return do_decode_sequence_length(byte(seq[0]));
}

template <typename B>
static inline
code_point decode_code_point(const span<const B>& src)
noexcept
{
	assert(src.size() > 0);
	if(auto len = decode_sequence_length(src))
	{
		const std::size_t l = len.value();
		assert(span_size_type(l) < src.size());

		code_point_t cp = code_point_t(
			(byte(src[0]) & head_data_mask(l)) <<
			head_data_bitshift(l)
		);

		for(std::size_t i=1; i<l; ++i)
		{
			cp |= code_point_t(
				(byte(src[i]) & tail_data_mask()) <<
				tail_data_bitshift(i, l)
			);
		}
		return cp;
	}
	return code_point(~code_point_t(0));
}

template <typename B>
static inline
void do_encode_code_point(code_point cp, const span<B>& dest, std::size_t l)
{
	assert(span_size_type(l) <= dest.size());

	code_point_t val = cp.value();

	dest[0] = B(
		head_code(l) |
		(head_data_mask(l) & (val >> head_data_bitshift(l)))
	);

	for(std::size_t i=1; i<l; ++i)
	{
		dest[i] = B(
			tail_code() | 
			(tail_data_mask() & (val >> tail_data_bitshift(i, l)))
		);
	}
}

template <typename B>
static inline
bool encode_code_point(code_point cp, const span<B>& dest)
noexcept
{
	if(auto len = required_sequence_length(cp.value()))
	{
		do_encode_code_point(cp, dest, len.value());
		return true;
	}
	return false;
}

static inline
valid_if_not_empty<std::string> encode_code_point(code_point cp)
noexcept
{
	if(auto len = required_sequence_length(cp.value()))
	{
		std::string tmp(len.value(), '\0');
		do_encode_code_point(
			cp,
			span<char>(
				const_cast<char*>(tmp.data()),
				static_cast<span_size_type>(tmp.size())
			),
			len.value()
		);
		return {std::move(tmp)};
	}
	return {};
}


} // namespace mbs
} // namespace eagine

#endif // include guard
