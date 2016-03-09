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

struct options
{
	typedef eagine::program_parameter<eagine::cstr_ref>
		_str_param_t;
	typedef eagine::program_parameter<eagine::valid_if_positive<GLsizei>>
		_int_param_t;

	_str_param_t output_path;
	_int_param_t width;
	_int_param_t height;
	_int_param_t depth;
	_int_param_t rep_x;
	_int_param_t rep_y;
	_int_param_t rep_z;

	eagine::program_parameters all;

	options(void)
	 : output_path("-o", "--output", "a.oglptex")
	 , width("-w", "--width", 256)
	 , height("-h", "--height", 256)
	 , depth("-d", "--depth", 1)
	 , rep_x("-x", "--x-repeat", 8)
	 , rep_y("-y", "--y-repeat", 8)
	 , rep_z("-z", "--z-repeat", 8)
	 , all(output_path, width, height, depth, rep_x, rep_y, rep_z)
	{
		output_path.description(
		"Output file path, or '-' for standard output."
		);
		width.description("Output image width in pixels.");
		height.description("Output image height in pixels.");
		depth.description("Output image depth in pixels.");
		rep_x.description("Pattern repeat along the X axis.");
		rep_y.description("Pattern repeat along the Y axis.");
		rep_z.description("Pattern repeat along the Z axis.");
	}

	void print_usage(std::ostream& log)
	{
		all.print_usage(log, "bake_checker_image");
	}

	bool check(std::ostream& log)
	{
		return all.validate(log);
	}

	bool parse(eagine::program_arg& arg, std::ostream& log)
	{
		return all.parse(arg, log);
	}
};

void write_output(std::ostream& output, const options& opts)
{
	oglplus::image_data_header hdr(opts.width, opts.height, opts.depth);
	hdr.format = GL_RGB;
	hdr.internal_format = GL_R3_G3_B2;
	hdr.data_type = GL_UNSIGNED_BYTE_3_3_2;

	const std::size_t size = std::size_t(
		opts.width.value()*
		opts.height.value()*
		opts.depth.value()
	);

	oglplus::write_and_pad_texture_image_data_header(output, hdr, size);

	const GLsizei fd = opts.depth.value() / opts.rep_z.value();
	const GLsizei fh = opts.height.value()/ opts.rep_y.value();
	const GLsizei fw = opts.width.value() / opts.rep_x.value();

	for(GLsizei z=0; z<hdr.depth; ++z)
	{
		const GLsizei fz = (fd == 0? 0 : z / fd);
		for(GLsizei y=0; y<hdr.height; ++y)
		{
			const GLsizei fy = (fh == 0 ? 0 : y / fh);
			for(GLsizei x=0; x<hdr.width; ++x)
			{
				const GLsizei fx = (fw == 0 ? 0 : x / fw);
				bool black = ((fx%2)+(fy%2)+(fz%2))%2 == 0;
				output.put(char(black?0x00:0xFF));
			}
		}
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
		return 3;
	}

	return 0;
}

