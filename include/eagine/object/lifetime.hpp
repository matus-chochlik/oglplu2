/**
 *  @file eagine/object/lifetime.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OBJECT_LIFETIME_1509260923_HPP
#define EAGINE_OBJECT_LIFETIME_1509260923_HPP

#include "fwd.hpp"

namespace eagine {

template <typename ObjTag>
struct obj_lifetime_ops {
    typedef typename object_traits<ObjTag>::gen_del_ops gen_del_ops;

    template <typename Storage>
    static inline auto
    gen_objects(owned<object_names<ObjTag, Storage>>& names) noexcept {
        return gen_del_ops::_gen(get_raw_names(names));
    }

    static inline auto
    gen_objects(owned<object_name_and_ops<ObjTag>>& name) noexcept {
        return gen_del_ops::_gen(get_raw_names(name));
    }

    template <typename Storage, typename Param>
    static inline auto gen_objects(
      owned<object_names<ObjTag, Storage>>& names, Param param) noexcept {
        return gen_del_ops::_gen(get_raw_names(names), param);
    }

    template <typename Param>
    static inline auto gen_objects(
      owned<object_name_and_ops<ObjTag>>& name, Param param) noexcept {
        return gen_del_ops::_gen(get_raw_names(name), param);
    }

    template <typename Storage>
    static inline auto
    delete_objects(owned<object_names<ObjTag, Storage>>& names) noexcept {
        return gen_del_ops::_delete(get_raw_names(names));
    }

    static inline auto
    delete_objects(owned<object_name_and_ops<ObjTag>>& name) noexcept {
        return gen_del_ops::_delete(get_raw_names(name));
    }

    static inline auto is_object(object_name<ObjTag> name) noexcept {
        return gen_del_ops::_is_a(get_raw_name(name));
    }
};

} // namespace eagine

#endif // include guard
