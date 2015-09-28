/**
 *  @file oglplus/object/lifetime.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_LIFETIME_1509260923_HPP
#define OGLPLUS_OBJECT_LIFETIME_1509260923_HPP

#include "fwd.hpp"

namespace oglplus {

template <typename ObjTag>
struct obj_lifetime_ops
{
	template <typename Storage>
	static inline
	auto
	gen_objects(owned<object_names<ObjTag, Storage>>& names)
	noexcept
	{
		return obj_gen_del_ops<ObjTag>::_gen(
			get_raw_names(names)
		);
	}

	template <typename Storage, typename Param>
	static inline
	auto
	gen_objects(owned<object_names<ObjTag, Storage>>& names, Param param)
	noexcept
	{
		return obj_gen_del_ops<ObjTag>::_gen(
			get_raw_names(names),
			param
		);
	}

	template <typename Storage>
	static inline
	auto
	delete_objects(owned<object_names<ObjTag, Storage>>& names)
	noexcept
	{
		return obj_gen_del_ops<ObjTag>::_delete(
			get_raw_names(names)
		);
	}

	static inline
	auto
	is_object(object_name<ObjTag> name)
	noexcept
	{
		return obj_gen_del_ops<ObjTag>::_is_a(
			get_raw_name(name)
		);
	}
};

} // namespace oglplus

#endif // include guard
