/**
 *  @file eagine/struct_memory_block.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STRUCT_MEMORY_BLOCK_HPP
#define EAGINE_STRUCT_MEMORY_BLOCK_HPP

#include "memory/block.hpp"
#include <type_traits>

namespace eagine {

// TODO: remove this
template <typename T>
class structured_memory_block {
private:
    memory::basic_block<std::is_const_v<T>> _blk;

    template <typename X = T, typename = std::enable_if_t<!std::is_const_v<X>>>
    X* _ptr() noexcept {
        assert(is_valid_block(_blk));
        return static_cast<X*>(_blk.addr());
    }

    const T* _cptr() const noexcept {
        assert(is_valid_block(_blk));
        return static_cast<const T*>(_blk.addr());
    }

public:
    static bool is_valid_block(memory::const_block blk) noexcept {
        return !blk.empty() && (blk.is_aligned_as<T>()) &&
               (can_accomodate(blk, identity<T>()));
    }

    structured_memory_block(
      memory::basic_block<std::is_const_v<T>> blk) noexcept
      : _blk(blk) {
        assert(is_valid_block(_blk));
    }

    template <
      typename X = T,
      typename = std::enable_if_t<!std::is_const_v<X> && std::is_same_v<X, T>>>
    X& get() noexcept {
        return *_ptr();
    }

    template <
      typename X = T,
      typename = std::enable_if_t<!std::is_const_v<X> && std::is_same_v<X, T>>>
    X* operator->() noexcept {
        return _ptr();
    }

    const T& get() const noexcept {
        return *_cptr();
    }

    const T* operator->() const noexcept {
        return _cptr();
    }
};

} // namespace eagine

#endif // EAGINE_STRUCT_MEMORY_BLOCK_HPP
