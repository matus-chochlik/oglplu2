/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/assert.hpp>
#include <cstdlib>

namespace eagine::memory {
//------------------------------------------------------------------------------
template <typename Alloc>
inline auto basic_allocation_arena<Alloc>::_do_allocate(
  const span_size_t size,
  const span_size_t align) -> block {
    owned_block b = _alloc.allocate(size, align);

    if(b.empty()) {
        return {};
    }

    EAGINE_ASSERT(is_aligned_to(b.addr(), align));
    EAGINE_ASSERT(b.size() >= size);

    _blks.push_back(std::move(b));
    _alns.push_back(align);

    return _blks.back();
}
//------------------------------------------------------------------------------
template <typename Alloc>
inline void basic_allocation_arena<Alloc>::clear() {
    EAGINE_ASSERT(_blks.size() == _alns.size());

    for(std_size_t i = 0; i < _blks.size(); ++i) {
        _alloc.deallocate(std::move(_blks[i]), _alns[i]);
    }
    _blks.clear();
    _alns.clear();
}
//------------------------------------------------------------------------------
template <typename Alloc>
template <typename T>
inline auto basic_allocation_arena<Alloc>::_allocate(
  const span_size_t count,
  const span_size_t align) -> block {
    return _do_allocate(
      span_size_of<T>(count), std::max(align, span_align_of<T>()));
}
//------------------------------------------------------------------------------
template <typename Alloc>
template <typename T>
inline auto basic_allocation_arena<Alloc>::_make_n(
  const span_size_t count,
  const span_size_t align) -> T* {
    return new(_allocate<T>(count, align).data()) T[std_size(count)]{};
}
//------------------------------------------------------------------------------
template <typename Alloc>
template <typename T, typename... Args>
inline auto
basic_allocation_arena<Alloc>::_make_1(const span_size_t align, Args&&... a)
  -> T* {
    return new(_allocate<T>(1, align).data()) T(std::forward<Args>(a)...);
}
//------------------------------------------------------------------------------
template <typename Alloc>
template <typename T>
inline auto basic_allocation_arena<Alloc>::make_aligned_array(
  const span_size_t count,
  const span_size_t align) -> span<T> {
    if(count < 1) {
        return {};
    }

    T* p = _make_n<T>(count, align);
    if(!p) {
        throw std::bad_alloc();
    }
    return {p, count};
}
//------------------------------------------------------------------------------
template <typename Alloc>
template <typename T, typename... Args>
inline auto basic_allocation_arena<Alloc>::make_aligned(
  const span_size_t align,
  Args&&... args) -> T& {
    T* p = _make_1<T>(align, std::forward<Args>(args)...);
    if(!p) {
        throw std::bad_alloc();
    }

    return *p;
}
//------------------------------------------------------------------------------
} // namespace eagine::memory
