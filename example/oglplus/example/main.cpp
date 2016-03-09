/**
 *  .file oglplus/example/main.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <oglplus/gl_fixed.hpp>
#include <oglplus/constants.hpp>
#include <oglplus/constant_defs.hpp>
#include "../example.hpp"
#include "state.hpp"

#include <oglplus/error/error.hpp>
#include <oglplus/error/format.hpp>
#include <oglplus/utils/cstr_ref.hpp>
#include <eagine/program_args.hpp>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

int example_main(
	oglplus::example_args&,
	oglplus::example_params&,
	oglplus::example_state&
);

template <typename T, typename Errstr>
bool consume_next_arg(
	eagine::program_arg& a,
	T& dest,
	const char* value_type,
	Errstr& errstr
)
{
	auto handle_missing =
	[&value_type,&errstr](const eagine::cstr_ref& arg_tag)
	{
		errstr()
			<< "Missing "
			<< value_type
			<< " after '"
			<< arg_tag
			<< "'."
			<< std::endl;
	};
	auto handle_invalid =
	[&value_type,&errstr](
		const eagine::cstr_ref& arg_tag,
		const eagine::cstr_ref& arg_val,
		const eagine::cstr_ref& log_str
	)
	{
		errstr()
			<< "Invalid "
			<< value_type
			<< " '"
			<< arg_val
			<< "' after '"
			<< arg_tag
			<< "'. "
			<< log_str
			<< std::endl;
	};
	return a.do_consume_next(dest, handle_missing, handle_invalid);
}

bool example_knows_arg(const eagine::program_arg& arg)
{
	using namespace oglplus;
	return is_example_param(example_arg(arg)) ||
		is_example_param(example_arg(arg.prev()));
}

int main(int argc, const char** argv)
{
	eagine::program_args args(argc, argv);

	using namespace oglplus;

	example_params params;
	example_state state;

	oglplus::adjust_params(params);

	state.set_size(800, 600);

	auto errstr = [&args](void) -> std::ostream&
	{
		return std::cerr
			<< args.command()
			<< ": ";
	};

	params.executable_path(args.command());

	for(auto a = args.first(); a; a = a.next())
	{
		if(a == "--screenshot")
		{
			if(params.doing_framedump())
			{
				errstr()
				<< "Cannot specify --screenshot "
				<< "together with --framedump."
				<< std::endl;
				return 1;
			}
			valid_if_not_empty<cstr_ref> path;
			if(consume_next_arg(a, path, "path", errstr))
			{
				params.screenshot_path(path);
			}
			else return 1;
		}
		else if(a == "--framedump")
		{
			if(params.doing_screenshot())
			{
				errstr()
				<< "Cannot specify --framedump"
				<< "together with --screenshot ."
				<< std::endl;
				return 1;
			}
			valid_if_not_empty<cstr_ref> prefix;
			if(consume_next_arg(a, prefix, "prefix", errstr))
			{
				params.framedump_prefix(prefix);
			}
			else return 1;
		}
		else if(a == "--fixed-fps")
		{
			valid_if_positive<float> fps;
			if(consume_next_arg(a, fps, "float", errstr))
			{
				params.fixed_fps(fps);
			}
			else return 1;
		}
		else if(a == "--window-x")
		{
			int x;
			if(consume_next_arg(a, x, "integer", errstr))
			{
				params.window_x_pos(x);
			}
			else return 1;
		}
		else if(a == "--window-y")
		{
			int y;
			if(consume_next_arg(a, y, "integer", errstr))
			{
				params.window_y_pos(y);
			}
			else return 1;
		}
		else if(a == "--width")
		{
			valid_if_positive<int> w;
			if(consume_next_arg(a, w, "integer", errstr))
			{
				state.set_width(w);
			}
			else return 1;
		}
		else if(a == "--height")
		{
			valid_if_positive<int> h;
			if(consume_next_arg(a, h, "integer", errstr))
			{
				state.set_height(h);
			}
			else return 1;
		}
		else if(a == "--hd")
		{
			state.set_size(1280, 720);
		}
		else if(a == "--full-hd")
		{
			state.set_size(1920, 1080);
		}
		else if(a == "--x-tiles")
		{
			valid_if_positive<int> x;
			if(consume_next_arg(a, x, "integer", errstr))
			{
				params.x_tiles(x);
			}
			else return 1;
		}
		else if(a == "--y-tiles")
		{
			valid_if_positive<int> y;
			if(consume_next_arg(a, y, "integer", errstr))
			{
				params.y_tiles(y);
			}
			else return 1;
		}
		else if(a == "--demo")
		{
			params.demo_mode(true);
		}
		else if(!example_knows_arg(a))
		{
			errstr()
			<< "Unknown command-line option '"
			<< a.get()
			<< "'."
			<< std::endl;
			return 1;
		}
	}

	state.set_tiles(params.x_tiles(), params.y_tiles());

	try
	{
		example_args eargs(args, std::cerr);
		return example_main(eargs, params, state);
	}
	catch(oglplus::error& gle)
	{
		oglplus::format_error(
			gle,
			"OpenGL error\n"
			"in GL function: %(gl_function_name)\n"
			"with object: %(gl_object)\n"
			"with enum parameter: %(gl_enum_value)\n"
			"with index: %(gl_index)\n"
			"from source file: %(source_file)\n"
			"%(message)\n"
			"%(info_log)\n",
			std::cerr
		) << std::endl;
	}
	catch(std::runtime_error& sre)
	{
		std::cerr
			<< "Runtime error: "
			<< sre.what()
			<< std::endl;
	}
	catch(std::exception& se)
	{
		std::cerr
			<< "Unknown error: "
			<< se.what()
			<< std::endl;
	}
	return 1;
}
