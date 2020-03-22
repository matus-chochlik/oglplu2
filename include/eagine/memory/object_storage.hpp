/**
 *  @file eagine/memory/object_storage.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MEMORY_OBJECT_STORAGE_HPP
#define EAGINE_MEMORY_OBJECT_STORAGE_HPP

#include "../assert.hpp"
#include "../types.hpp"
#include "block.hpp"
#include "byte_alloc.hpp"
#include <vector>

namespace eagine {
namespace memory {
//------------------------------------------------------------------------------
template <typename Alloc>
class basic_object_storage {
private:
    Alloc _alloc;

    template <typename T>
    static void _destroy(block blk) noexcept {
        auto spn = accomodate<T>(blk);
        EAGINE_ASSERT(spn);
        auto& x{extract(spn)};
        x.~T();
    }

    std::vector<owned_block> _blks;
    std::vector<span_size_t> _alns;
    std::vector<void (*)(block)> _dtrs;

public:
    basic_object_storage() noexcept = default;
    basic_object_storage(basic_object_storage&&) noexcept = default;
    basic_object_storage(const basic_object_storage&) = delete;
    basic_object_storage& operator=(basic_object_storage&&) = delete;
    basic_object_storage& operator=(const basic_object_storage&) = delete;
    ~basic_object_storage() noexcept {
        clear();
    }

    template <typename T, typename... Args>
    std::remove_const_t<T>& emplace(Args&&... args) {
        using A = std::remove_const_t<T>;
        const auto size = span_size_of<A>();
        const auto align = span_align_of<A>();
        owned_block b = _alloc.allocate(size, align);

        if(b.empty()) {
            throw std::bad_alloc();
        }

        EAGINE_ASSERT(is_aligned_to(b.addr(), align));
        EAGINE_ASSERT(b.size() >= size);

        _blks.push_back(std::move(b));
        _alns.push_back(align);
        _dtrs.push_back(&_destroy<A>);

        A* result = new(_blks.back().data()) A(std::forward<Args>(args)...);
        EAGINE_ASSERT(result != nullptr);
        return *result;
    }

    void clear() noexcept {
        EAGINE_ASSERT(_blks.size() == _alns.size());
        EAGINE_ASSERT(_blks.size() == _dtrs.size());

        for(std_size_t i = _blks.size(); i > 0; --i) {
            _dtrs[i - 1](_blks[i - 1]);
        }

        for(std_size_t i = 0; i < _blks.size(); ++i) {
            _alloc.deallocate(std::move(_blks[i]), _alns[i]);
        }

        _dtrs.clear();
        _alns.clear();
        _blks.clear();
    }
};
//------------------------------------------------------------------------------
} // namespace memory
} // namespace eagine

#endif // EAGINE_MEMORY_OBJECT_STORAGE_HPP
