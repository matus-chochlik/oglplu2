//  File implement/oglplus/enum/texture_target_bq.inl
//
//  Automatically generated file, DO NOT modify manually.
//  Edit the enumeration source files in 'source/enums/oglplus'
//  or the 'source/enums/make_enum.py' script instead.
//
//  Copyright Matus Chochlik.
//  Distributed under the Boost Software License, Version 1.0.
//  See accompanying file LICENSE_1_0.txt or copy at
//   http://www.boost.org/LICENSE_1_0.txt
//
namespace oglplus {

OGLPLUS_LIB_FUNC
binding_query get_binding_query(texture_target tgt) noexcept {
    GLenum result = 0;
    switch(GLenum(tgt)) {
#if defined(GL_TEXTURE_1D) && defined(GL_TEXTURE_BINDING_1D)
        case GL_TEXTURE_1D:
            result = GL_TEXTURE_BINDING_1D;
            break;
#endif
#if defined(GL_TEXTURE_1D_ARRAY) && defined(GL_TEXTURE_BINDING_1D_ARRAY)
        case GL_TEXTURE_1D_ARRAY:
            result = GL_TEXTURE_BINDING_1D_ARRAY;
            break;
#endif
#if defined(GL_TEXTURE_2D) && defined(GL_TEXTURE_BINDING_2D)
        case GL_TEXTURE_2D:
            result = GL_TEXTURE_BINDING_2D;
            break;
#endif
#if defined(GL_TEXTURE_2D_ARRAY) && defined(GL_TEXTURE_BINDING_2D_ARRAY)
        case GL_TEXTURE_2D_ARRAY:
            result = GL_TEXTURE_BINDING_2D_ARRAY;
            break;
#endif
#if defined(GL_TEXTURE_2D_MULTISAMPLE) && \
  defined(GL_TEXTURE_BINDING_2D_MULTISAMPLE)
        case GL_TEXTURE_2D_MULTISAMPLE:
            result = GL_TEXTURE_BINDING_2D_MULTISAMPLE;
            break;
#endif
#if defined(GL_TEXTURE_2D_MULTISAMPLE_ARRAY) && \
  defined(GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY)
        case GL_TEXTURE_2D_MULTISAMPLE_ARRAY:
            result = GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY;
            break;
#endif
#if defined(GL_TEXTURE_3D) && defined(GL_TEXTURE_BINDING_3D)
        case GL_TEXTURE_3D:
            result = GL_TEXTURE_BINDING_3D;
            break;
#endif
#if defined(GL_TEXTURE_BUFFER) && defined(GL_TEXTURE_BINDING_BUFFER)
        case GL_TEXTURE_BUFFER:
            result = GL_TEXTURE_BINDING_BUFFER;
            break;
#endif
#if defined(GL_TEXTURE_CUBE_MAP) && defined(GL_TEXTURE_BINDING_CUBE_MAP)
        case GL_TEXTURE_CUBE_MAP:
            result = GL_TEXTURE_BINDING_CUBE_MAP;
            break;
#endif
#if defined(GL_TEXTURE_CUBE_MAP_ARRAY) && \
  defined(GL_TEXTURE_BINDING_CUBE_MAP_ARRAY)
        case GL_TEXTURE_CUBE_MAP_ARRAY:
            result = GL_TEXTURE_BINDING_CUBE_MAP_ARRAY;
            break;
#endif
#if defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_X) && \
  defined(GL_TEXTURE_BINDING_CUBE_MAP)
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
            result = GL_TEXTURE_BINDING_CUBE_MAP;
            break;
#endif
#if defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y) && \
  defined(GL_TEXTURE_BINDING_CUBE_MAP)
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
            result = GL_TEXTURE_BINDING_CUBE_MAP;
            break;
#endif
#if defined(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z) && \
  defined(GL_TEXTURE_BINDING_CUBE_MAP)
        case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
            result = GL_TEXTURE_BINDING_CUBE_MAP;
            break;
#endif
#if defined(GL_TEXTURE_CUBE_MAP_POSITIVE_X) && \
  defined(GL_TEXTURE_BINDING_CUBE_MAP)
        case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
            result = GL_TEXTURE_BINDING_CUBE_MAP;
            break;
#endif
#if defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Y) && \
  defined(GL_TEXTURE_BINDING_CUBE_MAP)
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
            result = GL_TEXTURE_BINDING_CUBE_MAP;
            break;
#endif
#if defined(GL_TEXTURE_CUBE_MAP_POSITIVE_Z) && \
  defined(GL_TEXTURE_BINDING_CUBE_MAP)
        case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
            result = GL_TEXTURE_BINDING_CUBE_MAP;
            break;
#endif
#if defined(GL_TEXTURE_RECTANGLE) && defined(GL_TEXTURE_BINDING_RECTANGLE)
        case GL_TEXTURE_RECTANGLE:
            result = GL_TEXTURE_BINDING_RECTANGLE;
            break;
#endif
        default:;
    }
    return binding_query(result);
}

} // namespace oglplus
