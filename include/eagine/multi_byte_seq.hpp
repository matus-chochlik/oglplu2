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

#include "valid_if/less_than.hpp"
#include "valid_if/not_zero.hpp"
#include "valid_if/between.hpp"
#include "valid_if/always.hpp"
#include "valid_if/not_empty.hpp"
#include "valid_if/le_size_ge0.hpp"
#include "valid_if/size_gt.hpp"
#include "types.hpp"
#include "span.hpp"
#include "string_span.hpp"
#include <cstdint>
#include <string>

namespace eagine {
namespace mbs {

using code_point_t = std::uint32_t;
using code_point = valid_if_less_than<code_point_t, 0x7FFFFFFF>;

using valid_sequence_length = valid_if_between<span_size_t, 1, 6>;

using valid_byte_span = valid_if_size_gt<span<byte>, span_size_t>;

static inline
valid_byte_span make_byte_span(span<byte> s)
noexcept { return {s}; }

static inline
valid_byte_span make_byte_span(span<char> s)
noexcept {
	return {span<byte>{
		reinterpret_cast<byte*>(s.data()),
		s.size()
	}};
}

using valid_cbyte_span = valid_if_size_gt<span<const byte>, span_size_t>;

static inline
valid_cbyte_span make_cbyte_span(span<const byte> s)
noexcept { return {s}; }

static inline
valid_cbyte_span make_cbyte_span(span<const char> s)
noexcept {
	return {span<const byte>{
		reinterpret_cast<const byte*>(s.data()),
		s.size()
	}};
}


static constexpr inline
valid_if_not_zero<code_point_t>
max_code_point(const valid_sequence_length len)
noexcept {
	return	len==1?	0x0000007F: //  7b
		len==2? 0x000007FF: // 11b
		len==3? 0x0000FFFF: // 16b
		len==4? 0x001FFFFF: // 21b
		len==5? 0x03FFFFFF: // 26b
		len==6? 0x7FFFFFFF: // 31b
			0x00000000;
}

static constexpr inline
valid_span_size_t
head_data_bitshift(const valid_sequence_length len)
noexcept {
	return {
		len.is_valid()?
		(len.value_anyway()-1)*6:-1
	};
}

static constexpr inline
valid_span_size_t
tail_data_bitshift(
	const valid_sequence_length idx,
	const valid_sequence_length len
) noexcept {
	return {
		(idx.is_valid() && len.is_valid())?
		(len.value_anyway()-idx.value_anyway()-1)*6:-1
	};
}

static constexpr inline
valid_if_not_zero<byte>
head_code_mask(const valid_sequence_length len)
noexcept {
	return	len==1?	0x80:
		len==2?	0xE0:
		len==3?	0xF0:
		len==4?	0xF8:
		len==5?	0xFC:
		len==6?	0xFE:
			0x00;
}

template <typename P>
static constexpr inline
optionally_valid<byte> inverted_byte(const valid_if<byte, P> b)
noexcept {
	return {byte(~b.value_anyway()), b.is_valid()};
}

static constexpr inline
optionally_valid<byte>
head_data_mask(const valid_sequence_length len)
noexcept {
	return inverted_byte(head_code_mask(len));
}

static constexpr inline
always_valid<byte> tail_code_mask(void)
noexcept {
	return 0xC0;
}

static constexpr inline
always_valid<byte> tail_data_mask(void)
noexcept {
	return 0x3F;
}

template <typename P>
static constexpr inline
optionally_valid<byte> head_code_from_mask(const valid_if<byte, P> mask)
noexcept {
	return {
		byte((mask.value_anyway() << 1) & 0xFF),
		mask.is_valid()
	};
}

static constexpr inline
optionally_valid<byte> head_code(const valid_sequence_length len)
noexcept {
	return head_code_from_mask(head_code_mask(len));
}

static constexpr inline
always_valid<byte> tail_code(void)
noexcept {
	return 0x80;
}

template <typename P1, typename P2>
static constexpr inline
bool is_valid_masked_code(
	const byte b,
	const valid_if<byte, P1> mask,
	const valid_if<byte, P2> code
) noexcept {
	return (mask.is_valid() && code.is_valid())?
		(b & mask.value_anyway()) == code.value_anyway():
		false;
}

static constexpr inline
bool is_valid_head_byte(const byte b, const valid_sequence_length l)
noexcept {
	return is_valid_masked_code(
		b, head_code_mask(l),
		head_code(l)
	);
}

static inline
bool is_valid_head_byte(const byte b)
noexcept {
	for(span_size_t l=1; l<6; ++l) {
		if(is_valid_head_byte(b, l)) {
			return true;
		}
	}
	return false;
}

static constexpr inline
bool is_valid_tail_byte(
	const byte b,
	const valid_sequence_length,
	const valid_sequence_length
) noexcept {
	return is_valid_masked_code(
		b, tail_code_mask(),
		tail_code()
	);
}

static constexpr inline
valid_sequence_length
required_sequence_length(const code_point_t cp)
noexcept {
	return	(max_code_point(1) > cp)?1:
		(max_code_point(2) > cp)?2:
		(max_code_point(3) > cp)?3:
		(max_code_point(4) > cp)?4:
		(max_code_point(5) > cp)?5:
		(max_code_point(6) > cp)?6:0;
}

static inline
valid_sequence_length
do_decode_sequence_length(const byte b)
noexcept {
	for(span_size_t l=1; l<=6; ++l) {
		if(is_valid_head_byte(b, l)) {
			return l;
		}
	}
	return 0;
}

static inline
valid_sequence_length
decode_sequence_length(const valid_cbyte_span& seq)
noexcept {
	return do_decode_sequence_length(byte(seq.value(0)[0]));
}

static inline
bool is_valid_encoding(const valid_cbyte_span& vseq)
noexcept {
	if(auto len = decode_sequence_length(vseq)) {
		const span_size_t l = len.value();
		const span<const byte>& seq = vseq.value(l-1);

		if(!is_valid_head_byte(seq[0], l)) {
			return false;
		}

		for(span_size_t i=1; i<l; ++i) {
			if(!is_valid_tail_byte(seq[i], i, l)) {
				return false;
			}
		}
		return true;	
	}
	return false;
}

template <typename P1, typename P2>
static constexpr inline
optionally_valid<code_point_t>
do_decode_code_point_head(
	const byte b,
	const valid_if<byte, P1> mask,
	const valid_if<span_size_t, P2> bitshift
) noexcept {
	return {
		code_point_t(
			(b & mask.value_anyway()) << bitshift.value_anyway()
		), (mask.is_valid() && bitshift.is_valid())
	};
}

static constexpr inline
optionally_valid<code_point_t>
decode_code_point_head(
	const byte b,
	const valid_sequence_length l
) noexcept {
	return do_decode_code_point_head(
		b, head_data_mask(l),
		head_data_bitshift(l)
	);
}

template <typename P1, typename P2>
static constexpr inline
optionally_valid<code_point_t>
do_decode_code_point_tail(
	const byte b,
	const valid_if<byte, P1> mask,
	const valid_if<span_size_t, P2> bitshift
) noexcept {
	return {
		code_point_t(
			(b & mask.value_anyway()) << bitshift.value_anyway()
		), (mask.is_valid() && bitshift.is_valid())
	};
}

static constexpr inline
optionally_valid<code_point_t>
decode_code_point_tail(
	const byte b,
	const valid_sequence_length i,
	const valid_sequence_length l
) noexcept {
	return do_decode_code_point_tail(
		b, tail_data_mask(),
		tail_data_bitshift(i, l)
	);
}

static inline
code_point_t do_decode_code_point(
	const valid_cbyte_span& vsrc,
	const valid_sequence_length vl
) noexcept {
	const span_size_t l = vl.value();
	const span<const byte>& src = vsrc.value(l-1);

	code_point_t cp = decode_code_point_head(src[0], vl).value();

	for(span_size_t i=1; i<l; ++i) {
		cp |= decode_code_point_tail(src[i], i, vl).value();
	}

	return cp;
}

static inline
code_point decode_code_point(const valid_cbyte_span& src)
noexcept {
	return do_decode_code_point(src, decode_sequence_length(src));
}

template <typename P1, typename P2, typename P3>
static constexpr inline
optionally_valid<byte>
do_encode_code_point_byte(
	const code_point_t cp,
	const valid_if<byte, P1> code,
	const valid_if<byte, P2> mask,
	const valid_if<span_size_t, P3> bitshift
) noexcept {
	return {
		byte(
			(code.value_anyway())|
			(mask.value_anyway()&(cp >> bitshift.value_anyway()))
		), (code.is_valid() && mask.is_valid() && bitshift.is_valid())
	};
}


static constexpr inline
optionally_valid<byte>
encode_code_point_head(
	const code_point_t cp,
	const valid_sequence_length l
) noexcept {
	return do_encode_code_point_byte(
		cp, head_code(l),
		head_data_mask(l),
		head_data_bitshift(l)
	);
}

static constexpr inline
optionally_valid<byte>
encode_code_point_tail(
	const code_point_t cp,
	const valid_sequence_length i,
	const valid_sequence_length l
) noexcept {
	return do_encode_code_point_byte(
		cp, tail_code(),
		tail_data_mask(),
		tail_data_bitshift(i, l)
	);
}

static inline
void do_encode_code_point(
	const code_point cp,
	const valid_byte_span& vdest,
	const valid_sequence_length vl
) noexcept {
	const span_size_t l = vl.value();
	const span<byte>& dest = vdest.value(l-1);

	code_point_t val = cp.value();

	dest[0] = encode_code_point_head(val, vl).value();

	for(span_size_t i=1; i<l; ++i) {
		dest[i] = encode_code_point_tail(val, i, vl).value();
	}
}

static inline
valid_sequence_length
encode_code_point(const code_point cp, const valid_byte_span& dest)
noexcept {
	auto len = required_sequence_length(cp.value());
	do_encode_code_point(cp, dest, len);
	return len;
}

static inline
valid_if_not_empty<std::string> encode_code_point(code_point cp)
{
	if(auto len = required_sequence_length(cp.value())) {
		std::array<byte, 7> tmp;
		do_encode_code_point(
			cp,
			make_byte_span(make_span(tmp)),
			len.value()
		);
		return {std::string(
			reinterpret_cast<const char*>(tmp.data()),
			std_size(tmp.size())
		)};
	}
	return {};
}

static inline
optionally_valid<span_size_t>
encoding_bytes_required(const span<const code_point_t>& cps)
noexcept
{
	span_size_t result = 0;
	for(code_point_t cp : cps) {
		if(auto len = required_sequence_length(cp)) {
			result += len.value();
		}
		else return {0, false};
	}
	return {result, true};
}

static inline
optionally_valid<span_size_t>
encoding_bytes_required(const span<const code_point>& cps)
noexcept
{
	span_size_t result = 0;
	for(code_point cp : cps) {
		if(cp.is_valid()) {
			if(auto len = required_sequence_length(cp.value())) {
				result += len.value();
			}
			else return {0, false};
		}
		else return {0, false};
	}
	return {result, true};
}

static inline
optionally_valid<span_size_t>
decoding_code_points_required(const valid_cbyte_span& bytes)
noexcept
{
	span_size_t result = 0;

	auto i = bytes.value(0).begin();
	auto e = bytes.value(0).end();

	while(i != e) {
		if(auto len = do_decode_sequence_length(*i)) {
			++result;
			i += span_size(len.value());
			assert(!(i > e));
		}
		else return {0, false};
	}

	return {result, true};
}

static inline
bool encode_code_points(
	const span<const code_point>& cps,
	const valid_byte_span& bytes
) noexcept
{
	span_size_t i = 0;

	for(code_point cp : cps) {
		if(!cp.is_valid()) {
			return false;
		}

		span<byte> sub{
			bytes.value(i).data()+i,
			bytes.value(i).size()-i
		};
		auto len = encode_code_point(cp.value(), sub);

		if(!len.is_valid()) {
			return false;
		}

		i += span_size_t(len.value());
	}
	return true;
}

static inline
bool decode_code_points(
	const valid_cbyte_span& bytes,
	const span<code_point>& cps
)
{
	span_size_t i = 0;

	for(code_point& cp : cps) {
		span<const byte> sub{
			bytes.value(i).data()+i,
			bytes.value(i).size()-i
		};
		if(auto len = decode_sequence_length(sub)) {
			cp = do_decode_code_point(sub, len.value());

			i += span_size_t(len.value());
		}
		else return false;
	}
	return true;
}

} // namespace mbs
} // namespace eagine

#endif // include guard
