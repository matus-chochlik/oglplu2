/**
 *  @file oglplus/shapes/adapted_gen.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_ADAPTED_GEN_HPP
#define OGLPLUS_SHAPES_ADAPTED_GEN_HPP

#include "../utils/span.hpp"
#include "drawing.hpp"
#include <eagine/memory/block.hpp>
#include <eagine/shapes/gen_base.hpp>
#include <eagine/shapes/vertex_attrib.hpp>
#include <memory>

namespace oglplus {
namespace shapes {

using eagine::shapes::vertex_attrib_and_location;
using eagine::shapes::vertex_attrib_bits;
using eagine::shapes::vertex_attrib_kind;

class adapted_generator {
private:
    std::unique_ptr<eagine::shapes::generator_base> _gen;

    template <typename Gen>
    static inline eagine::shapes::generator_base* _copy_gen(const Gen& gen) {
        return new Gen(gen);
    }

    static span_size_t _index_type_size(eagine::shapes::index_data_type type);

public:
    template <typename Gen>
    adapted_generator(const Gen& gen)
      : _gen(_copy_gen(gen)) {
    }

    span_size_t vertex_count() const {
        return _gen->vertex_count();
    }

    span_size_t values_per_vertex(vertex_attrib_kind attr) const {
        return _gen->values_per_vertex(attr);
    }

    span_size_t value_count(vertex_attrib_kind attr) const {
        return vertex_count() * values_per_vertex(attr);
    }

    span_size_t attrib_data_block_size(vertex_attrib_kind attr) const {
        // TODO other attrib data types
        return value_count(attr) * span_size(sizeof(GLfloat));
    }

    void attrib_data(
      vertex_attrib_kind attrib, eagine::memory::block data) const {
        // TODO other attrib data types
        _gen->attrib_values(
          attrib, accomodate(data, eagine::identity<GLfloat>()));
    }

    bool indexed() const {
        return _gen->index_count() > 0;
    }

    span_size_t index_count() const {
        return _gen->index_count();
    }

    span_size_t index_type_size() const {
        return _index_type_size(_gen->index_type());
    }

    span_size_t index_data_block_size() const {
        return index_count() * index_type_size();
    }

    void index_data(eagine::memory::block data) const {
        // TODO other index data types, see also drawing
        _gen->indices(accomodate(data, eagine::identity<GLuint>()));
    }

    span_size_t operation_count() const {
        return _gen->operation_count();
    }

    void instructions(span<draw_operation> ops) const;
};

template <typename Generator>
class concrete_adapted_generator : public adapted_generator {
public:
    template <typename... P>
    concrete_adapted_generator(vertex_attrib_bits bits, P&&... p)
      : adapted_generator(Generator(bits, std::forward<P>(p)...)) {
    }
};

} // namespace shapes
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/shapes/adapted_gen.inl>
#endif

#endif // OGLPLUS_SHAPES_ADAPTED_GEN_HPP
