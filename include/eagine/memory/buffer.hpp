/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_BUFFER_HPP
#define EAGINE_MEMORY_BUFFER_HPP

#include "../assert.hpp"
#include "block.hpp"
#include "default_alloc.hpp"
#include "shared_alloc.hpp"

namespace eagine::memory {
//------------------------------------------------------------------------------
class buffer {
public:
    using size_type = typename block::size_type;
    using pointer = typename block::pointer;

private:
    span_size_t _size{0};
    span_size_t _align{0};
    owned_block _storage{};
    shared_byte_allocator _alloc{};

    auto _is_ok() const noexcept {
        return bool(_alloc) && size() <= capacity();
    }

    void _reallocate(span_size_t new_size) {
        _alloc.do_reallocate(_storage, new_size, _align);
    }

public:
    explicit buffer(span_size_t align)
      : _align(align)
      , _alloc(default_byte_allocator()) {}

    buffer()
      : buffer(alignof(long double)) {}

    buffer(buffer&& temp) noexcept
      : _size{temp._size}
      , _align{temp._align}
      , _storage{std::move(temp._storage)}
      , _alloc{std::move(temp._alloc)} {
        temp._size = 0;
    }
    auto operator=(buffer&& temp) noexcept -> buffer& {
        _size = temp._size;
        temp._size = 0;
        _align = temp._align;
        _storage = std::move(temp._storage);
        _alloc = std::move(temp._alloc);
        return *this;
    }
    buffer(const buffer&) = delete;
    auto operator=(const buffer&) = delete;

    ~buffer() noexcept {
        free();
    }

    auto addr() const noexcept {
        return _storage.addr();
    }

    auto data() const noexcept -> pointer {
        return _storage.data();
    }

    auto size() const noexcept -> span_size_t {
        return _size;
    }

    auto empty() const noexcept {
        return size() == 0;
    }

    auto capacity() const noexcept -> span_size_t {
        return _storage.size();
    }

    auto reserve(span_size_t new_size) -> auto& {
        if(capacity() < new_size) {
            _reallocate(new_size);
        }
        EAGINE_ASSERT(_is_ok());
        return *this;
    }

    auto resize(span_size_t new_size) -> auto& {
        reserve(new_size);
        _size = new_size;
        EAGINE_ASSERT(_is_ok());
        return *this;
    }

    auto ensure(span_size_t new_size) -> auto& {
        if(size() < new_size) {
            return resize(new_size);
        }
        EAGINE_ASSERT(_is_ok());
        return *this;
    }

    auto clear() -> auto& {
        return resize(0);
    }

    auto enlarge_by(span_size_t inc_size) -> auto& {
        return resize(size() + inc_size);
    }

    void free() {
        _alloc.deallocate(std::move(_storage), _align);
        _size = 0;
    }

    operator block() noexcept {
        EAGINE_ASSERT(_is_ok());
        return {_storage.begin(), _size};
    }

    operator const_block() const noexcept {
        EAGINE_ASSERT(_is_ok());
        return {_storage.begin(), _size};
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_BUFFER_HPP
