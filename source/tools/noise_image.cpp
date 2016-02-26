/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/utils/image_file_io.hpp>
#include <eagine/valid_if.hpp>
#include <fstream>
#include <random>
#include <climits>

namespace oglplus {

inline
void write_3d_noise_data(
	std::ostream& output,
	valid_if_positive<GLsizei> width,
	valid_if_positive<GLsizei> height,
	valid_if_positive<GLsizei> depth,
	valid_if_positive<GLsizei> components
)
{
	const unsigned mask = ((1 << CHAR_BIT)-1);

	std::random_device rd;
	std::independent_bits_engine<std::mt19937, CHAR_BIT,unsigned> ibe(rd());

	const std::size_t n = std::size_t(
		width.value()*
		height.value()*
		depth.value()*
		components.value()
	);
	for(std::size_t i=0; i<n; ++i)
	{
		output.put(char(ibe() & mask));
	}
}

inline
void write_3d_red_ub_noise(
	std::ostream& output,
	valid_if_positive<GLsizei> width,
	valid_if_positive<GLsizei> height,
	valid_if_positive<GLsizei> depth
)
{
	image_data_header hdr(width, height, depth);
	hdr.format = GL_RED;
	hdr.internal_format = GL_R8;
	hdr.data_type = GL_UNSIGNED_BYTE;

	write_and_pad_texture_image_data_header(
		output,
		hdr,
		std::size_t(hdr.width*hdr.height*hdr.depth)
	);

	write_3d_noise_data(output, width, height, depth, 1);
}

} // namespace oglplus

struct options
{
	std::string output_path;
	GLsizei width;
	GLsizei height;
	GLsizei depth;

	options(void)
	 : output_path("a.oglptex")
	 , width(256)
	 , height(256)
	 , depth(1)
	{ }
};

int parse_options(int argc, const char** argv, options& opts);

int main(int argc, const char** argv)
{
	options opts;

	if(int err = parse_options(argc, argv, opts))
	{
		return err;
	}

	std::ofstream output_file(opts.output_path);
	oglplus::write_3d_red_ub_noise(
		output_file,
		opts.width,
		opts.height,
		opts.depth
	);

	return 0;
}

int parse_options(int argc, const char** argv, options& opts)
{
	// TODO
	(void) argc;
	(void) argv;
	(void) opts;
	return 0;
}

