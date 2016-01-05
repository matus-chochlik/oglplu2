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
	const eagine::program_args&,
	oglplus::example_params&,
	oglplus::example_state&
);

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
			if(a.next())
			{
				if(a.next().get().empty())
				{
					errstr()
					<< "Empty path after '--screenshot'."
					<< std::endl;
					return 1;
				}
				else
				{
					params.screenshot_path(a.next());
					a = a.next();
				}
			}
			else
			{
				errstr()
				<< "Missing path after '--screenshot'."
				<< std::endl;
				return 1;
			}
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
			if(a.next())
			{
				if(a.next().get().empty())
				{
					errstr()
					<< "Empty prefix after '--framedump'."
					<< std::endl;
					return 1;
				}
				else
				{
					params.framedump_prefix(a.next());
					a = a.next();
				}
			}
			else
			{
				errstr()
				<< "Missing prefix after '--framedump'."
				<< std::endl;
				return 1;
			}
		}
		else if(a == "--fixed-fps")
		{
			if(a.next())
			{
				int fps = std::atoi(a.next().get().c_str());
				if(fps < 1)
				{
					errstr()
					<< "Invalid value '"
					<< a.next().get()
					<< "' after --fixed-fps."
					<< std::endl;
					return 1;
				}
				params.fixed_fps(fps);
				a = a.next();
			}
			else 
			{
				errstr()
				<< "Missing number after '--fixed-fps'."
				<< std::endl;
				return 1;
			}
		}
		else if(a == "--width")
		{
			if(a.next())
			{
				int width = std::atoi(a.next().get().c_str());
				if(width < 1)
				{
					errstr()
					<< "Invalid value '"
					<< a.next().get()
					<< "' after --width."
					<< std::endl;
					return 1;
				}
				state.set_width(width);
				a = a.next();
			}
			else 
			{
				errstr()
				<< "Missing number after '--width'."
				<< std::endl;
				return 1;
			}
		}
		else if(a == "--height")
		{
			if(a.next())
			{
				int height = std::atoi(a.next().get().c_str());
				if(height < 1)
				{
					errstr()
					<< "Invalid value '"
					<< a.next().get()
					<< "' after --height."
					<< std::endl;
					return 1;
				}
				state.set_height(height);
				a = a.next();
			}
			else 
			{
				errstr()
				<< "Missing number after '--height'."
				<< std::endl;
				return 1;
			}
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
			if(a.next())
			{
				int x_tiles = std::atoi(a.next().get().c_str());
				if(x_tiles < 1)
				{
					errstr()
					<< "Invalid value '"
					<< a.next().get()
					<< "' after --x-tiles."
					<< std::endl;
					return 1;
				}
				params.x_tiles(x_tiles);
				a = a.next();
			}
			else 
			{
				errstr()
				<< "Missing number after '--x-tiles'."
				<< std::endl;
				return 1;
			}
		}
		else if(a == "--y-tiles")
		{
			if(a.next())
			{
				int y_tiles = std::atoi(a.next().get().c_str());
				if(y_tiles < 1)
				{
					errstr()
					<< "Invalid value '"
					<< a.next().get()
					<< "' after --y-tiles."
					<< std::endl;
					return 1;
				}
				params.y_tiles(y_tiles);
				a = a.next();
			}
			else 
			{
				errstr()
				<< "Missing number after '--y-tiles'."
				<< std::endl;
				return 1;
			}
		}
		else
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

	try { return example_main(args, params, state); }
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
			"%(message)\n",
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
