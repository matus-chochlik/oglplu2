/**
 *  @file eagine/serialize/block_source.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_BLOCK_SOURCE_HPP
#define EAGINE_SERIALIZE_BLOCK_SOURCE_HPP

#include "../memory/buffer.hpp"
#include "../memory/span_algo.hpp"
#include "data_source.hpp"
#include <istream>

namespace eagine {
//------------------------------------------------------------------------------
class block_data_source : public deserializer_data_source {
public:
    block_data_source(memory::const_block src) noexcept
      : _src{src} {
    }

    memory::const_block top(span_size_t req_size) final {
        return head(skip(_src, _done), req_size);
    }

    void pop(span_size_t del_size) final {
        _done += del_size;
    }

private:
    memory::const_block _src;
    span_size_t _done{0};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_BLOCK_SOURCE_HPP

