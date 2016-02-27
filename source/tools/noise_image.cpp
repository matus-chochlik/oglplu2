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
	eagine::cstr_ref output_path;
	eagine::cstr_ref format_name;
	eagine::valid_if_positive<GLsizei> components;
	eagine::valid_if_positive<GLsizei> width;
	eagine::valid_if_positive<GLsizei> height;
	eagine::valid_if_positive<GLsizei> depth;

	options(void)
	 : output_path("a.oglptex")
	 , format_name("R8")
	 , components(1)
	 , width(256)
	 , height(256)
	 , depth(1)
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

	if(opts.output_path == eagine::cstr_ref("-"))
	{
		write_output(std::cout, opts);
	}
	else
	{
		std::ofstream output_file(opts.output_path.c_str());
		write_output(output_file, opts);
	}
	return 0;
}

template <typename T>
bool consume_next(eagine::program_arg& a, T& dest)
{
	return a.consume_next(dest, std::cerr);
}

template <typename T, typename C>
bool consume_next(
	eagine::program_arg& a,
	T& dest,
	eagine::span<const C> choices
)
{
	return a.consume_next(dest, choices, std::cerr);
}

template <typename T, typename C>
bool consume_next(
	eagine::program_arg& a,
	T& dest,
	eagine::span<const eagine::cstr_ref> symbols,
	eagine::span<const C> translations
)
{
	return a.consume_next(dest, symbols, translations, std::cerr);
}

bool parse_argument(eagine::program_arg& a, options& opts)
{
	const eagine::cstr_ref fmtnames[] = {"R8", "RG8", "RGB8", "RGBA8"};
	const eagine::span<const eagine::cstr_ref> formats =
		eagine::as_span(fmtnames);

	const GLsizei cmpbytes[] = {1, 2, 3, 4};
	const eagine::span<const GLsizei> components =
		eagine::as_span(cmpbytes);

	if((a == "-o") || (a == "--output"))
	{
		if(!consume_next(a, opts.output_path)) return false;
	}
	else if((a == "-f") || (a == "--format"))
	{
		if(!consume_next(a, opts.components, formats, components))
			return false;
	}
	else if((a == "-c") || (a == "--components"))
	{
		if(!consume_next(a, opts.components, components))
			return false;
	}
	else if((a == "-w") || (a == "--width"))
	{
		if(!consume_next(a, opts.width)) return false;
	}
	else if((a == "-h") || (a == "--height"))
	{
		if(!consume_next(a, opts.height)) return false;
	}
	else if((a == "-d") || (a == "--depth"))
	{
		if(!consume_next(a, opts.depth)) return false;
	}
	else
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

