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

#include "callable_ref.hpp"
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

    using data_handler = callable_ref<bool(memory::const_block)>;

    auto compress(
      memory::const_block input,
      const data_handler& handler,
      data_compression_level level) -> bool;

    auto compress(
      memory::const_block input,
      memory::buffer& output,
      data_compression_level level) -> memory::const_block;

    auto compress(memory::const_block input, memory::buffer& output)
      -> memory::const_block {
        return compress(input, output, data_compression_level::normal);
    }

    auto compress(memory::const_block input, data_compression_level level)
      -> memory::const_block;

    auto decompress(memory::const_block input, const data_handler& handler)
      -> bool;

    auto decompress(memory::const_block input, memory::buffer& output)
      -> memory::const_block;

    auto decompress(memory::const_block input) -> memory::const_block;

private:
    std::shared_ptr<data_compressor_impl> _pimpl{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/compression.inl>
#endif

#endif // EAGINE_COMPRESSION_HPP
