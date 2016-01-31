/**
 *  @file eagine/shapes/translated.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SHAPES_TRANSLATED_1509260923_HPP
#define EAGINE_SHAPES_TRANSLATED_1509260923_HPP

#include "delegated.hpp"
#include <eagine/config/basic.hpp>
#include <array>

namespace eagine {
namespace shapes {

class translated_gen
 : public delegated_gen
{
private:
	std::array<float, 3> _d;
public:
	translated_gen(
		std::unique_ptr<generator_intf>&& gen,
		float dx,
		float dy,
		float dz
	) noexcept
	 : delegated_gen(std::move(gen))
	 , _d{{dx, dy, dz}}
	{ }

	void attrib_values(vertex_attrib_kind attr, const span<float>& dest)
	override
	{
		delegated_gen::attrib_values(attr, dest);

		if(attr == vertex_attrib_kind::position)
		{
			for(unsigned v=0, n=vertex_count(); v<n; ++v)
			for(unsigned c=0, m=values_per_vertex(attr); c<m; ++c)
			{
				dest[v*m+c] += _d[c];
			}
		}
	}
};

} // namespace shapes
} // namespace eagine

#endif // include guard
