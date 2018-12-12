/**
 *  @file oglplus/shapes/wrapper.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_SHAPES_WRAPPER_1509260923_HPP
#define OGLPLUS_SHAPES_WRAPPER_1509260923_HPP

#include "drawing.hpp"
#include "init.hpp"
#include <eagine/make_array.hpp>
#include <eagine/memory/buffer.hpp>
#include <cassert>
#include <vector>

namespace oglplus {
namespace shapes {

// base_wrapper
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
      const span<const vertex_attrib_and_location>& vaals)
      : _bufs()
      , _ops(std_size(gen.operation_count())) {
        assert(vaals.size() >= span_size(N));
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

// wrapper
template <std::size_t N>
class wrapper : public base_wrapper<N> {
public:
    template <typename Generator, typename... P>
    wrapper(
      eagine::identity<Generator>,
      eagine::memory::buffer& tmp_buf,
      const std::array<const vertex_attrib_and_location, N>& vaals,
      P&&... p)
      : base_wrapper<N>(
          tmp_buf,
          Generator(
            eagine::shapes::get_attrib_bits(vaals), std::forward<P>(p)...),
          view(vaals)) {
    }
};

// generator_wrapper
template <typename Generator, std::size_t N>
class generator_wrapper : public wrapper<N> {
public:
    template <typename... P>
    generator_wrapper(
      eagine::memory::buffer& tmp_buf,
      const std::array<const vertex_attrib_and_location, N>& vaals,
      P&&... p)
      : wrapper<N>(
          eagine::identity<Generator>(),
          tmp_buf,
          vaals,
          std::forward<P>(p)...) {
    }

    template <typename... P>
    generator_wrapper(
      eagine::memory::buffer& tmp_buf,
      const vertex_attrib_and_location& vaal,
      P&&... p)
      : wrapper<N>(
          eagine::identity<Generator>(),
          tmp_buf,
          std::array<const vertex_attrib_and_location, 1>{{vaal}},
          std::forward<P>(p)...) {
    }
};

} // namespace shapes
} // namespace oglplus

#endif // include guard
