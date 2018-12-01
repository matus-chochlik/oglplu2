//  File test/boost_test/oglplus/enums/internal_format_parameter.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
#include "common.hpp"
#define BOOST_TEST_MODULE OGLPLUS_internal_format_parameter

#include <cstring>
#include "../../unit_test_begin.inl"

BOOST_AUTO_TEST_SUITE(enum_internal_format_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_internal_format_parameter_values) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    internal_format_parameter x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_AUTO_GENERATE_MIPMAP
    x = ev.auto_generate_mipmap;
    BOOST_CHECK(x == ev.auto_generate_mipmap);
#ifdef GL_CLEAR_BUFFER
    BOOST_CHECK(x != ev.clear_buffer);
#endif
#ifdef GL_CLEAR_TEXTURE
    BOOST_CHECK(x != ev.clear_texture);
#endif
#ifdef GL_COLOR_COMPONENTS
    BOOST_CHECK(x != ev.color_components);
#endif
#ifdef GL_COLOR_ENCODING
    BOOST_CHECK(x != ev.color_encoding);
#endif
#ifdef GL_COLOR_RENDERABLE
    BOOST_CHECK(x != ev.color_renderable);
#endif
#ifdef GL_COMPUTE_TEXTURE
    BOOST_CHECK(x != ev.compute_texture);
#endif
#ifdef GL_DEPTH_COMPONENTS
    BOOST_CHECK(x != ev.depth_components);
#endif
#ifdef GL_DEPTH_RENDERABLE
    BOOST_CHECK(x != ev.depth_renderable);
#endif
#ifdef GL_FILTER
    BOOST_CHECK(x != ev.filter);
#endif
#ifdef GL_FRAGMENT_TEXTURE
    BOOST_CHECK(x != ev.fragment_texture);
#endif
#ifdef GL_FRAMEBUFFER_BLEND
    BOOST_CHECK(x != ev.framebuffer_blend);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE
    BOOST_CHECK(x != ev.framebuffer_renderable);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_CLEAR_BUFFER
    x = ev.clear_buffer;
    BOOST_CHECK(x == ev.clear_buffer);
#ifdef GL_CLEAR_TEXTURE
    BOOST_CHECK(x != ev.clear_texture);
#endif
#ifdef GL_COLOR_COMPONENTS
    BOOST_CHECK(x != ev.color_components);
#endif
#ifdef GL_COLOR_ENCODING
    BOOST_CHECK(x != ev.color_encoding);
#endif
#ifdef GL_COLOR_RENDERABLE
    BOOST_CHECK(x != ev.color_renderable);
#endif
#ifdef GL_COMPUTE_TEXTURE
    BOOST_CHECK(x != ev.compute_texture);
#endif
#ifdef GL_DEPTH_COMPONENTS
    BOOST_CHECK(x != ev.depth_components);
#endif
#ifdef GL_DEPTH_RENDERABLE
    BOOST_CHECK(x != ev.depth_renderable);
#endif
#ifdef GL_FILTER
    BOOST_CHECK(x != ev.filter);
#endif
#ifdef GL_FRAGMENT_TEXTURE
    BOOST_CHECK(x != ev.fragment_texture);
#endif
#ifdef GL_FRAMEBUFFER_BLEND
    BOOST_CHECK(x != ev.framebuffer_blend);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE
    BOOST_CHECK(x != ev.framebuffer_renderable);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_CLEAR_TEXTURE
    x = ev.clear_texture;
    BOOST_CHECK(x == ev.clear_texture);
#ifdef GL_COLOR_COMPONENTS
    BOOST_CHECK(x != ev.color_components);
#endif
#ifdef GL_COLOR_ENCODING
    BOOST_CHECK(x != ev.color_encoding);
#endif
#ifdef GL_COLOR_RENDERABLE
    BOOST_CHECK(x != ev.color_renderable);
#endif
#ifdef GL_COMPUTE_TEXTURE
    BOOST_CHECK(x != ev.compute_texture);
#endif
#ifdef GL_DEPTH_COMPONENTS
    BOOST_CHECK(x != ev.depth_components);
#endif
#ifdef GL_DEPTH_RENDERABLE
    BOOST_CHECK(x != ev.depth_renderable);
#endif
#ifdef GL_FILTER
    BOOST_CHECK(x != ev.filter);
#endif
#ifdef GL_FRAGMENT_TEXTURE
    BOOST_CHECK(x != ev.fragment_texture);
#endif
#ifdef GL_FRAMEBUFFER_BLEND
    BOOST_CHECK(x != ev.framebuffer_blend);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE
    BOOST_CHECK(x != ev.framebuffer_renderable);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_COLOR_COMPONENTS
    x = ev.color_components;
    BOOST_CHECK(x == ev.color_components);
#ifdef GL_COLOR_ENCODING
    BOOST_CHECK(x != ev.color_encoding);
#endif
#ifdef GL_COLOR_RENDERABLE
    BOOST_CHECK(x != ev.color_renderable);
#endif
#ifdef GL_COMPUTE_TEXTURE
    BOOST_CHECK(x != ev.compute_texture);
#endif
#ifdef GL_DEPTH_COMPONENTS
    BOOST_CHECK(x != ev.depth_components);
#endif
#ifdef GL_DEPTH_RENDERABLE
    BOOST_CHECK(x != ev.depth_renderable);
#endif
#ifdef GL_FILTER
    BOOST_CHECK(x != ev.filter);
#endif
#ifdef GL_FRAGMENT_TEXTURE
    BOOST_CHECK(x != ev.fragment_texture);
#endif
#ifdef GL_FRAMEBUFFER_BLEND
    BOOST_CHECK(x != ev.framebuffer_blend);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE
    BOOST_CHECK(x != ev.framebuffer_renderable);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_COLOR_ENCODING
    x = ev.color_encoding;
    BOOST_CHECK(x == ev.color_encoding);
#ifdef GL_COLOR_RENDERABLE
    BOOST_CHECK(x != ev.color_renderable);
#endif
#ifdef GL_COMPUTE_TEXTURE
    BOOST_CHECK(x != ev.compute_texture);
#endif
#ifdef GL_DEPTH_COMPONENTS
    BOOST_CHECK(x != ev.depth_components);
#endif
#ifdef GL_DEPTH_RENDERABLE
    BOOST_CHECK(x != ev.depth_renderable);
#endif
#ifdef GL_FILTER
    BOOST_CHECK(x != ev.filter);
#endif
#ifdef GL_FRAGMENT_TEXTURE
    BOOST_CHECK(x != ev.fragment_texture);
#endif
#ifdef GL_FRAMEBUFFER_BLEND
    BOOST_CHECK(x != ev.framebuffer_blend);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE
    BOOST_CHECK(x != ev.framebuffer_renderable);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_COLOR_RENDERABLE
    x = ev.color_renderable;
    BOOST_CHECK(x == ev.color_renderable);
