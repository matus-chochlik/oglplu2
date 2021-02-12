/// @file eagine/flat_set.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_FLAT_SET_HPP
#define EAGINE_FLAT_SET_HPP

#include "assert.hpp"
#include "types.hpp"
#include <algorithm>
#include <stdexcept>
#include <utility>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
template <
  typename Key,
  typename Compare = std::less<Key>,
  class Allocator = std::allocator<Key>>
class flat_set : private Compare {

    using _vec_t = std::vector<Key, Allocator>;
    _vec_t _vec;

    auto _find_insert_pos(const Key& k) const noexcept {
        const auto b = _vec.begin();
        const auto e = _vec.end();
        const auto p = std::lower_bound(b, e, k, key_comp());

        return std::pair{p, (p == e) || (k != *p)};
    }

    template <typename I>
    auto _find_insert_pos(I p, const Key& k) const noexcept {
        auto b = _vec.begin();
        auto e = _vec.end();
        if(p == e) {
            if(_vec.empty() || value_comp()(_vec.back(), k)) {
                return std::pair{p, true};
            }
            p = std::lower_bound(b, e, k, key_comp());
        }
        if(k == *p) {
            return std::pair{p, false};
        }
        if(key_comp()(k, *p)) {
            if(p != b) {
                p = std::lower_bound(b, p, k, key_comp());
            }
        } else {
            p = std::lower_bound(p, e, k, key_comp());
        }
        return std::pair{p, true};
    }

    template <typename I>
    auto _do_insert(I ip, const Key& value) -> I {
        if(ip.second) {
            ip.first = _vec.insert(ip.first, value);
        }
        return ip;
    }

public:
    using key_type = Key;
    using value_type = Key;
    using size_type = typename _vec_t::size_type;
    using difference_type = typename _vec_t::difference_type;
    using iterator = typename _vec_t::const_iterator;
    using const_iterator = typename _vec_t::const_iterator;
    using allocator_type = Allocator;
    using reference = value_type&;
    using const_reference = const value_type&;

    flat_set() noexcept = default;
    flat_set(const flat_set&) = default;
    flat_set(flat_set&&) noexcept = default;
    auto operator=(const flat_set&) -> flat_set& = default;
    auto operator=(flat_set&&) noexcept -> flat_set& = default;
    ~flat_set() noexcept = default;

    flat_set(std::initializer_list<Key> il) {
        assign(il);
    }

    flat_set(const std::vector<value_type>& v) {
        assign(v);
    }

    void assign(std::initializer_list<Key> il) {
        _vec = _vec_t(il);
        std::sort(_vec.begin(), _vec.end(), value_comp());
    }

    void assign(const std::vector<value_type>& v) {
        _vec = _vec_t(v.begin(), v.end());
        std::sort(_vec.begin(), _vec.end(), value_comp());
    }

    auto key_comp() const noexcept -> const Compare& {
        return *this;
    }

    auto value_comp() const noexcept -> const Compare& {
        return *this;
    }

    auto empty() const noexcept {
        return _vec.empty();
    }

    auto size() const noexcept {
        return _vec.size();
    }

    auto max_size() const noexcept {
        return _vec.max_size();
    }

    auto begin() -> iterator {
        return _vec.begin();
    }

    auto begin() const -> const_iterator {
        return _vec.begin();
    }

    auto end() -> iterator {
        return _vec.end();
    }

    auto end() const -> const_iterator {
        return _vec.end();
    }

    auto lower_bound(const Key& key) const noexcept {
        return ::std::lower_bound(begin(), end(), key, value_comp());
    }

    auto upper_bound(const Key& key) const noexcept {
        return ::std::upper_bound(begin(), end(), key, value_comp());
    }

    auto equal_range(const Key& key) const noexcept {
        return ::std::equal_range(begin(), end(), key, value_comp());
    }

    auto find(const Key& key) const noexcept {
        auto [p, i] = _find_insert_pos(key);
        return i ? _vec.end() : p;
    }

    auto contains(const Key& key) const noexcept {
        return !_find_insert_pos(key).second;
    }

    auto clear() noexcept {
        _vec.clear();
    }

    auto insert(const value_type& value) -> std::pair<iterator, bool> {
        auto ip = _find_insert_pos(value);
        ip = _do_insert(ip, value);
        return {ip.first, ip.second};
    }

    auto insert(iterator p, const value_type& value) -> iterator {
        const auto ip = _find_insert_pos(p, value);
        return _do_insert(ip, value).first;
    }

    auto erase(iterator p) -> iterator {
        return _vec.erase(p);
    }

    auto erase(iterator f, iterator t) -> iterator {
        return _vec.erase(f, t);
    }

    auto erase(const Key& key) -> size_type {
        const auto p =
          std::equal_range(_vec.begin(), _vec.end(), key, key_comp());
        const auto res = size_type(std::distance(p.first, p.second));
        EAGINE_ASSERT(res <= 1);
        _vec.erase(p.first, p.second);
        return res;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif
