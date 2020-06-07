/**
 *  @file eagine/value_tree/interface.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_VALUE_TREE_INTERFACE_HPP
#define EAGINE_VALUE_TREE_INTERFACE_HPP

#include "../string_path.hpp"
#include "../string_span.hpp"
#include <cstdint>
#include <memory>
#include <string>

namespace eagine {
namespace valtree {
//------------------------------------------------------------------------------
struct compound_interface;
struct attribute_interface {
    attribute_interface() noexcept = default;
    attribute_interface(attribute_interface&&) noexcept = default;
    attribute_interface(const attribute_interface&) = default;
    attribute_interface& operator=(attribute_interface&&) noexcept = default;
    attribute_interface& operator=(const attribute_interface&) = default;
    virtual ~attribute_interface() noexcept = default;

    virtual string_view name(compound_interface&) = 0;

    virtual span_size_t nested_count(compound_interface&) = 0;

    virtual attribute_interface* nested(
      compound_interface&, span_size_t index) = 0;

    virtual attribute_interface* find(
      compound_interface&, const basic_string_path&) = 0;
};
//------------------------------------------------------------------------------
struct compound_interface {
    compound_interface() noexcept = default;
    compound_interface(compound_interface&&) = delete;
    compound_interface(const compound_interface&) = delete;
    compound_interface& operator=(compound_interface&&) = delete;
    compound_interface& operator=(const compound_interface&) = delete;
    virtual ~compound_interface() noexcept = default;

    virtual attribute_interface* structure() = 0;

    virtual void add_ref(attribute_interface&) noexcept = 0;
    virtual void release(attribute_interface&) noexcept = 0;

    virtual span_size_t value_count(attribute_interface&) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&, span_size_t offset, span<std::int16_t> dest) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&, span_size_t offset, span<std::int32_t> dest) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&, span_size_t offset, span<std::int64_t> dest) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&, span_size_t offset, span<float> dest) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&, span_size_t offset, span<std::string> dest) = 0;
};
//------------------------------------------------------------------------------
} // namespace valtree
} // namespace eagine

#endif // EAGINE_VALUE_TREE_INTERFACE_HPP
