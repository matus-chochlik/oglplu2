/**
 *  @file eagine/string_list.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STRING_LIST_HPP
#define EAGINE_STRING_LIST_HPP

#include "assert.hpp"
#include "maybe_unused.hpp"
#include "memory/span_algo.hpp"
#include "multi_byte_seq.hpp"
#include "string_span.hpp"
#include <iterator>
#include <string>
#include <tuple>

namespace eagine {
namespace string_list {
//------------------------------------------------------------------------------
static inline auto encode_length(span_size_t len) -> std::string {
    return extract(mbs::encode_code_point(mbs::code_point_t(len)));
}
//------------------------------------------------------------------------------
static inline auto element_header_size(string_view elem) noexcept
  -> span_size_t {
    return extract_or(
      mbs::decode_sequence_length(mbs::make_cbyte_span(elem)), 0);
}
//------------------------------------------------------------------------------
static inline auto element_value_size(string_view elem, span_size_t l) noexcept
  -> span_size_t {
    return extract_or(
      mbs::do_decode_code_point(mbs::make_cbyte_span(elem), l), 0U);
}
//------------------------------------------------------------------------------
static inline auto element_value_size(string_view elem) noexcept
  -> span_size_t {
    return element_value_size(elem, elem.size());
}
//------------------------------------------------------------------------------
static inline auto rev_seek_header_start(string_view elem) -> span_size_t {
    for(auto i = elem.rbegin(); i != elem.rend(); ++i) {
        if(mbs::is_valid_head_byte(byte(*i))) {
            return elem.rend() - i - 1;
        }
    }
    return 0;
}
//------------------------------------------------------------------------------
static inline auto front_value(string_view list) noexcept -> string_view {
    const span_size_t k = element_header_size(list);
    const span_size_t l = element_value_size(list, k);
    return slice(list, k, l);
}
//------------------------------------------------------------------------------
static inline auto back_value(string_view list) noexcept -> string_view {
    const span_size_t i = rev_seek_header_start(list);
    string_view header = skip(list, i);
    const span_size_t k = element_header_size(header);
    const span_size_t l = element_value_size(header, k);
    return slice(list, i - l, l);
}
//------------------------------------------------------------------------------
static inline auto pop_back(string_view list) noexcept -> string_view {
    const span_size_t i = rev_seek_header_start(list);
    string_view header = skip(list, i);
    const span_size_t k = element_header_size(header);
    const span_size_t l = element_value_size(header, k);
    EAGINE_ASSERT(i >= k + l);
    return head(list, i - k - l);
}
//------------------------------------------------------------------------------
static inline void push_back(std::string& list, string_view value) {
    const span_size_t vl = value.size();
    const std::string elen = encode_length(vl);
    const std::size_t nl = list.size() + elen.size() * 2 + std_size(vl);
    if(list.capacity() < nl) {
        list.reserve(nl);
    }
    list.append(elen);
    list.append(value.data(), std_size(vl));
    list.append(elen);
}
//------------------------------------------------------------------------------
class element : public string_view {
private:
    auto _base() -> string_view {
        return *this;
    }
    auto _base() const -> string_view {
        return *this;
    }

    static inline auto _fit(string_view s) noexcept -> string_view {
        span_size_t hs = element_header_size(s);
        span_size_t vs = element_value_size(s, hs);
        EAGINE_ASSERT(s.size() >= hs + vs + hs);
        return {s.data(), hs + vs + hs};
    }

    static inline auto _fit(const char* ptr, span_size_t max_size) noexcept
      -> string_view {
        return _fit(string_view(ptr, max_size));
    }

    static inline auto _rev_fit(string_view s, span_size_t rev_sz) noexcept
      -> string_view {
        span_size_t hs = element_header_size(s);
        span_size_t vs = element_value_size(s, hs);
        EAGINE_ASSERT(rev_sz >= hs + vs);
        EAGINE_MAYBE_UNUSED(rev_sz);
        return {s.data() - hs - vs, hs + vs + hs};
    }

    static inline auto
    _rev_fit(const char* ptr, span_size_t rev_sz, span_size_t foot_sz) noexcept
      -> string_view {
        return _rev_fit(string_view(ptr, foot_sz), rev_sz);
    }

public:
    element(const char* ptr, span_size_t max_size) noexcept
      : string_view(_fit(ptr, max_size)) {}

    element(const char* ptr, span_size_t rev_sz, span_size_t foot_sz) noexcept
      : string_view(_rev_fit(ptr, rev_sz, foot_sz)) {}

    auto header_size() const noexcept -> span_size_t {
        return element_header_size(_base());
    }

    auto header() const noexcept -> string_view {
        return {data(), header_size()};
    }

    auto value_size() const noexcept -> span_size_t {
        return element_value_size(header());
    }

    auto value_data() const noexcept -> const char* {
        return data() + header_size();
    }

    auto value() const noexcept -> string_view {
        return {value_data(), value_size()};
    }

    auto footer_size() const noexcept -> span_size_t {
        return element_header_size(_base());
    }

    auto footer() const noexcept -> string_view {
        return {data() + header_size() + value_size(), header_size()};
    }
};
//------------------------------------------------------------------------------
template <typename Func>
static inline void for_each_elem(string_view list, Func func) noexcept {
    span_size_t i = 0;
    bool first = true;
    while(i < list.size()) {
        element elem(list.data() + i, list.size() - i);
        func(elem, first);
        i += elem.size();
        first = false;
    }
}
//------------------------------------------------------------------------------
template <typename Func>
static inline void for_each(string_view list, Func func) noexcept {
    auto adapted_func = [&func](const element& elem, bool) {
        func(elem.value());
    };
    for_each_elem(list, adapted_func);
}
//------------------------------------------------------------------------------
template <typename Func>
static inline void rev_for_each_elem(string_view list, Func func) noexcept {
    span_size_t i = list.size() - 1;
    bool first = true;
    while(i > 0) {
        while(!mbs::is_valid_head_byte(byte(list[i]))) {
            EAGINE_ASSERT(i > 0);
            --i;
        }
        element elem(list.data() + i, i, list.size() - i);
        func(elem, first);
        i -= elem.header_size() + elem.value_size() + 1;
        first = false;
    }
}
//------------------------------------------------------------------------------
template <typename Func>
static inline void rev_for_each(string_view list, Func func) noexcept {
    auto adapted_func = [&func](const element& elem, bool) {
        func(elem.value());
    };
    rev_for_each_elem(list, adapted_func);
}
//------------------------------------------------------------------------------
static inline auto
split_into(std::string& dst, string_view str, string_view sep) -> span_size_t {
    span_size_t cnt = 0;
    for_each_delimited(str, sep, [&dst, &cnt](const auto& x) {
        push_back(dst, x);
        ++cnt;
    });
    return cnt;
}
//------------------------------------------------------------------------------
static inline auto split(string_view str, string_view sep)
  -> std::tuple<std::string, span_size_t> {
    std::string res;
    const auto cnt = split_into(res, str, sep);
    return std::make_tuple(std::move(res), cnt);
}
//------------------------------------------------------------------------------
template <typename Func>
static inline auto
for_each_separated_c_str(const char* str, const char sep, Func func)
  -> span_size_t {
    span_size_t cnt = 0;
    const char* bgn = str;
    const char* pos = bgn;
    if(sep != '\0') {
        while(bool(str) && (*pos != '\0')) {
            if(*pos == sep) {
                if(pos - bgn > 0) {
                    func(string_view(bgn, pos - bgn));
                    ++cnt;
                    bgn = ++pos;
                } else {
                    break;
                }
            } else {
                ++pos;
            }
        }
    } else {
        while(bool(str)) {
            if((*pos == sep) || (*pos == char(0))) {
                if(pos - bgn > 1) {
                    func(string_view(bgn, pos - bgn));
                    ++cnt;
                    bgn = ++pos;
                } else {
                    break;
                }
            } else {
                ++pos;
            }
        }
    }
    return cnt;
}
//------------------------------------------------------------------------------
static inline auto
split_c_str_into(std::string& dst, const char* str, const char sep)
  -> span_size_t {
    return for_each_separated_c_str(
      str, sep, [&dst](auto elem) { push_back(dst, elem); });
}
//------------------------------------------------------------------------------
static inline auto split_c_str(const char* str, const char sep)
  -> std::tuple<std::string, span_size_t> {
    std::string res;
    const auto cnt = split_c_str_into(res, str, sep);
    return std::make_tuple(std::move(res), cnt);
}
//------------------------------------------------------------------------------
static inline auto join(string_view list, string_view sep, bool trail_sep)
  -> std::string {
    span_size_t slen = sep.size();
    span_size_t len = trail_sep ? slen : 0;
    auto get_len = [&len, slen](const element& elem, bool first) {
        if(!first) {
            len += slen;
        }
        len += elem.value_size();
    };
    for_each_elem(list, get_len);

    std::string res;
    res.reserve(std_size(len));

    auto fill = [&res, sep](const element& elem, bool first) {
        if(!first) {
            res.append(sep.data(), std_size(sep.size()));
        }
        res.append(elem.value_data(), std_size(elem.value_size()));
    };
    for_each_elem(list, fill);

    if(trail_sep) {
        res.append(sep.data(), std_size(sep.size()));
    }
    EAGINE_ASSERT(res.size() == std_size(len));

    return res;
}
//------------------------------------------------------------------------------
static inline auto join(string_view list, string_view sep) -> std::string {
    return join(list, sep, false);
}
//------------------------------------------------------------------------------
template <typename Iter>
class iterator {
private:
    Iter _pos;
    mutable string_view _tmp;

    auto _b() const noexcept {
        return byte(*_pos);
    }

    auto _len_len() const noexcept -> span_size_t {
        byte b = _b();
        EAGINE_ASSERT(mbs::is_valid_head_byte(b));
        return extract(mbs::do_decode_sequence_length(b));
    }

    auto _val_len(span_size_t ll) const noexcept -> span_size_t {
        string_view el{&*_pos, ll};
        return extract_or(
          mbs::do_decode_code_point(mbs::make_cbyte_span(el), ll), 0U);
    }

    void _update() const {
        if(_tmp.size() == 0) {
            span_size_t ll = _len_len();
            span_size_t vl = _val_len(ll);
            _tmp = string_view{&*(_pos + ll), vl};
        }
    }

public:
    using difference_type = std::ptrdiff_t;
    using value_type = string_view;
    using reference = const value_type&;
    using pointer = const value_type*;
    using iterator_category = std::forward_iterator_tag;

    iterator(Iter pos) noexcept
      : _pos(pos) {}

    friend auto operator==(iterator a, iterator b) noexcept {
        return a._pos == b._pos;
    }

    friend auto operator!=(iterator a, iterator b) noexcept {
        return a._pos != b._pos;
    }

    friend auto operator<(iterator a, iterator b) noexcept {
        return a._pos < b._pos;
    }

    auto operator*() const noexcept -> reference {
        _update();
        return _tmp;
    }

    auto operator->() const noexcept -> pointer {
        _update();
        return &_tmp;
    }

    auto operator++() noexcept -> auto& {
        span_size_t ll = _len_len();
        span_size_t vl = _val_len(ll);
        _pos += ll + vl + ll;
        _tmp = string_view();
        return *this;
    }

    auto operator++(int) noexcept -> iterator {
        iterator result = *this;
        ++(*this);
        return result;
    }
};
//------------------------------------------------------------------------------
template <typename Iter>
class rev_iterator {
private:
    mutable Iter _pos;
    mutable string_view _tmp;

    auto _b() const noexcept {
        return byte(*_pos);
    }

    void _rseek_head() const noexcept {
        while(!mbs::is_valid_head_byte(_b())) {
            --_pos;
        }
    }

    auto _len_len() const noexcept -> span_size_t {
        byte b = _b();
        EAGINE_ASSERT(mbs::is_valid_head_byte(b));
        return extract(mbs::do_decode_sequence_length(b));
    }

    auto _val_len(span_size_t ll) const noexcept -> span_size_t {
        string_view el{&*_pos, ll};
        return extract_or(
          mbs::do_decode_code_point(mbs::make_cbyte_span(el), ll), 0U);
    }

    void _update() const {
        if(_tmp.size() == 0) {
            _rseek_head();
            span_size_t ll = _len_len();
            span_size_t vl = _val_len(ll);
            _tmp = string_view{&*(_pos - vl), vl};
        }
    }

public:
    using difference_type = std::ptrdiff_t;
    using value_type = string_view;
    using reference = const value_type&;
    using pointer = const value_type*;
    using iterator_category = std::forward_iterator_tag;

    rev_iterator(Iter pos) noexcept
      : _pos(pos) {}

    friend auto operator==(rev_iterator a, rev_iterator b) noexcept {
        return a._pos == b._pos;
    }

    friend auto operator!=(rev_iterator a, rev_iterator b) noexcept {
        return a._pos != b._pos;
    }

    friend auto operator<(rev_iterator a, rev_iterator b) noexcept {
        return a._pos > b._pos;
    }

    auto operator*() const noexcept -> reference {
        _update();
        return _tmp;
    }

    auto operator->() const noexcept -> pointer {
        _update();
        return &_tmp;
    }

    auto operator++() noexcept -> auto& {
        _rseek_head();
        span_size_t ll = _len_len();
        span_size_t vl = _val_len(ll);
        _pos -= ll + vl + 1;
        _tmp = string_view();
        return *this;
    }

    auto operator++(int) noexcept -> rev_iterator {
        rev_iterator result = *this;
        ++(*this);
        return result;
    }
};
//------------------------------------------------------------------------------
template <typename Range>
class range_view {

public:
    using iterator = eagine::string_list::iterator<typename Range::iterator>;

    range_view(Range& range) noexcept
      : _range{range} {}

    auto begin() const noexcept -> iterator {
        return {_range.begin()};
    }

    auto end() const noexcept -> iterator {
        return {_range.end()};
    }

private:
    Range& _range;
};
//------------------------------------------------------------------------------
template <typename Range>
class rev_range_view {

public:
    using iterator =
      eagine::string_list::rev_iterator<typename Range::iterator>;

    rev_range_view(Range& range) noexcept
      : _range{range} {}

    auto begin() const noexcept -> iterator {
        return {_range.end() - 1};
    }

    auto end() const noexcept -> iterator {
        return {_range.begin() - 1};
    }

private:
    Range& _range;
};
//------------------------------------------------------------------------------
template <typename Range>
class basic_string_list {
public:
    using value_type = string_view;
    using iterator =
      eagine::string_list::iterator<typename Range::const_iterator>;
    using reverse_iterator =
      eagine::string_list::rev_iterator<typename Range::const_iterator>;

    basic_string_list() noexcept = default;

    basic_string_list(Range range) noexcept
      : _range{std::move(range)} {}

    auto begin() const noexcept -> iterator {
        return {_range.begin()};
    }

    auto end() const noexcept -> iterator {
        return {_range.end()};
    }

    auto rbegin() const noexcept -> reverse_iterator {
        return {_range.end() - 1};
    }

    auto rend() const noexcept -> reverse_iterator {
        return {_range.begin() - 1};
    }

private:
    Range _range{};
};
//------------------------------------------------------------------------------
} // namespace string_list
//------------------------------------------------------------------------------
static inline auto make_string_list(std::string str)
  -> string_list::basic_string_list<std::string> {
    return {std::move(str)};
}
//------------------------------------------------------------------------------
static inline auto split_into_string_list(string_view src, char sep) {
    std::string temp;
    string_list::split_into(temp, src, cover_one(sep));
    return make_string_list(std::move(temp));
}
//------------------------------------------------------------------------------
static inline auto split_c_str_into_string_list(const char* src, char sep) {
    std::string temp;
    string_list::split_c_str_into(temp, src, sep);
    return make_string_list(std::move(temp));
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_STRING_LIST_HPP
