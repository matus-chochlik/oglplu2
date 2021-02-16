/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_BITESET_HPP
#define EAGINE_BITESET_HPP

#include "assert.hpp"
#include "byteset.hpp"
#include "int_constant.hpp"
#include <climits>
#include <cstdint>
#include <iterator>
#include <type_traits>
#include <utility>

namespace eagine {

template <typename std::size_t B>
using biteset_cell_type = std::conditional_t<
  (B <= 8),
  std::uint_least8_t,
  std::conditional_t<
    (B <= 16),
    std::uint_least16_t,
    std::conditional_t<
      (B <= 32),
      std::uint_least32_t,
      std::conditional_t<(B <= 64), std::uint_least64_t, void>>>>;

template <std::size_t N, std::size_t B, typename T = biteset_cell_type<B>>
class biteset;

template <typename BiS>
class biteset_value_proxy;

template <typename BiS>
class biteset_value_proxy_base {
public:
    using size_type = typename BiS::size_type;
    using value_type = typename BiS::value_type;
    using self = biteset_value_proxy_base;
    using derived = biteset_value_proxy<BiS>;

    constexpr biteset_value_proxy_base(BiS& bs, size_type pos) noexcept
      : _ptr{&bs}
      , _pos{pos} {}

    constexpr auto is_valid() const noexcept -> bool {
        return (_ptr != nullptr) && (_pos < _ptr->size());
    }

    constexpr auto get() const noexcept -> value_type {
        return EAGINE_CONSTEXPR_ASSERT(is_valid(), _ptr->get(_pos));
    }

    void set(value_type val) noexcept {
        EAGINE_CONSTEXPR_ASSERT(is_valid(), _ptr->set(_pos, val));
    }

    void swap(self& other) noexcept {
        using std::swap;
        EAGINE_ASSERT(_ptr != nullptr);
        EAGINE_ASSERT(_ptr == other._ptr);
        value_type a = this->get();
        value_type b = other.get();
        swap(a, b);
        this->set(a);
        other.set(b);
    }

    constexpr operator value_type() const noexcept {
        return get();
    }

    friend constexpr auto operator==(const self& a, const self& b) noexcept {
        return a.get() == b.get();
    }

    friend constexpr auto operator!=(const self& a, const self& b) noexcept {
        return a.get() != b.get();
    }

    friend constexpr auto operator<(const self& a, const self& b) noexcept {
        return a.get() < b.get();
    }

    friend constexpr auto operator<=(const self& a, const self& b) noexcept {
        return a.get() <= b.get();
    }

    friend constexpr auto operator>(const self& a, const self& b) noexcept {
        return a.get() > b.get();
    }

    friend constexpr auto operator>=(const self& a, const self& b) noexcept {
        return a.get() >= b.get();
    }

protected:
    BiS* _ptr{nullptr};
    size_type _pos{0};
};

template <std::size_t N, std::size_t B, typename T>
class biteset_value_proxy<const biteset<N, B, T>>
  : public biteset_value_proxy_base<const biteset<N, B, T>> {
    using _base = biteset_value_proxy_base<const biteset<N, B, T>>;

public:
    using size_type = typename _base::size_type;
    using self = biteset_value_proxy;

    constexpr biteset_value_proxy(
      const biteset<N, B, T>& bs,
      size_type pos) noexcept
      : _base{bs, pos} {}
};

template <std::size_t N, std::size_t B, typename T>
class biteset_value_proxy<biteset<N, B, T>>
  : public biteset_value_proxy_base<biteset<N, B, T>> {
    using _base = biteset_value_proxy_base<biteset<N, B, T>>;
    using _base::_pos;
    using _base::_ptr;

public:
    using size_type = typename _base::size_type;
    using value_type = typename _base::value_type;
    using self = biteset_value_proxy;

    constexpr biteset_value_proxy(biteset<N, B, T>& bs, size_type pos) noexcept
      : _base{bs, pos} {}

    constexpr biteset_value_proxy(biteset_value_proxy&& temp) noexcept(
      std::is_nothrow_move_constructible_v<_base>) = default;
    constexpr biteset_value_proxy(const biteset_value_proxy&) noexcept(
      std::is_nothrow_copy_constructible_v<_base>) = delete;

    auto operator=(biteset_value_proxy&& temp) noexcept
      -> biteset_value_proxy& {
        this->set(temp.get());
        return *this;
    }
    auto operator=(const biteset_value_proxy&) noexcept(
      std::is_nothrow_copy_assignable_v<_base>) = delete;

    ~biteset_value_proxy() noexcept = default;

    auto operator=(const T& v) noexcept -> self& {
        this->set(v);
        return *this;
    }
};

template <typename BiS>
static inline void
swap(biteset_value_proxy<BiS>&& a, biteset_value_proxy<BiS>&& b) noexcept {
    return a.swap(b);
}

template <typename BiS>
class biteset_iterator;

template <typename BiS>
class biteset_iterator_base {
public:
    using self = biteset_iterator_base;
    using derived = biteset_iterator<BiS>;
    using size_type = typename BiS::size_type;
    using difference_type = typename BiS::difference_type;