#ifdef GL_COMPUTE_TEXTURE
    BOOST_CHECK(x != ev.compute_texture);
#endif
#ifdef GL_DEPTH_COMPONENTS
    BOOST_CHECK(x != ev.depth_components);
#endif
#ifdef GL_DEPTH_RENDERABLE
    BOOST_CHECK(x != ev.depth_renderable);
#endif
#ifdef GL_FILTER
    BOOST_CHECK(x != ev.filter);
#endif
#ifdef GL_FRAGMENT_TEXTURE
    BOOST_CHECK(x != ev.fragment_texture);
#endif
#ifdef GL_FRAMEBUFFER_BLEND
    BOOST_CHECK(x != ev.framebuffer_blend);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE
    BOOST_CHECK(x != ev.framebuffer_renderable);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_COMPUTE_TEXTURE
    x = ev.compute_texture;
    BOOST_CHECK(x == ev.compute_texture);
#ifdef GL_DEPTH_COMPONENTS
    BOOST_CHECK(x != ev.depth_components);
#endif
#ifdef GL_DEPTH_RENDERABLE
    BOOST_CHECK(x != ev.depth_renderable);
#endif
#ifdef GL_FILTER
    BOOST_CHECK(x != ev.filter);
#endif
#ifdef GL_FRAGMENT_TEXTURE
    BOOST_CHECK(x != ev.fragment_texture);
#endif
#ifdef GL_FRAMEBUFFER_BLEND
    BOOST_CHECK(x != ev.framebuffer_blend);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE
    BOOST_CHECK(x != ev.framebuffer_renderable);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_DEPTH_COMPONENTS
    x = ev.depth_components;
    BOOST_CHECK(x == ev.depth_components);
#ifdef GL_DEPTH_RENDERABLE
    BOOST_CHECK(x != ev.depth_renderable);
#endif
#ifdef GL_FILTER
    BOOST_CHECK(x != ev.filter);
#endif
#ifdef GL_FRAGMENT_TEXTURE
    BOOST_CHECK(x != ev.fragment_texture);
#endif
#ifdef GL_FRAMEBUFFER_BLEND
    BOOST_CHECK(x != ev.framebuffer_blend);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE
    BOOST_CHECK(x != ev.framebuffer_renderable);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_DEPTH_RENDERABLE
    x = ev.depth_renderable;
    BOOST_CHECK(x == ev.depth_renderable);
#ifdef GL_FILTER
    BOOST_CHECK(x != ev.filter);
#endif
#ifdef GL_FRAGMENT_TEXTURE
    BOOST_CHECK(x != ev.fragment_texture);
#endif
#ifdef GL_FRAMEBUFFER_BLEND
    BOOST_CHECK(x != ev.framebuffer_blend);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE
    BOOST_CHECK(x != ev.framebuffer_renderable);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_FILTER
    x = ev.filter;
    BOOST_CHECK(x == ev.filter);
#ifdef GL_FRAGMENT_TEXTURE
    BOOST_CHECK(x != ev.fragment_texture);
#endif
#ifdef GL_FRAMEBUFFER_BLEND
    BOOST_CHECK(x != ev.framebuffer_blend);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE
    BOOST_CHECK(x != ev.framebuffer_renderable);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_FRAGMENT_TEXTURE
    x = ev.fragment_texture;
    BOOST_CHECK(x == ev.fragment_texture);
#ifdef GL_FRAMEBUFFER_BLEND
    BOOST_CHECK(x != ev.framebuffer_blend);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE
    BOOST_CHECK(x != ev.framebuffer_renderable);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_FRAMEBUFFER_BLEND
    x = ev.framebuffer_blend;
    BOOST_CHECK(x == ev.framebuffer_blend);
#ifdef GL_FRAMEBUFFER_RENDERABLE
    BOOST_CHECK(x != ev.framebuffer_renderable);
#endif
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_FRAMEBUFFER_RENDERABLE
    x = ev.framebuffer_renderable;
    BOOST_CHECK(x == ev.framebuffer_renderable);
#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    BOOST_CHECK(x != ev.framebuffer_renderable_layered);
#endif
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    x = ev.framebuffer_renderable_layered;
    BOOST_CHECK(x == ev.framebuffer_renderable_layered);
#ifdef GL_GENERATE_MIPMAP
    BOOST_CHECK(x != ev.generate_mipmap);
#endif
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_GENERATE_MIPMAP
    x = ev.generate_mipmap;
    BOOST_CHECK(x == ev.generate_mipmap);
#ifdef GL_GEOMETRY_TEXTURE
    BOOST_CHECK(x != ev.geometry_texture);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_GEOMETRY_TEXTURE
    x = ev.geometry_texture;
    BOOST_CHECK(x == ev.geometry_texture);
#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.get_texture_image_format);
#endif
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    x = ev.get_texture_image_format;
    BOOST_CHECK(x == ev.get_texture_image_format);
#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.get_texture_image_type);
#endif
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    x = ev.get_texture_image_type;
    BOOST_CHECK(x == ev.get_texture_image_type);
#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.image_compatibility_class);
#endif
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    x = ev.image_compatibility_class;
    BOOST_CHECK(x == ev.image_compatibility_class);
#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    BOOST_CHECK(x != ev.image_format_compatibility_type);
#endif
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    x = ev.image_format_compatibility_type;
    BOOST_CHECK(x == ev.image_format_compatibility_type);
#ifdef GL_IMAGE_PIXEL_FORMAT
    BOOST_CHECK(x != ev.image_pixel_format);
#endif
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_IMAGE_PIXEL_FORMAT
    x = ev.image_pixel_format;
    BOOST_CHECK(x == ev.image_pixel_format);
#ifdef GL_IMAGE_PIXEL_TYPE
    BOOST_CHECK(x != ev.image_pixel_type);
#endif
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_IMAGE_PIXEL_TYPE
    x = ev.image_pixel_type;
    BOOST_CHECK(x == ev.image_pixel_type);
