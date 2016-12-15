/**
 *  @file eagine/object/owner.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OBJECT_OWNER_1509260923_HPP
#define EAGINE_OBJECT_OWNER_1509260923_HPP

#include "name.hpp"
#include "operations.hpp"
#include "lifetime.hpp"

namespace eagine {

template <typename ObjTag, typename Storage>
class owned<object_names<ObjTag, Storage>>
 : public object_names<ObjTag, Storage>
{
protected:
	owned(span_size_t n)
	 : object_names<ObjTag, Storage>(n)
	{ }
public:
	owned(void) = default;

	owned(const owned&) = delete;
	owned& operator = (const owned&) = delete;

	owned(owned&&) = default;
	owned& operator = (owned&&) = default;
};

template <typename ObjTag>
class owned<object_name_and_ops<ObjTag>>
 : public object_name_and_ops<ObjTag>
{
public:
	owned(void) = default;

	owned(const owned&) = delete;
	owned& operator = (const owned&) = delete;

	owned(owned&&) = default;
	owned& operator = (owned&&) = default;
};

template <typename ObjTag>
class object_owner
 : public owned<object_name_and_ops<ObjTag>>
{
public:
	template <typename Storage>
	static inline
	auto gen_(owned<object_names<ObjTag, Storage>>& names)
	noexcept
	{
		return obj_lifetime_ops<ObjTag>::gen_objects(names);
	}

	static inline
	auto gen_(owned<object_name_and_ops<ObjTag>>& names)
	noexcept
	{
		return obj_lifetime_ops<ObjTag>::gen_objects(names);
	}

	template <typename Storage>
	static inline
	auto gen_(
		owned<object_names<ObjTag, Storage>>& names,
		object_subtype_t<ObjTag> subtype
	) noexcept
	{
		return obj_lifetime_ops<ObjTag>::gen_objects(names, subtype);
	}

	static inline
	auto gen_(
		owned<object_name_and_ops<ObjTag>>& names,
		object_subtype_t<ObjTag> subtype
	) noexcept
	{
		return obj_lifetime_ops<ObjTag>::gen_objects(names, subtype);
	}

	template <typename Storage>
	static inline
	auto delete_(owned<object_names<ObjTag, Storage>>& names)
	noexcept
	{
		return obj_lifetime_ops<ObjTag>::delete_objects(names);
	}

	static inline
	auto delete_(owned<object_name_and_ops<ObjTag>>& names)
	noexcept
	{
		return obj_lifetime_ops<ObjTag>::delete_objects(names);
	}

	object_owner(void)
	 : owned<object_name_and_ops<ObjTag>>()
	{
		gen_(*this);
	}

	object_owner(object_subtype_t<ObjTag> subtype)
	 : owned<object_name_and_ops<ObjTag>>()
	{
		gen_(*this, subtype);
	}

	object_owner(object_owner&&) = default;
	object_owner& operator = (object_owner&&) = default;

	~object_owner(void)
	{
		try { delete_(*this); }
		catch(...) { } // TODO rethrow exceptions or cancel ?
	}

	static
	auto is_object(object_name<ObjTag> name)
	noexcept
	{
		return obj_lifetime_ops<ObjTag>::is_object(name);
	}

	auto is_object(void) const
	noexcept
	{
		return is_object(*this);
	}
};

} // namespace eagine

#endif // include guard
