/**
 *  @file oglplus/program_pipeline_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PROGRAM_PIPELINE_NAME_HPP
#define OGLPLUS_PROGRAM_PIPELINE_NAME_HPP

#include "object/gl_name.hpp"

#ifndef GL_PROGRAM_PIPELINE
#define GL_PROGRAM_PIPELINE 0x82E4
#endif

namespace oglplus {
namespace tag {

using program_pipeline = gl_obj_tag<GL_PROGRAM_PIPELINE>;

} // namespace tag

using program_pipeline_name = object_name<tag::program_pipeline>;

} // namespace oglplus

#endif // OGLPLUS_PROGRAM_PIPELINE_NAME_HPP
