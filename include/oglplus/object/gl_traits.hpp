/**
 *  @file oglplus/object/gl_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_GL_TRAITS_1509260923_HPP
#define OGLPLUS_OBJECT_GL_TRAITS_1509260923_HPP

#include "fwd.hpp"

namespace oglplus {
namespace tag {

template <GLenum Tag>
struct gl_obj_tag {};

} // namespace tag

template <typename ObjTag>
struct obj_zero_dsa_ops : object_zero_name<ObjTag> {
    obj_zero_dsa_ops() = default;

    obj_zero_dsa_ops(object_name<ObjTag> name) noexcept
      : object_zero_name<ObjTag>(name) {
    }
};

template <typename ObjTag>
struct obj_dsa_ops : obj_zero_dsa_ops<ObjTag> {
    obj_dsa_ops() = default;

    obj_dsa_ops(object_name<ObjTag> name) noexcept
      : obj_zero_dsa_ops<ObjTag>(name) {
    }
};

template <typename Tag>
struct gl_object_traits {
    using tag = Tag;

    using name_type = GLuint;

    using gen_del_ops = obj_gen_del_ops<tag>;

    template <typename ObjTag>
    using zero_dsa_ops_t = obj_zero_dsa_ops<ObjTag>;

    template <typename ObjTag>
    using dsa_ops_t = obj_dsa_ops<ObjTag>;

    static inline constexpr GLuint invalid_name() noexcept {
        return ~GLuint(0);
    }
};

} // namespace oglplus

namespace eagine {

template <GLenum Tag>
struct object_traits<oglplus::tag::gl_obj_tag<Tag>>
  : oglplus::gl_object_traits<oglplus::tag::gl_obj_tag<Tag>> {
    static inline constexpr GLenum get_type() noexcept {
        return Tag;
    }
};

} // namespace eagine

#endif // include guard
