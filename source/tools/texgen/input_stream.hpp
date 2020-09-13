/**
 *  @file texgen/input_stream.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEXGEN_INPUT_STREAM_HPP
#define TEXGEN_INPUT_STREAM_HPP

#include "input_location.hpp"
#include <eagine/string_span.hpp>
#include <iosfwd>
#include <iterator>
#include <memory>

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
struct input_stream_intf {
    input_stream_intf() noexcept = default;
    input_stream_intf(input_stream_intf&&) noexcept = default;
    input_stream_intf(const input_stream_intf&) noexcept = default;
    input_stream_intf& operator=(input_stream_intf&&) noexcept = default;
    input_stream_intf& operator=(const input_stream_intf&) noexcept = default;

    virtual ~input_stream_intf() noexcept = default;

    virtual input_location location(span_size_t index) = 0;
    virtual char peek(span_size_t index) noexcept = 0;
    virtual bool consume(span_size_t count) = 0;
    virtual string_view head(span_size_t length) noexcept = 0;
};
//------------------------------------------------------------------------------
class input_stream_iter {
public:
    using value_type = char;
    using difference_type = std::ptrdiff_t;
    using reference = const char&;
    using pointer = const char*;
    using iterator_category = std::bidirectional_iterator_tag;

    input_stream_iter() noexcept = default;

    input_stream_iter(input_stream_intf* pimpl, span_size_t index) noexcept
      : _pimpl{pimpl}
      , _index{index} {
        if(_pimpl) {
            _element = _pimpl->peek(_index);
        }
    }

    input_stream_iter& operator++() noexcept {
        ++_index;
        _element = _pimpl->peek(_index);
        return *this;
    }

    input_stream_iter operator++(int) noexcept {
        input_stream_iter res(*this);
        ++_index;
        _element = _pimpl->peek(_index);
        return res;
    }

    input_stream_iter& operator--() noexcept {
        --_index;
        _element = _pimpl->peek(_index);
        return *this;
    }

    input_stream_iter operator--(int) noexcept {
        input_stream_iter res(*this);
        --_index;
        _element = _pimpl->peek(_index);
        return res;
    }

    reference operator*() const noexcept {
        return _element;
    }

    friend bool operator==(
      const input_stream_iter& l,
      const input_stream_iter& r) noexcept {
        return (l.at_end() && r.at_end()) ||
               ((l._index == r._index) && (l._pimpl == r._pimpl));
    }

    friend bool operator!=(
      const input_stream_iter& l,
      const input_stream_iter& r) noexcept {
        return !(l == r);
    }

    bool at_end() const noexcept {
        return !_pimpl || (_index < 0) || !_pimpl->peek(_index);
    }

private:
    input_stream_intf* _pimpl{nullptr};
    span_size_t _index{-1};
    char _element{};
};
//------------------------------------------------------------------------------
class input_stream {
public:
    using iterator = input_stream_iter;
    using const_iterator = input_stream_iter;

    input_stream(std::unique_ptr<input_stream_intf> pimpl)
      : _pimpl(std::move(pimpl)) {}

    input_stream(std::istream& input);

    input_location location(span_size_t index = 0) {
        if(_pimpl) {
            return _pimpl->location(index);
        }
        return {};
    }

    char peek(span_size_t index = 0) {
        if(_pimpl) {
            return _pimpl->peek(index);
        }
        return char(0);
    }

    bool consume(span_size_t count = 1) {
        if(_pimpl) {
            return _pimpl->consume(count);
        }
        return false;
    }

    string_view head(span_size_t length) {
        if(_pimpl) {
            return _pimpl->head(length);
        }
        return {};
    }

    auto begin() const {
        return const_iterator(_pimpl.get(), 0);
    }

    auto end() const {
        return const_iterator();
    }

private:
    std::unique_ptr<input_stream_intf> _pimpl;
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen

#endif // TEXGEN_INPUT_STREAM_HPP
