/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
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

namespace eagine::oglp {
//------------------------------------------------------------------------------
/// @brief Class wrapping the C-functions from the GL API.
/// @ingroup gl_api_wrap
/// @see basic_gl_constants
/// @see basic_gl_operations
template <typename ApiTraits>
class basic_gl_c_api {
public:
    using this_api = basic_gl_c_api;

    /// @brief Alias for the API traits policy type passed as template argument.
    using api_traits = ApiTraits;

    /// @brief Untyped non-const pointer type.
    using void_ptr_type = typename gl_types::void_ptr_type;
    /// @brief Untyped const pointer type.
    using const_void_ptr_type = typename gl_types::const_void_ptr_type;
    /// @brief Size integer type.
    using sizei_type = typename gl_types::sizei_type;
    /// @brief Size integer type.
    using sizeiptr_type = typename gl_types::sizeiptr_type;
    /// @brief Integer type that can represent pointer.
    using intptr_type = typename gl_types::intptr_type;
    /// @brief Boolean type.
    using bool_type = typename gl_types::bool_type;
    /// @brief String character type.
    using char_type = typename gl_types::char_type;
    /// @brief Byte type.
    using byte_type = typename gl_types::byte_type;
    /// @brief Unsigned byte type.
    using ubyte_type = typename gl_types::ubyte_type;
    /// @brief Signed short integer type.
    using short_type = typename gl_types::short_type;
    /// @brief Unsigned short integer type.
    using ushort_type = typename gl_types::ushort_type;
    /// @brief Signed integer type.
    using int_type = typename gl_types::int_type;
    /// @brief Unsigned integer type.
    using uint_type = typename gl_types::uint_type;
    /// @brief Signed 64-bit integer type.
    using int64_type = typename gl_types::int64_type;
    /// @brief Unsigned 64-bit integer type.
    using uint64_type = typename gl_types::uint64_type;
    /// @brief Enumerator value type.
    using enum_type = typename gl_types::enum_type;
    /// @brief Floating-point type.
    using float_type = typename gl_types::float_type;
    /// @brief Double-precision floating-point type.
    using double_type = typename gl_types::double_type;
    /// @brief Bitfield/bitset value types.
    using bitfield_type = typename gl_types::bitfield_type;
    /// @brief Sync handler type.
    using sync_type = typename gl_types::sync_type;

    /// @brief Alias for the debug callback function type.
    using debug_callback_type = void(
      enum_type,
      enum_type,
      uint_type,
      enum_type,
      sizei_type,
      const char_type*,
      const_void_ptr_type);

    /// @brief Alias for GL C-API function wrapper template.
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

    /// @var GetError
    /// @glfuncwrap{GetError}
    gl_api_function<enum_type(), OGLPLUS_GL_STATIC_FUNC(GetError)> GetError;

    /// @var GetGraphicsResetStatus
    /// @glfuncwrap{GetGraphicsResetStatus}
    gl_api_function<enum_type(), OGLPLUS_GL_STATIC_FUNC(GetGraphicsResetStatus)>
      GetGraphicsResetStatus;

    /// @var Enable
    /// @glfuncwrap{Enable}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(Enable)> Enable;

    /// @var Enablei
    /// @glfuncwrap{Enablei}
    gl_api_function<void(enum_type, uint_type), OGLPLUS_GL_STATIC_FUNC(Enablei)>
      Enablei;

    /// @var Disable
    /// @glfuncwrap{Disable}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(Disable)> Disable;

    /// @var Disablei
    /// @glfuncwrap{Disablei}
    gl_api_function<void(enum_type, uint_type), OGLPLUS_GL_STATIC_FUNC(Disablei)>
      Disablei;

    /// @var IsEnabled
    /// @glfuncwrap{IsEnabled}
    gl_api_function<bool_type(enum_type), OGLPLUS_GL_STATIC_FUNC(IsEnabled)>
      IsEnabled;

    /// @var IsEnabledi
    /// @glfuncwrap{IsEnabledi}
    gl_api_function<
      bool_type(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(IsEnabledi)>
      IsEnabledi;

    /// @var MemoryBarrier
    /// @glfuncwrap{MemoryBarrier}
    gl_api_function<void(bitfield_type), OGLPLUS_GL_STATIC_FUNC(MemoryBarrier)>
      MemoryBarrier;

    /// @var MemoryBarrierByRegion
    /// @glfuncwrap{MemoryBarrierByRegion}
    gl_api_function<
      void(bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(MemoryBarrierByRegion)>
      MemoryBarrierByRegion;

    // object ops

    /// @var FenceSync
    /// @glfuncwrap{FenceSync}
    gl_api_function<
      sync_type(enum_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(FenceSync)>
      FenceSync;

    /// @var DeleteSync
    /// @glfuncwrap{DeleteSync}
    gl_api_function<void(sync_type), OGLPLUS_GL_STATIC_FUNC(DeleteSync)>
      DeleteSync;

    /// @var IsSync
    /// @glfuncwrap{IsSync}
    gl_api_function<bool_type(sync_type), OGLPLUS_GL_STATIC_FUNC(IsSync)> IsSync;

    /// @var GetSynciv
    /// @glfuncwrap{GetSynciv}
    gl_api_function<
      void(sync_type, enum_type, sizei_type, sizei_type*, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSynciv)>
      GetSynciv;

    /// @var WaitSync
    /// @glfuncwrap{WaitSync}
    gl_api_function<
      void(sync_type, bitfield_type, uint64_type),
      OGLPLUS_GL_STATIC_FUNC(WaitSync)>
      WaitSync;

    /// @var ClientWaitSync
    /// @glfuncwrap{ClientWaitSync}
    gl_api_function<
      enum_type(sync_type, bitfield_type, uint64_type),
      OGLPLUS_GL_STATIC_FUNC(ClientWaitSync)>
      ClientWaitSync;

    /// @var GenVertexArrays
    /// @glfuncwrap{GenVertexArrays}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenVertexArrays)>
      GenVertexArrays;

    /// @var CreateVertexArrays
    /// @glfuncwrap{CreateVertexArrays}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateVertexArrays)>
      CreateVertexArrays;

    /// @var DeleteVertexArrays
    /// @glfuncwrap{DeleteVertexArrays}
    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteVertexArrays)>
      DeleteVertexArrays;

    /// @var IsVertexArray
    /// @glfuncwrap{IsVertexArray}
    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsVertexArray)>
      IsVertexArray;

    /// @var BindVertexArray
    /// @glfuncwrap{BindVertexArray}
    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(BindVertexArray)>
      BindVertexArray;

    /// @var VertexArrayElementBuffer
    /// @glfuncwrap{VertexArrayElementBuffer}
    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayElementBuffer)>
      VertexArrayElementBuffer;

    /// @var BindVertexBuffer
    /// @glfuncwrap{BindVertexBuffer}
    gl_api_function<
      void(uint_type, uint_type, intptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(BindVertexBuffer)>
      BindVertexBuffer;

    /// @var VertexArrayVertexBuffer
    /// @glfuncwrap{VertexArrayVertexBuffer}
    gl_api_function<
      void(uint_type, uint_type, uint_type, intptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayVertexBuffer)>
      VertexArrayVertexBuffer;

    /// @var BindVertexBuffers
    /// @glfuncwrap{BindVertexBuffers}
    gl_api_function<
      void(
        uint_type,
        sizei_type,
        const uint_type*,
        const intptr_type*,
        const sizei_type*),
      OGLPLUS_GL_STATIC_FUNC(BindVertexBuffers)>
      BindVertexBuffers;

    /// @var VertexArrayVertexBuffers
    /// @glfuncwrap{VertexArrayVertexBuffers}
    gl_api_function<
      void(
        uint_type,
        uint_type,
        sizei_type,
        const uint_type*,
        const intptr_type*,
        const sizei_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayVertexBuffers)>
      VertexArrayVertexBuffers;

    /// @var VertexAttribBinding
    /// @glfuncwrap{VertexAttribBinding}
    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribBinding)>
      VertexAttribBinding;

    /// @var VertexArrayAttribBinding
    /// @glfuncwrap{VertexArrayAttribBinding}
    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayAttribBinding)>
      VertexArrayAttribBinding;

    /// @var EnableVertexAttribArray
    /// @glfuncwrap{EnableVertexAttribArray}
    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(EnableVertexAttribArray)>
      EnableVertexAttribArray;

    /// @var EnableVertexArrayAttrib
    /// @glfuncwrap{EnableVertexArrayAttrib}
    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(EnableVertexArrayAttrib)>
      EnableVertexArrayAttrib;

    /// @var DisableVertexAttribArray
    /// @glfuncwrap{DisableVertexAttribArray}
    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(DisableVertexAttribArray)>
      DisableVertexAttribArray;

