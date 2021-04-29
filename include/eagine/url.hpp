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

class url {
public:
    url(
      std::string url_str,
      std::match_results<std::string::iterator> match = {}) noexcept
      : _url_str{std::move(url_str)}
      , _parsed{std::regex_match(
          _url_str.begin(),
          _url_str.end(),
          match,
          _get_regex())} {

        if(_parsed) {
            _cover(_scheme, match, 3);
        }
    }

    auto scheme() const noexcept {
        return _scheme;
    }

private:
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
          R"(^((([\w]+):)?\/\/)$)",
		  std::regex::ECMAScript
          // clang-format on
        };
#ifdef __clang__
        EAGINE_DIAG_POP()
#endif
        return re;
    }

    std::string _url_str;
    string_view _authority;
    string_view _scheme;
    bool _parsed{false};
};

} // namespace eagine

#endif // EAGINE_URL_HPP
