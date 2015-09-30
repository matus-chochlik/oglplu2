//  File test/oglplus/enums/pixel_parameter.cpp
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_pixel_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"

BOOST_AUTO_TEST_SUITE(enum_pixel_parameter)

BOOST_AUTO_TEST_CASE(enum_pixel_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_parameter x;
	(void)x;

#ifdef GL_PACK_LSB_FIRST
	x = ev.PackLSBFirst;
	BOOST_CHECK(x == ev.PackLSBFirst);
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_LSB_FIRST
	x = ev.UnpackLSBFirst;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
	BOOST_CHECK(x == ev.UnpackLSBFirst);
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_PACK_ALIGNMENT
	x = ev.pack_alignment;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
	BOOST_CHECK(x == ev.pack_alignment);
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	x = ev.pack_compressed_block_depth;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
	BOOST_CHECK(x == ev.pack_compressed_block_depth);
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	x = ev.pack_compressed_block_height;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
	BOOST_CHECK(x == ev.pack_compressed_block_height);
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	x = ev.pack_compressed_block_size;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
	BOOST_CHECK(x == ev.pack_compressed_block_size);
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	x = ev.pack_compressed_block_width;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
	BOOST_CHECK(x == ev.pack_compressed_block_width);
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_PACK_IMAGE_HEIGHT
	x = ev.pack_image_height;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
	BOOST_CHECK(x == ev.pack_image_height);
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_PACK_ROW_LENGTH
	x = ev.pack_row_length;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
	BOOST_CHECK(x == ev.pack_row_length);
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_PACK_SKIP_IMAGES
	x = ev.pack_skip_images;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
	BOOST_CHECK(x == ev.pack_skip_images);
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_PACK_SKIP_PIXELS
	x = ev.pack_skip_pixels;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
	BOOST_CHECK(x == ev.pack_skip_pixels);
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_PACK_SKIP_ROWS
	x = ev.pack_skip_rows;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
	BOOST_CHECK(x == ev.pack_skip_rows);
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_PACK_SWAP_BYTES
	x = ev.pack_swap_bytes;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
	BOOST_CHECK(x == ev.pack_swap_bytes);
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_ALIGNMENT
	x = ev.unpack_alignment;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
	BOOST_CHECK(x == ev.unpack_alignment);
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	x = ev.unpack_compressed_block_depth;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
	BOOST_CHECK(x == ev.unpack_compressed_block_depth);
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	x = ev.unpack_compressed_block_height;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
	BOOST_CHECK(x == ev.unpack_compressed_block_height);
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	x = ev.unpack_compressed_block_size;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
	BOOST_CHECK(x == ev.unpack_compressed_block_size);
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	x = ev.unpack_compressed_block_width;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
	BOOST_CHECK(x == ev.unpack_compressed_block_width);
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_IMAGE_HEIGHT
	x = ev.unpack_image_height;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
	BOOST_CHECK(x == ev.unpack_image_height);
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_ROW_LENGTH
	x = ev.unpack_row_length;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
	BOOST_CHECK(x == ev.unpack_row_length);
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_SKIP_IMAGES
	x = ev.unpack_skip_images;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
	BOOST_CHECK(x == ev.unpack_skip_images);
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_SKIP_PIXELS
	x = ev.unpack_skip_pixels;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
	BOOST_CHECK(x == ev.unpack_skip_pixels);
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_SKIP_ROWS
	x = ev.unpack_skip_rows;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
	BOOST_CHECK(x == ev.unpack_skip_rows);
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_SWAP_BYTES
	x = ev.unpack_swap_bytes;
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.PackLSBFirst);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.UnpackLSBFirst);
# endif
# ifdef GL_PACK_ALIGNMENT
	BOOST_CHECK(x != ev.pack_alignment);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.pack_compressed_block_depth);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.pack_compressed_block_height);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.pack_compressed_block_size);
# endif
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_ROW_LENGTH
	BOOST_CHECK(x != ev.pack_row_length);
# endif
# ifdef GL_PACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.pack_skip_images);
# endif
# ifdef GL_PACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.pack_skip_pixels);
# endif
# ifdef GL_PACK_SKIP_ROWS
	BOOST_CHECK(x != ev.pack_skip_rows);
# endif
# ifdef GL_PACK_SWAP_BYTES
	BOOST_CHECK(x != ev.pack_swap_bytes);
# endif
# ifdef GL_UNPACK_ALIGNMENT
	BOOST_CHECK(x != ev.unpack_alignment);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	BOOST_CHECK(x != ev.unpack_compressed_block_depth);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	BOOST_CHECK(x != ev.unpack_compressed_block_height);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	BOOST_CHECK(x != ev.unpack_compressed_block_size);
# endif
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_ROW_LENGTH
	BOOST_CHECK(x != ev.unpack_row_length);
# endif
# ifdef GL_UNPACK_SKIP_IMAGES
	BOOST_CHECK(x != ev.unpack_skip_images);
# endif
# ifdef GL_UNPACK_SKIP_PIXELS
	BOOST_CHECK(x != ev.unpack_skip_pixels);
# endif
# ifdef GL_UNPACK_SKIP_ROWS
	BOOST_CHECK(x != ev.unpack_skip_rows);
# endif
	BOOST_CHECK(x == ev.unpack_swap_bytes);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
