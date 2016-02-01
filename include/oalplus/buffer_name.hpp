/**
 *  @file oalplus/buffer_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_BUFFER_NAME_1509260923_HPP
#define OALPLUS_BUFFER_NAME_1509260923_HPP

#include "object/al_name.hpp"

namespace oalplus {
namespace tag {

using buffer = al_obj_tag<AL_BUFFER>;

} // namespace tag

using buffer_name = object_name<tag::buffer>;

} // namespace oalplus

#endif // include guard
