//  File implement/oglplus/enum/buffer_target_bq.inl
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
binding_query
get_binding_query(buffer_target tgt) noexcept {
    GLenum result = 0;
    switch(GLenum(tgt)) {
#if defined(GL_ARRAY_BUFFER) && defined(GL_ARRAY_BUFFER_BINDING)
	case GL_ARRAY_BUFFER:
	    result = GL_ARRAY_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_ATOMIC_COUNTER_BUFFER) \
  && defined(GL_ATOMIC_COUNTER_BUFFER_BINDING)
	case GL_ATOMIC_COUNTER_BUFFER:
	    result = GL_ATOMIC_COUNTER_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_COPY_READ_BUFFER) && defined(GL_COPY_READ_BUFFER_BINDING)
	case GL_COPY_READ_BUFFER:
	    result = GL_COPY_READ_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_COPY_WRITE_BUFFER) && defined(GL_COPY_WRITE_BUFFER_BINDING)
	case GL_COPY_WRITE_BUFFER:
	    result = GL_COPY_WRITE_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_DISPATCH_INDIRECT_BUFFER) \
  && defined(GL_DISPATCH_INDIRECT_BUFFER_BINDING)
	case GL_DISPATCH_INDIRECT_BUFFER:
	    result = GL_DISPATCH_INDIRECT_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_DRAW_INDIRECT_BUFFER) && defined(GL_DRAW_INDIRECT_BUFFER_BINDING)
	case GL_DRAW_INDIRECT_BUFFER:
	    result = GL_DRAW_INDIRECT_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_ELEMENT_ARRAY_BUFFER) && defined(GL_ELEMENT_ARRAY_BUFFER_BINDING)
	case GL_ELEMENT_ARRAY_BUFFER:
	    result = GL_ELEMENT_ARRAY_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_PARAMETER_BUFFER_ARB) && defined(GL_PARAMETER_BUFFER_BINDING_ARB)
	case GL_PARAMETER_BUFFER_ARB:
	    result = GL_PARAMETER_BUFFER_BINDING_ARB;
	    break;
#endif
#if defined(GL_PIXEL_PACK_BUFFER) && defined(GL_PIXEL_PACK_BUFFER_BINDING)
	case GL_PIXEL_PACK_BUFFER:
	    result = GL_PIXEL_PACK_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_PIXEL_UNPACK_BUFFER) && defined(GL_PIXEL_UNPACK_BUFFER_BINDING)
	case GL_PIXEL_UNPACK_BUFFER:
	    result = GL_PIXEL_UNPACK_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_QUERY_BUFFER) && defined(GL_QUERY_BUFFER_BINDING)
	case GL_QUERY_BUFFER:
	    result = GL_QUERY_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_SHADER_STORAGE_BUFFER) \
  && defined(GL_SHADER_STORAGE_BUFFER_BINDING)
	case GL_SHADER_STORAGE_BUFFER:
	    result = GL_SHADER_STORAGE_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_TEXTURE_BUFFER) && defined(GL_TEXTURE_BUFFER_BINDING)
	case GL_TEXTURE_BUFFER:
	    result = GL_TEXTURE_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_TRANSFORM_FEEDBACK_BUFFER) \
  && defined(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING)
	case GL_TRANSFORM_FEEDBACK_BUFFER:
	    result = GL_TRANSFORM_FEEDBACK_BUFFER_BINDING;
	    break;
#endif
#if defined(GL_UNIFORM_BUFFER) && defined(GL_UNIFORM_BUFFER_BINDING)
	case GL_UNIFORM_BUFFER:
	    result = GL_UNIFORM_BUFFER_BINDING;
	    break;
#endif
	default:;
    }
    return binding_query(result);
}

} // namespace oglplus
