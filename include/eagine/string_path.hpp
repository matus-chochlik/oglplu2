/**
 *  @file eagine/string_path.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STRING_PATH_1509260923_HPP
#define EAGINE_STRING_PATH_1509260923_HPP

#include "identifier.hpp"
#include "memory/block.hpp"
#include "span.hpp"
#include "string_list.hpp"
#include <string>
#include <tuple>

namespace eagine {
//------------------------------------------------------------------------------
class basic_string_path {
private:
    span_size_t _size;
    std::string _str;

    template <typename Str>
    void _init(span<Str> names) {
        span_size_t len = 2 * names.size();
        for(const auto& name : names) {
            len += span_size(name.size());
        }
        _str.reserve(std_size(len));

        for(const auto& name : names) {
            push_back(name);
        }
        assert(span_size(_str.size()) == len);
    }

    static inline string_view _fix(string_view str) noexcept {
        while(str.size() > 0) {
            if(str[str.size() - 1] == '\0') {
                str = string_view(str.data(), str.size() - 1);
            } else
                break;
        }
        return str;
    }

    template <typename... Str>
    static inline std::array<string_view, sizeof...(Str)> _pack_names(
      const Str&... n) noexcept {
        return {{_fix(n)...}};
    }

public:
    typedef string_view value_type;
    typedef string_view str_span;
    typedef span_size_t size_type;
    typedef string_list::iterator<const char*> iterator;
    typedef string_list::rev_iterator<const char*> reverse_iterator;

    basic_string_path() noexcept
      : _size{0} {
    }

    basic_string_path(const basic_string_path&) = default;
    basic_string_path(basic_string_path&&) = default;
    basic_string_path& operator=(const basic_string_path&) = default;
    basic_string_path& operator=(basic_string_path&&) = default;

    basic_string_path(const str_span& str, span_size_t size)
      : _size{size}
      , _str(str.data(), std_size(str.size())) {
    }

    basic_string_path(const std::string& str, span_size_t size)
      : _size{size}
      , _str(str) {
    }

    basic_string_path(std::string&& str, span_size_t size)
      : _size{size}
      , _str(std::move(str)) {
    }

    basic_string_path(std::tuple<std::string, span_size_t>&& init)
      : basic_string_path(
          std::move(std::get<0>(init)), std::move(std::get<1>(init))) {
    }

    basic_string_path(
      const str_span& path, EAGINE_TAG_TYPE(split_by), const str_span& sep)
      : basic_string_path(string_list::split(path, sep)) {
    }

    explicit basic_string_path(
      const basic_string_path& a,
      EAGINE_TAG_TYPE(plus),
      const basic_string_path& b)
      : _size(a._size + b._size)
      , _str(a._str + b._str) {
    }

    explicit basic_string_path(span<const str_span> names)
      : _size(0) {
        _init(names);
    }

    template <std::size_t N>
    explicit basic_string_path(const std::array<str_span, N>& names)
      : basic_string_path(view(names)) {
    }

    template <typename... Str>
    explicit basic_string_path(
      EAGINE_TAG_TYPE(from_pack), const str_span& name, const Str&... names)
      : basic_string_path(_pack_names(name, view(names)...)) {
    }

    friend bool operator==(
      const basic_string_path& a, const basic_string_path& b) noexcept {
        return a._str == b._str;
    }

    friend bool operator!=(
      const basic_string_path& a, const basic_string_path& b) noexcept {
        return a._str != b._str;
    }

    friend bool operator<(
      const basic_string_path& a, const basic_string_path& b) noexcept {
        return a._str < b._str;
    }

    friend bool operator<=(
      const basic_string_path& a, const basic_string_path& b) noexcept {
        return a._str <= b._str;
    }

    friend bool operator>(
      const basic_string_path& a, const basic_string_path& b) noexcept {
        return a._str > b._str;
    }

    friend bool operator>=(
      const basic_string_path& a, const basic_string_path& b) noexcept {
        return a._str >= b._str;
    }

    friend basic_string_path operator+(
      const basic_string_path& a, const basic_string_path& b) noexcept {
        return basic_string_path(a, EAGINE_TAG(plus), b);
    }

    bool empty() const noexcept {
        assert((size() == 0) == _str.empty());
        return _str.empty();
    }

    void clear() {
        _size = 0;
        _str.clear();
    }

    size_type size() const noexcept {
        return _size;
    }

    static size_type required_bytes(size_type l) noexcept {
        using namespace mbs;
        return l + 2 * required_sequence_length(code_point_t(l)).value();
    }

    static size_type required_bytes(str_span str) noexcept {
        return required_bytes(size_type(str.size()));
    }

    void reserve_bytes(size_type s) {
        _str.reserve(std_size(s));
    }

    str_span front() const noexcept {
        assert(!empty());
        return string_list::front_value(_str);
    }

    str_span back() const noexcept {
        assert(!empty());
        return string_list::back_value(_str);
    }

    void push_back(str_span name) {
        string_list::push_back(_str, _fix(name));
        ++_size;
    }

    void push_back_elem(const string_list::element& elem) {
        _str.append(elem.data(), std_size(elem.size()));
        ++_size;
    }

    void pop_back() {
        assert(!empty());
        _str.resize(std_size(string_list::pop_back(_str).size()));
        --_size;
    }

    iterator begin() const noexcept {
        return empty() ? iterator() : iterator(_str.data());
    }

    iterator end() const noexcept {
        return empty() ? iterator() : iterator(_str.data() + _str.size());
    }

    reverse_iterator rbegin() const noexcept {
        return empty() ? reverse_iterator()
                       : reverse_iterator(_str.data() + _str.size() - 1);
    }

    reverse_iterator rend() const noexcept {
        return empty() ? reverse_iterator() : reverse_iterator(_str.data() - 1);
    }

    template <typename Func>
    void for_each_elem(Func func) const {
        string_list::for_each_elem(view(_str), func);
    }

    template <typename Func>
    void for_each(Func func) const {
        string_list::for_each(view(_str), func);
    }

    template <typename Func>
    void rev_for_each_elem(Func func) const {
        string_list::rev_for_each_elem(view(_str), func);
    }

    template <typename Func>
    void rev_for_each(Func func) const {
        string_list::rev_for_each(view(_str), func);
    }

    std::string as_string(const str_span& sep, bool trail_sep) const {
        return string_list::join(view(_str), sep, trail_sep);
    }

    memory::const_block block() noexcept {
        return as_bytes(view(_str));
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // include guard
