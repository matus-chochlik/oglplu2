/**
 *  @file eagine/string_list.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_STRING_LIST_1509260923_HPP
#define EAGINE_STRING_LIST_1509260923_HPP

#include <cassert>
#include <iterator>
#include <string>
#include "multi_byte_seq.hpp"
#include "range_algo.hpp"
#include "string_span.hpp"

namespace eagine {
namespace string_list {

static inline std::string
encode_length(span_size_t len) {
    return mbs::encode_code_point(mbs::code_point_t(len)).value();
}

static inline span_size_t
element_header_size(const cstring_span& elem) noexcept {
    return mbs::decode_sequence_length(mbs::make_cbyte_span(elem)).value();
}

static inline span_size_t
element_value_size(const cstring_span& elem, span_size_t l) noexcept {
    return mbs::do_decode_code_point(mbs::make_cbyte_span(elem), l);
}

static inline span_size_t
element_value_size(const cstring_span& elem) noexcept {
    return element_value_size(elem, elem.size());
}

static inline span_size_t
rev_seek_header_start(const cstring_span& elem) {
    for(auto i = elem.rbegin(); i != elem.rend(); ++i) {
        if(mbs::is_valid_head_byte(byte(*i))) {
            return elem.rend() - i - 1;
        }
    }
    return 0;
}

static inline cstring_span
front_value(const cstring_span& list) noexcept {
    const span_size_t k = element_header_size(list);
    const span_size_t l = element_value_size(list, k);
    return list.subspan(k, l);
}

static inline cstring_span
back_value(const cstring_span& list) noexcept {
    const span_size_t i = rev_seek_header_start(list);
    const cstring_span head = list.subspan(i);
    const span_size_t k = element_header_size(head);
    const span_size_t l = element_value_size(head, k);
    return list.subspan(i - l, l);
}

static inline cstring_span
pop_back(const cstring_span& list) noexcept {
    const span_size_t i = rev_seek_header_start(list);
    const cstring_span head = list.subspan(i);
    const span_size_t k = element_header_size(head);
    const span_size_t l = element_value_size(head, k);
    assert(i >= k + l);
    return list.subspan(0, i - k - l);
}

static inline void
push_back(std::string& list, const cstring_span& value) noexcept {
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

class element : public cstring_span {
private:
    cstring_span& _base() {
        return *this;
    }
    const cstring_span& _base() const {
        return *this;
    }

    static inline cstring_span _fit(const cstring_span& s) noexcept {
        span_size_t hs = element_header_size(s);
        span_size_t vs = element_value_size(s, hs);
        assert(s.size() >= hs + vs + hs);
        return {s.data(), hs + vs + hs};
    }

    static inline cstring_span _fit(
      const char* ptr, span_size_t max_size) noexcept {
        return _fit(cstring_span(ptr, max_size));
    }

    static inline cstring_span _rev_fit(
      const cstring_span& s, span_size_t rev_sz) noexcept {
        span_size_t hs = element_header_size(s);
        span_size_t vs = element_value_size(s, hs);
        assert(rev_sz >= hs + vs);
        return {s.data() - hs - vs, hs + vs + hs};
    }

    static inline cstring_span _rev_fit(
      const char* ptr, span_size_t rev_sz, span_size_t foot_sz) noexcept {
        return _rev_fit(cstring_span(ptr, foot_sz), rev_sz);
    }

public:
    element(const char* ptr, span_size_t max_size) noexcept
      : cstring_span(_fit(ptr, max_size)) {
    }

    element(const char* ptr, span_size_t rev_sz, span_size_t foot_sz) noexcept
      : cstring_span(_rev_fit(ptr, rev_sz, foot_sz)) {
    }

    span_size_t header_size() const noexcept {
        return element_header_size(_base());
    }

    cstring_span header() const noexcept {
        return {data(), header_size()};
    }

    span_size_t value_size() const noexcept {
        return element_value_size(header());
    }

    const char* value_data() const noexcept {
        return data() + header_size();
    }

    cstring_span value() const noexcept {
        return {value_data(), value_size()};
    }

    span_size_t footer_size() const noexcept {
        return element_header_size(_base());
    }

    cstring_span footer() const noexcept {
        return {data() + header_size() + value_size(), header_size()};
    }
};

template <typename Func>
static inline void
for_each_elem(const cstring_span& list, Func func) noexcept {
    span_size_t i = 0;
    bool first = true;
    while(i < list.size()) {
        element elem(list.data() + i, list.size() - i);
        func(elem, first);
        i += elem.size();
        first = false;
    }
}

template <typename Func>
static inline void
for_each(const cstring_span& list, Func func) noexcept {
    auto adapted_func = [&func](const element& elem, bool) {
        func(elem.value());
    };
    for_each_elem(list, adapted_func);
}

template <typename Func>
static inline void
rev_for_each_elem(const cstring_span& list, Func func) noexcept {
    span_size_t i = list.size() - 1;
    bool first = true;
    while(i > 0) {
        while(!mbs::is_valid_head_byte(byte(list[i]))) {
            assert(i > 0);
            --i;
        }
        element elem(list.data() + i, i, list.size() - i);
        func(elem, first);
        i -= elem.header_size() + elem.value_size() + 1;
        first = false;
    }
}

template <typename Func>
static inline void
rev_for_each(const cstring_span& list, Func func) noexcept {
    auto adapted_func = [&func](const element& elem, bool) {
        func(elem.value());
    };
    rev_for_each_elem(list, adapted_func);
}

static inline std::tuple<std::string, span_size_t>
split(const cstring_span& str, const cstring_span& sep) {
    std::string res;
    span_size_t cnt = 0;
    ranges::for_each_delimited(str, sep, [&res, &cnt](const auto& x) {
        push_back(res, x);
        ++cnt;
    });
    return std::make_tuple(res, cnt);
}

static inline std::string
join(const cstring_span& list, const cstring_span& sep, bool trail_sep) {
    span_size_t slen = sep.size();
    span_size_t len = trail_sep ? slen : 0;
    auto get_len = [&len, slen](const element& elem, bool first) {
        if(!first)
            len += slen;
        len += elem.value_size();
    };
    for_each_elem(list, get_len);

    std::string res;
    res.reserve(std_size(len));

    auto fill = [&res, sep](const element& elem, bool first) {
        if(!first)
            res.append(sep.data(), std_size(sep.size()));
        res.append(elem.value_data(), std_size(elem.value_size()));
    };
    for_each_elem(list, fill);

    if(trail_sep) {
        res.append(sep.data(), std_size(sep.size()));
    }
    assert(res.size() == std_size(len));

    return res;
}

static inline std::string
join(const cstring_span& list, const cstring_span& sep) {
    return join(list, sep, false);
}

template <typename Iter>
class iterator {
private:
    Iter _pos;
    mutable cstring_span _tmp;

    byte _b() const noexcept {
        assert(_pos != nullptr);
        return byte(*_pos);
    }

    span_size_t _len_len() const noexcept {
        byte b = _b();
        assert(mbs::is_valid_head_byte(b));
        return mbs::do_decode_sequence_length(b).value();
    }

    span_size_t _val_len(span_size_t ll) const noexcept {
        cstring_span el{_pos, ll};
        return mbs::do_decode_code_point(mbs::make_cbyte_span(el), ll);
    }

    void _update() const {
        if(_pos != nullptr && (_tmp.size() == 0)) {
            span_size_t ll = _len_len();
            span_size_t vl = _val_len(ll);
            _tmp = cstring_span{_pos + ll, vl};
        }
    }

public:
    typedef std::ptrdiff_t difference_type;
    typedef cstring_span value_type;
    typedef const value_type& reference;
    typedef const value_type* pointer;
    typedef std::forward_iterator_tag iterator_category;

    iterator() noexcept
      : _pos(nullptr) {
    }

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
        assert(_pos != nullptr);
        _update();
        return _tmp;
    }

    pointer operator->() const noexcept {
        assert(_pos != nullptr);
        _update();
        return &_tmp;
    }

    iterator& operator++() noexcept {
        assert(_pos != nullptr);
        span_size_t ll = _len_len();
        span_size_t vl = _val_len(ll);
        _pos += ll + vl + ll;
        _tmp = cstring_span();
        return *this;
    }

    iterator operator++(int) noexcept {
        iterator result = *this;
        ++(*this);
        return result;
    }
};

template <typename Iter>
class rev_iterator {
private:
    mutable Iter _pos;
    mutable cstring_span _tmp;

    byte _b() const noexcept {
        assert(_pos != nullptr);
        return byte(*_pos);
    }

    void _rseek_head() const noexcept {
        assert(_pos != nullptr);
        while(!mbs::is_valid_head_byte(_b())) {
            --_pos;
        }
    }

    span_size_t _len_len() const noexcept {
        byte b = _b();
        assert(mbs::is_valid_head_byte(b));
        return mbs::do_decode_sequence_length(b).value();
    }

    span_size_t _val_len(span_size_t ll) const noexcept {
        cstring_span el{_pos, ll};
        return mbs::do_decode_code_point(mbs::make_cbyte_span(el), ll);
    }

    void _update() const {
        if(_pos != nullptr && (_tmp.size() == 0)) {
            _rseek_head();
            span_size_t ll = _len_len();
            span_size_t vl = _val_len(ll);
            _tmp = cstring_span{_pos - vl, vl};
        }
    }

public:
    typedef std::ptrdiff_t difference_type;
    typedef cstring_span value_type;
    typedef const value_type& reference;
    typedef const value_type* pointer;
    typedef std::forward_iterator_tag iterator_category;

    rev_iterator() noexcept
      : _pos(nullptr) {
    }

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
        assert(_pos != nullptr);
        _update();
        return _tmp;
    }

    pointer operator->() const noexcept {
        assert(_pos != nullptr);
        _update();
        return &_tmp;
    }

    rev_iterator& operator++() noexcept {
        assert(_pos != nullptr);
        _rseek_head();
        span_size_t ll = _len_len();
        span_size_t vl = _val_len(ll);
        _pos -= ll + vl + 1;
        _tmp = cstring_span();
        return *this;
    }

    rev_iterator operator++(int) noexcept {
        rev_iterator result = *this;
        ++(*this);
        return result;
    }
};

} // namespace string_list
} // namespace eagine

#endif // include guard
