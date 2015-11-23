/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEST_OALPLUS_HELPER_MOCK_OBJECT_HPP
#define TEST_OALPLUS_HELPER_MOCK_OBJECT_HPP

#include <oalplus/object/gl_name.hpp>

namespace oalplus {
namespace tag {

using mock_object = gl_obj_tag<AL_BUFFER>;

} // namespace tag

using mock_object_name = object_name<tag::mock_object>;

} // namespace oalplus

#endif // include guard