#ifdef GL_IMAGE_TEXEL_SIZE
    BOOST_CHECK(x != ev.image_texel_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_IMAGE_TEXEL_SIZE
    x = ev.image_texel_size;
    BOOST_CHECK(x == ev.image_texel_size);
#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    BOOST_CHECK(x != ev.internalformat_alpha_size);
#endif
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    x = ev.internalformat_alpha_size;
    BOOST_CHECK(x == ev.internalformat_alpha_size);
#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    BOOST_CHECK(x != ev.internalformat_alpha_type);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    x = ev.internalformat_alpha_type;
    BOOST_CHECK(x == ev.internalformat_alpha_type);
#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    BOOST_CHECK(x != ev.internalformat_blue_size);
#endif
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    x = ev.internalformat_blue_size;
    BOOST_CHECK(x == ev.internalformat_blue_size);
#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    BOOST_CHECK(x != ev.internalformat_blue_type);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    x = ev.internalformat_blue_type;
    BOOST_CHECK(x == ev.internalformat_blue_type);
#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    BOOST_CHECK(x != ev.internalformat_depth_size);
#endif
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    x = ev.internalformat_depth_size;
    BOOST_CHECK(x == ev.internalformat_depth_size);
#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    BOOST_CHECK(x != ev.internalformat_depth_type);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    x = ev.internalformat_depth_type;
    BOOST_CHECK(x == ev.internalformat_depth_type);
#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    BOOST_CHECK(x != ev.internalformat_green_size);
#endif
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    x = ev.internalformat_green_size;
    BOOST_CHECK(x == ev.internalformat_green_size);
#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    BOOST_CHECK(x != ev.internalformat_green_type);
#endif
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    x = ev.internalformat_green_type;
    BOOST_CHECK(x == ev.internalformat_green_type);
#ifdef GL_INTERNALFORMAT_PREFERRED
    BOOST_CHECK(x != ev.internalformat_preferred);
#endif
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_PREFERRED
    x = ev.internalformat_preferred;
    BOOST_CHECK(x == ev.internalformat_preferred);
#ifdef GL_INTERNALFORMAT_RED_SIZE
    BOOST_CHECK(x != ev.internalformat_red_size);
#endif
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_RED_SIZE
    x = ev.internalformat_red_size;
    BOOST_CHECK(x == ev.internalformat_red_size);
#ifdef GL_INTERNALFORMAT_RED_TYPE
    BOOST_CHECK(x != ev.internalformat_red_type);
#endif
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_RED_TYPE
    x = ev.internalformat_red_type;
    BOOST_CHECK(x == ev.internalformat_red_type);
#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    BOOST_CHECK(x != ev.internalformat_shared_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    x = ev.internalformat_shared_size;
    BOOST_CHECK(x == ev.internalformat_shared_size);
#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    BOOST_CHECK(x != ev.internalformat_stencil_size);
#endif
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    x = ev.internalformat_stencil_size;
    BOOST_CHECK(x == ev.internalformat_stencil_size);
#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    BOOST_CHECK(x != ev.internalformat_stencil_type);
#endif
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    x = ev.internalformat_stencil_type;
    BOOST_CHECK(x == ev.internalformat_stencil_type);
#ifdef GL_INTERNALFORMAT_SUPPORTED
    BOOST_CHECK(x != ev.internalformat_supported);
#endif
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_INTERNALFORMAT_SUPPORTED
    x = ev.internalformat_supported;
    BOOST_CHECK(x == ev.internalformat_supported);
#ifdef GL_MAX_COMBINED_DIMENSIONS
    BOOST_CHECK(x != ev.max_combined_dimensions);
#endif
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_MAX_COMBINED_DIMENSIONS
    x = ev.max_combined_dimensions;
    BOOST_CHECK(x == ev.max_combined_dimensions);
#ifdef GL_MAX_DEPTH
    BOOST_CHECK(x != ev.max_depth);
#endif
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_MAX_DEPTH
    x = ev.max_depth;
    BOOST_CHECK(x == ev.max_depth);
#ifdef GL_MAX_HEIGHT
    BOOST_CHECK(x != ev.max_height);
#endif
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_MAX_HEIGHT
    x = ev.max_height;
    BOOST_CHECK(x == ev.max_height);
#ifdef GL_MAX_LAYERS
    BOOST_CHECK(x != ev.max_layers);
#endif
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_MAX_LAYERS
    x = ev.max_layers;
    BOOST_CHECK(x == ev.max_layers);
#ifdef GL_MAX_WIDTH
    BOOST_CHECK(x != ev.max_width);
#endif
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_MAX_WIDTH
    x = ev.max_width;
    BOOST_CHECK(x == ev.max_width);
#ifdef GL_MIPMAP
    BOOST_CHECK(x != ev.mipmap);
#endif
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_MIPMAP
    x = ev.mipmap;
    BOOST_CHECK(x == ev.mipmap);
#ifdef GL_NUM_SAMPLE_COUNTS
    BOOST_CHECK(x != ev.num_sample_counts);
#endif
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_NUM_SAMPLE_COUNTS
    x = ev.num_sample_counts;
    BOOST_CHECK(x == ev.num_sample_counts);
#ifdef GL_READ_PIXELS
    BOOST_CHECK(x != ev.read_pixels);
#endif
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_READ_PIXELS
    x = ev.read_pixels;
    BOOST_CHECK(x == ev.read_pixels);
#ifdef GL_READ_PIXELS_FORMAT
    BOOST_CHECK(x != ev.read_pixels_format);
#endif
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_READ_PIXELS_FORMAT
    x = ev.read_pixels_format;
    BOOST_CHECK(x == ev.read_pixels_format);
#ifdef GL_READ_PIXELS_TYPE
    BOOST_CHECK(x != ev.read_pixels_type);
#endif
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_READ_PIXELS_TYPE
    x = ev.read_pixels_type;
    BOOST_CHECK(x == ev.read_pixels_type);
#ifdef GL_SAMPLES
    BOOST_CHECK(x != ev.samples);
#endif
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_SAMPLES
    x = ev.samples;
    BOOST_CHECK(x == ev.samples);
#ifdef GL_SHADER_IMAGE_ATOMIC
    BOOST_CHECK(x != ev.shader_image_atomic);
#endif
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_SHADER_IMAGE_ATOMIC
    x = ev.shader_image_atomic;
    BOOST_CHECK(x == ev.shader_image_atomic);
#ifdef GL_SHADER_IMAGE_LOAD
    BOOST_CHECK(x != ev.shader_image_load);
#endif
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_SHADER_IMAGE_LOAD
    x = ev.shader_image_load;
    BOOST_CHECK(x == ev.shader_image_load);
#ifdef GL_SHADER_IMAGE_STORE
    BOOST_CHECK(x != ev.shader_image_store);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_SHADER_IMAGE_STORE
    x = ev.shader_image_store;
    BOOST_CHECK(x == ev.shader_image_store);
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    x = ev.simultaneous_texture_and_depth_test;
    BOOST_CHECK(x == ev.simultaneous_texture_and_depth_test);
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_depth_write);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    x = ev.simultaneous_texture_and_depth_write;
    BOOST_CHECK(x == ev.simultaneous_texture_and_depth_write);
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_test);
#endif
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    x = ev.simultaneous_texture_and_stencil_test;
    BOOST_CHECK(x == ev.simultaneous_texture_and_stencil_test);
#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    BOOST_CHECK(x != ev.simultaneous_texture_and_stencil_write);
#endif
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    x = ev.simultaneous_texture_and_stencil_write;
    BOOST_CHECK(x == ev.simultaneous_texture_and_stencil_write);
