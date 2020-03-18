/**
 *  @file oglplus/shapes/wrapper.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_WRAPPER_HPP
#define OGLPLUS_SHAPES_WRAPPER_HPP

#include "adapted_gen.hpp"
#include "drawing.hpp"
#include "init.hpp"
#include <eagine/assert.hpp>
#include <eagine/make_array.hpp>
#include <eagine/memory/buffer.hpp>
#include <vector>

namespace eagine {
namespace oglp {
namespace shapes {
//------------------------------------------------------------------------------
template <std::size_t N, bool InclElemBuf = true>
class base_wrapper {
private:
    vertex_array _vao;
    buffer_array<N + (InclElemBuf ? 1 : 0)> _bufs;
    std::vector<draw_operation> _ops;

public:
    base_wrapper(
      eagine::memory::buffer& data,
      const adapted_generator& gen,
      span<const vertex_attrib_and_location> vaals)
      : _bufs()
      , _ops(std_size(gen.operation_count())) {
        EAGINE_ASSERT(vaals.size() >= span_size(N));
        initialize_vao_and_buffers(_vao, _bufs, vaals, cover(_ops), gen, data);
    }

    outcome<void> use() noexcept {
        oper::vertex_array_ops gl;
        return gl.bind_vertex_array(_vao);
    }

    outcome<void> draw() const noexcept {
        return draw_using_instructions(view(_ops));
    }
};
//------------------------------------------------------------------------------
template <std::size_t N>
class adapted_generator_wrapper : public base_wrapper<N> {
public:
    adapted_generator_wrapper(
      eagine::memory::buffer& tmp_buf,
      const adapted_generator& gen,
      const vertex_attribs_and_locations<N>& vaals)
      : base_wrapper<N>(tmp_buf, gen, view(vaals)) {
    }

    adapted_generator_wrapper(
      eagine::memory::buffer& tmp_buf,
      std::unique_ptr<eagine::shapes::generator_intf>&& gen,
      const vertex_attribs_and_locations<N>& vaals)
      : base_wrapper<N>(tmp_buf, std::move(gen), view(vaals)) {
    }
};
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_SHAPES_WRAPPER_HPP
