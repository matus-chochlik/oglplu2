/// @file eagine/embed.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_EMBED_HPP
#define EAGINE_EMBED_HPP

#include "assert.hpp"
#include "compression.hpp"
#include "identifier.hpp"
#include "int_constant.hpp"
#include "main_ctx.hpp"
#include "memory/copy.hpp"
#include "string_span.hpp"

namespace eagine {

class embedded_resource {
    memory::const_block _res_blk{};
    string_view _src_path{};
    bool _packed{false};

public:
    constexpr embedded_resource() noexcept = default;

    constexpr embedded_resource(
      memory::const_block blk,
      string_view src_path,
      bool packed = false) noexcept
      : _res_blk{blk}
      , _src_path{src_path}
      , _packed{packed} {}

    constexpr auto source_path() const noexcept -> string_view {
        return _src_path;
    }

    constexpr auto is_packed() const noexcept -> bool {
        return _packed;
    }

    constexpr operator memory::const_block() const noexcept {
        EAGINE_ASSERT(!is_packed());
        return _res_blk;
    }

    auto unpack(data_compressor& comp, memory::buffer& buf) const
      -> memory::const_block {
        if(is_packed()) {
            return {comp.decompress(_res_blk, buf)};
        }
        return copy_into(_res_blk, buf);
    }

    auto unpack(main_ctx& ctx) const -> memory::const_block {
        return unpack(ctx.compressor(), ctx.scratch_space());
    }

    auto unpack(main_ctx_object& mco) const -> memory::const_block {
        return unpack(mco.main_context());
    }
};

static inline auto as_chars(const embedded_resource& res) noexcept {
    return as_chars(memory::const_block{res});
}

extern auto
get_embedded_resource(identifier res_id, string_view src_path) noexcept
  -> embedded_resource;

static inline auto embed(identifier res_id, string_view src_path) noexcept {
    return get_embedded_resource(res_id, src_path);
}

} // namespace eagine

#endif // EAGINE_EMBED_HPP
