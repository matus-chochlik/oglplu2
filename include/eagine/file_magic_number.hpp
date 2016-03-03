/**
 *  @file eagine/file_magic_number.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_FILE_MAGIC_NUMBER_1408161720_HPP
#define EAGINE_FILE_MAGIC_NUMBER_1408161720_HPP

#include <array>
#include <cstring>

namespace eagine {

template <char ... C>
class file_magic_number
{
private:
	static_assert(
		sizeof...(C) <= 16,
		"File magic number cannot be more than 16 bytes long"
	);
	const std::array<const char, 16> _magic_number;

	static constexpr
	std::array<const char, 16> _make_magic_number(void)
	{
		return {{C...}};
	}
public:
	typedef const char value_type;
	typedef std::size_t size_type;

	constexpr
	file_magic_number(void)
	noexcept
	 : _magic_number(_make_magic_number())
	{ }

	bool is_valid(void) const
	noexcept
	{
		return std::strncmp(
			_magic_number.data(),
			_make_magic_number().data(),
			sizeof ... (C)
		) == 0;
	}

	const char* data(void) const
	noexcept
	{
		return _magic_number.data();
	}

	static constexpr inline
	std::size_t size(void)
	noexcept
	{
		return 16u;
	}
};

} // namespace eagine

#endif //include guard

