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

#include "../identifier_t.hpp"
#include "../string_path.hpp"
#include "../string_span.hpp"
#include <chrono>
#include <cstdint>
#include <memory>
#include <string>

namespace eagine::valtree {
//------------------------------------------------------------------------------
struct compound_interface;
struct attribute_interface {
    attribute_interface() noexcept = default;
    attribute_interface(attribute_interface&&) noexcept = default;
    attribute_interface(const attribute_interface&) = default;
    auto operator=(attribute_interface&&) = delete;
    auto operator=(const attribute_interface&) = delete;
    virtual ~attribute_interface() noexcept = default;

    virtual auto type_id() const noexcept -> identifier_t = 0;
};
//------------------------------------------------------------------------------
struct compound_interface {
    compound_interface() noexcept = default;
    compound_interface(compound_interface&&) = delete;
    compound_interface(const compound_interface&) = delete;
    auto operator=(compound_interface&&) = delete;
    auto operator=(const compound_interface&) = delete;
    virtual ~compound_interface() noexcept = default;

    virtual auto type_id() const noexcept -> identifier_t = 0;
    virtual void add_ref(attribute_interface&) noexcept = 0;
    virtual void release(attribute_interface&) noexcept = 0;

    virtual auto structure() -> attribute_interface* = 0;

    virtual auto attribute_name(attribute_interface&) -> string_view = 0;

    virtual auto nested_count(attribute_interface&) -> span_size_t = 0;

    virtual auto nested(attribute_interface&, span_size_t index)
      -> attribute_interface* = 0;

    virtual auto nested(attribute_interface&, string_view name)
      -> attribute_interface* = 0;

    virtual auto find(attribute_interface&, const basic_string_path&)
      -> attribute_interface* = 0;

    virtual auto value_count(attribute_interface&) -> span_size_t = 0;

    virtual auto
    fetch_values(attribute_interface&, span_size_t offset, span<bool> dest)
      -> span_size_t = 0;

    virtual auto
    fetch_values(attribute_interface&, span_size_t offset, span<byte> dest)
      -> span_size_t = 0;

    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::int16_t> dest) -> span_size_t = 0;

    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::int32_t> dest) -> span_size_t = 0;

    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::int64_t> dest) -> span_size_t = 0;

    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::uint16_t> dest) -> span_size_t = 0;

    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::uint32_t> dest) -> span_size_t = 0;

    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::uint64_t> dest) -> span_size_t = 0;

    virtual auto
    fetch_values(attribute_interface&, span_size_t offset, span<float> dest)
      -> span_size_t = 0;

    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::chrono::duration<float>> dest) -> span_size_t = 0;

    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::string> dest) -> span_size_t = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine::valtree

#endif // EAGINE_VALUE_TREE_INTERFACE_HPP
