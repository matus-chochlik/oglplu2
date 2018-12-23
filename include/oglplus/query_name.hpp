/**
 *  @file oglplus/query_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_QUERY_NAME_HPP
#define OGLPLUS_QUERY_NAME_HPP

#include "object/gl_name.hpp"

#ifndef GL_QUERY
#define GL_QUERY 0x82E3
#endif

namespace oglplus {
namespace tag {

using query = gl_obj_tag<GL_QUERY>;

} // namespace tag

using query_name = object_name<tag::query>;

} // namespace oglplus

#endif // OGLPLUS_QUERY_NAME_HPP
