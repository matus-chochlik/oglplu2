/**
 *  @file oalplus/object/al_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_OBJECT_AL_TRAITS_1509260923_HPP
#define OALPLUS_OBJECT_AL_TRAITS_1509260923_HPP

#include "fwd.hpp"

namespace oalplus {
namespace tag {

template <ALenum Tag>
struct al_obj_tag;

} // namespace tag

template <typename ObjTag>
struct obj_dsa_ops : object_name<ObjTag> {
    obj_dsa_ops() = default;

    obj_dsa_ops(object_name<ObjTag> name) noexcept
      : object_name<ObjTag>(name) {
    }
};

} // namespace oalplus

namespace eagine {

template <ALenum Tag>
struct object_traits<oalplus::tag::al_obj_tag<Tag>> {
    using name_type = ALuint;
    using tag = oalplus::tag::al_obj_tag<Tag>;

    using gen_del_ops = oalplus::obj_gen_del_ops<tag>;

    template <typename ObjTag>
    using dsa_ops_t = oalplus::obj_dsa_ops<ObjTag>;

    static inline constexpr ALuint invalid_name() noexcept {
        return ~ALuint(0);
    }

    static inline constexpr ALenum get_type() noexcept {
        return Tag;
    }
};

} // namespace eagine

#endif // include guard
