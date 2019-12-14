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
static inline std::string encode_length(span_size_t len) {
    return extract(mbs::encode_code_point(mbs::code_point_t(len)));
}
//------------------------------------------------------------------------------
static inline span_size_t element_header_size(string_view elem) noexcept {
    return extract_or(
      mbs::decode_sequence_length(mbs::make_cbyte_span(elem)), 0);
}
//------------------------------------------------------------------------------
static inline span_size_t element_value_size(
  string_view elem, span_size_t l) noexcept {
    return extract_or(
      mbs::do_decode_code_point(mbs::make_cbyte_span(elem), l), 0U);
}
//------------------------------------------------------------------------------
static inline span_size_t element_value_size(string_view elem) noexcept {
    return element_value_size(elem, elem.size());
}
//------------------------------------------------------------------------------
static inline span_size_t rev_seek_header_start(string_view elem) {
    for(auto i = elem.rbegin(); i != elem.rend(); ++i) {
        if(mbs::is_valid_head_byte(byte(*i))) {
            return elem.rend() - i - 1;
        }
    }
    return 0;
}
//------------------------------------------------------------------------------
static inline string_view front_value(string_view list) noexcept {
    const span_size_t k = element_header_size(list);
    const span_size_t l = element_value_size(list, k);
    return slice(list, k, l);
}
//------------------------------------------------------------------------------
static inline string_view back_value(string_view list) noexcept {
    const span_size_t i = rev_seek_header_start(list);
    string_view header = skip(list, i);
    const span_size_t k = element_header_size(header);
    const span_size_t l = element_value_size(header, k);
    return slice(list, i - l, l);
}
//------------------------------------------------------------------------------
static inline string_view pop_back(string_view list) noexcept {
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
    string_view _base() {
        return *this;
    }
    string_view _base() const {
        return *this;
    }

    static inline string_view _fit(string_view s) noexcept {
        span_size_t hs = element_header_size(s);
        span_size_t vs = element_value_size(s, hs);
        EAGINE_ASSERT(s.size() >= hs + vs + hs);
        return {s.data(), hs + vs + hs};
    }

    static inline string_view _fit(
      const char* ptr, span_size_t max_size) noexcept {
        return _fit(string_view(ptr, max_size));
    }

    static inline string_view _rev_fit(
      string_view s, span_size_t rev_sz) noexcept {
        span_size_t hs = element_header_size(s);
        span_size_t vs = element_value_size(s, hs);
        EAGINE_ASSERT(rev_sz >= hs + vs);
        EAGINE_MAYBE_UNUSED(rev_sz);
        return {s.data() - hs - vs, hs + vs + hs};
    }

    static inline string_view _rev_fit(
      const char* ptr, span_size_t rev_sz, span_size_t foot_sz) noexcept {
        return _rev_fit(string_view(ptr, foot_sz), rev_sz);
    }

public:
    element(const char* ptr, span_size_t max_size) noexcept
      : string_view(_fit(ptr, max_size)) {
    }

    element(const char* ptr, span_size_t rev_sz, span_size_t foot_sz) noexcept
      : string_view(_rev_fit(ptr, rev_sz, foot_sz)) {
    }

    span_size_t header_size() const noexcept {
        return element_header_size(_base());
    }

    string_view header() const noexcept {
        return {data(), header_size()};
    }

    span_size_t value_size() const noexcept {
        return element_value_size(header());
    }

    const char* value_data() const noexcept {
        return data() + header_size();
    }

    string_view value() const noexcept {
        return {value_data(), value_size()};
    }

    span_size_t footer_size() const noexcept {
        return element_header_size(_base());
    }

    string_view footer() const noexcept {
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
    auto adapted_func = [&func](
                          const element& elem, bool) { func(elem.value()); };
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
    auto adapted_func = [&func](
                          const element& elem, bool) { func(elem.value()); };
    rev_for_each_elem(list, adapted_func);
}
//------------------------------------------------------------------------------
static inline span_size_t split_into(
  std::string& dst, string_view str, string_view sep) {
    span_size_t cnt = 0;
    for_each_delimited(str, sep, [&dst, &cnt](const auto& x) {
        push_back(dst, x);
        ++cnt;
    });
    return cnt;
}
//------------------------------------------------------------------------------
static inline std::tuple<std::string, span_size_t> split(
  string_view str, string_view sep) {
    std::string res;
    const auto cnt = split_into(res, str, sep);
    return std::make_tuple(std::move(res), cnt);
}
//------------------------------------------------------------------------------
template <typename Func>
static inline span_size_t for_each_separated_c_str(
  const char* str, const char sep, Func func) {
    span_size_t cnt = 0;
    const char* bgn = str;
    const char* pos = bgn;
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
    return cnt;
}
//------------------------------------------------------------------------------
static inline span_size_t split_c_str_into(
  std::string& dst, const char* str, const char sep) {
    return for_each_separated_c_str(
      str, sep, [&dst](auto elem) { push_back(dst, elem); });
}
//------------------------------------------------------------------------------
static inline std::tuple<std::string, span_size_t> split_c_str(
  const char* str, const char sep) {
    std::string res;
    const auto cnt = split_c_str_into(res, str, sep);
    return std::make_tuple(std::move(res), cnt);
}
//------------------------------------------------------------------------------
static inline std::string join(
  string_view list, string_view sep, bool trail_sep) {
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
static inline std::string join(string_view list, string_view sep) {
    return join(list, sep, false);
}
//------------------------------------------------------------------------------
template <typename Iter>
class iterator {
private:
    Iter _pos;
    mutable string_view _tmp;

    byte _b() const noexcept {
        return byte(*_pos);
    }

    span_size_t _len_len() const noexcept {
        byte b = _b();
        EAGINE_ASSERT(mbs::is_valid_head_byte(b));
        return extract(mbs::do_decode_sequence_length(b));
    }

    span_size_t _val_len(span_size_t ll) const noexcept {
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
      : _pos(pos) {
    }

    friend bool operator==(iterator a, iterator b) noexcept {
        return a._pos == b._pos;
    }

    friend bool operator!=(iterator a, iterator b) noexcept {
        return a._pos != b._pos;
    }

    friend bool operator<(iterator a, iterator b) noexcept {
        return a._pos < b._pos;
    }

    reference operator*() const noexcept {
        _update();
        return _tmp;
    }

    pointer operator->() const noexcept {
        _update();
        return &_tmp;
    }

    iterator& operator++() noexcept {
        span_size_t ll = _len_len();
        span_size_t vl = _val_len(ll);
        _pos += ll + vl + ll;
        _tmp = string_view();
        return *this;
    }

    const iterator operator++(int) noexcept {
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

    byte _b() const noexcept {
        return byte(*_pos);
    }

    void _rseek_head() const noexcept {
        while(!mbs::is_valid_head_byte(_b())) {
            --_pos;
        }
    }

    span_size_t _len_len() const noexcept {
        byte b = _b();
        EAGINE_ASSERT(mbs::is_valid_head_byte(b));
        return extract(mbs::do_decode_sequence_length(b));
    }

    span_size_t _val_len(span_size_t ll) const noexcept {
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
      : _pos(pos) {
    }

    friend bool operator==(rev_iterator a, rev_iterator b) noexcept {
        return a._pos == b._pos;
    }

    friend bool operator!=(rev_iterator a, rev_iterator b) noexcept {
        return a._pos != b._pos;
    }

    friend bool operator<(rev_iterator a, rev_iterator b) noexcept {
        return a._pos > b._pos;
    }

    reference operator*() const noexcept {
        _update();
        return _tmp;
    }

    pointer operator->() const noexcept {
        _update();
        return &_tmp;
    }

    rev_iterator& operator++() noexcept {
        _rseek_head();
        span_size_t ll = _len_len();
        span_size_t vl = _val_len(ll);
        _pos -= ll + vl + 1;
        _tmp = string_view();
        return *this;
    }

    const rev_iterator operator++(int) noexcept {
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
      : _range{range} {
    }

    iterator begin() const noexcept {
        return {_range.begin()};
    }

    iterator end() const noexcept {
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
      : _range{range} {
    }

    iterator begin() const noexcept {
        return iterator(_range.end() - 1);
    }

    iterator end() const noexcept {
        return iterator(_range.begin() - 1);
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
      : _range{std::move(range)} {
    }

    iterator begin() const noexcept {
        return {_range.begin()};
    }

    iterator end() const noexcept {
        return {_range.end()};
    }

    reverse_iterator rbegin() const noexcept {
        return {_range.end() - 1};
    }

    reverse_iterator rend() const noexcept {
        return {_range.begin() - 1};
    }

private:
    Range _range{};
};
//------------------------------------------------------------------------------
} // namespace string_list
//------------------------------------------------------------------------------
static inline string_list::basic_string_list<std::string> make_string_list(
  std::string str) {
    return {std::move(str)};
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
