/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/utils/image_file_io.hpp>
#include <eagine/program_args.hpp>
#include <eagine/valid_if.hpp>
#include <fstream>
#include <random>
#include <climits>

struct options
{
	typedef eagine::program_parameter<eagine::cstr_ref>
		_str_param_t;
	typedef eagine::program_parameter<eagine::valid_if_positive<GLsizei>>
		_int_param_t;

	_str_param_t output_path;
	_str_param_t format_name;
	_int_param_t components;
	_int_param_t width;
	_int_param_t height;
	_int_param_t depth;

	options(void)
	 : output_path("-o", "--output", "a.oglptex")
	 , format_name("-f", "--format", "R8")
	 , components("-c", "--components", 1)
	 , width("-w", "--width", 256)
	 , height("-h", "--height", 256)
	 , depth("-d", "--depth", 1)
	{ }
};

void write_output(std::ostream& output, const options& opts)
{
	oglplus::image_data_header hdr(opts.width, opts.height, opts.depth);
	switch(opts.components.value())
	{
		case 1:
			hdr.format = GL_RED;
			hdr.internal_format = GL_R8;
			break;
		case 2:
			hdr.format = GL_RG;
			hdr.internal_format = GL_RG8;
			break;
		case 3:
			hdr.format = GL_RGB;
			hdr.internal_format = GL_RGB8;
			break;
		case 4:
			hdr.format = GL_RGBA;
			hdr.internal_format = GL_RGBA8;
			break;
	};

	hdr.data_type = GL_UNSIGNED_BYTE;

	const std::size_t size = std::size_t(
		opts.width.value()*
		opts.height.value()*
		opts.depth.value()*
		opts.components.value()
	);

	oglplus::write_and_pad_texture_image_data_header(output, hdr, size);

	const unsigned mask = ((1 << CHAR_BIT)-1);

	std::random_device rd;
	std::independent_bits_engine<std::mt19937, CHAR_BIT,unsigned> ibe(rd());

	for(std::size_t i=0; i<size; ++i)
	{
		output.put(char(ibe() & mask));
	}
}

int parse_options(int argc, const char** argv, options& opts);

int main(int argc, const char** argv)
{
	options opts;

	if(int err = parse_options(argc, argv, opts))
	{
		return err;
	}

	if(opts.output_path.value() == eagine::cstr_ref("-"))
	{
		write_output(std::cout, opts);
	}
	else
	{
		std::ofstream output_file(opts.output_path.value().c_str());
		write_output(output_file, opts);
	}
	return 0;
}

bool parse_argument(eagine::program_arg& a, options& opts)
{
	const eagine::cstr_ref fmtnames[] = {"R8", "RG8", "RGB8", "RGBA8"};
	const eagine::span<const eagine::cstr_ref> formats =
		eagine::as_span(fmtnames);

	const GLsizei cmpbytes[] = {1, 2, 3, 4};
	const eagine::span<const GLsizei> components =
		eagine::as_span(cmpbytes);

	if(
		!a.parse_param(opts.output_path, std::cerr) &&
		!a.parse_param(opts.width, std::cerr) &&
		!a.parse_param(opts.height, std::cerr) &&
		!a.parse_param(opts.depth, std::cerr) &&
		!a.parse_param(opts.components, components, std::cerr) &&
		!a.parse_param(opts.components, formats,components, std::cerr)
	)
	{
		std::cerr
			<< "Unknown argument '"
			<< a.get()
			<< "'"
			<< std::endl;
		return false;
	}
	return true;
}

int parse_options(int argc, const char** argv, options& opts)
{
	eagine::program_args args(argc, argv);

	for(eagine::program_arg a = args.first(); a; a = a.next())
	{
		if(!parse_argument(a, opts))
		{
			return 1;
		}
	}
	return 0;
}

