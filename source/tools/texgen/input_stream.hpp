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

#include <oglplus/utils/string_span.hpp>
#include <iosfwd>
#include <memory>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
class input_location {
public:
private:
    span_size_t _line;
    span_size_t _column;
};
//------------------------------------------------------------------------------
struct input_stream_intf {
    input_stream_intf() noexcept = default;
    input_stream_intf(input_stream_intf&&) noexcept = default;
    input_stream_intf(const input_stream_intf&) noexcept = default;
    input_stream_intf& operator=(input_stream_intf&&) noexcept = default;
    input_stream_intf& operator=(const input_stream_intf&) noexcept = default;

    virtual ~input_stream_intf() noexcept = default;

    virtual char peek(span_size_t index) = 0;
    virtual bool pop(span_size_t count) = 0;
};
//------------------------------------------------------------------------------
class input_stream {
public:
    input_stream(std::unique_ptr<input_stream_intf> pimpl)
      : _pimpl(std::move(pimpl)) {
    }

    input_stream(std::istream& input);

    char peek(span_size_t index = 0) {
        if(_pimpl) {
            return _pimpl->peek(index);
        }
        return char(0);
    }
    bool pop(span_size_t count = 1) {
        if(_pimpl) {
            return _pimpl->pop(count);
        }
        return false;
    }

private:
    std::unique_ptr<input_stream_intf> _pimpl;
};
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus

#endif // TEXGEN_INPUT_STREAM_HPP
