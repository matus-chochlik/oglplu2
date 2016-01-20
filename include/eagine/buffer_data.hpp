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

#include "memory_block.hpp"
#include "buffer_size.hpp"
#include "types.hpp"

namespace eagine {

template <typename S>
class buffer_data_spec
{
private:
	buffer_size<S> _size;
	const void* _data;
public:
	buffer_data_spec(void)
	noexcept
	 : _size()
	 , _data(nullptr)
	{ }

	buffer_data_spec(const memory_block& blk)
	noexcept
	 : _size(S(blk.size()))
	 , _data(blk.data())
	{ }

	template <typename T, std::size_t N>
	buffer_data_spec(const T (&data) [N])
	noexcept
	 : _size(identity<T>(), N)
	 , _data(data)
	{ }

	template <typename T>
	buffer_data_spec(const T* data, std::size_t n)
	noexcept
	 : _size(identity<T>(), n)
	 , _data(data)
	{ }

	template <typename T>
	buffer_data_spec(span<T> av)
	noexcept
	 : _size(av)
	 , _data(av.data())
	{ }

	bool empty(void) const
	noexcept
	{
		return _size.get() == 0;
	}

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

	span<const byte> view(void) const
	noexcept
	{
		return {
			static_cast<const byte*>(_data),
			static_cast<std::ptrdiff_t>(_size)
		};
	}
};

} // namespace eagine

#endif // include guard
