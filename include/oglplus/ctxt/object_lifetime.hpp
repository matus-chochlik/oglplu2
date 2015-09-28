/**
 *  @file oglplus/ctxt/object_lifetime.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CTXT_OBJECT_LIFETIME_1509260923_HPP
#define OGLPLUS_CTXT_OBJECT_LIFETIME_1509260923_HPP

#include "../utils/gl_func.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../object/lifetime.hpp"

namespace oglplus {
namespace ctxt {

struct object_lifetime
{
	template <typename ObjTag, typename Storage>
	static inline
	outcome<void>
	gen_objects(owned<object_names<ObjTag, Storage>>& names)
	noexcept
	{
		return obj_lifetime_ops<ObjTag>::gen_objects(names);
	}

	template <typename ObjTag, typename Storage>
	static inline
	outcome<void>
	gen_objects(
		owned<object_names<ObjTag, Storage>>& names,
		object_subtype_t<ObjTag> subtype
	)
	noexcept
	{
		return obj_lifetime_ops<ObjTag>::gen_objects(names, subtype);
	}

	template <typename ObjTag, typename Storage>
	static inline
	outcome<void>
	delete_objects(owned<object_names<ObjTag, Storage>>& names)
	noexcept
	{
		return obj_lifetime_ops<ObjTag>::delete_objects(names);
	}

	template <typename ObjTag>
	static inline
	auto
	is_object(object_name<ObjTag> name)
	noexcept
	{
		return obj_lifetime_ops<ObjTag>::is_object(name);
	}
};

} // namespace ctxt
} // namespace oglplus

#endif // include guard