    void swap(self& other) noexcept {
        using std::swap;
        EAGINE_ASSERT(_ptr == other._ptr);
        swap(_pos, other._pos);
    }

    auto operator++() noexcept -> auto& {
        ++_pos;
        return *static_cast<derived*>(this);
    }

    auto operator++(int) noexcept -> const derived {
        derived that = *static_cast<derived*>(this);
        ++_pos;
        return that;
    }

    auto operator--() noexcept -> auto& {
        --_pos;
        return *static_cast<derived*>(this);
    }

    auto operator--(int) noexcept -> const derived {
        derived that = *static_cast<derived*>(this);
        --_pos;
        return that;
    }

    auto operator+=(size_type n) noexcept -> auto& {
        _pos += n;
        return *static_cast<derived*>(this);
    }

    auto operator-=(size_type n) noexcept -> auto& {
        _pos -= n;
        return *static_cast<derived*>(this);
    }

    friend auto operator+(const self& a, difference_type n) noexcept {
        return derived(*a._ptr, a._pos + n);
    }

    friend auto operator+(difference_type n, const self& a) noexcept {
        return derived(*a._ptr, n + a._pos);
    }

    friend auto operator-(const self& a, difference_type n) noexcept {
        return derived(*a._ptr, a._pos - n);
    }

    friend auto operator-(const self& a, const self& b) noexcept
      -> difference_type {
        return a._pos - b._pos;
    }

    friend constexpr auto operator==(const self& a, const self& b) noexcept {
        return _cmp(a, b) == 0;
    }

    friend constexpr auto operator!=(const self& a, const self& b) noexcept {
        return _cmp(a, b) != 0;
    }

    friend constexpr auto operator<(const self& a, const self& b) noexcept {
        return _cmp(a, b) < 0;
    }

    friend constexpr auto operator<=(const self& a, const self& b) noexcept {
        return _cmp(a, b) <= 0;
    }

    friend constexpr auto operator>(const self& a, const self& b) noexcept {
        return _cmp(a, b) > 0;
    }

    friend constexpr auto operator>=(const self& a, const self& b) noexcept {
        return _cmp(a, b) >= 0;
    }

protected:
    constexpr biteset_iterator_base(BiS& bs, size_type pos) noexcept
      : _ptr{&bs}
      , _pos{pos} {}

    constexpr biteset_iterator_base() noexcept = default;

    constexpr auto is_valid() const noexcept {
        return (_ptr != nullptr) && (_pos < _ptr->size());
    }

    static constexpr auto _cmp(const self& a, const self& b) noexcept
      -> difference_type {
        return EAGINE_CONSTEXPR_ASSERT(
          (a._ptr != nullptr) && (a._ptr == b._ptr), a._pos - b._pos);
    }

