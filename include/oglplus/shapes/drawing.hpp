/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef OGLPLUS_SHAPES_DRAWING_HPP
#define OGLPLUS_SHAPES_DRAWING_HPP

#include "../config/basic.hpp"
#include "../gl_api.hpp"
#include <eagine/shapes/drawing.hpp>
#include <eagine/span.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
/// @brief Translates from shape primitive type to GL primitive type.
/// @ingroup shapes
/// @see shapes::primitive_type
template <typename A>
auto translate(const basic_gl_api<A>&, shapes::primitive_type) noexcept
  -> primitive_type;
//------------------------------------------------------------------------------
/// @brief Translates from shape attribute data type to GL data type.
/// @ingroup shapes
/// @see shapes::attrib_data_type
template <typename A>
auto translate(const basic_gl_api<A>&, shapes::attrib_data_type) noexcept
  -> data_type;
//------------------------------------------------------------------------------
/// @brief Translates from shape index data type to GL data type.
/// @ingroup shapes
/// @see shapes::index_data_type
template <typename A>
auto translate(const basic_gl_api<A>&, shapes::index_data_type) noexcept
  -> index_data_type;
//------------------------------------------------------------------------------
/// @brief Returns the byte size of a shape attribute data type.
/// @ingroup shapes
/// @see shapes::attrib_data_type
template <typename A>
auto type_size(const basic_gl_api<A>&, shapes::attrib_data_type) noexcept
  -> span_size_t;
//------------------------------------------------------------------------------
/// @brief Returns the byte size of a shape index data type.
/// @ingroup shapes
/// @see shapes::index_data_type
template <typename A>
auto type_size(const basic_gl_api<A>&, shapes::index_data_type) noexcept
  -> span_size_t;
//------------------------------------------------------------------------------
/// @brief Shape draw operation parameters, translated to GL representation.
/// @ingroup shapes
/// @see draw_using_instructions
/// @see draw_instanced_using_instructions
class shape_draw_operation {
public:
    /// @brief Default constructor.
    constexpr shape_draw_operation() noexcept = default;

    /// @brief Initialization from shape generator draw operation.
    template <typename A>
    shape_draw_operation(
      const basic_gl_api<A>& api,
      const shapes::draw_operation& draw_op) noexcept;

    /// @brief Moves the first index by the specified offset.
    auto offset_first(span_size_t offs) noexcept -> auto& {
        _first += offs;
        return *this;
    }

    /// @brief Returns the drawing phase.
    auto phase() const noexcept {
        return _phase;
    }

    /// @brief Indicates if indexed drawing is enabled.
    template <typename A>
    auto is_indexed(const basic_gl_api<A>& api) const noexcept -> bool {
        const basic_gl_constants<A>& GL = api;
        return _idx_type != GL.none;
    }

    /// @brief Invokes the appropriate draw operation on the specified GL api.
    template <typename A>
    void draw(const basic_gl_api<A>& api) const noexcept;

    /// @brief Invokes the appropriate instanced draw operation on the given GL api.
    template <typename A>
    void draw_instanced(
      const basic_gl_api<A>& api,
      gl_types::sizei_type inst_count) const noexcept;

private:
    primitive_type _mode{0};
    index_data_type _idx_type{0};
    gl_types::int_type _first{0};
    gl_types::sizei_type _count{0};
    gl_types::uint_type _phase{0};
    gl_types::uint_type _primitive_restart_index{0};
    gl_types::int_type _patch_vertices{3};
    bool _primitive_restart{false};
    bool _cw_face_winding{false};

    auto _idx_ptr() const noexcept -> gl_types::const_void_ptr_type;

    template <typename A>
    void _prepare(const basic_gl_api<A>& api) const noexcept;
};
//------------------------------------------------------------------------------
/// @brief Holds the first index and count of a subset of drawn shape elements.
/// @ingroup shapes
/// @see shape_draw_operation
struct shape_draw_subset {
    /// @brief Index of the first element.
    span_size_t first{0};
    /// @brief Number of elements to be drawn.
    span_size_t count{0};
};
//------------------------------------------------------------------------------
/// @brief Takes a sequence of draw operations from a shape generator and draws them.
/// @ingroup shapes
/// @see shape_draw_operation
/// @see draw_instanced_using_instructions
template <typename A>
void draw_using_instructions(
  const basic_gl_api<A>& api,
  span<const shape_draw_operation> ops) noexcept;
//------------------------------------------------------------------------------
/// @brief Takes a sequence of draw operations from a shape generator and draws them.
/// @ingroup shapes
/// @see shape_draw_operation
/// @see draw_using_instructions
template <typename A>
void draw_instanced_using_instructions(
  const basic_gl_api<A>& api,
  span<const shape_draw_operation> ops,
  gl_types::sizei_type inst_count) noexcept;
//------------------------------------------------------------------------------
/// @brief Takes a sequence of draw operations from a shape generator and draws them.
/// @ingroup shapes
/// @see shape_draw_operation
/// @see draw_instanced_using_instructions
template <typename A>
void draw_using_instructions(
  const basic_gl_api<A>& api,
  span<const shape_draw_operation> ops,
  const shape_draw_subset& subs) noexcept;
//------------------------------------------------------------------------------
/// @brief Takes a sequence of draw operations from a shape generator and draws them.
/// @ingroup shapes
/// @see shape_draw_operation
/// @see draw_using_instructions
template <typename A>
void draw_instanced_using_instructions(
  const basic_gl_api<A>& api,
  span<const shape_draw_operation> ops,
  const shape_draw_subset& subs,
  gl_types::sizei_type inst_count) noexcept;
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#include <oglplus/shapes/drawing.inl>

#endif // OGLPLUS_SHAPES_DRAWING_HPP