#ifdef GL_SRGB_READ
    BOOST_CHECK(x != ev.srgb_read);
#endif
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_SRGB_READ
    x = ev.srgb_read;
    BOOST_CHECK(x == ev.srgb_read);
#ifdef GL_SRGB_WRITE
    BOOST_CHECK(x != ev.srgb_write);
#endif
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_SRGB_WRITE
    x = ev.srgb_write;
    BOOST_CHECK(x == ev.srgb_write);
#ifdef GL_STENCIL_COMPONENTS
    BOOST_CHECK(x != ev.stencil_components);
#endif
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_STENCIL_COMPONENTS
    x = ev.stencil_components;
    BOOST_CHECK(x == ev.stencil_components);
#ifdef GL_STENCIL_RENDERABLE
    BOOST_CHECK(x != ev.stencil_renderable);
#endif
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_STENCIL_RENDERABLE
    x = ev.stencil_renderable;
    BOOST_CHECK(x == ev.stencil_renderable);
#ifdef GL_TESS_CONTROL_TEXTURE
    BOOST_CHECK(x != ev.tess_control_texture);
#endif
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_TESS_CONTROL_TEXTURE
    x = ev.tess_control_texture;
    BOOST_CHECK(x == ev.tess_control_texture);
#ifdef GL_TESS_EVALUATION_TEXTURE
    BOOST_CHECK(x != ev.tess_evaluation_texture);
#endif
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_TESS_EVALUATION_TEXTURE
    x = ev.tess_evaluation_texture;
    BOOST_CHECK(x == ev.tess_evaluation_texture);
#ifdef GL_TEXTURE_COMPRESSED
    BOOST_CHECK(x != ev.texture_compressed);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_TEXTURE_COMPRESSED
    x = ev.texture_compressed;
    BOOST_CHECK(x == ev.texture_compressed);
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    BOOST_CHECK(x != ev.texture_compressed_block_height);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    x = ev.texture_compressed_block_height;
    BOOST_CHECK(x == ev.texture_compressed_block_height);
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    BOOST_CHECK(x != ev.texture_compressed_block_size);
#endif
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    x = ev.texture_compressed_block_size;
    BOOST_CHECK(x == ev.texture_compressed_block_size);
#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    BOOST_CHECK(x != ev.texture_compressed_block_width);
#endif
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    x = ev.texture_compressed_block_width;
    BOOST_CHECK(x == ev.texture_compressed_block_width);
#ifdef GL_TEXTURE_GATHER
    BOOST_CHECK(x != ev.texture_gather);
#endif
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_TEXTURE_GATHER
    x = ev.texture_gather;
    BOOST_CHECK(x == ev.texture_gather);
#ifdef GL_TEXTURE_GATHER_SHADOW
    BOOST_CHECK(x != ev.texture_gather_shadow);
#endif
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_TEXTURE_GATHER_SHADOW
    x = ev.texture_gather_shadow;
    BOOST_CHECK(x == ev.texture_gather_shadow);
#ifdef GL_TEXTURE_IMAGE_FORMAT
    BOOST_CHECK(x != ev.texture_image_format);
#endif
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_TEXTURE_IMAGE_FORMAT
    x = ev.texture_image_format;
    BOOST_CHECK(x == ev.texture_image_format);
#ifdef GL_TEXTURE_IMAGE_TYPE
    BOOST_CHECK(x != ev.texture_image_type);
#endif
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_TEXTURE_IMAGE_TYPE
    x = ev.texture_image_type;
    BOOST_CHECK(x == ev.texture_image_type);
#ifdef GL_TEXTURE_SHADOW
    BOOST_CHECK(x != ev.texture_shadow);
#endif
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_TEXTURE_SHADOW
    x = ev.texture_shadow;
    BOOST_CHECK(x == ev.texture_shadow);
#ifdef GL_TEXTURE_VIEW
    BOOST_CHECK(x != ev.texture_view);
#endif
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_TEXTURE_VIEW
    x = ev.texture_view;
    BOOST_CHECK(x == ev.texture_view);
#ifdef GL_VERTEX_TEXTURE
    BOOST_CHECK(x != ev.vertex_texture);
#endif
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_VERTEX_TEXTURE
    x = ev.vertex_texture;
    BOOST_CHECK(x == ev.vertex_texture);
#ifdef GL_VIEW_COMPATIBILITY_CLASS
    BOOST_CHECK(x != ev.view_compatibility_class);
#endif
#endif

#ifdef GL_VIEW_COMPATIBILITY_CLASS
    x = ev.view_compatibility_class;
    BOOST_CHECK(x == ev.view_compatibility_class);
#endif
}

BOOST_AUTO_TEST_CASE(enum_internal_format_parameter_names) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    internal_format_parameter x;
    EAGINE_MAYBE_UNUSED(x);

#ifdef GL_AUTO_GENERATE_MIPMAP
    x = ev.auto_generate_mipmap;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "AUTO_GENERATE_MIPMAP") == 0);
#endif

#ifdef GL_CLEAR_BUFFER
    x = ev.clear_buffer;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "CLEAR_BUFFER") == 0);
#endif

#ifdef GL_CLEAR_TEXTURE
    x = ev.clear_texture;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "CLEAR_TEXTURE") == 0);
#endif

#ifdef GL_COLOR_COMPONENTS
    x = ev.color_components;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "COLOR_COMPONENTS") == 0);
#endif

#ifdef GL_COLOR_ENCODING
    x = ev.color_encoding;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "COLOR_ENCODING") == 0);
#endif

#ifdef GL_COLOR_RENDERABLE
    x = ev.color_renderable;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "COLOR_RENDERABLE") == 0);
#endif

#ifdef GL_COMPUTE_TEXTURE
    x = ev.compute_texture;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "COMPUTE_TEXTURE") == 0);
#endif

#ifdef GL_DEPTH_COMPONENTS
    x = ev.depth_components;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "DEPTH_COMPONENTS") == 0);
#endif

#ifdef GL_DEPTH_RENDERABLE
    x = ev.depth_renderable;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "DEPTH_RENDERABLE") == 0);
#endif

#ifdef GL_FILTER
    x = ev.filter;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "FILTER") == 0);
#endif

#ifdef GL_FRAGMENT_TEXTURE
    x = ev.fragment_texture;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "FRAGMENT_TEXTURE") == 0);
#endif

#ifdef GL_FRAMEBUFFER_BLEND
    x = ev.framebuffer_blend;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "FRAMEBUFFER_BLEND") == 0);
#endif

#ifdef GL_FRAMEBUFFER_RENDERABLE
    x = ev.framebuffer_renderable;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "FRAMEBUFFER_RENDERABLE") == 0);
#endif

