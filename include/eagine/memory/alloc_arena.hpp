/**
 *  @file eagine/memory/alloc_arena.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_ALLOC_ARENA_HPP
#define EAGINE_MEMORY_ALLOC_ARENA_HPP

#include "../assert.hpp"
#include "../span.hpp"
#include "../string_span.hpp"
#include "c_realloc.hpp"
#include <algorithm>
#include <utility>
#include <vector>

namespace eagine::memory {

template <typename Alloc>
class basic_allocation_arena : public block_owner {
private:
    Alloc _alloc;
    std::vector<owned_block> _blks;
    std::vector<span_size_t> _alns;

    auto _do_allocate(const span_size_t size, const span_size_t align) -> block;

    template <typename T>
    auto _allocate(const span_size_t count, const span_size_t align) -> block;

    template <typename T>
    auto _make_n(const span_size_t count, const span_size_t align) -> T*;

    template <typename T, typename... Args>
    auto _make_1(const span_size_t align, Args&&... args) -> T*;

protected:
    auto allocator() const -> const Alloc& {
        return _alloc;
    }

public:
    basic_allocation_arena() = default;

    template <typename... P>
    explicit basic_allocation_arena(P&&... p)
      : _alloc(std::forward<P>(p)...) {}

    explicit basic_allocation_arena(Alloc&& alloc)
      : _alloc(std::move(alloc)) {}

    basic_allocation_arena(basic_allocation_arena&&) noexcept = default;
    basic_allocation_arena(const basic_allocation_arena&) = delete;
    auto operator=(basic_allocation_arena&&) = delete;
    auto operator=(const basic_allocation_arena&) = delete;

    ~basic_allocation_arena() {
        clear();
    }

    auto empty() const noexcept -> bool {
        EAGINE_ASSERT(_blks.empty() == _alns.empty());
        return _blks.empty();
    }

    void clear();

    auto allocate(span_size_t size, span_size_t align) -> block {
        _blks.push_back(_alloc.allocate(size, align));
        _alns.push_back(align);
        return _blks.back();
    }

    template <typename T>
    auto make_aligned_array(const span_size_t count, const span_size_t align)
      -> span<T>;

    template <typename T>
    auto make_array(const span_size_t count) {
        return make_aligned_array<T>(count, 1);
    }

    template <typename T, typename P, typename S>
    auto copy_aligned_array(basic_span<T, P, S> src, const span_size_t align)
      -> span<std::remove_const_t<T>> {
        auto dst =
          make_aligned_array<std::remove_const_t<T>>(src.size(), align);
        std::copy(src.begin(), src.end(), dst.begin());
        return dst;
    }

    template <typename T, typename P, typename S>
    auto copy_array(basic_span<T, P, S> src) -> span<std::remove_const_t<T>> {
        return copy_aligned_array<T>(src, span_size(alignof(T)));
    }

    template <typename T, typename... Args>
    auto make_aligned(const span_size_t align, Args&&... args) -> T&;

    template <typename T, typename... Args>
    auto make(Args&&... args) -> T& {
        return make_aligned<T>(
          span_size(alignof(T)), std::forward<Args>(args)...);
    }

    template <typename T>
    void destroy(T& v) {
        v.~T();
    }
};

using system_allocation_arena =
  basic_allocation_arena<c_byte_reallocator<byte_alloc_managed_policy>>;

} // namespace eagine::memory

#include <eagine/memory/alloc_arena.inl>

#endif // EAGINE_MEMORY_ALLOC_ARENA_HPP
