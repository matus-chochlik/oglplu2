/**
 *  @file oglplus/path_nv_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PATH_NV_NAME_1509260923_HPP
#define OGLPLUS_PATH_NV_NAME_1509260923_HPP

#ifndef GL_NV_path_rendering
#error NV_path_rendering API is not defined
#endif

#include <vector>
#include "object/gl_names.hpp"

namespace oglplus {
namespace tag {

using path_nv = gl_obj_tag<0xC357>;

} // namespace tag
} // namespace oglplus

namespace eagine {

template <std::size_t N>
class object_names<oglplus::tag::path_nv, std::array<GLuint, N>>
  : public object_name_fake_array<oglplus::tag::path_nv> {
public:
    object_names(void) noexcept
      : object_name_fake_array<oglplus::tag::path_nv>(span_size(N)) {
    }
};

template <>
class object_names<oglplus::tag::path_nv, std::vector<GLuint>>
  : public object_name_fake_array<oglplus::tag::path_nv> {
public:
    object_names(span_size_t n) noexcept
      : object_name_fake_array<oglplus::tag::path_nv>(n) {
    }
};

} // namespace eagine

namespace oglplus {

using path_nv_name = object_name<tag::path_nv>;

} // namespace oglplus

#endif // include guard
