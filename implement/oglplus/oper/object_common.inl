/**
 *  @file oglplus/oper/object_common.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_3)
template <GLenum ObjectType>
inline
outcome<void>
object_common_ops::
object_label(
	object_name<oglplus::tag::gl_obj_tag<ObjectType>> obj,
	cstring_span label
) noexcept {
	OGLPLUS_GLFUNC(ObjectLabel)(
		ObjectType,
		get_raw_name(obj),
		GLsizei(label.size()),
		(label.empty()?nullptr:label.data())
	);
	OGLPLUS_VERIFY(
		ObjectLabel,
		gl_object(obj),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
object_common_ops::
object_label(
	const sync_object& sync,
	cstring_span label
) noexcept {
	OGLPLUS_GLFUNC(ObjectPtrLabel)(
		const_cast<GLsync*>(&get_raw_handle(sync)),
		GLsizei(label.size()),
		(label.empty()?nullptr:label.data())
	);
	OGLPLUS_VERIFY_SIMPLE(ObjectPtrLabel, debug);
	return {};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
