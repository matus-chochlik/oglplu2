/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_COMPILER_INFO_HPP
#define EAGINE_COMPILER_INFO_HPP

#include "serialize/fwd.hpp"
#include "string_span.hpp"
#include "valid_if/nonnegative.hpp"
#include "valid_if/not_empty.hpp"
#include <tuple>

namespace eagine {

auto architecture_name() noexcept -> valid_if_not_empty<string_view>;
auto compiler_name() noexcept -> valid_if_not_empty<string_view>;
auto compiler_version_major() noexcept -> valid_if_nonnegative<int>;
auto compiler_version_minor() noexcept -> valid_if_nonnegative<int>;
auto compiler_version_patch() noexcept -> valid_if_nonnegative<int>;

/// @brief Class providing compiler and architecture information.
/// @ingroup main_context
class compiler_info {
    friend struct serializer<compiler_info>;
    friend struct deserializer<compiler_info>;

    // arch. name, compiler name, compiler version numbers
    using _data_tuple =
      std::tuple<std::string, std::string, std::tuple<int, int, int>>;

public:
    /// @brief Default constructor, populates the class with detected values.
    compiler_info() noexcept
      : compiler_info{_data_tuple{
          to_string(eagine::architecture_name().value_anyway()),
          to_string(eagine::compiler_name().value_anyway()),
          {compiler_version_major().value_anyway(),
           compiler_version_minor().value_anyway(),
           compiler_version_patch().value_anyway()}}} {}

    compiler_info(nothing_t) noexcept {}

    /// @brief Returns the architecture name.
    /// @see name
    auto architecture_name() const noexcept -> valid_if_not_empty<string_view> {
        return {std::get<0>(_data)};
    }

    /// @brief Returns the compiler name.
    /// @see architecture_name
    auto name() const noexcept -> valid_if_not_empty<string_view> {
        return {std::get<1>(_data)};
    }

    /// @brief Returns the compiler version numbers in a single tuple.
    /// @see name
    /// @see version_major
    /// @see version_minor
    /// @see version_patch
    auto version_tuple() const noexcept -> const std::tuple<int, int, int>& {
        return std::get<2>(_data);
    }

    /// @brief Returns the compiler major version number.
    /// @see name
    /// @see version_tuple
    /// @see version_minor
    /// @see version_patch
    auto version_major() const noexcept -> valid_if_nonnegative<int> {
        return {std::get<0>(version_tuple())};
    }

    /// @brief Returns the compiler minor version number.
    /// @see name
    /// @see version_tuple
    /// @see version_major
    /// @see version_patch
    auto version_minor() const noexcept -> valid_if_nonnegative<int> {
        return {std::get<1>(version_tuple())};
    }

    /// @brief Returns the compiler patch number.
    /// @see name
    /// @see version_tuple
    /// @see version_major
    /// @see version_minor
    auto version_patch() const noexcept -> valid_if_nonnegative<int> {
        return {std::get<2>(version_tuple())};
    }

private:
    compiler_info(_data_tuple data) noexcept
      : _data{std::move(data)} {}

    _data_tuple _data{{}, {}, {-1, -1, -1}};
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/compiler_info.inl>
#endif

#endif // EAGINE_COMPILER_INFO_HPP
