/**
 *  @file eagine/object/names.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OBJECT_NAMES_1509260923_HPP
#define EAGINE_OBJECT_NAMES_1509260923_HPP

#include "../iterator.hpp"
#include "../range_types.hpp"
#include "name.hpp"
#include <algorithm>
#include <array>
#include <cassert>
#include <vector>

namespace eagine {

template <typename ObjTag, typename Iterator>
class object_name_const_iterator {
private:
    Iterator _iter;
    object_name<ObjTag> _name;

public:
    object_name_const_iterator() = default;

    object_name_const_iterator(Iterator iter) noexcept
      : _iter(iter) {
    }

    typedef object_name<ObjTag> value_type;
    typedef const object_name<ObjTag>& reference;

    void swap(object_name_const_iterator& that) noexcept {
        using std::swap;
        swap(_iter, that._iter);
        swap(_name, that._name);
    }

    object_name_const_iterator& operator++() {
        ++_iter;
        return *this;
    }

    reference operator*() {
        _name = object_name<ObjTag>(*_iter);
        return _name;
    }

    friend inline bool operator==(
      const object_name_const_iterator& a,
      const object_name_const_iterator& b) noexcept {
        return a._iter == b._iter;
    }

    friend inline bool operator!=(
      const object_name_const_iterator& a,
      const object_name_const_iterator& b) noexcept {
        return a._iter != b._iter;
    }

    friend inline bool operator<(
      const object_name_const_iterator& a,
      const object_name_const_iterator& b) noexcept {
        return a._iter < b._iter;
    }
};

template <typename ObjTag, typename Container>
class object_name_container {
private:
    typedef object_traits<ObjTag> _traits;
    Container _names;

    static void _invalidate_names(Container& names) {
        using std::begin;
        using std::end;
        using std::fill;
        fill(begin(names), end(names), _traits::invalid_name());
    }

    auto _release_names() noexcept {
        Container names = std::move(_names);
        _invalidate_names(_names);
        return names;
    }

public:
    object_name_container() noexcept {
        _invalidate_names(_names);
    }

    object_name_container(const object_name_container&) = default;
    object_name_container& operator=(const object_name_container&) = default;

    object_name_container(object_name_container&& temp) noexcept
      : _names(temp._release_names()) {
    }

    object_name_container& operator=(object_name_container&& temp) noexcept {
        swap(temp, *this);
        return *this;
    }

    void swap(object_name_container& that) noexcept {
        std::swap(this->_names, that._names);
    }

    bool empty() const noexcept {
        return _names.empty();
    }

    span_size_t size() const noexcept {
        return span_size(_names.size());
    }

    object_name<ObjTag> operator[](span_size_t index) const noexcept {
        const auto i = range_index<Container>(index);
        return object_name<ObjTag>(_names[i]);
    }

    object_name<ObjTag> at(span_size_t index) const noexcept {
        const auto i = range_index<Container>(index);
        return object_name<ObjTag>(_names.at(i));
    }

    typedef object_name_const_iterator<
      ObjTag,
      typename Container::const_iterator>
      iterator;

    iterator begin() const noexcept {
        return _names.begin();
    }

    iterator end() const noexcept {
        return _names.end();
    }

    friend inline constexpr typename _traits::name_type
    get_raw_name(const object_name_container& ctr) noexcept {
        assert(ctr._names.size() > 0);
        return *ctr._names.data();
    }

    friend inline span<typename _traits::name_type>
    get_raw_names(object_name_container& ctr) noexcept {
        return {ctr._names};
    }

    friend inline span<const typename _traits::name_type>
    get_raw_names(const object_name_container& ctr) noexcept {
        return {ctr._names};
    }
};

template <typename NameT>
class object_name_base_and_count_view {
private:
    NameT* _pbase;
    span_size_t _size;

public:
    constexpr object_name_base_and_count_view(
      NameT& base, span_size_t count) noexcept
      : _pbase(&base)
      , _size(count) {
    }

    NameT base() const noexcept {
        assert(_pbase);
        return *_pbase;
    }

    void base(NameT name) noexcept {
        assert(_pbase);
        *_pbase = name;
    }

    span_size_t size() const noexcept {
        return _size;
    }
};

template <typename ObjTag>
class object_name_fake_array {
private:
    typedef object_traits<ObjTag> _traits;
    typedef object_name_t<ObjTag> _name_type;

    _name_type _base;
    span_size_t _size;

public:
    constexpr object_name_fake_array() noexcept
      : _base(_traits::invalid_name())
      , _size(0) {
    }

    constexpr object_name_fake_array(span_size_t count) noexcept
      : _base(_traits::invalid_name())
      , _size(count) {
    }

    void swap(object_name_fake_array& that) noexcept {
        std::swap(this->_base, that._base);
        std::swap(this->_size, that._size);
    }

    bool empty() const noexcept {
        return !(_size > 0);
    }

    span_size_t size() const noexcept {
        return _size;
    }

    object_name<ObjTag> operator[](span_size_t index) const noexcept {
        assert(index < size());
        return object_name<ObjTag>(_name_type(_base + index));
    }

    object_name<ObjTag> at(span_size_t index) const noexcept {
        if(!(index < size())) {
            throw std::out_of_range(
              "Index exceeds object_name_fake_array bounds.");
        }
        return object_name<ObjTag>(_name_type(_base + index));
    }

    typedef noexcept_casting_iterator<
      selfref_iterator<_name_type>,
      const object_name<ObjTag>,
      object_name<ObjTag>>
      iterator;

    iterator begin() const noexcept {
        return iterator(_base);
    }

    iterator end() const noexcept {
        return iterator(_name_type(_base + _size));
    }

    friend inline constexpr typename _traits::name_type
    get_raw_name(const object_name_fake_array& onfa) noexcept {
        assert(onfa.size() > 0);
        return onfa._base;
    }

    friend inline object_name_base_and_count_view<_name_type>
    get_raw_names(object_name_fake_array& onfa) noexcept {
        return {onfa._base, onfa._size};
    }
};

template <typename ObjTag, std::size_t N>
class object_names<ObjTag, std::array<object_name_t<ObjTag>, N>>
  : public object_name_container<ObjTag, std::array<object_name_t<ObjTag>, N>> {
public:
    using object_name_container<ObjTag, std::array<object_name_t<ObjTag>, N>>::
      object_name_container;
};

template <typename ObjTag, std::size_t N>
using object_name_array =
  object_names<ObjTag, std::array<object_name_t<ObjTag>, N>>;

template <typename ObjTag>
using object_name_vector =
  object_names<ObjTag, std::vector<object_name_t<ObjTag>>>;

} // namespace eagine

#endif // include guard