    BiS* _ptr{nullptr};
    size_type _pos{0};
};

template <typename BiS>
static inline void
swap(biteset_iterator_base<BiS>& a, biteset_iterator_base<BiS>& b) noexcept {
    return a.swap(b);
}

template <std::size_t N, std::size_t B, typename T>
class biteset_iterator<const biteset<N, B, T>>
  : public biteset_iterator_base<const biteset<N, B, T>> {
    using _base = biteset_iterator_base<const biteset<N, B, T>>;
    using _base::_pos;
    using _base::_ptr;
    using _base::is_valid;

public:
    using size_type = typename biteset<N, B, T>::size_type;
    using difference_type = typename biteset<N, B, T>::difference_type;
    using value_type = typename biteset<N, B, T>::value_type;
    using const_proxy = biteset_value_proxy<const biteset<N, B, T>>;
    using reference = const_proxy;
    using const_reference = const_proxy;
    using pointer = const_proxy;
    using const_pointer = const_proxy;
    using iterator_category = std::random_access_iterator_tag;
    using self = biteset_iterator;

    constexpr biteset_iterator(
      const biteset<N, B, T>& bs,
      size_type pos) noexcept
      : _base{bs, pos} {}

    constexpr biteset_iterator() = default;

    constexpr auto operator*() const noexcept -> const_proxy {
        return EAGINE_CONSTEXPR_ASSERT(is_valid(), const_proxy(*_ptr, _pos));
    }
};

template <std::size_t N, std::size_t B, typename T>
class biteset_iterator<biteset<N, B, T>>
  : public biteset_iterator_base<biteset<N, B, T>> {
    using _base = biteset_iterator_base<biteset<N, B, T>>;
    using _base::_cmp;
    using _base::_pos;
    using _base::_ptr;
    using _base::is_valid;

public:
    using size_type = typename biteset<N, B, T>::size_type;
    using difference_type = typename biteset<N, B, T>::difference_type;
    using value_type = typename biteset<N, B, T>::value_type;
    using proxy = biteset_value_proxy<biteset<N, B, T>>;
    using const_proxy = biteset_value_proxy<const biteset<N, B, T>>;
    using reference = proxy;
    using const_reference = const_proxy;
    using pointer = proxy;
    using const_pointer = const_proxy;
    using iterator_category = std::random_access_iterator_tag;
    using self = biteset_iterator;

    constexpr biteset_iterator(biteset<N, B, T>& bs, size_type pos) noexcept
      : _base{bs, pos} {}

    constexpr biteset_iterator() noexcept = default;

    constexpr auto operator*() noexcept -> proxy {
        return EAGINE_CONSTEXPR_ASSERT(is_valid(), proxy(*_ptr, _pos));
    }

    constexpr auto operator*() const noexcept -> const_proxy {
        return EAGINE_CONSTEXPR_ASSERT(is_valid(), const_proxy(*_ptr, _pos));
    }

    constexpr auto operator->() noexcept -> proxy {
        return EAGINE_CONSTEXPR_ASSERT(is_valid(), proxy(*_ptr, _pos));
    }

    auto operator->() const noexcept -> const_proxy {
        return EAGINE_CONSTEXPR_ASSERT(is_valid(), const_proxy(*_ptr, _pos));
    }
};

template <std::size_t N, std::size_t B, typename T>
class biteset {
private:
    static constexpr const std::size_t _store_size =
      ((N * B) / CHAR_BIT) + (((N * B) % CHAR_BIT != 0) ? 1 : 0);

    using _bytes_t = byteset<_store_size>;
    using _byte_t = typename _bytes_t::value_type;

    // the number of useful bits in T
    static constexpr const std::size_t _bite_s = B;
    // the number of bits in a byte
    static constexpr const std::size_t _byte_s = CHAR_BIT;
    // the number of all bits in T
    static constexpr const std::size_t _cell_s = sizeof(T) * CHAR_BIT;

public:
    static_assert((B > 0), "bite size must be greater than zero");
    static_assert((N > 0), "bite count must be greater than zero");
    static_assert(
      (_cell_s >= _bite_s),
      "bite with B bits size does not fit into type T");
    static_assert(std::is_integral_v<T>, "T must be integral type");

    using size_type = span_size_t;
    using difference_type = span_size_t;
    using value_type = T;
    using iterator = biteset_iterator<biteset>;
    using const_iterator = biteset_iterator<const biteset>;

    constexpr biteset() noexcept = default;

    template <
      typename... P,
      typename = std::enable_if_t<
        (sizeof...(P) == N) &&
        std::conjunction_v<std::true_type, std::is_convertible<P, T>...>>>
    explicit constexpr biteset(P... p) noexcept
      : _bytes{_make_bytes(T(p)...)} {}

    explicit constexpr biteset(_bytes_t init) noexcept
      : _bytes{init} {}

    template <typename UIntT>
    static constexpr auto from_value(UIntT init) noexcept {
        return biteset{_bytes_t{init}};
    }

    constexpr auto size() const noexcept -> size_type {
        return N;
    }