#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    x = ev.framebuffer_renderable_layered;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(
        enum_value_name(x).data(), "FRAMEBUFFER_RENDERABLE_LAYERED") == 0);
#endif

#ifdef GL_GENERATE_MIPMAP
    x = ev.generate_mipmap;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "GENERATE_MIPMAP") == 0);
#endif

#ifdef GL_GEOMETRY_TEXTURE
    x = ev.geometry_texture;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "GEOMETRY_TEXTURE") == 0);
#endif

#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    x = ev.get_texture_image_format;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "GET_TEXTURE_IMAGE_FORMAT") == 0);
#endif

#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    x = ev.get_texture_image_type;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "GET_TEXTURE_IMAGE_TYPE") == 0);
#endif

#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    x = ev.image_compatibility_class;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_COMPATIBILITY_CLASS") == 0);
#endif

#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    x = ev.image_format_compatibility_type;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(
        enum_value_name(x).data(), "IMAGE_FORMAT_COMPATIBILITY_TYPE") == 0);
#endif

#ifdef GL_IMAGE_PIXEL_FORMAT
    x = ev.image_pixel_format;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_PIXEL_FORMAT") == 0);
#endif

#ifdef GL_IMAGE_PIXEL_TYPE
    x = ev.image_pixel_type;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_PIXEL_TYPE") == 0);
#endif

#ifdef GL_IMAGE_TEXEL_SIZE
    x = ev.image_texel_size;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "IMAGE_TEXEL_SIZE") == 0);
#endif

#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    x = ev.internalformat_alpha_size;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_ALPHA_SIZE") == 0);
#endif

#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    x = ev.internalformat_alpha_type;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_ALPHA_TYPE") == 0);
#endif

#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    x = ev.internalformat_blue_size;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_BLUE_SIZE") == 0);
#endif

#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    x = ev.internalformat_blue_type;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_BLUE_TYPE") == 0);
#endif

#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    x = ev.internalformat_depth_size;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_DEPTH_SIZE") == 0);
#endif

#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    x = ev.internalformat_depth_type;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_DEPTH_TYPE") == 0);
#endif

#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    x = ev.internalformat_green_size;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_GREEN_SIZE") == 0);
#endif

#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    x = ev.internalformat_green_type;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_GREEN_TYPE") == 0);
#endif

#ifdef GL_INTERNALFORMAT_PREFERRED
    x = ev.internalformat_preferred;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_PREFERRED") == 0);
#endif

#ifdef GL_INTERNALFORMAT_RED_SIZE
    x = ev.internalformat_red_size;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_RED_SIZE") == 0);
#endif

#ifdef GL_INTERNALFORMAT_RED_TYPE
    x = ev.internalformat_red_type;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_RED_TYPE") == 0);
#endif

#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    x = ev.internalformat_shared_size;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_SHARED_SIZE") ==
      0);
#endif

#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    x = ev.internalformat_stencil_size;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_STENCIL_SIZE") ==
      0);
#endif

#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    x = ev.internalformat_stencil_type;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_STENCIL_TYPE") ==
      0);
#endif

#ifdef GL_INTERNALFORMAT_SUPPORTED
    x = ev.internalformat_supported;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "INTERNALFORMAT_SUPPORTED") == 0);
#endif

#ifdef GL_MAX_COMBINED_DIMENSIONS
    x = ev.max_combined_dimensions;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "MAX_COMBINED_DIMENSIONS") == 0);
#endif

#ifdef GL_MAX_DEPTH
    x = ev.max_depth;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "MAX_DEPTH") == 0);
#endif

#ifdef GL_MAX_HEIGHT
    x = ev.max_height;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "MAX_HEIGHT") == 0);
#endif

#ifdef GL_MAX_LAYERS
    x = ev.max_layers;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "MAX_LAYERS") == 0);
#endif

#ifdef GL_MAX_WIDTH
    x = ev.max_width;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "MAX_WIDTH") == 0);
#endif

#ifdef GL_MIPMAP
    x = ev.mipmap;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "MIPMAP") == 0);
#endif

#ifdef GL_NUM_SAMPLE_COUNTS
    x = ev.num_sample_counts;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "NUM_SAMPLE_COUNTS") == 0);
#endif

#ifdef GL_READ_PIXELS
    x = ev.read_pixels;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "READ_PIXELS") == 0);
#endif

#ifdef GL_READ_PIXELS_FORMAT
    x = ev.read_pixels_format;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "READ_PIXELS_FORMAT") == 0);
#endif

#ifdef GL_READ_PIXELS_TYPE
    x = ev.read_pixels_type;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "READ_PIXELS_TYPE") == 0);
#endif

#ifdef GL_SAMPLES
    x = ev.samples;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "SAMPLES") == 0);
#endif

#ifdef GL_SHADER_IMAGE_ATOMIC
    x = ev.shader_image_atomic;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "SHADER_IMAGE_ATOMIC") == 0);
#endif

#ifdef GL_SHADER_IMAGE_LOAD
    x = ev.shader_image_load;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "SHADER_IMAGE_LOAD") == 0);
#endif

#ifdef GL_SHADER_IMAGE_STORE
    x = ev.shader_image_store;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "SHADER_IMAGE_STORE") == 0);
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    x = ev.simultaneous_texture_and_depth_test;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(
        enum_value_name(x).data(), "SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST") == 0);
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    x = ev.simultaneous_texture_and_depth_write;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(
        enum_value_name(x).data(), "SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE") ==
      0);
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    x = ev.simultaneous_texture_and_stencil_test;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(
        enum_value_name(x).data(), "SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST") ==
      0);
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    x = ev.simultaneous_texture_and_stencil_write;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(
        enum_value_name(x).data(), "SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE") ==
      0);
#endif

#ifdef GL_SRGB_READ
    x = ev.srgb_read;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "SRGB_READ") == 0);
#endif

#ifdef GL_SRGB_WRITE
    x = ev.srgb_write;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "SRGB_WRITE") == 0);
#endif

#ifdef GL_STENCIL_COMPONENTS
    x = ev.stencil_components;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "STENCIL_COMPONENTS") == 0);
#endif

#ifdef GL_STENCIL_RENDERABLE
    x = ev.stencil_renderable;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "STENCIL_RENDERABLE") == 0);
#endif

#ifdef GL_TESS_CONTROL_TEXTURE
    x = ev.tess_control_texture;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "TESS_CONTROL_TEXTURE") == 0);
#endif

#ifdef GL_TESS_EVALUATION_TEXTURE
    x = ev.tess_evaluation_texture;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "TESS_EVALUATION_TEXTURE") == 0);
#endif

