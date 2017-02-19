/*
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEST_OGLPLUS_HELPER_MOCK_OBJECT_HPP
#define TEST_OGLPLUS_HELPER_MOCK_OBJECT_HPP

#include <oglplus/object/gl_name.hpp>

namespace oglplus {
namespace tag {

using mock_object = gl_obj_tag<GL_TEXTURE>;

} // namespace tag

using mock_object_name = object_name<tag::mock_object>;

} // namespace oglplus

#endif // include guard
