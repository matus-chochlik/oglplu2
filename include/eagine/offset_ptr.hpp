/**
 *  @file eagine/offset_ptr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_OFFSET_PTR_1509260923_HPP
#define EAGINE_OFFSET_PTR_1509260923_HPP

#include "memory/address.hpp"
#include "memory_block.hpp"
#include "span.hpp"
#include "types.hpp"
#include <cassert>

namespace eagine {

// basic_offset_ptr
template <typename T, typename OffsT>
class basic_offset_ptr {
public:
    using address = memory::basic_address<std::is_const_v<T>>;
    using const_address = memory::const_address;
    using offset_type = OffsT;
    using pointer = T*;
    using const_pointer = std::add_const_t<T>*;
    using reference = T&;
    using const_reference = std::add_const_t<T>&;

private:
    static_assert(std::is_signed_v<offset_type>, "");

    offset_type _offs;
    using _rawptr = typename address::pointer;

    static address _that_addr(const basic_offset_ptr& that) {
	return address(_rawptr(&that));
    }

    address _this_addr(void) const noexcept {
	return _that_addr(*this);
    }

    offset_type _get_offs(address addr) noexcept {
	return addr ? addr - _this_addr() : 0;
    }

    offset_type _get_offs(T* ptr) noexcept {
	return _get_offs(address(ptr));
    }

    offset_type _get_offs(const basic_offset_ptr& that) noexcept {
	return that._offs ? that._offs + _get_offs(_that_addr(that)) : 0;
    }

public:
    constexpr inline basic_offset_ptr(void) noexcept
      : _offs{0} {
    }

    explicit constexpr inline basic_offset_ptr(offset_type offs) noexcept
      : _offs{offs} {
    }

    explicit constexpr inline basic_offset_ptr(address addr) noexcept
      : _offs{_get_offs(addr)} {
    }

    basic_offset_ptr(T* ptr) noexcept
      : _offs{_get_offs(ptr)} {
    }

    basic_offset_ptr(const basic_offset_ptr& that) noexcept
      : _offs{_get_offs(that)} {
    }

    basic_offset_ptr& operator=(const basic_offset_ptr& that) noexcept {
	_offs = _get_offs(that);
	return *this;
    }

    basic_offset_ptr& reset(T* ptr) noexcept {
	return *this = basic_offset_ptr(ptr);
    }

    basic_offset_ptr& reset(address adr) noexcept {
	return *this = basic_offset_ptr(adr);
    }

    constexpr inline bool is_null(void) const noexcept {
	return _offs == offset_type(0);
    }

    explicit constexpr inline operator bool(void) const noexcept {
	return !is_null();
    }

    constexpr inline bool operator!(void)const noexcept {
	return is_null();
    }

    offset_type offset(void) const noexcept {
	return _offs;
    }

    address addr(void) noexcept {
	return is_null() ? address() : address(_this_addr(), _offs);
    }

    const_address addr(void) const noexcept {
	return is_null() ? address() : address(_this_addr(), _offs);
    }

    pointer data(void) noexcept {
	return static_cast<pointer>(addr());
    }

    const_pointer data(void) const noexcept {
	return static_cast<const_pointer>(addr());
    }

    pointer get(void) noexcept {
	return data();
    }

    const_pointer get(void) const noexcept {
	return data();
    }

    operator pointer(void) noexcept {
	return get();
    }

    operator const_pointer(void) const noexcept {
	return get();
    }

    reference operator*(void)noexcept {
	assert(!is_null());
	return *get();
    }

    const_reference operator*(void)const noexcept {
	assert(!is_null());
	return *get();
    }

    pointer operator->(void)noexcept {
	assert(!is_null());
	return get();
    }

    const_pointer operator->(void)const noexcept {
	assert(!is_null());
	return get();
    }
};

template <typename T>
using offset_ptr = basic_offset_ptr<T, std::ptrdiff_t>;

template <typename T>
using short_offset_ptr = basic_offset_ptr<T, short>;

// basic_offset_array
template <typename T, typename OffsT>
class basic_offset_array {
public:
    using address = memory::basic_address<std::is_const_v<T>>;
    using value_type = T;
    using size_type = span_size_t;
    using offset_type = OffsT;
    using pointer = T*;
    using const_pointer = std::add_const_t<T>*;
    using reference = T&;
    using const_reference = std::add_const_t<T>&;
    using iterator = pointer;
    using const_iterator = const_pointer;

private:
    size_type _size;
    basic_offset_ptr<T, offset_type> _optr;

public:
    constexpr inline basic_offset_array(void) noexcept
      : _size{0} {
    }

    constexpr inline basic_offset_array(span<T> dest) noexcept
      : _size(dest.size())
      , _optr(_size > 0 ? dest.data() : nullptr) {
    }

    constexpr inline basic_offset_array(
      offset_type offs, size_type len) noexcept
      : _size(len)
      , _optr(offs) {
    }

    constexpr inline basic_offset_array(address adr, size_type len) noexcept
      : _size(len)
      , _optr(adr) {
    }

    basic_offset_array(T* ptr, size_type len) noexcept
      : _size(len)
      , _optr(ptr) {
    }

    basic_offset_array& operator=(const basic_offset_array&) = default;

    basic_offset_array& reset(T* ptr, size_type len) noexcept {
	return *this = basic_offset_array(ptr, len);
    }

    basic_offset_array& reset(address adr, size_type len) noexcept {
	return *this = basic_offset_array(adr, len);
    }

    constexpr inline size_type size(void) const noexcept {
	return _size;
    }

    offset_type offset(void) const noexcept {
	return _optr.offset();
    }

    address addr(void) noexcept {
	return _optr.addr();
    }

    iterator data(void) noexcept {
	return _optr.data();
    }

    iterator begin(void) noexcept {
	return _optr.data();
    }

    iterator end(void) noexcept {
	return begin() + size();
    }

    memory::const_address addr(void) const noexcept {
	return _optr.addr();
    }

    const_iterator data(void) const noexcept {
	return _optr.data();
    }

    const_iterator begin(void) const noexcept {
	return _optr.data();
    }

    const_iterator end(void) const noexcept {
	return begin() + size();
    }

    const_memory_block block(void) const noexcept {
	return {data(), size()};
    }

    memory_block block(void) noexcept {
	return {data(), size()};
    }

    reference operator[](size_type index) noexcept {
	assert(index >= size_type(0) && index < size());
	return begin()[index];
    }

    const_reference operator[](size_type index) const noexcept {
	assert(index >= size_type(0) && index < size());
	return begin()[index];
    }
};

template <typename T>
using offset_array = basic_offset_array<T, std::ptrdiff_t>;

template <typename T>
using short_offset_array = basic_offset_array<T, short>;

template <typename T, typename PtrOffsT, typename AryOffsT>
class basic_offset_ptr_array_facade {
public:
    typedef T value_type;
    typedef span_size_t size_type;

private:
    const basic_offset_array<const basic_offset_ptr<T, PtrOffsT>, AryOffsT>&
      _ptrarray;

public:
    basic_offset_ptr_array_facade(
      const basic_offset_array<const basic_offset_ptr<T, PtrOffsT>, AryOffsT>&
	pa) noexcept
      : _ptrarray(pa) {
    }

    size_type size(void) const noexcept {
	return _ptrarray.size();
    }

    T& operator[](span_size_t index) const noexcept {
	assert(index < size());
	assert(_ptrarray[index] != nullptr);
	return *_ptrarray[index];
    }
};

template <typename T>
using offset_ptr_array_facade =
  basic_offset_ptr_array_facade<T, std::ptrdiff_t, std::ptrdiff_t>;

} // namespace eagine

#endif // include guard
