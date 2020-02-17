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
#define OGLPLUS_GL_STATIC_FUNC(NAME) &EAGINE_JOIN(::gl, NAME)
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
    using sizei_type = typename gl_types::sizei_type;
    using bool_type = typename gl_types::bool_type;
    using char_type = typename gl_types::char_type;
    using byte_type = typename gl_types::byte_type;
    using ubyte_type = typename gl_types::ubyte_type;
    using int_type = typename gl_types::int_type;
    using uint_type = typename gl_types::uint_type;
    using int64_type = typename gl_types::int64_type;
    using enum_type = typename gl_types::enum_type;
    using float_type = typename gl_types::float_type;
    using double_type = typename gl_types::double_type;
    using bitfield_type = typename gl_types::bitfield_type;

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
      void(uint_type),
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
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BeginQuery)>
      BeginQuery;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(EndQuery)> EndQuery;

    //
    gl_api_function<uint_type(enum_type), OGLPLUS_GL_STATIC_FUNC(CreateShader)>
      CreateShader;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(DeleteShader)>
      DeleteShader;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsShader)>
      IsShader;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(CompileShader)>
      CompileShader;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderiv)>
      GetShaderiv;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderInfoLog)>
      GetShaderInfoLog;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderSource)>
      GetShaderSource;

    //
    gl_api_function<uint_type(enum_type), OGLPLUS_GL_STATIC_FUNC(CreateProgram)>
      CreateProgram;

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
      OGLPLUS_GL_STATIC_FUNC(GetAttachedShader)>
      GetAttachedShader;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(ValidateProgram)>
      ValidateProgram;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(LinkProgram)>
      LinkProgram;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramiv)>
      GetProgramiv;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramInfoLog)>
      GetProgramInfoLog;

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
      , GenVertexArrays("GenVertexArrays", traits, *this)
      , DeleteVertexArrays("DeleteVertexArrays", traits, *this)
      , IsVertexArray("IsVertexArray", traits, *this)
      , BindVertexArray("BindVertexArray", traits, *this)
      , GenBuffers("GenBuffers", traits, *this)
      , DeleteBuffers("DeleteBuffers", traits, *this)
      , IsBuffer("IsBuffer", traits, *this)
      , BindBuffer("BindBuffer", traits, *this)
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
      , BeginQuery("BeginQuery", traits, *this)
      , EndQuery("EndQuery", traits, *this)
      , CreateShader("CreateShader", traits, *this)
      , DeleteShader("DeleteShader", traits, *this)
      , IsShader("IsShader", traits, *this)
      , CompileShader("CompileShader", traits, *this)
      , GetShaderiv("GetShaderiv", traits, *this)
      , GetShaderInfoLog("GetShaderInfoLog", traits, *this)
      , GetShaderSource("GetShaderSource", traits, *this)
      , CreateProgram("CreateProgram", traits, *this)
      , DeleteProgram("DeleteProgram", traits, *this)
      , IsProgram("IsProgram", traits, *this)
      , AttachShader("AttachShader", traits, *this)
      , DetachShader("DetachShader", traits, *this)
      , GetAttachedShader("GetAttachedShader", traits, *this)
      , ValidateProgram("ValidateProgram", traits, *this)
      , LinkProgram("LinkProgram", traits, *this)
      , GetProgramiv("GetProgramiv", traits, *this)
      , GetProgramInfoLog("GetProgramInfoLog", traits, *this)
      , UseProgram("UseProgram", traits, *this)
      , BindAttribLocation("BindAttribLocation", traits, *this)
      , GetAttribLocation("GetAttribLocation", traits, *this)
      , GetUniformLocation("GetUniformLocation", traits, *this)
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

