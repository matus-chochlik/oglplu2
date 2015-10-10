/**
 *  @file eagine/utils/buffer_data.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_UTILS_BUFFER_DATA_1509260923_HPP
#define EAGINE_UTILS_BUFFER_DATA_1509260923_HPP

#include "buffer_size.hpp"
#include "types.hpp"

namespace eagine {

template <typename S>
class buffer_data
{
private:
	buffer_size<S> _size;
	const void* _data;
public:
	template <typename T, std::size_t N>
	buffer_data(const T (&data) [N])
	noexcept
	 : _size(N, data)
	 , _data(data)
	{ }

	template <typename T>
	buffer_data(array_view<T> av)
	noexcept
	 : _size(av)
	 , _data(av.data())
	{ }

	buffer_size<S> size(void) const
	noexcept
	{
		return _size;
	}

	const void* data(void) const
	noexcept
	{
		return _data;
	}

	array_view<const byte> view(void) const
	noexcept
	{
		return {
			static_cast<const byte*>(_data),
			static_cast<std::size_t>(_size)
		};
	}
};

} // namespace eagine

#endif // include guard
