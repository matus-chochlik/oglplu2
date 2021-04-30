/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_URL_HPP
#define EAGINE_URL_HPP

#include "diagnostic.hpp"
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
      : url{std::move(url_str), {}} {}

    /// @brief Indicates if the URL was parsed successfully.
    auto is_valid() const noexcept {
        return _parsed;
    }

    /// @brief Indicates if the URL was parsed successfully.
    /// @see is_valid
    explicit operator bool() const noexcept {
        return is_valid();
    }

    /// @brief Returns the scheme.
    auto scheme() const noexcept -> valid_if_not_empty<string_view> {
        return {_scheme};
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
    auto path() const noexcept -> basic_string_path {
        return {basic_string_path{_path, EAGINE_TAG(split_by), "/"}};
    }

    /// @brief Returns the query string.
    auto query_str() const noexcept -> valid_if_not_empty<string_view> {
        return {_query};
    }

    /// @brief Name to value map for storing URL query parts.
    using query_args =
      flat_map<string_view, string_view, basic_view_less<string_view>>;

    /// @brief Returns the query.
    auto query() const noexcept -> query_args {
        query_args result;
        for_each_delimited(_query, string_view{"+"}, [&result](auto part) {
            auto [name, value] = split_by_first(part, string_view{"="});
            result[name] = value;
        });
        return result;
    }

    /// @brief Returns the fragment.
    auto fragment() const noexcept -> valid_if_not_empty<string_view> {
        return {_fragment};
    }

private:
    url(
      std::string url_str,
      std::match_results<std::string::iterator> match) noexcept
      : _url_str{std::move(url_str)}
      , _parsed{std::regex_match(
          _url_str.begin(),
          _url_str.end(),
          match,
          _get_regex())} {

        if(_parsed) {
            _cover(_scheme, match, 3);
            _cover(_login, match, 5);
            _cover(_passwd, match, 7);
            _cover(_host, match, 9);
            _cover(_port, match, 28);
            _cover(_path, match, 29);
            _cover(_query, match, 32);
            _cover(_fragment, match, 37);
        }
    }

    void _cover(
      string_view& part,
      const std::match_results<std::string::iterator>& match,
      std::size_t index) const noexcept {
        if(index < match.size()) {
            auto& m = match[index];
            part = head(
              skip(view(_url_str), m.first - _url_str.begin()),
              m.second - m.first);
        }
    }

    static auto _get_regex() noexcept -> const std::regex& {
#ifdef __clang__
        EAGINE_DIAG_PUSH()
        EAGINE_DIAG_OFF(exit-time-destructors)
#endif
        static const std::regex re{
          // clang-format off
          R"(^((([\w]+):)?\/\/)(([^:]+)(:(\S+))?@)?((((\w[\w_-]{0,62}(\.\w[\w_-]{0,62})*))|((10|127)(\.\d{1,3}){3})|((169\.254|192\.168)(\.\d{1,3}){2})|(172\.(1[6-9]|2\d|3[0-1])(\.\d{1,3}){2})|([1-9]\d?|1\d\d|2[01]\d|22[0-3])(\.(1?\d{1,2}|2[0-4]\d|25[0-5])){2}(\.([1-9]\d?|1\d\d|2[0-4]\d|25[0-4])))(:(\d{1,5}))?)?((/[\w_-]+)*/?)?(\?(([\w_]+=[^+#]*)(\+([\w_]+=[^+#]*))*))?(#([\w_-]*))?$)",
          // clang-format on
          std::regex::ECMAScript};
#ifdef __clang__
        EAGINE_DIAG_POP()
#endif
        return re;
    }

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

#endif // EAGINE_URL_HPP
