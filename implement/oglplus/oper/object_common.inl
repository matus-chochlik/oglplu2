/**
 *  @file oglplus/oper/object_common.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/range_algo.hpp>
#include <oglplus/utils/gl_func.hpp>
#include <oglplus/oper/numeric_queries.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_3)
inline
outcome<GLsizei>
object_common_ops::
get_max_label_length(void)
noexcept {
	return GLsizei(numeric_queries::get_integer(
		numeric_query(GL_MAX_LABEL_LENGTH)
	));
}
//------------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
template <GLenum ObjectType>
inline
outcome<cstring_span>
object_common_ops::
get_object_label(
	object_name<oglplus::tag::gl_obj_tag<ObjectType>> obj,
	string_span storage
) noexcept {
	GLsizei realLen = 0;
	OGLPLUS_GLFUNC(GetObjectLabel)(
		ObjectType,
		get_raw_name(obj),
		GLsizei(storage.size()),
		&realLen,
		storage.data()
	);
	OGLPLUS_VERIFY(
		GetObjectLabel,
		gl_object(obj),
		debug
	);
	return {eagine::ranges::head(storage, realLen)};
}
//------------------------------------------------------------------------------
inline
outcome<cstring_span>
object_common_ops::
get_object_label(
	const sync_object& sync,
	string_span storage
) noexcept {
	GLsizei realLen = 0;
	OGLPLUS_GLFUNC(GetObjectPtrLabel)(
		const_cast<GLsync*>(&get_raw_handle(sync)),
		GLsizei(storage.size()),
		&realLen,
		storage.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GetObjectPtrLabel, debug);
	return {eagine::ranges::head(storage, realLen)};
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
