/**
 *  @file oglplus/shapes/adapted_gen.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_ADAPTED_GEN_1509260923_HPP
#define OGLPLUS_SHAPES_ADAPTED_GEN_1509260923_HPP

#include "drawing.hpp"
#include "../utils/span.hpp"
#include <eagine/shapes/vertex_attrib.hpp>
#include <eagine/shapes/gen_base.hpp>
#include <memory>

namespace oglplus {
namespace shapes {

using eagine::shapes::vertex_attrib_kind;
using eagine::shapes::vertex_attrib_bits;

class adapted_generator
{
private:
	std::unique_ptr<eagine::shapes::generator_base> _gen;

	template <typename Gen>
	static inline
	eagine::shapes::generator_base* 
	_copy_gen(const Gen& gen)
	{
		return new Gen(gen);
	}

	static
	std::size_t
	_index_type_size(eagine::shapes::index_data_type type);
public:
	template <typename Gen>
	adapted_generator(const Gen& gen)
	 : _gen(_copy_gen(gen))
	{ }

	std::size_t index_count(void) const
	{
		return _gen->index_count();
	}

	std::size_t index_type_size(void) const
	{
		return _index_type_size(_gen->index_type());
	}

	std::size_t index_block_size(void) const
	{
		return index_count()*index_type_size();
	}

	unsigned operation_count(void) const
	{
		return _gen->operation_count();
	}

	void instructions(const span<draw_operation>& ops) const;
};

template <typename Generator>
class concrete_adapted_generator
 : public adapted_generator
{
public:
	concrete_adapted_generator(vertex_attrib_bits bits)
	 : adapted_generator(Generator(bits))
	{ }
};

} // namespace shapes
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/shapes/adapted_gen.inl>
#endif

#endif // include guard
