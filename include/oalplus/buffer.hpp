/**
 *  @file oalplus/buffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_BUFFER_1509260923_HPP
#define OALPLUS_BUFFER_1509260923_HPP

#include "object/al_name.hpp"
#include "object/owner.hpp"
#include "error/handling.hpp"
#include "error/outcome.hpp"

namespace oalplus {
namespace tag {

using buffer = al_obj_tag<AL_BUFFER>;

} // namespace tag

using buffer_name = object_name<tag::buffer>;
using buffer = object_owner<tag::buffer>;

template <>
struct obj_gen_del_ops<tag::buffer>
{
	static
	deferred_error_handler
	_gen(array_view<ALuint> names)
	noexcept;

	static
	deferred_error_handler
	_delete(array_view<ALuint> names)
	noexcept;

	static
	outcome<bool> _is_a(ALuint name)
	noexcept;
};

} // namespace oalplus

#include <oalplus/buffer.inl>

#endif // include guard
