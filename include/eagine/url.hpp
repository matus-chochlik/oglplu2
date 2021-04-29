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
#include "memory/span_algo.hpp"
#include "string_span.hpp"
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
    auto scheme() const noexcept -> string_view {
        return _scheme;
    }

    /// @brief Returns the login name.
    auto login() const noexcept -> string_view {
        return _login;
    }

    /// @brief Returns the login password.
    auto password() const noexcept -> string_view {
        return _passwd;
    }

    /// @brief Returns the host name or IP address.
    auto host() const noexcept -> string_view {
        return _host;
    }

    /// @brief Returns the port.
    auto port() const noexcept -> string_view {
        return _port;
    }

    /// @brief Returns the path.
    auto path() const noexcept -> string_view {
        return _path;
    }

    /// @brief Returns the query.
    auto query() const noexcept -> string_view {
        return _query;
    }

    /// @brief Returns the fragment.
    auto fragment() const noexcept -> string_view {
        return _fragment;
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
		  std::regex::ECMAScript
          // clang-format on
        };
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
