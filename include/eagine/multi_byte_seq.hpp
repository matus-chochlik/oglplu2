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

typedef valid_if_between<std::size_t, 1u, 6u> valid_sequence_length;

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
byte head_code_mask(std::size_t len)
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
	return ~head_code_mask(len);
}

static constexpr inline
byte tail_code_mask(void)
noexcept 
{
	return 0xC0;
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
	return (head_code_mask(len) << 1) & 0xFF;
}

static constexpr inline
byte tail_code(void)
noexcept
{
	return 0x80;
}

static constexpr inline
bool is_valid_head_byte(byte b, std::size_t l)
noexcept
{
	return (b & head_code_mask(l)) == head_code(l);
}

static inline
bool is_valid_head_byte(byte b)
noexcept
{
	for(std::size_t l=1; l<6; ++l)
	{
		if(is_valid_head_byte(b, l))
		{
			return true;
		}
	}
	return false;
}

static constexpr inline
bool is_valid_tail_byte(byte b, std::size_t, std::size_t)
noexcept
{
	return (b & tail_code_mask()) == tail_code();
}

static inline
valid_sequence_length
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
valid_sequence_length
do_decode_sequence_length(byte b)
noexcept
{
	for(std::size_t l=1; l<=6; ++l)
	{
		if(is_valid_head_byte(b, l))
		{
			return l;
		}
	}
	return 0;
}

template <typename B>
static inline
valid_sequence_length
decode_sequence_length(const span<B>& seq)
noexcept
{
	assert(seq.size() > 0);
	return do_decode_sequence_length(byte(seq[0]));
}

template <typename B>
static inline
bool is_valid_encoding(const span<B>& seq)
noexcept
{
	assert(seq.size() > 0);
	if(auto len = decode_sequence_length(seq))
	{
		const std::size_t l = len.value();
		assert(span_size_type(l) <= seq.size());

		if(!is_valid_head_byte(byte(seq[0]), l))
		{
			return false;
		}

		for(std::size_t i=1; i<l; ++i)
		{
			if(!is_valid_tail_byte(byte(seq[i]), i, l))
			{
				return false;
			}
		}
		return true;	
	}
	return false;
}

static constexpr inline
code_point_t decode_code_point_head(byte b, std::size_t l)
noexcept
{
	return code_point_t((b & head_data_mask(l)) << head_data_bitshift(l));
}

static constexpr inline
code_point_t decode_code_point_tail(byte b, std::size_t i, std::size_t l)
noexcept
{
	return code_point_t((b & tail_data_mask()) << tail_data_bitshift(i, l));
}

template <typename B>
static inline
code_point_t do_decode_code_point(const span<B>& src, std::size_t l)
noexcept
{
	assert(span_size_type(l) <= src.size());

	code_point_t cp = decode_code_point_head(byte(src[0]), l);

	for(std::size_t i=1; i<l; ++i)
	{
		cp |= decode_code_point_tail(byte(src[i]), i, l);
	}

	return cp;
}

template <typename B>
static inline
code_point decode_code_point(const span<B>& src)
noexcept
{
	if(auto len = decode_sequence_length(src))
	{
		return do_decode_code_point(src, len.value());
	}
	return code_point(~code_point_t(0));
}

static constexpr inline
byte encode_code_point_head(code_point_t cp, std::size_t l)
noexcept
{
	return head_code(l)|(head_data_mask(l)&(cp >> head_data_bitshift(l)));
}

static constexpr inline
byte encode_code_point_tail(code_point_t cp, std::size_t i, std::size_t l)
noexcept
{
	return tail_code()|(tail_data_mask()&(cp >> tail_data_bitshift(i, l)));
}

template <typename B>
static inline
void do_encode_code_point(code_point cp, const span<B>& dest, std::size_t l)
noexcept
{
	assert(span_size_type(l) <= dest.size());

	code_point_t val = cp.value();

	dest[0] = B(encode_code_point_head(val, l));

	for(std::size_t i=1; i<l; ++i)
	{
		dest[i] = B(encode_code_point_tail(val, i, l));
	}
}

template <typename B>
static inline
valid_sequence_length
encode_code_point(code_point cp, const span<B>& dest)
noexcept
{
	valid_sequence_length len = required_sequence_length(cp.value());
	if(len.is_valid())
	{
		do_encode_code_point(cp, dest, len.value());
	}
	return len;
}

static inline
valid_if_not_empty<std::string> encode_code_point(code_point cp)
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

static inline
optionally_valid<std::size_t>
encoding_bytes_required(const span<const code_point_t>& cps)
noexcept
{
	std::size_t result = 0;
	for(code_point_t cp : cps)
	{
		if(auto len = required_sequence_length(cp))
		{
			result += len.value();
		}
		else return {0, false};
	}
	return {result, true};
}

static inline
optionally_valid<std::size_t>
encoding_bytes_required(const span<const code_point>& cps)
noexcept
{
	std::size_t result = 0;
	for(code_point cp : cps)
	{
		if(cp.is_valid())
		{
			if(auto len = required_sequence_length(cp.value()))
			{
				result += len.value();
			}
			else return {0, false};
		}
		else return {0, false};
	}
	return {result, true};
}

template <typename B>
static inline
optionally_valid<std::size_t>
decoding_code_points_required(const span<B>& bytes)
noexcept
{
	std::size_t result = 0;

	auto i = bytes.begin();
	auto e = bytes.end();

	while(i != e)
	{
		if(auto len = do_decode_sequence_length(byte(*i)))
		{
			++result;
			i += span_size_type(len.value());
		}
		else return {0, false};
		assert(!(i > e));
	}

	return {result, true};
}

template <typename B>
static inline
bool encode_code_points(
	const span<const code_point>& cps,
	const span<B>& bytes
) noexcept
{
	span_size_type i = 0;

	for(code_point cp : cps)
	{
		if(!cp.is_valid()) return false;

		assert(i < bytes.size());
		span<B> sub(bytes.data()+i, bytes.size()-i);
		auto len = encode_code_point(cp.value(), sub);

		if(!len.is_valid()) return false;

		i += span_size_type(len.value());
	}
	return true;
}

template <typename B>
static inline
bool decode_code_points(
	const span<B>& bytes,
	const span<code_point>& cps
)
{
	span_size_type i = 0;

	for(code_point& cp : cps)
	{
		assert(i < bytes.size());
		span<B> sub(bytes.data()+i, bytes.size()-i);
		if(auto len = decode_sequence_length(sub))
		{
			cp = do_decode_code_point(sub, len.value());

			i += span_size_type(len.value());
		}
		else return false;
	}
	return true;
}

} // namespace mbs
} // namespace eagine

#endif // include guard
