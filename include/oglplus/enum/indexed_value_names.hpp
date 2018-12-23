/**
 *  @file oglplus/enum/indexed_value_names.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_ENUM_INDEXED_VALUE_NAMES_HPP
#define OGLPLUS_ENUM_INDEXED_VALUE_NAMES_HPP

#include "../config/basic.hpp"
#include "../utils/indexed_enum.hpp"
#include "../utils/string_span.hpp"
#include <string>

namespace oglplus {

std::string get_enum_value_name(const any_indexed_enum_value&) noexcept;

template <GLenum Base>
static inline std::string enum_value_name(
  indexed_enum_value<Base> val) noexcept {
    return ::oglplus::get_enum_value_name(val);
}

} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/enum/indexed_value_names.inl>
#endif

#endif // OGLPLUS_ENUM_INDEXED_VALUE_NAMES_HPP
