/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_STRING_PATH_HPP
#define EAGINE_STRING_PATH_HPP

#include "assert.hpp"
#include "identifier.hpp"
#include "memory/block.hpp"
#include "span.hpp"
#include "string_list.hpp"
#include <string>
#include <tuple>
#include <utility>

namespace eagine {
//------------------------------------------------------------------------------
/// @brief Basic class storing paths made of string elements.
/// @ingroup string_utils
///
/// Efficiently stores a sequence of string elements in a single block of memory.
class basic_string_path {
private:
    span_size_t _size{0};
    std::string _str{};

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
        EAGINE_ASSERT(span_size(_str.size()) == len);
    }

    static inline auto _fix(string_view str) noexcept -> string_view {
        while(str.size() > 0) {
            if(str[str.size() - 1] == '\0') {
                str = string_view(str.data(), str.size() - 1);
            } else {
                break;
            }
        }
        return str;
    }

    template <typename... Str>
    static inline auto _pack_names(const Str&... n) noexcept
      -> std::array<string_view, sizeof...(Str)> {
        return {{_fix(n)...}};
    }

public:
    /// @brief The element value type.
    using value_type = string_view;

    /// @brief The element count type.
    using size_type = span_size_t;

    /// @brief Iterator type.
    using iterator = string_list::iterator<const char*>;

    /// @brief Reverse iterator type.
    using reverse_iterator = string_list::rev_iterator<const char*>;

    /// @brief Default constructor. Creates an empty path.
    /// @post empty()
    basic_string_path() noexcept = default;

    /// @brief Move constructor.
    basic_string_path(basic_string_path&&) noexcept = default;

    /// @brief Copy constructor.
    basic_string_path(const basic_string_path&) = default;

    /// @brief Move assignment operator.
    auto operator=(basic_string_path&&) noexcept
      -> basic_string_path& = default;

    /// @brief Copy assignment operator.
    auto operator=(const basic_string_path&) -> basic_string_path& = default;

    ~basic_string_path() noexcept = default;

    basic_string_path(string_view str, span_size_t size)
      : _size{size}
      , _str(str.data(), std_size(str.size())) {}

    basic_string_path(std::string str, span_size_t size)
      : _size{size}
      , _str(std::move(str)) {}

    basic_string_path(std::tuple<std::string, span_size_t>&& init)
      : basic_string_path(std::move(std::get<0>(init)), std::get<1>(init)) {}

    /// @brief Construction from a path string and a separator string.
    basic_string_path(
      string_view path,
      EAGINE_TAG_TYPE(split_by),
      string_view sep)
      : basic_string_path(string_list::split(path, sep)) {}

    explicit basic_string_path(
      const basic_string_path& a,
      EAGINE_TAG_TYPE(plus),
      const basic_string_path& b)
      : _size(a._size + b._size)
      , _str(a._str + b._str) {}

    /// @brief Construction from a list of path element names.
    explicit basic_string_path(span<const string_view> names) {
        _init(names);
    }

    /// @brief Construction from a list of path element names.
    template <std::size_t N>
    explicit basic_string_path(const std::array<string_view, N>& names)
      : basic_string_path(view(names)) {}

    /// @brief Construction from a pack of path element names.
    template <typename... Str>
    explicit basic_string_path(
      EAGINE_TAG_TYPE(from_pack),
      string_view name,
      const Str&... names)
      : basic_string_path(_pack_names(name, view(names)...)) {}

    /// @brief Equality comparison.
    friend auto operator==(
      const basic_string_path& a,
      const basic_string_path& b) noexcept {
        return a._str == b._str;
    }

    /// @brief Non-equality comparison.
    friend auto operator!=(
      const basic_string_path& a,
      const basic_string_path& b) noexcept {
        return a._str != b._str;
    }

    /// @brief Less-than comparison.
    friend auto
    operator<(const basic_string_path& a, const basic_string_path& b) noexcept {
        return a._str < b._str;
    }

    /// @brief Less-equal comparison.
    friend auto operator<=(
      const basic_string_path& a,
      const basic_string_path& b) noexcept {
        return a._str <= b._str;
    }

    /// @brief Greater-than comparison.
    friend auto
    operator>(const basic_string_path& a, const basic_string_path& b) noexcept {
        return a._str > b._str;
    }

