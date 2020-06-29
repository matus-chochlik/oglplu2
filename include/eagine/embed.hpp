/**
 *  @file eagine/embed.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_EMBED_HPP
#define EAGINE_EMBED_HPP

#include "assert.hpp"
#include "compression.hpp"
#include "identifier.hpp"
#include "int_constant.hpp"
#include "memory/buffer.hpp"
#include "memory/span_algo.hpp"
#include "string_span.hpp"

namespace eagine {

class embedded_resource {
    memory::const_block _res_blk{};
    string_view _src_path{};
    bool _packed{false};

public:
    embedded_resource() noexcept = default;

    embedded_resource(
      memory::const_block blk,
      string_view src_path,
      bool packed = false) noexcept
      : _res_blk{blk}
      , _src_path{src_path}
      , _packed{packed} {
    }

    bool is_packed() const noexcept {
        return _packed;
    }

    operator memory::const_block() const noexcept {
        EAGINE_ASSERT(!is_packed());
        return _res_blk;
    }

    memory::const_block unpack(
      data_compressor& comp, memory::buffer& buf) const noexcept {
        EAGINE_ASSERT(is_packed());
        return {comp.decompress(_res_blk, buf)};
    }
};

static inline auto as_chars(const embedded_resource& res) noexcept {
    return as_chars(memory::const_block{res});
}

extern embedded_resource get_embedded_resource(
  identifier res_id, string_view src_path) noexcept;

static inline embedded_resource embed(
  identifier res_id, string_view src_path) noexcept {
    return get_embedded_resource(res_id, src_path);
}

} // namespace eagine

#endif // EAGINE_EMBED_HPP
