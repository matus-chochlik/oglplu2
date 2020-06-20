/**
 *  @file eagine/filesystem.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/config/platform.hpp>
#include <eagine/memory/span_algo.hpp>

#include <eagine/posix/fd_path.hpp> // TODO Windows

namespace eagine {
namespace filesystem {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_view path_separator() noexcept {
#if EAGINE_WINDOWS
    return string_view("\\");
#else
    return string_view("/");
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_view alt_path_separator() noexcept {
    return string_view("/");
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool has_alt_path_separator() noexcept {
#if EAGINE_WINDOWS
    return true;
#else
    return false;
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_view path_curdir() noexcept {
    return string_view(".");
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_view path_pardir() noexcept {
    return string_view("..");
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_view basename(string_view path) noexcept {
    return slice_after_last(
      strip_suffix(path, path_separator()), path_separator());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_view dirname(string_view path) noexcept {
    return slice_before_last(
      strip_suffix(path, path_separator()), path_separator());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_path::string_path(
  string_view path_str, string_view sep, string_view alt_sep) {
    span_size_t s = 0;

    auto count = [&s](string_view name) {
        s += basic_string_path::required_bytes(name);
    };

    auto count_alt = [&count, &alt_sep](string_view name) {
        for_each_delimited(name, alt_sep, count);
    };

    for_each_delimited(path_str, sep, count_alt);
    _p.reserve_bytes(s);

    auto push_back = [this](string_view name) { _p.push_back(name); };

    auto push_back_alt = [&push_back, &alt_sep](string_view name) {
        for_each_delimited(name, alt_sep, push_back);
    };

    for_each_delimited(path_str, sep, push_back_alt);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_path::string_path(string_view path_str, string_view sep) {
    span_size_t s = 0;

    auto count = [&s](string_view name) {
        s += basic_string_path::required_bytes(name);
    };

    for_each_delimited(path_str, sep, count);
    _p.reserve_bytes(s);

    auto push_back = [this](string_view name) { _p.push_back(name); };

    for_each_delimited(path_str, sep, push_back);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_path::string_path(string_view path_str)
#if EAGINE_WINDOWS
  : string_path(path_str, path_separator(), alt_path_separator())
#else
  : string_path(path_str, path_separator())
#endif
{
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_path string_path::normalized() const {
    string_path result;

    auto do_norm = [&result](const string_list::element& elem, bool first) {
        auto val = elem.value();
        if(are_equal(val, path_curdir()) && !first) {
            return;
        }
        if((val.size() == 0) && !first) {
            return;
        }

        if(result.empty() || (are_equal(result.back(), path_pardir()))) {
            result._p.push_back_elem(elem);
        } else if(are_equal(val, path_pardir())) {
            if(are_equal(result.back(), path_curdir())) {
                result._p.pop_back();
                result._p.push_back_elem(elem);

            } else if((result.size() != 1) || (result.back().size() != 0)) {
                result._p.pop_back();
            }
        } else {
            result._p.push_back_elem(elem);
        }
    };
    _p.for_each_elem(do_norm);

    return result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_path string_path::parent_path() const {
    string_path result(normalized());
    if(result.empty() || are_equal(result.back(), path_pardir())) {
        result.push_back(path_pardir());
    } else if(result.size() == 1) {
        if(are_equal(result.back(), path_curdir())) {
            result.pop_back();
            result.push_back(path_pardir());
        } else {
            result.pop_back();
            result.push_back(path_curdir());
        }
    } else if((result.size() > 1) || (!is_root_name(front()))) {
        result.pop_back();
    }
    return result;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool string_path::is_root_name(string_view name) noexcept {
#if EAGINE_WINDOWS
    return ends_with(name, string_view(":"));
#else
    return name.size() == 0;
#endif
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool string_path::is_root_path() const noexcept {
    return (size() == 1) && is_root_name(front());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool string_path::is_absolute() const noexcept {
    return !empty() && is_root_name(front());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool string_path::is_relative() const noexcept {
    return !is_absolute();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
string_path current_working_directory() {
    return string_path(posix::safe_getcwd().value());
}
//------------------------------------------------------------------------------
} // namespace filesystem
} // namespace eagine
