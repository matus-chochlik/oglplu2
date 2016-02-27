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
	eagine::cstr_ref output_path;
	eagine::valid_if_positive<GLsizei> width;
	eagine::valid_if_positive<GLsizei> height;
	eagine::valid_if_positive<GLsizei> depth;
	eagine::valid_if_positive<GLsizei> rep_x;
	eagine::valid_if_positive<GLsizei> rep_y;
	eagine::valid_if_positive<GLsizei> rep_z;

	options(void)
	 : output_path("a.oglptex")
	 , width(256)
	 , height(256)
	 , depth(1)
	 , rep_x(8)
	 , rep_y(8)
	 , rep_z(8)
	{ }
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

bool parse_argument(eagine::program_arg& a, options& opts)
{
	if((a == "-o") || (a == "--output"))
	{
		if(!consume_next(a, opts.output_path)) return false;
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
	else if((a == "-x") || (a == "--x-repeat"))
	{
		if(!consume_next(a, opts.rep_x)) return false;
	}
	else if((a == "-y") || (a == "--y-repeat"))
	{
		if(!consume_next(a, opts.rep_y)) return false;
	}
	else if((a == "-z") || (a == "--z-repeat"))
	{
		if(!consume_next(a, opts.rep_z)) return false;
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

