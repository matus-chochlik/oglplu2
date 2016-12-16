/**
 *  @file eagine/object/array_owner.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_OBJECT_ARRAY_OWNER_1509260923_HPP
#define EAGINE_OBJECT_ARRAY_OWNER_1509260923_HPP

#include "owner.hpp"
#include "names.hpp"
#include "operations.hpp"

namespace eagine {

template <typename ObjTag, std::size_t N>
class object_array_owner
 : public owned<object_name_array<ObjTag, N>>
{
private:
	const object_name_array<ObjTag, N>&
	_ona(void) const
	{
		return *this;
	}
public:
	object_array_owner(void)
	 : owned<object_name_array<ObjTag, N>>()
	{
		obj_lifetime_ops<ObjTag>::gen_objects(*this);
	}

	object_array_owner(object_subtype_t<ObjTag> subtype)
	 : owned<object_name_array<ObjTag, N>>()
	{
		obj_lifetime_ops<ObjTag>::gen_objects(*this, subtype);
	}

	object_array_owner(object_array_owner&&) = default;
	object_array_owner& operator = (object_array_owner&&) = default;

	~object_array_owner(void)
	{
		try { obj_lifetime_ops<ObjTag>::delete_objects(*this); }
		catch(...) { }
	}

	object_name_and_ops<ObjTag>
	operator [] (span_size_t i) const
	noexcept
	{
		return _ona()[i];
	}
};

template <typename ObjTag>
class object_vector_owner
 : public owned<object_name_vector<ObjTag>>
{
private:
	const object_name_vector<ObjTag>&
	_ona(void) const
	{
		return *this;
	}
public:
	object_vector_owner(span_size_t n)
	 : owned<object_name_vector<ObjTag>>(n)
	{
		obj_lifetime_ops<ObjTag>::gen_objects(*this);
	}

	object_vector_owner(
		span_size_t n,
		object_subtype_t<ObjTag> subtype
	): owned<object_name_vector<ObjTag>>(n)
	{
		obj_lifetime_ops<ObjTag>::gen_objects(*this, subtype);
	}

	object_vector_owner(object_vector_owner&&) = default;
	object_vector_owner& operator = (object_vector_owner&&) = default;

	~object_vector_owner(void)
	{
		try { obj_lifetime_ops<ObjTag>::delete_objects(*this); }
		catch(...) { } // TODO rethrow exceptions or cancel ?
	}

	object_name_and_ops<ObjTag>
	operator [] (span_size_t i) const
	noexcept
	{
		return _ona()[i];
	}
};

} // namespace eagine

#endif // include guard