#ifdef GL_TEXTURE_COMPRESSED
    x = ev.texture_compressed;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "TEXTURE_COMPRESSED") == 0);
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    x = ev.texture_compressed_block_height;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(
        enum_value_name(x).data(), "TEXTURE_COMPRESSED_BLOCK_HEIGHT") == 0);
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    x = ev.texture_compressed_block_size;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "TEXTURE_COMPRESSED_BLOCK_SIZE") ==
      0);
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    x = ev.texture_compressed_block_width;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(
        enum_value_name(x).data(), "TEXTURE_COMPRESSED_BLOCK_WIDTH") == 0);
#endif

#ifdef GL_TEXTURE_GATHER
    x = ev.texture_gather;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "TEXTURE_GATHER") == 0);
#endif

#ifdef GL_TEXTURE_GATHER_SHADOW
    x = ev.texture_gather_shadow;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "TEXTURE_GATHER_SHADOW") == 0);
#endif

#ifdef GL_TEXTURE_IMAGE_FORMAT
    x = ev.texture_image_format;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "TEXTURE_IMAGE_FORMAT") == 0);
#endif

#ifdef GL_TEXTURE_IMAGE_TYPE
    x = ev.texture_image_type;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "TEXTURE_IMAGE_TYPE") == 0);
#endif

#ifdef GL_TEXTURE_SHADOW
    x = ev.texture_shadow;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "TEXTURE_SHADOW") == 0);
#endif

#ifdef GL_TEXTURE_VIEW
    x = ev.texture_view;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "TEXTURE_VIEW") == 0);
#endif

#ifdef GL_VERTEX_TEXTURE
    x = ev.vertex_texture;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(std::strcmp(enum_value_name(x).data(), "VERTEX_TEXTURE") == 0);
#endif

#ifdef GL_VIEW_COMPATIBILITY_CLASS
    x = ev.view_compatibility_class;
    BOOST_ASSERT(enum_value_name(x).data() != nullptr);
    BOOST_CHECK(
      std::strcmp(enum_value_name(x).data(), "VIEW_COMPATIBILITY_CLASS") == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_internal_format_parameter_range) {
    using namespace oglplus;
    auto count = enum_value_range<internal_format_parameter>().size();

#ifdef GL_AUTO_GENERATE_MIPMAP
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_AUTO_GENERATE_MIPMAP)) != r.end());
    }
#endif

#ifdef GL_CLEAR_BUFFER
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_CLEAR_BUFFER)) !=
          r.end());
    }
#endif

#ifdef GL_CLEAR_TEXTURE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_CLEAR_TEXTURE)) !=
          r.end());
    }
#endif

#ifdef GL_COLOR_COMPONENTS
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_COLOR_COMPONENTS)) != r.end());
    }
#endif

#ifdef GL_COLOR_ENCODING
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_COLOR_ENCODING)) !=
          r.end());
    }
#endif

#ifdef GL_COLOR_RENDERABLE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_COLOR_RENDERABLE)) != r.end());
    }
#endif

#ifdef GL_COMPUTE_TEXTURE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_COMPUTE_TEXTURE)) != r.end());
    }
#endif

#ifdef GL_DEPTH_COMPONENTS
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_DEPTH_COMPONENTS)) != r.end());
    }
#endif

#ifdef GL_DEPTH_RENDERABLE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_DEPTH_RENDERABLE)) != r.end());
    }
#endif

#ifdef GL_FILTER
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), internal_format_parameter(GL_FILTER)) !=
          r.end());
    }
#endif

#ifdef GL_FRAGMENT_TEXTURE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_FRAGMENT_TEXTURE)) != r.end());
    }
#endif

#ifdef GL_FRAMEBUFFER_BLEND
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_FRAMEBUFFER_BLEND)) != r.end());
    }
#endif

#ifdef GL_FRAMEBUFFER_RENDERABLE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_FRAMEBUFFER_RENDERABLE)) != r.end());
    }
#endif

#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_FRAMEBUFFER_RENDERABLE_LAYERED)) !=
          r.end());
    }
#endif

#ifdef GL_GENERATE_MIPMAP
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_GENERATE_MIPMAP)) != r.end());
    }
#endif

#ifdef GL_GEOMETRY_TEXTURE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_GEOMETRY_TEXTURE)) != r.end());
    }
#endif

#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_GET_TEXTURE_IMAGE_FORMAT)) != r.end());
    }
#endif

#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_GET_TEXTURE_IMAGE_TYPE)) != r.end());
    }
#endif

#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_IMAGE_COMPATIBILITY_CLASS)) !=
          r.end());
    }
#endif

#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_IMAGE_FORMAT_COMPATIBILITY_TYPE)) !=
          r.end());
    }
#endif

#ifdef GL_IMAGE_PIXEL_FORMAT
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_IMAGE_PIXEL_FORMAT)) != r.end());
    }
#endif

#ifdef GL_IMAGE_PIXEL_TYPE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_IMAGE_PIXEL_TYPE)) != r.end());
    }
#endif

#ifdef GL_IMAGE_TEXEL_SIZE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_IMAGE_TEXEL_SIZE)) != r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_ALPHA_SIZE)) !=
          r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_ALPHA_TYPE)) !=
          r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_BLUE_SIZE)) != r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_BLUE_TYPE)) != r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_DEPTH_SIZE)) !=
          r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_DEPTH_TYPE)) !=
          r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_GREEN_SIZE)) !=
          r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_GREEN_TYPE)) !=
          r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_PREFERRED
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_PREFERRED)) != r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_RED_SIZE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_RED_SIZE)) != r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_RED_TYPE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_RED_TYPE)) != r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_SHARED_SIZE)) !=
          r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_STENCIL_SIZE)) !=
          r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_STENCIL_TYPE)) !=
          r.end());
    }
#endif

#ifdef GL_INTERNALFORMAT_SUPPORTED
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_INTERNALFORMAT_SUPPORTED)) != r.end());
    }
#endif

#ifdef GL_MAX_COMBINED_DIMENSIONS
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_MAX_COMBINED_DIMENSIONS)) != r.end());
    }
#endif

#ifdef GL_MAX_DEPTH
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_MAX_DEPTH)) !=
          r.end());
    }
#endif

#ifdef GL_MAX_HEIGHT
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_MAX_HEIGHT)) !=
          r.end());
    }
#endif

#ifdef GL_MAX_LAYERS
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_MAX_LAYERS)) !=
          r.end());
    }
#endif

#ifdef GL_MAX_WIDTH
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_MAX_WIDTH)) !=
          r.end());
    }
#endif

#ifdef GL_MIPMAP
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(r.begin(), r.end(), internal_format_parameter(GL_MIPMAP)) !=
          r.end());
    }
#endif

#ifdef GL_NUM_SAMPLE_COUNTS
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_NUM_SAMPLE_COUNTS)) != r.end());
    }
#endif

#ifdef GL_READ_PIXELS
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_READ_PIXELS)) !=
          r.end());
    }
#endif

