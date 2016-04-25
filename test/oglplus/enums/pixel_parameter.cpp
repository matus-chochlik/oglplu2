//  File test/oglplus/enums/pixel_parameter.cpp
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
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE OGLPLUS_pixel_parameter

#include <boost/test/unit_test.hpp>
#include "common.hpp"
#include <cstring>

BOOST_AUTO_TEST_SUITE(enum_pixel_parameter_tests)

BOOST_AUTO_TEST_CASE(enum_pixel_parameter_values)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_parameter x;
	(void)x;

#ifdef GL_PACK_ALIGNMENT
	x = ev.pack_alignment;
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
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
	BOOST_CHECK(x == ev.pack_compressed_block_size);
# ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.pack_compressed_block_width);
# endif
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
	BOOST_CHECK(x == ev.pack_compressed_block_width);
# ifdef GL_PACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.pack_image_height);
# endif
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
	BOOST_CHECK(x == ev.pack_image_height);
# ifdef GL_PACK_LSB_FIRST
	BOOST_CHECK(x != ev.pack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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

#ifdef GL_PACK_LSB_FIRST
	x = ev.pack_lsb_first;
	BOOST_CHECK(x == ev.pack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
	BOOST_CHECK(x == ev.unpack_compressed_block_size);
# ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	BOOST_CHECK(x != ev.unpack_compressed_block_width);
# endif
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
	BOOST_CHECK(x == ev.unpack_compressed_block_width);
# ifdef GL_UNPACK_IMAGE_HEIGHT
	BOOST_CHECK(x != ev.unpack_image_height);
# endif
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
	BOOST_CHECK(x == ev.unpack_image_height);
# ifdef GL_UNPACK_LSB_FIRST
	BOOST_CHECK(x != ev.unpack_lsb_first);
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
	x = ev.unpack_lsb_first;
	BOOST_CHECK(x == ev.unpack_lsb_first);
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
	BOOST_CHECK(x == ev.unpack_skip_rows);
# ifdef GL_UNPACK_SWAP_BYTES
	BOOST_CHECK(x != ev.unpack_swap_bytes);
# endif
#endif

#ifdef GL_UNPACK_SWAP_BYTES
	x = ev.unpack_swap_bytes;
	BOOST_CHECK(x == ev.unpack_swap_bytes);
#endif
}

BOOST_AUTO_TEST_CASE(enum_pixel_parameter_names)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_parameter x;
	(void)x;

#ifdef GL_PACK_ALIGNMENT
	x = ev.pack_alignment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_ALIGNMENT"
	) == 0);
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	x = ev.pack_compressed_block_depth;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_COMPRESSED_BLOCK_DEPTH"
	) == 0);
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	x = ev.pack_compressed_block_height;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_COMPRESSED_BLOCK_HEIGHT"
	) == 0);
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	x = ev.pack_compressed_block_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_COMPRESSED_BLOCK_SIZE"
	) == 0);
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	x = ev.pack_compressed_block_width;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_COMPRESSED_BLOCK_WIDTH"
	) == 0);
#endif

#ifdef GL_PACK_IMAGE_HEIGHT
	x = ev.pack_image_height;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_IMAGE_HEIGHT"
	) == 0);
#endif

#ifdef GL_PACK_LSB_FIRST
	x = ev.pack_lsb_first;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_LSB_FIRST"
	) == 0);
#endif

#ifdef GL_PACK_ROW_LENGTH
	x = ev.pack_row_length;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_ROW_LENGTH"
	) == 0);
#endif

#ifdef GL_PACK_SKIP_IMAGES
	x = ev.pack_skip_images;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_SKIP_IMAGES"
	) == 0);
#endif

#ifdef GL_PACK_SKIP_PIXELS
	x = ev.pack_skip_pixels;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_SKIP_PIXELS"
	) == 0);
#endif

#ifdef GL_PACK_SKIP_ROWS
	x = ev.pack_skip_rows;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_SKIP_ROWS"
	) == 0);
#endif

#ifdef GL_PACK_SWAP_BYTES
	x = ev.pack_swap_bytes;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"PACK_SWAP_BYTES"
	) == 0);
#endif

