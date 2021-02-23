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
/// @brief Reallocatable owning byte buffer.
/// @ingroup memory
/// @see block
class buffer {
public:
    /// @brief Buffer size type.
    using size_type = typename block::size_type;

    /// @brief Pointer type.
    using pointer = typename block::pointer;

    /// @brief Constructor with explicit alignment specification.
    explicit buffer(span_size_t align)
      : _align(align)
      , _alloc(default_byte_allocator()) {}

    /// @brief Default constructor.
    buffer()
      : buffer(alignof(long double)) {}

    /// @brief Move constructor.
    buffer(buffer&& temp) noexcept
      : _size{temp._size}
      , _align{temp._align}
      , _storage{std::move(temp._storage)}
      , _alloc{std::move(temp._alloc)} {
        temp._size = 0;
    }

    /// @brief Move assignment operator.
    auto operator=(buffer&& temp) noexcept -> buffer& {
        _size = temp._size;
        temp._size = 0;
        _align = temp._align;
        _storage = std::move(temp._storage);
        _alloc = std::move(temp._alloc);
        return *this;
    }

    /// @brief Not copyable.
    buffer(const buffer&) = delete;

    /// @brief Not copy assignable.
    auto operator=(const buffer&) = delete;

    ~buffer() noexcept {
        free();
    }

    /// @brief Returns the memory address of the start of the allocated space.
    auto addr() const noexcept {
        return _storage.addr();
    }

    /// @brief Returns the pointer to the start of the allocated space.
    auto data() const noexcept -> pointer {
        return _storage.data();
    }

    /// @brief Returns the size of the buffer in bytes.
    /// @see empty
    /// @see capacity
    auto size() const noexcept -> span_size_t {
        return _size;
    }

    /// @brief Indicates that the buffer is empty.
    /// @see size
    /// @see capacity
    auto empty() const noexcept {
        return size() == 0;
    }

    /// @brief Returns the capacity of this buffer.
    /// @see reserve
    /// @see resize
    auto capacity() const noexcept -> span_size_t {
        return _storage.size();
    }

    /// @brief Pre-allocate the specified number of bytes.
    /// @see capacity
    /// @see resize
    auto reserve(span_size_t new_size) -> auto& {
        if(capacity() < new_size) {
            _reallocate(new_size);
        }
        EAGINE_ASSERT(_is_ok());
        return *this;
    }

    /// @brief Resizes the buffer to the specified number of bytes.
    /// @see size
    /// @see ensure
    /// @see reserve
    auto resize(span_size_t new_size) -> auto& {
        reserve(new_size);
        _size = new_size;
        EAGINE_ASSERT(_is_ok());
        return *this;
    }

    /// @brief Ensure that the buuffer has at least the specified size in bytes.
    /// @see size
    /// @see resize
    /// @see reserve
    /// @see enlarge_by
    auto ensure(span_size_t new_size) -> auto& {
        if(size() < new_size) {
            return resize(new_size);
        }
        EAGINE_ASSERT(_is_ok());
        return *this;
    }

    /// @brief Enlarges the buffer by the specified number of bytes.
    /// @see size
    /// @see resize
    /// @see reserve
    /// @see ensure
    auto enlarge_by(span_size_t inc_size) -> auto& {
        return resize(size() + inc_size);
    }

    /// @brief Clears the buffer.
    /// @see size
    /// @see resize
    /// @see reserve
    /// @see free
    /// @post empty()
    auto clear() -> auto& {
        return resize(0);
    }

    /// @brief Deallocates the buffer.
    /// @see size
    /// @see resize
    /// @see reserve
    /// @see clear
    /// @post empty() && capacity() == 0
    void free() {
        _alloc.deallocate(std::move(_storage), _align);
        _size = 0;
    }

    /// @brief Implicit conversion to block.
    operator block() noexcept {
        EAGINE_ASSERT(_is_ok());
        return {_storage.begin(), _size};
    }

    /// @brief Implicit conversion to const_block.
    operator const_block() const noexcept {
        EAGINE_ASSERT(_is_ok());
        return {_storage.begin(), _size};
    }

private:
    span_size_t _size{0};
    span_size_t _align{0};
    owned_block _storage{};
    shared_byte_allocator _alloc{};

    auto _is_ok() const noexcept -> bool {
        return bool(_alloc) && size() <= capacity();
    }

    void _reallocate(span_size_t new_size) {
        _alloc.do_reallocate(_storage, new_size, _align);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::memory

#endif // EAGINE_MEMORY_BUFFER_HPP
