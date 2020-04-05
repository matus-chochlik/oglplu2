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
#include "default_alloc.hpp"
#include "shared_alloc.hpp"
#include <vector>

namespace eagine {
namespace memory {
//------------------------------------------------------------------------------
class object_storage {
private:
    shared_byte_allocator _alloc{default_byte_allocator()};

    template <typename T>
    static void _destroy(block blk) noexcept {
        auto spn = accomodate<T>(blk);
        EAGINE_ASSERT(spn);
        auto& x{extract(spn)};
        x.~T();
    }

    // TODO: use _alloc
    std::vector<owned_block> _blks{};
    std::vector<span_size_t> _alns{};
    std::vector<void (*)(block)> _dtrs{};

public:
    object_storage() noexcept = default;

    template <
      typename X,
      typename = shared_byte_allocator::enable_if_compatible_t<X>>
    object_storage(X&& x) noexcept
      : _alloc(std::forward<X>(x)) {
    }

    object_storage(object_storage&&) noexcept = default;
    object_storage(const object_storage&) = delete;
    object_storage& operator=(object_storage&&) = delete;
    object_storage& operator=(const object_storage&) = delete;
    ~object_storage() noexcept {
        clear();
    }

    bool is_empty() const noexcept {
        EAGINE_ASSERT(_blks.size() == _alns.size());
        EAGINE_ASSERT(_blks.size() == _dtrs.size());
        return _blks.empty();
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

    template <typename Func>
    void for_each_block(Func& func) noexcept {
        for(std_size_t i = 0; i < _blks.size(); ++i) {
            func(i, block(_blks[i]));
        }
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
template <typename Signature>
class callable_storage;

template <typename... Params>
class callable_storage<void(Params...)> {
private:
    std::vector<void (*)(block, Params...)> _clrs{};
    memory::object_storage _storage;

    template <typename T>
    static void _call(block blk, Params... params) noexcept {
        auto spn = accomodate<T>(blk);
        EAGINE_ASSERT(spn);
        auto& x{extract(spn)};
        x(params...);
    }

public:
    template <
      typename T,
      typename = std::enable_if_t<std::is_invocable_v<T, Params...>>>
    auto& add(T x) {
        using A = std::remove_const_t<T>;
        _clrs.push_back(&_call<A>);
        return _storage.template emplace<A>(std::move(x));
    }

    bool is_empty() const noexcept {
        return _storage.is_empty();
    }

    void clear() noexcept {
        _storage.clear();
        _clrs.clear();
    }

    void operator()(Params... params) noexcept {
        auto fn = [&](auto i, block blk) { this->_clrs[i](blk, params...); };
        _storage.for_each_block(fn);
    }
};
//------------------------------------------------------------------------------
} // namespace memory
} // namespace eagine

#endif // EAGINE_MEMORY_OBJECT_STORAGE_HPP
