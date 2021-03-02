/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALUE_TREE_INTERFACE_HPP
#define EAGINE_VALUE_TREE_INTERFACE_HPP

#include "../identifier_t.hpp"
#include "../interface.hpp"
#include "../reflect/map_enumerators.hpp"
#include "../string_path.hpp"
#include "../string_span.hpp"
#include "../tags.hpp"
#include <chrono>
#include <cstdint>
#include <memory>
#include <string>

namespace eagine::valtree {
//------------------------------------------------------------------------------
/// @brief Value tree value element data type enumeration.
/// @ingroup valtree
enum class value_type {
    /// @brief Unknown value type.
    unknown,
    /// @brief Boolean value type.
    bool_type,
    /// @brief Byte/BLOB value type.
    byte_type,
    /// @brief 16-bit integer value type.
    int16_type,
    /// @brief 32-bit integer value type.
    int32_type,
    /// @brief 64-bit integer value type.
    int64_type,
    /// @brief floating-point number value type.
    float_type,
    /// @brief time duration value type.
    duration_type,
    /// @brief string value type.
    string_type,
    /// @brief composite structure type.
    composite
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto enumerator_mapping(type_identity<value_type>, Selector) noexcept {
    return enumerator_map_type<value_type, 10>{
      {{"unknown", value_type::unknown},
       {"bool_type", value_type::bool_type},
       {"byte_type", value_type::byte_type},
       {"int16_type", value_type::int16_type},
       {"int32_type", value_type::int32_type},
       {"int64_type", value_type::int64_type},
       {"float_type", value_type::float_type},
       {"duration_type", value_type::duration_type},
       {"string_type", value_type::string_type},
       {"composite", value_type::composite}}};
}
//------------------------------------------------------------------------------
struct compound_interface;

/// @brief Interfaca for value tree attribute implementations.
/// @ingroup valtree
/// @note Do not use directly in client code, use attribute instead.
/// @see attribute
/// @see compound_interface
struct attribute_interface : interface<attribute_interface> {

    /// @brief Returns the implementation type identifier of this attribute.
    virtual auto type_id() const noexcept -> identifier_t = 0;
};
//------------------------------------------------------------------------------
/// @brief Interfaca for value tree compound implementations.
/// @ingroup valtree
/// @note Do not use directly in client code, use compound instead.
/// @see compound
/// @see attribute_interface
struct compound_interface : interface<compound_interface> {

    /// @brief Returns the implementation type identifier of this compound.
    virtual auto type_id() const noexcept -> identifier_t = 0;

    /// @brief Add usage reference to the specified attribute.
    /// @pre this->type_id() == attr.type_id()
    virtual void add_ref(attribute_interface& attr) noexcept = 0;

    /// @brief Release usage reference to the specified attribute.
    /// @pre this->type_id() == attr.type_id()
    virtual void release(attribute_interface& attr) noexcept = 0;

    /// @brief Returns the root of attribute hierarch, describing the tree structure.
    virtual auto structure() -> attribute_interface* = 0;

    /// @brief Returns the name of the specified attribute.
    /// @pre this->type_id() == attr.type_id()
    virtual auto attribute_name(attribute_interface& attr) -> string_view = 0;

    /// @brief Returns the value type of the specified attribute.
    /// @pre this->type_id() == attr.type_id()
    virtual auto canonical_type(attribute_interface& attr) -> value_type = 0;

    /// @brief Indicates if the specified attribute is a reference or link in the tree.
    /// @pre this->type_id() == attr.type_id()
    virtual auto is_link(attribute_interface& attr) -> bool = 0;

    /// @brief Returns the count of nested attributes in an attribute.
    /// @pre this->type_id() == attr.type_id()
    virtual auto nested_count(attribute_interface& attr) -> span_size_t = 0;

    /// @brief Returns the nested attribute of an attribute at given @p index.
    /// @pre this->type_id() == attr.type_id()
    virtual auto nested(attribute_interface& attr, span_size_t index)
      -> attribute_interface* = 0;

    /// @brief Returns the nested attribute of an attribute with specified @p name.
    /// @pre this->type_id() == attr.type_id()
    virtual auto nested(attribute_interface&, string_view name)
      -> attribute_interface* = 0;

    /// @brief Finds the nested attribute of an attribute at the given @p path.
    /// @pre this->type_id() == attr.type_id()
    virtual auto find(attribute_interface& attr, const basic_string_path& path)
      -> attribute_interface* {
        return find(attr, path, {});
    }

    /// @brief Finds the nested attribute of an attribute at @p path with @p tags.
    /// @pre this->type_id() == attr.type_id()
    virtual auto find(
      attribute_interface& attr,
      const basic_string_path&,
      span<const string_view> tags) -> attribute_interface* = 0;

    /// @brief Returns the count of individual values stored in an attribute.
    /// @pre this->type_id() == attr.type_id()
    virtual auto value_count(attribute_interface& attr) -> span_size_t = 0;

    /// @brief Fetches boolean values from attribute into dest, starting at offset.
    virtual auto
    fetch_values(attribute_interface&, span_size_t offset, span<bool> dest)
      -> span_size_t = 0;

    /// @brief Fetches char values from attribute into dest, starting at offset.
    virtual auto
    fetch_values(attribute_interface&, span_size_t offset, span<char> dest)
      -> span_size_t = 0;

    /// @brief Fetches byte values from attribute into dest, starting at offset.
    virtual auto
    fetch_values(attribute_interface&, span_size_t offset, span<byte> dest)
      -> span_size_t = 0;

    /// @brief Fetches 16-bit int values from attribute into dest, starting at offset.
    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::int16_t> dest) -> span_size_t = 0;

    /// @brief Fetches 32-bit int values from attribute into dest, starting at offset.
    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::int32_t> dest) -> span_size_t = 0;

    /// @brief Fetches 64-bit int values from attribute into dest, starting at offset.
    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::int64_t> dest) -> span_size_t = 0;

    /// @brief Fetches 16-bit uint values from attribute into dest, starting at offset.
    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::uint16_t> dest) -> span_size_t = 0;

    /// @brief Fetches 32-bit uint values from attribute into dest, starting at offset.
    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::uint32_t> dest) -> span_size_t = 0;

    /// @brief Fetches 64-bit uint values from attribute into dest, starting at offset.
    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::uint64_t> dest) -> span_size_t = 0;

    /// @brief Fetches float values from attribute into dest, starting at offset.
    virtual auto
    fetch_values(attribute_interface&, span_size_t offset, span<float> dest)
      -> span_size_t = 0;

    /// @brief Fetches duration values from attribute into dest, starting at offset.
    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::chrono::duration<float>> dest) -> span_size_t = 0;

    /// @brief Fetches string values from attribute into dest, starting at offset.
    virtual auto fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::string> dest) -> span_size_t = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine::valtree

#endif // EAGINE_VALUE_TREE_INTERFACE_HPP
