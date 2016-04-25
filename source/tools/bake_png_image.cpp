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
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <png.h>

// program options
struct options
{
	typedef eagine::program_parameter<
		eagine::valid_if_not_empty<eagine::cstr_ref>
	> _str_param_t;

	_str_param_t input_path;
	_str_param_t output_path;

	eagine::program_parameters all;

	options(void)
	 : input_path("-i", "--input", eagine::cstr_ref())
	 , output_path("-o", "--output", eagine::cstr_ref("a.oglptex"))
	 , all(input_path, output_path)
	{
		input_path.description(
		"Path to existing PNG input file, or '-' for standard input."
		);
		output_path.description(
		"Path to output file, or '-' for standard output."
		);
	}

	void print_usage(std::ostream& log)
	{
		all.print_usage(log, "bake_png_image");
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

// png_header_validator
class png_header_validator
{
public:
	png_header_validator(std::istream& input);
};

class png_read_driver;

// png_read_struct
class png_read_struct
{
protected:
	::png_structp _read;

	[[noreturn]] static
	void _handle_error(::png_structp, const char* msg);

	static
	void _handle_warning(::png_structp, const char* msg);

	friend class png_read_driver;
public:
	png_read_struct(void);
	~png_read_struct(void) noexcept;
};

// png_read_info_struct 
class png_read_info_struct
 : public png_read_struct
{
protected:
	::png_infop _info;

	friend class png_read_driver;
public:
	png_read_info_struct(void);
	~png_read_info_struct(void) noexcept;

	png_uint_32 row_bytes(void);
	png_uint_32 image_width(void);
	png_uint_32 image_height(void);
	png_byte bit_depth(void);
	png_byte channels(void);
	png_byte color_type(void);

	void set_palette_to_rgb(void);
	void set_expand_gray_1_2_4_to_8(void);
	void set_tRNS_to_alpha(void);
	png_uint_32 get_valid(png_uint_32);
};

// png_read_info_end_struct 
class png_read_info_end_struct
 : public png_read_info_struct
{
protected:
	::png_infop _endi;

	friend class png_read_driver;
public:
	png_read_info_end_struct(void);
	~png_read_info_end_struct(void) noexcept;
};

class png_reader;

// png_read_driver
class png_read_driver
{
private:
	png_read_info_end_struct& _png;

	static
	void _read_data(::png_structp, ::png_bytep, ::png_size_t);

	static
	int _read_user_chunk(::png_structp, ::png_unknown_chunkp);

	void _read_row(::png_bytep data);

	friend class png_reader;
public:
	png_read_driver(png_reader& reader);
};

// png_reader
class png_reader
{
private:
	std::istream& _input;
	png_header_validator _validator;
	png_read_info_end_struct _png;
	png_read_driver _driver;

	friend class png_read_driver;
public:
	png_reader(std::istream& input);

	void do_read_data(::png_bytep, ::png_size_t);
	void read_row(::png_bytep data) { _driver._read_row(data); }

	png_uint_32 image_width(void) { return _driver._png.image_width(); }
	png_uint_32 image_height(void) { return _driver._png.image_height(); }
	png_uint_32 row_bytes(void) { return _driver._png.row_bytes(); }
	png_uint_32 data_size(void) { return row_bytes() * image_height(); }

	GLenum gl_data_type(void);
	GLenum gl_format(void);
	GLenum gl_iformat(void);
};

void convert_image(
	std::istream& input,
	std::ostream& output,
	const options& /*opts*/
)
{
	png_reader reader(input);

	int width = int(reader.image_width());
	int height = int(reader.image_height());

	oglplus::image_data_header hdr(width, height, 1);

	hdr.data_type = reader.gl_data_type();
	hdr.format = reader.gl_format();
	hdr.internal_format = reader.gl_iformat();


	std::size_t row_size = std::size_t(reader.row_bytes());
	std::size_t size = std::size_t(reader.data_size());

	oglplus::write_and_pad_texture_image_data_header(output, hdr, size);

	std::vector< ::png_byte> buffer(size);

	for(png_uint_32 r=0, h=reader.image_height(); r<h; ++r)
	{
		reader.read_row(buffer.data()+(h-1-r)*row_size);
	}

	output.write(
		reinterpret_cast<const char*>(buffer.data()),
		static_cast<std::streamsize>(buffer.size())
	);
}

int parse_options(int argc, const char** argv, options& opts);

int main(int argc, const char** argv)
{
	options opts;

	if(int err = parse_options(argc, argv, opts))
	{
		return err;
	}

	bool from_stdin = opts.input_path.value() == eagine::cstr_ref("-");
	bool to_stdout = opts.output_path.value() == eagine::cstr_ref("-");

	if(from_stdin && to_stdout)
	{
		convert_image(std::cin, std::cout, opts);
	}
	else if(from_stdin)
	{
		std::ofstream output_file(opts.output_path.value().c_str());
		convert_image(std::cin, output_file, opts);
	}
	else if(to_stdout)
	{
		std::ifstream input_file(opts.input_path.value().c_str());
		convert_image(input_file, std::cout, opts);
	}
	else
	{
		std::ifstream input_file(opts.input_path.value().c_str());
		std::ofstream output_file(opts.output_path.value().c_str());
		convert_image(input_file, output_file, opts);
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

png_header_validator::
png_header_validator(std::istream& input)
{
	if(!input.good())
	{
		throw
		std::runtime_error("Unable to read PNG input stream");
	}

	const size_t sig_size = 8;
	::png_byte sig[sig_size];
	input.read(reinterpret_cast<char*>(sig), sig_size);

	if(!input.good())
	{
		throw
		std::runtime_error("Unable to read PNG signature");
	}

	if(::png_sig_cmp(sig, 0, sig_size) != 0)
	{
		throw
		std::runtime_error("Invalid PNG signature");
	}
}

[[noreturn]] void
png_read_struct::
_handle_error(::png_structp, const char* message)
{
	throw ::std::runtime_error(message);
}

void
png_read_struct::
_handle_warning(::png_structp, const char* message)
{
	::std::cerr << "libpng warning: " << message << ::std::endl;
}

png_read_struct::
png_read_struct(void)
 : _read(::png_create_read_struct(
	PNG_LIBPNG_VER_STRING,
	reinterpret_cast<::png_voidp>(this),
	&_handle_error,
	&_handle_warning
))
{
	if(!_read)
	{
		throw
		std::runtime_error("Unable to create PNG read struct");
	}
}

png_read_struct::
~png_read_struct(void)
noexcept
{
	try { ::png_destroy_read_struct(&_read, nullptr, nullptr); }
	catch (...) { }
}

png_read_info_struct::
png_read_info_struct(void)
 : png_read_struct()
 , _info(::png_create_info_struct(_read))
{
	if(!_info)
	{
		throw
		std::runtime_error("Unable to create PNG info struct");
	}
}

png_read_info_struct::
~png_read_info_struct(void)
noexcept
{
	try { ::png_destroy_read_struct(&_read, &_info, nullptr); }
	catch (...) { }
}

png_uint_32
png_read_info_struct::
row_bytes(void)
{
	return ::png_get_rowbytes(_read, _info);
}

png_uint_32
png_read_info_struct::
image_width(void)
{
	return ::png_get_image_width(_read, _info);
}

png_uint_32
png_read_info_struct::
image_height(void)
{
	return ::png_get_image_height(_read, _info);
}

png_byte
png_read_info_struct::
bit_depth(void)
{
	return ::png_get_bit_depth(_read, _info);
}

png_byte
png_read_info_struct::
channels(void)
{
	return ::png_get_channels(_read, _info);
}

png_byte
png_read_info_struct::
color_type(void)
{
	return ::png_get_color_type(_read, _info);
}

void
png_read_info_struct::
set_palette_to_rgb(void)
{
	::png_set_palette_to_rgb(_read);
}

void
png_read_info_struct::
set_expand_gray_1_2_4_to_8(void)
{
	::png_set_expand_gray_1_2_4_to_8(_read);
}

void
png_read_info_struct::
set_tRNS_to_alpha(void)
{
	::png_set_tRNS_to_alpha(_read);
}

png_uint_32
png_read_info_struct::
get_valid(png_uint_32 flag)
{
	return ::png_get_valid(_read, _info, flag);
}

png_read_info_end_struct::
png_read_info_end_struct(void)
 : png_read_info_struct()
 , _endi(::png_create_info_struct(_read))
{
	if(!_endi)
	{
		throw
		std::runtime_error("Unable to create PNG end info struct");
	}
}

png_read_info_end_struct::
~png_read_info_end_struct(void)
noexcept
{
	try { ::png_destroy_read_struct(&_read, &_info, &_endi); }
	catch (...) { }
}

void
png_read_driver::
_read_data(::png_structp png, ::png_bytep data, ::png_size_t size)
{
	::png_voidp p = ::png_get_io_ptr(png);
	assert(p != 0);
	(reinterpret_cast<png_reader*>(p))->do_read_data(data, size);
}

int
png_read_driver::
_read_user_chunk(::png_structp, ::png_unknown_chunkp)
{
	return 0;
}

void
png_read_driver::
_read_row(::png_bytep data)
{
	::png_read_row(_png._read, data, nullptr);
}

png_read_driver::
png_read_driver(png_reader& reader)
 : _png(reader._png)
{
	::png_set_read_fn(_png._read, &reader, &_read_data);
	::png_set_read_user_chunk_fn(_png._read, &reader, &_read_user_chunk);
	::png_set_keep_unknown_chunks(_png._read, PNG_HANDLE_CHUNK_NEVER, 0,0);

	const size_t sig_size = 8;
	::png_set_sig_bytes(_png._read, sig_size);
	::png_read_info(_png._read, _png._info);
}

png_reader::
png_reader(std::istream& input)
 : _input(input)
 , _validator(_input)
 , _driver(*this)
{
	switch(_driver._png.color_type())
	{
		case PNG_COLOR_TYPE_PALETTE:
		{
			_driver._png.set_palette_to_rgb();
			break;
		}
		case PNG_COLOR_TYPE_GRAY:
		{
			if(_png.bit_depth() < 8)
			{
				_driver._png.set_expand_gray_1_2_4_to_8();
			}
			break;
		}
		default:;
	}

	if(_driver._png.get_valid(PNG_INFO_tRNS))
	{
		_driver._png.set_tRNS_to_alpha();
	}
}

GLenum
png_reader::
gl_data_type(void)
{
	switch(_driver._png.bit_depth())
	{
		case 1:
		case 2:
		case 4:
		case 8: return GL_UNSIGNED_BYTE;
		case 16: return GL_UNSIGNED_SHORT;
		default:
			throw
			std::runtime_error("Unsupported PNG image color depth");
	}
	
	return GL_NONE;
}

GLenum
png_reader::
gl_format(void)
{
	switch(_driver._png.color_type())
	{
		case PNG_COLOR_TYPE_GRAY:
			return GL_RED;
		case PNG_COLOR_TYPE_GRAY_ALPHA:
			return GL_RG;
		case PNG_COLOR_TYPE_PALETTE:
		case PNG_COLOR_TYPE_RGB:
			return GL_RGB;
		case PNG_COLOR_TYPE_RGB_ALPHA:
			return GL_RGBA;
		default:
			throw
			std::runtime_error("Unsupported PNG color type");
	}
}

GLenum
png_reader::
gl_iformat(void)
{
	if(_driver._png.bit_depth() == 16)
	{
		switch(gl_format())
		{
			case GL_RED: return GL_R16;
			case GL_RG: return GL_RG16;
			case GL_RGB: return GL_RGB16;
			case GL_RGBA: return GL_RGBA16;
			default:;
		}
	}
	else
	{
		switch(gl_format())
		{
			case GL_RED: return GL_R8;
			case GL_RG: return GL_RG8;
			case GL_RGB: return GL_RGB8;
			case GL_RGBA: return GL_RGBA8;
			default:;
		}
	}

	return GL_NONE;
}

void
png_reader::
do_read_data(::png_bytep data, ::png_size_t size)
{
	_input.read(reinterpret_cast<char*>(data), std::streamsize(size));
	if(!_input.good())
	{
		throw
		std::runtime_error("Unable to read PNG data");
	}
}

