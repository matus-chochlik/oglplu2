/**
 *  @file oglplus/object/name_or_target.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_NAME_OR_TARGET_HPP
#define OGLPLUS_OBJECT_NAME_OR_TARGET_HPP

#include "../utils/nothing.hpp"
#include "gl_name.hpp"

namespace oglplus {

template <typename Name, typename Target>
struct object_name_or_target;

template <typename Name, typename Target>
static constexpr inline object_name_or_target<Name, Target>
wrap_object_name_or_target(object_name_or_target<Name, Target> ont) noexcept {
    return ont;
}

template <typename ObjBindingPoint>
struct object_name_or_target<nothing_t, ObjBindingPoint> {
    ObjBindingPoint _target;

    template <
      typename Target,
      typename =
        std::enable_if_t<std::is_convertible_v<Target, ObjBindingPoint>>>
    constexpr inline object_name_or_target(Target target) noexcept
      : _target(target) {
    }
};

template <typename ObjTag>
using object_target_only =
  object_name_or_target<nothing_t, obj_binding_point<ObjTag>>;

template <typename ObjTag>
struct object_name_or_target<object_name<ObjTag>, nothing_t> {
    object_name<ObjTag> _name;

    constexpr inline object_name_or_target(object_name<ObjTag> name) noexcept
      : _name(std::move(name)) {
    }
};

template <typename ObjTag>
using object_name_only = object_name_or_target<object_name<ObjTag>, nothing_t>;

template <typename ObjTag>
struct object_name_or_target<object_name<ObjTag>, obj_binding_point<ObjTag>> {
    object_name<ObjTag> _name;
    obj_binding_point<ObjTag> _target;

    constexpr inline object_name_or_target(
      object_name<ObjTag> name, obj_binding_point<ObjTag> target) noexcept
      : _name(name)
      , _target(target) {
    }
};
template <typename ObjTag>
using object_name_and_target =
  object_name_or_target<object_name<ObjTag>, obj_binding_point<ObjTag>>;

} // namespace oglplus

#endif // OGLPLUS_OBJECT_NAME_OR_TARGET_HPP
