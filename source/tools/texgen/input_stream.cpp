/**
 *  @file texgen/input_stream.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "input_stream.hpp"
#include <eagine/assert.hpp>
#include <eagine/memory/span_algo.hpp>
#include <istream>
#include <vector>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
class istream_impl : public input_stream_intf {
public:
    explicit istream_impl(std::istream& input) noexcept
      : _input(input) {
    }

    char peek(span_size_t index) noexcept override {
        try {
            if(_ensure_cached(index + 1)) {
                return _cache[std_size(index)];
            }
        } catch(...) {
        }
        return char(0);
    }

    bool consume(span_size_t count) override {
        if(_ensure_cached(count)) {
            _cache.erase(_cache.begin(), _cache.begin() + count);
            _locs.erase(_locs.begin(), _locs.begin() + count);
            return true;
        }
        _cache.clear();
        _locs.clear();
        return false;
    }

    input_location location(span_size_t index) override {
        if(_ensure_cached(index + 1)) {
            return _locs[std_size(index)];
        }
        return {};
    }

    string_view head(span_size_t length) noexcept override {
        try {
            _ensure_cached(length);
        } catch(...) {
        }
        return eagine::memory::head(string_view(_cache), length);
    }

private:
    bool _ensure_cached(span_size_t count) {
        EAGINE_ASSERT(_cache.size() == _locs.size());
        while(_input.good() && (span_size(_cache.size()) < count)) {
            _cache.push_back(_input.get());
            if(_locs.empty()) {
                _locs.emplace_back();
            } else {
                _locs.emplace_back(_locs.back() + _cache.back());
            }
        }
        EAGINE_ASSERT(_cache.size() == _locs.size());
        return span_size(_cache.size()) >= count;
    }

    std::istream& _input;
    std::vector<char> _cache;
    std::vector<input_location> _locs;
};
//------------------------------------------------------------------------------
input_stream::input_stream(std::istream& input)
  : input_stream(std::make_unique<istream_impl>(input)) {
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
