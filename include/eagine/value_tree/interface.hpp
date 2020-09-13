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
    attribute_interface& operator=(attribute_interface&&) noexcept = default;
    attribute_interface& operator=(const attribute_interface&) = default;
    virtual ~attribute_interface() noexcept = default;

    virtual identifier_t type_id() const noexcept = 0;
};
//------------------------------------------------------------------------------
struct compound_interface {
    compound_interface() noexcept = default;
    compound_interface(compound_interface&&) = delete;
    compound_interface(const compound_interface&) = delete;
    compound_interface& operator=(compound_interface&&) = delete;
    compound_interface& operator=(const compound_interface&) = delete;
    virtual ~compound_interface() noexcept = default;

    virtual identifier_t type_id() const noexcept = 0;
    virtual void add_ref(attribute_interface&) noexcept = 0;
    virtual void release(attribute_interface&) noexcept = 0;

    virtual attribute_interface* structure() = 0;

    virtual string_view attribute_name(attribute_interface&) = 0;

    virtual span_size_t nested_count(attribute_interface&) = 0;

    virtual attribute_interface*
    nested(attribute_interface&, span_size_t index) = 0;

    virtual attribute_interface*
    nested(attribute_interface&, string_view name) = 0;

    virtual attribute_interface*
    find(attribute_interface&, const basic_string_path&) = 0;

    virtual span_size_t value_count(attribute_interface&) = 0;

    virtual span_size_t
    fetch_values(attribute_interface&, span_size_t offset, span<bool> dest) = 0;

    virtual span_size_t
    fetch_values(attribute_interface&, span_size_t offset, span<byte> dest) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::int16_t> dest) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::int32_t> dest) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::int64_t> dest) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::uint16_t> dest) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::uint32_t> dest) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::uint64_t> dest) = 0;

    virtual span_size_t
    fetch_values(attribute_interface&, span_size_t offset, span<float> dest) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::chrono::duration<float>> dest) = 0;

    virtual span_size_t fetch_values(
      attribute_interface&,
      span_size_t offset,
      span<std::string> dest) = 0;
};
//------------------------------------------------------------------------------
template <typename Derived>
class compound_implementation : public compound_interface {
private:
    Derived& derived() noexcept {
        return *static_cast<Derived*>(this);
    }

public:
    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<bool> dest) final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<byte> dest) final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::int16_t> dest) final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::int32_t> dest) final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::int64_t> dest) final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::uint16_t> dest) final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::uint32_t> dest) final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::uint64_t> dest) final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<float> dest) final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::chrono::duration<float>> dest) final {
        return derived().do_fetch_values(attrib, offset, dest);
    }

    span_size_t fetch_values(
      attribute_interface& attrib,
      span_size_t offset,
      span<std::string> dest) final {
        return derived().do_fetch_values(attrib, offset, dest);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::valtree

#endif // EAGINE_VALUE_TREE_INTERFACE_HPP