    /// @brief Greater-equal comparison.
    friend auto operator>=(
      const basic_string_path& a,
      const basic_string_path& b) noexcept {
        return a._str >= b._str;
    }

    /// @brief Concatenates two paths.
    friend auto
    operator+(const basic_string_path& a, const basic_string_path& b) noexcept {
        return basic_string_path(a, EAGINE_TAG(plus), b);
    }

    /// @brief Indicates if this path is empty.
    /// @see size
    /// @see clear
    auto empty() const noexcept -> bool {
        EAGINE_ASSERT((size() == 0) == _str.empty());
        return _str.empty();
    }

    /// @brief Clears this path.
    /// @see empty
    void clear() noexcept {
        _size = 0;
        _str.clear();
    }

    /// @brief Returns the number of elements in this path.
    /// @see empty
    auto size() const noexcept -> size_type {
        return _size;
    }

    static auto required_bytes(size_type l) -> size_type {
        using namespace mbs;
        return l + 2 * required_sequence_length(code_point_t(l)).value();
    }

    static auto required_bytes(string_view str) -> size_type {
        return required_bytes(size_type(str.size()));
    }

    /// @brief Reserves the specified number of bytes in the storage.
    void reserve_bytes(size_type s) {
        _str.reserve(std_size(s));
    }

    /// @brief Returns the element at the front of the path.
    auto front() const noexcept -> string_view {
        EAGINE_ASSERT(!empty());
        return string_list::front_value(_str);
    }

    /// @brief Returns the element at the back of the path.
    auto back() const noexcept -> string_view {
        EAGINE_ASSERT(!empty());
        return string_list::back_value(_str);
    }

    /// @brief Appends a new element with the specified name to the end.
    /// @see pop_back
    void push_back(string_view name) {
        string_list::push_back(_str, _fix(name));
        ++_size;
    }

    void push_back_elem(const string_list::element& elem) {
        append_to(_str, elem);
        ++_size;
    }

    /// @brief Removes a single element from the end of this path.
    /// @see push_back
    void pop_back() {
        EAGINE_ASSERT(!empty());
        _str.resize(std_size(string_list::pop_back(_str).size()));
        --_size;
    }

    /// @brief Returns an iterator pointing to the start of the path.
    /// @see end
    /// @see rbegin
    auto begin() const noexcept -> iterator {
        return empty() ? iterator(nullptr) : iterator(_str.data());
    }

    /// @brief Returns an iterator pointing past the end of the path.
    /// @see begin
    /// @see rend
    auto end() const noexcept -> iterator {
        return empty() ? iterator(nullptr)
                       : iterator(_str.data() + _str.size());
    }

    /// @brief Returns a reverse iterator pointing to the end of the path.
    /// @see rend
    /// @see begin
    auto rbegin() const noexcept -> reverse_iterator {
        return empty() ? reverse_iterator(nullptr)
                       : reverse_iterator(_str.data() + _str.size() - 1);
    }

    /// @brief Returns an iterator pointing past the start of the path.
    /// @see rbegin
    /// @see end
    auto rend() const noexcept -> reverse_iterator {
        return empty() ? reverse_iterator(nullptr)
                       : reverse_iterator(_str.data() - 1);
    }

    /// @brief Calls the specified function for each element of this path.
    template <typename Func>
    void for_each_elem(Func func) const {
        string_list::for_each_elem(view(_str), func);
    }

    template <typename Func>
    void for_each(Func func) const {
        string_list::for_each(view(_str), func);
    }

    /// @brief Calls the specified function for each element in reverse order.
    template <typename Func>
    void rev_for_each_elem(Func func) const {
        string_list::rev_for_each_elem(view(_str), func);
    }

    template <typename Func>
    void rev_for_each(Func func) const {
        string_list::rev_for_each(view(_str), func);
    }

    /// @brief Returns this path as string with elements separated by @p sep.
    auto as_string(string_view sep, bool trail_sep) const -> std::string {
        return string_list::join(view(_str), sep, trail_sep);
    }

    /// @brief Returns a block covering the internal representation of this path.
    auto block() noexcept -> memory::const_block {
        return as_bytes(view(_str));
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_STRING_PATH_HPP