    constexpr auto get(size_type i) const noexcept {
        return _get_cell(std::size_t(i));
    }

    void set(size_type i, T value) noexcept {
        _set_cell(std::size_t(i), value);
    }

    auto begin() const noexcept -> const_iterator {
        return {*this, 0};
    }

    auto end() const noexcept -> const_iterator {
        return {*this, N};
    }

    auto begin() noexcept -> iterator {
        return {*this, 0};
    }

    auto end() noexcept -> iterator {
        return {*this, N};
    }

    constexpr auto operator[](size_type i) const noexcept
      -> biteset_value_proxy<const biteset> {
        return {*this, i};
    }

    constexpr auto operator[](size_type i) noexcept
      -> biteset_value_proxy<biteset> {
        return {*this, i};
    }

    friend constexpr auto
    operator==(const biteset& a, const biteset& b) noexcept {
        return a.bytes() == b.bytes();
    }

    friend constexpr auto
    operator!=(const biteset& a, const biteset& b) noexcept {
        return a.bytes() != b.bytes();
    }

    friend constexpr auto
    operator<(const biteset& a, const biteset& b) noexcept {
        return a.bytes() < b.bytes();
    }

    friend constexpr auto
    operator<=(const biteset& a, const biteset& b) noexcept {
        return a.bytes() <= b.bytes();
    }

    friend constexpr auto
    operator>(const biteset& a, const biteset& b) noexcept {
        return a.bytes() > b.bytes();
    }

    friend constexpr auto
    operator>=(const biteset& a, const biteset& b) noexcept {
        return a.bytes() >= b.bytes();
    }

    constexpr auto bytes() const noexcept -> const auto& {
        return _bytes;
    }

private:
    _bytes_t _bytes{};

    static constexpr auto _min_s(std::size_t x, std::size_t y) noexcept
      -> std::size_t {
        return (x < y) ? x : y;
    }

    static constexpr auto
    _extract_init_bits(T init, std::size_t ofs, std::size_t len) noexcept
      -> _byte_t {
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        return _byte_t(init >> (_bite_s - ofs - len)) & _byte_t((1 << len) - 1);
    }

    template <std::size_t L>
    static constexpr auto _do_get_byte_bits(
      const T (&init)[N],
      _byte_t state,
      std::size_t bo,
      std::size_t bl,
      std::size_t bb,
      std::size_t be,
      std::size_t cb,
      std::size_t ce,
      size_constant<L>) noexcept {
        return _get_byte_bits(
          init,
          _byte_t(state << bl) |
            _extract_init_bits(cb < N ? init[cb] : T(0), bo, bl),
          bb + bl,
          be,
          cb + 1,
          ce,
          size_constant<L + 1>{});
    }

    static constexpr auto _get_byte_bits(
      const T (&)[N],
      _byte_t state,
      std::size_t,
      std::size_t,
      std::size_t,
      std::size_t,
      size_constant<_byte_s>) noexcept {
        return state;
    }

    template <std::size_t L>
    static constexpr auto _get_byte_bits(
      const T (&init)[N],
      _byte_t state,
      std::size_t bb,
      std::size_t be,
      std::size_t cb,
      std::size_t ce,
      size_constant<L> l) noexcept {
        return (bb >= be)
                 ? state
                 : _do_get_byte_bits(
                     init,
                     state,
                     (bb - cb * _bite_s),
                     _min_s((be - bb), (_bite_s - (bb - cb * _bite_s))),
                     bb,
                     be,
                     cb,
                     ce,
                     l);
    }

    static constexpr auto
    _get_byte_bits(const T (&init)[N], std::size_t bb, std::size_t be) noexcept {
        return _get_byte_bits(
          init,
          _byte_t(0),
          bb,
          be,
          bb / _bite_s,
          be / _bite_s,
          size_constant<1>{});
    }

    static constexpr auto _get_byte(const T (&init)[N], std::size_t i) noexcept {
        return (B == _byte_s)
                 ? _byte_t(init[i])
                 : _get_byte_bits(init, (i + 0) * _byte_s, (i + 1) * _byte_s);
    }

    static constexpr auto
    _extract_cell_bits(_byte_t by, std::size_t ofs, std::size_t len) noexcept
      -> T {
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        return T(by >> (_byte_s - ofs - len)) & T((1 << len) - 1);
    }

