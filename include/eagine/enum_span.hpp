/**
 *  @file eagine/enum_span.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_ENUM_SPAN_HPP
#define EAGINE_ENUM_SPAN_HPP

#include "enum_class.hpp"
#include "span.hpp"
#include "types.hpp"
#include <algorithm>
#include <vector>

namespace eagine {

template <typename EnumClass>
class enum_list {
private:
    using value_type = typename EnumClass::value_type;
    std::vector<value_type> _values;

public:
    enum_list() = default;

    template <typename... EnumValues>
    constexpr enum_list(EnumValues... evs) noexcept
      : _values{{value_type(evs)...}} {}

    auto values() const noexcept {
        return view(_values);
    }
};

template <typename EnumClass>
struct enum_span : span<const typename EnumClass::value_type> {

    enum_span() = default;

    enum_span(const enum_list<EnumClass>& enums) noexcept
      : span<const typename EnumClass::value_type>(enums.values()) {}
};

} // namespace eagine

#endif // EAGINE_ENUM_SPAN_HPP
