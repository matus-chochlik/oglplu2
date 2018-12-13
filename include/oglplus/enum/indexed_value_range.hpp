/**
 *  @file oglplus/enum/indexed_value_range.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ENUM_INDEXED_VALUE_RANGE_1509260923_HPP
#define OGLPLUS_ENUM_INDEXED_VALUE_RANGE_1509260923_HPP

#include "../utils/indexed_enum.hpp"
#include "../utils/limited_value.hpp"
#include <eagine/iterator.hpp>
#include <cassert>

namespace oglplus {

template <typename LimitedValue>
class limited_value_range;

template <GLenum Query, GLenum Base>
class limited_value_range<limited_value<Query, indexed_enum_value<Base>>> {
private:
    GLenum _limit;

    using _lv_t = limited_value<Query, indexed_enum_value<Base>>;

    static _lv_t _wrap_enum(GLenum e) noexcept {
        return _lv_t{e};
    }

public:
    using value_type = _lv_t;
    using size_type = span_size_t;

    limited_value_range(_lv_t limit) noexcept
      : _limit(GLenum(limit)) {
        assert(Base <= _limit);
    }

    limited_value_range()
      : limited_value_range(get_limit(identity<_lv_t>()).value()) {
    }

    using iterator = eagine::transforming_iterator<
      eagine::selfref_iterator<GLenum>,
      _lv_t,
      _lv_t,
      _lv_t (*)(GLenum) noexcept>;

    size_type size() const noexcept {
        return _limit - Base;
    }

    iterator begin() const noexcept {
        return iterator(Base, &_wrap_enum);
    }

    iterator end() const noexcept {
        return iterator(_limit, &_wrap_enum);
    }
};

template <
  typename LimitedValue,
  typename = std::enable_if_t<is_limited_value<LimitedValue>::value>>
static inline limited_value_range<LimitedValue> enum_value_range() {
    return {};
}

} // namespace oglplus

#endif // include guard
