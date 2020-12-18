/**
 *  @file eagine/stack_alloc.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/assert.hpp>
#include <eagine/maybe_unused.hpp>

namespace eagine::memory {
//------------------------------------------------------------------------------
// base_stack_allocator
//------------------------------------------------------------------------------
template <typename T>
inline auto base_stack_allocator<T>::_store() const noexcept -> const_block {
    EAGINE_ASSERT(_btm <= _top);
    return const_block(_btm, _top);
}
//------------------------------------------------------------------------------
template <typename T>
inline auto base_stack_allocator<T>::_allocated() const noexcept
  -> const_block {
    EAGINE_ASSERT(_btm <= _pos);
    return const_block(_btm, _pos);
}
//------------------------------------------------------------------------------
template <typename T>
inline auto base_stack_allocator<T>::_available() const noexcept
  -> const_block {
    EAGINE_ASSERT(_pos <= _top);
    return const_block(_pos, _top);
}
//------------------------------------------------------------------------------
template <typename T>
inline base_stack_allocator<T>::base_stack_allocator(
  base_stack_allocator&& tmp) noexcept
  : _btm(tmp._btm)
  , _top(tmp._top)
  , _pos(tmp._pos)
  , _min(tmp._min)
  , _dif(tmp._dif) {
    tmp._btm = nullptr;
    tmp._top = nullptr;
    tmp._pos = nullptr;
    tmp._min = nullptr;
    tmp._dif = 0;
}
//------------------------------------------------------------------------------
template <typename T>
inline base_stack_allocator<T>::base_stack_allocator(
  const block& blk,
  span_size_t align) noexcept
  : _btm(align_up_to(blk.addr(), type_identity<T>(), align))
  , _top(align_down_to(blk.end_addr(), type_identity<T>(), align))
  , _pos(_btm)
  , _min(_btm) {}
//------------------------------------------------------------------------------
template <typename T>
inline base_stack_allocator<T>::base_stack_allocator(const block& blk) noexcept
  : base_stack_allocator(blk, alignof(T)) {}
//------------------------------------------------------------------------------
template <typename T>
inline base_stack_allocator<T>::~base_stack_allocator() noexcept {
    if(!std::is_trivially_destructible<T>()) {
        EAGINE_ASSERT(_allocated().empty());
    }
}
//------------------------------------------------------------------------------
template <typename T>
inline auto
base_stack_allocator<T>::contains(const owned_block& b) const noexcept -> bool {
    return _store().contains(b);
}
//------------------------------------------------------------------------------
template <typename T>
inline auto
base_stack_allocator<T>::has_allocated(const owned_block& b) const noexcept
  -> tribool {
    return _allocated().contains(b);
}
//------------------------------------------------------------------------------
template <typename T>
inline auto base_stack_allocator<T>::allocate(size_type n) noexcept
  -> owned_block {
    if(n > max_size()) {
        return {};
    }

    auto result = static_cast<pointer>(_pos);

    EAGINE_ASSERT(_min <= _pos);
    if(_min == _pos) {
        _min += n;
    } else {
        _dif += n;
    }

    _pos += n;
    return acquire_block({result, n});
}
//------------------------------------------------------------------------------
template <typename T>
inline auto
base_stack_allocator<T>::truncate(owned_block&& b, size_type nn) noexcept
  -> owned_block {
    auto p = static_cast<pointer>(b.addr());
    size_type pn = b.size();
    release_block(std::move(b));

    EAGINE_ASSERT(pn >= nn);

    if(p + pn == _pos) {
        auto d = difference_type(pn - nn);
        EAGINE_ASSERT(_min <= _pos);
        if(_min == _pos) {
            _min -= d;
        } else {
            _dif -= d;
        }

        _pos -= d;
    }
    return acquire_block({p, nn});
}
//------------------------------------------------------------------------------
template <typename T>
inline void base_stack_allocator<T>::deallocate(owned_block&& b) noexcept {
    auto p = static_cast<pointer>(b.addr());
    size_type n = b.size();
    release_block(std::move(b));

    EAGINE_ASSERT(p + n <= _pos);
    if(p + n == _pos) {
        EAGINE_ASSERT(_min <= _pos);
        if(_min == _pos) {
            _min -= n;
        } else {
            _dif -= n;
        }

        _pos -= n;
    } else {
        if(p + n == _min) {
            _min -= n;
        } else if(p + n > _min) {
            _dif -= n;
        } else {
            _dif += size_type(_min - p) - n;
            _min = p;
        }
    }
    if(_dif == 0) {
        _pos = _min;
    }
}
//------------------------------------------------------------------------------
// stack_byte_allocator_only
//------------------------------------------------------------------------------
template <typename Policy>
inline auto
stack_byte_allocator_only<Policy>::equal(byte_allocator* a) const noexcept
  -> bool {
    auto* sba = dynamic_cast<stack_byte_allocator_only*>(a);

    return (sba != nullptr) && (this->_alloc == sba->_alloc);
}
//------------------------------------------------------------------------------
template <typename Policy>
inline auto
stack_byte_allocator_only<Policy>::allocate(size_type n, size_type a) noexcept
  -> owned_block {
    size_type m = (a - _alloc.allocated_size() % a) % a;
    owned_block b = _alloc.allocate(m + n);

    if(b) {
        EAGINE_ASSERT(is_aligned_to(b.begin() + m, a));
    }

    EAGINE_ASSERT(m <= b.size());

    owned_block r{this->acquire_block({b.begin() + m, b.end()})};

    this->release_block(std::move(b));

    return r;
}
//------------------------------------------------------------------------------
template <typename Policy>
inline void stack_byte_allocator_only<Policy>::deallocate(
  owned_block&& b,
  size_type) noexcept {
    EAGINE_ASSERT(_alloc.has_allocated(b));
    this->release_block(std::move(b));
}
//------------------------------------------------------------------------------
// stack_byte_allocator
//------------------------------------------------------------------------------
template <typename Policy>
inline auto
stack_byte_allocator<Policy>::equal(byte_allocator* a) const noexcept -> bool {
    auto* sba = dynamic_cast<stack_byte_allocator*>(a);

    return (sba != nullptr) && (this->_alloc == sba->_alloc);
}
//------------------------------------------------------------------------------
template <typename Policy>
inline auto
stack_byte_allocator<Policy>::allocate(size_type n, size_type a) noexcept
  -> owned_block {
    size_type m = a - _alloc.allocated_size() % a;

    EAGINE_ASSERT((m < 255) && "must fit into a byte");

    owned_block b = _alloc.allocate(m + n);

    if(b) {
        EAGINE_ASSERT(is_aligned_to(b.begin() + m, a));
        b[m - 1] = byte(m);
    }

    EAGINE_ASSERT(m <= b.size());

    owned_block r = this->acquire_block({b.begin() + m, b.end()});

    this->release_block(std::move(b));

    return r;
}
//------------------------------------------------------------------------------
template <typename Policy>
inline void
stack_byte_allocator<Policy>::deallocate(owned_block&& b, size_type) noexcept {
    EAGINE_ASSERT(_alloc.has_allocated(b));

    byte* p = b.data();

    EAGINE_ASSERT(reinterpret_cast<std::intptr_t>(p) >= 1);

    const auto m = size_type(p[-1]);

    EAGINE_ASSERT(reinterpret_cast<std::intptr_t>(p) >= m);

    _alloc.deallocate(this->acquire_block({p - m, b.size() + m}));

    this->release_block(std::move(b));
}
//------------------------------------------------------------------------------
template <typename Policy>
inline auto
stack_aligned_byte_allocator<Policy>::equal(byte_allocator* a) const noexcept
  -> bool {
    auto* sba = dynamic_cast<_this_class*>(a);

    return (sba != nullptr) && (this->_alloc == sba->_alloc);
}
//------------------------------------------------------------------------------
template <typename Policy>
inline auto stack_aligned_byte_allocator<Policy>::has_allocated(
  const owned_block& b,
  span_size_t) noexcept -> tribool {
    return _alloc.has_allocated(b);
}
//------------------------------------------------------------------------------
template <typename Policy>
inline auto stack_aligned_byte_allocator<Policy>::allocate(
  size_type n,
  size_type a) noexcept -> owned_block {
    EAGINE_MAYBE_UNUSED(a);
    auto b = _alloc.allocate(n);

    EAGINE_ASSERT(is_aligned_to(b.addr(), a));

    return b;
}
//------------------------------------------------------------------------------
template <typename Policy>
inline void stack_aligned_byte_allocator<Policy>::deallocate(
  owned_block&& b,
  size_type a) noexcept {
    EAGINE_MAYBE_UNUSED(a);
    EAGINE_ASSERT(is_aligned_to(b.addr(), a));
    _alloc.deallocate(std::move(b));
}
//------------------------------------------------------------------------------
template <typename Policy>
inline auto stack_aligned_byte_allocator<Policy>::_own_end_misalign(
  _this_class* p) const noexcept -> span_size_t {
    const auto e =
      reinterpret_cast<std::intptr_t>(p) + span_size(sizeof(_this_class));

    return (_align - (e % _align)) % _align;
}
//------------------------------------------------------------------------------
template <typename Policy>
inline auto stack_aligned_byte_allocator<Policy>::accomodate_self() noexcept
  -> byte_allocator* {
    auto* ba = this->accomodate_derived(*this);

    if(span_size_t m = _own_end_misalign(ba)) {
        this->release_block(ba->_alloc.allocate(m));
    }

    return ba;
}
//------------------------------------------------------------------------------
template <typename Policy>
inline void stack_aligned_byte_allocator<Policy>::eject_self() noexcept {
    if(span_size_t m = _own_end_misalign(this)) {
        byte* p = reinterpret_cast<byte*>(this);
        p += sizeof(_this_class);

        _alloc.deallocate(this->acquire_block({p, m}));
    }

    this->eject_derived(*this);
}
//------------------------------------------------------------------------------
} // namespace eagine::memory
