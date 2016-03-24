/**
 *  .file oglplus/example/params.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "params.hpp"
#include <eagine/filesystem.hpp>
#include <fstream>

namespace oglplus {

example_params::
example_params(void)
noexcept
 : _rand_seed(0)
 , _screenshot_time(3)
 , _fixed_fps(30)
 , _x_pos(64)
 , _y_pos(64)
 , _x_tiles(1)
 , _y_tiles(1)
 , _samples(4)
 , _color_bits(8)
 , _alpha_bits(0)
 , _depth_bits(24)
 , _stencil_bits(0)
 , _compat_ctxt(false)
 , _debug_ctxt(true)
 , _auto_tiles(true)
 , _demo_mode(false)
{ }

bool
example_params::
is_readable_file(cstr_ref path) const
noexcept
{
	// TODO something more efficient?
	return std::ifstream(path.c_str()).good();
}

valid_if_not_empty<std::string>
example_params::
find_resource_file_path(cstr_ref res_group, cstr_ref res_name) const
noexcept
{
	using eagine::filesystem::string_path;

	string_path relpath;
	if(!res_group.empty())
	{
		relpath.push_back(res_group);
	}
	relpath = relpath + string_path(res_name);

	std::string result;

	std::string pathstr = relpath.str();
	if(is_readable_file(cstr_ref(pathstr)))
	{
		result = std::move(pathstr);
	}
	else
	{
		int trials = 10;
		string_path curdir(exec_command());
		do
		{
			curdir = curdir.parent_path();
			string_path respath = curdir+relpath;

			pathstr = respath.str();
			if(is_readable_file(cstr_ref(pathstr)))
			{
				result = std::move(pathstr);
				break;
			}
		} while((--trials > 0) && (!curdir.is_root_path()));
	}
	return {result};
}

} // namespace oglplus
