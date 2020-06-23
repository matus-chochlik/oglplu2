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
#include "std_alloc.hpp"
#include <vector>

namespace eagine {
namespace memory {
//------------------------------------------------------------------------------
class object_storage {
protected:
    shared_byte_allocator _alloc;

    template <typename T>
    static void _destroy(block blk) noexcept {
        auto spn = accomodate<T>(blk);
        EAGINE_ASSERT(spn);
        auto& x{extract(spn)};
        x.~T();
    }

    std::vector<owned_block, std_allocator<owned_block>> _blks;
    std::vector<span_size_t, std_allocator<span_size_t>> _alns;
    std::vector<void (*)(block), std_allocator<void (*)(block)>> _dtrs;

    template <typename Func>
    void for_each_block(Func& func) noexcept {
        for(std_size_t i = 0; i < _blks.size(); ++i) {
            func(i, block(_blks[i]));
        }
    }

public:
    template <
      typename X,
      typename = shared_byte_allocator::enable_if_compatible_t<X>>
    object_storage(X&& x) noexcept
      : _alloc(std::forward<X>(x))
      , _blks{std_allocator<owned_block>{_alloc}}
      , _alns{std_allocator<span_size_t>{_alloc}}
      , _dtrs{std_allocator<void (*)(block)>{_alloc}} {
    }

    object_storage(shared_byte_allocator a) noexcept
      : _alloc(std::move(a))
      , _blks{std_allocator<owned_block>{_alloc}}
      , _alns{std_allocator<span_size_t>{_alloc}}
      , _dtrs{std_allocator<void (*)(block)>{_alloc}} {
    }

    object_storage() noexcept
      : object_storage{default_byte_allocator()} {
    }

    object_storage(object_storage&&) = delete;
    object_storage(const object_storage&) = delete;
    object_storage& operator=(object_storage&&) = delete;
    object_storage& operator=(const object_storage&) = delete;
    ~object_storage() noexcept {
        clear();
    }

    void reserve(span_size_t n) {
        const auto sz{std_size(n)};
        _blks.reserve(sz);
        _alns.reserve(sz);
        _dtrs.reserve(sz);
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
class callable_storage<void(Params...)> : private memory::object_storage {
private:
    using base = memory::object_storage;
    std::vector<
      void (*)(block, Params...),
      std_allocator<void (*)(block, Params...)>>
      _clrs{};

    template <typename T>
    static void _call(block blk, Params... params) noexcept {
        auto spn = accomodate<T>(blk);
        EAGINE_ASSERT(spn);
        auto& x{extract(spn)};
        x(params...);
    }

public:
    template <
      typename X,
      typename = shared_byte_allocator::enable_if_compatible_t<X>>
    callable_storage(X&& x) noexcept
      : base(std::forward<X>(x))
      , _clrs{std_allocator<void (*)(block, Params...)>{base::_alloc}} {
    }

    callable_storage(shared_byte_allocator a) noexcept
      : base(std::move(a))
      , _clrs{std_allocator<void (*)(block, Params...)>{base::_alloc}} {
    }

    callable_storage() noexcept
      : callable_storage(default_byte_allocator()) {
    }

    void reserve(span_size_t n) {
        base::reserve(n);
        _clrs.reserve(std_size(n));
    }

    template <
      typename T,
      typename = std::enable_if_t<std::is_invocable_v<T, Params...>>>
    auto& add(T x) {
        using A = std::remove_const_t<T>;
        auto& result = base::template emplace<A>(std::move(x));
        _clrs.push_back(&_call<A>);
        return result;
    }

    bool is_empty() const noexcept {
        EAGINE_ASSERT(_blks.size() == _clrs.size());
        return base::is_empty();
    }

    void clear() noexcept {
        base::clear();
        _clrs.clear();
    }

    void operator()(Params... params) noexcept {
        auto fn = [&](auto i, block blk) { this->_clrs[i](blk, params...); };
        base::for_each_block(fn);
    }
};
//------------------------------------------------------------------------------
} // namespace memory
} // namespace eagine

#endif // EAGINE_MEMORY_OBJECT_STORAGE_HPP