#ifdef GL_READ_PIXELS_FORMAT
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_READ_PIXELS_FORMAT)) != r.end());
    }
#endif

#ifdef GL_READ_PIXELS_TYPE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_READ_PIXELS_TYPE)) != r.end());
    }
#endif

#ifdef GL_SAMPLES
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_SAMPLES)) !=
          r.end());
    }
#endif

#ifdef GL_SHADER_IMAGE_ATOMIC
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_SHADER_IMAGE_ATOMIC)) != r.end());
    }
#endif

#ifdef GL_SHADER_IMAGE_LOAD
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_SHADER_IMAGE_LOAD)) != r.end());
    }
#endif

#ifdef GL_SHADER_IMAGE_STORE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_SHADER_IMAGE_STORE)) != r.end());
    }
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(
              GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST)) != r.end());
    }
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(
              GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE)) != r.end());
    }
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(
              GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST)) != r.end());
    }
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(
              GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE)) != r.end());
    }
#endif

#ifdef GL_SRGB_READ
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_SRGB_READ)) !=
          r.end());
    }
#endif

#ifdef GL_SRGB_WRITE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_SRGB_WRITE)) !=
          r.end());
    }
#endif

#ifdef GL_STENCIL_COMPONENTS
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_STENCIL_COMPONENTS)) != r.end());
    }
#endif

#ifdef GL_STENCIL_RENDERABLE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_STENCIL_RENDERABLE)) != r.end());
    }
#endif

#ifdef GL_TESS_CONTROL_TEXTURE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_TESS_CONTROL_TEXTURE)) != r.end());
    }
#endif

#ifdef GL_TESS_EVALUATION_TEXTURE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_TESS_EVALUATION_TEXTURE)) != r.end());
    }
#endif

#ifdef GL_TEXTURE_COMPRESSED
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_TEXTURE_COMPRESSED)) != r.end());
    }
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT)) !=
          r.end());
    }
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_TEXTURE_COMPRESSED_BLOCK_SIZE)) !=
          r.end());
    }
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_TEXTURE_COMPRESSED_BLOCK_WIDTH)) !=
          r.end());
    }
#endif

#ifdef GL_TEXTURE_GATHER
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_TEXTURE_GATHER)) !=
          r.end());
    }
#endif

#ifdef GL_TEXTURE_GATHER_SHADOW
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_TEXTURE_GATHER_SHADOW)) != r.end());
    }
#endif

#ifdef GL_TEXTURE_IMAGE_FORMAT
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_TEXTURE_IMAGE_FORMAT)) != r.end());
    }
#endif

#ifdef GL_TEXTURE_IMAGE_TYPE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_TEXTURE_IMAGE_TYPE)) != r.end());
    }
#endif

#ifdef GL_TEXTURE_SHADOW
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_TEXTURE_SHADOW)) !=
          r.end());
    }
#endif

#ifdef GL_TEXTURE_VIEW
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_TEXTURE_VIEW)) !=
          r.end());
    }
#endif

#ifdef GL_VERTEX_TEXTURE
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(), r.end(), internal_format_parameter(GL_VERTEX_TEXTURE)) !=
          r.end());
    }
#endif

#ifdef GL_VIEW_COMPATIBILITY_CLASS
    {
        --count;
        auto r = enum_value_range<internal_format_parameter>();
        BOOST_CHECK(
          std::find(
            r.begin(),
            r.end(),
            internal_format_parameter(GL_VIEW_COMPATIBILITY_CLASS)) != r.end());
    }
#endif
    BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_internal_format_parameter_any) {
    using namespace oglplus;
    enum_values ev;
    EAGINE_MAYBE_UNUSED(ev);
    internal_format_parameter x, y;
    EAGINE_MAYBE_UNUSED(x);
    EAGINE_MAYBE_UNUSED(y);
    any_enum_value a;
    EAGINE_MAYBE_UNUSED(a);

#ifdef GL_AUTO_GENERATE_MIPMAP
    x = ev.auto_generate_mipmap;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.auto_generate_mipmap);
#endif

#ifdef GL_CLEAR_BUFFER
    x = ev.clear_buffer;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.clear_buffer);
#endif

#ifdef GL_CLEAR_TEXTURE
    x = ev.clear_texture;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.clear_texture);
#endif

#ifdef GL_COLOR_COMPONENTS
    x = ev.color_components;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.color_components);
#endif

#ifdef GL_COLOR_ENCODING
    x = ev.color_encoding;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.color_encoding);
#endif

#ifdef GL_COLOR_RENDERABLE
    x = ev.color_renderable;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.color_renderable);
#endif

#ifdef GL_COMPUTE_TEXTURE
    x = ev.compute_texture;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.compute_texture);
#endif

#ifdef GL_DEPTH_COMPONENTS
    x = ev.depth_components;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.depth_components);
#endif

#ifdef GL_DEPTH_RENDERABLE
    x = ev.depth_renderable;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.depth_renderable);
#endif

#ifdef GL_FILTER
    x = ev.filter;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.filter);
#endif

#ifdef GL_FRAGMENT_TEXTURE
    x = ev.fragment_texture;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.fragment_texture);
#endif

#ifdef GL_FRAMEBUFFER_BLEND
    x = ev.framebuffer_blend;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.framebuffer_blend);
#endif

#ifdef GL_FRAMEBUFFER_RENDERABLE
    x = ev.framebuffer_renderable;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.framebuffer_renderable);
#endif

#ifdef GL_FRAMEBUFFER_RENDERABLE_LAYERED
    x = ev.framebuffer_renderable_layered;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.framebuffer_renderable_layered);
#endif

#ifdef GL_GENERATE_MIPMAP
    x = ev.generate_mipmap;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.generate_mipmap);
#endif

#ifdef GL_GEOMETRY_TEXTURE
    x = ev.geometry_texture;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.geometry_texture);
#endif

#ifdef GL_GET_TEXTURE_IMAGE_FORMAT
    x = ev.get_texture_image_format;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.get_texture_image_format);
#endif

#ifdef GL_GET_TEXTURE_IMAGE_TYPE
    x = ev.get_texture_image_type;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.get_texture_image_type);
#endif

#ifdef GL_IMAGE_COMPATIBILITY_CLASS
    x = ev.image_compatibility_class;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_compatibility_class);
#endif

#ifdef GL_IMAGE_FORMAT_COMPATIBILITY_TYPE
    x = ev.image_format_compatibility_type;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_format_compatibility_type);
#endif

#ifdef GL_IMAGE_PIXEL_FORMAT
    x = ev.image_pixel_format;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_pixel_format);
#endif

#ifdef GL_IMAGE_PIXEL_TYPE
    x = ev.image_pixel_type;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_pixel_type);
#endif

#ifdef GL_IMAGE_TEXEL_SIZE
    x = ev.image_texel_size;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.image_texel_size);
#endif

