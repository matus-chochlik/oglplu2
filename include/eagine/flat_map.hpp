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

#include "types.hpp"
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <vector>

namespace eagine {

template <typename Key, typename Val, typename Cmp>
struct flat_map_ops {
    using value_type = std::pair<const Key, Val>;
    struct value_compare {
        Cmp key_comp;
        bool operator()(const value_type& a, const value_type& b) const {
            return key_comp(a.first, b.first);
        }

        bool operator()(const value_type& a, const Key& b) const {
            return key_comp(a.first, b);
        }

        bool operator()(const Key& a, const value_type& b) const {
            return key_comp(a, b.first);
        }
    } value_comp;

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
        return ::std::lower_bound(b, e, key, value_comp);
    }

    template <typename I>
    auto upper_bound(I b, I e, const Key& key) const noexcept {
        return ::std::upper_bound(b, e, key, value_comp);
    }

    template <typename I>
    auto equal_range(I b, I e, const Key& key) const noexcept {
        return ::std::equal_range(b, e, key, value_comp);
    }

    template <typename I>
    auto find(I b, I e, const Key& key) const noexcept {
        b = lower_bound(b, e, key);
        if((b != e) && value_comp.key_comp(b->first, key)) {
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
    auto& get(I b, I e, const Key& key) const {
        b = find(b, e, key);
        assert(b != e);
        return b->second;
    }
};

template <typename Key, typename Val, typename Cmp, typename Derived>
class flat_map_view_crtp {
private:
    const Derived& _self() const {
        return *static_cast<const Derived*>(this);
    }

    Derived& _self() {
        return *static_cast<Derived*>(this);
    }

    auto _b() const {
        return _self().begin();
    }
    auto _b() {
        return _self().begin();
    }

    auto _e() const {
        return _self().end();
    }
    auto _e() {
        return _self().end();
    }

protected:
    using _ops_t = flat_map_ops<Key, Val, Cmp>;
    _ops_t _ops;

public:
    using key_type = Key;
    using mapped_type = Val;
    using value_type = std::pair<const Key, Val>;
    using reference = value_type&;
    using const_reference = const value_type&;

    using key_compare = Cmp;
    using value_compare = typename _ops_t::value_compare;

    const key_compare& key_comp() const {
        return _ops.value_comp.key_comp;
    }

    const value_compare& value_comp() const {
        return _ops.value_comp;
    }

    bool empty() const {
        return _ops.empty(_b(), _e());
    }

    auto size() const {
        return _ops.size(_b(), _e());
    }

    auto find(const Key& key) {
        return _ops.find(_b(), _e(), key);
    }

    auto find(const Key& key) const {
        return _ops.find(_b(), _e(), key);
    }

    auto lower_bound(const Key& key) {
        return _ops.lower_bound(_b(), _e(), key);
    }

    auto lower_bound(const Key& key) const {
        return _ops.lower_bound(_b(), _e(), key);
    }

    auto upper_bound(const Key& key) {
        return _ops.upper_bound(_b(), _e(), key);
    }

    auto upper_bound(const Key& key) const {
        return _ops.upper_bound(_b(), _e(), key);
    }

    auto equal_range(const Key& key) {
        return _ops.equal_range(_b(), _e(), key);
    }

    auto equal_range(const Key& key) const {
        return _ops.equal_range(_b(), _e(), key);
    }

    Val& at(const Key& key) {
        return _ops.at(_b(), _e(), key);
    }

    const Val& at(const Key& key) const {
        return _ops.at(_b(), _e(), key);
    }
};

template <
  typename Key,
  typename Val,
  typename Cmp = std::less<Key>,
  typename Allocator = std::allocator<std::pair<const Key, Val>>>
class flat_map
  : public flat_map_view_crtp<
      Key,
      Val,
      Cmp,
      flat_map<Key, Val, Cmp, Allocator>> {
private:
    using _base =
      flat_map_view_crtp<Key, Val, Cmp, flat_map<Key, Val, Cmp, Allocator>>;

    using _cvec_t = std::vector<std::pair<const Key, Val>, Allocator>;
    using _vec_t = std::vector<std::pair<Key, Val>, Allocator>;
    _vec_t _vec;

    typename _cvec_t::const_iterator _cast(typename _vec_t::const_iterator i) {
        return *reinterpret_cast<typename _cvec_t::const_iterator*>(&i);
    }

    typename _cvec_t::iterator _cast(typename _vec_t::iterator i) {
        return *reinterpret_cast<typename _cvec_t::iterator*>(&i);
    }

    typename _vec_t::const_iterator _cast(typename _cvec_t::const_iterator i) {
        return *reinterpret_cast<typename _vec_t::const_iterator*>(&i);
    }

    typename _vec_t::iterator _cast(typename _cvec_t::iterator i) {
        return *reinterpret_cast<typename _vec_t::iterator*>(&i);
    }

    std::pair<typename _vec_t::iterator, bool> _find_insert_pos(const Key& k) {
        typename _vec_t::iterator b = _vec.begin();
        typename _vec_t::iterator e = _vec.end();
        auto p = this->_ops.lower_bound(b, e, k);

        return {p, (p == e) || (k != p->first)};
    }

    std::pair<typename _vec_t::iterator, bool> _find_insert_pos(
      typename _vec_t::iterator p, const Key& k) {
        typename _vec_t::iterator b = _vec.begin();
        typename _vec_t::iterator e = _vec.end();
        if(p == e) {
            if(_vec.empty() || value_comp()(_vec.back(), k)) {
                return {p, true};
            }
            p = this->_ops.lower_bound(b, e, k);
        }
        if(k == p->first) {
            return {p, false};
        }
        if(key_comp()(k, p->first)) {
            if(p != b) {
                p = this->_ops.lower_bound(b, p, k);
            }
        } else {
            p = this->_ops.lower_bound(p, e, k);
        }
        return {p, true};
    }

    std::pair<typename _vec_t::iterator, bool> _do_insert(
      std::pair<typename _vec_t::iterator, bool> ip,
      const typename _base::value_type& value) {
        if(ip.second) {
            ip.first = _vec.insert(ip.first, value);
        } else {
            ip.first->second = value.second;
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
    using iterator = typename _cvec_t::iterator;
    using const_iterator = typename _cvec_t::const_iterator;
    using allocator_type = Allocator;

    using _base::key_comp;
    using _base::lower_bound;
    using _base::value_comp;

    flat_map() = default;
    flat_map(const flat_map&) = default;
    flat_map(flat_map&&) = default;
    flat_map& operator=(const flat_map&) = default;
    flat_map& operator=(flat_map&&) = default;

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
        return _cast(_vec.begin());
    }

    const_iterator begin() const {
        return _cast(_vec.begin());
    }

    iterator end() {
        return _cast(_vec.end());
    }

    const_iterator end() const {
        return _cast(_vec.end());
    }

    std::pair<iterator, bool> insert(const value_type& value) {
        auto ip = _find_insert_pos(value.first);
        ip = _do_insert(ip, value);
        return {_cast(ip.first), ip.second};
    }

    iterator insert(iterator p, const value_type& value) {
        auto ip = _find_insert_pos(_cast(p), value.first);
        return _cast(_do_insert(ip, value).first);
    }

    iterator erase(iterator p) {
        return _cast(_vec.erase(_cast(p)));
    }

    iterator erase(iterator f, iterator t) {
        return _cast(_vec.erase(_cast(f), _cast(t)));
    }

    size_type erase(const Key& key) {
        auto p = this->_ops.equal_range(_vec.begin(), _vec.end(), key);
        _vec.erase(p.first, p.second);
        return size_type(std::distance(p.first, p.second));
    }
};

} // namespace eagine

#endif // EAGINE_FLAT_MAP_HPP
