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

bool parse_next_arg(const eagine::program_arg& a, int& i)
{
	i = std::atoi(a.next().get().c_str());
	return (i != 0) || (a.next() == "0");
}

bool parse_next_arg(const eagine::program_arg& a, float& f)
{
	f = float(std::atof(a.next().get().c_str()));
	return (f != 0.f) || (a.next() == "0") || (a.next() == "0.0");
}

bool parse_next_arg(const eagine::program_arg& a, eagine::cstr_ref& s)
{
	s = a.next();
	return s.size() > 0;
}

template <typename T>
bool is_positive(T v)
{
	return v > T(0);
}

bool is_positive(const eagine::cstr_ref&)
{
	return true;
}

template <typename T>
bool parse_next_arg(const eagine::program_arg& a, T& v, bool only_positive)
{
	return parse_next_arg(a, v) && (!only_positive || is_positive(v));
}

template <typename T, typename Action, typename Errstr>
bool act_on_next_arg(
	eagine::program_arg& a,
	const char* value_type,
	Action action,
	Errstr& errstr,
	bool only_positive
)
{
	if(a.next())
	{
		T value = T();
		if(a.next().get().empty())
		{
			errstr()
				<< "Empty argument after '"
				<< a.get()
				<< "'."
				<< std::endl;
		}
		else if(!parse_next_arg(a, value, only_positive))
		{
			errstr()
				<< "Invalid "
				<< value_type
				<< " '"
				<< a.next().get()
				<< "' after '"
				<< a.get()
				<< "'."
				<< std::endl;
		}
		else
		{
			action(value);
			a = a.next();
			return true;
		}
	}
	else
	{
		errstr()
			<< "Missing "
			<< value_type
			<< " after '"
			<< a.get()
			<< "'."
			<< std::endl;
	}
	return false;
}

template <typename Action, typename Errstr>
bool act_on_next_str(
	eagine::program_arg& arg,
	const char* value_type,
	Action action,
	Errstr& errstr
)
{
	return act_on_next_arg<eagine::cstr_ref>(
		arg,
		value_type,
		action,
		errstr,
		false
	);
}

template <typename Action, typename Errstr>
bool act_on_next_int(
	eagine::program_arg& arg,
	Action action,
	Errstr& errstr,
	bool only_positive = false
)
{
	return act_on_next_arg<int>(
		arg,
		"integer value",
		action,
		errstr,
		only_positive
	);
}

template <typename Action, typename Errstr>
bool act_on_next_positive_int(
	eagine::program_arg& arg,
	Action action,
	Errstr& errstr
)
{
	return act_on_next_int(arg, action, errstr, true);
}

template <typename Action, typename Errstr>
bool act_on_next_float(
	eagine::program_arg& arg,
	Action action,
	Errstr& errstr,
	bool only_positive
)
{
	return act_on_next_arg<float>(
		arg,
		"floating-point value",
		action,
		errstr,
		only_positive
	);
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
			auto action = [&params](const cstr_ref& s)
			{
				params.screenshot_path(s);
			};
			if(!act_on_next_str(a, "path", action, errstr))
			{
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
			auto action = [&params](const cstr_ref& s)
			{
				params.framedump_prefix(s);
			};
			if(!act_on_next_str(a, "prefix", action, errstr))
			{
				return 1;
			}
		}
		else if(a == "--fixed-fps")
		{
			auto action = [&params](float f)
			{
				params.fixed_fps(f);
			};
			if(!act_on_next_float(a, action, errstr, true))
			{
				return 1;
			}
		}
		else if(a == "--window-x")
		{
			auto action = [&params](int i)
			{
				params.window_x_pos(i);
			};
			if(!act_on_next_int(a, action, errstr))
			{
				return 1;
			}
		}
		else if(a == "--window-y")
		{
			auto action = [&params](int i)
			{
				params.window_y_pos(i);
			};
			if(!act_on_next_int(a, action, errstr))
			{
				return 1;
			}
		}
		else if(a == "--width")
		{
			auto action = [&state](int i)
			{
				state.set_width(i);
			};
			if(!act_on_next_positive_int(a, action, errstr))
			{
				return 1;
			}
		}
		else if(a == "--height")
		{
			auto action = [&state](int i)
			{
				state.set_height(i);
			};
			if(!act_on_next_positive_int(a, action, errstr))
			{
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
			auto action = [&params](int i)
			{
				params.x_tiles(i);
			};
			if(!act_on_next_positive_int(a, action, errstr))
			{
				return 1;
			}
		}
		else if(a == "--y-tiles")
		{
			auto action = [&params](int i)
			{
				params.x_tiles(i);
			};
			if(!act_on_next_positive_int(a, action, errstr))
			{
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
