/**
 *  @file texgen/input_stream.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "input_stream.hpp"
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

    char peek(span_size_t index) override {
        if(_ensure_cached(index + 1)) {
            return _cache[std_size(index)];
        }
        return char(0);
    }

    bool pop(span_size_t count) override {
        if(_ensure_cached(count)) {
            _cache.erase(_cache.begin(), _cache.begin() + count);
            return true;
        }
        _cache.clear();
        return false;
    }

private:
    bool _ensure_cached(span_size_t count) {
        while(_input.good() && (span_size(_cache.size()) < count)) {
            _cache.push_back(_input.get());
        }
        return span_size(_cache.size()) >= count;
    }

    std::istream& _input;
    std::vector<char> _cache;
};
//------------------------------------------------------------------------------
input_stream::input_stream(std::istream& input)
  : input_stream(std::make_unique<istream_impl>(input)) {
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
