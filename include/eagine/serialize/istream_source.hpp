/**
 *  @file eagine/serialize/istream_source.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_ISTREAM_SOURCE_HPP
#define EAGINE_SERIALIZE_ISTREAM_SOURCE_HPP

#include "../memory/buffer.hpp"
#include "../memory/span_algo.hpp"
#include "data_source.hpp"
#include <istream>

namespace eagine {
//------------------------------------------------------------------------------
class istream_data_source : public deserializer_data_source {
public:
    istream_data_source(std::istream& in) noexcept
      : _in{in} {
    }

    memory::const_block top(span_size_t req_size) final {
        if(_cur_size < req_size) {
            while(_storage.size() < _cur_size + req_size) {
                _storage.resize(_storage.size() + _chunk_size());
            }
            _in.read(
              reinterpret_cast<char*>(_storage.data()) + _cur_size,
              static_cast<std::streamsize>(req_size - _cur_size));
            _cur_size += span_size_t(_in.gcount());
        }
        return head(head(view(_storage), _cur_size), req_size);
    }

    void pop(span_size_t del_size) final {
        if(_cur_size <= del_size) {
            _cur_size = 0;
            if(_storage.size() > _chunk_size()) {
                _storage.resize(_chunk_size());
            }
        } else {
            auto sw = head(cover(_storage), _cur_size);
            memory::copy(skip(sw, del_size), sw);
            _cur_size -= del_size;
        }
    }

private:
    static constexpr span_size_t _chunk_size() noexcept {
        return 8 * 1024;
    }

    std::istream& _in;
    span_size_t _cur_size{0};
    memory::buffer _storage{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_ISTREAM_SOURCE_HPP

