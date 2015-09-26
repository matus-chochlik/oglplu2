/**
 *  @file oglplus/object/owner.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *  https://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OBJECT_OWNER_1509260923_HPP
#define OGLPLUS_OBJECT_OWNER_1509260923_HPP

#include "name.hpp"
#include "lifetime.hpp"

namespace oglplus {

template <typename ObjTag>
class object_owner
 : public object_name<ObjTag>
{
public:
	object_owner(void)
	{
		obj_lifetime_ops<ObjTag>::gen_objects(*this);
	}

	object_owner(GLenum subtype) // TODO: subtype
	{
		obj_lifetime_ops<ObjTag>::gen_objects(*this, subtype);
	}

	object_owner(const object_owner&) = delete;
	object_owner& operator = (const object_owner&) = delete;

	object_owner(object_owner&&) = default;
	object_owner& operator = (object_owner&&) = default;

	~object_owner(void)
	{
		try { obj_lifetime_ops<ObjTag>::delete_objects(*this); }
		catch(...) { } // TODO rethrow exceptions or cancel ?
	}

	using object_name<ObjTag>::operator bool;
	using object_name<ObjTag>::operator !;
};

} // namespace oglplus

#endif // include guard
