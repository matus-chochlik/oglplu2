/**
 *  @file eagine/memory/block.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_BLOCK_1510290655_HPP
#define EAGINE_MEMORY_BLOCK_1510290655_HPP

#include <cstddef>
#include <utility>
#include "address.hpp"

namespace eagine {
namespace memory {

template <bool IsConst>
class basic_block {
public:
    typedef std::conditional_t<IsConst, const void*, void*> pointer;

    typedef std::conditional_t<IsConst, const byte*, byte*> iterator;

    typedef std::conditional_t<IsConst, const byte&, byte&> reference;

    typedef span_size_t size_type;

private:
    pointer _addr;
    size_type _size;

    template <typename T>
    static span_size_t _positive_distance(T* a, T* b) noexcept {
        assert(a <= b);
        return span_size(b - a);
    }

public:
    template <typename T>
    basic_block(T* a, span_size_t count) noexcept
      : _addr(static_cast<pointer>(a))
      , _size(span_size_of<T>(count)) {
    }

    template <typename T>
    basic_block(T* a, T* b) noexcept
      : _addr(static_cast<pointer>(a))
      , _size(span_size_of<T>(_positive_distance(a, b))) {
    }

    basic_block(pointer addr_, size_type size_) noexcept
      : _addr(addr_)
      , _size(size_) {
    }

    constexpr basic_block() noexcept
      : _addr(nullptr)
      , _size(0) {
    }

    basic_block(const basic_block&) = default;
    basic_block& operator=(const basic_block&) = default;

    basic_block(basic_block&& temp) noexcept
      : _addr(temp._addr)
      , _size(temp._size) {
        temp.reset();
    }

    basic_block& operator=(basic_block&& temp) noexcept {
        using std::swap;
        swap(_addr, temp._addr);
        swap(_size, temp._size);
        return *this;
    }

    template <bool IsConst2, typename = std::enable_if_t<IsConst && !IsConst2>>
    constexpr basic_block(basic_block<IsConst2> b) noexcept
      : _addr(b.data())
      , _size(b.size()) {
    }

    basic_block& reset() noexcept {
        _addr = nullptr;
        _size = 0;
        return *this;
    }

    size_type size() const noexcept {
        return _size;
    }

    bool empty() const noexcept {
        return !(size() > 0);
    }

    explicit operator bool() const noexcept {
        return _addr != nullptr && !empty();
    }

    bool operator!() const noexcept {
        return _addr == nullptr || empty();
    }

    iterator data() const noexcept {
        return static_cast<iterator>(_addr);
    }

    basic_address<IsConst> addr() const noexcept {
        return basic_address<IsConst>(_addr);
    }

    basic_address<IsConst> end_addr() const noexcept {
        return basic_address<IsConst>(addr(), _size);
    }

    iterator begin() const noexcept {
        return static_cast<iterator>(_addr);
    }

    iterator end() const noexcept {
        return begin() + size();
    }

    reference operator[](span_size_t i) noexcept {
        assert(i < size());
        return *(begin() + i);
    }

    friend bool operator==(
      const basic_block& a, const basic_block& b) noexcept {
        return (a._addr == b._addr) && (a._size == b._size);
    }

    friend bool operator!=(
      const basic_block& a, const basic_block& b) noexcept {
        return (a._addr != b._addr) || (a._size != b._size);
    }

    bool is_aligned_to(span_size_t align) const noexcept {
        return addr().is_aligned_to(align);
    }

    template <typename T>
    bool is_aligned_as() const noexcept {
        return addr().template is_aligned_as<T>();
    }

    template <typename T>
    bool is_enough_for() const noexcept {
        return size() >= span_size(sizeof(T));
    }

    bool encloses(const_address a) const noexcept {
        return (addr() <= a) && (a <= end_addr());
    }

    bool contains(const basic_block& b) const noexcept {
        return (addr() <= b.addr()) && (b.end_addr() <= end_addr());
    }

    bool overlaps(const basic_block& b) const noexcept {
        return encloses(b.addr()) || encloses(b.end_addr()) ||
               b.encloses(addr()) || b.encloses(end_addr());
    }
};

typedef basic_block<false> block;
typedef basic_block<true> const_block;

template <typename T>
static inline basic_block<std::is_const<T>::value>
block_of(T& v) noexcept {
    return {&v, 1};
}

template <typename T, span_size_t N>
static inline basic_block<std::is_const<T>::value>
block_of(T (&a)[N]) noexcept {
    return {a, N};
}

template <typename T>
static inline basic_block<
  std::is_const<T>::value || std::is_const<typename T::value_type>::value>
data_block_of(T& c) noexcept {
    return {c.data(), span_size(c.size())};
}

class block_owner;

class owned_block : public block {
private:
    friend class block_owner;

    owned_block(block b) noexcept
      : block(b) {
    }

protected:
    using block::reset;

public:
    owned_block() = default;
    owned_block(owned_block&&) = default;
    owned_block& operator=(owned_block&&) = default;
    owned_block(const owned_block&) = delete;
    owned_block& operator=(const owned_block&) = delete;

    ~owned_block() noexcept {
        assert(empty());
    }
};

class block_owner {
protected:
    static inline owned_block acquire_block(block b) noexcept {
        return {b};
    }

    static inline void release_block(owned_block&& b) noexcept {
        b.reset();
    }
};

} // namespace memory
} // namespace eagine

#endif // include guard
