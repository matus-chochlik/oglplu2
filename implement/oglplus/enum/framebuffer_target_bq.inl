//  File implement/oglplus/enum/framebuffer_target_bq.inl
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
binding_query get_binding_query(framebuffer_target tgt) noexcept {
    GLenum result = 0;
    switch(GLenum(tgt)) {
#if defined(GL_DRAW_FRAMEBUFFER) && defined(GL_DRAW_FRAMEBUFFER_BINDING)
        case GL_DRAW_FRAMEBUFFER:
            result = GL_DRAW_FRAMEBUFFER_BINDING;
            break;
#endif
#if defined(GL_READ_FRAMEBUFFER) && defined(GL_READ_FRAMEBUFFER_BINDING)
        case GL_READ_FRAMEBUFFER:
            result = GL_READ_FRAMEBUFFER_BINDING;
            break;
#endif
        default:;
    }
    return binding_query(result);
}

} // namespace oglplus
