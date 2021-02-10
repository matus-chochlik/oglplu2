/**
 *  @file eagine/serialize/packed_block_source.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_PACKED_BLOCK_SOURCE_HPP
#define EAGINE_SERIALIZE_PACKED_BLOCK_SOURCE_HPP

#include "../compression.hpp"
#include "block_source.hpp"

namespace eagine {
//------------------------------------------------------------------------------
class packed_block_data_source : public block_data_source {
public:
    packed_block_data_source() noexcept = default;

    packed_block_data_source(
      data_compressor compressor,
      memory::const_block src) noexcept
      : _compressor{std::move(compressor)} {
        reset(src);
    }

    packed_block_data_source(memory::const_block src) noexcept
      : packed_block_data_source{{}, src} {}

    packed_block_data_source(data_compressor compressor) noexcept
      : packed_block_data_source{std::move(compressor), {}} {}

    void reset(memory::const_block src) {
        block_data_source::reset(_compressor.decompress(src));
    }

private:
    data_compressor _compressor{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_PACKED_BLOCK_SOURCE_HPP
