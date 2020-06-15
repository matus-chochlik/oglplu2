/**
 *  @file eagine/compression.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_COMPRESSION_HPP
#define EAGINE_COMPRESSION_HPP

#include "memory/block.hpp"
#include "memory/buffer.hpp"
#include <memory>

namespace eagine {
//------------------------------------------------------------------------------
enum class data_compression_level { none, lowest, normal, highest };
//------------------------------------------------------------------------------
class data_compressor_impl;
class data_compressor {
public:
    data_compressor();

    memory::const_block compress(
      memory::const_block input,
      memory::buffer& output,
      data_compression_level level);

    memory::const_block compress(
      memory::const_block input, memory::buffer& output) {
        return compress(input, output, data_compression_level::normal);
    }

    memory::const_block decompress(
      memory::const_block input, memory::buffer& output);

private:
    std::shared_ptr<data_compressor_impl> _pimpl{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/compression.inl>
#endif

#endif // EAGINE_COMPRESSION_HPP
