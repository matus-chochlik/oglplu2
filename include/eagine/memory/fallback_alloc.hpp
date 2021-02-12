/// @file eagine/memory/fallback_alloc.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MEMORY_FALLBACK_ALLOC_HPP
#define EAGINE_MEMORY_FALLBACK_ALLOC_HPP

#include "../assert.hpp"
#include "default_alloc.hpp"
#include "shared_alloc.hpp"

namespace eagine::memory {

template <typename Policy = default_byte_allocator_policy>
class byte_allocator_with_fallback
  : public byte_allocator_impl<Policy, byte_allocator_with_fallback> {
private:
    span_size_t _fbk_size;
    span_size_t _fbk_max;
    shared_byte_allocator _dft;
    shared_byte_allocator _fbk;

public:
    byte_allocator_with_fallback(
      shared_byte_allocator&& dft,
      shared_byte_allocator&& fbk = default_byte_allocator())
      : _fbk_size(0)
      , _fbk_max(0)
      , _dft(std::move(dft))
      , _fbk(std::move(fbk)) {}

    using size_type = span_size_t;

    auto equal(byte_allocator* a) const noexcept -> bool override {
        auto* pa = dynamic_cast<byte_allocator_with_fallback*>(a);

        if(a != nullptr) {
            return (_dft == pa->_dft) && (_fbk == pa->_fbk);
        }
        return false;
    }

    auto max_size(span_size_t a) noexcept -> size_type override {
        size_type mdft = _dft.max_size(a);
        size_type mfbk = _fbk.max_size(a);

        return (mfbk > mdft) ? mfbk : mdft;
    }

    auto has_allocated(const owned_block& b, span_size_t a) noexcept
      -> tribool override {
        return _dft.has_allocated(b, a) || _fbk.has_allocated(b, a);
    }

    auto allocate(size_type n, size_type a) noexcept -> owned_block override {
        if(n <= _dft.max_size(a)) {
            if(owned_block b = _dft.allocate(n, a)) {
                return b;
            }
        }

        _fbk_size += n;
        if(_fbk_max < _fbk_size) {
            _fbk_max = _fbk_size;
        }
        return _fbk.allocate(n, a);
    }

    void deallocate(owned_block&& b, size_type a) noexcept override {
        if(_dft.has_allocated(b, a)) {
            _dft.deallocate(std::move(b), a);
        } else if(!!_fbk.has_allocated(b, a)) {
            _fbk_size -= b.size();
            _fbk.deallocate(std::move(b), a);
        } else {
            EAGINE_ABORT("Pointer not allocated by this allocator!");
        }
    }
};

} // namespace eagine::memory

#endif // EAGINE_MEMORY_FALLBACK_ALLOC_HPP
