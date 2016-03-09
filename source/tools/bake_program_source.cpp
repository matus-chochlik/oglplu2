/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl.hpp>
#include <oglplus/utils/program_file_io.hpp>
#include <eagine/program_args.hpp>
#include <eagine/valid_if.hpp>
#include <eagine/file_contents.hpp>
#include <fstream>

struct options
{
	typedef eagine::program_parameter<
		eagine::valid_if_not_empty<eagine::cstr_ref>
	> _str_param_t;

	typedef eagine::program_parameter<
		std::vector<
			eagine::valid_if_not_empty<eagine::cstr_ref>
		>
	> _str_list_param_t;

	_str_list_param_t vertex_shader_paths;
#ifdef GL_GEOMETRY_SHADER
	_str_list_param_t geometry_shader_paths;
#endif
#ifdef GL_TESS_CONTROL_SHADER
	_str_list_param_t tess_control_shader_paths;
#endif
#ifdef GL_TESS_EVALUATION_SHADER
	_str_list_param_t tess_evaluation_shader_paths;
#endif
	_str_list_param_t fragment_shader_paths;
#ifdef GL_COMPUTE_SHADER
	_str_list_param_t compute_shader_paths;
#endif

	_str_param_t output_path;

	eagine::program_parameters all;

	options(void)
	 : vertex_shader_paths("-vx", "--vertex", {})
#ifdef GL_GEOMETRY_SHADER
	 , geometry_shader_paths("-gy", "--geometry", {})
#endif
#ifdef GL_TESS_CONTROL_SHADER
	 , tess_control_shader_paths("-tc", "--tess-control", {})
#endif
#ifdef GL_TESS_EVALUATION_SHADER
	 , tess_evaluation_shader_paths("-te", "--tess-evaluation", {})
#endif
	 , fragment_shader_paths("-ft", "--fragment", {})
#ifdef GL_COMPUTE_SHADER
	 , compute_shader_paths("-ce", "--compute", {})
#endif
	 , output_path("-o", "--output", eagine::cstr_ref("a.oglpprog"))
	 , all(
		vertex_shader_paths,
#ifdef GL_GEOMETRY_SHADER
		geometry_shader_paths,
#endif
#ifdef GL_TESS_CONTROL_SHADER
		tess_control_shader_paths,
#endif
#ifdef GL_TESS_EVALUATION_SHADER
		tess_evaluation_shader_paths,
#endif
		fragment_shader_paths,
#ifdef GL_COMPUTE_SHADER
		compute_shader_paths,
#endif
		output_path
	)
	{
		vertex_shader_paths.description(
		"Path to existing vertex shader source file."
		);
#ifdef GL_GEOMETRY_SHADER
		geometry_shader_paths.description(
		"Path to existing geometry shader source file."
		);
#endif
#ifdef GL_TESS_CONTROL_SHADER
		tess_control_shader_paths.description(
		"Path to existing tessellation control shader source file."
		);
#endif
#ifdef GL_TESS_EVALUATION_SHADER
		tess_evaluation_shader_paths.description(
		"Path to existing tessellation evaluation shader source file."
		);
#endif
		fragment_shader_paths.description(
		"Path to existing fragment shader source file."
		);
#ifdef GL_COMPUTE_SHADER
		compute_shader_paths.description(
		"Path to existing compute shader source file."
		);
#endif
		output_path.description(
		"Output file path, or '-' for standard output."
		);
		
	}

	void print_usage(std::ostream& log)
	{
		all.print_usage(log, "bake_program_source");
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

void read_shader_source_texts(
	std::vector<eagine::file_contents>& source_texts,
	std::vector<GLenum>& shader_types,
	GLenum shader_type,
	const std::vector<eagine::valid_if_not_empty<eagine::cstr_ref>>& paths
)
{
	for(const eagine::valid_if_not_empty<eagine::cstr_ref>& path : paths)
	{
		source_texts.push_back(eagine::file_contents(path.value()));
		shader_types.push_back(shader_type);
	}
}

void write_output(std::ostream& output, const options& opts)
{
	std::vector<eagine::file_contents> source_texts;
	std::vector<GLenum> shader_types;

	read_shader_source_texts(
		source_texts,
		shader_types,
		GL_VERTEX_SHADER,
		opts.vertex_shader_paths
	);

#ifdef GL_GEOMETRY_SHADER
	read_shader_source_texts(
		source_texts,
		shader_types,
		GL_GEOMETRY_SHADER,
		opts.geometry_shader_paths
	);
#endif

#ifdef GL_TESS_CONTROL_SHADER
	read_shader_source_texts(
		source_texts,
		shader_types,
		GL_TESS_CONTROL_SHADER,
		opts.tess_control_shader_paths
	);
#endif

#ifdef GL_TESS_EVALUATION_SHADER
	read_shader_source_texts(
		source_texts,
		shader_types,
		GL_TESS_EVALUATION_SHADER,
		opts.tess_evaluation_shader_paths
	);
#endif

	read_shader_source_texts(
		source_texts,
		shader_types,
		GL_FRAGMENT_SHADER,
		opts.fragment_shader_paths
	);

#ifdef GL_COMPUTE_SHADER
	read_shader_source_texts(
		source_texts,
		shader_types,
		GL_COMPUTE_SHADER,
		opts.compute_shader_paths
	);
#endif

	std::vector<std::size_t> slens;
	slens.reserve(source_texts.size());

	for(eagine::file_contents& source_text : source_texts)
	{
		slens.push_back(source_text.block().size());
	}

	std::size_t spos = 0;
	oglplus::program_source_header hdr;

	oglplus::write_and_pad_program_source_header(
		output,
		hdr,
		slens,
		spos
	);

	assert(shader_types.size() == source_texts.size());

	for(std::size_t i=0, n=shader_types.size(); i<n; ++i)
	{
		oglplus::shader_source_header shdr;
		shdr.shader_type = shader_types[i];
		oglplus::write_shader_source(output, shdr, source_texts[i]);
	}
}

int parse_options(int argc, const char** argv, options& opts);

int run(int argc, const char** argv)
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

int main(int argc, const char** argv)
{
	try { return run(argc, argv); }
	catch(std::exception& err)
	{
		std::cerr << "Error: " << err.what() << std::endl;
	}
	return 1;
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