#ifdef GL_UNPACK_ALIGNMENT
	x = ev.unpack_alignment;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_ALIGNMENT"
	) == 0);
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	x = ev.unpack_compressed_block_depth;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_COMPRESSED_BLOCK_DEPTH"
	) == 0);
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	x = ev.unpack_compressed_block_height;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_COMPRESSED_BLOCK_HEIGHT"
	) == 0);
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	x = ev.unpack_compressed_block_size;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_COMPRESSED_BLOCK_SIZE"
	) == 0);
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	x = ev.unpack_compressed_block_width;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_COMPRESSED_BLOCK_WIDTH"
	) == 0);
#endif

#ifdef GL_UNPACK_IMAGE_HEIGHT
	x = ev.unpack_image_height;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_IMAGE_HEIGHT"
	) == 0);
#endif

#ifdef GL_UNPACK_LSB_FIRST
	x = ev.unpack_lsb_first;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_LSB_FIRST"
	) == 0);
#endif

#ifdef GL_UNPACK_ROW_LENGTH
	x = ev.unpack_row_length;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_ROW_LENGTH"
	) == 0);
#endif

#ifdef GL_UNPACK_SKIP_IMAGES
	x = ev.unpack_skip_images;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_SKIP_IMAGES"
	) == 0);
#endif

#ifdef GL_UNPACK_SKIP_PIXELS
	x = ev.unpack_skip_pixels;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_SKIP_PIXELS"
	) == 0);
#endif

#ifdef GL_UNPACK_SKIP_ROWS
	x = ev.unpack_skip_rows;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_SKIP_ROWS"
	) == 0);
#endif

#ifdef GL_UNPACK_SWAP_BYTES
	x = ev.unpack_swap_bytes;
	BOOST_ASSERT(enum_value_name(x).data() != nullptr);
	BOOST_CHECK(std::strcmp(
		enum_value_name(x).data(),
		"UNPACK_SWAP_BYTES"
	) == 0);
#endif
}

BOOST_AUTO_TEST_CASE(enum_pixel_parameter_range)
{
	using namespace oglplus;
	auto count = enum_value_range<pixel_parameter>().size();

#ifdef GL_PACK_ALIGNMENT
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_PACK_ALIGNMENT)
	) != r.end());
}
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_PACK_COMPRESSED_BLOCK_DEPTH)
	) != r.end());
}
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_PACK_COMPRESSED_BLOCK_HEIGHT)
	) != r.end());
}
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_PACK_COMPRESSED_BLOCK_SIZE)
	) != r.end());
}
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_PACK_COMPRESSED_BLOCK_WIDTH)
	) != r.end());
}
#endif

#ifdef GL_PACK_IMAGE_HEIGHT
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_PACK_IMAGE_HEIGHT)
	) != r.end());
}
#endif

#ifdef GL_PACK_LSB_FIRST
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_PACK_LSB_FIRST)
	) != r.end());
}
#endif

#ifdef GL_PACK_ROW_LENGTH
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_PACK_ROW_LENGTH)
	) != r.end());
}
#endif

#ifdef GL_PACK_SKIP_IMAGES
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_PACK_SKIP_IMAGES)
	) != r.end());
}
#endif

#ifdef GL_PACK_SKIP_PIXELS
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_PACK_SKIP_PIXELS)
	) != r.end());
}
#endif

#ifdef GL_PACK_SKIP_ROWS
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_PACK_SKIP_ROWS)
	) != r.end());
}
#endif

#ifdef GL_PACK_SWAP_BYTES
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_PACK_SWAP_BYTES)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_ALIGNMENT
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_UNPACK_ALIGNMENT)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_UNPACK_COMPRESSED_BLOCK_DEPTH)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_UNPACK_COMPRESSED_BLOCK_HEIGHT)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_UNPACK_COMPRESSED_BLOCK_SIZE)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_UNPACK_COMPRESSED_BLOCK_WIDTH)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_IMAGE_HEIGHT
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_UNPACK_IMAGE_HEIGHT)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_LSB_FIRST
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_UNPACK_LSB_FIRST)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_ROW_LENGTH
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_UNPACK_ROW_LENGTH)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_SKIP_IMAGES
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_UNPACK_SKIP_IMAGES)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_SKIP_PIXELS
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_UNPACK_SKIP_PIXELS)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_SKIP_ROWS
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_UNPACK_SKIP_ROWS)
	) != r.end());
}
#endif

