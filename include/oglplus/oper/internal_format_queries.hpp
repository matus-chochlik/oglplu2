/**
 *  @file oglplus/oper/internal_format_queries.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_INTERNAL_FORMAT_QUERIES_1509260923_HPP
#define OGLPLUS_OPER_INTERNAL_FORMAT_QUERIES_1509260923_HPP

#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/boolean.hpp"
#include "../utils/gl_func.hpp"
#include "../utils/span.hpp"

namespace oglplus {
namespace oper {

struct internal_format_queries {
#if defined(GL_VERSION_4_2)
    static outcome<void> get_internal_format_iv(internal_format_target target,
      pixel_data_internal_format iformat,
      internal_format_parameter param,
      span<GLint> data) noexcept;

    template <typename Result, typename Temp = Result>
    static outcome<Result> return_internal_format_i(
      internal_format_target target,
      pixel_data_internal_format iformat,
      internal_format_parameter param) noexcept;
#endif

#if defined(GL_VERSION_4_3)
    static outcome<void> get_internal_format_i64v(internal_format_target target,
      pixel_data_internal_format iformat,
      internal_format_parameter param,
      span<GLint64> data) noexcept;

    template <typename Result, typename Temp = Result>
    static outcome<Result> return_internal_format_i64(
      internal_format_target target,
      pixel_data_internal_format iformat,
      internal_format_parameter param) noexcept;

    static outcome<boolean> is_internal_format_supported(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;

    static outcome<boolean> is_internal_format_preferred(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;

    static outcome<boolean> is_internal_format_compressed(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;

    static outcome<boolean> has_internal_format_color_components(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;

    static outcome<boolean> has_internal_format_depth_components(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;

    static outcome<boolean> has_internal_format_stencil_components(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;

    static outcome<boolean> supports_internal_format_framebuffer_blend(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;

    static outcome<boolean> supports_internal_format_mipmap(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;

    static outcome<boolean> supports_internal_format_filter(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;

    static outcome<support_level>
    get_internal_format_framebuffer_renderable_support(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;

    static outcome<support_level>
    get_internal_format_framebuffer_renderable_layered_support(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;

    static outcome<support_level> get_internal_format_read_pixels_support(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;

#if defined(GL_GENERATE_MIPMAP)
    static outcome<support_level> get_internal_format_generate_mipmap_support(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;
#endif

    static outcome<support_level>
    get_internal_format_auto_generate_mipmap_support(
      internal_format_target target,
      pixel_data_internal_format iformat) noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/internal_format_queries.inl>

#endif // include guard
