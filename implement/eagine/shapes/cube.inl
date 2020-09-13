/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include <eagine/assert.hpp>
#include <eagine/math/tvec.hpp>
#include <eagine/memory/span_algo.hpp>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdouble-promotion"
#endif

namespace eagine {
namespace shapes {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
vertex_attrib_bits unit_cube_gen::_attr_mask() noexcept {
    return vertex_attrib_kind::position | vertex_attrib_kind::normal |
           vertex_attrib_kind::tangential | vertex_attrib_kind::bitangential |
           vertex_attrib_kind::pivot | vertex_attrib_kind::box_coord;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
vertex_attrib_bits unit_cube_gen::_shared_attrs() noexcept {
    return vertex_attrib_kind::position | vertex_attrib_kind::pivot |
           vertex_attrib_kind::box_coord;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool unit_cube_gen::_only_shared_attribs() noexcept {
    return !(attrib_bits() & ~_shared_attrs());
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t
unit_cube_gen::_face_vert(span_size_t f, span_size_t t, span_size_t v) noexcept {
    EAGINE_ASSERT(f < 6);
    EAGINE_ASSERT(t < 2);
    EAGINE_ASSERT(v < 3);

    /*
     *    (2)-----(3)    (Y)
     *    /|      /|      ^
     *   / |     / |      |
     * (6)-|---(7) |      |
     *  | (0)---|-(1)     O----> (X)
     *  | /     | /      /
     *  |/      |/      /
     * (4)-----(5)     L (Z)
     *
     *    (2)----(3)   (2)  (0)---(2)
     *     ^ \ II |     | \   \ II |
     *     |  \   | <=> |  \   \   |
     *     |   \  |     |   \   \  |
     *     | I  \ |     | I  \   \ |
     *    (0)--->(1)   (0)-->(1)  (1)
     *
     *        (-)        (+)
     *    (2)----(6) (7)----(3)
     *     ^ \ II |   ^ \ II |
     *     |  \   |   |  \   |
     * (X) |   \  |   |   \  |
     *     | I  \ |   | I  \ |
     *    (0)--->(4) (5)--->(1)
     *
     *        (-)        (+)
     *    (4)----(5) (2)----(3)
     *     ^ \ II |   ^ \ II |
     *     |  \   |   |  \   |
     * (Y) |   \  |   |   \  |
     *     | I  \ |   | I  \ |
     *    (0)--->(1) (6)--->(7)
     *
     *        (-)        (+)
     *    (3)----(2) (6)----(7)
     *     ^ \ II |   ^ \ II |
     *     |  \   |   |  \   |
     * (Z) |   \  |   |   \  |
     *     | I  \ |   | I  \ |
     *    (1)--->(0) (4)--->(5)
     */

    static const span_size_t ftvi[2][3] = {
      {0, 1, 2}, // ( I)
      {2, 1, 3}  // (II)
    };

    static const span_size_t fv[6][4] = {
      {0, 4, 2, 6}, // (-X)
      {5, 1, 7, 3}, // (+X)
      {0, 1, 4, 5}, // (-Y)
      {6, 7, 2, 3}, // (+Y)
      {1, 0, 3, 2}, // (-Z)
      {4, 5, 6, 7}  // (+Z)
    };
    return fv[f][ftvi[t][v]];
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
unit_cube_gen::unit_cube_gen(vertex_attrib_bits attr_bits) noexcept
  : _base(attr_bits & _attr_mask()) {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t unit_cube_gen::vertex_count() {
    if(_only_shared_attribs()) {
        return 8;
    } else {
        return 6 * 2 * 3;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
int unit_cube_gen::_coord_c(span_size_t v, span_size_t c) noexcept {
    EAGINE_ASSERT(v < 8);
    EAGINE_ASSERT(c < 3);

    static const unsigned char _coord_bits[3] = {0xAA, 0xCC, 0xF0};

    const auto b = static_cast<unsigned char>(1U << unsigned(v));
    return ((_coord_bits[c] & b) == b) ? 1 : 0;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_cube_gen::positions(span<float> dest) noexcept {
    span_size_t k = 0;

    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    if(_only_shared_attribs()) {
        EAGINE_ASSERT(dest.size() >= 8 * 3);

        for(span_size_t v = 0; v < 8; ++v) {
            for(span_size_t c = 0; c < 3; ++c) {
                dest[k++] = float(_coord_c(v, c)) - 0.5F;
            }
        }
    } else {
        EAGINE_ASSERT(dest.size() >= 6 * 2 * 3 * 3);

        for(span_size_t f = 0; f < 6; ++f) {
            for(span_size_t t = 0; t < 2; ++t) {
                for(span_size_t i = 0; i < 3; ++i) {
                    span_size_t v = _face_vert(f, t, i);
                    for(span_size_t c = 0; c < 3; ++c) {
                        dest[k++] = float(_coord_c(v, c)) - 0.5F;
                    }
                }
            }
        }
    }

    EAGINE_ASSERT(k == vertex_count() * 3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
int unit_cube_gen::_normal_c(span_size_t f, span_size_t c) noexcept {
    EAGINE_ASSERT(f < 6);
    EAGINE_ASSERT(c < 3);

    //    f =  5, 4, 3, 2, 1, 0
    //  face: +Z,-Z,+Y,-Y,+X,-X
    //   vec: +Z,-Z,+Y,-Y,+X,-X
    // X c=0:  0  0  0  0  1  1 = 0x03
    // Y c=1:  0  0  1  1  0  0 = 0x0C
    // Z c=2:  1  1  0  0  0  0 = 0x30
    static const unsigned char _vec_bits[3] = {0x03, 0x0C, 0x30};
    // X c=0:  0  0  0  0  1  0 = 0x02
    // Y c=1:  0  0  1  0  0  0 = 0x08
    // Z c=2:  1  0  0  0  0  0 = 0x20
    static const unsigned char _vec_sign[3] = {0x02, 0x08, 0x20};

    const auto b = static_cast<unsigned char>(1U << unsigned(f));
    return (((_vec_bits[c] & b) == b) ? 1 : 0) *
           (((_vec_sign[c] & b) == b) ? 1 : -1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_cube_gen::normals(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::normal));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;
    span_size_t n = 2 * 3;

    for(span_size_t f = 0; f < 6; ++f) {
        for(span_size_t i = 0; i < n; ++i) {
            for(span_size_t c = 0; c < 3; ++c) {
                dest[k++] = float(_normal_c(f, c));
            }
        }
    }

    EAGINE_ASSERT(k == vertex_count() * 3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
int unit_cube_gen::_tangential_c(span_size_t f, span_size_t c) noexcept {
    EAGINE_ASSERT(f < 6);
    EAGINE_ASSERT(c < 3);

    //    f =  5, 4, 3, 2, 1, 0
    //  face: +Z,-Z,+Y,-Y,+X,-X
    //   vec: +X,-X,+X,+X,-Z,+Z
    // X c=0:  1  1  1  1  0  0 = 0x3C
    // Y c=1:  0  0  0  0  0  0 = 0x00
    // Z c=2:  0  0  0  0  1  1 = 0x03
    static const unsigned char _vec_bits[3] = {0x3C, 0x00, 0x03};
    // X c=0:  1  0  1  1  0  0 = 0x2C
    // Y c=1:  0  0  0  0  0  0 = 0x00
    // Z c=2:  0  0  0  0  0  1 = 0x01
    static const unsigned char _vec_sign[3] = {0x2C, 0x00, 0x01};

    const auto b = static_cast<unsigned char>(1U << unsigned(f));
    return (((_vec_bits[c] & b) == b) ? 1 : 0) *
           (((_vec_sign[c] & b) == b) ? 1 : -1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_cube_gen::tangentials(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::tangential));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;
    span_size_t n = 2 * 3;

    for(span_size_t f = 0; f < 6; ++f) {
        for(span_size_t i = 0; i < n; ++i) {
            for(span_size_t c = 0; c < 3; ++c) {
                dest[k++] = float(_tangential_c(f, c));
            }
        }
    }

    EAGINE_ASSERT(k == vertex_count() * 3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
int unit_cube_gen::_bitangential_c(span_size_t f, span_size_t c) noexcept {
    EAGINE_ASSERT(f < 6);
    EAGINE_ASSERT(c < 3);

    //    f =  5, 4, 3, 2, 1, 0
    //  face: +Z,-Z,+Y,-Y,+X,-X
    //   vec: +Y,+Y,-Z,+Z,+Y,+Y
    // X c=0:  0  0  0  0  0  0 = 0x00
    // Y c=1:  1  1  0  0  1  1 = 0x33
    // Z c=2:  0  0  1  1  0  0 = 0x0C
    static const unsigned char _vec_bits[3] = {0x00, 0x33, 0x0C};
    // X c=0:  0  0  0  0  0  0 = 0x00
    // Y c=1:  1  1  0  0  1  1 = 0x33
    // Z c=2:  0  0  0  1  0  0 = 0x04
    static const unsigned char _vec_sign[3] = {0x00, 0x33, 0x04};

    const auto b = static_cast<unsigned char>(1U << unsigned(f));
    return (((_vec_bits[c] & b) == b) ? 1 : 0) *
           (((_vec_sign[c] & b) == b) ? 1 : -1);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_cube_gen::bitangentials(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::bitangential));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    span_size_t k = 0;
    span_size_t n = 2 * 3;

    for(span_size_t f = 0; f < 6; ++f) {
        for(span_size_t i = 0; i < n; ++i) {
            for(span_size_t c = 0; c < 3; ++c) {
                dest[k++] = float(_bitangential_c(f, c));
            }
        }
    }

    EAGINE_ASSERT(k == vertex_count() * 3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_cube_gen::face_coords(span<float> dest) noexcept {
    EAGINE_ASSERT(has(vertex_attrib_kind::face_coord));
    EAGINE_ASSERT(dest.size() >= vertex_count() * 3);

    /*
     *     (0,1,f) (1,1,f)
     *       (2)----(3)
     *        ^ \ II |
     *        |  \   |
     *        |   \  |
     *        | I  \ |
     *       (0)--->(1)
     *     (0,0,f) (1,0,f)
     */

    static const span_size_t ftvi[2][3] = {
      {0, 1, 2}, // ( I)
      {2, 1, 3}  // (II)
    };

    const float uv[4][2] = {{0.F, 0.F}, {1.F, 0.F}, {0.F, 1.F}, {1.F, 1.F}};

    span_size_t k = 0;

    for(span_size_t f = 0; f < 6; ++f) {
        for(const auto& ftv : ftvi) {
            for(const auto v : ftv) {
                dest[k++] = uv[v][0];
                dest[k++] = uv[v][1];
                dest[k++] = float(f);
            }
        }
    }

    EAGINE_ASSERT(k == vertex_count() * 3);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_cube_gen::attrib_values(vertex_attrib_variant vav, span<float> dest) {
    switch(vav.attrib) {
        case vertex_attrib_kind::position:
            positions(dest);
            break;
        case vertex_attrib_kind::normal:
            normals(dest);
            break;
        case vertex_attrib_kind::tangential:
            tangentials(dest);
            break;
        case vertex_attrib_kind::bitangential:
            bitangentials(dest);
            break;
        case vertex_attrib_kind::face_coord:
            face_coords(dest);
            break;
        case vertex_attrib_kind::pivot:
        case vertex_attrib_kind::pivot_pivot:
        case vertex_attrib_kind::vertex_pivot:
        case vertex_attrib_kind::object_id:
        case vertex_attrib_kind::polygon_id:
        case vertex_attrib_kind::material_id:
        case vertex_attrib_kind::box_coord:
        case vertex_attrib_kind::wrap_coord:
        case vertex_attrib_kind::weight:
        case vertex_attrib_kind::color:
        case vertex_attrib_kind::occlusion:
            _base::attrib_values(vav, dest);
            break;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t unit_cube_gen::draw_variant_count() {
    return 2;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
index_data_type unit_cube_gen::index_type(drawing_variant var) {
    if(var == 0) {
        if(_only_shared_attribs()) {
            return index_data_type::unsigned_8;
        }
    } else if(var == 1) {
        return index_data_type::unsigned_8;
    }
    return index_data_type::none;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t unit_cube_gen::index_count(drawing_variant var) {
    if(var == 0) {
        if(_only_shared_attribs()) {
            return 6 * 2 * 3;
        }
    } else if(var == 1) {
        return 6 * 8;
    }
    return 0;
}
//------------------------------------------------------------------------------
template <typename T>
inline void unit_cube_gen::_indices(drawing_variant var, span<T> dest) noexcept {
    EAGINE_ASSERT(dest.size() >= index_count(var));

    span_size_t k = 0;

    if(var == 0) {
        if(_only_shared_attribs()) {
            for(span_size_t f = 0; f < 6; ++f) {
                for(span_size_t t = 0; t < 2; ++t) {
                    for(span_size_t v = 0; v < 3; ++v) {
                        dest[k++] = T(_face_vert(f, t, v));
                    }
                }
            }
        }
    } else if(var == 1) {
        for(span_size_t f = 0; f < 6; ++f) {
            dest[k++] = T(_face_vert(f, 0, 0));
            dest[k++] = T(_face_vert(f, 0, 2));

            dest[k++] = T(_face_vert(f, 0, 2));
            dest[k++] = T(_face_vert(f, 1, 2));

            dest[k++] = T(_face_vert(f, 1, 2));
            dest[k++] = T(_face_vert(f, 1, 1));

            dest[k++] = T(_face_vert(f, 1, 1));
            dest[k++] = T(_face_vert(f, 0, 0));
        }
    }

    EAGINE_ASSERT(k == index_count(var));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_cube_gen::indices(drawing_variant var, span<std::uint8_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_cube_gen::indices(drawing_variant var, span<std::uint16_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_cube_gen::indices(drawing_variant var, span<std::uint32_t> dest) {
    _indices(var, dest);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
span_size_t unit_cube_gen::operation_count(drawing_variant) {
    return 1;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void unit_cube_gen::instructions(drawing_variant var, span<draw_operation> ops) {
    EAGINE_ASSERT(ops.size() >= operation_count(var));

    if(var == 0) {
        if(_only_shared_attribs()) {
            draw_operation& op = ops[0];
            op.mode = primitive_type::triangles;
            op.idx_type = index_type(var);
            op.first = 0;
            op.count = index_count(var);
            op.primitive_restart = false;
            op.cw_face_winding = false;
        } else {
            draw_operation& op = ops[0];
            op.mode = primitive_type::triangles;
            op.idx_type = index_data_type::none;
            op.first = 0;
            op.count = vertex_count();
            op.primitive_restart = false;
            op.cw_face_winding = false;
        }
    } else if(var == 1) {
        draw_operation& op = ops[0];
        op.mode = primitive_type::lines;
        op.idx_type = index_type(var);
        op.first = 0;
        op.count = index_count(var);
        op.primitive_restart = false;
    }
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
math::sphere<float, true> unit_cube_gen::bounding_sphere() {
    using std::sqrt;
    return {{0.0F}, float(sqrt(2.F))};
}
//------------------------------------------------------------------------------
} // namespace shapes
} // namespace eagine

#ifdef __clang__
#pragma clang diagnostic pop
#endif
