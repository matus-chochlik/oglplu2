/**
 *  @file eagine/filesystem.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_FILESYSTEM_HPP
#define EAGINE_FILESYSTEM_HPP

#include "config/basic.hpp"
#include "string_path.hpp"
#include "string_span.hpp"

namespace eagine {
namespace filesystem {

string_view path_separator() noexcept;

string_view alt_path_separator() noexcept;

bool has_alt_path_separator() noexcept;

string_view path_curdir() noexcept;

string_view path_pardir() noexcept;

string_view basename(string_view path) noexcept;

string_view dirname(string_view path) noexcept;

class string_path {
private:
    basic_string_path _p;

public:
    using size_type = basic_string_path::size_type;
    using str_span = basic_string_path::str_span;
    using iterator = basic_string_path::iterator;
    using reverse_iterator = basic_string_path::reverse_iterator;

    string_path() = default;

    string_path(
      const str_span& path_str, const str_span& sep, const str_span& alt_sep);

    string_path(const str_span& path_str, const str_span& sep);

    explicit string_path(str_span path_str);

    explicit string_path(const std::string& path_str)
      : string_path(string_view(path_str)) {
    }

    string_path(const string_path& a, const string_path& b)
      : _p(a._p, EAGINE_TAG(plus), b._p) {
    }

    friend inline bool operator==(
      const string_path& a, const string_path& b) noexcept {
        return a._p == b._p;
    }

    friend inline bool operator!=(
      const string_path& a, const string_path& b) noexcept {
        return a._p != b._p;
    }

    friend inline bool operator<(
      const string_path& a, const string_path& b) noexcept {
        return a._p < b._p;
    }

    friend inline bool operator<=(
      const string_path& a, const string_path& b) noexcept {
        return a._p <= b._p;
    }

    friend inline bool operator>(
      const string_path& a, const string_path& b) noexcept {
        return a._p > b._p;
    }

    friend inline bool operator>=(
      const string_path& a, const string_path& b) noexcept {
        return a._p >= b._p;
    }

    friend inline string_path operator+(
      const string_path& a, const string_path& b) noexcept {
        return string_path(a, b);
    }

    inline bool empty() const noexcept {
        return _p.empty();
    }

    inline size_type size() const noexcept {
        return _p.size();
    }

    inline str_span front() const {
        return _p.front();
    }

    inline str_span back() const {
        return _p.back();
    }

    inline string_path& push_back(const str_span& name) {
        _p.push_back(name);
        return *this;
    }

    inline void pop_back() {
        _p.pop_back();
    }

    inline iterator begin() const {
        return _p.begin();
    }

    inline iterator end() const {
        return _p.end();
    }

    inline reverse_iterator rbegin() const {
        return _p.rbegin();
    }

    inline reverse_iterator rend() const {
        return _p.rend();
    }

    inline std::string str() const {
        return _p.as_string(path_separator(), false);
    }

    inline std::string dir_str() const {
        return empty() ? std::string() : _p.as_string(path_separator(), true);
    }

    string_path normalized() const;

    string_path parent_path() const;

    static bool is_root_name(const str_span& name) noexcept;

    bool is_root_path() const noexcept;

    bool is_absolute() const noexcept;

    bool is_relative() const noexcept;
};

string_path current_working_directory();

} // namespace filesystem
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/filesystem.inl>
#endif

#endif // EAGINE_FILESYSTEM_HPP
