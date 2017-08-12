/**
 *  @file oglplus/buffer.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>
#include <oglplus/oper/numeric_queries.hpp>

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include "enum/buffer_target_bq.inl"
#endif

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
bind_buffer(buffer_target target, buffer_name buf)
noexcept
{
	OGLPLUS_GLFUNC(BindBuffer)(
		GLenum(target),
		get_raw_name(buf)
	);
	OGLPLUS_VERIFY(
		BindBuffer,
		gl_enum_value(target).
		gl_object(buf),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<buffer_name>
buffer_ops::
buffer_binding(buffer_target target)
noexcept
{
	GLint result = 0;
	return numeric_queries::get_integer_v(
		get_binding_query(target),
		{&result, 1}
	).add(buffer_name(GLuint(result)));
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
bind_buffer_base(
	buffer_indexed_target target,
	GLuint index,
	buffer_name buf
) noexcept
{
	OGLPLUS_GLFUNC(BindBufferBase)(
		GLenum(target),
		index,
		get_raw_name(buf)
	);
	OGLPLUS_VERIFY(
		BindBufferBase,
		gl_enum_value(target).
		gl_index(index).
		gl_object(buf),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
get_buffer_parameter_iv(
	buffer_target tgt,
	oglplus::buffer_parameter param,
	span<GLint> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetBufferParameteriv)(
		GLenum(tgt),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetBufferParameteriv,
		gl_object_binding(tag::buffer(), tgt).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
get_buffer_parameter_i64v(
	buffer_target tgt,
	oglplus::buffer_parameter param,
	span<GLint64> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetBufferParameteri64v)(
		GLenum(tgt),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetBufferParameteri64v,
		gl_object_binding(tag::buffer(), tgt).
		gl_enum_value(param),
		always
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_NV_shader_buffer_load)
inline
outcome<void>
buffer_ops::
get_buffer_parameter_ui64v(
	buffer_target tgt,
	oglplus::buffer_parameter param,
	span<GLuint64> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetBufferParameterui64vNV)(
		GLenum(tgt),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetBufferParameterui64vNV,
		gl_object_binding(tag::buffer(), tgt).
		gl_enum_value(param),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
inline
outcome<void>
buffer_ops::
get_buffer_parameter_iv(
	buffer_name buf,
	oglplus::buffer_parameter param,
	span<GLint> values
) noexcept
{
	assert(values.size() > 0);
#ifdef GL_VERSION_4_5
	OGLPLUS_GLFUNC(GetNamedBufferParameteriv)(
#else
	OGLPLUS_GLFUNC(GetNamedBufferParameterivEXT)(
#endif
		get_raw_name(buf),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		OGLPLUS_GL_DSA_FUNC_NAME(GetNamedBufferParameteriv),
		gl_object(buf).
		gl_enum_value(param),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5)
inline
outcome<void>
buffer_ops::
get_buffer_parameter_i64v(
	buffer_name buf,
	oglplus::buffer_parameter param,
	span<GLint64> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetNamedBufferParameteri64v)(
		get_raw_name(buf),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetNamedBufferParameteri64v,
		gl_object(buf).
		gl_enum_value(param),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_NV_shader_buffer_load)
inline
outcome<void>
buffer_ops::
get_buffer_parameter_ui64v(
	buffer_name buf,
	oglplus::buffer_parameter param,
	span<GLuint64> values
) noexcept
{
	assert(values.size() > 0);
	OGLPLUS_GLFUNC(GetNamedBufferParameterui64vNV)(
		get_raw_name(buf),
		GLenum(param),
		values.data()
	);
	OGLPLUS_VERIFY(
		GetNamedBufferParameterui64vNV,
		gl_object(buf).
		gl_enum_value(param),
		always
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
template <typename R, typename T, typename BNT>
inline
outcome<R>
buffer_ops::
return_buffer_parameter_i(
	const BNT& bnt,
	oglplus::buffer_parameter parameter
) noexcept
{
	GLint result = 0;
	return get_buffer_parameter_iv(
		bnt,
		parameter,
		{&result, 1}
	).add(R(T(result)));
}
//------------------------------------------------------------------------------
template <typename BNT>
inline
outcome<GLint>
buffer_ops::
get_buffer_size(const BNT& bnt)
noexcept
{
	return return_buffer_parameter_i<GLint, GLint>(
		bnt,
		oglplus::buffer_parameter(GL_BUFFER_SIZE)
	);
}
//------------------------------------------------------------------------------
template <typename BNT>
inline
outcome<boolean>
buffer_ops::
is_buffer_mapped(const BNT& bnt)
noexcept
{
	return return_buffer_parameter_i<boolean, GLboolean>(
		bnt,
		oglplus::buffer_parameter(GL_BUFFER_MAPPED)
	);
}
//------------------------------------------------------------------------------
template <typename BNT>
inline
outcome<oglplus::buffer_usage>
buffer_ops::
get_buffer_usage(const BNT& bnt)
noexcept
{
	return return_buffer_parameter_i<
		oglplus::buffer_usage,
		GLboolean
	>(
		bnt,
		oglplus::buffer_parameter(GL_BUFFER_USAGE)
	);
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_4) || defined(GL_ARB_buffer_storage)
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
buffer_storage(
	buffer_target target,
	const buffer_data_spec& data,
	enum_bitfield<buffer_storage_bits> flags
) noexcept
{
	OGLPLUS_GLFUNC(BufferStorage)(
		GLenum(target),
		GLsizei(data.size()),
		data.data(),
		GLbitfield(flags)
	);
	OGLPLUS_VERIFY(
		BufferStorage,
		gl_object_binding(tag::buffer(), target),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
inline
outcome<void>
buffer_ops::
buffer_storage(
	buffer_name buf,
	const buffer_data_spec& data,
	enum_bitfield<buffer_storage_bits> flags
) noexcept
{
#ifdef GL_VERSION_4_5
	OGLPLUS_GLFUNC(NamedBufferStorage)(
#else
	OGLPLUS_GLFUNC(NamedBufferStorageEXT)(
#endif
		get_raw_name(buf),
		GLsizei(data.size()),
		data.data(),
		GLbitfield(flags)
	);
	OGLPLUS_VERIFY(
		OGLPLUS_GL_DSA_FUNC_NAME(NamedBufferStorage),
		gl_object(buf),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
template <typename BNT>
inline
outcome<boolean>
buffer_ops::
has_buffer_immutable_storage(const BNT& bnt)
noexcept
{
	return return_buffer_parameter_i<boolean, GLboolean>(
		bnt,
		oglplus::buffer_parameter(GL_BUFFER_IMMUTABLE_STORAGE)
	);
}
//------------------------------------------------------------------------------
template <typename BNT>
inline
outcome<enum_bitfield<buffer_storage_bits>>
buffer_ops::
get_buffer_storage_flags(const BNT& bnt)
noexcept
{
	return return_buffer_parameter_i<
		enum_bitfield<buffer_storage_bits>,
		GLbitfield
	>(
		bnt,
		oglplus::buffer_parameter(GL_BUFFER_STORAGE_FLAGS)
	);
}
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
buffer_data(
	buffer_target target,
	const buffer_data_spec& data,
	oglplus::buffer_usage usage
) noexcept
{
	OGLPLUS_GLFUNC(BufferData)(
		GLenum(target),
		GLsizei(data.size()),
		data.data(),
		GLenum(usage)
	);
	OGLPLUS_VERIFY(
		BufferData,
		gl_object_binding(tag::buffer(), target),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
inline
outcome<void>
buffer_ops::
buffer_data(
	buffer_name buf,
	const buffer_data_spec& data,
	oglplus::buffer_usage usage
) noexcept
{
#ifdef GL_VERSION_4_5
	OGLPLUS_GLFUNC(NamedBufferData)(
#else
	OGLPLUS_GLFUNC(NamedBufferDataEXT)(
#endif
		get_raw_name(buf),
		GLsizei(data.size()),
		data.data(),
		GLenum(usage)
	);

	OGLPLUS_VERIFY_STR(
		OGLPLUS_GL_DSA_FUNC_NAME(NamedBufferData),
		gl_object(buf),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
buffer_sub_data(
	buffer_target target,
	oglplus::buffer_size offset,
	const buffer_data_spec& data
) noexcept
{
	OGLPLUS_GLFUNC(BufferSubData)(
		GLenum(target),
		GLintptr(offset),
		GLsizei(data.size()),
		data.data()
	);
	OGLPLUS_VERIFY(
		BufferSubData,
		gl_enum_value(target),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
inline
outcome<void>
buffer_ops::
buffer_sub_data(
	buffer_name buf,
	oglplus::buffer_size offset,
	const buffer_data_spec& data
) noexcept
{
#ifdef GL_VERSION_4_5
	OGLPLUS_GLFUNC(NamedBufferSubData)(
#else
	OGLPLUS_GLFUNC(NamedBufferSubDataEXT)(
#endif
		get_raw_name(buf),
		GLintptr(offset),
		GLsizei(data.size()),
		data.data()
	);

	OGLPLUS_VERIFY_STR(
		OGLPLUS_GL_DSA_FUNC_NAME(NamedBufferSubData),
		gl_object(buf),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_1) || defined(GL_ARB_copy_buffer)
inline
outcome<void>
buffer_ops::
copy_buffer_sub_data(
	buffer_target read_target,
	buffer_target write_target,
	oglplus::buffer_size read_offset,
	oglplus::buffer_size write_offset,
	oglplus::buffer_size size
) noexcept
{
	OGLPLUS_GLFUNC(CopyBufferSubData)(
		GLenum(read_target),
		GLenum(write_target),
		GLintptr(read_offset),
		GLintptr(write_offset),
		GLsizei(size)
	);
	OGLPLUS_VERIFY(
		CopyBufferSubData,
		gl_enum_value(read_target),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
inline
outcome<void>
buffer_ops::
copy_buffer_sub_data(
	buffer_name read_buffer,
	buffer_name write_buffer,
	oglplus::buffer_size read_offset,
	oglplus::buffer_size write_offset,
	oglplus::buffer_size size
) noexcept
{
#ifdef GL_VERSION_4_5
	OGLPLUS_GLFUNC(CopyNamedBufferSubData)(
#else
	OGLPLUS_GLFUNC(NamedCopyBufferSubDataEXT)(
#endif
		get_raw_name(read_buffer),
		get_raw_name(write_buffer),
		GLintptr(read_offset),
		GLintptr(write_offset),
		GLsizei(size)
	);
	OGLPLUS_VERIFY_STR(
		OGLPLUS_GL_DSA_FUNC_NAME(CopyNamedBufferSubData),
		gl_object(read_buffer).
		gl_object(write_buffer),
		debug
	);
	return {};
}
#endif
#endif
//------------------------------------------------------------------------------
#if defined(GL_VERSION_4_3) || defined(GL_ARB_invalidate_subdata)
inline
outcome<void>
buffer_ops::
invalidate_buffer_data(buffer_name buf)
noexcept
{
	OGLPLUS_GLFUNC(InvalidateBufferData)(get_raw_name(buf));
	OGLPLUS_VERIFY(
		InvalidateBufferData,
		gl_object(buf),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
invalidate_buffer_sub_data(
	buffer_name buf,
	oglplus::buffer_size offset,
	oglplus::buffer_size size
) noexcept
{
	OGLPLUS_GLFUNC(InvalidateBufferSubData)(
		get_raw_name(buf),
		GLintptr(offset),
		GLsizeiptr(size)
	);
	OGLPLUS_VERIFY(
		InvalidateBufferSubData,
		gl_object(buf),
		debug
	);
	return {};
}
#endif
//------------------------------------------------------------------------------
#if defined(GL_NV_shader_buffer_load)
inline
outcome<void>
buffer_ops::
make_buffer_resident(buffer_target tgt, access_specifier access)
noexcept
{
	OGLPLUS_GLFUNC(MakeBufferResidentNV)(
		GLenum(tgt),
		GLenum(access)
	);
	OGLPLUS_VERIFY(
		MakeBufferResidentNV,
		gl_enum_value(access).
		gl_object_binding(tag::buffer(), tgt),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
make_buffer_resident(buffer_name buf, access_specifier access)
noexcept
{
	OGLPLUS_GLFUNC(MakeNamedBufferResidentNV)(
		get_raw_name(buf),
		GLenum(access)
	);
	OGLPLUS_VERIFY(
		MakeNamedBufferResidentNV,
		gl_enum_value(access).
		gl_object(buf),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
make_buffer_non_resident(buffer_target tgt)
noexcept
{
	OGLPLUS_GLFUNC(MakeBufferNonResidentNV)(GLenum(tgt));
	OGLPLUS_VERIFY(
		MakeBufferNonResidentNV,
		gl_object_binding(tag::buffer(), tgt),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<void>
buffer_ops::
make_buffer_non_resident(buffer_name buf)
noexcept
{
	OGLPLUS_GLFUNC(MakeNamedBufferNonResidentNV)(get_raw_name(buf));
	OGLPLUS_VERIFY(
		MakeNamedBufferNonResidentNV,
		gl_object(buf),
		debug
	);
	return {};
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
buffer_ops::
is_buffer_resident(buffer_target tgt)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsBufferResidentNV)(GLenum(tgt));
	OGLPLUS_VERIFY(
		IsBufferResidentNV,
		gl_object_binding(tag::buffer(), tgt),
		debug
	);
	return {boolean(res)};
}
//------------------------------------------------------------------------------
inline
outcome<boolean>
buffer_ops::
is_buffer_resident(buffer_name buf)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsNamedBufferResidentNV)(
		get_raw_name(buf)
	);
	OGLPLUS_VERIFY(
		IsNamedBufferResidentNV,
		gl_object(buf),
		debug
	);
	return {boolean(res)};
}
//------------------------------------------------------------------------------
inline
outcome<buffer_address>
buffer_ops::
get_buffer_gpu_address(buffer_target tgt)
noexcept
{
	GLuint64EXT result = 0;
	return get_buffer_parameter_ui64v(
		tgt,
		buffer_parameter(GL_BUFFER_GPU_ADDRESS_NV),
		{&result, 1}
	).add(buffer_address(result));
}
//------------------------------------------------------------------------------
inline
outcome<buffer_address>
buffer_ops::
get_buffer_gpu_address(buffer_name buf)
noexcept
{
	GLuint64EXT result = 0;
	return get_buffer_parameter_ui64v(
		buf,
		buffer_parameter(GL_BUFFER_GPU_ADDRESS_NV),
		{&result, 1}
	).add(buffer_address(result));
}
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
// obj_gen_del_ops::_gen
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::buffer>::
_gen(span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(GenBuffers)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(GenBuffers,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_delete
//------------------------------------------------------------------------------
inline
deferred_error_handler
obj_gen_del_ops<tag::buffer>::
_delete(span<GLuint> names)
noexcept
{
	OGLPLUS_GLFUNC(DeleteBuffers)(
		GLsizei(names.size()),
		names.data()
	);
	OGLPLUS_VERIFY_SIMPLE(DeleteBuffers,debug);
	return {};
}
//------------------------------------------------------------------------------
// obj_gen_del_ops::_is_a
//------------------------------------------------------------------------------
inline
outcome<boolean>
obj_gen_del_ops<tag::buffer>::
_is_a(GLuint name)
noexcept
{
	GLboolean res = OGLPLUS_GLFUNC(IsBuffer)(name);
	OGLPLUS_VERIFY_SIMPLE(IsBuffer,debug);
	return boolean(res);
}
//------------------------------------------------------------------------------
} // namespace oglplus

