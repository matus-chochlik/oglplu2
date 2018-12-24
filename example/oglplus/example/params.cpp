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
#include <sstream>

namespace oglplus {

example_params::example_params() noexcept
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
  , _demo_mode(false) {
}

bool example_params::is_readable_file(string_view path) const noexcept {
    // TODO something more efficient?
    return std::ifstream(c_str(path)).good();
}

eagine::valid_if_not_empty<std::string> example_params::find_resource_file_path(
  string_view res_group, string_view res_name) const {
    using eagine::filesystem::string_path;

    string_path relpath;
    if(!res_group.empty()) {
        relpath.push_back(res_group);
    }
    relpath = relpath + string_path(res_name);

    std::string result;

    std::string pathstr = relpath.str();
    if(is_readable_file(string_view(pathstr))) {
        result = std::move(pathstr);
    } else {
        int trials = 10;
        string_path curdir(exec_command());
        do {
            curdir = curdir.parent_path();
            string_path respath = curdir + relpath;

            pathstr = respath.str();
            if(is_readable_file(string_view(pathstr))) {
                result = std::move(pathstr);
                break;
            }
        } while((--trials > 0) && (!curdir.is_root_path()));
    }
    return {result};
}

static inline string_view resource_type_to_desc(
  example_resource_type type) noexcept {
    switch(type) {
        case example_resource_type::texture_image:
            return string_view("texture image");
        case example_resource_type::shader_source:
            return string_view("shader source");
        case example_resource_type::program_source:
            return string_view("program source");
    }
    return string_view();
}
static inline string_view resource_type_to_group_name(
  example_resource_type type) noexcept {
    switch(type) {
        case example_resource_type::texture_image:
            return string_view("textures");
        case example_resource_type::shader_source:
            return string_view("shaders");
        case example_resource_type::program_source:
            return string_view("programs");
    }
    return string_view();
}

eagine::valid_if_not_empty<std::string> example_params::find_resource_file_path(
  example_resource_type type, string_view res_name) const {
    return find_resource_file_path(resource_type_to_group_name(type), res_name);
}

std::string example_params::get_resource_file_path(
  example_resource_type type, string_view res_name) const {
    auto path = find_resource_file_path(type, res_name);

    if(!path.is_valid()) {
        std::stringstream msg;
        msg << "Failed to find the path of " << resource_type_to_desc(type)
            << " file '" << res_name << "'";
        throw std::runtime_error(msg.str());
    }

    return path.value();
}

} // namespace oglplus
