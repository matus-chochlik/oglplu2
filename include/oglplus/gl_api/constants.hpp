/**
 *  @file oglplus/gl_api/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_CONSTANTS_HPP
#define OGLPLUS_GL_API_CONSTANTS_HPP

#include "c_api.hpp"
#include "enum_types.hpp"

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
struct basic_gl_constants {
public:
    using enum_type = typename gl_types::enum_type;
    using enum_type_i = identity<enum_type>;
    template <enum_type value>
    using enum_type_c = std::integral_constant<enum_type, value>;

    using bitfield_type = typename gl_types::bitfield_type;
    using bitfield_type_i = identity<bitfield_type>;
    template <bitfield_type value>
    using bitfield_type_c = std::integral_constant<bitfield_type, value>;

    opt_c_api_constant<
      mp_list<error_code>,
#ifdef GL_NO_ERROR
      enum_type_c<GL_NO_ERROR>>
#else
      enum_type_i>
#endif
      no_error;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_BLEND
      enum_type_c<GL_BLEND>>
#else
      enum_type_i>
#endif
      blend;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_CULL_FACE
      enum_type_c<GL_CULL_FACE>>
#else
      enum_type_i>
#endif
      cull_face;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_DEPTH_CLAMP
      enum_type_c<GL_DEPTH_CLAMP>>
#else
      enum_type_i>
#endif
      depth_clamp;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_DEPTH_TEST
      enum_type_c<GL_DEPTH_TEST>>
#else
      enum_type_i>
#endif
      depth_test;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_SCISSOR_TEST
      enum_type_c<GL_SCISSOR_TEST>>
#else
      enum_type_i>
#endif
      scissor_test;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_STENCIL_TEST
      enum_type_c<GL_STENCIL_TEST>>
#else
      enum_type_i>
#endif
      stencil_test;

    opt_c_api_constant<
      mp_list<capability>,
#ifdef GL_MULTISAMPLE
      enum_type_c<GL_MULTISAMPLE>>
#else
      enum_type_i>
#endif
      multisample;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_VENDOR
      enum_type_c<GL_VENDOR>>
#else
      enum_type_i>
#endif
      vendor;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_RENDERER
      enum_type_c<GL_RENDERER>>
#else
      enum_type_i>
#endif
      renderer;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_VERSION
      enum_type_c<GL_VERSION>>
#else
      enum_type_i>
#endif
      version;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_SHADING_LANGUAGE_VERSION
      enum_type_c<GL_SHADING_LANGUAGE_VERSION>>
#else
      enum_type_i>
#endif
      shading_language_version;

    opt_c_api_constant<
      mp_list<string_query>,
#ifdef GL_EXTENSIONS
      enum_type_c<GL_EXTENSIONS>>
#else
      enum_type_i>
#endif
      extensions;

    opt_c_api_constant<
      mp_list<buffer_clear_bit>,
#ifdef GL_COLOR_BUFFER_BIT
      bitfield_type_c<GL_COLOR_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      color_buffer_bit;

    opt_c_api_constant<
      mp_list<buffer_clear_bit>,
#ifdef GL_DEPTH_BUFFER_BIT
      bitfield_type_c<GL_DEPTH_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      depth_buffer_bit;

    opt_c_api_constant<
      mp_list<buffer_clear_bit>,
#ifdef GL_STENCIL_BUFFER_BIT
      bitfield_type_c<GL_STENCIL_BUFFER_BIT>>
#else
      bitfield_type_i>
#endif
      stencil_buffer_bit;

    opt_c_api_constant<
      mp_list<texture_compare_mode>,
#ifdef GL_NONE
      bitfield_type_c<GL_NONE>>
#else
      bitfield_type_i>
#endif
      none;

    basic_gl_constants(ApiTraits& traits, basic_gl_c_api<ApiTraits>& api)
      : no_error("NO_ERROR", traits, api)
      , blend("BLEND", traits, api)
      , cull_face("CULL_FACE", traits, api)
      , depth_clamp("DEPTH_CLAMP", traits, api)
      , depth_test("DEPTH_TEST", traits, api)
      , scissor_test("SCISSOR_TEST", traits, api)
      , stencil_test("STENCIL_TEST", traits, api)
      , multisample("MULTISAMPLE", traits, api)
      , vendor("VENDOR", traits, api)
      , renderer("RENDERER", traits, api)
      , version("VERSION", traits, api)
      , shading_language_version("SHADING_LANGUAGE_VERSION", traits, api)
      , extensions("EXTENSIONS", traits, api)
      , color_buffer_bit("COLOR_BUFFER_BIT", traits, api)
      , depth_buffer_bit("DEPTH_BUFFER_BIT", traits, api)
      , stencil_buffer_bit("STENCIL_BUFFER_BIT", traits, api)
      , none("NONE", traits, api) {
    }
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_CONSTANTS_HPP

