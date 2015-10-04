/**
 *  @file oglplus/glsl/container.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GLSL_CONTAINER_1509260923_HPP
#define OGLPLUS_GLSL_CONTAINER_1509260923_HPP

#include "string_ref.hpp"
#include <string>

namespace oglplus {

template <typename Container>
class glsl_container
{
private:
	Container _storage;
	glsl_string_ref _str_ref;
public:
	glsl_container(void) = default;
	glsl_container(glsl_container&&) = default;
	glsl_container& operator = (glsl_container&&) = default;
	glsl_container(const glsl_container&) = default;
	glsl_container& operator = (const glsl_container&) = default;

	glsl_container(Container&& storage)
	noexcept
	 : _storage(std::move(storage))
	 , _str_ref(_storage.data(), _storage.size())
	{ }

	Container& storage(void)
	noexcept
	{
		return _storage;
	}

	operator glsl_source_ref (void) const
	noexcept
	{
		return _str_ref;
	}
};

using glsl_string = glsl_container<std::string>;

} // namespace oglplus

#endif // include guard