#ifdef GL_INTERNALFORMAT_ALPHA_SIZE
    x = ev.internalformat_alpha_size;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_alpha_size);
#endif

#ifdef GL_INTERNALFORMAT_ALPHA_TYPE
    x = ev.internalformat_alpha_type;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_alpha_type);
#endif

#ifdef GL_INTERNALFORMAT_BLUE_SIZE
    x = ev.internalformat_blue_size;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_blue_size);
#endif

#ifdef GL_INTERNALFORMAT_BLUE_TYPE
    x = ev.internalformat_blue_type;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_blue_type);
#endif

#ifdef GL_INTERNALFORMAT_DEPTH_SIZE
    x = ev.internalformat_depth_size;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_depth_size);
#endif

#ifdef GL_INTERNALFORMAT_DEPTH_TYPE
    x = ev.internalformat_depth_type;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_depth_type);
#endif

#ifdef GL_INTERNALFORMAT_GREEN_SIZE
    x = ev.internalformat_green_size;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_green_size);
#endif

#ifdef GL_INTERNALFORMAT_GREEN_TYPE
    x = ev.internalformat_green_type;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_green_type);
#endif

#ifdef GL_INTERNALFORMAT_PREFERRED
    x = ev.internalformat_preferred;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_preferred);
#endif

#ifdef GL_INTERNALFORMAT_RED_SIZE
    x = ev.internalformat_red_size;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_red_size);
#endif

#ifdef GL_INTERNALFORMAT_RED_TYPE
    x = ev.internalformat_red_type;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_red_type);
#endif

#ifdef GL_INTERNALFORMAT_SHARED_SIZE
    x = ev.internalformat_shared_size;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_shared_size);
#endif

#ifdef GL_INTERNALFORMAT_STENCIL_SIZE
    x = ev.internalformat_stencil_size;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_stencil_size);
#endif

#ifdef GL_INTERNALFORMAT_STENCIL_TYPE
    x = ev.internalformat_stencil_type;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_stencil_type);
#endif

#ifdef GL_INTERNALFORMAT_SUPPORTED
    x = ev.internalformat_supported;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.internalformat_supported);
#endif

#ifdef GL_MAX_COMBINED_DIMENSIONS
    x = ev.max_combined_dimensions;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.max_combined_dimensions);
#endif

#ifdef GL_MAX_DEPTH
    x = ev.max_depth;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.max_depth);
#endif

#ifdef GL_MAX_HEIGHT
    x = ev.max_height;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.max_height);
#endif

#ifdef GL_MAX_LAYERS
    x = ev.max_layers;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.max_layers);
#endif

#ifdef GL_MAX_WIDTH
    x = ev.max_width;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.max_width);
#endif

#ifdef GL_MIPMAP
    x = ev.mipmap;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.mipmap);
#endif

#ifdef GL_NUM_SAMPLE_COUNTS
    x = ev.num_sample_counts;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.num_sample_counts);
#endif

#ifdef GL_READ_PIXELS
    x = ev.read_pixels;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.read_pixels);
#endif

#ifdef GL_READ_PIXELS_FORMAT
    x = ev.read_pixels_format;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.read_pixels_format);
#endif

#ifdef GL_READ_PIXELS_TYPE
    x = ev.read_pixels_type;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.read_pixels_type);
#endif

#ifdef GL_SAMPLES
    x = ev.samples;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.samples);
#endif

#ifdef GL_SHADER_IMAGE_ATOMIC
    x = ev.shader_image_atomic;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.shader_image_atomic);
#endif

#ifdef GL_SHADER_IMAGE_LOAD
    x = ev.shader_image_load;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.shader_image_load);
#endif

#ifdef GL_SHADER_IMAGE_STORE
    x = ev.shader_image_store;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.shader_image_store);
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST
    x = ev.simultaneous_texture_and_depth_test;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.simultaneous_texture_and_depth_test);
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE
    x = ev.simultaneous_texture_and_depth_write;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.simultaneous_texture_and_depth_write);
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST
    x = ev.simultaneous_texture_and_stencil_test;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.simultaneous_texture_and_stencil_test);
#endif

#ifdef GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE
    x = ev.simultaneous_texture_and_stencil_write;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.simultaneous_texture_and_stencil_write);
#endif

#ifdef GL_SRGB_READ
    x = ev.srgb_read;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.srgb_read);
#endif

#ifdef GL_SRGB_WRITE
    x = ev.srgb_write;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.srgb_write);
#endif

#ifdef GL_STENCIL_COMPONENTS
    x = ev.stencil_components;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.stencil_components);
#endif

#ifdef GL_STENCIL_RENDERABLE
    x = ev.stencil_renderable;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.stencil_renderable);
#endif

#ifdef GL_TESS_CONTROL_TEXTURE
    x = ev.tess_control_texture;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.tess_control_texture);
#endif

#ifdef GL_TESS_EVALUATION_TEXTURE
    x = ev.tess_evaluation_texture;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.tess_evaluation_texture);
#endif

#ifdef GL_TEXTURE_COMPRESSED
    x = ev.texture_compressed;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.texture_compressed);
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT
    x = ev.texture_compressed_block_height;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.texture_compressed_block_height);
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_SIZE
    x = ev.texture_compressed_block_size;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.texture_compressed_block_size);
#endif

#ifdef GL_TEXTURE_COMPRESSED_BLOCK_WIDTH
    x = ev.texture_compressed_block_width;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.texture_compressed_block_width);
#endif

#ifdef GL_TEXTURE_GATHER
    x = ev.texture_gather;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.texture_gather);
#endif

#ifdef GL_TEXTURE_GATHER_SHADOW
    x = ev.texture_gather_shadow;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.texture_gather_shadow);
#endif

#ifdef GL_TEXTURE_IMAGE_FORMAT
    x = ev.texture_image_format;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.texture_image_format);
#endif

#ifdef GL_TEXTURE_IMAGE_TYPE
    x = ev.texture_image_type;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.texture_image_type);
#endif

#ifdef GL_TEXTURE_SHADOW
    x = ev.texture_shadow;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.texture_shadow);
#endif

#ifdef GL_TEXTURE_VIEW
    x = ev.texture_view;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.texture_view);
#endif

#ifdef GL_VERTEX_TEXTURE
    x = ev.vertex_texture;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.vertex_texture);
#endif

#ifdef GL_VIEW_COMPATIBILITY_CLASS
    x = ev.view_compatibility_class;
    a = x;
    y = a;
    BOOST_CHECK(same_enum_class(x, a));
    BOOST_CHECK(same_enum_class(a, y));
    BOOST_CHECK(same_enum_class(x, y));
    BOOST_CHECK(y == ev.view_compatibility_class);
#endif
}

BOOST_AUTO_TEST_SUITE_END()

#include "../../unit_test_end.inl"
