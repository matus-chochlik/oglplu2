/**
 *  @file eagine/enum_range.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ENUM_RANGE_HPP
#define EAGINE_ENUM_RANGE_HPP

#include "enum_class.hpp"
#include "iterator.hpp"
#include "memory/span.hpp"
#include <cassert>
#include <cstdint>
#include <utility>

namespace eagine {
//------------------------------------------------------------------------------
template <typename EnumClass>
class enumerated_value_range;
//------------------------------------------------------------------------------
template <typename EnumClass, typename T, unsigned LibId, unsigned EnumId>
class enumerated_value_range<enum_class<EnumClass, T, LibId, EnumId>> {
private:
    const T* _begin;
    const T* _end;

    using _ec_t = enum_class<EnumClass, T, LibId, EnumId>;

    static _ec_t _wrap_enum(T e) noexcept {
        return _ec_t{e};
    }

public:
    using value_type = _ec_t;
    using size_type = span_size_t;

    explicit enumerated_value_range(memory::span<const T> v) noexcept
      : _begin(v.data())
      , _end(v.data() + v.size()) {
        assert(_begin <= _end);
    }

    explicit enumerated_value_range(
      std::pair<const void*, size_type> p) noexcept
      : enumerated_value_range(
          memory::span<const T>{static_cast<const T*>(p.first), p.second}) {
    }

    using iterator =
      transforming_iterator<const T*, _ec_t, _ec_t, _ec_t (*)(T) noexcept>;

    size_type size() const noexcept {
        return size_type(_end - _begin);
    }

    iterator begin() const noexcept {
        return iterator(_begin, &_wrap_enum);
    }

    iterator end() const noexcept {
        return iterator(_end, &_wrap_enum);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_ENUM_RANGE_HPP