    /// @var DisableVertexArrayAttrib
    /// @glfuncwrap{GetError}
    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DisableVertexArrayAttrib)>
      DisableVertexArrayAttrib;

    /// @var VertexBindingDivisor
    /// @glfuncwrap{VertexBindingDivisor}
    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexBindingDivisor)>
      VertexBindingDivisor;

    /// @var VertexArrayBindingDivisor
    /// @glfuncwrap{VertexArrayBindingDivisor}
    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayBindingDivisor)>
      VertexArrayBindingDivisor;

    /// @var VertexAttribDivisor
    /// @glfuncwrap{VertexAttribDivisor}
    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribDivisor)>
      VertexAttribDivisor;

    /// @var GenBuffers
    /// @glfuncwrap{GenBuffers}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenBuffers)>
      GenBuffers;

    /// @var CreateBuffers
    /// @glfuncwrap{CreateBuffers}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateBuffers)>
      CreateBuffers;

    /// @var DeleteBuffers
    /// @glfuncwrap{DeleteBuffers}
    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteBuffers)>
      DeleteBuffers;

    /// @var IsBuffer
    /// @glfuncwrap{IsBuffer}
    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsBuffer)>
      IsBuffer;

    /// @var BindBuffer
    /// @glfuncwrap{BindBuffer}
    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindBuffer)>
      BindBuffer;

    /// @var BindBufferBase
    /// @glfuncwrap{BindBufferBase}
    gl_api_function<
      void(enum_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindBufferBase)>
      BindBufferBase;

    /// @var BindBufferRange
    /// @glfuncwrap{BindBufferRange}
    gl_api_function<
      void(enum_type, uint_type, uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(BindBufferRange)>
      BindBufferRange;

    /// @var BufferStorage
    /// @glfuncwrap{BufferStorage}
    gl_api_function<
      void(enum_type, sizeiptr_type, const_void_ptr_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(BufferStorage)>
      BufferStorage;

    /// @var NamedBufferStorage
    /// @glfuncwrap{NamedBufferStorage}
    gl_api_function<
      void(uint_type, sizeiptr_type, const_void_ptr_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(BufferStorage)>
      NamedBufferStorage;

    /// @var BufferData
    /// @glfuncwrap{BufferData}
    gl_api_function<
      void(enum_type, sizeiptr_type, const_void_ptr_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BufferData)>
      BufferData;

    /// @var NamedBufferData
    /// @glfuncwrap{NamedBufferData}
    gl_api_function<
      void(uint_type, sizeiptr_type, const_void_ptr_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(NamedBufferData)>
      NamedBufferData;

    /// @var BufferSubData
    /// @glfuncwrap{BufferSubData}
    gl_api_function<
      void(enum_type, intptr_type, sizeiptr_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(BufferSubData)>
      BufferSubData;

    /// @var NamedBufferSubData
    /// @glfuncwrap{NamedBufferSubData}
    gl_api_function<
      void(uint_type, intptr_type, sizeiptr_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(NamedBufferSubData)>
      NamedBufferSubData;

    /// @var ClearBufferSubData
    /// @glfuncwrap{ClearBufferSubData}
    gl_api_function<
      void(enum_type, enum_type, enum_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferData)>
      ClearBufferData;

    /// @var ClearNamedBufferData
    /// @glfuncwrap{ClearNamedBufferData}
    gl_api_function<
      void(uint_type, enum_type, enum_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedBufferData)>
      ClearNamedBufferData;

    /// @var ClearBufferSubData
    /// @glfuncwrap{ClearBufferSubData}
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

    /// @var ClearNamedBufferSubData
    /// @glfuncwrap{ClearNamedBufferSubData}
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

    /// @var MapBuffer
    /// @glfuncwrap{MapBuffer}
    gl_api_function<
      void_ptr_type(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(MapBuffer)>
      MapBuffer;

    /// @var MapNamedBuffer
    /// @glfuncwrap{MapNamedBuffer}
    gl_api_function<
      void_ptr_type(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(MapNamedBuffer)>
      MapNamedBuffer;

    /// @var MapBufferRange
    /// @glfuncwrap{MapBufferRange}
    gl_api_function<
      void_ptr_type(enum_type, intptr_type, sizeiptr_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(MapBufferRange)>
      MapBufferRange;

    /// @var MapNamedBufferRange
    /// @glfuncwrap{MapNamedBufferRange}
    gl_api_function<
      void_ptr_type(uint_type, intptr_type, sizeiptr_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(MapNamedBufferRange)>
      MapNamedBufferRange;

    /// @var FlushMappedBufferRange
    /// @glfuncwrap{FlushMappedBufferRange}
    gl_api_function<
      void(enum_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(FlushMappedBufferRange)>
      FlushMappedBufferRange;

    /// @var FlushMappedNamedBufferRange
    /// @glfuncwrap{FlushMappedNamedBufferRange}
    gl_api_function<
      void(uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(FlushMappedNamedBufferRange)>
      FlushMappedNamedBufferRange;

    /// @var UnmapBuffer
    /// @glfuncwrap{UnmapBuffer}
    gl_api_function<bool_type(enum_type), OGLPLUS_GL_STATIC_FUNC(UnmapBuffer)>
      UnmapBuffer;

    /// @var UnmapNamedBuffer
    /// @glfuncwrap{UnmapNamedBuffer}
    gl_api_function<
      bool_type(uint_type),
      OGLPLUS_GL_STATIC_FUNC(UnmapNamedBuffer)>
      UnmapNamedBuffer;

    /// @var InvalidateBufferData
    /// @glfuncwrap{InvalidateBufferData}
    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(InvalidateBufferData)>
      InvalidateBufferData;

    /// @var InvalidateBufferSubData
    /// @glfuncwrap{InvalidateBufferSubData}
    gl_api_function<
      void(uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateBufferSubData)>
      InvalidateBufferSubData;

    /// @var CopyBufferSubData
    /// @glfuncwrap{CopyBufferSubData}
    gl_api_function<
      void(enum_type, enum_type, intptr_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(CopyBufferSubData)>
      CopyBufferSubData;

    /// @var CopyNamedBufferSubData
    /// @glfuncwrap{CopyNamedBufferSubData}
    gl_api_function<
      void(uint_type, uint_type, intptr_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(CopyNamedBufferSubData)>
      CopyNamedBufferSubData;

    /// @var GetBufferParameteriv
    /// @glfuncwrap{GetBufferParameteriv}
    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetBufferParameteriv)>
      GetBufferParameteriv;

    /// @var GetBufferParameteri64v
    /// @glfuncwrap{GetBufferParameteri64v}
    gl_api_function<
      void(enum_type, enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetBufferParameteri64v)>
      GetBufferParameteri64v;

    /// @var GetNamedBufferParameteriv
    /// @glfuncwrap{GetNamedBufferParameteriv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedBufferParameteriv)>
      GetNamedBufferParameteriv;

    /// @var GetNamedBufferParameteri64v
    /// @glfuncwrap{GetNamedBufferParameteri64v}
    gl_api_function<
      void(uint_type, enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedBufferParameteri64v)>
      GetNamedBufferParameteri64v;

    /// @var GetBufferSubData
    /// @glfuncwrap{GetBufferSubData}
    gl_api_function<
      void(enum_type, intptr_type, sizeiptr_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetBufferSubData)>
      GetBufferSubData;

    /// @var GetNamedBufferSubData
    /// @glfuncwrap{GetNamedBufferSubData}
    gl_api_function<
      void(uint_type, intptr_type, sizeiptr_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetNamedBufferSubData)>
      GetNamedBufferSubData;

    /// @var GenTextures
    /// @glfuncwrap{GenTextures}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenTextures)>
      GenTextures;

    /// @var CreateTextures
    /// @glfuncwrap{CreateTextures}
    gl_api_function<
      void(enum_type, sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateTextures)>
      CreateTextures;

    /// @var DeleteTextures
    /// @glfuncwrap{DeleteTextures}
    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteTextures)>
      DeleteTextures;

    /// @var IsTexture
    /// @glfuncwrap{IsTexture}
    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsTexture)>
      IsTexture;

    /// @var ActiveTexture
    /// @glfuncwrap{ActiveTexture}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(ActiveTexture)>
      ActiveTexture;

    /// @var BindTexture
    /// @glfuncwrap{BindTexture}
    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindTexture)>
      BindTexture;

    /// @var BindTextures
    /// @glfuncwrap{BindTextures}
    gl_api_function<
      void(uint_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(BindTextures)>
      BindTextures;

    /// @var BindTextureUnit
    /// @glfuncwrap{BindTextureUnit}
    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindTextureUnit)>
      BindTextureUnit;

    /// @var BindImageTexture
    /// @glfuncwrap{BindImageTexture}
    gl_api_function<
      void(uint_type, uint_type, int_type, bool_type, int_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BindImageTexture)>
      BindImageTexture;

    /// @var BindImageTextures
    /// @glfuncwrap{BindImageTextures}
    gl_api_function<
      void(uint_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(BindImageTextures)>
      BindImageTextures;

    /// @var TexStorage3D
    /// @glfuncwrap{TexStorage3D}
    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage3D)>
      TexStorage3D;

    /// @var TexStorage2D
    /// @glfuncwrap{TexStorage2D}
    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage2D)>
      TexStorage2D;

    /// @var TexStorage1D
    /// @glfuncwrap{TexStorage1D}
    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage1D)>
      TexStorage1D;

    /// @var TexStorage3DMultisample
    /// @glfuncwrap{TexStorage3DMultisample}
    gl_api_function<
      void(
        enum_type,
        sizei_type,
        enum_type,
        sizei_type,
        sizei_type,
        sizei_type,
        bool_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage3DMultisample)>
      TexStorage3DMultisample;

    /// @var TexStorage2DMultisample
    /// @glfuncwrap{TexStorage2DMultisample}
    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage2DMultisample)>
      TexStorage2DMultisample;

    /// @var TexImage3D
    /// @glfuncwrap{TexImage3D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        int_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexImage3D)>
      TexImage3D;

    /// @var TexImage2D
    /// @glfuncwrap{TexImage2D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        int_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexImage2D)>
      TexImage2D;

    /// @var TexImage1D
    /// @glfuncwrap{TexImage1D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        sizei_type,
        int_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexImage1D)>
      TexImage1D;

    /// @var CopyTexImage2D
    /// @glfuncwrap{CopyTexImage2D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        enum_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        int_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTexImage2D)>
      CopyTexImage2D;

    /// @var CopyTexImage1D
    /// @glfuncwrap{CopyTexImage1D}
    gl_api_function<
      void(enum_type, int_type, enum_type, int_type, int_type, sizei_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTexImage1D)>
      CopyTexImage1D;

    /// @var TexSubImage3D
    /// @glfuncwrap{TexSubImage3D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexSubImage3D)>
      TexSubImage3D;

    /// @var TexSubImage2D
    /// @glfuncwrap{TexSubImage2D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexSubImage2D)>
      TexSubImage2D;

    /// @var TexSubImage1D
    /// @glfuncwrap{TexSubImage1D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexSubImage1D)>
      TexSubImage1D;

    /// @var CopyTexSubImage3D
    /// @glfuncwrap{CopyTexSubImage3D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTexSubImage3D)>
      CopyTexSubImage3D;

    /// @var CopyTexSubImage2D
    /// @glfuncwrap{CopyTexSubImage2D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTexSubImage2D)>
      CopyTexSubImage2D;

    /// @var CopyTexSubImage1D
    /// @glfuncwrap{CopyTexSubImage1D}
    gl_api_function<
      void(enum_type, int_type, int_type, int_type, int_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTexSubImage1D)>
      CopyTexSubImage1D;

    /// @var TextureStorage3D
    /// @glfuncwrap{TextureStorage3D}
    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage3D)>
      TextureStorage3D;

    /// @var TextureStorage2D
    /// @glfuncwrap{TextureStorage2D}
    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage2D)>
      TextureStorage2D;

    /// @var TextureStorage1D
    /// @glfuncwrap{TextureStorage1D}
    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage1D)>
      TextureStorage1D;

    /// @var TextureStorage3DMultisample
    /// @glfuncwrap{TextureStorage3DMultisample}
    gl_api_function<
      void(
        uint_type,
        sizei_type,
        enum_type,
        sizei_type,
        sizei_type,
        sizei_type,
        bool_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage3DMultisample)>
      TextureStorage3DMultisample;

    /// @var TextureStorage2DMultisample
    /// @glfuncwrap{TextureStorage2DMultisample}
    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type, sizei_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage2DMultisample)>
      TextureStorage2DMultisample;

    /// @var TextureSubImage3D
    /// @glfuncwrap{TextureSubImage3D}
    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TextureSubImage3D)>
      TextureSubImage3D;

    /// @var TextureSubImage2D
    /// @glfuncwrap{TextureSubImage2D}
    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TextureSubImage2D)>
      TextureSubImage2D;

    /// @var TextureSubImage1D
    /// @glfuncwrap{TextureSubImage1D}
    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(TextureSubImage1D)>
      TextureSubImage1D;

    /// @var CopyTextureSubImage3D
    /// @glfuncwrap{CopyTextureSubImage3D}
    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTextureSubImage3D)>
      CopyTextureSubImage3D;

    /// @var CopyTextureSubImage2D
    /// @glfuncwrap{CopyTextureSubImage2D}
    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTextureSubImage2D)>
      CopyTextureSubImage2D;

    /// @var CopyTextureSubImage1D
    /// @glfuncwrap{CopyTextureSubImage1D}
    gl_api_function<
      void(uint_type, int_type, int_type, int_type, int_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTextureSubImage1D)>
      CopyTextureSubImage1D;

    /// @var CompressedTexImage3D
    /// @glfuncwrap{CompressedTexImage3D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        enum_type,
        sizei_type,
        sizei_type,
        sizei_type,
        int_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTexImage3D)>
      CompressedTexImage3D;

    /// @var CompressedTexImage2D
    /// @glfuncwrap{CompressedTexImage2D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        enum_type,
        sizei_type,
        sizei_type,
        int_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTexImage2D)>
      CompressedTexImage2D;

    /// @var CompressedTexImage1D
    /// @glfuncwrap{CompressedTexImage1D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        enum_type,
        sizei_type,
        int_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTexImage1D)>
      CompressedTexImage1D;

    /// @var CompressedTexSubImage3D
    /// @glfuncwrap{CompressedTexSubImage3D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        enum_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTexSubImage3D)>
      CompressedTexSubImage3D;

    /// @var CompressedTexSubImage2D
    /// @glfuncwrap{CompressedTexSubImage2D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        enum_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTexSubImage2D)>
      CompressedTexSubImage2D;

    /// @var CompressedTexSubImage1D
    /// @glfuncwrap{CompressedTexSubImage1D}
    gl_api_function<
      void(
        enum_type,
        int_type,
        int_type,
        sizei_type,
        enum_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTexSubImage1D)>
      CompressedTexSubImage1D;

    /// @var CompressedTextureSubImage3D
    /// @glfuncwrap{CompressedTextureSubImage3D}
    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        enum_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTextureSubImage3D)>
      CompressedTextureSubImage3D;

    /// @var CompressedTextureSubImage2D
    /// @glfuncwrap{CompressedTextureSubImage2D}
    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        enum_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTextureSubImage2D)>
      CompressedTextureSubImage2D;

    /// @var CompressedTextureSubImage1D
    /// @glfuncwrap{CompressedTextureSubImage1D}
    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        sizei_type,
        enum_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(CompressedTextureSubImage1D)>
      CompressedTextureSubImage1D;

    /// @var TexImage3DMultisample
    /// @glfuncwrap{TexImage3DMultisample}
    gl_api_function<
      void(
        enum_type,
        sizei_type,
        enum_type,
        sizei_type,
        sizei_type,
        sizei_type,
        bool_type),
      OGLPLUS_GL_STATIC_FUNC(TexImage3DMultisample)>
      TexImage3DMultisample;

    /// @var TexImage2DMultisample
    /// @glfuncwrap{TexImage2DMultisample}
    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(TexImage2DMultisample)>
      TexImage2DMultisample;

    /// @var TexBuffer
    /// @glfuncwrap{TexBuffer}
    gl_api_function<
      void(enum_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(TexBuffer)>
      TexBuffer;

    /// @var TexBufferRange
    /// @glfuncwrap{TexBufferRange}
    gl_api_function<
      void(enum_type, enum_type, uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexBufferRange)>
      TexBufferRange;

    /// @var TextureBuffer
    /// @glfuncwrap{TextureBuffer}
    gl_api_function<
      void(uint_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(TextureBuffer)>
      TextureBuffer;

    /// @var TextureBufferRange
    /// @glfuncwrap{TextureBufferRange}
    gl_api_function<
      void(uint_type, enum_type, uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(TextureBufferRange)>
      TextureBufferRange;

    /// @var TexParameterf
    /// @glfuncwrap{TexParameterf}
    gl_api_function<
      void(enum_type, enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(TexParameterf)>
      TexParameterf;

    /// @var TexParameteri
    /// @glfuncwrap{TexParameteri}
    gl_api_function<
      void(enum_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(TexParameteri)>
      TexParameteri;

    /// @var TexParameterfv
    /// @glfuncwrap{TexParameterfv}
    gl_api_function<
      void(enum_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(TexParameterfv)>
      TexParameterfv;

    /// @var TexParameteriv
    /// @glfuncwrap{TexParameteriv}
    gl_api_function<
      void(enum_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(TexParameteriv)>
      TexParameteriv;

    /// @var TexParameterIiv
    /// @glfuncwrap{TexParameterIiv}
    gl_api_function<
      void(enum_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(TexParameterIiv)>
      TexParameterIiv;

    /// @var TexParameterIuiv
    /// @glfuncwrap{TexParameterIuiv}
    gl_api_function<
      void(enum_type, enum_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(TexParameterIuiv)>
      TexParameterIuiv;

    /// @var TextureParameterf
    /// @glfuncwrap{TextureParameterf}
    gl_api_function<
      void(uint_type, enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(TextureParameterf)>
      TextureParameterf;

    /// @var TextureParameteri
    /// @glfuncwrap{TextureParameteri}
    gl_api_function<
      void(uint_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(TextureParameteri)>
      TextureParameteri;

    /// @var TextureParameterfv
    /// @glfuncwrap{TextureParameterfv}
    gl_api_function<
      void(uint_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(TextureParameterfv)>
      TextureParameterfv;

    /// @var TextureParameteriv
    /// @glfuncwrap{TextureParameteriv}
    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(TextureParameteriv)>
      TextureParameteriv;

    /// @var TextureParameterIiv
    /// @glfuncwrap{TextureParameterIiv}
    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(TextureParameterIiv)>
      TextureParameterIiv;

    /// @var TextureParameterIuiv
    /// @glfuncwrap{TextureParameterIuiv}
    gl_api_function<
      void(uint_type, enum_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(TextureParameterIuiv)>
      TextureParameterIuiv;

    /// @var GetTexParameterfv
    /// @glfuncwrap{GetTexParameterfv}
    gl_api_function<
      void(enum_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexParameterfv)>
      GetTexParameterfv;

    /// @var GetTexParameteriv
    /// @glfuncwrap{GetTexParameteriv}
    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexParameteriv)>
      GetTexParameteriv;

    /// @var GetTexParameterIiv
    /// @glfuncwrap{GetTexParameterIiv}
    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexParameterIiv)>
      GetTexParameterIiv;

    /// @var GetTexParameterIuiv
    /// @glfuncwrap{GetTexParameterIuiv}
    gl_api_function<
      void(enum_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexParameterIuiv)>
      GetTexParameterIuiv;

    /// @var GetTexLevelParameterfv
    /// @glfuncwrap{GetTexLevelParameterfv}
    gl_api_function<
      void(enum_type, int_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexLevelParameterfv)>
      GetTexLevelParameterfv;

    /// @var GetTexLevelParameteriv
    /// @glfuncwrap{GetTexLevelParameteriv}
    gl_api_function<
      void(enum_type, int_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexLevelParameteriv)>
      GetTexLevelParameteriv;

    /// @var GetTexImage
    /// @glfuncwrap{GetTexImage}
    gl_api_function<
      void(enum_type, int_type, enum_type, enum_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetTexImage)>
      GetTexImage;

    /// @var GetnTexImage
    /// @glfuncwrap{GetnTexImage}
    gl_api_function<
      void(enum_type, int_type, enum_type, enum_type, sizei_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetnTexImage)>
      GetnTexImage;

    /// @var GetCompressedTexImage
    /// @glfuncwrap{GetCompressedTexImage}
    gl_api_function<
      void(enum_type, int_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetCompressedTexImage)>
      GetCompressedTexImage;

    /// @var GetnCompressedTexImage
    /// @glfuncwrap{GetnCompressedTexImage}
    gl_api_function<
      void(enum_type, int_type, sizei_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetnCompressedTexImage)>
      GetnCompressedTexImage;

    /// @var GetTextureParameterfv
    /// @glfuncwrap{GetTextureParameterfv}
    gl_api_function<
      void(uint_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureParameterfv)>
      GetTextureParameterfv;

    /// @var GetTextureParameteriv
    /// @glfuncwrap{GetTextureParameteriv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureParameteriv)>
      GetTextureParameteriv;

    /// @var GetTextureParameterIiv
    /// @glfuncwrap{GetTextureParameterIiv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureParameterIiv)>
      GetTextureParameterIiv;

    /// @var GetTextureParameterIuiv
    /// @glfuncwrap{GetTextureParameterIuiv}
    gl_api_function<
      void(uint_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureParameterIuiv)>
      GetTextureParameterIuiv;

    /// @var GetTextureLevelParameterfv
    /// @glfuncwrap{GetTextureLevelParameterfv}
    gl_api_function<
      void(uint_type, int_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureLevelParameterfv)>
      GetTextureLevelParameterfv;

    /// @var GetTextureLevelParameteriv
    /// @glfuncwrap{GetTextureLevelParameteriv}
    gl_api_function<
      void(uint_type, int_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureLevelParameteriv)>
      GetTextureLevelParameteriv;

    /// @var GetTextureImage
    /// @glfuncwrap{GetTextureImage}
    gl_api_function<
      void(uint_type, int_type, enum_type, enum_type, sizei_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetTextureImage)>
      GetTextureImage;

    /// @var GetTextureSubImage
    /// @glfuncwrap{GetTextureSubImage}
    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        sizei_type,
        void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetTextureSubImage)>
      GetTextureSubImage;

    /// @var GetCompressedTextureImage
    /// @glfuncwrap{GetCompressedTextureImage}
    gl_api_function<
      void(uint_type, int_type, sizei_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetCompressedTextureImage)>
      GetCompressedTextureImage;

    /// @var GetCompressedTextureSubImage
    /// @glfuncwrap{GetCompressedTextureSubImage}
    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        sizei_type,
        void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetCompressedTextureSubImage)>
      GetCompressedTextureSubImage;

    /// @var GenerateMipmap
    /// @glfuncwrap{GenerateMipmap}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(GenerateMipmap)>
      GenerateMipmap;

    /// @var GenerateTextureMipmap
    /// @glfuncwrap{GenerateTextureMipmap}
    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(GenerateTextureMipmap)>
      GenerateTextureMipmap;

    /// @var TextureView
    /// @glfuncwrap{TextureView}
    gl_api_function<
      void(
        uint_type,
        enum_type,
        uint_type,
        enum_type,
        uint_type,
        uint_type,
        uint_type,
        uint_type),
      OGLPLUS_GL_STATIC_FUNC(TextureView)>
      TextureView;

    /// @var InvalidateTexSubImage
    /// @glfuncwrap{InvalidateTexSubImage}
    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateTexSubImage)>
      InvalidateTexSubImage;

    /// @var InvalidateTexImage
    /// @glfuncwrap{InvalidateTexImage}
    gl_api_function<
      void(uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateTexImage)>
      InvalidateTexImage;

    /// @var ClearTexSubImage
    /// @glfuncwrap{ClearTexSubImage}
    gl_api_function<
      void(
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearTexSubImage)>
      ClearTexSubImage;

    /// @var ClearTexImage
    /// @glfuncwrap{ClearTexImage}
    gl_api_function<
      void(uint_type, int_type, enum_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearTexImage)>
      ClearTexImage;

    /// @var TextureBarrier
    /// @glfuncwrap{TextureBarrier}
    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(TextureBarrier)>
      TextureBarrier;

    /// @var GenSamplers
    /// @glfuncwrap{GenSamplers}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenSamplers)>
      GenSamplers;

    /// @var CreateSamplers
    /// @glfuncwrap{CreateSamplers}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateSamplers)>
      CreateSamplers;

    /// @var DeleteSamplers
    /// @glfuncwrap{DeleteSamplers}
    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteSamplers)>
      DeleteSamplers;

    /// @var IsSampler
    /// @glfuncwrap{IsSampler}
    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsSampler)>
      IsSampler;

    /// @var BindSampler
    /// @glfuncwrap{BindSampler}
    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindSampler)>
      BindSampler;

    /// @var BindSamplers
    /// @glfuncwrap{BindSamplers}
    gl_api_function<
      void(uint_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(BindSamplers)>
      BindSamplers;

    /// @var SamplerParameterf
    /// @glfuncwrap{SamplerParameterf}
    gl_api_function<
      void(uint_type, enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameterf)>
      SamplerParameterf;

    /// @var SamplerParameteri
    /// @glfuncwrap{SamplerParameteri}
    gl_api_function<
      void(uint_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameteri)>
      SamplerParameteri;

    /// @var SamplerParameterfv
    /// @glfuncwrap{SamplerParameterfv}
    gl_api_function<
      void(uint_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameterfv)>
      SamplerParameterfv;

    /// @var SamplerParameteriv
    /// @glfuncwrap{SamplerParameteriv}
    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameteriv)>
      SamplerParameteriv;

    /// @var SamplerParameterIiv
    /// @glfuncwrap{SamplerParameterIiv}
    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameterIiv)>
      SamplerParameterIiv;

    /// @var SamplerParameterIuiv
    /// @glfuncwrap{SamplerParameterIuiv}
    gl_api_function<
      void(uint_type, enum_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameterIuiv)>
      SamplerParameterIuiv;

    /// @var GetSamplerParameterfv
    /// @glfuncwrap{GetSamplerParameterfv}
    gl_api_function<
      void(uint_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSamplerParameterfv)>
      GetSamplerParameterfv;

    /// @var GetSamplerParameteriv
    /// @glfuncwrap{GetSamplerParameteriv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSamplerParameteriv)>
      GetSamplerParameteriv;

    /// @var GetSamplerParameterIiv
    /// @glfuncwrap{GetSamplerParameterIiv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSamplerParameterIiv)>
      GetSamplerParameterIiv;

    /// @var GetSamplerParameterIuiv
    /// @glfuncwrap{GetSamplerParameterIuiv}
    gl_api_function<
      void(uint_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSamplerParameterIuiv)>
      GetSamplerParameterIuiv;

    /// @var GenRenderbuffers
    /// @glfuncwrap{GenRenderbuffers}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenRenderbuffers)>
      GenRenderbuffers;

    /// @var CreateRenderbuffers
    /// @glfuncwrap{CreateRenderbuffers}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateRenderbuffers)>
      CreateRenderbuffers;

    /// @var DeleteRenderbuffers
    /// @glfuncwrap{DeleteRenderbuffers}
    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteRenderbuffers)>
      DeleteRenderbuffers;

    /// @var IsRenderbuffer
    /// @glfuncwrap{IsRenderbuffer}
    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsRenderbuffer)>
      IsRenderbuffer;

    /// @var BindRenderbuffer
    /// @glfuncwrap{BindRenderbuffer}
    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindRenderbuffer)>
      BindRenderbuffer;

    /// @var RenderbufferStorage
    /// @glfuncwrap{RenderbufferStorage}
    gl_api_function<
      void(enum_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(RenderbufferStorage)>
      RenderbufferStorage;

    /// @var NamedRenderbufferStorage
    /// @glfuncwrap{NamedRenderbufferStorage}
    gl_api_function<
      void(uint_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(NamedRenderbufferStorage)>
      NamedRenderbufferStorage;

    /// @var RenderbufferStorageMultisample
    /// @glfuncwrap{RenderbufferStorageMultisample}
    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(RenderbufferStorageMultisample)>
      RenderbufferStorageMultisample;

    /// @var NamedRenderbufferStorageMultisample
    /// @glfuncwrap{NamedRenderbufferStorageMultisample}
    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(NamedRenderbufferStorageMultisample)>
      NamedRenderbufferStorageMultisample;

    /// @var GetRenderbufferParameteriv
    /// @glfuncwrap{GetRenderbufferParameteriv}
    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetRenderbufferParameteriv)>
      GetRenderbufferParameteriv;

    /// @var GetNamedRenderbufferParameteriv
    /// @glfuncwrap{GetNamedRenderbufferParameteriv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedRenderbufferParameteriv)>
      GetNamedRenderbufferParameteriv;

    /// @var GenFramebuffers
    /// @glfuncwrap{GenFramebuffers}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenFramebuffers)>
      GenFramebuffers;

    /// @var CreateFramebuffers
    /// @glfuncwrap{CreateFramebuffers}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateFramebuffers)>
      CreateFramebuffers;

    /// @var DeleteFramebuffers
    /// @glfuncwrap{DeleteFramebuffers}
    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteFramebuffers)>
      DeleteFramebuffers;

    /// @var IsFramebuffer
    /// @glfuncwrap{IsFramebuffer}
    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsFramebuffer)>
      IsFramebuffer;

    /// @var BindFramebuffer
    /// @glfuncwrap{BindFramebuffer}
    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindFramebuffer)>
      BindFramebuffer;

    /// @var DrawBuffers
    /// @glfuncwrap{DrawBuffers}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(DrawBuffer)>
      DrawBuffer;

    /// @var NamedFramebufferDrawBuffer
    /// @glfuncwrap{NamedFramebufferDrawBuffer}
    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferDrawBuffer)>
      NamedFramebufferDrawBuffer;

    /// @var DrawBuffers
    /// @glfuncwrap{DrawBuffers}
    gl_api_function<
      void(sizei_type, const enum_type*),
      OGLPLUS_GL_STATIC_FUNC(DrawBuffers)>
      DrawBuffers;

    /// @var NamedFramebufferDrawBuffer
    /// @glfuncwrap{NamedFramebufferDrawBuffer}
    gl_api_function<
      void(uint_type, sizei_type, const enum_type*),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferDrawBuffers)>
      NamedFramebufferDrawBuffers;

    /// @var ClearBufferfv
    /// @glfuncwrap{ClearBufferfv}
    gl_api_function<
      void(enum_type, int_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferfv)>
      ClearBufferfv;

    /// @var ClearBufferiv
    /// @glfuncwrap{ClearBufferiv}
    gl_api_function<
      void(enum_type, int_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferiv)>
      ClearBufferiv;

    /// @var ClearBufferuiv
    /// @glfuncwrap{ClearBufferuiv}
    gl_api_function<
      void(enum_type, int_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferuiv)>
      ClearBufferuiv;

    /// @var ClearBufferfi
    /// @glfuncwrap{ClearBufferfi}
    gl_api_function<
      void(enum_type, int_type, float_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferfi)>
      ClearBufferfi;

    /// @var ClearNamedFramebufferfv
    /// @glfuncwrap{ClearNamedFramebufferfv}
    gl_api_function<
      void(uint_type, enum_type, int_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedFramebufferfv)>
      ClearNamedFramebufferfv;

    /// @var ClearNamedFramebufferiv
    /// @glfuncwrap{ClearNamedFramebufferiv}
    gl_api_function<
      void(uint_type, enum_type, int_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedFramebufferiv)>
      ClearNamedFramebufferiv;

    /// @var ClearNamedFramebufferuiv
    /// @glfuncwrap{ClearNamedFramebufferuiv}
    gl_api_function<
      void(uint_type, enum_type, int_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedFramebufferuiv)>
      ClearNamedFramebufferuiv;

    /// @var ClearNamedFramebufferfi
    /// @glfuncwrap{ClearNamedFramebufferfi}
    gl_api_function<
      void(uint_type, enum_type, int_type, float_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedFramebufferfi)>
      ClearNamedFramebufferfi;

    /// @var InvalidateFramebuffer
    /// @glfuncwrap{InvalidateFramebuffer}
    gl_api_function<
      void(enum_type, sizei_type, const enum_type*),
      OGLPLUS_GL_STATIC_FUNC(InvalidateFramebuffer)>
      InvalidateFramebuffer;

    /// @var InvalidateSubFramebuffer
    /// @glfuncwrap{InvalidateSubFramebuffer}
    gl_api_function<
      void(
        enum_type,
        sizei_type,
        const enum_type*,
        int_type,
        int_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateSubFramebuffer)>
      InvalidateSubFramebuffer;

    /// @var InvalidateNamedFramebufferData
    /// @glfuncwrap{InvalidateNamedFramebufferData}
    gl_api_function<
      void(uint_type, sizei_type, const enum_type*),
      OGLPLUS_GL_STATIC_FUNC(InvalidateFramebuffer)>
      InvalidateNamedFramebufferData;

    /// @var InvalidateNamedFramebufferSubData
    /// @glfuncwrap{InvalidateNamedFramebufferSubData}
    gl_api_function<
      void(
        uint_type,
        sizei_type,
        const enum_type*,
        int_type,
        int_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateNamedFramebufferSubData)>
      InvalidateNamedFramebufferSubData;

    /// @var FramebufferParameteri
    /// @glfuncwrap{FramebufferParameteri}
    gl_api_function<
      void(enum_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferParameteri)>
      FramebufferParameteri;

    /// @var NamedFramebufferParameteri
    /// @glfuncwrap{NamedFramebufferParameteri}
    gl_api_function<
      void(uint_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferParameteri)>
      NamedFramebufferParameteri;

    /// @var GetFramebufferParameteriv
    /// @glfuncwrap{GetFramebufferParameteriv}
    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFramebufferParameteriv)>
      GetFramebufferParameteriv;

    /// @var GetNamedFramebufferParameteriv
    /// @glfuncwrap{GetNamedFramebufferParameteriv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedFramebufferParameteriv)>
      GetNamedFramebufferParameteriv;

    /// @var GetFramebufferAttachmentParameteriv
    /// @glfuncwrap{GetFramebufferAttachmentParameteriv}
    gl_api_function<
      void(enum_type, enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFramebufferAttachmentParameteriv)>
      GetFramebufferAttachmentParameteriv;

    /// @var GetNamedFramebufferAttachmentParameteriv
    /// @glfuncwrap{GetNamedFramebufferAttachmentParameteriv}
    gl_api_function<
      void(uint_type, enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedFramebufferAttachmentParameteriv)>
      GetNamedFramebufferAttachmentParameteriv;

    /// @var FramebufferRenderbuffer
    /// @glfuncwrap{FramebufferRenderbuffer}
    gl_api_function<
      void(enum_type, enum_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferRenderbuffer)>
      FramebufferRenderbuffer;

    /// @var NamedFramebufferRenderbuffer
    /// @glfuncwrap{NamedFramebufferRenderbuffer}
    gl_api_function<
      void(uint_type, enum_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferRenderbuffer)>
      NamedFramebufferRenderbuffer;

    /// @var FramebufferTexture
    /// @glfuncwrap{FramebufferTexture}
    gl_api_function<
      void(enum_type, enum_type, uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTexture)>
      FramebufferTexture;

    /// @var NamedFramebufferTexture
    /// @glfuncwrap{NamedFramebufferTexture}
    gl_api_function<
      void(uint_type, enum_type, uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferTexture)>
      NamedFramebufferTexture;

    /// @var FramebufferTexture1D
    /// @glfuncwrap{FramebufferTexture1D}
    gl_api_function<
      void(enum_type, enum_type, enum_type, uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTexture1D)>
      FramebufferTexture1D;

    /// @var FramebufferTexture2D
    /// @glfuncwrap{FramebufferTexture2D}
    gl_api_function<
      void(enum_type, enum_type, enum_type, uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTexture2D)>
      FramebufferTexture2D;

    /// @var FramebufferTexture3D
    /// @glfuncwrap{FramebufferTexture3D}
    gl_api_function<
      void(enum_type, enum_type, enum_type, uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTexture3D)>
      FramebufferTexture3D;

    /// @var FramebufferTextureLayer
    /// @glfuncwrap{FramebufferTextureLayer}
    gl_api_function<
      void(enum_type, enum_type, uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTextureLayer)>
      FramebufferTextureLayer;

    /// @var NamedFramebufferTextureLayer
    /// @glfuncwrap{NamedFramebufferTextureLayer}
    gl_api_function<
      void(uint_type, enum_type, uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferTextureLayer)>
      NamedFramebufferTextureLayer;

    /// @var CheckFramebufferStatus
    /// @glfuncwrap{CheckFramebufferStatus}
    gl_api_function<
      enum_type(enum_type),
      OGLPLUS_GL_STATIC_FUNC(CheckFramebufferStatus)>
      CheckFramebufferStatus;

    /// @var CheckNamedFramebufferStatus
    /// @glfuncwrap{CheckNamedFramebufferStatus}
    gl_api_function<
      enum_type(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(CheckNamedFramebufferStatus)>
      CheckNamedFramebufferStatus;

    /// @var ReadBuffer
    /// @glfuncwrap{ReadBuffer}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(ReadBuffer)>
      ReadBuffer;

    /// @var NamedFramebufferReadBuffer
    /// @glfuncwrap{NamedFramebufferReadBuffer}
    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferReadBuffer)>
      NamedFramebufferReadBuffer;

    /// @var BlitFramebuffer
    /// @glfuncwrap{BlitFramebuffer}
    gl_api_function<
      void(
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        bitfield_type,
        enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlitFramebuffer)>
      BlitFramebuffer;

    /// @var BlitNamedFramebuffer
    /// @glfuncwrap{BlitNamedFramebuffer}
    gl_api_function<
      void(
        uint_type,
        uint_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        bitfield_type,
        enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlitNamedFramebuffer)>
      BlitNamedFramebuffer;

    /// @var CopyImageSubData
    /// @glfuncwrap{CopyImageSubData}
    gl_api_function<
      void(
        uint_type,
        enum_type,
        int_type,
        int_type,
        int_type,
        int_type,
        uint_type,
        enum_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyImageSubData)>
      CopyImageSubData;

    /// @var GenTransformFeedbacks
    /// @glfuncwrap{GenTransformFeedbacks}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenTransformFeedbacks)>
      GenTransformFeedbacks;

    /// @var CreateTransformFeedbacks
    /// @glfuncwrap{CreateTransformFeedbacks}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateTransformFeedbacks)>
      CreateTransformFeedbacks;

    /// @var DeleteTransformFeedbacks
    /// @glfuncwrap{DeleteTransformFeedbacks}
    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteTransformFeedbacks)>
      DeleteTransformFeedbacks;

    /// @var IsTransformFeedback
    /// @glfuncwrap{IsTransformFeedback}
    gl_api_function<
      bool_type(uint_type),
      OGLPLUS_GL_STATIC_FUNC(IsTransformFeedback)>
      IsTransformFeedback;

    /// @var BindTransformFeedback
    /// @glfuncwrap{BindTransformFeedback}
    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindTransformFeedback)>
      BindTransformFeedback;

    /// @var BeginTransformFeedback
    /// @glfuncwrap{BeginTransformFeedback}
    gl_api_function<
      void(enum_type),
      OGLPLUS_GL_STATIC_FUNC(BeginTransformFeedback)>
      BeginTransformFeedback;

    /// @var PauseTransformFeedback
    /// @glfuncwrap{PauseTransformFeedback}
    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(PauseTransformFeedback)>
      PauseTransformFeedback;

    /// @var ResumeTransformFeedback
    /// @glfuncwrap{ResumeTransformFeedback}
    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(ResumeTransformFeedback)>
      ResumeTransformFeedback;

    /// @var EndTransformFeedback
    /// @glfuncwrap{EndTransformFeedback}
    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(EndTransformFeedback)>
      EndTransformFeedback;

    /// @var TransformFeedbackBufferBase
    /// @glfuncwrap{TransformFeedbackBufferBase}
    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(TransformFeedbackBufferBase)>
      TransformFeedbackBufferBase;

    /// @var TransformFeedbackBufferRange
    /// @glfuncwrap{TransformFeedbackBufferRange}
    gl_api_function<
      void(uint_type, uint_type, uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(TransformFeedbackBufferRange)>
      TransformFeedbackBufferRange;

    /// @var GetTransformFeedbackiv
    /// @glfuncwrap{GetTransformFeedbackiv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTransformFeedbackiv)>
      GetTransformFeedbackiv;

    /// @var GetTransformFeedbacki_v
    /// @glfuncwrap{GetTransformFeedbacki_v}
    gl_api_function<
      void(uint_type, enum_type, uint_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTransformFeedbacki_v)>
      GetTransformFeedbacki_v;

    /// @var GetTransformFeedbacki64_v
    /// @glfuncwrap{GetTransformFeedbacki64_v}
    gl_api_function<
      void(uint_type, enum_type, uint_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTransformFeedbacki64_v)>
      GetTransformFeedbacki64_v;

    /// @var GenQueries
    /// @glfuncwrap{GenQueries}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenQueries)>
      GenQueries;

    /// @var CreateQueries
    /// @glfuncwrap{CreateQueries}
    gl_api_function<
      void(enum_type, sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateQueries)>
      CreateQueries;

    /// @var DeleteQueries
    /// @glfuncwrap{DeleteQueries}
    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteQueries)>
      DeleteQueries;

    /// @var IsQuery
    /// @glfuncwrap{IsQuery}
    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsQuery)>
      IsQuery;

    /// @var GetQueryiv
    /// @glfuncwrap{GetQueryiv}
    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryiv)>
      GetQueryiv;

    /// @var GetQueryIndexediv
    /// @glfuncwrap{GetQueryIndexediv}
    gl_api_function<
      void(enum_type, uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryIndexediv)>
      GetQueryIndexediv;

    /// @var GetQueryObjectiv
    /// @glfuncwrap{GetQueryObjectiv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryObjectiv)>
      GetQueryObjectiv;

    /// @var GetQueryObjectuiv
    /// @glfuncwrap{GetQueryObjectuiv}
    gl_api_function<
      void(uint_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryObjectuiv)>
      GetQueryObjectuiv;

    /// @var GetQueryObjecti64v
    /// @glfuncwrap{GetQueryObjecti64v}
    gl_api_function<
      void(uint_type, enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryObjecti64v)>
      GetQueryObjecti64v;

    /// @var GetQueryObjectui64v
    /// @glfuncwrap{GetQueryObjectui64v}
    gl_api_function<
      void(uint_type, enum_type, uint64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetQueryObjectui64v)>
      GetQueryObjectui64v;

    /// @var GetQueryBufferObjectiv
    /// @glfuncwrap{GetQueryBufferObjectiv}
    gl_api_function<
      void(uint_type, uint_type, enum_type, intptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetQueryBufferObjectiv)>
      GetQueryBufferObjectiv;

    /// @var GetQueryBufferObjectuiv
    /// @glfuncwrap{GetQueryBufferObjectuiv}
    gl_api_function<
      void(uint_type, uint_type, enum_type, intptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetQueryBufferObjectuiv)>
      GetQueryBufferObjectuiv;

    /// @var GetQueryBufferObjecti64v
    /// @glfuncwrap{GetQueryBufferObjecti64v}
    gl_api_function<
      void(uint_type, uint_type, enum_type, intptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetQueryBufferObjecti64v)>
      GetQueryBufferObjecti64v;

    /// @var GetQueryBufferObjectui64v
    /// @glfuncwrap{GetQueryBufferObjectui64v}
    gl_api_function<
      void(uint_type, uint_type, enum_type, intptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetQueryBufferObjectui64v)>
      GetQueryBufferObjectui64v;

    /// @var BeginQuery
    /// @glfuncwrap{BeginQuery}
    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BeginQuery)>
      BeginQuery;

    /// @var BeginQueryIndexed
    /// @glfuncwrap{BeginQueryIndexed}
    gl_api_function<
      void(enum_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BeginQueryIndexed)>
      BeginQueryIndexed;

    /// @var EndQuery
    /// @glfuncwrap{EndQuery}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(EndQuery)> EndQuery;

    /// @var EndQueryIndexed
    /// @glfuncwrap{EndQueryIndexed}
    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(EndQueryIndexed)>
      EndQueryIndexed;

    /// @var QueryCounter
    /// @glfuncwrap{QueryCounter}
    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(QueryCounter)>
      QueryCounter;

    /// @var BeginConditionalRender
    /// @glfuncwrap{BeginConditionalRender}
    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BeginConditionalRender)>
      BeginConditionalRender;

    /// @var EndConditionalRender
    /// @glfuncwrap{EndConditionalRender}
    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(EndConditionalRender)>
      EndConditionalRender;

    /// @var GenProgramPipelines
    /// @glfuncwrap{GenProgramPipelines}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenProgramPipelines)>
      GenProgramPipelines;

    /// @var CreateProgramPipelines
    /// @glfuncwrap{CreateProgramPipelines}
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateProgramPipelines)>
      CreateProgramPipelines;

    /// @var DeleteProgramPipelines
    /// @glfuncwrap{DeleteProgramPipelines}
    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteProgramPipelines)>
      DeleteProgramPipelines;

    /// @var IsProgramPipeline
    /// @glfuncwrap{IsProgramPipeline}
    gl_api_function<
      bool_type(uint_type),
      OGLPLUS_GL_STATIC_FUNC(IsProgramPipeline)>
      IsProgramPipeline;

    /// @var BindProgramPipeline
    /// @glfuncwrap{BindProgramPipeline}
    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(BindProgramPipeline)>
      BindProgramPipeline;

    /// @var ValidateProgramPipeline
    /// @glfuncwrap{ValidateProgramPipeline}
    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(ValidateProgramPipeline)>
      ValidateProgramPipeline;

    /// @var UseProgramStages
    /// @glfuncwrap{UseProgramStages}
    gl_api_function<
      void(uint_type, bitfield_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(UseProgramStages)>
      UseProgramStages;

    /// @var GetProgramStageiv
    /// @glfuncwrap{GetProgramStageiv}
    gl_api_function<
      void(uint_type, enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramStageiv)>
      GetProgramStageiv;

    /// @var GetProgramPipelineiv
    /// @glfuncwrap{GetProgramPipelineiv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramPipelineiv)>
      GetProgramPipelineiv;

    /// @var GetProgramPipelineInfoLog
    /// @glfuncwrap{GetProgramPipelineInfoLog}
    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramPipelineInfoLog)>
      GetProgramPipelineInfoLog;

    /// @var ActiveShaderProgram
    /// @glfuncwrap{ActiveShaderProgram}
    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ActiveShaderProgram)>
      ActiveShaderProgram;

    /// @var CreateShader
    /// @glfuncwrap{CreateShader}
    gl_api_function<uint_type(enum_type), OGLPLUS_GL_STATIC_FUNC(CreateShader)>
      CreateShader;

    /// @var DeleteShader
    /// @glfuncwrap{DeleteShader}
    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(DeleteShader)>
      DeleteShader;

    /// @var IsShader
    /// @glfuncwrap{IsShader}
    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsShader)>
      IsShader;

    /// @var ShaderSource
    /// @glfuncwrap{ShaderSource}
    gl_api_function<
      void(uint_type, sizei_type, const char_type* const*, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ShaderSource)>
      ShaderSource;

    /// @var CompileShader
    /// @glfuncwrap{CompileShader}
    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(CompileShader)>
      CompileShader;

    /// @var CompileShaderInclude
    /// @glfuncwrap{CompileShaderInclude}
    gl_api_function<
      void(uint_type, sizei_type, const char_type* const*, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(nullptr)>
      CompileShaderInclude;

    /// @var ShaderBinary
    /// @glfuncwrap{ShaderBinary}
    gl_api_function<
      void(sizei_type, const uint_type*, enum_type, const_void_ptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(ShaderBinary)>
      ShaderBinary;

    /// @var SpecializeShader
    /// @glfuncwrap{SpecializeShader}
    gl_api_function<
      void(
        uint_type,
        const char_type*,
        uint_type,
        const uint_type*,
        const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(SpecializeShader)>
      SpecializeShader;

    /// @var GetShaderiv
    /// @glfuncwrap{GetShaderiv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderiv)>
      GetShaderiv;

    /// @var GetShaderInfoLog
    /// @glfuncwrap{GetShaderInfoLog}
    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderInfoLog)>
      GetShaderInfoLog;

    /// @var GetShaderSource
    /// @glfuncwrap{GetShaderSource}
    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderSource)>
      GetShaderSource;

    /// @var GetShaderPrecisionFormat
    /// @glfuncwrap{GetShaderPrecisionFormat}
    gl_api_function<
      void(enum_type, enum_type, int_type*, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderPrecisionFormat)>
      GetShaderPrecisionFormat;

    /// @var ReleaseShaderCompiler
    /// @glfuncwrap{ReleaseShaderCompiler}
    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(ReleaseShaderCompiler)>
      ReleaseShaderCompiler;

    /// @var CreateProgram
    /// @glfuncwrap{CreateProgram}
    gl_api_function<uint_type(), OGLPLUS_GL_STATIC_FUNC(CreateProgram)>
      CreateProgram;

    /// @var CreateShaderProgramv
    /// @glfuncwrap{CreateShaderProgramv}
    gl_api_function<
      uint_type(enum_type, sizei_type, const char_type* const*),
      OGLPLUS_GL_STATIC_FUNC(CreateShaderProgramv)>
      CreateShaderProgramv;

    /// @var DeleteProgram
    /// @glfuncwrap{DeleteProgram}
    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(DeleteProgram)>
      DeleteProgram;

    /// @var IsProgram
    /// @glfuncwrap{IsProgram}
    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsProgram)>
      IsProgram;

    /// @var AttachShader
    /// @glfuncwrap{AttachShader}
    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(AttachShader)>
      AttachShader;

    /// @var DetachShader
    /// @glfuncwrap{DetachShader}
    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DetachShader)>
      DetachShader;

    /// @var GetAttachedShaders
    /// @glfuncwrap{GetAttachedShaders}
    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetAttachedShaders)>
      GetAttachedShaders;

    /// @var ValidateProgram
    /// @glfuncwrap{ValidateProgram}
    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(ValidateProgram)>
      ValidateProgram;

    /// @var LinkProgram
    /// @glfuncwrap{LinkProgram}
    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(LinkProgram)>
      LinkProgram;

    /// @var UseProgram
    /// @glfuncwrap{UseProgram}
    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(UseProgram)>
      UseProgram;

    /// @var ProgramBinary
    /// @glfuncwrap{ProgramBinary}
    gl_api_function<
      void(uint_type, enum_type, const_void_ptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramBinary)>
      ProgramBinary;

    /// @var GetProgramBinary
    /// @glfuncwrap{GetProgramBinary}
    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, enum_type*, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetProgramBinary)>
      GetProgramBinary;

    /// @var GetProgramiv
    /// @glfuncwrap{GetProgramiv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramiv)>
      GetProgramiv;

    /// @var GetProgramInfoLog
    /// @glfuncwrap{GetProgramInfoLog}
    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramInfoLog)>
      GetProgramInfoLog;

    /// @var GetProgramInterfaceiv
    /// @glfuncwrap{GetProgramInterfaceiv}
    gl_api_function<
      void(uint_type, enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramInterfaceiv)>
      GetProgramInterfaceiv;

    /// @var GetProgramResourceIndex
    /// @glfuncwrap{GetProgramResourceIndex}
    gl_api_function<
      uint_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceIndex)>
      GetProgramResourceIndex;

    /// @var GetProgramResourceName
    /// @glfuncwrap{GetProgramResourceName}
    gl_api_function<
      void(uint_type, enum_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceName)>
      GetProgramResourceName;

    /// @var GetProgramResourceLocation
    /// @glfuncwrap{GetProgramResourceLocation}
    gl_api_function<
      int_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceLocation)>
      GetProgramResourceLocation;

    /// @var GetProgramResourceLocationIndex
    /// @glfuncwrap{GetProgramResourceLocationIndex}
    gl_api_function<
      int_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourceLocationIndex)>
      GetProgramResourceLocationIndex;

    /// @var GetProgramResourceiv
    /// @glfuncwrap{GetProgramResourceiv}
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

    /// @var GetProgramResourcefvNV
    /// @glfuncwrap{GetProgramResourcefvNV}
    gl_api_function<
      void(
        uint_type,
        enum_type,
        uint_type,
        sizei_type,
        const enum_type*,
        sizei_type,
        sizei_type*,
        float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramResourcefvNV)>
      GetProgramResourcefvNV;

    /// @var BindAttribLocation
    /// @glfuncwrap{BindAttribLocation}
    gl_api_function<
      void(uint_type, uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(BindAttribLocation)>
      BindAttribLocation;

    /// @var GetAttribLocation
    /// @glfuncwrap{GetAttribLocation}
    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetAttribLocation)>
      GetAttribLocation;

    /// @var GetActiveAttrib
    /// @glfuncwrap{GetActiveAttrib}
    gl_api_function<
      void(
        uint_type,
        uint_type,
        sizei_type,
        sizei_type*,
        int_type*,
        enum_type*,
        char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveAttrib)>
      GetActiveAttrib;

    /// @var GetActiveUniformLocation
    /// @glfuncwrap{GetActiveUniformLocation}
    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformLocation)>
      GetUniformLocation;

    /// @var GetUniformBlockIndex
    /// @glfuncwrap{GetUniformBlockIndex}
    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformBlockIndex)>
      GetUniformBlockIndex;

    /// @var GetActiveUniformName
    /// @glfuncwrap{GetActiveUniformName}
    gl_api_function<
      void(uint_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveUniformName)>
      GetActiveUniformName;

    /// @var GetSubroutineIndex
    /// @glfuncwrap{GetSubroutineIndex}
    gl_api_function<
      uint_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSubroutineIndex)>
      GetSubroutineIndex;

    /// @var GetActiveSubroutineName
    /// @glfuncwrap{GetActiveSubroutineName}
    gl_api_function<
      void(uint_type, enum_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveSubroutineName)>
      GetActiveSubroutineName;

    /// @var GetActiveSubroutineUniformName
    /// @glfuncwrap{GetActiveSubroutineUniformName}
    gl_api_function<
      void(uint_type, enum_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveSubroutineUniformName)>
      GetActiveSubroutineUniformName;

    /// @var GetSubroutineUniformLocation
    /// @glfuncwrap{GetSubroutineUniformLocation}
    gl_api_function<
      int_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSubroutineUniformLocation)>
      GetSubroutineUniformLocation;

    /// @var GetActiveSubroutineUniformiv
    /// @glfuncwrap{GetActiveSubroutineUniformiv}
    gl_api_function<
      void(uint_type, enum_type, uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveSubroutineUniformiv)>
      GetActiveSubroutineUniformiv;

    /// @var TransformFeedbackVaryings
    /// @glfuncwrap{TransformFeedbackVaryings}
    gl_api_function<
      void(uint_type, sizei_type, const char_type* const*, enum_type),
      OGLPLUS_GL_STATIC_FUNC(TransformFeedbackVaryings)>
      TransformFeedbackVaryings;

    /// @var GetTransformFeedbackVarying
    /// @glfuncwrap{GetTransformFeedbackVarying}
    gl_api_function<
      void(
        uint_type,
        uint_type,
        sizei_type,
        sizei_type*,
        sizei_type*,
        enum_type*,
        char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTransformFeedbackVarying)>
      GetTransformFeedbackVarying;

    /// @var BindFragDataLocation
    /// @glfuncwrap{BindFragDataLocation}
    gl_api_function<
      void(uint_type, uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(BindFragDataLocation)>
      BindFragDataLocation;

    /// @var BindFragDataLocationIndexed
    /// @glfuncwrap{BindFragDataLocationIndexed}
    gl_api_function<
      void(uint_type, uint_type, uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(BindFragDataLocationIndexed)>
      BindFragDataLocationIndexed;

    /// @var GetFragDataLocation
    /// @glfuncwrap{GetFragDataLocation}
    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFragDataLocation)>
      GetFragDataLocation;

    /// @var GetFragDataIndex
    /// @glfuncwrap{GetFragDataIndex}
    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFragDataIndex)>
      GetFragDataIndex;

    /// @var UniformSubroutinesuiv
    /// @glfuncwrap{UniformSubroutinesuiv}
    gl_api_function<
      void(enum_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformSubroutinesuiv)>
      UniformSubroutinesuiv;

    /// @var GetUniformSubroutineuiv
    /// @glfuncwrap{GetUniformSubroutineuiv}
    gl_api_function<
      void(enum_type, int_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformSubroutineuiv)>
      GetUniformSubroutineuiv;

    /// @var Uniform1i
    /// @glfuncwrap{Uniform1i}
    gl_api_function<void(int_type, int_type), OGLPLUS_GL_STATIC_FUNC(Uniform1i)>
      Uniform1i;

    /// @var Uniform2i
    /// @glfuncwrap{Uniform2i}
    gl_api_function<
      void(int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform2i)>
      Uniform2i;

    /// @var Uniform3i
    /// @glfuncwrap{Uniform3i}
    gl_api_function<
      void(int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform3i)>
      Uniform3i;

    /// @var Uniform4i
    /// @glfuncwrap{Uniform4i}
    gl_api_function<
      void(int_type, int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform4i)>
      Uniform4i;

    /// @var Uniform1iv
    /// @glfuncwrap{Uniform1iv}
    gl_api_function<
      void(int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform1iv)>
      Uniform1iv;

    /// @var Uniform2iv
    /// @glfuncwrap{Uniform2iv}
    gl_api_function<
      void(int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform2iv)>
      Uniform2iv;

    /// @var Uniform3iv
    /// @glfuncwrap{Uniform3iv}
    gl_api_function<
      void(int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform3iv)>
      Uniform3iv;

    /// @var Uniform4iv
    /// @glfuncwrap{Uniform4iv}
    gl_api_function<
      void(int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform4iv)>
      Uniform4iv;

    /// @var Uniform1ui
    /// @glfuncwrap{Uniform1ui}
    gl_api_function<void(int_type, uint_type), OGLPLUS_GL_STATIC_FUNC(Uniform1ui)>
      Uniform1ui;

    /// @var Uniform2ui
    /// @glfuncwrap{Uniform2ui}
    gl_api_function<
      void(int_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform2ui)>
      Uniform2ui;

    /// @var Uniform3ui
    /// @glfuncwrap{Uniform3ui}
    gl_api_function<
      void(int_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform3ui)>
      Uniform3ui;

    /// @var Uniform4ui
    /// @glfuncwrap{Uniform4ui}
    gl_api_function<
      void(int_type, uint_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform4ui)>
      Uniform4ui;

    /// @var Uniform1uiv
    /// @glfuncwrap{Uniform1uiv}
    gl_api_function<
      void(int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform1uiv)>
      Uniform1uiv;

    /// @var Uniform2uiv
    /// @glfuncwrap{Uniform2uiv}
    gl_api_function<
      void(int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform2uiv)>
      Uniform2uiv;

    /// @var Uniform3uiv
    /// @glfuncwrap{Uniform3uiv}
    gl_api_function<
      void(int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform3uiv)>
      Uniform3uiv;

    /// @var Uniform4uiv
    /// @glfuncwrap{Uniform4uiv}
    gl_api_function<
      void(int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform4uiv)>
      Uniform4uiv;

    /// @var Uniform1f
    /// @glfuncwrap{Uniform1f}
    gl_api_function<void(int_type, float_type), OGLPLUS_GL_STATIC_FUNC(Uniform1f)>
      Uniform1f;

    /// @var Uniform2f
    /// @glfuncwrap{Uniform2f}
    gl_api_function<
      void(int_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform2f)>
      Uniform2f;

    /// @var Uniform3f
    /// @glfuncwrap{Uniform3f}
    gl_api_function<
      void(int_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform3f)>
      Uniform3f;

    /// @var Uniform4f
    /// @glfuncwrap{Uniform4f}
    gl_api_function<
      void(int_type, float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(Uniform4f)>
      Uniform4f;

    /// @var Uniform1fv
    /// @glfuncwrap{Uniform1fv}
    gl_api_function<
      void(int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform1fv)>
      Uniform1fv;

    /// @var Uniform2fv
    /// @glfuncwrap{Uniform2fv}
    gl_api_function<
      void(int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform2fv)>
      Uniform2fv;

    /// @var Uniform3fv
    /// @glfuncwrap{Uniform3fv}
    gl_api_function<
      void(int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform3fv)>
      Uniform3fv;

    /// @var Uniform4fv
    /// @glfuncwrap{Uniform4fv}
    gl_api_function<
      void(int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(Uniform4fv)>
      Uniform4fv;

    /// @var UniformMatrix2fv
    /// @glfuncwrap{UniformMatrix2fv}
    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix2fv)>
      UniformMatrix2fv;

    /// @var UniformMatrix3fv
    /// @glfuncwrap{UniformMatrix3fv}
    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix3fv)>
      UniformMatrix3fv;

    /// @var UniformMatrix4fv
    /// @glfuncwrap{UniformMatrix4fv}
    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix4fv)>
      UniformMatrix4fv;

    /// @var UniformMatrix2x3fv
    /// @glfuncwrap{UniformMatrix2x3fv}
    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix2x3fv)>
      UniformMatrix2x3fv;

    /// @var UniformMatrix3x2fv
    /// @glfuncwrap{UniformMatrix3x2fv}
    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix3x2fv)>
      UniformMatrix3x2fv;

    /// @var UniformMatrix2x4fv
    /// @glfuncwrap{UniformMatrix2x4fv}
    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix2x4fv)>
      UniformMatrix2x4fv;

    /// @var UniformMatrix4x2fv
    /// @glfuncwrap{UniformMatrix4x2fv}
    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix4x2fv)>
      UniformMatrix4x2fv;

    /// @var UniformMatrix3x4fv
    /// @glfuncwrap{UniformMatrix3x4fv}
    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix3x4fv)>
      UniformMatrix3x4fv;

    /// @var UniformMatrix4x3fv
    /// @glfuncwrap{UniformMatrix4x3fv}
    gl_api_function<
      void(int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformMatrix4x3fv)>
      UniformMatrix4x3fv;

    /// @var GetUniformfv
    /// @glfuncwrap{GetUniformfv}
    gl_api_function<
      void(uint_type, int_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformfv)>
      GetUniformfv;

    /// @var GetUniformdv
    /// @glfuncwrap{GetUniformdv}
    gl_api_function<
      void(uint_type, int_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformdv)>
      GetUniformdv;

    /// @var GetUniformiv
    /// @glfuncwrap{GetUniformiv}
    gl_api_function<
      void(uint_type, int_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformiv)>
      GetUniformiv;

    /// @var GetUniformuiv
    /// @glfuncwrap{GetUniformuiv}
    gl_api_function<
      void(uint_type, int_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformuiv)>
      GetUniformuiv;

    /// @var GetnUniformfv
    /// @glfuncwrap{GetnUniformfv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetnUniformfv)>
      GetnUniformfv;

    /// @var GetnUniformdv
    /// @glfuncwrap{GetnUniformdv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetnUniformdv)>
      GetnUniformdv;

    /// @var GetnUniformiv
    /// @glfuncwrap{GetnUniformiv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetnUniformiv)>
      GetnUniformiv;

    /// @var GetnUniformuiv
    /// @glfuncwrap{GetnUniformuiv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetnUniformuiv)>
      GetnUniformuiv;

    /// @var ProgramUniform1i
    /// @glfuncwrap{ProgramUniform1i}
    gl_api_function<
      void(uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1i)>
      ProgramUniform1i;

    /// @var ProgramUniform2i
    /// @glfuncwrap{ProgramUniform2i}
    gl_api_function<
      void(uint_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2i)>
      ProgramUniform2i;

    /// @var ProgramUniform3i
    /// @glfuncwrap{ProgramUniform3i}
    gl_api_function<
      void(uint_type, int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3i)>
      ProgramUniform3i;

    /// @var ProgramUniform4i
    /// @glfuncwrap{ProgramUniform4i}
    gl_api_function<
      void(uint_type, int_type, int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4i)>
      ProgramUniform4i;

    /// @var ProgramUniform1iv
    /// @glfuncwrap{ProgramUniform1iv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1iv)>
      ProgramUniform1iv;

    /// @var ProgramUniform2iv
    /// @glfuncwrap{ProgramUniform2iv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2iv)>
      ProgramUniform2iv;

    /// @var ProgramUniform3iv
    /// @glfuncwrap{ProgramUniform3iv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3iv)>
      ProgramUniform3iv;

    /// @var ProgramUniform4iv
    /// @glfuncwrap{ProgramUniform4iv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4iv)>
      ProgramUniform4iv;

    /// @var ProgramUniform1ui
    /// @glfuncwrap{ProgramUniform1ui}
    gl_api_function<
      void(uint_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1ui)>
      ProgramUniform1ui;

    /// @var ProgramUniform2ui
    /// @glfuncwrap{ProgramUniform2ui}
    gl_api_function<
      void(uint_type, int_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2ui)>
      ProgramUniform2ui;

    /// @var ProgramUniform3ui
    /// @glfuncwrap{ProgramUniform3ui}
    gl_api_function<
      void(uint_type, int_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3ui)>
      ProgramUniform3ui;

    /// @var ProgramUniform4ui
    /// @glfuncwrap{ProgramUniform4ui}
    gl_api_function<
      void(uint_type, int_type, uint_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4ui)>
      ProgramUniform4ui;

    /// @var ProgramUniform1uiv
    /// @glfuncwrap{ProgramUniform1uiv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1uiv)>
      ProgramUniform1uiv;

    /// @var ProgramUniform2uiv
    /// @glfuncwrap{ProgramUniform2uiv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2uiv)>
      ProgramUniform2uiv;

    /// @var ProgramUniform3uiv
    /// @glfuncwrap{ProgramUniform3uiv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3uiv)>
      ProgramUniform3uiv;

    /// @var ProgramUniform4uiv
    /// @glfuncwrap{ProgramUniform4uiv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4uiv)>
      ProgramUniform4uiv;

    /// @var ProgramUniform1f
    /// @glfuncwrap{ProgramUniform1f}
    gl_api_function<
      void(uint_type, int_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1f)>
      ProgramUniform1f;

    /// @var ProgramUniform2f
    /// @glfuncwrap{ProgramUniform2f}
    gl_api_function<
      void(uint_type, int_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2f)>
      ProgramUniform2f;

    /// @var ProgramUniform3f
    /// @glfuncwrap{ProgramUniform3f}
    gl_api_function<
      void(uint_type, int_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3f)>
      ProgramUniform3f;

    /// @var ProgramUniform4f
    /// @glfuncwrap{ProgramUniform4f}
    gl_api_function<
      void(uint_type, int_type, float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4f)>
      ProgramUniform4f;

    /// @var ProgramUniform1fv
    /// @glfuncwrap{ProgramUniform1fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1fv)>
      ProgramUniform1fv;

    /// @var ProgramUniform2fv
    /// @glfuncwrap{ProgramUniform2fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2fv)>
      ProgramUniform2fv;

    /// @var ProgramUniform3fv
    /// @glfuncwrap{ProgramUniform3fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3fv)>
      ProgramUniform3fv;

    /// @var ProgramUniform4fv
    /// @glfuncwrap{ProgramUniform4fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4fv)>
      ProgramUniform4fv;

    /// @var ProgramUniformMatrix2fv
    /// @glfuncwrap{ProgramUniformMatrix2fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix2fv)>
      ProgramUniformMatrix2fv;

    /// @var ProgramUniformMatrix3fv
    /// @glfuncwrap{ProgramUniformMatrix3fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix3fv)>
      ProgramUniformMatrix3fv;

    /// @var ProgramUniformMatrix4fv
    /// @glfuncwrap{ProgramUniformMatrix4fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix4fv)>
      ProgramUniformMatrix4fv;

    /// @var ProgramUniformMatrix2x3fv
    /// @glfuncwrap{ProgramUniformMatrix2x3fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix2x3fv)>
      ProgramUniformMatrix2x3fv;

    /// @var ProgramUniformMatrix3x2fv
    /// @glfuncwrap{ProgramUniformMatrix3x2fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix3x2fv)>
      ProgramUniformMatrix3x2fv;

    /// @var ProgramUniformMatrix2x4fv
    /// @glfuncwrap{ProgramUniformMatrix2x4fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix2x4fv)>
      ProgramUniformMatrix2x4fv;

    /// @var ProgramUniformMatrix4x2fv
    /// @glfuncwrap{ProgramUniformMatrix4x2fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix4x2fv)>
      ProgramUniformMatrix4x2fv;

    /// @var ProgramUniformMatrix3x4fv
    /// @glfuncwrap{ProgramUniformMatrix3x4fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix3x4fv)>
      ProgramUniformMatrix3x4fv;

    /// @var ProgramUniformMatrix4x3fv
    /// @glfuncwrap{ProgramUniformMatrix4x3fv}
    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix4x3fv)>
      ProgramUniformMatrix4x3fv;

    /// @var UniformBlockBinding
    /// @glfuncwrap{UniformBlockBinding}
    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(UniformBlockBinding)>
      UniformBlockBinding;

    /// @var ShaderStorageBlockBinding
    /// @glfuncwrap{ShaderStorageBlockBinding}
    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ShaderStorageBlockBinding)>
      ShaderStorageBlockBinding;

    /// @var VertexAttrib1f
    /// @glfuncwrap{VertexAttrib1f}
    gl_api_function<
      void(uint_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1f)>
      VertexAttrib1f;

    /// @var VertexAttrib2f
    /// @glfuncwrap{VertexAttrib2f}
    gl_api_function<
      void(uint_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2f)>
      VertexAttrib2f;

    /// @var VertexAttrib3f
    /// @glfuncwrap{VertexAttrib3f}
    gl_api_function<
      void(uint_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3f)>
      VertexAttrib3f;

    /// @var VertexAttrib4f
    /// @glfuncwrap{VertexAttrib4f}
    gl_api_function<
      void(uint_type, float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4f)>
      VertexAttrib4f;

    /// @var VertexAttrib1fv
    /// @glfuncwrap{VertexAttrib1fv}
    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1fv)>
      VertexAttrib1fv;

    /// @var VertexAttrib2fv
    /// @glfuncwrap{VertexAttrib2fv}
    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2fv)>
      VertexAttrib2fv;

    /// @var VertexAttrib3fv
    /// @glfuncwrap{VertexAttrib3fv}
    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3fv)>
      VertexAttrib3fv;

    /// @var VertexAttrib4fv
    /// @glfuncwrap{VertexAttrib4fv}
    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4fv)>
      VertexAttrib4fv;

    /// @var VertexAttrib1d
    /// @glfuncwrap{VertexAttrib1d}
    gl_api_function<
      void(uint_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1d)>
      VertexAttrib1d;

    /// @var VertexAttrib2d
    /// @glfuncwrap{VertexAttrib2d}
    gl_api_function<
      void(uint_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2d)>
      VertexAttrib2d;

    /// @var VertexAttrib3d
    /// @glfuncwrap{VertexAttrib3d}
    gl_api_function<
      void(uint_type, double_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3d)>
      VertexAttrib3d;

    /// @var VertexAttrib4d
    /// @glfuncwrap{VertexAttrib4d}
    gl_api_function<
      void(uint_type, double_type, double_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4d)>
      VertexAttrib4d;

    /// @var VertexAttrib1dv
    /// @glfuncwrap{VertexAttrib1dv}
    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1dv)>
      VertexAttrib1dv;

    /// @var VertexAttrib2dv
    /// @glfuncwrap{VertexAttrib2dv}
    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2dv)>
      VertexAttrib2dv;

    /// @var VertexAttrib3dv
    /// @glfuncwrap{VertexAttrib3dv}
    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3dv)>
      VertexAttrib3dv;

    /// @var VertexAttrib4dv
    /// @glfuncwrap{VertexAttrib4dv}
    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4dv)>
      VertexAttrib4dv;

    /// @var VertexAttrib1s
    /// @glfuncwrap{VertexAttrib1s}
    gl_api_function<
      void(uint_type, short_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1s)>
      VertexAttrib1s;

    /// @var VertexAttrib2s
    /// @glfuncwrap{VertexAttrib2s}
    gl_api_function<
      void(uint_type, short_type, short_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2s)>
      VertexAttrib2s;

    /// @var VertexAttrib3s
    /// @glfuncwrap{VertexAttrib3s}
    gl_api_function<
      void(uint_type, short_type, short_type, short_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3s)>
      VertexAttrib3s;

    /// @var VertexAttrib4s
    /// @glfuncwrap{VertexAttrib4s}
    gl_api_function<
      void(uint_type, short_type, short_type, short_type, short_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4s)>
      VertexAttrib4s;

    /// @var VertexAttrib1sv
    /// @glfuncwrap{VertexAttrib1sv}
    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1sv)>
      VertexAttrib1sv;

    /// @var VertexAttrib2sv
    /// @glfuncwrap{VertexAttrib2sv}
    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2sv)>
      VertexAttrib2sv;

    /// @var VertexAttrib3sv
    /// @glfuncwrap{VertexAttrib3sv}
    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3sv)>
      VertexAttrib3sv;

    /// @var VertexAttrib4sv
    /// @glfuncwrap{VertexAttrib4sv}
    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4sv)>
      VertexAttrib4sv;

    /// @var VertexAttribI1i
    /// @glfuncwrap{VertexAttribI1i}
    gl_api_function<
      void(uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI1i)>
      VertexAttribI1i;

    /// @var VertexAttribI2i
    /// @glfuncwrap{VertexAttribI2i}
    gl_api_function<
      void(uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI2i)>
      VertexAttribI2i;

    /// @var VertexAttribI3i
    /// @glfuncwrap{VertexAttribI3i}
    gl_api_function<
      void(uint_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI3i)>
      VertexAttribI3i;

    /// @var VertexAttribI4i
    /// @glfuncwrap{VertexAttribI4i}
    gl_api_function<
      void(uint_type, int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4i)>
      VertexAttribI4i;

    /// @var VertexAttribI1iv
    /// @glfuncwrap{VertexAttribI1iv}
    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI1iv)>
      VertexAttribI1iv;

    /// @var VertexAttribI2iv
    /// @glfuncwrap{VertexAttribI2iv}
    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI2iv)>
      VertexAttribI2iv;

    /// @var VertexAttribI3iv
    /// @glfuncwrap{VertexAttribI3iv}
    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI3iv)>
      VertexAttribI3iv;

    /// @var VertexAttribI4iv
    /// @glfuncwrap{VertexAttribI4iv}
    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4iv)>
      VertexAttribI4iv;

    /// @var VertexAttribI1ui
    /// @glfuncwrap{VertexAttribI1ui}
    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI1ui)>
      VertexAttribI1ui;

    /// @var VertexAttribI2ui
    /// @glfuncwrap{VertexAttribI2ui}
    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI2ui)>
      VertexAttribI2ui;

    /// @var VertexAttribI3ui
    /// @glfuncwrap{VertexAttribI3ui}
    gl_api_function<
      void(uint_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI3ui)>
      VertexAttribI3ui;

    /// @var VertexAttribI4ui
    /// @glfuncwrap{VertexAttribI4ui}
    gl_api_function<
      void(uint_type, uint_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4ui)>
      VertexAttribI4ui;

    /// @var VertexAttribI1uiv
    /// @glfuncwrap{VertexAttribI1uiv}
    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI1uiv)>
      VertexAttribI1uiv;

    /// @var VertexAttribI2uiv
    /// @glfuncwrap{VertexAttribI2uiv}
    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI2uiv)>
      VertexAttribI2uiv;

    /// @var VertexAttribI3uiv
    /// @glfuncwrap{VertexAttribI3uiv}
    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI3uiv)>
      VertexAttribI3uiv;

    /// @var VertexAttribI4uiv
    /// @glfuncwrap{VertexAttribI4uiv}
    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4uiv)>
      VertexAttribI4uiv;

    /// @var VertexAttribI4bv
    /// @glfuncwrap{VertexAttribI4bv}
    gl_api_function<
      void(uint_type, const byte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4bv)>
      VertexAttribI4bv;

    /// @var VertexAttribI4ubv
    /// @glfuncwrap{VertexAttribI4ubv}
    gl_api_function<
      void(uint_type, const ubyte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4ubv)>
      VertexAttribI4ubv;

    /// @var VertexAttribI4sv
    /// @glfuncwrap{VertexAttribI4sv}
    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4sv)>
      VertexAttribI4sv;

    /// @var VertexAttribI4usv
    /// @glfuncwrap{VertexAttribI4usv}
    gl_api_function<
      void(uint_type, const ushort_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4usv)>
      VertexAttribI4usv;

    /// @var VertexAttrib4bv
    /// @glfuncwrap{VertexAttrib4bv}
    gl_api_function<
      void(uint_type, const byte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4bv)>
      VertexAttrib4bv;

    /// @var VertexAttrib4ubv
    /// @glfuncwrap{VertexAttrib4ubv}
    gl_api_function<
      void(uint_type, const ubyte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4ubv)>
      VertexAttrib4ubv;

    /// @var VertexAttrib4usv
    /// @glfuncwrap{VertexAttrib4usv}
    gl_api_function<
      void(uint_type, const ushort_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4usv)>
      VertexAttrib4usv;

    /// @var VertexAttrib4iv
    /// @glfuncwrap{VertexAttrib4iv}
    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4iv)>
      VertexAttrib4iv;

    /// @var VertexAttrib4uiv
    /// @glfuncwrap{VertexAttrib4uiv}
    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4uiv)>
      VertexAttrib4uiv;

    /// @var VertexAttrib4Nub
    /// @glfuncwrap{VertexAttrib4Nub}
    gl_api_function<
      void(uint_type, ubyte_type, ubyte_type, ubyte_type, ubyte_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nub)>
      VertexAttrib4Nub;

    /// @var VertexAttrib4Nbv
    /// @glfuncwrap{VertexAttrib4Nbv}
    gl_api_function<
      void(uint_type, const byte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nbv)>
      VertexAttrib4Nbv;

    /// @var VertexAttrib4Nubv
    /// @glfuncwrap{VertexAttrib4Nubv}
    gl_api_function<
      void(uint_type, const ubyte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nubv)>
      VertexAttrib4Nubv;

    /// @var VertexAttrib4Nsv
    /// @glfuncwrap{VertexAttrib4Nsv}
    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nsv)>
      VertexAttrib4Nsv;

    /// @var VertexAttrib4Nusv
    /// @glfuncwrap{VertexAttrib4Nusv}
    gl_api_function<
      void(uint_type, const ushort_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nusv)>
      VertexAttrib4Nusv;

    /// @var VertexAttrib4Niv
    /// @glfuncwrap{VertexAttrib4Niv}
    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Niv)>
      VertexAttrib4Niv;

    /// @var VertexAttrib4Nuiv
    /// @glfuncwrap{VertexAttrib4Nuiv}
    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nuiv)>
      VertexAttrib4Nuiv;

    /// @var VertexAttribL1d
    /// @glfuncwrap{VertexAttribL1d}
    gl_api_function<
      void(uint_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL1d)>
      VertexAttribL1d;

    /// @var VertexAttribL2d
    /// @glfuncwrap{VertexAttribL2d}
    gl_api_function<
      void(uint_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL2d)>
      VertexAttribL2d;

    /// @var VertexAttribL3d
    /// @glfuncwrap{VertexAttribL3d}
    gl_api_function<
      void(uint_type, double_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL3d)>
      VertexAttribL3d;

    /// @var VertexAttribL4d
    /// @glfuncwrap{VertexAttribL4d}
    gl_api_function<
      void(uint_type, double_type, double_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL4d)>
      VertexAttribL4d;

    /// @var VertexAttribL1dv
    /// @glfuncwrap{VertexAttribL1dv}
    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL1dv)>
      VertexAttribL1dv;

    /// @var VertexAttribL2dv
    /// @glfuncwrap{VertexAttribL2dv}
    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL2dv)>
      VertexAttribL2dv;

    /// @var VertexAttribL3dv
    /// @glfuncwrap{VertexAttribL3dv}
    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL3dv)>
      VertexAttribL3dv;

    /// @var VertexAttribL4dv
    /// @glfuncwrap{VertexAttribL4dv}
    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL4dv)>
      VertexAttribL4dv;

    /// @var VertexAttrib4P1ui
    /// @glfuncwrap{VertexAttrib4P1ui}
    gl_api_function<
      void(uint_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP1ui)>
      VertexAttribP1ui;

    /// @var VertexAttribP2ui
    /// @glfuncwrap{VertexAttribP2ui}
    gl_api_function<
      void(uint_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP2ui)>
      VertexAttribP2ui;

    /// @var VertexAttribP3ui
    /// @glfuncwrap{VertexAttribP3ui}
    gl_api_function<
      void(uint_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP3ui)>
      VertexAttribP3ui;

    /// @var VertexAttribP4ui
    /// @glfuncwrap{VertexAttribP4ui}
    gl_api_function<
      void(uint_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP4ui)>
      VertexAttribP4ui;

    /// @var VertexAttribP1uiv
    /// @glfuncwrap{VertexAttribP1uiv}
    gl_api_function<
      void(uint_type, enum_type, bool_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP1uiv)>
      VertexAttribP1uiv;

    /// @var VertexAttribP2uiv
    /// @glfuncwrap{VertexAttribP2uiv}
    gl_api_function<
      void(uint_type, enum_type, bool_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP2uiv)>
      VertexAttribP2uiv;

    /// @var VertexAttribP3uiv
    /// @glfuncwrap{VertexAttribP3uiv}
    gl_api_function<
      void(uint_type, enum_type, bool_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP3uiv)>
      VertexAttribP3uiv;

    /// @var VertexAttribP4uiv
    /// @glfuncwrap{VertexAttribP4uiv}
    gl_api_function<
      void(uint_type, enum_type, bool_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP4uiv)>
      VertexAttribP4uiv;

    /// @var VertexAttribFormat
    /// @glfuncwrap{VertexAttribFormat}
    gl_api_function<
      void(uint_type, int_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribFormat)>
      VertexAttribFormat;

    /// @var VertexAttribIFormat
    /// @glfuncwrap{VertexAttribIFormat}
    gl_api_function<
      void(uint_type, int_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribIFormat)>
      VertexAttribIFormat;

    /// @var VertexAttribLFormat
    /// @glfuncwrap{VertexAttribLFormat}
    gl_api_function<
      void(uint_type, int_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribLFormat)>
      VertexAttribLFormat;

    /// @var VertexArrayAttribFormat
    /// @glfuncwrap{VertexArrayAttribFormat}
    gl_api_function<
      void(uint_type, uint_type, int_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayAttribFormat)>
      VertexArrayAttribFormat;

    /// @var VertexArrayAttribIFormat
    /// @glfuncwrap{VertexArrayAttribIFormat}
    gl_api_function<
      void(uint_type, uint_type, int_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayAttribIFormat)>
      VertexArrayAttribIFormat;

    /// @var VertexArrayAttribLFormat
    /// @glfuncwrap{VertexArrayAttribLFormat}
    gl_api_function<
      void(uint_type, uint_type, int_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayAttribLFormat)>
      VertexArrayAttribLFormat;

    /// @var VertexAttribPointer
    /// @glfuncwrap{VertexAttribPointer}
    gl_api_function<
      void(
        uint_type,
        int_type,
        enum_type,
        bool_type,
        sizei_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribPointer)>
      VertexAttribPointer;

    /// @var VertexAttribIPointer
    /// @glfuncwrap{VertexAttribIPointer}
    gl_api_function<
      void(uint_type, int_type, enum_type, sizei_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribIPointer)>
      VertexAttribIPointer;

    /// @var VertexAttribLPointer
    /// @glfuncwrap{VertexAttribLPointer}
    gl_api_function<
      void(uint_type, int_type, enum_type, sizei_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribLPointer)>
      VertexAttribLPointer;

    /// @var GetVertexArrayiv
    /// @glfuncwrap{GetVertexArrayiv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexArrayiv)>
      GetVertexArrayiv;

    /// @var GetVertexArrayIndexediv
    /// @glfuncwrap{GetVertexArrayIndexediv}
    gl_api_function<
      void(uint_type, uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexArrayIndexediv)>
      GetVertexArrayIndexediv;

    /// @var GetVertexArrayIndexed64iv
    /// @glfuncwrap{GetVertexArrayIndexed64iv}
    gl_api_function<
      void(uint_type, uint_type, enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexArrayIndexed64iv)>
      GetVertexArrayIndexed64iv;

    /// @var GetVertexAttribdv
    /// @glfuncwrap{GetVertexAttribdv}
    gl_api_function<
      void(uint_type, enum_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribdv)>
      GetVertexAttribdv;

    /// @var GetVertexAttribfv
    /// @glfuncwrap{GetVertexAttribfv}
    gl_api_function<
      void(uint_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribfv)>
      GetVertexAttribfv;

    /// @var GetVertexAttribiv
    /// @glfuncwrap{GetVertexAttribiv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribiv)>
      GetVertexAttribiv;

    /// @var GetVertexAttribIiv
    /// @glfuncwrap{GetVertexAttribIiv}
    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribIiv)>
      GetVertexAttribIiv;

    /// @var GetVertexAttribIuiv
    /// @glfuncwrap{GetVertexAttribIuiv}
    gl_api_function<
      void(uint_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribIuiv)>
      GetVertexAttribIuiv;

    /// @var GetVertexAttribLdv
    /// @glfuncwrap{GetVertexAttribLdv}
    gl_api_function<
      void(uint_type, enum_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribLdv)>
      GetVertexAttribLdv;

    /// @var GetVertexAttribPointerv
    /// @glfuncwrap{GetVertexAttribPointerv}
    gl_api_function<
      void(uint_type, enum_type, void_ptr_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribPointerv)>
      GetVertexAttribPointerv;

    /// @var ClipControl
    /// @glfuncwrap{ClipControl}
    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(ClipControl)>
      ClipControl;

    /// @var DepthRange
    /// @glfuncwrap{DepthRange}
    gl_api_function<
      void(double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRange)>
      DepthRange;

    /// @var DepthRangef
    /// @glfuncwrap{DepthRangef}
    gl_api_function<
      void(float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRangef)>
      DepthRangef;

    /// @var DepthRangeArrayv
    /// @glfuncwrap{DepthRangeArrayv}
    gl_api_function<
      void(uint_type, sizei_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(DepthRangeArrayv)>
      DepthRangeArrayv;

    /// @var DepthRangeIndexed
    /// @glfuncwrap{DepthRangeIndexed}
    gl_api_function<
      void(uint_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRangeIndexed)>
      DepthRangeIndexed;

    /// @var Viewport
    /// @glfuncwrap{Viewport}
    gl_api_function<
      void(int_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(Viewport)>
      Viewport;

    /// @var ViewportArrayv
    /// @glfuncwrap{ViewportArrayv}
    gl_api_function<
      void(uint_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ViewportArrayv)>
      ViewportArrayv;

    /// @var ViewportIndexedf
    /// @glfuncwrap{ViewportIndexedf}
    gl_api_function<
      void(uint_type, float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ViewportIndexedf)>
      ViewportIndexedf;

    /// @var ViewportIndexedfv
    /// @glfuncwrap{ViewportIndexedfv}
    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ViewportIndexedfv)>
      ViewportIndexedfv;

    /// @var Scissor
    /// @glfuncwrap{Scissor}
    gl_api_function<
      void(int_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(Scissor)>
      Scissor;

    /// @var ScissorArrayv
    /// @glfuncwrap{ScissorArrayv}
    gl_api_function<
      void(uint_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ScissorArrayv)>
      ScissorArrayv;

    /// @var ScissorIndexed
    /// @glfuncwrap{ScissorIndexed}
    gl_api_function<
      void(uint_type, int_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(ScissorIndexed)>
      ScissorIndexed;

    /// @var ScissorIndexedv
    /// @glfuncwrap{ScissorIndexedv}
    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ScissorIndexedv)>
      ScissorIndexedv;

    /// @var StencilFunc
    /// @glfuncwrap{StencilFunc}
    gl_api_function<
      void(enum_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilFunc)>
      StencilFunc;

    /// @var StencilFuncSeparate
    /// @glfuncwrap{StencilFuncSeparate}
    gl_api_function<
      void(enum_type, enum_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilFuncSeparate)>
      StencilFuncSeparate;

    /// @var StencilOp
    /// @glfuncwrap{StencilOp}
    gl_api_function<
      void(enum_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(StencilOp)>
      StencilOp;

    /// @var StencilOpSeparate
    /// @glfuncwrap{StencilOpSeparate}
    gl_api_function<
      void(enum_type, enum_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(StencilOpSeparate)>
      StencilOpSeparate;

    /// @var DepthFunc
    /// @glfuncwrap{DepthFunc}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(DepthFunc)>
      DepthFunc;

    /// @var ColorMask
    /// @glfuncwrap{ColorMask}
    gl_api_function<
      void(bool_type, bool_type, bool_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(ColorMask)>
      ColorMask;

    /// @var ColorMaski
    /// @glfuncwrap{ColorMaski}
    gl_api_function<
      void(uint_type, bool_type, bool_type, bool_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(ColorMaski)>
      ColorMaski;

    /// @var DepthMask
    /// @glfuncwrap{DepthMask}
    gl_api_function<void(bool_type), OGLPLUS_GL_STATIC_FUNC(DepthMask)>
      DepthMask;

    /// @var StencilMask
    /// @glfuncwrap{StencilMask}
    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(StencilMask)>
      StencilMask;

    /// @var StencilMaskSeparate
    /// @glfuncwrap{StencilMaskSeparate}
    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilMaskSeparate)>
      StencilMaskSeparate;

    /// @var ClearColor
    /// @glfuncwrap{ClearColor}
    gl_api_function<
      void(float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ClearColor)>
      ClearColor;

    /// @var ClearDepthf
    /// @glfuncwrap{ClearDepthf}
    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(ClearDepthf)>
      ClearDepthf;

    /// @var ClearDepth
    /// @glfuncwrap{ClearDepth}
    gl_api_function<void(double_type), OGLPLUS_GL_STATIC_FUNC(ClearDepth)>
      ClearDepth;

    /// @var ClearStencil
    /// @glfuncwrap{ClearStencil}
    gl_api_function<void(int_type), OGLPLUS_GL_STATIC_FUNC(ClearStencil)>
      ClearStencil;

    /// @var Clear
    /// @glfuncwrap{Clear}
    gl_api_function<void(bitfield_type), OGLPLUS_GL_STATIC_FUNC(Clear)> Clear;

    /// @var PrimitiveRestartIndex
    /// @glfuncwrap{PrimitiveRestartIndex}
    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(PrimitiveRestartIndex)>
      PrimitiveRestartIndex;

    /// @var ProvokingVertex
    /// @glfuncwrap{ProvokingVertex}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(ProvokingVertex)>
      ProvokingVertex;

    /// @var LineWidth
    /// @glfuncwrap{LineWidth}
    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(LineWidth)>
      LineWidth;

    /// @var PointSize
    /// @glfuncwrap{PointSize}
    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(PointSize)>
      PointSize;

    /// @var PointParameteri
    /// @glfuncwrap{PointParameteri}
    gl_api_function<
      void(enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(PointParameteri)>
      PointParameteri;

    /// @var PointParameterf
    /// @glfuncwrap{PointParameterf}
    gl_api_function<
      void(enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PointParameterf)>
      PointParameterf;

    /// @var PointParameteriv
    /// @glfuncwrap{PointParameteriv}
    gl_api_function<
      void(enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(PointParameteriv)>
      PointParameteriv;

    /// @var PointParameterfv
    /// @glfuncwrap{PointParameterfv}
    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(PointParameterfv)>
      PointParameterfv;

    /// @var PatchParameteri
    /// @glfuncwrap{PatchParameteri}
    gl_api_function<
      void(enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(PatchParameteri)>
      PatchParameteri;

    /// @var PatchParameterfv
    /// @glfuncwrap{PatchParameterfv}
    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(PatchParameterfv)>
      PatchParameterfv;

    /// @var FrontFace
    /// @glfuncwrap{FrontFace}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(FrontFace)>
      FrontFace;

    /// @var CullFace
    /// @glfuncwrap{CullFace}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(CullFace)> CullFace;

    /// @var PolygonMode
    /// @glfuncwrap{PolygonMode}
    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(PolygonMode)>
      PolygonMode;

    /// @var PolygonOffset
    /// @glfuncwrap{PolygonOffset}
    gl_api_function<
      void(float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PolygonOffset)>
      PolygonOffset;

    /// @var PolygonOffsetClamp
    /// @glfuncwrap{PolygonOffsetClamp}
    gl_api_function<
      void(float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PolygonOffsetClamp)>
      PolygonOffsetClamp;

    /// @var SampleCoverage
    /// @glfuncwrap{SampleCoverage}
    gl_api_function<
      void(float_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(SampleCoverage)>
      SampleCoverage;

    /// @var SampleMaski
    /// @glfuncwrap{SampleMaski}
    gl_api_function<
      void(uint_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(SampleMaski)>
      SampleMaski;

    /// @var MinSampleShading
    /// @glfuncwrap{MinSampleShading}
    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(MinSampleShading)>
      MinSampleShading;

    /// @var GetMultisamplefv
    /// @glfuncwrap{GetMultisamplefv}
    gl_api_function<
      void(enum_type, uint_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetMultisamplefv)>
      GetMultisamplefv;

    /// @var BlendEquation
    /// @glfuncwrap{BlendEquation}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(BlendEquation)>
      BlendEquation;

    /// @var BlendEquationSeparate
    /// @glfuncwrap{BlendEquationSeparate}
    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendEquationSeparate)>
      BlendEquationSeparate;

    /// @var BlendEquationi
    /// @glfuncwrap{BlendEquationi}
    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendEquationi)>
      BlendEquationi;

    /// @var BlendEquationSeparatei
    /// @glfuncwrap{BlendEquationSeparatei}
    gl_api_function<
      void(uint_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendEquationSeparatei)>
      BlendEquationSeparatei;

    /// @var BlendFunc
    /// @glfuncwrap{BlendFunc}
    gl_api_function<void(enum_type, enum_type), OGLPLUS_GL_STATIC_FUNC(BlendFunc)>
      BlendFunc;

    /// @var BlendFuncSeparate
    /// @glfuncwrap{BlendFuncSeparate}
    gl_api_function<
      void(enum_type, enum_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendFuncSeparate)>
      BlendFuncSeparate;

    /// @var BlendFunci
    /// @glfuncwrap{BlendFunci}
    gl_api_function<
      void(uint_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendFunci)>
      BlendFunci;

    /// @var BlendFuncSeparatei
    /// @glfuncwrap{BlendFuncSeparatei}
    gl_api_function<
      void(uint_type, enum_type, enum_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendFuncSeparatei)>
      BlendFuncSeparatei;

    /// @var BlendColor
    /// @glfuncwrap{BlendColor}
    gl_api_function<
      void(float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(BlendColor)>
      BlendColor;

    /// @var LogicOp
    /// @glfuncwrap{LogicOp}
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(LogicOp)> LogicOp;

    /// @var DrawArrays
    /// @glfuncwrap{DrawArrays}
    gl_api_function<
      void(enum_type, int_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawArrays)>
      DrawArrays;

    /// @var DrawArraysInstancedBaseInstance
    /// @glfuncwrap{DrawArraysInstancedBaseInstance}
    gl_api_function<
      void(enum_type, int_type, sizei_type, sizei_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawArraysInstancedBaseInstance)>
      DrawArraysInstancedBaseInstance;

    /// @var DrawArraysInstanced
    /// @glfuncwrap{DrawArraysInstanced}
    gl_api_function<
      void(enum_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawArraysInstanced)>
      DrawArraysInstanced;

    /// @var DrawArraysIndirect
    /// @glfuncwrap{DrawArraysIndirect}
    gl_api_function<
      void(enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DrawArraysIndirect)>
      DrawArraysIndirect;

    /// @var MultiDrawArrays
    /// @glfuncwrap{MultiDrawArrays}
    gl_api_function<
      void(enum_type, const int_type*, const sizei_type*, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawArrays)>
      MultiDrawArrays;

    /// @var MultiDrawArraysIndirect
    /// @glfuncwrap{MultiDrawArraysIndirect}
    gl_api_function<
      void(enum_type, const_void_ptr_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawArraysIndirect)>
      MultiDrawArraysIndirect;

    /// @var MultiDrawArraysIndirectCount
    /// @glfuncwrap{MultiDrawArraysIndirectCount}
    gl_api_function<
      void(enum_type, const_void_ptr_type, intptr_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawArraysIndirectCount)>
      MultiDrawArraysIndirectCount;

    /// @var DrawElements
    /// @glfuncwrap{DrawElements}
    gl_api_function<
      void(enum_type, sizei_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElements)>
      DrawElements;

    /// @var DrawRangeElements
    /// @glfuncwrap{DrawRangeElements}
    gl_api_function<
      void(
        enum_type,
        uint_type,
        uint_type,
        sizei_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DrawRangeElements)>
      DrawRangeElements;

    /// @var DrawElementsInstancedBaseInstance
    /// @glfuncwrap{DrawElementsInstancedBaseInstance}
    gl_api_function<
      void(
        enum_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        sizei_type,
        uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsInstancedBaseInstance)>
      DrawElementsInstancedBaseInstance;

    /// @var DrawElementsInstanced
    /// @glfuncwrap{DrawElementsInstanced}
    gl_api_function<
      void(enum_type, sizei_type, enum_type, const_void_ptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsInstanced)>
      DrawElementsInstanced;

    /// @var DrawElementsBaseVertex
    /// @glfuncwrap{DrawElementsBaseVertex}
    gl_api_function<
      void(enum_type, sizei_type, enum_type, const_void_ptr_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsBaseVertex)>
      DrawElementsBaseVertex;

    /// @var DrawRangeElementsBaseVertex
    /// @glfuncwrap{DrawRangeElementsBaseVertex}
    gl_api_function<
      void(
        enum_type,
        uint_type,
        uint_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        int_type),
      OGLPLUS_GL_STATIC_FUNC(DrawRangeElementsBaseVertex)>
      DrawRangeElementsBaseVertex;

    /// @var DrawElementsInstancedBaseVertex
    /// @glfuncwrap{DrawElementsInstancedBaseVertex}
    gl_api_function<
      void(
        enum_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        sizei_type,
        int_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsInstancedBaseVertex)>
      DrawElementsInstancedBaseVertex;

    /// @var DrawElementsInstancedBaseVertexBaseInstance
    /// @glfuncwrap{DrawElementsInstancedBaseVertexBaseInstance}
    gl_api_function<
      void(
        enum_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        sizei_type,
        int_type,
        uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsInstancedBaseVertexBaseInstance)>
      DrawElementsInstancedBaseVertexBaseInstance;

    /// @var DrawElementsIndirect
    /// @glfuncwrap{DrawElementsIndirect}
    gl_api_function<
      void(enum_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsIndirect)>
      DrawElementsIndirect;

    /// @var MultiDrawElements
    /// @glfuncwrap{MultiDrawElements}
    gl_api_function<
      void(
        enum_type,
        const sizei_type*,
        enum_type,
        const const_void_ptr_type*,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawElements)>
      MultiDrawElements;

    /// @var MultiDrawElementsIndirect
    /// @glfuncwrap{MultiDrawElementsIndirect}
    gl_api_function<
      void(enum_type, enum_type, const_void_ptr_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawElementsIndirect)>
      MultiDrawElementsIndirect;

    /// @var MultiDrawElementsIndirectCount
    /// @glfuncwrap{MultiDrawElementsIndirectCount}
    gl_api_function<
      void(
        enum_type,
        enum_type,
        const_void_ptr_type,
        intptr_type,
        sizei_type,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawElementsIndirectCount)>
      MultiDrawElementsIndirectCount;

    /// @var MultiDrawElementsBaseVertex
    /// @glfuncwrap{MultiDrawElementsBaseVertex}
    gl_api_function<
      void(
        enum_type,
        const sizei_type*,
        enum_type,
        const const_void_ptr_type*,
        sizei_type,
        const int_type*),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawElementsBaseVertex)>
      MultiDrawElementsBaseVertex;

    /// @var DrawTransformFeedback
    /// @glfuncwrap{DrawTransformFeedback}
    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawTransformFeedback)>
      DrawTransformFeedback;

    /// @var DrawTransformFeedbackInstanced
    /// @glfuncwrap{DrawTransformFeedbackInstanced}
    gl_api_function<
      void(enum_type, uint_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawTransformFeedbackInstanced)>
      DrawTransformFeedbackInstanced;

    /// @var DrawTransformFeedbackStream
    /// @glfuncwrap{DrawTransformFeedbackStream}
    gl_api_function<
      void(enum_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawTransformFeedbackStream)>
      DrawTransformFeedbackStream;

    /// @var DrawTransformFeedbackStreamInstanced
    /// @glfuncwrap{DrawTransformFeedbackStreamInstanced}
    gl_api_function<
      void(enum_type, uint_type, uint_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawTransformFeedbackStreamInstanced)>
      DrawTransformFeedbackStreamInstanced;

    /// @var DispatchCompute
    /// @glfuncwrap{DispatchCompute}
    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DispatchCompute)>
      DispatchCompute;

    /// @var DispatchComputeIndirect
    /// @glfuncwrap{DispatchComputeIndirect}
    gl_api_function<
      void(intptr_type),
      OGLPLUS_GL_STATIC_FUNC(DispatchComputeIndirect)>
      DispatchComputeIndirect;

    /// @var ClampColor
    /// @glfuncwrap{ClampColor}
    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(ClampColor)>
      ClampColor;

    /// @var ReadPixels
    /// @glfuncwrap{ReadPixels}
    gl_api_function<
      void(
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ReadPixels)>
      ReadPixels;

    /// @var ReadnPixels
    /// @glfuncwrap{ReadnPixels}
    gl_api_function<
      void(
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        enum_type,
        enum_type,
        sizei_type,
        void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ReadnPixels)>
      ReadnPixels;

    /// @var GetBooleanv
    /// @glfuncwrap{GetBooleanv}
    gl_api_function<
      void(enum_type, bool_type*),
      OGLPLUS_GL_STATIC_FUNC(GetBooleanv)>
      GetBooleanv;

    /// @var GetBooleani_v
    /// @glfuncwrap{GetBooleani_v}
    gl_api_function<
      void(enum_type, uint_type, bool_type*),
      OGLPLUS_GL_STATIC_FUNC(GetBooleani_v)>
      GetBooleani_v;

    /// @var GetIntegerv
    /// @glfuncwrap{GetIntegerv}
    gl_api_function<
      void(enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetIntegerv)>
      GetIntegerv;

    /// @var GetIntegeri_v
    /// @glfuncwrap{GetIntegeri_v}
    gl_api_function<
      void(enum_type, uint_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetIntegeri_v)>
      GetIntegeri_v;

    /// @var GetInteger64v
    /// @glfuncwrap{GetInteger64v}
    gl_api_function<
      void(enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetInteger64v)>
      GetInteger64v;

    /// @var GetInteger64i_v
    /// @glfuncwrap{GetInteger64i_v}
    gl_api_function<
      void(enum_type, uint_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetInteger64i_v)>
      GetInteger64i_v;

    /// @var GetFloatv
    /// @glfuncwrap{GetFloatv}
    gl_api_function<
      void(enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFloatv)>
      GetFloatv;

    /// @var GetFloati_v
    /// @glfuncwrap{GetFloati_v}
    gl_api_function<
      void(enum_type, uint_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFloati_v)>
      GetFloati_v;

    /// @var GetDoublev
    /// @glfuncwrap{GetDoublev}
    gl_api_function<
      void(enum_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetDoublev)>
      GetDoublev;

    /// @var GetDoublei_v
    /// @glfuncwrap{GetDoublei_v}
    gl_api_function<
      void(enum_type, uint_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetDoublei_v)>
      GetDoublei_v;

    /// @var GetInternalformativ
    /// @glfuncwrap{GetInternalformativ}
    gl_api_function<
      void(enum_type, enum_type, enum_type, sizei_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetInternalformativ)>
      GetInternalformativ;

    /// @var GetInternalformati64v
    /// @glfuncwrap{GetInternalformati64v}
    gl_api_function<
      void(enum_type, enum_type, enum_type, sizei_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetInternalformati64v)>
      GetInternalformati64v;

    /// @var GetPointerv
    /// @glfuncwrap{GetPointerv}
    gl_api_function<
      void(enum_type, void_ptr_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPointerv)>
      GetPointerv;

    /// @var GetStringi
    /// @glfuncwrap{GetStringi}
    gl_api_function<
      const ubyte_type*(enum_type),
      OGLPLUS_GL_STATIC_FUNC(GetString)>
      GetString;

    /// @var GetStringi
    /// @glfuncwrap{GetStringi}
    gl_api_function<
      const ubyte_type*(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(GetStringi)>
      GetStringi;

    /// @var NamedString
    /// @glfuncwrap{NamedString}
    gl_api_function<
      void(enum_type, int_type, const char_type*, int_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(nullptr)>
      NamedString;

    /// @var DeleteNamedString
    /// @glfuncwrap{DeleteNamedString}
    gl_api_function<
      void(int_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(nullptr)>
      DeleteNamedString;

    /// @var IsNamedString
    /// @glfuncwrap{IsNamedString}
    gl_api_function<
      bool_type(int_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(nullptr)>
      IsNamedString;

    /// @var GetNamedStringiv
    /// @glfuncwrap{GetNamedStringiv}
    gl_api_function<
      void(int_type, const char_type*, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(nullptr)>
      GetNamedStringiv;

    /// @var GetNamedString
    /// @glfuncwrap{GetNamedString}
    gl_api_function<
      void(int_type, const char_type*, sizei_type, int_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(nullptr)>
      GetNamedString;

    // debugging
    gl_api_function<
      void(debug_callback_type*, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DebugMessageCallback)>
      DebugMessageCallback;

    gl_api_function<
      void(enum_type, enum_type, enum_type, sizei_type, const uint_type*, bool_type),
      OGLPLUS_GL_STATIC_FUNC(DebugMessageControl)>
      DebugMessageControl;

    gl_api_function<
      void(enum_type, enum_type, uint_type, enum_type, int_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(DebugMessageInsert)>
      DebugMessageInsert;

    gl_api_function<
      void(enum_type, uint_type, sizei_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(PushDebugGroup)>
      PushDebugGroup;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(PopDebugGroup)> PopDebugGroup;

    gl_api_function<
      void(enum_type, uint_type, sizei_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(ObjectLabel)>
      ObjectLabel;

    gl_api_function<
      void(const_void_ptr_type, sizei_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(ObjectPtrLabel)>
      ObjectPtrLabel;

    gl_api_function<
      void(enum_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetObjectLabel)>
      GetObjectLabel;

    gl_api_function<
      void(const_void_ptr_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetObjectPtrLabel)>
      GetObjectPtrLabel;

    gl_api_function<
      uint_type(
        uint_type,
        sizei_type,
        enum_type*,
        enum_type*,
        uint_type*,
        enum_type*,
        sizei_type*,
        char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetDebugMessageLog)>
      GetDebugMessageLog;

    // arb compatibility
    gl_api_function<void(enum_type), nullptr> Begin;
    gl_api_function<void(), nullptr> End;

    // vertex position
    gl_api_function<void(int_type, int_type), nullptr> Vertex2i;
    gl_api_function<void(int_type, int_type, int_type), nullptr> Vertex3i;
    gl_api_function<void(int_type, int_type, int_type, int_type), nullptr>
      Vertex4i;

    gl_api_function<void(float_type, float_type), nullptr> Vertex2f;
    gl_api_function<void(float_type, float_type, float_type), nullptr> Vertex3f;
    gl_api_function<void(float_type, float_type, float_type, float_type), nullptr>
      Vertex4f;

    // vertex color
    gl_api_function<void(int_type, int_type, int_type), nullptr> Color3i;
    gl_api_function<void(int_type, int_type, int_type, int_type), nullptr>
      Color4i;

    gl_api_function<void(float_type, float_type, float_type), nullptr> Color3f;
    gl_api_function<void(float_type, float_type, float_type, float_type), nullptr>
      Color4f;

    gl_api_function<void(int_type, int_type, int_type), nullptr>
      SecondaryColor3i;
    gl_api_function<void(int_type, int_type, int_type, int_type), nullptr>
      SecondaryColor4i;

    gl_api_function<void(float_type, float_type, float_type), nullptr>
      SecondaryColor3f;
    gl_api_function<void(float_type, float_type, float_type, float_type), nullptr>
      SecondaryColor4f;

    // vertex texture coord
    gl_api_function<void(int_type), nullptr> TexCoord1i;
    gl_api_function<void(int_type, int_type), nullptr> TexCoord2i;
    gl_api_function<void(int_type, int_type, int_type), nullptr> TexCoord3i;
    gl_api_function<void(int_type, int_type, int_type, int_type), nullptr>
      TexCoord4i;

    gl_api_function<void(float_type), nullptr> TexCoord1f;
    gl_api_function<void(float_type, float_type), nullptr> TexCoord2f;
    gl_api_function<void(float_type, float_type, float_type), nullptr>
      TexCoord3f;
    gl_api_function<void(float_type, float_type, float_type, float_type), nullptr>
      TexCoord4f;

    // vertex multi texture coord
    gl_api_function<void(enum_type, int_type), nullptr> MultiTexCoord1i;
    gl_api_function<void(enum_type, int_type, int_type), nullptr>
      MultiTexCoord2i;
    gl_api_function<void(enum_type, int_type, int_type, int_type), nullptr>
      MultiTexCoord3i;
    gl_api_function<
      void(enum_type, int_type, int_type, int_type, int_type),
      nullptr>
      MultiTexCoord4i;

    gl_api_function<void(enum_type, float_type), nullptr> MultiTexCoord1f;
    gl_api_function<void(enum_type, float_type, float_type), nullptr>
      MultiTexCoord2f;
    gl_api_function<void(enum_type, float_type, float_type, float_type), nullptr>
      MultiTexCoord3f;
    gl_api_function<
      void(enum_type, float_type, float_type, float_type, float_type),
      nullptr>
      MultiTexCoord4f;

    // matrix compatibility
    gl_api_function<void(enum_type), nullptr> MatrixMode;

    gl_api_function<void(void), nullptr> PushMatrix;
    gl_api_function<void(void), nullptr> PopMatrix;

    gl_api_function<void(enum_type), nullptr> MatrixPushEXT;
    gl_api_function<void(enum_type), nullptr> MatrixPopEXT;

    gl_api_function<void(), nullptr> LoadIdentity;
    gl_api_function<void(enum_type), nullptr> MatrixLoadIdentityEXT;

    gl_api_function<void(float_type, float_type, float_type), nullptr>
      Translatef;

    gl_api_function<void(double_type, double_type, double_type), nullptr>
      Translated;

    gl_api_function<void(enum_type, float_type, float_type, float_type), nullptr>
      MatrixTranslatefEXT;

    gl_api_function<
      void(enum_type, double_type, double_type, double_type),
      nullptr>
      MatrixTranslatedEXT;

    gl_api_function<void(float_type, float_type, float_type, float_type), nullptr>
      Rotatef;

    gl_api_function<
      void(double_type, double_type, double_type, double_type),
      nullptr>
      Rotated;

    gl_api_function<
      void(enum_type, float_type, float_type, float_type, float_type),
      nullptr>
      MatrixRotatefEXT;

    gl_api_function<
      void(enum_type, double_type, double_type, double_type, double_type),
      nullptr>
      MatrixRotatedEXT;

    gl_api_function<void(float_type, float_type, float_type), nullptr> Scalef;

    gl_api_function<void(double_type, double_type, double_type), nullptr> Scaled;

    gl_api_function<void(enum_type, float_type, float_type, float_type), nullptr>
      MatrixScalefEXT;

    gl_api_function<
      void(enum_type, double_type, double_type, double_type),
      nullptr>
      MatrixScaledEXT;

    gl_api_function<
      void(
        double_type,
        double_type,
        double_type,
        double_type,
        double_type,
        double_type),
      nullptr>
      Frustum;

    gl_api_function<
      void(
        double_type,
        double_type,
        double_type,
        double_type,
        double_type,
        double_type),
      nullptr>
      Ortho;

    gl_api_function<
      void(
        enum_type,
        double_type,
        double_type,
        double_type,
        double_type,
        double_type),
      nullptr>
      MatrixFrustumEXT;

    gl_api_function<
      void(
        enum_type,
        double_type,
        double_type,
        double_type,
        double_type,
        double_type),
      nullptr>
      MatrixOrthoEXT;

    gl_api_function<void(const float_type[16]), nullptr> LoadMatrixf;
    gl_api_function<void(const double_type[16]), nullptr> LoadMatrixd;

    gl_api_function<void(enum_type, const float_type[16]), nullptr>
      MatrixLoadfEXT;
    gl_api_function<void(enum_type, const double_type[16]), nullptr>
      MatrixLoaddEXT;

    gl_api_function<void(const float_type[16]), nullptr> MultMatrixf;
    gl_api_function<void(const double_type[16]), nullptr> MultMatrixd;

    gl_api_function<void(enum_type, const float_type[16]), nullptr>
      MatrixMultfEXT;
    gl_api_function<void(enum_type, const double_type[16]), nullptr>
      MatrixMultdEXT;

    gl_api_function<void(const float_type[16]), nullptr> LoadTransposeMatrixf;
    gl_api_function<void(const double_type[16]), nullptr> LoadTransposeMatrixd;

    gl_api_function<void(enum_type, const float_type[16]), nullptr>
      MatrixLoadTransposefEXT;
    gl_api_function<void(enum_type, const double_type[16]), nullptr>
      MatrixLoadTransposedEXT;

    gl_api_function<void(const float_type[16]), nullptr> MultTransposeMatrixf;
    gl_api_function<void(const double_type[16]), nullptr> MultTransposeMatrixd;

    gl_api_function<void(enum_type, const float_type[16]), nullptr>
      MatrixMultTransposefEXT;
    gl_api_function<void(enum_type, const double_type[16]), nullptr>
      MatrixMultTransposedEXT;

    // nv path rendering
    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(MatrixLoad3x2fNV)>
      MatrixLoad3x2fNV;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(MatrixLoad3x3fNV)>
      MatrixLoad3x3fNV;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(MatrixLoadTranspose3x3fNV)>
      MatrixLoadTranspose3x3fNV;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(MatrixMult3x2fNV)>
      MatrixMult3x2fNV;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(MatrixMult3x3fNV)>
      MatrixMult3x3fNV;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(MatrixMultTranspose3x3fNV)>
      MatrixMultTranspose3x3fNV;

    gl_api_function<uint_type(sizei_type), OGLPLUS_GL_STATIC_FUNC(GenPathsNV)>
      GenPathsNV;

    gl_api_function<
      void(uint_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DeletePathsNV)>
      DeletePathsNV;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsPathNV)>
      IsPathNV;

    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(PathParameterivNV)>
      PathParameterivNV;

    gl_api_function<
      void(uint_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(PathParameteriNV)>
      PathParameteriNV;

    gl_api_function<
      void(uint_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(PathParameterfvNV)>
      PathParameterfvNV;

    gl_api_function<
      void(uint_type, enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PathParameterfNV)>
      PathParameterfNV;

    gl_api_function<
      void(
        uint_type,
        sizei_type,
        const ubyte_type*,
        sizei_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(PathCommandsNV)>
      PathCommandsNV;

    gl_api_function<
      void(
        uint_type,
        sizei_type,
        sizei_type,
        sizei_type,
        const ubyte_type*,
        sizei_type,
        enum_type,
        const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(PathSubCommandsNV)>
      PathSubCommandsNV;

    gl_api_function<
      void(uint_type, sizei_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(PathCoordsNV)>
      PathCoordsNV;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(PathSubCoordsNV)>
      PathSubCoordsNV;

    gl_api_function<
      void(uint_type, enum_type, sizei_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(PathStringNV)>
      PathStringNV;

    gl_api_function<
      void(
        uint_type,
        enum_type,
        const_void_ptr_type,
        bitfield_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        enum_type,
        uint_type,
        float_type),
      OGLPLUS_GL_STATIC_FUNC(PathGlyphsNV)>
      PathGlyphsNV;

    gl_api_function<
      void(
        uint_type,
        enum_type,
        const_void_ptr_type,
        bitfield_type,
        uint_type,
        sizei_type,
        enum_type,
        uint_type,
        float_type),
      OGLPLUS_GL_STATIC_FUNC(PathGlyphRangeNV)>
      PathGlyphRangeNV;

    gl_api_function<
      enum_type(
        uint_type,
        enum_type,
        const_void_ptr_type,
        bitfield_type,
        uint_type,
        sizei_type,
        uint_type,
        float_type),
      OGLPLUS_GL_STATIC_FUNC(PathGlyphIndexArrayNV)>
      PathGlyphIndexArrayNV;

    gl_api_function<
      enum_type(
        uint_type,
        enum_type,
        sizeiptr_type,
        const_void_ptr_type,
        sizei_type,
        uint_type,
        sizei_type,
        uint_type,
        float_type),
      OGLPLUS_GL_STATIC_FUNC(PathMemoryGlyphIndexArrayNV)>
      PathMemoryGlyphIndexArrayNV;

    gl_api_function<
      enum_type(
        enum_type,
        const_void_ptr_type,
        bitfield_type,
        uint_type,
        float_type,
        uint_type[2]),
      OGLPLUS_GL_STATIC_FUNC(PathGlyphIndexRangeNV)>
      PathGlyphIndexRangeNV;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(CopyPathNV)>
      CopyPathNV;

    gl_api_function<
      void(uint_type, uint_type, uint_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(InterpolatePathsNV)>
      InterpolatePathsNV;

    gl_api_function<
      void(uint_type, sizei_type, const uint_type[], const float_type[]),
      OGLPLUS_GL_STATIC_FUNC(WeightPathsNV)>
      WeightPathsNV;

    gl_api_function<
      void(uint_type, uint_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(TransformPathNV)>
      TransformPathNV;

    gl_api_function<
      void(enum_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(PathStencilFuncNV)>
      PathStencilFuncNV;

    gl_api_function<
      void(float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PathStencilDepthOffsetNV)>
      PathStencilDepthOffsetNV;

    gl_api_function<
      void(uint_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilFillPathNV)>
      StencilFillPathNV;

    gl_api_function<
      void(uint_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilStrokePathNV)>
      StencilStrokePathNV;

    gl_api_function<
      void(
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        enum_type,
        uint_type,
        enum_type,
        const float_type*),
      OGLPLUS_GL_STATIC_FUNC(StencilFillPathInstancedNV)>
      StencilFillPathInstancedNV;

    gl_api_function<
      void(
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        int_type,
        uint_type,
        enum_type,
        const float_type*),
      OGLPLUS_GL_STATIC_FUNC(StencilStrokePathInstancedNV)>
      StencilStrokePathInstancedNV;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(PathCoverDepthFuncNV)>
      PathCoverDepthFuncNV;

    gl_api_function<
      void(enum_type, enum_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(PathColorGenNV)>
      PathColorGenNV;

    gl_api_function<
      void(enum_type, enum_type, int_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(PathTexGenNV)>
      PathTexGenNV;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(PathFogGenNV)>
      PathFogGenNV;

    gl_api_function<
      void(uint_type, int_type, enum_type, int_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramPathFragmentInputGenNV)>
      ProgramPathFragmentInputGenNV;

    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(CoverFillPathNV)>
      CoverFillPathNV;

    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(CoverStrokePathNV)>
      CoverStrokePathNV;

    gl_api_function<
      void(
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        enum_type,
        enum_type,
        const float_type*),
      OGLPLUS_GL_STATIC_FUNC(CoverFillPathInstancedNV)>
      CoverFillPathInstancedNV;

    gl_api_function<
      void(
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        enum_type,
        enum_type,
        const float_type*),
      OGLPLUS_GL_STATIC_FUNC(CoverStrokePathInstancedNV)>
      CoverStrokePathInstancedNV;

    gl_api_function<
      void(uint_type, enum_type, uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(StencilThenCoverFillPathNV)>
      StencilThenCoverFillPathNV;

    gl_api_function<
      void(uint_type, int_type, uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(StencilThenCoverStrokePathNV)>
      StencilThenCoverStrokePathNV;

    gl_api_function<
      void(
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        enum_type,
        uint_type,
        enum_type,
        enum_type,
        const float_type*),
      OGLPLUS_GL_STATIC_FUNC(StencilThenCoverFillPathInstancedNV)>
      StencilThenCoverFillPathInstancedNV;

    gl_api_function<
      void(
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        int_type,
        uint_type,
        enum_type,
        enum_type,
        const float_type*),
      OGLPLUS_GL_STATIC_FUNC(StencilThenCoverStrokePathInstancedNV)>
      StencilThenCoverStrokePathInstancedNV;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathParameterivNV)>
      GetPathParameterivNV;

    gl_api_function<
      void(uint_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathParameterfvNV)>
      GetPathParameterfvNV;

    gl_api_function<
      void(uint_type, ubyte_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathCommandsNV)>
      GetPathCommandsNV;

    gl_api_function<
      void(uint_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathCoordsNV)>
      GetPathCoordsNV;

    gl_api_function<
      void(uint_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathDashArrayNV)>
      GetPathDashArrayNV;

    gl_api_function<
      void(
        bitfield_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        sizei_type,
        float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathMetricsNV)>
      GetPathMetricsNV;

    gl_api_function<
      void(bitfield_type, uint_type, sizei_type, sizei_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathMetricRangeNV)>
      GetPathMetricRangeNV;

    gl_api_function<
      void(
        enum_type,
        sizei_type,
        enum_type,
        const_void_ptr_type,
        uint_type,
        float_type,
        float_type,
        enum_type,
        float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathSpacingNV)>
      GetPathSpacingNV;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathColorGenivNV)>
      GetPathColorGenivNV;

    gl_api_function<
      void(enum_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathColorGenfvNV)>
      GetPathColorGenfvNV;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathTexGenivNV)>
      GetPathTexGenivNV;

    gl_api_function<
      void(enum_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPathTexGenfvNV)>
      GetPathTexGenfvNV;

    gl_api_function<
      float_type(uint_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(GetPathLengthNV)>
      GetPathLengthNV;

    gl_api_function<
      bool_type(uint_type, uint_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(IsPointInFillPathNV)>
      IsPointInFillPathNV;

    gl_api_function<
      bool_type(uint_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(IsPointInStrokePathNV)>
      IsPointInStrokePathNV;

    gl_api_function<
      bool_type(
        uint_type,
        sizei_type,
        sizei_type,
        float_type,
        float_type*,
        float_type*,
        float_type*,
        float_type*),
      OGLPLUS_GL_STATIC_FUNC(PointAlongPathNV)>
      PointAlongPathNV;

    // hints
    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(MaxShaderCompilerThreadsARB)>
      MaxShaderCompilerThreadsARB;

    gl_api_function<void(enum_type, enum_type), OGLPLUS_GL_STATIC_FUNC(Hint)>
      Hint;

    // flush/finish
    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(Flush)> Flush;
    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(Finish)> Finish;

    basic_gl_c_api(api_traits& traits);
};
//------------------------------------------------------------------------------
using gl_c_api = basic_gl_c_api<gl_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_C_API_HPP
