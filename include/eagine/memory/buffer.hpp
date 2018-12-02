/**
 *  @file eagine/memory/buffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_BUFFER_1510290655_HPP
#define EAGINE_MEMORY_BUFFER_1510290655_HPP

#include "block.hpp"
#include "default_alloc.hpp"
#include "shared_alloc.hpp"

namespace eagine {
namespace memory {

class buffer {
public:
    typedef typename block::size_type size_type;
    typedef typename block::pointer pointer;

private:
    span_size_t _size;
    span_size_t _align;
    owned_block _storage;
    shared_byte_allocator _alloc;

    bool _is_ok() const noexcept {
        return bool(_alloc) && size() <= capacity();
    }

    void _reallocate(span_size_t new_size) {
        _alloc.do_reallocate(_storage, new_size, _align);
    }

public:
    explicit buffer(span_size_t align)
      : _size(0)
      , _align(align)
      , _alloc(default_byte_allocator()) {
    }

    buffer()
      : buffer(alignof(long double)) {
    }

    buffer(const buffer&) = delete;

    ~buffer() noexcept {
        free();
    }

    auto addr() const noexcept {
        return _storage.addr();
    }

    pointer data() const noexcept {
        return _storage.data();
    }

    span_size_t size() const noexcept {
        return _size;
    }

    span_size_t capacity() const noexcept {
        return _storage.size();
    }

    void reserve(span_size_t new_size) {
        if(capacity() < new_size) {
            _reallocate(new_size);
        }
        assert(_is_ok());
    }

    void resize(span_size_t new_size) {
        reserve(new_size);
        _size = new_size;
        assert(_is_ok());
    }

    void free() {
        _alloc.deallocate(std::move(_storage), _align);
        _size = 0;
    }

    operator block() noexcept {
        assert(_is_ok());
        return {_storage.begin(), _size};
    }

    operator const_block() const noexcept {
        assert(_is_ok());
        return {_storage.begin(), _size};
    }
};

} // namespace memory
} // namespace eagine

#endif // include guard
