/**
 *  @file eagine/from_string.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_FROM_STRING_HPP
#define EAGINE_FROM_STRING_HPP

#include "identity.hpp"
#include "is_within_limits.hpp"
#include "memory/span_algo.hpp"
#include "string_span.hpp"
#include "valid_if/decl.hpp"
#include <cstdlib>
#include <iostream>

namespace eagine {

static inline optionally_valid<bool> from_string(
  string_view src, identity<bool>) noexcept {

    const string_view true_strs[] = {{"true"}, {"True"}, {"1"}, {"t"}, {"T"}};
    if(find_element(view(true_strs), src)) {
        return {true, true};
    }

    const string_view false_strs[] = {
      {"false"}, {"False"}, {"0"}, {"f"}, {"F"}};
    if(find_element(view(false_strs), src)) {
        return {false, true};
    }

    return {};
}

static inline optionally_valid<char> from_string(
  string_view src, identity<char>) noexcept {
    if(src.size() == 1) {
        return {extract(src), true};
    }
    return {};
}

template <typename T, typename N>
optionally_valid<T> convert_from_string_with(
  N (*converter)(const char*, char**), string_view src, identity<T>) noexcept {
    char* end = nullptr;
    auto cstr = c_str(src);
    errno = 0;
    const N result = converter(cstr, &end);
    if(
      (errno != ERANGE) && (end != cstr) && (end != nullptr) &&
      (*end == '\0')) {
        return convert_if_fits<T>(result);
    }
    return {};
}

template <typename T, typename N>
optionally_valid<T> convert_from_string_with(
  N (*converter)(const char*, char**, int),
  int base,
  string_view src,
  identity<T>) noexcept {
    char* end = nullptr;
    auto cstr = c_str(src);
    errno = 0;
    const N result = converter(cstr, &end, base);
    if(
      (errno != ERANGE) && (end != cstr) && (end != nullptr) &&
      (*end == '\0')) {
        return convert_if_fits<T>(result);
    }
    return {};
}

static inline optionally_valid<short> from_string(
  string_view src, identity<short> id, int base = 10) noexcept {
    return convert_from_string_with(&std::strtol, base, src, id);
}

static inline optionally_valid<int> from_string(
  string_view src, identity<int> id, int base = 10) noexcept {
    return convert_from_string_with(&std::strtol, base, src, id);
}

static inline optionally_valid<long> from_string(
  string_view src, identity<long> id, int base = 10) noexcept {
    return convert_from_string_with(&std::strtol, base, src, id);
}

static inline optionally_valid<long long> from_string(
  string_view src, identity<long long> id, int base = 10) noexcept {
    return convert_from_string_with(&std::strtoll, base, src, id);
}

static inline optionally_valid<unsigned short> from_string(
  string_view src, identity<unsigned short> id, int base = 10) noexcept {
    return convert_from_string_with(&std::strtoul, base, src, id);
}

static inline optionally_valid<unsigned int> from_string(
  string_view src, identity<unsigned int> id, int base = 10) noexcept {
    return convert_from_string_with(&std::strtoul, base, src, id);
}

static inline optionally_valid<unsigned long> from_string(
  string_view src, identity<unsigned long> id, int base = 10) noexcept {
    return convert_from_string_with(&std::strtoul, base, src, id);
}

static inline optionally_valid<unsigned long long> from_string(
  string_view src, identity<unsigned long long> id, int base = 10) noexcept {
    return convert_from_string_with(&std::strtoull, base, src, id);
}

static inline optionally_valid<float> from_string(
  string_view src, identity<float> id) noexcept {
    return convert_from_string_with(&std::strtof, src, id);
}

static inline optionally_valid<double> from_string(
  string_view src, identity<double> id) noexcept {
    return convert_from_string_with(&std::strtod, src, id);
}

static inline optionally_valid<long double> from_string(
  string_view src, identity<long double> id) noexcept {
    return convert_from_string_with(&std::strtold, src, id);
}

static inline optionally_valid<std::string> from_string(
  string_view src, identity<std::string>) noexcept {
    return to_string(src);
}

template <typename T>
optionally_valid<T> from_string(string_view src) noexcept {
    return from_string(src, identity<T>());
}

} // namespace eagine

#endif // EAGINE_FROM_STRING_HPP
