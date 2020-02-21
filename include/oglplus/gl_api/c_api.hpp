/**
 *  @file oglplus/gl_api/c_api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_C_API_HPP
#define OGLPLUS_GL_API_C_API_HPP

#include "api_traits.hpp"
#include "config.hpp"
#include <eagine/nothing.hpp>
#include <eagine/preprocessor.hpp>

#ifndef OGLPLUS_GL_STATIC_FUNC
#if OGLPLUS_HAS_GL
#if defined(__GLEW_H__)
#define OGLPLUS_GL_STATIC_FUNC(NAME) nullptr
#else
#define OGLPLUS_GL_STATIC_FUNC(NAME) &EAGINE_JOIN(gl, NAME)
#endif
#else
#define OGLPLUS_GL_STATIC_FUNC(NAME) nullptr
#endif
#endif

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
template <typename Traits>
struct basic_gl_c_api {

    using this_api = basic_gl_c_api;
    using api_traits = Traits;

    using void_ptr_type = typename gl_types::void_ptr_type;
    using const_void_ptr_type = typename gl_types::const_void_ptr_type;
    using sizei_type = typename gl_types::sizei_type;
    using sizeiptr_type = typename gl_types::sizeiptr_type;
    using intptr_type = typename gl_types::intptr_type;
    using bool_type = typename gl_types::bool_type;
    using char_type = typename gl_types::char_type;
    using byte_type = typename gl_types::byte_type;
    using ubyte_type = typename gl_types::ubyte_type;
    using int_type = typename gl_types::int_type;
    using uint_type = typename gl_types::uint_type;
    using int64_type = typename gl_types::int64_type;
    using uint64_type = typename gl_types::uint64_type;
    using enum_type = typename gl_types::enum_type;
    using float_type = typename gl_types::float_type;
    using double_type = typename gl_types::double_type;
    using bitfield_type = typename gl_types::bitfield_type;
    using sync_type = typename gl_types::sync_type;

    template <
      typename Signature,
      c_api_function_ptr<api_traits, nothing_t, Signature> Function>
    using gl_api_function = eagine::opt_c_api_function<
      api_traits,
      nothing_t,
      Signature,
      Function,
      gl_types::has_api,
      gl_types::has_static_api>;

    gl_api_function<enum_type(), OGLPLUS_GL_STATIC_FUNC(GetError)> GetError;

    gl_api_function<enum_type(), OGLPLUS_GL_STATIC_FUNC(GetGraphicsResetStatus)>
      GetGraphicsResetStatus;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(Enable)> Enable;

    gl_api_function<void(enum_type, uint_type), OGLPLUS_GL_STATIC_FUNC(Enablei)>
      Enablei;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(Disable)> Disable;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Disablei)>
      Disablei;

    gl_api_function<bool_type(enum_type), OGLPLUS_GL_STATIC_FUNC(IsEnabled)>
      IsEnabled;

    gl_api_function<
      bool_type(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(IsEnabledi)>
      IsEnabledi;

    // object ops

    gl_api_function<
      sync_type(enum_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(FenceSync)>
      FenceSync;

    gl_api_function<void(sync_type), OGLPLUS_GL_STATIC_FUNC(DeleteSync)>
      DeleteSync;

    gl_api_function<bool_type(sync_type), OGLPLUS_GL_STATIC_FUNC(IsSync)>
      IsSync;

    gl_api_function<
      void(sync_type, enum_type, sizei_type, sizei_type*, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSynciv)>
      GetSynciv;

    gl_api_function<
      void(sync_type, bitfield_type, uint64_type),
      OGLPLUS_GL_STATIC_FUNC(WaitSync)>
      WaitSync;

    gl_api_function<
      enum_type(sync_type, bitfield_type, uint64_type),
      OGLPLUS_GL_STATIC_FUNC(ClientWaitSync)>
      ClientWaitSync;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenVertexArrays)>
      GenVertexArrays;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteVertexArrays)>
      DeleteVertexArrays;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsVertexArray)>
      IsVertexArray;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(BindVertexArray)>
      BindVertexArray;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenBuffers)>
      GenBuffers;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteBuffers)>
      DeleteBuffers;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsBuffer)>
      IsBuffer;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindBuffer)>
      BindBuffer;

    gl_api_function<
      void(enum_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindBufferBase)>
      BindBufferBase;

    gl_api_function<
      void(enum_type, uint_type, uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(BindBufferRange)>
      BindBufferRange;

    gl_api_function<
      void(enum_type, sizeiptr_type, const_void_ptr_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(BufferStorage)>
      BufferStorage;

    gl_api_function<
      void(uint_type, sizeiptr_type, const_void_ptr_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(BufferStorage)>
      NamedBufferStorage;

    gl_api_function<
      void(enum_type, sizeiptr_type, const_void_ptr_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BufferData)>
      BufferData;

    gl_api_function<
      void(uint_type, sizeiptr_type, const_void_ptr_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(NamedBufferData)>
      NamedBufferData;

    gl_api_function<
      void(enum_type, intptr_type, sizeiptr_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(BufferSubData)>
      BufferSubData;

    gl_api_function<
      void(uint_type, intptr_type, sizeiptr_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(NamedBufferSubData)>
      NamedBufferSubData;

    gl_api_function<
      void(enum_type, enum_type, enum_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferData)>
      ClearBufferData;

    gl_api_function<
      void(uint_type, enum_type, enum_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedBufferData)>
      ClearNamedBufferData;

    gl_api_function<
      void(
        enum_type,
        enum_type,
        intptr_type,
        sizeiptr_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferSubData)>
      ClearBufferSubData;

    gl_api_function<
      void(
        uint_type,
        enum_type,
        intptr_type,
        sizeiptr_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedBufferSubData)>
      ClearNamedBufferSubData;

    gl_api_function<
      void_ptr_type(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(MapBuffer)>
      MapBuffer;

    gl_api_function<
      void_ptr_type(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(MapNamedBuffer)>
      MapNamedBuffer;

    gl_api_function<
      void_ptr_type(enum_type, intptr_type, sizeiptr_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(MapBufferRange)>
      MapBufferRange;

    gl_api_function<
      void_ptr_type(uint_type, intptr_type, sizeiptr_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(MapNamedBufferRange)>
      MapNamedBufferRange;

    gl_api_function<
      void(enum_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(FlushMappedBufferRange)>
      FlushMappedBufferRange;

    gl_api_function<
      void(uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(FlushMappedNamedBufferRange)>
      FlushMappedNamedBufferRange;

    gl_api_function<bool_type(enum_type), OGLPLUS_GL_STATIC_FUNC(UnmapBuffer)>
      UnmapBuffer;

    gl_api_function<
      bool_type(uint_type),
      OGLPLUS_GL_STATIC_FUNC(UnmapNamedBuffer)>
      UnmapNamedBuffer;

    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateBufferData)>
      InvalidateBufferData;

    gl_api_function<
      void(uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateBufferSubData)>
      InvalidateBufferSubData;

    gl_api_function<
      void(enum_type, enum_type, intptr_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(CopyBufferSubData)>
      CopyBufferSubData;

    gl_api_function<
      void(uint_type, uint_type, intptr_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(CopyNamedBufferSubData)>
      CopyNamedBufferSubData;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetBufferParameteriv)>
      GetBufferParameteriv;

    gl_api_function<
      void(enum_type, enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetBufferParameteri64v)>
      GetBufferParameteri64v;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedBufferParameteriv)>
      GetNamedBufferParameteriv;

    gl_api_function<
      void(uint_type, enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedBufferParameteri64v)>
      GetNamedBufferParameteri64v;

    gl_api_function<
      void(enum_type, intptr_type, sizeiptr_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetBufferSubData)>
      GetBufferSubData;

    gl_api_function<
      void(uint_type, intptr_type, sizeiptr_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetNamedBufferSubData)>
      GetNamedBufferSubData;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenTextures)>
      GenTextures;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteTextures)>
      DeleteTextures;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsTexture)>
      IsTexture;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindTexture)>
      BindTexture;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenSamplers)>
      GenSamplers;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteSamplers)>
      DeleteSamplers;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsSampler)>
      IsSampler;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindSampler)>
      BindSampler;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenRenderbuffers)>
      GenRenderbuffers;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteRenderbuffers)>
      DeleteRenderbuffers;

    gl_api_function<
      bool_type(uint_type),
      OGLPLUS_GL_STATIC_FUNC(IsRenderbuffer)>
      IsRenderbuffer;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindRenderbuffer)>
      BindRenderbuffer;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenFramebuffers)>
      GenFramebuffers;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteFramebuffers)>
      DeleteFramebuffers;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsFramebuffer)>
      IsFramebuffer;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindFramebuffer)>
      BindFramebuffer;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenTransformFeedbacks)>
      GenTransformFeedbacks;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteTransformFeedbacks)>
      DeleteTransformFeedbacks;

    gl_api_function<
      bool_type(uint_type),
      OGLPLUS_GL_STATIC_FUNC(IsTransformFeedback)>
      IsTransformFeedback;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindTransformFeedback)>
      BindTransformFeedback;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenQueries)>
      GenQueries;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteQueries)>
      DeleteQueries;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsQuery)>
      IsQuery;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryiv)>
      GetQueryiv;

    gl_api_function<
      void(enum_type, uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryIndexediv)>
      GetQueryIndexediv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryObjectiv)>
      GetQueryObjectiv;

    gl_api_function<
      void(uint_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryObjectuiv)>
      GetQueryObjectuiv;

    gl_api_function<
      void(uint_type, enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryObjecti64v)>
      GetQueryObjecti64v;

    gl_api_function<
      void(uint_type, enum_type, uint64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryObjectui64v)>
      GetQueryObjectui64v;

    gl_api_function<
      void(uint_type, uint_type, enum_type, intptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetQueryBufferObjectiv)>
      GetQueryBufferObjectiv;

    gl_api_function<
      void(uint_type, uint_type, enum_type, intptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetQueryBufferObjectuiv)>
      GetQueryBufferObjectuiv;

    gl_api_function<
      void(uint_type, uint_type, enum_type, intptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetQueryBufferObjecti64v)>
      GetQueryBufferObjecti64v;

    gl_api_function<
      void(uint_type, uint_type, enum_type, intptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetQueryBufferObjectui64v)>
      GetQueryBufferObjectui64v;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BeginQuery)>
      BeginQuery;

    gl_api_function<
      void(enum_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BeginQueryIndexed)>
      BeginQueryIndexed;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(EndQuery)> EndQuery;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(EndQueryIndexed)>
      EndQueryIndexed;

    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(QueryCounter)>
      QueryCounter;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenProgramPipelines)>
      GenProgramPipelines;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateProgramPipelines)>
      CreateProgramPipelines;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteProgramPipelines)>
      DeleteProgramPipelines;

    gl_api_function<
      bool_type(uint_type),
      OGLPLUS_GL_STATIC_FUNC(IsProgramPipeline)>
      IsProgramPipeline;

    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindProgramPipeline)>
      BindProgramPipeline;

    gl_api_function<
      void(uint_type, bitfield_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(UseProgramStages)>
      UseProgramStages;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ActiveShaderProgram)>
      ActiveShaderProgram;

    //
    gl_api_function<uint_type(enum_type), OGLPLUS_GL_STATIC_FUNC(CreateShader)>
      CreateShader;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(DeleteShader)>
      DeleteShader;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsShader)>
      IsShader;

    gl_api_function<
      void(uint_type, sizei_type, const char_type* const*, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ShaderSource)>
      ShaderSource;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(CompileShader)>
      CompileShader;

    gl_api_function<
      void(
        sizei_type,
        const uint_type*,
        enum_type,
        const_void_ptr_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(ShaderBinary)>
      ShaderBinary;

    gl_api_function<
      void(
        uint_type,
        const char_type*,
        uint_type,
        const uint_type*,
        const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(SpecializeShader)>
      SpecializeShader;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderiv)>
      GetShaderiv;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderInfoLog)>
      GetShaderInfoLog;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderSource)>
      GetShaderSource;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(ReleaseShaderCompiler)>
      ReleaseShaderCompiler;

    //
    gl_api_function<uint_type(), OGLPLUS_GL_STATIC_FUNC(CreateProgram)>
      CreateProgram;

    gl_api_function<
      uint_type(enum_type, sizei_type, const char_type* const*),
      OGLPLUS_GL_STATIC_FUNC(CreateShaderProgramv)>
      CreateShaderProgramv;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(DeleteProgram)>
      DeleteProgram;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsProgram)>
      IsProgram;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(AttachShader)>
      AttachShader;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DetachShader)>
      DetachShader;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetAttachedShaders)>
      GetAttachedShaders;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(ValidateProgram)>
      ValidateProgram;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(LinkProgram)>
      LinkProgram;

    gl_api_function<
      void(uint_type, enum_type, const_void_ptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramBinary)>
      ProgramBinary;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, enum_type*, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetProgramBinary)>
      GetProgramBinary;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramiv)>
      GetProgramiv;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramInfoLog)>
      GetProgramInfoLog;

    gl_api_function<
      void(uint_type, enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramInterfaceiv)>
      GetProgramInterfaceiv;

    gl_api_function<
      uint_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceIndex)>
      GetProgramResourceIndex;

    gl_api_function<
      void(
        uint_type, enum_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceName)>
      GetProgramResourceName;

    gl_api_function<
      int_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceLocation)>
      GetProgramResourceLocation;

    gl_api_function<
      int_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceLocationIndex)>
      GetProgramResourceLocationIndex;

    gl_api_function<
      void(
        uint_type,
        enum_type,
        uint_type,
        sizei_type,
        const enum_type*,
        sizei_type,
        sizei_type*,
        int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceiv)>
      GetProgramResourceiv;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(UseProgram)>
      UseProgram;

    gl_api_function<
      void(uint_type, uint_type, const char*),
      OGLPLUS_GL_STATIC_FUNC(BindAttribLocation)>
      BindAttribLocation;

    gl_api_function<
      int_type(uint_type, const char*),
      OGLPLUS_GL_STATIC_FUNC(GetAttribLocation)>
      GetAttribLocation;

    gl_api_function<
      int_type(uint_type, const char*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformLocation)>
      GetUniformLocation;

    gl_api_function<
      void(uint_type, uint_type, const char*),
      OGLPLUS_GL_STATIC_FUNC(BindFragDataLocation)>
      BindFragDataLocation;

    gl_api_function<
      void(uint_type, uint_type, uint_type, const char*),
      OGLPLUS_GL_STATIC_FUNC(BindFragDataLocationIndexed)>
      BindFragDataLocationIndexed;

    // uniform
    gl_api_function<void(int_type, int_type), OGLPLUS_GL_STATIC_FUNC(Uniform1i)>
      Uniform1i;

    gl_api_function<
      void(int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform2i)>
      Uniform2i;

    gl_api_function<
      void(int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform3i)>
      Uniform3i;

    gl_api_function<
      void(int_type, int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform4i)>
      Uniform4i;

    gl_api_function<
      void(int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform1iv)>
      Uniform1iv;

    gl_api_function<
      void(int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform2iv)>
      Uniform2iv;

    gl_api_function<
      void(int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform3iv)>
      Uniform3iv;

    gl_api_function<
      void(int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform4iv)>
      Uniform4iv;

    gl_api_function<
      void(int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform1ui)>
      Uniform1ui;

    gl_api_function<
      void(int_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform2ui)>
      Uniform2ui;

    gl_api_function<
      void(int_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform3ui)>
      Uniform3ui;

    gl_api_function<
      void(int_type, uint_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform4ui)>
      Uniform4ui;

    gl_api_function<
      void(int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform1uiv)>
      Uniform1uiv;

    gl_api_function<
      void(int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform2uiv)>
      Uniform2uiv;

    gl_api_function<
      void(int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform3uiv)>
      Uniform3uiv;

    gl_api_function<
      void(int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform4uiv)>
      Uniform4uiv;

    gl_api_function<
      void(int_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform1f)>
      Uniform1f;

    gl_api_function<
      void(int_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform2f)>
      Uniform2f;

    gl_api_function<
      void(int_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform3f)>
      Uniform3f;

    gl_api_function<
      void(int_type, float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform4f)>
      Uniform4f;

    gl_api_function<
      void(int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform1fv)>
      Uniform1fv;

    gl_api_function<
      void(int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform2fv)>
      Uniform2fv;

    gl_api_function<
      void(int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform3fv)>
      Uniform3fv;

    gl_api_function<
      void(int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform4fv)>
      Uniform4fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix2fv)>
      UniformMatrix2fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix3fv)>
      UniformMatrix3fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix4fv)>
      UniformMatrix4fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix2x3fv)>
      UniformMatrix2x3fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix3x2fv)>
      UniformMatrix3x2fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix2x4fv)>
      UniformMatrix2x4fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix4x2fv)>
      UniformMatrix4x2fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix3x4fv)>
      UniformMatrix3x4fv;

    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix4x3fv)>
      UniformMatrix4x3fv;

    // viewport
    gl_api_function<
      void(double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRange)>
      DepthRange;

    gl_api_function<
      void(float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRangef)>
      DepthRangef;

    gl_api_function<
      void(int_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(Viewport)>
      Viewport;

    gl_api_function<
      void(float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ClearColor)>
      ClearColor;

    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(ClearDepthf)>
      ClearDepthf;

    gl_api_function<void(double_type), OGLPLUS_GL_STATIC_FUNC(ClearDepth)>
      ClearDepth;

    gl_api_function<void(int_type), OGLPLUS_GL_STATIC_FUNC(ClearStencil)>
      ClearStencil;

    gl_api_function<void(bitfield_type), OGLPLUS_GL_STATIC_FUNC(Clear)> Clear;

    gl_api_function<
      void(enum_type, bool_type*),
      OGLPLUS_GL_STATIC_FUNC(GetBooleanv)>
      GetBooleanv;

    gl_api_function<
      void(enum_type, uint_type, bool_type*),
      OGLPLUS_GL_STATIC_FUNC(GetBooleani_v)>
      GetBooleani_v;

    gl_api_function<
      void(enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetIntegerv)>
      GetIntegerv;

    gl_api_function<
      void(enum_type, uint_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetIntegeri_v)>
      GetIntegeri_v;

    gl_api_function<
      void(enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetInteger64v)>
      GetInteger64v;

    gl_api_function<
      void(enum_type, uint_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetInteger64i_v)>
      GetInteger64i_v;

    gl_api_function<
      void(enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFloatv)>
      GetFloatv;

    gl_api_function<
      void(enum_type, uint_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFloati_v)>
      GetFloati_v;

    gl_api_function<
      void(enum_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetDoublev)>
      GetDoublev;

    gl_api_function<
      void(enum_type, uint_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetDoublei_v)>
      GetDoublei_v;

    gl_api_function<
      const ubyte_type*(enum_type),
      OGLPLUS_GL_STATIC_FUNC(GetString)>
      GetString;

    gl_api_function<
      const ubyte_type*(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(GetStringi)>
      GetStringi;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(Flush)> Flush;
    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(Finish)> Finish;

    constexpr basic_gl_c_api(api_traits& traits)
      : GetError("GetError", traits, *this)
      , GetGraphicsResetStatus("GetGraphicsResetStatus", traits, *this)
      , Enable("Enable", traits, *this)
      , Enablei("Enablei", traits, *this)
      , Disable("Disable", traits, *this)
      , Disablei("Disablei", traits, *this)
      , IsEnabled("IsEnabled", traits, *this)
      , IsEnabledi("IsEnabledi", traits, *this)
      , FenceSync("FenceSync", traits, *this)
      , DeleteSync("DeleteSync", traits, *this)
      , IsSync("IsSync", traits, *this)
      , GetSynciv("GetSynciv", traits, *this)
      , WaitSync("WaitSync", traits, *this)
      , ClientWaitSync("ClientWaitSync", traits, *this)
      , GenVertexArrays("GenVertexArrays", traits, *this)
      , DeleteVertexArrays("DeleteVertexArrays", traits, *this)
      , IsVertexArray("IsVertexArray", traits, *this)
      , BindVertexArray("BindVertexArray", traits, *this)
      , GenBuffers("GenBuffers", traits, *this)
      , DeleteBuffers("DeleteBuffers", traits, *this)
      , IsBuffer("IsBuffer", traits, *this)
      , BindBuffer("BindBuffer", traits, *this)
      , BindBufferBase("BindBufferBase", traits, *this)
      , BindBufferRange("BindBufferRange", traits, *this)
      , BufferStorage("BufferStorage", traits, *this)
      , NamedBufferStorage("NamedBufferStorage", traits, *this)
      , BufferData("BufferData", traits, *this)
      , NamedBufferData("NamedBufferData", traits, *this)
      , BufferSubData("BufferSubData", traits, *this)
      , NamedBufferSubData("NamedBufferSubData", traits, *this)
      , ClearBufferData("ClearBufferData", traits, *this)
      , ClearNamedBufferData("ClearNamedBufferData", traits, *this)
      , ClearBufferSubData("ClearBufferSubData", traits, *this)
      , ClearNamedBufferSubData("ClearNamedBufferSubData", traits, *this)
      , MapBuffer("MapBuffer", traits, *this)
      , MapNamedBuffer("MapNamedBuffer", traits, *this)
      , MapBufferRange("MapBufferRange", traits, *this)
      , MapNamedBufferRange("MapNamedBufferRange", traits, *this)
      , FlushMappedBufferRange("FlushMappedBufferRange", traits, *this)
      , FlushMappedNamedBufferRange(
          "FlushMappedNamedBufferRange", traits, *this)
      , UnmapBuffer("UnmapBuffer", traits, *this)
      , UnmapNamedBuffer("UnmapNamedBuffer", traits, *this)
      , InvalidateBufferData("InvalidateBufferData", traits, *this)
      , InvalidateBufferSubData("InvalidateBufferSubData", traits, *this)
      , CopyBufferSubData("CopyBufferSubData", traits, *this)
      , CopyNamedBufferSubData("CopyNamedBufferSubData", traits, *this)
      , GetBufferParameteriv("GetBufferParameteriv", traits, *this)
      , GetBufferParameteri64v("GetBufferParameteri64v", traits, *this)
      , GetNamedBufferParameteriv("GetNamedBufferParameteriv", traits, *this)
      , GetNamedBufferParameteri64v(
          "GetNamedBufferParameteri64v", traits, *this)
      , GetBufferSubData("GetBufferSubData", traits, *this)
      , GetNamedBufferSubData("GetNamedBufferSubData", traits, *this)
      , GenTextures("GenTextures", traits, *this)
      , DeleteTextures("DeleteTextures", traits, *this)
      , IsTexture("IsTexture", traits, *this)
      , BindTexture("BindTexture", traits, *this)
      , GenSamplers("GenSamplers", traits, *this)
      , DeleteSamplers("DeleteSamplers", traits, *this)
      , IsSampler("IsSampler", traits, *this)
      , BindSampler("BindSampler", traits, *this)
      , GenRenderbuffers("GenRenderbuffers", traits, *this)
      , DeleteRenderbuffers("DeleteRenderbuffers", traits, *this)
      , IsRenderbuffer("IsRenderbuffer", traits, *this)
      , BindRenderbuffer("BindRenderbuffer", traits, *this)
      , GenFramebuffers("GenFramebuffers", traits, *this)
      , DeleteFramebuffers("DeleteFramebuffers", traits, *this)
      , IsFramebuffer("IsFramebuffer", traits, *this)
      , BindFramebuffer("BindFramebuffer", traits, *this)
      , GenTransformFeedbacks("GenTransformFeedbacks", traits, *this)
      , DeleteTransformFeedbacks("DeleteTransformFeedbacks", traits, *this)
      , IsTransformFeedback("IsTransformFeedback", traits, *this)
      , BindTransformFeedback("BindTransformFeedback", traits, *this)
      , GenQueries("GenQueries", traits, *this)
      , DeleteQueries("DeleteQueries", traits, *this)
      , IsQuery("IsQuery", traits, *this)
      , GetQueryiv("GetQueryiv", traits, *this)
      , GetQueryIndexediv("GetQueryIndexediv", traits, *this)
      , GetQueryObjectiv("GetQueryObjectiv", traits, *this)
      , GetQueryObjectuiv("GetQueryObjectuiv", traits, *this)
      , GetQueryObjecti64v("GetQueryObjecti64v", traits, *this)
      , GetQueryObjectui64v("GetQueryObjectui64v", traits, *this)
      , GetQueryBufferObjectiv("GetQueryBufferObjectiv", traits, *this)
      , GetQueryBufferObjectuiv("GetQueryBufferObjectuiv", traits, *this)
      , GetQueryBufferObjecti64v("GetQueryBufferObjecti64v", traits, *this)
      , GetQueryBufferObjectui64v("GetQueryBufferObjectui64v", traits, *this)
      , BeginQuery("BeginQuery", traits, *this)
      , BeginQueryIndexed("BeginQueryIndexed", traits, *this)
      , EndQuery("EndQuery", traits, *this)
      , EndQueryIndexed("EndQueryIndexed", traits, *this)
      , QueryCounter("QueryCounter", traits, *this)
      , GenProgramPipelines("GenProgramPipelines", traits, *this)
      , CreateProgramPipelines("CreateProgramPipelines", traits, *this)
      , DeleteProgramPipelines("DeleteProgramPipelines", traits, *this)
      , IsProgramPipeline("IsProgramPipeline", traits, *this)
      , BindProgramPipeline("BindProgramPipeline", traits, *this)
      , UseProgramStages("UseProgramStages", traits, *this)
      , ActiveShaderProgram("ActiveShaderProgram", traits, *this)
      , CreateShader("CreateShader", traits, *this)
      , DeleteShader("DeleteShader", traits, *this)
      , IsShader("IsShader", traits, *this)
      , ShaderSource("ShaderSource", traits, *this)
      , CompileShader("CompileShader", traits, *this)
      , ShaderBinary("ShaderBinary", traits, *this)
      , SpecializeShader("SpecializeShader", traits, *this)
      , GetShaderiv("GetShaderiv", traits, *this)
      , GetShaderInfoLog("GetShaderInfoLog", traits, *this)
      , GetShaderSource("GetShaderSource", traits, *this)
      , ReleaseShaderCompiler("ReleaseShaderCompiler", traits, *this)
      , CreateProgram("CreateProgram", traits, *this)
      , CreateShaderProgramv("CreateShaderProgramv", traits, *this)
      , DeleteProgram("DeleteProgram", traits, *this)
      , IsProgram("IsProgram", traits, *this)
      , AttachShader("AttachShader", traits, *this)
      , DetachShader("DetachShader", traits, *this)
      , GetAttachedShaders("GetAttachedShaders", traits, *this)
      , ValidateProgram("ValidateProgram", traits, *this)
      , LinkProgram("LinkProgram", traits, *this)
      , ProgramBinary("ProgramBinary", traits, *this)
      , GetProgramBinary("GetProgramBinary", traits, *this)
      , GetProgramiv("GetProgramiv", traits, *this)
      , GetProgramInfoLog("GetProgramInfoLog", traits, *this)
      , GetProgramInterfaceiv("GetProgramInterfaceiv", traits, *this)
      , GetProgramResourceIndex("GetProgramResourceIndex", traits, *this)
      , GetProgramResourceName("GetProgramResourceName", traits, *this)
      , GetProgramResourceLocation("GetProgramResourceLocation", traits, *this)
      , GetProgramResourceLocationIndex(
          "GetProgramResourceLocationIndex", traits, *this)
      , GetProgramResourceiv("GetProgramResourceiv", traits, *this)
      , UseProgram("UseProgram", traits, *this)
      , BindAttribLocation("BindAttribLocation", traits, *this)
      , GetAttribLocation("GetAttribLocation", traits, *this)
      , GetUniformLocation("GetUniformLocation", traits, *this)
      , BindFragDataLocation("BindFragDataLocation", traits, *this)
      , BindFragDataLocationIndexed(
          "BindFragDataLocationIndexed", traits, *this)
      , Uniform1i("Uniform1i", traits, *this)
      , Uniform2i("Uniform2i", traits, *this)
      , Uniform3i("Uniform3i", traits, *this)
      , Uniform4i("Uniform4i", traits, *this)
      , Uniform1iv("Uniform1iv", traits, *this)
      , Uniform2iv("Uniform2iv", traits, *this)
      , Uniform3iv("Uniform3iv", traits, *this)
      , Uniform4iv("Uniform4iv", traits, *this)
      , Uniform1ui("Uniform1ui", traits, *this)
      , Uniform2ui("Uniform2ui", traits, *this)
      , Uniform3ui("Uniform3ui", traits, *this)
      , Uniform4ui("Uniform4ui", traits, *this)
      , Uniform1uiv("Uniform1uiv", traits, *this)
      , Uniform2uiv("Uniform2uiv", traits, *this)
      , Uniform3uiv("Uniform3uiv", traits, *this)
      , Uniform4uiv("Uniform4uiv", traits, *this)
      , Uniform1f("Uniform1f", traits, *this)
      , Uniform2f("Uniform2f", traits, *this)
      , Uniform3f("Uniform3f", traits, *this)
      , Uniform4f("Uniform4f", traits, *this)
      , Uniform1fv("Uniform1fv", traits, *this)
      , Uniform2fv("Uniform2fv", traits, *this)
      , Uniform3fv("Uniform3fv", traits, *this)
      , Uniform4fv("Uniform4fv", traits, *this)
      , UniformMatrix2fv("UniformMatrix2fv", traits, *this)
      , UniformMatrix3fv("UniformMatrix3fv", traits, *this)
      , UniformMatrix4fv("UniformMatrix4fv", traits, *this)
      , UniformMatrix2x3fv("UniformMatrix2x3fv", traits, *this)
      , UniformMatrix3x2fv("UniformMatrix3x2fv", traits, *this)
      , UniformMatrix2x4fv("UniformMatrix2x4fv", traits, *this)
      , UniformMatrix4x2fv("UniformMatrix4x2fv", traits, *this)
      , UniformMatrix3x4fv("UniformMatrix3x4fv", traits, *this)
      , UniformMatrix4x3fv("UniformMatrix4x3fv", traits, *this)
      , DepthRange("DepthRange", traits, *this)
      , DepthRangef("DepthRangef", traits, *this)
      , Viewport("Viewport", traits, *this)
      , ClearColor("ClearColor", traits, *this)
      , ClearDepthf("ClearDepthf", traits, *this)
      , ClearDepth("ClearDepth", traits, *this)
      , ClearStencil("ClearStencil", traits, *this)
      , Clear("Clear", traits, *this)
      , GetBooleanv("GetBooleanv", traits, *this)
      , GetBooleani_v("GetBooleani_v", traits, *this)
      , GetIntegerv("GetIntegerv", traits, *this)
      , GetIntegeri_v("GetIntegeri_v", traits, *this)
      , GetInteger64v("GetInteger64v", traits, *this)
      , GetInteger64i_v("GetInteger64i_v", traits, *this)
      , GetFloatv("GetFloatv", traits, *this)
      , GetFloati_v("GetFloati_v", traits, *this)
      , GetDoublev("GetDoublev", traits, *this)
      , GetDoublei_v("GetDoublei_v", traits, *this)
      , GetString("GetString", traits, *this)
      , GetStringi("GetStringi", traits, *this)
      , Flush("Flush", traits, *this)
      , Finish("Finish", traits, *this) {
    }
};
//------------------------------------------------------------------------------
using gl_c_api = basic_gl_c_api<gl_api_traits>;
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_C_API_HPP