#ifdef GL_UNPACK_SWAP_BYTES
{
	--count;
	auto r = enum_value_range<pixel_parameter>();
	BOOST_CHECK(std::find(
		r.begin(), r.end(),
		pixel_parameter(GL_UNPACK_SWAP_BYTES)
	) != r.end());
}
#endif
	BOOST_CHECK_EQUAL(count, 0);
}

BOOST_AUTO_TEST_CASE(enum_pixel_parameter_any)
{
	using namespace oglplus;
	enum_values ev;
	(void)ev;
	pixel_parameter x, y;
	(void)x;
	(void)y;
	any_enum_value a;
	(void)a;

#ifdef GL_PACK_ALIGNMENT
	x = ev.pack_alignment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_alignment);
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_DEPTH
	x = ev.pack_compressed_block_depth;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_compressed_block_depth);
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_HEIGHT
	x = ev.pack_compressed_block_height;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_compressed_block_height);
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_SIZE
	x = ev.pack_compressed_block_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_compressed_block_size);
#endif

#ifdef GL_PACK_COMPRESSED_BLOCK_WIDTH
	x = ev.pack_compressed_block_width;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_compressed_block_width);
#endif

#ifdef GL_PACK_IMAGE_HEIGHT
	x = ev.pack_image_height;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_image_height);
#endif

#ifdef GL_PACK_LSB_FIRST
	x = ev.pack_lsb_first;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_lsb_first);
#endif

#ifdef GL_PACK_ROW_LENGTH
	x = ev.pack_row_length;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_row_length);
#endif

#ifdef GL_PACK_SKIP_IMAGES
	x = ev.pack_skip_images;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_skip_images);
#endif

#ifdef GL_PACK_SKIP_PIXELS
	x = ev.pack_skip_pixels;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_skip_pixels);
#endif

#ifdef GL_PACK_SKIP_ROWS
	x = ev.pack_skip_rows;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_skip_rows);
#endif

#ifdef GL_PACK_SWAP_BYTES
	x = ev.pack_swap_bytes;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.pack_swap_bytes);
#endif

#ifdef GL_UNPACK_ALIGNMENT
	x = ev.unpack_alignment;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_alignment);
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_DEPTH
	x = ev.unpack_compressed_block_depth;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_compressed_block_depth);
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_HEIGHT
	x = ev.unpack_compressed_block_height;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_compressed_block_height);
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_SIZE
	x = ev.unpack_compressed_block_size;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_compressed_block_size);
#endif

#ifdef GL_UNPACK_COMPRESSED_BLOCK_WIDTH
	x = ev.unpack_compressed_block_width;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_compressed_block_width);
#endif

#ifdef GL_UNPACK_IMAGE_HEIGHT
	x = ev.unpack_image_height;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_image_height);
#endif

#ifdef GL_UNPACK_LSB_FIRST
	x = ev.unpack_lsb_first;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_lsb_first);
#endif

#ifdef GL_UNPACK_ROW_LENGTH
	x = ev.unpack_row_length;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_row_length);
#endif

#ifdef GL_UNPACK_SKIP_IMAGES
	x = ev.unpack_skip_images;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_skip_images);
#endif

#ifdef GL_UNPACK_SKIP_PIXELS
	x = ev.unpack_skip_pixels;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_skip_pixels);
#endif

#ifdef GL_UNPACK_SKIP_ROWS
	x = ev.unpack_skip_rows;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_skip_rows);
#endif

#ifdef GL_UNPACK_SWAP_BYTES
	x = ev.unpack_swap_bytes;
	a = x;
	y = a;
	BOOST_CHECK(same_enum_class(x, a));
	BOOST_CHECK(same_enum_class(a, y));
	BOOST_CHECK(same_enum_class(x, y));
	BOOST_CHECK(y == ev.unpack_swap_bytes);
#endif
}

BOOST_AUTO_TEST_SUITE_END()
