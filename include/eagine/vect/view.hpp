/**
 *  @file eagine/vect/view.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_VECT_VIEW_1509260923_HPP
#define EAGINE_VECT_VIEW_1509260923_HPP

#include "data.hpp"
#include "../array_view.hpp"

namespace eagine {
namespace vect {

template <typename T, unsigned N, bool V>
struct view
{
private:
	static inline
	array_view<const T>
	_apply(const data_t<T, N, V>& d, std::false_type)
	noexcept
	{
		return {d._v, N};
	}

	static inline
	array_view<const T>
	_apply(const data_t<T, N, V>& d, std::true_type)
	noexcept
	{
		// TODO: strict aliasing?
		return {reinterpret_cast<const T*>(&d), N};
	}

public:
	static inline
	array_view<const T>
	apply(const data_t<T, N, V>& d)
	noexcept
	{
		return _apply(d, has_vect_data<T, N, V>());
	}
};

} // namespace vect
} // namespace eagine

#endif //include guard