    template <std::size_t L>
    constexpr auto _do_get_cell_bits(
      T state,
      std::size_t bo,
      std::size_t bl,
      std::size_t bb,
      std::size_t be,
      std::size_t cb,
      std::size_t ce,
      size_constant<L>) const noexcept -> T {
        return _get_cell_bits(
          T(state << bl) | _extract_cell_bits(_bytes[size_type(cb)], bo, bl),
          bb + bl,
          be,
          cb + 1,
          ce,
          size_constant<L + 1>{});
    }

    static constexpr auto _get_cell_bits(
      T state,
      std::size_t,
      std::size_t,
      std::size_t,
      std::size_t,
      size_constant<_byte_s>) noexcept -> T {
        return state;
    }

    template <std::size_t L>
    constexpr auto _get_cell_bits(
      T state,
      std::size_t bb,
      std::size_t be,
      std::size_t cb,
      std::size_t ce,
      size_constant<L> l) const noexcept -> T {
        return (bb >= be)
                 ? state
                 : _do_get_cell_bits(
                     state,
                     (bb - cb * _byte_s),
                     _min_s((be - bb), (_byte_s - (bb - cb * _byte_s))),
                     bb,
                     be,
                     cb,
                     ce,
                     l);
    }

    constexpr auto _get_cell_bits(std::size_t bb, std::size_t be) const noexcept
      -> T {
        return _get_cell_bits(
          _byte_t(0), bb, be, bb / _byte_s, be / _byte_s, size_constant<1>{});
    }

    constexpr auto _get_cell(std::size_t i) const noexcept -> T {
        return (B == _byte_s)
                 ? T(_bytes[size_type(i)])
                 : _get_cell_bits((i + 0) * _bite_s, (i + 1) * _bite_s);
    }

    static constexpr void _store_cell_bits(
      T v,
      _byte_t& by,
      std::size_t ofs,
      std::size_t len) noexcept {
        // NOLINTNEXTLINE(hicpp-signed-bitwise)
        _byte_t msk = _byte_t(((1 << len) - 1) << (_byte_s - ofs - len));
        by ^= (by & msk);
        by |= (v << (_byte_s - ofs - len));
    }

    template <std::size_t L>
    void _do_set_cell_bits(
      T state,
      std::size_t bo,
      std::size_t bl,
      std::size_t bb,
      std::size_t be,
      std::size_t cb,
      std::size_t ce,
      size_constant<L>) noexcept {
        _store_cell_bits(
          (state >> (_cell_s - bl)), _bytes[size_type(cb)], bo, bl);
        return _set_cell_bits(
          T(state << bl), bb + bl, be, cb + 1, ce, size_constant<L + 1>{});
    }

    static constexpr void _set_cell_bits(
      T,
      std::size_t,
      std::size_t,
      std::size_t,
      std::size_t,
      size_constant<_byte_s>) noexcept {}

    template <std::size_t L>
    void _set_cell_bits(
      T state,
      std::size_t bb,
      std::size_t be,
      std::size_t cb,
      std::size_t ce,
      size_constant<L> l) noexcept {
        if(bb < be) {
            _do_set_cell_bits(
              state,
              (bb - cb * _byte_s),
              _min_s((be - bb), (_byte_s - (bb - cb * _byte_s))),
              bb,
              be,
              cb,
              ce,
              l);
        }
    }

    void _set_cell_bits(T state, std::size_t bb, std::size_t be) noexcept {
        return _set_cell_bits(
          state, bb, be, bb / _byte_s, be / _byte_s, size_constant<1>{});
    }

    void _set_cell(std::size_t i, T value) noexcept {
        if(B == _byte_s) {
            _bytes[size_type(i)] = _byte_t(value);
        } else {
            _set_cell_bits(
              T(value << (_cell_s - _bite_s)),
              (i + 0) * _bite_s,
              (i + 1) * _bite_s);
        }
    }

    template <std::size_t... I>
    static constexpr auto
    _do_make_bytes(const T (&init)[N], std::index_sequence<I...>) noexcept {
        return _bytes_t{_get_byte(init, size_constant<I>{})...};
    }

    template <typename... P>
    static constexpr auto _make_bytes(P... p) noexcept {
        return _do_make_bytes(
          {T(p)...}, std::make_index_sequence<_store_size>{});
    }
};

} // namespace eagine

#endif // EAGINE_BITESET_HPP
