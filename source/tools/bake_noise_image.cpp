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
	typedef eagine::program_parameter<eagine::cstr_ref> _str_param_t;
	typedef eagine::valid_if_positive<GLsizei> _pos_int_t;
	typedef eagine::program_parameter<_pos_int_t> _int_param_t;
	typedef eagine::program_parameter_alias<_pos_int_t> _int_alias_t;
	typedef eagine::program_option _opt_param_t;

	_str_param_t output_path;
	_int_param_t components;
	_int_alias_t format;
	_int_param_t width;
	_int_param_t height;
	_int_param_t depth;
	_opt_param_t verbosity;

	eagine::program_parameters all;

	options(void)
	 : output_path("-o", "--output", "a.oglptex")
	 , components("-c", "--components", 1)
	 , format("-f", "--format", components)
	 , width("-w", "--width", 256)
	 , height("-h", "--height", 256)
	 , depth("-d", "--depth", 1)
	 , verbosity("-v", "--verbose")
	 , all(output_path, components, width, height, depth, verbosity)
	{ }

	void print_usage(std::ostream& log)
	{
		log <<	"bake_noise_image options" << std::endl;
		log <<	"  options:" << std::endl;
		log <<	"   -o|--output PATH: Output file path "
			"or '-' for stdout." << std::endl;
		log <<	"   -c|--components N: Number of components.";
		log <<	std::endl;
		log <<	"   -f|--format FORMAT: Output format." << std::endl;
		log <<	"     FORMAT is one of the following:" << std::endl;
		log <<	"       R8" << std::endl;
		log <<	"       RG8" << std::endl;
		log <<	"       RGB8" << std::endl;
		log <<	"       RGBB8" << std::endl;
		log <<	"   -w|--width N: Output image width." << std::endl;
		log <<	"   -h|--height N: Output image height." << std::endl;
		log <<	"   -d|--depth N: Output image depth." << std::endl;
	}

	bool check(std::ostream& log) const
	{
		return	all.validate(log);
	}

	bool parse(eagine::program_arg& a, std::ostream& log)
	{
		const eagine::cstr_ref fmtnamevals[] =
			{"R8", "RG8", "RGB8", "RGBA8"};
		const eagine::span<const eagine::cstr_ref> fmtnames =
			eagine::as_span(fmtnamevals);

		const GLsizei cmpbytevals[] = {1, 2, 3, 4};
		const eagine::span<const GLsizei> cmpbytes =
			eagine::as_span(cmpbytevals);

		return	a.parse_param(output_path, log) ||
			a.parse_param(components, cmpbytes, log) ||
			a.parse_param(format, fmtnames, cmpbytes, log) ||
			a.parse_param(width, log) ||
			a.parse_param(height, log) ||
			a.parse_param(depth, log) ||
			a.parse_param(verbosity, log);
	}
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

	if(!opts.parse(a, std::cerr))
	{
		std::cerr
			<< "Failed to parse argument '"
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
		if(a.is_help_arg())
		{
			opts.print_usage(std::cout);
			return 1;
		}
		else if(!parse_argument(a, opts))
		{
			opts.print_usage(std::cerr);
			return 2;
		}
	}

	if(!opts.check(std::cerr))
	{
		opts.print_usage(std::cerr);
		return 2;
	}

	return 0;
}

