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
struct obj_dsa_ops
 : object_name<ObjTag>
{
	obj_dsa_ops(void) = default;

	obj_dsa_ops(object_name<ObjTag> name)
	noexcept
	 : object_name<ObjTag>(name)
	{ }
};

} // namespace oalplus

namespace eagine {

template <ALenum Tag>
struct object_traits<oalplus::tag::al_obj_tag<Tag>>
{
	typedef ALuint name_type;
	typedef oalplus::tag::al_obj_tag<Tag> tag;

	typedef oalplus::obj_gen_del_ops<tag> gen_del_ops;

	template <typename ObjTag>
	using dsa_ops_t = oalplus::obj_dsa_ops<ObjTag>;

	static inline constexpr
	ALuint invalid_name(void)
	noexcept
	{
		return ~ALuint(0);
	}

	static inline constexpr
	ALenum get_type(void)
	noexcept
	{
		return Tag;
	}
};

} // namespace eagine

#endif // include guard
