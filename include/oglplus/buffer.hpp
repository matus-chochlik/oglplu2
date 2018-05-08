/**
 *  @file oglplus/buffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_BUFFER_1509260923_HPP
#define OGLPLUS_BUFFER_1509260923_HPP

#include "buffer_address.hpp"
#include "buffer_name.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"
#include "object/owner.hpp"
#include "utils/boolean.hpp"
#include "utils/buffer_data.hpp"
#include "utils/buffer_size.hpp"
#include "utils/gl_func.hpp"

#if defined(GL_VERSION_4_5) || defined(GL_ARB_direct_state_access) \
  || defined(GL_EXT_direct_state_access)
#define OGLPLUS_DSA_BUFFER 1
#endif

namespace oglplus {

binding_query
get_binding_query(buffer_target tgt) noexcept;

namespace oper {

struct buffer_ops {
    static outcome<void> bind_buffer(
      buffer_target target, buffer_name buf) noexcept;

    static outcome<buffer_name> buffer_binding(buffer_target target) noexcept;

    static outcome<void> bind_buffer_base(
      buffer_indexed_target target, GLuint index, buffer_name buf) noexcept;

    static outcome<void> bind_buffer_range(buffer_indexed_target target,
      GLuint index,
      buffer_name buf,
      oglplus::buffer_size offset,
      oglplus::buffer_size size) noexcept;

#if defined(GL_VERSION_4_4)
    template <typename S>
    static outcome<void> bind_buffers_base(buffer_indexed_target target,
      GLuint first,
      const object_names<tag::buffer, S>& buffers) noexcept;
#endif

    static outcome<void> get_buffer_parameter_iv(buffer_target tgt,
      oglplus::buffer_parameter param,
      span<GLint> values) noexcept;

    static outcome<void> get_buffer_parameter_i64v(buffer_target tgt,
      oglplus::buffer_parameter param,
      span<GLint64> values) noexcept;

#if defined(GL_NV_shader_buffer_load)
    static outcome<void> get_buffer_parameter_ui64v(buffer_target tgt,
      oglplus::buffer_parameter param,
      span<GLuint64> values) noexcept;
#endif

#if defined(OGLPLUS_DSA_BUFFER)
    static outcome<void> get_buffer_parameter_iv(buffer_name buf,
      oglplus::buffer_parameter param,
      span<GLint> values) noexcept;
#endif

#if defined(GL_VERSION_4_5)
    static outcome<void> get_buffer_parameter_i64v(buffer_name buf,
      oglplus::buffer_parameter param,
      span<GLint64> values) noexcept;
#endif

#if defined(GL_NV_shader_buffer_load)
    static outcome<void> get_buffer_parameter_ui64v(buffer_name buf,
      oglplus::buffer_parameter param,
      span<GLuint64> values) noexcept;
#endif

    template <typename R, typename T, typename BNT>
    static outcome<R> return_buffer_parameter_i(
      const BNT& bnt, buffer_parameter parameter) noexcept;

    template <typename BNT>
    static outcome<GLint> get_buffer_size(const BNT& bnt) noexcept;

    template <typename BNT>
    static outcome<boolean> is_buffer_mapped(const BNT& bnt) noexcept;

    template <typename BNT>
    static outcome<oglplus::buffer_usage> get_buffer_usage(
      const BNT& bnt) noexcept;

#if defined(GL_VERSION_4_4) || defined(GL_ARB_buffer_storage)
    static outcome<void> buffer_storage(buffer_target target,
      const buffer_data_spec& data,
      enum_bitfield<buffer_storage_bits> flags) noexcept;

#if defined(OGLPLUS_DSA_BUFFER)
    static outcome<void> buffer_storage(buffer_name buf,
      const buffer_data_spec& data,
      enum_bitfield<buffer_storage_bits> flags) noexcept;
#endif

    template <typename BNT>
    static outcome<boolean> has_buffer_immutable_storage(
      const BNT& bnt) noexcept;

    template <typename BNT>
    static outcome<enum_bitfield<buffer_storage_bits>> get_buffer_storage_flags(
      const BNT& bnt) noexcept;
#endif

    static outcome<void> buffer_data(buffer_target target,
      const buffer_data_spec& data,
      oglplus::buffer_usage usage) noexcept;

#if defined(OGLPLUS_DSA_BUFFER)
    static outcome<void> buffer_data(buffer_name buf,
      const buffer_data_spec& data,
      oglplus::buffer_usage usage) noexcept;
#endif

    static outcome<void> buffer_sub_data(buffer_target target,
      oglplus::buffer_size offset,
      const buffer_data_spec& data) noexcept;

#if defined(OGLPLUS_DSA_BUFFER)
    static outcome<void> buffer_sub_data(buffer_name buf,
      oglplus::buffer_size offset,
      const buffer_data_spec& data) noexcept;
#endif

#if defined(GL_VERSION_3_1) || defined(GL_ARB_copy_buffer)
    static outcome<void> copy_buffer_sub_data(buffer_target read_target,
      buffer_target write_target,
      oglplus::buffer_size read_offset,
      oglplus::buffer_size write_offset,
      oglplus::buffer_size size) noexcept;

#if defined(OGLPLUS_DSA_BUFFER)
    static outcome<void> copy_buffer_sub_data(buffer_name read_buffer,
      buffer_name write_buffer,
      oglplus::buffer_size read_offset,
      oglplus::buffer_size write_offset,
      oglplus::buffer_size size) noexcept;
#endif
#endif

#if defined(GL_VERSION_4_3)
    static outcome<void> clear_buffer_data(buffer_target tgt,
      pixel_data_internal_format internal_format,
      pixel_data_format format,
      pixel_data_type type,
      const buffer_data_spec& data) noexcept;

    static outcome<void> clear_buffer_sub_data(buffer_target tgt,
      pixel_data_internal_format internal_format,
      oglplus::buffer_size offset,
      pixel_data_format format,
      pixel_data_type type,
      const buffer_data_spec& data) noexcept;
#endif // GL_VERSION_4_3

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
    static outcome<void> clear_buffer_data(buffer_name buf,
      pixel_data_internal_format internal_format,
      pixel_data_format format,
      pixel_data_type type,
      const buffer_data_spec& data) noexcept;

    static outcome<void> clear_buffer_sub_data(buffer_name buf,
      pixel_data_internal_format internal_format,
      oglplus::buffer_size offset,
      pixel_data_format format,
      pixel_data_type type,
      const buffer_data_spec& data) noexcept;
#endif // GL_VERSION_4_5

#if defined(GL_VERSION_4_3) || defined(GL_ARB_invalidate_subdata)
    static outcome<void> invalidate_buffer_data(buffer_name buf) noexcept;

    static outcome<void> invalidate_buffer_sub_data(buffer_name buf,
      oglplus::buffer_size offset,
      oglplus::buffer_size size) noexcept;
#endif

#if defined(GL_NV_shader_buffer_load)
    static outcome<void> make_buffer_resident(
      buffer_target tgt, access_specifier access) noexcept;

    static outcome<void> make_buffer_resident(
      buffer_name buf, access_specifier access) noexcept;

    static outcome<void> make_buffer_non_resident(buffer_target tgt) noexcept;

    static outcome<void> make_buffer_non_resident(buffer_name buf) noexcept;

    static outcome<boolean> is_buffer_resident(buffer_target tgt) noexcept;

    static outcome<boolean> is_buffer_resident(buffer_name buf) noexcept;

    static outcome<buffer_address> get_buffer_gpu_address(
      buffer_target tgt) noexcept;

    static outcome<buffer_address> get_buffer_gpu_address(
      buffer_name buf) noexcept;
#endif
};

} // namespace oper

template <typename Derived, typename Base>
struct obj_member_ops<tag::buffer, Derived, Base> : Base {
private:
    Derived& _self() noexcept {
	return *static_cast<Derived*>(this);
    }

    typedef oper::buffer_ops _ops;

protected:
    using Base::Base;

public:
    outcome<Derived&> data(
      const buffer_data_spec& data, buffer_usage usage) noexcept {
	return {_ops::buffer_data(*this, data, usage), _self()};
    }

    outcome<Derived&> sub_data(
      buffer_size offset, const buffer_data_spec& data) noexcept {
	return {_ops::buffer_sub_data(*this, offset, data), _self()};
    }

#if defined(GL_VERSION_4_5) || defined(GL_EXT_direct_state_access)
    outcome<Derived&> clear_data(pixel_data_internal_format internal_format,
      pixel_data_format format,
      pixel_data_type type,
      const buffer_data_spec& data) noexcept {
	return {
	  _ops::clear_buffer_data(*this, internal_format, format, type, data),
	  _self()};
    }

    outcome<Derived&> clear_sub_data(pixel_data_internal_format internal_format,
      oglplus::buffer_size offset,
      pixel_data_format format,
      pixel_data_type type,
      const buffer_data_spec& data) noexcept {
	return {_ops::clear_buffer_sub_data(
		  *this, internal_format, offset, format, type, data),
	  _self()};
    }
#endif // GL_VERSION_4_5

#if defined(GL_VERSION_4_3) || defined(GL_ARB_invalidate_subdata)
    outcome<Derived&> invalidate_data(void) noexcept {
	return {_ops::invalidate_buffer_data(*this), _self()};
    }

    outcome<Derived&> invalidate_sub_data(
      buffer_size offset, buffer_size size) noexcept {
	return {_ops::invalidate_buffer_sub_data(*this, offset, size), _self()};
    }
#endif

    outcome<GLint> get_size(void) const noexcept {
	return _ops::get_buffer_size(*this);
    }

    outcome<boolean> is_mapped(void) const noexcept {
	return _ops::is_buffer_mapped(*this);
    }

    outcome<buffer_usage> get_usage(void) const noexcept {
	return _ops::get_buffer_usage(*this);
    }

#if defined(GL_VERSION_4_4) || defined(GL_ARB_buffer_storage)
    outcome<Derived&> storage(const buffer_data_spec& data,
      enum_bitfield<buffer_storage_bits> flags) noexcept {
	return {_ops::buffer_storage(*this, data, flags), _self()};
    }

    outcome<boolean> has_immutable_storage(void) const noexcept {
	return _ops::has_buffer_immutable_storage(*this);
    }

    outcome<enum_bitfield<buffer_storage_bits>> get_storage_flags(void) const
      noexcept {
	return _ops::get_buffer_storage_flags(*this);
    }
#endif

#if defined(GL_NV_shader_buffer_load)
    outcome<void> make_resident(access_specifier access) noexcept {
	return _ops::make_buffer_resident(*this, access);
    }

    outcome<void> make_non_resident(void) noexcept {
	return _ops::make_buffer_non_resident(*this);
    }

    outcome<boolean> is_resident(void) const noexcept {
	return _ops::is_buffer_resident(*this);
    }

    outcome<buffer_address> get_gpu_address(void) const noexcept {
	return _ops::get_buffer_gpu_address(*this);
    }
#endif
};

template <>
struct object_binding<tag::buffer>
  : obj_member_ops<tag::buffer, object_binding<tag::buffer>, buffer_target> {
    using obj_member_ops<tag::buffer,
      object_binding<tag::buffer>,
      buffer_target>::obj_member_ops;
};

#if defined(OGLPLUS_DSA_BUFFER)
template <>
struct obj_dsa_ops<tag::buffer>
  : obj_member_ops<tag::buffer,
      obj_dsa_ops<tag::buffer>,
      obj_zero_dsa_ops<tag::buffer>> {
    using obj_member_ops<tag::buffer,
      obj_dsa_ops<tag::buffer>,
      obj_zero_dsa_ops<tag::buffer>>::obj_member_ops;
};
#endif

template <>
struct obj_gen_del_ops<tag::buffer> {
    static deferred_error_handler _gen(span<GLuint> names) noexcept;

#if defined(GL_VERSION_4_5)
    static deferred_error_handler _create(span<GLuint> names) noexcept;
#endif

    static deferred_error_handler _delete(span<GLuint> names) noexcept;

    static outcome<boolean> _is_a(GLuint name) noexcept;
};

using buffer = object_owner<tag::buffer>;
using bound_buffer = object_binding<tag::buffer>;
template <std::size_t N>
using buffer_array = object_array_owner<tag::buffer, N>;

static const object_zero_and_ops<tag::buffer> no_buffer = {};

} // namespace oglplus

#include <oglplus/buffer.inl>

#ifdef OGLPLUS_DSA_BUFFER
#undef OGLPLUS_DSA_BUFFER
#endif

#endif // include guard
