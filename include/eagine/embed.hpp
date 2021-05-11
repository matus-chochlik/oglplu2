/// @file
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
#include "main_ctx_object.hpp"
#include "memory/copy.hpp"
#include "string_span.hpp"

namespace eagine {

/// @brief Class providing access to a const resource block embedded into the executable.
/// @ingroup embedding
/// @see embed
class embedded_resource {
public:
    /// @brief Default constructor.
    constexpr embedded_resource() noexcept = default;

    constexpr embedded_resource(
      memory::const_block blk,
      string_view src_path,
      bool packed = false) noexcept
      : _res_blk{blk}
      , _src_path{src_path}
      , _packed{packed} {}

    /// @brief Returns the path of the file this resource data comes from.
    constexpr auto source_path() const noexcept -> string_view {
        return _src_path;
    }

    /// @brief Indicates if the resource is packed and needs to be decompressed.
    /// @see decompress
    constexpr auto is_packed() const noexcept -> bool {
        return _packed;
    }

    /// @brief Implicit conversion to const block.
    constexpr operator memory::const_block() const noexcept {
        EAGINE_ASSERT(!is_packed());
        return _res_blk;
    }

    /// @brief Unpacks this resource into a buffer using the provided compressor.
    /// @see is_packed
    auto unpack(data_compressor& comp, memory::buffer& buf) const
      -> memory::const_block {
        if(is_packed()) {
            return {comp.decompress(_res_blk, buf)};
        }
        return copy_into(_res_blk, buf);
    }

    /// @brief Unpacks this resource into a buffer using compressor from main context.
    /// @see is_packed
    auto unpack(main_ctx& ctx) const -> memory::const_block {
        return unpack(ctx.compressor(), ctx.scratch_space());
    }

    /// @brief Unpacks this resource using compressor from a main context object.
    /// @see is_packed
    auto unpack(main_ctx_object& mco) const -> memory::const_block {
        return unpack(mco.main_context());
    }

private:
    memory::const_block _res_blk{};
    string_view _src_path{};
    bool _packed{false};
};

/// @brief Converts the embedded resource block to a const span of characters.
/// @ingroup embedding
/// @relates embedded_resource
static inline auto as_chars(const embedded_resource& res) noexcept {
    return as_chars(memory::const_block{res});
}

extern auto
get_embedded_resource(identifier res_id, string_view src_path) noexcept
  -> embedded_resource;

/// @brief Triggers the embedding of data from a file on the specified path.
/// @ingroup embedding
/// @see embedded_resource
///
/// This function only works properly if the build system invokes the embed
/// generator, that generates appropriate C++ code that defines byte blocks
/// with the content of the specified resource files, compiles them and links
/// them into the built executable.
/// The embed generator is installed as one of the tools and in cmake-based
/// build systems the eagine_embed_packed_target_resources and
/// eagine_embed_target_resources cmake functions can be used invoke it.
static inline auto embed(identifier res_id, string_view src_path) noexcept
  -> embedded_resource {
    return get_embedded_resource(res_id, src_path);
}

} // namespace eagine

#endif // EAGINE_EMBED_HPP
