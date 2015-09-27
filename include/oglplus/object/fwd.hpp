/**
 *  @file oglplus/object/fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_FWD_1509260923_HPP
#define OGLPLUS_OBJECT_FWD_1509260923_HPP

#include "../utils/nothing.hpp"

namespace oglplus {

template <typename ObjTag>
struct object_traits;

template <typename ObjTag, typename Storage>
class object_names;

template <typename ObjectNames>
class owned;

template <typename ObjTag>
class object_owner;

template <typename ObjTag>
struct obj_gen_del_ops;

} // namespace oglplus

#endif // include guard
