/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_BUILD_INFO_HPP
#define EAGINE_BUILD_INFO_HPP

#include "serialize/fwd.hpp"
#include "tribool.hpp"
#include "valid_if/nonnegative.hpp"
#include <tuple>

namespace eagine {

class build_info {
    friend struct serializer<build_info>;
    friend struct deserializer<build_info>;

    using _data_tuple = std::tuple<std::tuple<int, int, int, int>>;

public:
    constexpr build_info() noexcept(
      std::is_nothrow_default_constructible_v<_data_tuple>) = default;

    static auto query() noexcept -> build_info;

    auto version_tuple() const noexcept -> const auto& {
        return std::get<0>(_data);
    }

    auto version_major() const noexcept -> valid_if_nonnegative<int> {
        return {std::get<0>(version_tuple())};
    }

    auto version_minor() const noexcept -> valid_if_nonnegative<int> {
        return {std::get<1>(version_tuple())};
    }

    auto version_patch() const noexcept -> valid_if_nonnegative<int> {
        return {std::get<2>(version_tuple())};
    }

    auto version_commit() const noexcept -> valid_if_nonnegative<int> {
        return {std::get<3>(version_tuple())};
    }

    auto has_version() const noexcept -> bool {
        return version_major() && version_minor();
    }

    auto version_at_least(int major, int minor) const -> tribool;
    auto version_at_least(int major, int minor, int patch) const -> tribool;
    auto version_at_least(int major, int minor, int patch, int commit) const
      -> tribool;

private:
    build_info(_data_tuple data) noexcept
      : _data{std::move(data)} {}

    _data_tuple _data{{-1, -1, -1, -1}};
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/build_info.inl>
#endif

#endif
