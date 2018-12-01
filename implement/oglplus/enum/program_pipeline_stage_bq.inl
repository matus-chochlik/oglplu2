//  File implement/oglplus/enum/program_pipeline_stage_bq.inl
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
get_binding_query(program_pipeline_stage tgt) noexcept {
    GLbitfield result = 0;
    switch(GLbitfield(tgt)) {
#if defined(GL_COMPUTE_SHADER_BIT) && defined(GL_COMPUTE_SHADER)
        case GL_COMPUTE_SHADER_BIT:
            result = GL_COMPUTE_SHADER;
            break;
#endif
#if defined(GL_FRAGMENT_SHADER_BIT) && defined(GL_FRAGMENT_SHADER)
        case GL_FRAGMENT_SHADER_BIT:
            result = GL_FRAGMENT_SHADER;
            break;
#endif
#if defined(GL_GEOMETRY_SHADER_BIT) && defined(GL_GEOMETRY_SHADER)
        case GL_GEOMETRY_SHADER_BIT:
            result = GL_GEOMETRY_SHADER;
            break;
#endif
#if defined(GL_TESS_CONTROL_SHADER_BIT) && defined(GL_TESS_CONTROL_SHADER)
        case GL_TESS_CONTROL_SHADER_BIT:
            result = GL_TESS_CONTROL_SHADER;
            break;
#endif
#if defined(GL_TESS_EVALUATION_SHADER_BIT) && defined(GL_TESS_EVALUATION_SHADER)
        case GL_TESS_EVALUATION_SHADER_BIT:
            result = GL_TESS_EVALUATION_SHADER;
            break;
#endif
#if defined(GL_VERTEX_SHADER_BIT) && defined(GL_VERTEX_SHADER)
        case GL_VERTEX_SHADER_BIT:
            result = GL_VERTEX_SHADER;
            break;
#endif
        default:;
    }
    return binding_query(result);
}

} // namespace oglplus
