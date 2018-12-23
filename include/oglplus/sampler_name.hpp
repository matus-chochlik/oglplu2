/**
 *  @file oglplus/sampler_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_SAMPLER_NAME_HPP
#define OGLPLUS_SAMPLER_NAME_HPP

#include "object/gl_name.hpp"

#ifndef GL_SAMPLER
#define GL_SAMPLER 0x82E6
#endif

namespace oglplus {
namespace tag {

using sampler = gl_obj_tag<GL_SAMPLER>;

} // namespace tag

using sampler_name = object_name<tag::sampler>;

} // namespace oglplus

#endif // OGLPLUS_SAMPLER_NAME_HPP
