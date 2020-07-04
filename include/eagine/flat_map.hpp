/**
 *  @file eagine/flat_map.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_FLAT_MAP_HPP
#define EAGINE_FLAT_MAP_HPP

#include "assert.hpp"
#include "types.hpp"
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
template <typename Key, typename Val, typename Cmp>
struct flat_map_value_compare : Cmp {

    constexpr const Cmp& key_comp() const noexcept {
        return *this;
    }

    template <typename L, typename R>
    constexpr bool operator()(
      const std::pair<L, Val>& a, const std::pair<R, Val>& b) const noexcept {
        return key_comp()(a.first, b.first);
    }

    template <typename K>
    constexpr bool operator()(
      const std::pair<K, Val>& a, const Key& b) const noexcept {
        return key_comp()(a.first, b);
    }

    template <typename K>
    constexpr bool operator()(
      const Key& a, const std::pair<K, Val>& b) const noexcept {
        return key_comp()(a, b.first);
    }
};
//------------------------------------------------------------------------------
template <typename Key, typename Val, typename Cmp>
struct flat_map_ops : flat_map_value_compare<Key, Val, Cmp> {
    using value_type = std::pair<const Key, Val>;

    constexpr const flat_map_value_compare<Key, Val, Cmp>& value_comp()
      const noexcept {
        return *this;
    }

    template <typename I>
    static bool empty(I b, I e) noexcept {
        return b == e;
    }

    template <typename I>
    static auto size(I b, I e) noexcept {
        using ::std::distance;
        return static_cast<span_size_t>(distance(b, e));
    }

    template <typename I>
    auto lower_bound(I b, I e, const Key& key) const noexcept {
        return ::std::lower_bound(b, e, key, value_comp());
    }

    template <typename I>
    auto upper_bound(I b, I e, const Key& key) const noexcept {
        return ::std::upper_bound(b, e, key, value_comp());
    }

    template <typename I>
    auto equal_range(I b, I e, const Key& key) const noexcept {
        return ::std::equal_range(b, e, key, value_comp());
    }

    template <typename I>
    auto find(I b, I e, const Key& key) const noexcept {
        b = lower_bound(b, e, key);
        if((b != e) && value_comp()(key, *b)) {
            b = e;
        }
        return b;
    }

    template <typename I>
    auto& at(I b, I e, const Key& key) const {
        b = find(b, e, key);
        if(b == e) {
            throw std::out_of_range("Invalid flat map key");
        }
        return b->second;
    }

    template <typename I>
    auto& get(I b, I e, const Key& key) const noexcept {
        b = find(b, e, key);
        EAGINE_ASSERT(b != e);
        return b->second;
    }
};
//------------------------------------------------------------------------------
template <typename Key, typename Val, typename Cmp, typename Derived>
class flat_map_view_crtp : flat_map_ops<Key, Val, Cmp> {
private:
    const Derived& _self() const noexcept {
        return *static_cast<const Derived*>(this);
    }
    Derived& _self() noexcept {
        return *static_cast<Derived*>(this);
    }

    auto _b() const noexcept {
        return _self().begin();
    }
    auto _b() noexcept {
        return _self().begin();
    }

    auto _e() const noexcept {
        return _self().end();
    }
    auto _e() noexcept {
        return _self().end();
    }

protected:
    using _ops_t = flat_map_ops<Key, Val, Cmp>;

    constexpr const _ops_t& _ops() const noexcept {
        return *this;
    }

public:
    using key_type = Key;
    using mapped_type = Val;
    using value_type = std::pair<const Key, Val>;
    using reference = value_type&;
    using const_reference = const value_type&;

    using key_compare = Cmp;
    using value_compare = flat_map_value_compare<Key, Val, Cmp>;

    const key_compare& key_comp() const noexcept {
        return _ops().value_comp().key_comp();
    }

    const value_compare& value_comp() const noexcept {
        return _ops().value_comp();
    }

    bool empty() const noexcept {
        return _ops().empty(_b(), _e());
    }

    auto size() const {
        return _ops().size(_b(), _e());
    }

    auto find(const Key& key) {
        return _ops().find(_b(), _e(), key);
    }

    auto find(const Key& key) const {
        return _ops().find(_b(), _e(), key);
    }

    auto lower_bound(const Key& key) {
        return _ops().lower_bound(_b(), _e(), key);
    }

    auto lower_bound(const Key& key) const {
        return _ops().lower_bound(_b(), _e(), key);
    }

    auto upper_bound(const Key& key) {
        return _ops().upper_bound(_b(), _e(), key);
    }

    auto upper_bound(const Key& key) const {
        return _ops().upper_bound(_b(), _e(), key);
    }

    auto equal_range(const Key& key) {
        return _ops().equal_range(_b(), _e(), key);
    }

    auto equal_range(const Key& key) const {
        return _ops().equal_range(_b(), _e(), key);
    }

    Val& at(const Key& key) {
        return _ops().at(_b(), _e(), key);
    }

    const Val& at(const Key& key) const {
        return _ops().at(_b(), _e(), key);
    }
};
//------------------------------------------------------------------------------
template <
  typename Key,
  typename Val,
  typename Cmp = std::less<Key>,
  typename Allocator = std::allocator<std::pair<Key, Val>>>
class flat_map
  : public flat_map_view_crtp<
      Key,
      Val,
      Cmp,
      flat_map<Key, Val, Cmp, Allocator>> {
private:
    using _base =
      flat_map_view_crtp<Key, Val, Cmp, flat_map<Key, Val, Cmp, Allocator>>;
    using _base::_ops;

    using _alloc_t =
      typename Allocator::template rebind<std::pair<Key, Val>>::other;

    using _vec_t = std::vector<std::pair<Key, Val>, _alloc_t>;
    _vec_t _vec{};

    auto _find_insert_pos(const Key& k) noexcept {
        const auto b = _vec.begin();
        const auto e = _vec.end();
        const auto p = _ops().lower_bound(b, e, k);

        return std::pair{p, (p == e) || (k != p->first)};
    }

    template <typename I>
    auto _find_insert_pos(I p, const Key& k) {
        auto b = _vec.begin();
        auto e = _vec.end();
        if(p == e) {
            if(_vec.empty() || value_comp()(_vec.back(), k)) {
                return std::pair{p, true};
            }
            p = _ops().lower_bound(b, e, k);
        }
        if(k == p->first) {
            return std::pair{p, false};
        }
        if(key_comp()(k, p->first)) {
            if(p != b) {
                p = _ops().lower_bound(b, p, k);
            }
        } else {
            p = _ops().lower_bound(p, e, k);
        }
        return std::pair{p, true};
    }

    template <typename I, typename... Args>
    I _do_emplace(I ip, const Key& key, Args&&... args) {
        if(ip.second) {
            ip.first =
              _vec.emplace(ip.first, key, Val{std::forward<Args>(args)...});
        }
        return ip;
    }

    template <typename I, typename V>
    I _do_insert(I ip, const V& value) {
        if(ip.second) {
            ip.first = _vec.insert(ip.first, value);
        }
        return ip;
    }

public:
    using typename _base::key_compare;
    using typename _base::key_type;
    using typename _base::mapped_type;
    using typename _base::value_type;
    using size_type = typename _vec_t::size_type;
    using difference_type = typename _vec_t::difference_type;
    using iterator = typename _vec_t::iterator;
    using const_iterator = typename _vec_t::const_iterator;
    using allocator_type = Allocator;

    using _base::key_comp;
    using _base::lower_bound;
    using _base::value_comp;

    flat_map() noexcept = default;
    flat_map(const flat_map&) = default;
    flat_map(flat_map&&) noexcept = default;
    flat_map& operator=(const flat_map&) = default;
    flat_map& operator=(flat_map&&) noexcept = default;
    ~flat_map() noexcept = default;

    flat_map(std::initializer_list<std::pair<Key, Val>> il) {
        assign(il);
    }

    flat_map(const std::vector<value_type>& v) {
        assign(v);
    }

    void assign(std::initializer_list<std::pair<Key, Val>> il) {
        _vec = _vec_t(il);
        std::sort(_vec.begin(), _vec.end(), value_comp());
    }

    void assign(const std::vector<value_type>& v) {
        _vec = _vec_t(v.begin(), v.end());
        std::sort(_vec.begin(), _vec.end(), value_comp());
    }

    bool empty() const {
        return _vec.empty();
    }

    size_type size() const {
        return _vec.size();
    }

    size_type max_size() const {
        return _vec.max_size();
    }

    void reserve(size_type sz) {
        _vec.reserve(sz);
    }

    void clear() {
        _vec.clear();
    }

    iterator begin() {
        return _vec.begin();
    }

    const_iterator begin() const {
        return _vec.begin();
    }

    iterator end() {
        return _vec.end();
    }

    const_iterator end() const {
        return _vec.end();
    }

    auto& operator[](const Key& key) {
        auto ip = _find_insert_pos(key);
        ip = _do_emplace(ip, key);
        return ip.first->second;
    }

    template <typename... Args>
    std::pair<iterator, bool> emplace(const Key& key, Args&&... args) {
        auto ip = _find_insert_pos(key);
        ip = _do_emplace(ip, key, std::forward<Args>(args)...);
        return {ip.first, ip.second};
    }

    std::pair<iterator, bool> insert(const value_type& value) {
        auto ip = _find_insert_pos(value.first);
        ip = _do_insert(ip, value);
        return {ip.first, ip.second};
    }

    iterator insert(iterator p, const value_type& value) {
        const auto ip = _find_insert_pos(p, value.first);
        return _do_insert(ip, value).first;
    }

    iterator erase(iterator p) {
        return _vec.erase(p);
    }

    iterator erase(iterator f, iterator t) {
        return _vec.erase(f, t);
    }

    size_type erase(const Key& key) {
        const auto p = _ops().equal_range(_vec.begin(), _vec.end(), key);
        const auto res = size_type(std::distance(p.first, p.second));
        EAGINE_ASSERT(res <= 1);
        _vec.erase(p.first, p.second);
        return res;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_FLAT_MAP_HPP
