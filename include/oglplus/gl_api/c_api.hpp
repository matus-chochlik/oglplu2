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

    gl_api_function<void(bitfield_type), OGLPLUS_GL_STATIC_FUNC(MemoryBarrier)>
      MemoryBarrier;

    gl_api_function<
      void(bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(MemoryBarrierByRegion)>
      MemoryBarrierByRegion;

    // object ops
    gl_api_function<
      sync_type(enum_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(FenceSync)>
      FenceSync;

    gl_api_function<void(sync_type), OGLPLUS_GL_STATIC_FUNC(DeleteSync)>
      DeleteSync;

    gl_api_function<bool_type(sync_type), OGLPLUS_GL_STATIC_FUNC(IsSync)> IsSync;

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
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateVertexArrays)>
      CreateVertexArrays;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteVertexArrays)>
      DeleteVertexArrays;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsVertexArray)>
      IsVertexArray;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(BindVertexArray)>
      BindVertexArray;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayElementBuffer)>
      VertexArrayElementBuffer;

    gl_api_function<
      void(uint_type, uint_type, intptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(BindVertexBuffer)>
      BindVertexBuffer;

    gl_api_function<
      void(uint_type, uint_type, uint_type, intptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayVertexBuffer)>
      VertexArrayVertexBuffer;

    gl_api_function<
      void(
        uint_type,
        sizei_type,
        const uint_type*,
        const intptr_type*,
        const sizei_type*),
      OGLPLUS_GL_STATIC_FUNC(BindVertexBuffers)>
      BindVertexBuffers;

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

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribBinding)>
      VertexAttribBinding;

    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayAttribBinding)>
      VertexArrayAttribBinding;

    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(EnableVertexAttribArray)>
      EnableVertexAttribArray;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(EnableVertexArrayAttrib)>
      EnableVertexArrayAttrib;

    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(DisableVertexAttribArray)>
      DisableVertexAttribArray;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DisableVertexArrayAttrib)>
      DisableVertexArrayAttrib;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexBindingDivisor)>
      VertexBindingDivisor;

    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayBindingDivisor)>
      VertexArrayBindingDivisor;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribDivisor)>
      VertexAttribDivisor;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenBuffers)>
      GenBuffers;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateBuffers)>
      CreateBuffers;

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

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(InvalidateBufferData)>
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

    // texture
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenTextures)>
      GenTextures;

    gl_api_function<
      void(enum_type, sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateTextures)>
      CreateTextures;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteTextures)>
      DeleteTextures;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsTexture)>
      IsTexture;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(ActiveTexture)>
      ActiveTexture;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindTexture)>
      BindTexture;

    gl_api_function<
      void(uint_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(BindTextures)>
      BindTextures;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindTextureUnit)>
      BindTextureUnit;

    gl_api_function<
      void(uint_type, uint_type, int_type, bool_type, int_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BindImageTexture)>
      BindImageTexture;

    gl_api_function<
      void(uint_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(BindImageTextures)>
      BindImageTextures;

    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage3D)>
      TexStorage3D;

    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage2D)>
      TexStorage2D;

    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage1D)>
      TexStorage1D;

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

    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(TexStorage2DMultisample)>
      TexStorage2DMultisample;

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

    gl_api_function<
      void(enum_type, int_type, enum_type, int_type, int_type, sizei_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTexImage1D)>
      CopyTexImage1D;

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

    gl_api_function<
      void(enum_type, int_type, int_type, int_type, int_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTexSubImage1D)>
      CopyTexSubImage1D;

    // dsa texture
    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage3D)>
      TextureStorage3D;

    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage2D)>
      TextureStorage2D;

    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage1D)>
      TextureStorage1D;

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

    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type, sizei_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(TextureStorage2DMultisample)>
      TextureStorage2DMultisample;

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

    gl_api_function<
      void(uint_type, int_type, int_type, int_type, int_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(CopyTextureSubImage1D)>
      CopyTextureSubImage1D;

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

    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(TexImage2DMultisample)>
      TexImage2DMultisample;

    gl_api_function<
      void(enum_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(TexBuffer)>
      TexBuffer;

    gl_api_function<
      void(enum_type, enum_type, uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(TexBufferRange)>
      TexBufferRange;

    gl_api_function<
      void(uint_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(TextureBuffer)>
      TextureBuffer;

    gl_api_function<
      void(uint_type, enum_type, uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(TextureBufferRange)>
      TextureBufferRange;

    gl_api_function<
      void(enum_type, enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(TexParameterf)>
      TexParameterf;

    gl_api_function<
      void(enum_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(TexParameteri)>
      TexParameteri;

    gl_api_function<
      void(enum_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(TexParameterfv)>
      TexParameterfv;

    gl_api_function<
      void(enum_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(TexParameteriv)>
      TexParameteriv;

    gl_api_function<
      void(enum_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(TexParameterIiv)>
      TexParameterIiv;

    gl_api_function<
      void(enum_type, enum_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(TexParameterIuiv)>
      TexParameterIuiv;

    gl_api_function<
      void(uint_type, enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(TextureParameterf)>
      TextureParameterf;

    gl_api_function<
      void(uint_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(TextureParameteri)>
      TextureParameteri;

    gl_api_function<
      void(uint_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(TextureParameterfv)>
      TextureParameterfv;

    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(TextureParameteriv)>
      TextureParameteriv;

    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(TextureParameterIiv)>
      TextureParameterIiv;

    gl_api_function<
      void(uint_type, enum_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(TextureParameterIuiv)>
      TextureParameterIuiv;

    gl_api_function<
      void(enum_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexParameterfv)>
      GetTexParameterfv;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexParameteriv)>
      GetTexParameteriv;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexParameterIiv)>
      GetTexParameterIiv;

    gl_api_function<
      void(enum_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexParameterIuiv)>
      GetTexParameterIuiv;

    gl_api_function<
      void(enum_type, int_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexLevelParameterfv)>
      GetTexLevelParameterfv;

    gl_api_function<
      void(enum_type, int_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTexLevelParameteriv)>
      GetTexLevelParameteriv;

    gl_api_function<
      void(enum_type, int_type, enum_type, enum_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetTexImage)>
      GetTexImage;

    gl_api_function<
      void(enum_type, int_type, enum_type, enum_type, sizei_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetnTexImage)>
      GetnTexImage;

    gl_api_function<
      void(enum_type, int_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetCompressedTexImage)>
      GetCompressedTexImage;

    gl_api_function<
      void(enum_type, int_type, sizei_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetnCompressedTexImage)>
      GetnCompressedTexImage;

    gl_api_function<
      void(uint_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureParameterfv)>
      GetTextureParameterfv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureParameteriv)>
      GetTextureParameteriv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureParameterIiv)>
      GetTextureParameterIiv;

    gl_api_function<
      void(uint_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureParameterIuiv)>
      GetTextureParameterIuiv;

    gl_api_function<
      void(uint_type, int_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureLevelParameterfv)>
      GetTextureLevelParameterfv;

    gl_api_function<
      void(uint_type, int_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTextureLevelParameteriv)>
      GetTextureLevelParameteriv;

    gl_api_function<
      void(uint_type, int_type, enum_type, enum_type, sizei_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetTextureImage)>
      GetTextureImage;

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

    gl_api_function<
      void(uint_type, int_type, sizei_type, void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(GetCompressedTextureImage)>
      GetCompressedTextureImage;

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

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(GenerateMipmap)>
      GenerateMipmap;

    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(GenerateTextureMipmap)>
      GenerateTextureMipmap;

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

    gl_api_function<
      void(uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(InvalidateTexImage)>
      InvalidateTexImage;

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

    gl_api_function<
      void(uint_type, int_type, enum_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(ClearTexImage)>
      ClearTexImage;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(TextureBarrier)>
      TextureBarrier;

    // samplers
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenSamplers)>
      GenSamplers;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateSamplers)>
      CreateSamplers;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteSamplers)>
      DeleteSamplers;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsSampler)>
      IsSampler;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindSampler)>
      BindSampler;

    gl_api_function<
      void(uint_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(BindSamplers)>
      BindSamplers;

    gl_api_function<
      void(uint_type, enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameterf)>
      SamplerParameterf;

    gl_api_function<
      void(uint_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameteri)>
      SamplerParameteri;

    gl_api_function<
      void(uint_type, enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameterfv)>
      SamplerParameterfv;

    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameteriv)>
      SamplerParameteriv;

    gl_api_function<
      void(uint_type, enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameterIiv)>
      SamplerParameterIiv;

    gl_api_function<
      void(uint_type, enum_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(SamplerParameterIuiv)>
      SamplerParameterIuiv;

    gl_api_function<
      void(uint_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSamplerParameterfv)>
      GetSamplerParameterfv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSamplerParameteriv)>
      GetSamplerParameteriv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSamplerParameterIiv)>
      GetSamplerParameterIiv;

    gl_api_function<
      void(uint_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSamplerParameterIuiv)>
      GetSamplerParameterIuiv;

    // renderbuffer object
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenRenderbuffers)>
      GenRenderbuffers;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateRenderbuffers)>
      CreateRenderbuffers;

    gl_api_function<
      void(sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(DeleteRenderbuffers)>
      DeleteRenderbuffers;

    gl_api_function<bool_type(uint_type), OGLPLUS_GL_STATIC_FUNC(IsRenderbuffer)>
      IsRenderbuffer;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(BindRenderbuffer)>
      BindRenderbuffer;

    gl_api_function<
      void(enum_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(RenderbufferStorage)>
      RenderbufferStorage;

    gl_api_function<
      void(uint_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(NamedRenderbufferStorage)>
      NamedRenderbufferStorage;

    gl_api_function<
      void(enum_type, sizei_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(RenderbufferStorageMultisample)>
      RenderbufferStorageMultisample;

    gl_api_function<
      void(uint_type, sizei_type, enum_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(NamedRenderbufferStorageMultisample)>
      NamedRenderbufferStorageMultisample;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetRenderbufferParameteriv)>
      GetRenderbufferParameteriv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedRenderbufferParameteriv)>
      GetNamedRenderbufferParameteriv;

    // framebuffer objects
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenFramebuffers)>
      GenFramebuffers;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateFramebuffers)>
      CreateFramebuffers;

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

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(DrawBuffer)>
      DrawBuffer;

    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferDrawBuffer)>
      NamedFramebufferDrawBuffer;

    gl_api_function<
      void(sizei_type, const enum_type*),
      OGLPLUS_GL_STATIC_FUNC(DrawBuffers)>
      DrawBuffers;

    gl_api_function<
      void(uint_type, sizei_type, const enum_type*),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferDrawBuffers)>
      NamedFramebufferDrawBuffers;

    gl_api_function<
      void(enum_type, int_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferfv)>
      ClearBufferfv;

    gl_api_function<
      void(enum_type, int_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferiv)>
      ClearBufferiv;

    gl_api_function<
      void(enum_type, int_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferuiv)>
      ClearBufferuiv;

    gl_api_function<
      void(enum_type, int_type, float_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ClearBufferfi)>
      ClearBufferfi;

    gl_api_function<
      void(uint_type, enum_type, int_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedFramebufferfv)>
      ClearNamedFramebufferfv;

    gl_api_function<
      void(uint_type, enum_type, int_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedFramebufferiv)>
      ClearNamedFramebufferiv;

    gl_api_function<
      void(uint_type, enum_type, int_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedFramebufferuiv)>
      ClearNamedFramebufferuiv;

    gl_api_function<
      void(uint_type, enum_type, int_type, float_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ClearNamedFramebufferfi)>
      ClearNamedFramebufferfi;

    gl_api_function<
      void(enum_type, sizei_type, const enum_type*),
      OGLPLUS_GL_STATIC_FUNC(InvalidateFramebuffer)>
      InvalidateFramebuffer;

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

    gl_api_function<
      void(uint_type, sizei_type, const enum_type*),
      OGLPLUS_GL_STATIC_FUNC(InvalidateFramebuffer)>
      InvalidateNamedFramebufferData;

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

    gl_api_function<
      void(enum_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferParameteri)>
      FramebufferParameteri;

    gl_api_function<
      void(uint_type, enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferParameteri)>
      NamedFramebufferParameteri;

    gl_api_function<
      void(enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFramebufferParameteriv)>
      GetFramebufferParameteriv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedFramebufferParameteriv)>
      GetNamedFramebufferParameteriv;

    gl_api_function<
      void(enum_type, enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFramebufferAttachmentParameteriv)>
      GetFramebufferAttachmentParameteriv;

    gl_api_function<
      void(uint_type, enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetNamedFramebufferAttachmentParameteriv)>
      GetNamedFramebufferAttachmentParameteriv;

    gl_api_function<
      void(enum_type, enum_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferRenderbuffer)>
      FramebufferRenderbuffer;

    gl_api_function<
      void(uint_type, enum_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferRenderbuffer)>
      NamedFramebufferRenderbuffer;

    gl_api_function<
      void(enum_type, enum_type, uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTexture)>
      FramebufferTexture;

    gl_api_function<
      void(uint_type, enum_type, uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferTexture)>
      NamedFramebufferTexture;

    gl_api_function<
      void(enum_type, enum_type, enum_type, uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTexture1D)>
      FramebufferTexture1D;

    gl_api_function<
      void(enum_type, enum_type, enum_type, uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTexture2D)>
      FramebufferTexture2D;

    gl_api_function<
      void(enum_type, enum_type, enum_type, uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTexture3D)>
      FramebufferTexture3D;

    gl_api_function<
      void(enum_type, enum_type, uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(FramebufferTextureLayer)>
      FramebufferTextureLayer;

    gl_api_function<
      void(uint_type, enum_type, uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferTextureLayer)>
      NamedFramebufferTextureLayer;

    gl_api_function<
      enum_type(enum_type),
      OGLPLUS_GL_STATIC_FUNC(CheckFramebufferStatus)>
      CheckFramebufferStatus;

    gl_api_function<
      enum_type(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(CheckNamedFramebufferStatus)>
      CheckNamedFramebufferStatus;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(ReadBuffer)>
      ReadBuffer;

    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(NamedFramebufferReadBuffer)>
      NamedFramebufferReadBuffer;

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

    // transform feedback objects
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenTransformFeedbacks)>
      GenTransformFeedbacks;

    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateTransformFeedbacks)>
      CreateTransformFeedbacks;

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
      void(enum_type),
      OGLPLUS_GL_STATIC_FUNC(BeginTransformFeedback)>
      BeginTransformFeedback;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(PauseTransformFeedback)>
      PauseTransformFeedback;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(ResumeTransformFeedback)>
      ResumeTransformFeedback;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(EndTransformFeedback)>
      EndTransformFeedback;

    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(TransformFeedbackBufferBase)>
      TransformFeedbackBufferBase;

    gl_api_function<
      void(uint_type, uint_type, uint_type, intptr_type, sizeiptr_type),
      OGLPLUS_GL_STATIC_FUNC(TransformFeedbackBufferRange)>
      TransformFeedbackBufferRange;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTransformFeedbackiv)>
      GetTransformFeedbackiv;

    gl_api_function<
      void(uint_type, enum_type, uint_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTransformFeedbacki_v)>
      GetTransformFeedbacki_v;

    gl_api_function<
      void(uint_type, enum_type, uint_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetTransformFeedbacki64_v)>
      GetTransformFeedbacki64_v;

    // query objects
    gl_api_function<
      void(sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GenQueries)>
      GenQueries;

    gl_api_function<
      void(enum_type, sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(CreateQueries)>
      CreateQueries;

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

    // conditional rendering
    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BeginConditionalRender)>
      BeginConditionalRender;

    gl_api_function<void(), OGLPLUS_GL_STATIC_FUNC(EndConditionalRender)>
      EndConditionalRender;

    // program pipelines
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

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(BindProgramPipeline)>
      BindProgramPipeline;

    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(ValidateProgramPipeline)>
      ValidateProgramPipeline;

    gl_api_function<
      void(uint_type, bitfield_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(UseProgramStages)>
      UseProgramStages;

    gl_api_function<
      void(uint_type, enum_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramStageiv)>
      GetProgramStageiv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramPipelineiv)>
      GetProgramPipelineiv;

    gl_api_function<
      void(uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetProgramPipelineInfoLog)>
      GetProgramPipelineInfoLog;

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
      void(uint_type, sizei_type, const char_type* const*, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(nullptr)>
      CompileShaderInclude;

    gl_api_function<
      void(sizei_type, const uint_type*, enum_type, const_void_ptr_type, sizei_type),
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

    gl_api_function<
      void(enum_type, enum_type, int_type*, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetShaderPrecisionFormat)>
      GetShaderPrecisionFormat;

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

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(UseProgram)>
      UseProgram;

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
      void(uint_type, sizei_type, sizei_type*, char_type*),
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
      void(uint_type, enum_type, uint_type, sizei_type, sizei_type*, char_type*),
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

    gl_api_function<
      void(uint_type, uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(BindAttribLocation)>
      BindAttribLocation;

    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetAttribLocation)>
      GetAttribLocation;

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

    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformLocation)>
      GetUniformLocation;

    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformBlockIndex)>
      GetUniformBlockIndex;

    gl_api_function<
      void(uint_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveUniformName)>
      GetActiveUniformName;

    gl_api_function<
      uint_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSubroutineIndex)>
      GetSubroutineIndex;

    gl_api_function<
      void(uint_type, enum_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveSubroutineName)>
      GetActiveSubroutineName;

    gl_api_function<
      void(uint_type, enum_type, uint_type, sizei_type, sizei_type*, char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveSubroutineUniformName)>
      GetActiveSubroutineUniformName;

    gl_api_function<
      int_type(uint_type, enum_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetSubroutineUniformLocation)>
      GetSubroutineUniformLocation;

    gl_api_function<
      void(uint_type, enum_type, uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetActiveSubroutineUniformiv)>
      GetActiveSubroutineUniformiv;

    gl_api_function<
      void(uint_type, sizei_type, const char_type* const*, enum_type),
      OGLPLUS_GL_STATIC_FUNC(TransformFeedbackVaryings)>
      TransformFeedbackVaryings;

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

    gl_api_function<
      void(uint_type, uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(BindFragDataLocation)>
      BindFragDataLocation;

    gl_api_function<
      void(uint_type, uint_type, uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(BindFragDataLocationIndexed)>
      BindFragDataLocationIndexed;

    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFragDataLocation)>
      GetFragDataLocation;

    gl_api_function<
      int_type(uint_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(GetFragDataIndex)>
      GetFragDataIndex;

    // uniform subroutine
    gl_api_function<
      void(enum_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(UniformSubroutinesuiv)>
      UniformSubroutinesuiv;

    gl_api_function<
      void(enum_type, int_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformSubroutineuiv)>
      GetUniformSubroutineuiv;

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

    gl_api_function<void(int_type, uint_type), OGLPLUS_GL_STATIC_FUNC(Uniform1ui)>
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

    gl_api_function<void(int_type, float_type), OGLPLUS_GL_STATIC_FUNC(Uniform1f)>
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

    gl_api_function<
      void(uint_type, int_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformfv)>
      GetUniformfv;

    gl_api_function<
      void(uint_type, int_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformdv)>
      GetUniformdv;

    gl_api_function<
      void(uint_type, int_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformiv)>
      GetUniformiv;

    gl_api_function<
      void(uint_type, int_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetUniformuiv)>
      GetUniformuiv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetnUniformfv)>
      GetnUniformfv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetnUniformdv)>
      GetnUniformdv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetnUniformiv)>
      GetnUniformiv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetnUniformuiv)>
      GetnUniformuiv;

    // program uniform
    gl_api_function<
      void(uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1i)>
      ProgramUniform1i;

    gl_api_function<
      void(uint_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2i)>
      ProgramUniform2i;

    gl_api_function<
      void(uint_type, int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3i)>
      ProgramUniform3i;

    gl_api_function<
      void(uint_type, int_type, int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4i)>
      ProgramUniform4i;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1iv)>
      ProgramUniform1iv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2iv)>
      ProgramUniform2iv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3iv)>
      ProgramUniform3iv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4iv)>
      ProgramUniform4iv;

    gl_api_function<
      void(uint_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1ui)>
      ProgramUniform1ui;

    gl_api_function<
      void(uint_type, int_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2ui)>
      ProgramUniform2ui;

    gl_api_function<
      void(uint_type, int_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3ui)>
      ProgramUniform3ui;

    gl_api_function<
      void(uint_type, int_type, uint_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4ui)>
      ProgramUniform4ui;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1uiv)>
      ProgramUniform1uiv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2uiv)>
      ProgramUniform2uiv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3uiv)>
      ProgramUniform3uiv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4uiv)>
      ProgramUniform4uiv;

    gl_api_function<
      void(uint_type, int_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1f)>
      ProgramUniform1f;

    gl_api_function<
      void(uint_type, int_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2f)>
      ProgramUniform2f;

    gl_api_function<
      void(uint_type, int_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3f)>
      ProgramUniform3f;

    gl_api_function<
      void(uint_type, int_type, float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4f)>
      ProgramUniform4f;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform1fv)>
      ProgramUniform1fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform2fv)>
      ProgramUniform2fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform3fv)>
      ProgramUniform3fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniform4fv)>
      ProgramUniform4fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix2fv)>
      ProgramUniformMatrix2fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix3fv)>
      ProgramUniformMatrix3fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix4fv)>
      ProgramUniformMatrix4fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix2x3fv)>
      ProgramUniformMatrix2x3fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix3x2fv)>
      ProgramUniformMatrix3x2fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix2x4fv)>
      ProgramUniformMatrix2x4fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix4x2fv)>
      ProgramUniformMatrix4x2fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix3x4fv)>
      ProgramUniformMatrix3x4fv;

    gl_api_function<
      void(uint_type, int_type, sizei_type, bool_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ProgramUniformMatrix4x3fv)>
      ProgramUniformMatrix4x3fv;

    // uniform blocks
    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(UniformBlockBinding)>
      UniformBlockBinding;

    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(ShaderStorageBlockBinding)>
      ShaderStorageBlockBinding;

    // vertex attrib
    gl_api_function<
      void(uint_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1f)>
      VertexAttrib1f;

    gl_api_function<
      void(uint_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2f)>
      VertexAttrib2f;

    gl_api_function<
      void(uint_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3f)>
      VertexAttrib3f;

    gl_api_function<
      void(uint_type, float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4f)>
      VertexAttrib4f;

    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1fv)>
      VertexAttrib1fv;

    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2fv)>
      VertexAttrib2fv;

    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3fv)>
      VertexAttrib3fv;

    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4fv)>
      VertexAttrib4fv;

    gl_api_function<
      void(uint_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1d)>
      VertexAttrib1d;

    gl_api_function<
      void(uint_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2d)>
      VertexAttrib2d;

    gl_api_function<
      void(uint_type, double_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3d)>
      VertexAttrib3d;

    gl_api_function<
      void(uint_type, double_type, double_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4d)>
      VertexAttrib4d;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1dv)>
      VertexAttrib1dv;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2dv)>
      VertexAttrib2dv;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3dv)>
      VertexAttrib3dv;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4dv)>
      VertexAttrib4dv;

    gl_api_function<
      void(uint_type, short_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1s)>
      VertexAttrib1s;

    gl_api_function<
      void(uint_type, short_type, short_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2s)>
      VertexAttrib2s;

    gl_api_function<
      void(uint_type, short_type, short_type, short_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3s)>
      VertexAttrib3s;

    gl_api_function<
      void(uint_type, short_type, short_type, short_type, short_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4s)>
      VertexAttrib4s;

    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib1sv)>
      VertexAttrib1sv;

    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib2sv)>
      VertexAttrib2sv;

    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib3sv)>
      VertexAttrib3sv;

    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4sv)>
      VertexAttrib4sv;

    gl_api_function<
      void(uint_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI1i)>
      VertexAttribI1i;

    gl_api_function<
      void(uint_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI2i)>
      VertexAttribI2i;

    gl_api_function<
      void(uint_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI3i)>
      VertexAttribI3i;

    gl_api_function<
      void(uint_type, int_type, int_type, int_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4i)>
      VertexAttribI4i;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI1iv)>
      VertexAttribI1iv;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI2iv)>
      VertexAttribI2iv;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI3iv)>
      VertexAttribI3iv;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4iv)>
      VertexAttribI4iv;

    gl_api_function<
      void(uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI1ui)>
      VertexAttribI1ui;

    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI2ui)>
      VertexAttribI2ui;

    gl_api_function<
      void(uint_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI3ui)>
      VertexAttribI3ui;

    gl_api_function<
      void(uint_type, uint_type, uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4ui)>
      VertexAttribI4ui;

    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI1uiv)>
      VertexAttribI1uiv;

    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI2uiv)>
      VertexAttribI2uiv;

    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI3uiv)>
      VertexAttribI3uiv;

    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4uiv)>
      VertexAttribI4uiv;

    gl_api_function<
      void(uint_type, const byte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4bv)>
      VertexAttribI4bv;

    gl_api_function<
      void(uint_type, const ubyte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4ubv)>
      VertexAttribI4ubv;

    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4sv)>
      VertexAttribI4sv;

    gl_api_function<
      void(uint_type, const ushort_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribI4usv)>
      VertexAttribI4usv;

    gl_api_function<
      void(uint_type, const byte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4bv)>
      VertexAttrib4bv;

    gl_api_function<
      void(uint_type, const ubyte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4ubv)>
      VertexAttrib4ubv;

    gl_api_function<
      void(uint_type, const ushort_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4usv)>
      VertexAttrib4usv;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4iv)>
      VertexAttrib4iv;

    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4uiv)>
      VertexAttrib4uiv;

    gl_api_function<
      void(uint_type, ubyte_type, ubyte_type, ubyte_type, ubyte_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nub)>
      VertexAttrib4Nub;

    gl_api_function<
      void(uint_type, const byte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nbv)>
      VertexAttrib4Nbv;

    gl_api_function<
      void(uint_type, const ubyte_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nubv)>
      VertexAttrib4Nubv;

    gl_api_function<
      void(uint_type, const short_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nsv)>
      VertexAttrib4Nsv;

    gl_api_function<
      void(uint_type, const ushort_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nusv)>
      VertexAttrib4Nusv;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Niv)>
      VertexAttrib4Niv;

    gl_api_function<
      void(uint_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttrib4Nuiv)>
      VertexAttrib4Nuiv;

    gl_api_function<
      void(uint_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL1d)>
      VertexAttribL1d;

    gl_api_function<
      void(uint_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL2d)>
      VertexAttribL2d;

    gl_api_function<
      void(uint_type, double_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL3d)>
      VertexAttribL3d;

    gl_api_function<
      void(uint_type, double_type, double_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL4d)>
      VertexAttribL4d;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL1dv)>
      VertexAttribL1dv;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL2dv)>
      VertexAttribL2dv;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL3dv)>
      VertexAttribL3dv;

    gl_api_function<
      void(uint_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribL4dv)>
      VertexAttribL4dv;

    gl_api_function<
      void(uint_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP1ui)>
      VertexAttribP1ui;

    gl_api_function<
      void(uint_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP2ui)>
      VertexAttribP2ui;

    gl_api_function<
      void(uint_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP3ui)>
      VertexAttribP3ui;

    gl_api_function<
      void(uint_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP4ui)>
      VertexAttribP4ui;

    gl_api_function<
      void(uint_type, enum_type, bool_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP1uiv)>
      VertexAttribP1uiv;

    gl_api_function<
      void(uint_type, enum_type, bool_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP2uiv)>
      VertexAttribP2uiv;

    gl_api_function<
      void(uint_type, enum_type, bool_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP3uiv)>
      VertexAttribP3uiv;

    gl_api_function<
      void(uint_type, enum_type, bool_type, const uint_type*),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribP4uiv)>
      VertexAttribP4uiv;

    // vertex attrib format
    gl_api_function<
      void(uint_type, int_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribFormat)>
      VertexAttribFormat;

    gl_api_function<
      void(uint_type, int_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribIFormat)>
      VertexAttribIFormat;

    gl_api_function<
      void(uint_type, int_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribLFormat)>
      VertexAttribLFormat;

    gl_api_function<
      void(uint_type, uint_type, int_type, enum_type, bool_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayAttribFormat)>
      VertexArrayAttribFormat;

    gl_api_function<
      void(uint_type, uint_type, int_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayAttribIFormat)>
      VertexArrayAttribIFormat;

    gl_api_function<
      void(uint_type, uint_type, int_type, enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(VertexArrayAttribLFormat)>
      VertexArrayAttribLFormat;

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

    gl_api_function<
      void(uint_type, int_type, enum_type, sizei_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribIPointer)>
      VertexAttribIPointer;

    gl_api_function<
      void(uint_type, int_type, enum_type, sizei_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(VertexAttribLPointer)>
      VertexAttribLPointer;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexArrayiv)>
      GetVertexArrayiv;

    gl_api_function<
      void(uint_type, uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexArrayIndexediv)>
      GetVertexArrayIndexediv;

    gl_api_function<
      void(uint_type, uint_type, enum_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexArrayIndexed64iv)>
      GetVertexArrayIndexed64iv;

    gl_api_function<
      void(uint_type, enum_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribdv)>
      GetVertexAttribdv;

    gl_api_function<
      void(uint_type, enum_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribfv)>
      GetVertexAttribfv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribiv)>
      GetVertexAttribiv;

    gl_api_function<
      void(uint_type, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribIiv)>
      GetVertexAttribIiv;

    gl_api_function<
      void(uint_type, enum_type, uint_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribIuiv)>
      GetVertexAttribIuiv;

    gl_api_function<
      void(uint_type, enum_type, double_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribLdv)>
      GetVertexAttribLdv;

    gl_api_function<
      void(uint_type, enum_type, void_ptr_type*),
      OGLPLUS_GL_STATIC_FUNC(GetVertexAttribPointerv)>
      GetVertexAttribPointerv;

    // viewport
    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(ClipControl)>
      ClipControl;

    gl_api_function<
      void(double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRange)>
      DepthRange;

    gl_api_function<
      void(float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRangef)>
      DepthRangef;

    gl_api_function<
      void(uint_type, sizei_type, const double_type*),
      OGLPLUS_GL_STATIC_FUNC(DepthRangeArrayv)>
      DepthRangeArrayv;

    gl_api_function<
      void(uint_type, double_type, double_type),
      OGLPLUS_GL_STATIC_FUNC(DepthRangeIndexed)>
      DepthRangeIndexed;

    gl_api_function<
      void(int_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(Viewport)>
      Viewport;

    gl_api_function<
      void(uint_type, sizei_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ViewportArrayv)>
      ViewportArrayv;

    gl_api_function<
      void(uint_type, float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(ViewportIndexedf)>
      ViewportIndexedf;

    gl_api_function<
      void(uint_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(ViewportIndexedfv)>
      ViewportIndexedfv;

    // scissor test
    gl_api_function<
      void(int_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(Scissor)>
      Scissor;

    gl_api_function<
      void(uint_type, sizei_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ScissorArrayv)>
      ScissorArrayv;

    gl_api_function<
      void(uint_type, int_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(ScissorIndexed)>
      ScissorIndexed;

    gl_api_function<
      void(uint_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(ScissorIndexedv)>
      ScissorIndexedv;

    // stencil test
    gl_api_function<
      void(enum_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilFunc)>
      StencilFunc;

    gl_api_function<
      void(enum_type, enum_type, int_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilFuncSeparate)>
      StencilFuncSeparate;

    gl_api_function<
      void(enum_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(StencilOp)>
      StencilOp;

    gl_api_function<
      void(enum_type, enum_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(StencilOpSeparate)>
      StencilOpSeparate;

    // depth test
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(DepthFunc)>
      DepthFunc;

    // buffer masking
    gl_api_function<
      void(bool_type, bool_type, bool_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(ColorMask)>
      ColorMask;

    gl_api_function<
      void(uint_type, bool_type, bool_type, bool_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(ColorMaski)>
      ColorMaski;

    gl_api_function<void(bool_type), OGLPLUS_GL_STATIC_FUNC(DepthMask)>
      DepthMask;

    gl_api_function<void(uint_type), OGLPLUS_GL_STATIC_FUNC(StencilMask)>
      StencilMask;

    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(StencilMaskSeparate)>
      StencilMaskSeparate;

    // draw buffer clearing
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

    // draw parameters
    gl_api_function<
      void(uint_type),
      OGLPLUS_GL_STATIC_FUNC(PrimitiveRestartIndex)>
      PrimitiveRestartIndex;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(ProvokingVertex)>
      ProvokingVertex;

    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(LineWidth)>
      LineWidth;

    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(PointSize)>
      PointSize;

    gl_api_function<
      void(enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(PointParameteri)>
      PointParameteri;

    gl_api_function<
      void(enum_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PointParameterf)>
      PointParameterf;

    gl_api_function<
      void(enum_type, const int_type*),
      OGLPLUS_GL_STATIC_FUNC(PointParameteriv)>
      PointParameteriv;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(PointParameterfv)>
      PointParameterfv;

    gl_api_function<
      void(enum_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(PatchParameteri)>
      PatchParameteri;

    gl_api_function<
      void(enum_type, const float_type*),
      OGLPLUS_GL_STATIC_FUNC(PatchParameterfv)>
      PatchParameterfv;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(FrontFace)>
      FrontFace;

    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(CullFace)> CullFace;

    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(PolygonMode)>
      PolygonMode;

    gl_api_function<
      void(float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PolygonOffset)>
      PolygonOffset;

    gl_api_function<
      void(float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(PolygonOffsetClamp)>
      PolygonOffsetClamp;

    gl_api_function<
      void(float_type, bool_type),
      OGLPLUS_GL_STATIC_FUNC(SampleCoverage)>
      SampleCoverage;

    gl_api_function<
      void(uint_type, bitfield_type),
      OGLPLUS_GL_STATIC_FUNC(SampleMaski)>
      SampleMaski;

    gl_api_function<void(float_type), OGLPLUS_GL_STATIC_FUNC(MinSampleShading)>
      MinSampleShading;

    gl_api_function<
      void(enum_type, uint_type, float_type*),
      OGLPLUS_GL_STATIC_FUNC(GetMultisamplefv)>
      GetMultisamplefv;

    // blending
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(BlendEquation)>
      BlendEquation;

    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendEquationSeparate)>
      BlendEquationSeparate;

    gl_api_function<
      void(uint_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendEquationi)>
      BlendEquationi;

    gl_api_function<
      void(uint_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendEquationSeparatei)>
      BlendEquationSeparatei;

    gl_api_function<void(enum_type, enum_type), OGLPLUS_GL_STATIC_FUNC(BlendFunc)>
      BlendFunc;

    gl_api_function<
      void(enum_type, enum_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendFuncSeparate)>
      BlendFuncSeparate;

    gl_api_function<
      void(uint_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendFunci)>
      BlendFunci;

    gl_api_function<
      void(uint_type, enum_type, enum_type, enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(BlendFuncSeparatei)>
      BlendFuncSeparatei;

    gl_api_function<
      void(float_type, float_type, float_type, float_type),
      OGLPLUS_GL_STATIC_FUNC(BlendColor)>
      BlendColor;

    // logic operation
    gl_api_function<void(enum_type), OGLPLUS_GL_STATIC_FUNC(LogicOp)> LogicOp;

    // draw arrays
    gl_api_function<
      void(enum_type, int_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawArrays)>
      DrawArrays;

    gl_api_function<
      void(enum_type, int_type, sizei_type, sizei_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawArraysInstancedBaseInstance)>
      DrawArraysInstancedBaseInstance;

    gl_api_function<
      void(enum_type, int_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawArraysInstanced)>
      DrawArraysInstanced;

    gl_api_function<
      void(enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DrawArraysIndirect)>
      DrawArraysIndirect;

    gl_api_function<
      void(enum_type, const int_type*, const sizei_type*, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawArrays)>
      MultiDrawArrays;

    gl_api_function<
      void(enum_type, const_void_ptr_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawArraysIndirect)>
      MultiDrawArraysIndirect;

    gl_api_function<
      void(enum_type, const_void_ptr_type, intptr_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawArraysIndirectCount)>
      MultiDrawArraysIndirectCount;

    // draw elements
    gl_api_function<
      void(enum_type, sizei_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElements)>
      DrawElements;

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

    gl_api_function<
      void(enum_type, sizei_type, enum_type, const_void_ptr_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsInstanced)>
      DrawElementsInstanced;

    gl_api_function<
      void(enum_type, sizei_type, enum_type, const_void_ptr_type, int_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsBaseVertex)>
      DrawElementsBaseVertex;

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

    gl_api_function<
      void(enum_type, enum_type, const_void_ptr_type),
      OGLPLUS_GL_STATIC_FUNC(DrawElementsIndirect)>
      DrawElementsIndirect;

    gl_api_function<
      void(
        enum_type,
        const sizei_type*,
        enum_type,
        const const_void_ptr_type*,
        sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawElements)>
      MultiDrawElements;

    gl_api_function<
      void(enum_type, enum_type, const_void_ptr_type, sizei_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(MultiDrawElementsIndirect)>
      MultiDrawElementsIndirect;

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

    // draw transform feedback
    gl_api_function<
      void(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawTransformFeedback)>
      DrawTransformFeedback;

    gl_api_function<
      void(enum_type, uint_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawTransformFeedbackInstanced)>
      DrawTransformFeedbackInstanced;

    gl_api_function<
      void(enum_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DrawTransformFeedbackStream)>
      DrawTransformFeedbackStream;

    gl_api_function<
      void(enum_type, uint_type, uint_type, sizei_type),
      OGLPLUS_GL_STATIC_FUNC(DrawTransformFeedbackStreamInstanced)>
      DrawTransformFeedbackStreamInstanced;

    // compute
    gl_api_function<
      void(uint_type, uint_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(DispatchCompute)>
      DispatchCompute;

    gl_api_function<
      void(intptr_type),
      OGLPLUS_GL_STATIC_FUNC(DispatchComputeIndirect)>
      DispatchComputeIndirect;

    // framebufer reads/writes
    gl_api_function<
      void(enum_type, enum_type),
      OGLPLUS_GL_STATIC_FUNC(ClampColor)>
      ClampColor;

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

    // state queries
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
      void(enum_type, enum_type, enum_type, sizei_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(GetInternalformativ)>
      GetInternalformativ;

    gl_api_function<
      void(enum_type, enum_type, enum_type, sizei_type, int64_type*),
      OGLPLUS_GL_STATIC_FUNC(GetInternalformati64v)>
      GetInternalformati64v;

    gl_api_function<
      void(enum_type, void_ptr_type*),
      OGLPLUS_GL_STATIC_FUNC(GetPointerv)>
      GetPointerv;

    gl_api_function<
      const ubyte_type*(enum_type),
      OGLPLUS_GL_STATIC_FUNC(GetString)>
      GetString;

    gl_api_function<
      const ubyte_type*(enum_type, uint_type),
      OGLPLUS_GL_STATIC_FUNC(GetStringi)>
      GetStringi;

    // named strings
    gl_api_function<
      void(enum_type, int_type, const char_type*, int_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(nullptr)>
      NamedString;

    gl_api_function<
      void(int_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(nullptr)>
      DeleteNamedString;

    gl_api_function<
      bool_type(int_type, const char_type*),
      OGLPLUS_GL_STATIC_FUNC(nullptr)>
      IsNamedString;

    gl_api_function<
      void(int_type, const char_type*, enum_type, int_type*),
      OGLPLUS_GL_STATIC_FUNC(nullptr)>
      GetNamedStringiv;

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
