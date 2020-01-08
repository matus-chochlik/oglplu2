/**
 *  @file eagine/identifier.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_IDENTIFIER_HPP
#define EAGINE_IDENTIFIER_HPP

#include "biteset.hpp"
#include "fixed_size_str.hpp"
#include "identifier_t.hpp"
#include "mp_string.hpp"
#include "selector.hpp"
#include <iosfwd>

namespace eagine {
//------------------------------------------------------------------------------
template <typename CharSet>
class identifier_encoding;
//------------------------------------------------------------------------------
template <char... C>
class identifier_encoding<mp_string<C...>> {
public:
    static constexpr inline std::uint8_t encode(char c) noexcept {
        return _do_encode(c, 0, mp_string<C...>{});
    }

    static constexpr inline char decode(std::uint8_t i) noexcept {
        return _do_decode(i, mp_string<C...>{});
    }

    static constexpr inline bool invalid(std::uint8_t c) noexcept {
        return (c >= std::uint8_t(sizeof...(C)));
    }

    static inline auto chars() {
        static const char s[] = {C..., '\0'};
        return string_view(s, span_size(sizeof...(C)));
    }

private:
    static constexpr inline std::uint8_t _do_encode(
      char, std::uint8_t, mp_string<>) noexcept {
        return std::uint8_t(sizeof...(C));
    }

    template <char H, char... T>
    static constexpr inline std::uint8_t _do_encode(
      char c, std::uint8_t i, mp_string<H, T...>) noexcept {
        return (c == H) ? i : _do_encode(c, i + 1, mp_string<T...>{});
    }

    static constexpr inline char _do_decode(
      std::uint8_t, mp_string<>) noexcept {
        return '\0';
    }

    template <char H, char... T>
    static constexpr inline char _do_decode(
      std::uint8_t i, mp_string<H, T...>) noexcept {
        return (i == (sizeof...(C) - sizeof...(T) - 1))
                 ? H
                 : _do_decode(i, mp_string<T...>{});
    }
};
//------------------------------------------------------------------------------
using default_identifier_char_set = mp_string<
  'a',
  'b',
  'c',
  'd',
  'e',
  'f',
  'g',
  'h',
  'i',
  'j',
  'k',
  'l',
  'm',
  'n',
  'o',
  'p',
  'q',
  'r',
  's',
  't',
  'u',
  'v',
  'w',
  'x',
  'y',
  'z',
  'A',
  'B',
  'C',
  'D',
  'E',
  'F',
  'G',
  'H',
  'I',
  'J',
  'K',
  'L',
  'M',
  'N',
  'O',
  'P',
  'Q',
  'R',
  'S',
  'T',
  'U',
  'V',
  'W',
  'X',
  'Y',
  'Z',
  '0',
  '1',
  '2',
  '3',
  '4',
  '5',
  '6',
  '7',
  '8',
  '9',
  '_'>;
//------------------------------------------------------------------------------
using hex_identifier_char_set = mp_string<
  '0',
  '1',
  '2',
  '3',
  '4',
  '5',
  '6',
  '7',
  '8',
  '9',
  'a',
  'b',
  'c',
  'd',
  'e',
  'f'>;
//------------------------------------------------------------------------------
template <std::size_t M>
class identifier_name {
public:
    template <typename... C>
    identifier_name(span_size_t len, C... c) noexcept
      : _str{c...}
      , _len{std::uint8_t(len)} {
    }

    using size_type = span_size_t;
    using value_type = char;
    using iterator = const char*;
    using const_iterator = iterator;

    const char* data() const noexcept {
        return _str.data();
    }

    size_type size() const noexcept {
        return size_type(_len);
    }

    const_iterator begin() const {
        return _str.data();
    }

    const_iterator end() const {
        return _str.data() + size();
    }

    std::string str() const {
        return {_str.data(), _len};
    }

private:
    fixed_size_string<M> _str;
    std::uint8_t _len;
};
//------------------------------------------------------------------------------
template <std::size_t M>
static inline std::ostream& operator<<(
  std::ostream& out, const identifier_name<M>& n) {
    return out.write(n.data(), std::streamsize(n.size()));
}
//------------------------------------------------------------------------------
template <std::size_t M, std::size_t B, typename CharSet, typename UIntT>
class basic_identifier {
    using _bites_t = biteset<M, B, std::uint8_t>;

public:
    static_assert(
      // NOLINTNEXTLINE(hicpp-signed-bitwise)
      (1 << B) >= mp_strlen<CharSet>::value,
      "B-bits are not sufficient to represent CharSet");

    using encoding = identifier_encoding<CharSet>;
    using size_type = span_size_t;
    using value_type = char;
    using name_type = identifier_name<M>;

    basic_identifier() = default;

    template <std::size_t L, typename = std::enable_if_t<(L <= M + 1)>>
    constexpr inline basic_identifier(const char (&init)[L]) noexcept
      : _bites{_make_bites(
          static_cast<const char*>(init), L, std::make_index_sequence<M>{})} {
    }

    explicit constexpr inline basic_identifier(span<const char> init) noexcept
      : _bites{_make_bites(
          init.data(), init.size(), std::make_index_sequence<M>{})} {
    }

    explicit constexpr inline basic_identifier(UIntT init) noexcept
      : _bites{_bites_t::from_value(init)} {
    }

    static constexpr inline size_type max_size() noexcept {
        return size_type(M);
    }

    constexpr inline size_type size() const noexcept {
        return size_type(_get_size(0));
    }

    constexpr inline value_type operator[](size_type idx) const noexcept {
        return value_type(encoding::decode(_bites[idx]));
    }

    constexpr inline UIntT value() const noexcept {
        return _bites.bytes().template as<UIntT>();
    }

    constexpr inline bool matches(UIntT what) const noexcept {
        return value() == what;
    }

    constexpr inline name_type name() const noexcept {
        return _get_name(std::make_index_sequence<M>{});
    }

    inline std::string str() const {
        return name().str();
    }

    friend constexpr inline bool operator==(
      const basic_identifier& a, const basic_identifier& b) noexcept {
        return a._bites == b._bites;
    }

    friend constexpr inline bool operator!=(
      const basic_identifier& a, const basic_identifier& b) noexcept {
        return a._bites != b._bites;
    }

    friend constexpr inline bool operator<(
      const basic_identifier& a, const basic_identifier& b) noexcept {
        return a._bites < b._bites;
    }

    friend constexpr inline bool operator<=(
      const basic_identifier& a, const basic_identifier& b) noexcept {
        return a._bites <= b._bites;
    }

    friend constexpr inline bool operator>(
      const basic_identifier& a, const basic_identifier& b) noexcept {
        return a._bites > b._bites;
    }

    friend constexpr inline bool operator>=(
      const basic_identifier& a, const basic_identifier& b) noexcept {
        return a._bites >= b._bites;
    }

private:
    _bites_t _bites;

    template <std::size_t... I>
    static constexpr inline auto _make_bites(
      const char* init, std::size_t l, std::index_sequence<I...>) noexcept {
        return biteset<M, B, std::uint8_t>{
          encoding::encode((I < l) ? init[(I < l) ? I : 0] : '\0')...};
    }

    template <std::size_t... I>
    constexpr inline name_type _get_name(std::index_sequence<I...>) const
      noexcept {
        return name_type{size(), (*this)[size_type(I)]...};
    }

    constexpr inline std::size_t _get_size(std::size_t s) const noexcept {
        return (s < M) ? !encoding::invalid(_bites[size_type(s)])
                           ? _get_size(s + 1)
                           : s
                       : M;
    }
};
//------------------------------------------------------------------------------
using identifier =
  basic_identifier<10, 6, default_identifier_char_set, identifier_t>;
//------------------------------------------------------------------------------
#define EAGINE_ID(NAME) ::eagine::identifier(#NAME)
#define EAGINE_ID_V(NAME) ::eagine::identifier(#NAME).value()
#define EAGINE_TAG_TYPE(NAME) ::eagine::selector<EAGINE_ID_V(NAME)>
#define EAGINE_TAG(NAME)    \
    EAGINE_TAG_TYPE(NAME) { \
    }
//------------------------------------------------------------------------------
#if EAGINE_HAS_LONG_ID
using long_identifier =
  basic_identifier<20, 6, default_identifier_char_set, long_identifier_t>;
//------------------------------------------------------------------------------
#define EAGINE_LONG_ID(NAME) ::eagine::long_identifier(#NAME)
#define EAGINE_LONG_ID_V(NAME) ::eagine::long_identifier(#NAME).value()
#endif
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_IDENTIFIER_HPP
