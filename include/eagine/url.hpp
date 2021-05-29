/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_URL_HPP
#define EAGINE_URL_HPP

#include "flat_map.hpp"
#include "maybe_unused.hpp"
#include "memory/span_algo.hpp"
#include "string_path.hpp"
#include "string_span.hpp"
#include "valid_if/not_empty.hpp"
#include "valid_if/not_zero.hpp"
#include <charconv>
#include <regex>

namespace eagine {

/// @brief Class parsing and providing access to parts of an URL.
class url {
public:
    /// @brief Default constructor.
    url() noexcept = default;

    /// @brief Construction from a string.
    url(std::string url_str) noexcept
      : url{std::move(url_str), std::match_results<std::string::iterator>{}} {}

    /// @brief Indicates if the URL was parsed successfully.
    auto is_valid() const noexcept {
        return _parsed;
    }

    /// @brief Indicates if the URL was parsed successfully.
    /// @see is_valid
    explicit operator bool() const noexcept {
        return is_valid();
    }

    /// @brief Returns the whole URL string.
    auto str() const noexcept -> string_view {
        return {_url_str};
    }

    /// @brief Returns the scheme.
    /// @see has_scheme
    auto scheme() const noexcept -> valid_if_not_empty<string_view> {
        return {_scheme};
    }

    /// @brief Checks if the url scheme matches the given string.
    /// @see scheme
    auto has_scheme(string_view str) const noexcept -> bool {
        return are_equal(str, _scheme);
    }

    /// @brief Returns the login name.
    auto login() const noexcept -> valid_if_not_empty<string_view> {
        return {_login};
    }

    /// @brief Returns the login password.
    auto password() const noexcept -> valid_if_not_empty<string_view> {
        return {_passwd};
    }

    /// @brief Returns the host name or IP address.
    auto host() const noexcept -> valid_if_not_empty<string_view> {
        return {_host};
    }

    /// @brief Returns the port string.
    auto port_str() const noexcept -> valid_if_not_empty<string_view> {
        return {_port};
    }

    /// @brief Returns the port.
    auto port() const noexcept -> valid_if_not_zero<int> {
        int result = 0;
        EAGINE_MAYBE_UNUSED(
          std::from_chars(_port.begin(), _port.end(), result));
        return {result};
    }

    /// @brief Returns the path string.
    auto path_str() const noexcept -> valid_if_not_empty<string_view> {
        return {_path};
    }

    /// @brief Returns the path.
    /// @see has_path
    auto path() const noexcept -> basic_string_path {
        return {basic_string_path{_path, EAGINE_TAG(split_by), "/"}};
    }

    /// @brief Checks if the path matches the given string.
    /// @see path_str
    /// @see path
    auto has_path(string_view str) const noexcept -> bool {
        return are_equal(str, _path);
    }

    /// @brief Returns the query string.
    auto query_str() const noexcept -> valid_if_not_empty<string_view> {
        return {_query};
    }

    /// @brief Name to value map for storing URL query parts.
    using query_args =
      flat_map<string_view, string_view, basic_view_less<string_view>>;

    /// @brief Returns the query.
    /// @see argument
    auto query() const noexcept -> query_args {
        query_args result;
        for_each_delimited(_query, string_view{"+"}, [&result](auto part) {
            auto [name, value] = split_by_first(part, string_view{"="});
            result[name] = value;
        });
        return result;
    }

    /// @brief Returns the value of the specified query argument.
    /// @see query
    auto argument(string_view arg_name) const noexcept
      -> valid_if_not_empty<string_view> {
        string_view result;
        for_each_delimited(_query, string_view{"+"}, [&](auto part) {
            auto [name, value] = split_by_first(part, string_view{"="});
            if(!result && are_equal(name, arg_name)) {
                result = value;
            }
        });
        return {result};
    }

    /// @brief Returns the fragment.
    auto fragment() const noexcept -> valid_if_not_empty<string_view> {
        return {_fragment};
    }

private:
    url(std::string, std::match_results<std::string::iterator>) noexcept;

    void _cover(
      string_view& part,
      const std::match_results<std::string::iterator>& match,
      std::size_t index) const noexcept;

    static auto _get_regex() noexcept -> const std::regex&;

    std::string _url_str;
    string_view _scheme;
    string_view _login;
    string_view _passwd;
    string_view _host;
    string_view _port;
    string_view _path;
    string_view _query;
    string_view _fragment;
    bool _parsed{false};
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/url.inl>
#endif

#endif // EAGINE_URL_HPP
