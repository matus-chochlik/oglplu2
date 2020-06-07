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

#include "../callable_ref.hpp"
#include "../string_path.hpp"
#include "../string_span.hpp"
#include <memory>

namespace eagine {
namespace valtree {
//------------------------------------------------------------------------------
struct attribute_interface {
    attribute_interface() noexcept = default;
    attribute_interface(attribute_interface&&) = delete;
    attribute_interface(const attribute_interface&) = delete;
    attribute_interface& operator=(attribute_interface&&) = delete;
    attribute_interface& operator=(const attribute_interface&) = delete;
    virtual ~attribute_interface() noexcept = default;

    virtual string_view name() = 0;
    virtual span_size_t nested_count() = 0;
    virtual std::shared_ptr<attribute_interface> nested(span_size_t index) = 0;
    virtual std::shared_ptr<attribute_interface> find(
      const basic_string_path&) = 0;
};
//------------------------------------------------------------------------------
struct compound_interface {
    compound_interface() noexcept = default;
    compound_interface(compound_interface&&) = delete;
    compound_interface(const compound_interface&) = delete;
    compound_interface& operator=(compound_interface&&) = delete;
    compound_interface& operator=(const compound_interface&) = delete;
    virtual ~compound_interface() noexcept = default;

    virtual std::shared_ptr<attribute_interface> structure() = 0;

    virtual span_size_t value_count(
      const std::shared_ptr<attribute_interface>&) = 0;

    using fetch_strings_handler =
      callable_ref<void(span_size_t, span<const string_view>)>;

    virtual span_size_t fetch_strings(
      const std::shared_ptr<attribute_interface>&,
      span_size_t offset,
      span_size_t size,
      fetch_strings_handler handler) = 0;
};
//------------------------------------------------------------------------------
} // namespace valtree
} // namespace eagine

#endif // EAGINE_VALUE_TREE_INTERFACE_HPP
