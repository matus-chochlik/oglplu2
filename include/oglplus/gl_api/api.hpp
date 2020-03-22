/**
 *  @file oglplus/gl_api/api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_API_HPP
#define OGLPLUS_GL_API_API_HPP

#include "../glsl/source_ref.hpp"
#include "../utils/quantities.hpp"
#include "c_api.hpp"
#include "enum_types.hpp"
#include "object_name.hpp"
#include "prog_var_loc.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>
#include <oglplus/utils/buffer_data.hpp>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
#define OGLPAFP(FUNC) decltype(c_api::FUNC), &c_api::FUNC
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_gl_api : public basic_gl_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using c_api = basic_gl_c_api<ApiTraits>;

    using sizei_type = typename gl_types::sizei_type;
    using sizeiptr_type = typename gl_types::sizeiptr_type;
    using int_type = typename gl_types::int_type;
    using uint_type = typename gl_types::uint_type;
    using int64_type = typename gl_types::int64_type;
    using intptr_type = typename gl_types::intptr_type;
    using bool_type = typename gl_types::bool_type;
    using char_type = typename gl_types::char_type;
    using enum_type = typename gl_types::enum_type;
    using float_type = typename gl_types::float_type;
    using double_type = typename gl_types::double_type;
    using bitfield_type = typename gl_types::bitfield_type;

    using sync_type = typename gl_types::sync_type;
    using name_type = typename gl_types::name_type;

    using void_ptr_type = typename gl_types::void_ptr_type;
    using const_void_ptr_type = typename gl_types::const_void_ptr_type;

    template <
      typename W,
      W c_api::*F,
      typename Signature = typename W::signature>
    class func;

    template <typename W, W c_api::*F, typename RVC, typename... Params>
    class func<W, F, RVC(Params...)>
      : public wrapped_c_api_function<c_api, api_traits, nothing_t, W, F> {
        using base = wrapped_c_api_function<c_api, api_traits, nothing_t, W, F>;

    private:
        template <typename Res>
        constexpr auto _check(Res&& res) const noexcept {
            res.error_code(this->api().GetError());
            return std::forward<Res>(res);
        }

    protected:
        template <typename... Args>
        constexpr auto _chkcall(Args&&... args) const noexcept {
            return this->_check(this->_call(std::forward<Args>(args)...));
        }

        using base::_conv;

        template <identifier_t I>
        static constexpr inline auto _conv(prog_var_location<I> loc) noexcept {
            return loc.index();
        }

        template <typename T>
        static constexpr inline auto _conv(degrees_t<T> angle) noexcept {
            return angle.value();
        }

    public:
        using base::base;

        constexpr auto operator()(Params... params) const noexcept {
            return this->_chkcall(_conv(params)...).cast_to(identity<RVC>{});
        }

        auto bind(Params... params) const noexcept {
            return [=] { return (*this)(params...); };
        }
    };

    // generate / create objects
    struct : func<OGLPAFP(FenceSync)> {
        using func<OGLPAFP(FenceSync)>::func;

        constexpr auto operator()(sync_condition cond) const noexcept {
            return this->_chkcall(enum_type(cond), bitfield_type(0));
        }

        constexpr auto operator()(
          sync_condition cond, enum_bitfield<sync_flag_bit> flags) const
          noexcept {
            return this->_chkcall(enum_type(cond), bitfield_type(flags));
        }
    } fence_sync;

    template <typename ObjTag, typename W, W c_api::*GenObjects>
    struct make_object_func : func<W, GenObjects> {
        using func<W, GenObjects>::func;

        constexpr auto operator()(span<name_type> names) const noexcept {
            return this->_chkcall(sizei_type(names.size()), names.data());
        }

        constexpr auto operator()() const noexcept {
            name_type n{};
            return this->_chkcall(1, &n).replaced_with(n).cast_to(
              identity<gl_owned_object_name<ObjTag>>{});
        }
    };

    struct : func<OGLPAFP(CreateShader)> {
        using func<OGLPAFP(CreateShader)>::func;

        constexpr auto operator()(shader_type type) const noexcept {
            return this->_chkcall(enum_type(type))
              .cast_to(identity<owned_shader_name>{});
        }
    } create_shader;

    struct : func<OGLPAFP(CreateProgram)> {
        using func<OGLPAFP(CreateProgram)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall().cast_to(identity<owned_program_name>{});
        }
    } create_program;

    make_object_func<buffer_tag, OGLPAFP(GenBuffers)> gen_buffers;

    make_object_func<buffer_tag, OGLPAFP(CreateBuffers)> create_buffers;

    make_object_func<framebuffer_tag, OGLPAFP(GenFramebuffers)>
      gen_framebuffers;

    make_object_func<framebuffer_tag, OGLPAFP(CreateFramebuffers)>
      create_framebuffers;

    make_object_func<program_pipeline_tag, OGLPAFP(GenProgramPipelines)>
      gen_program_pipelines;

    make_object_func<program_pipeline_tag, OGLPAFP(CreateProgramPipelines)>
      create_program_pipelines;

    make_object_func<query_tag, OGLPAFP(GenQueries)> gen_queries;

    make_object_func<query_tag, OGLPAFP(CreateQueries)> create_queries;

    make_object_func<renderbuffer_tag, OGLPAFP(GenRenderbuffers)>
      gen_renderbuffers;

    make_object_func<renderbuffer_tag, OGLPAFP(CreateRenderbuffers)>
      create_renderbuffers;

    make_object_func<sampler_tag, OGLPAFP(GenSamplers)> gen_samplers;

    make_object_func<sampler_tag, OGLPAFP(CreateSamplers)> create_samplers;

    make_object_func<texture_tag, OGLPAFP(GenTextures)> gen_textures;

    make_object_func<texture_tag, OGLPAFP(CreateTextures)> create_textures;

    make_object_func<transform_feedback_tag, OGLPAFP(GenTransformFeedbacks)>
      gen_transform_feedbacks;

    make_object_func<transform_feedback_tag, OGLPAFP(CreateTransformFeedbacks)>
      create_transform_feedbacks;

    make_object_func<vertex_array_tag, OGLPAFP(GenVertexArrays)>
      gen_vertex_arrays;

    make_object_func<vertex_array_tag, OGLPAFP(CreateVertexArrays)>
      create_vertex_arrays;

    struct : func<OGLPAFP(GenPathsNV)> {
        using func<OGLPAFP(GenPathsNV)>::func;

        constexpr auto operator()() const noexcept {
            return this->_chkcall(1).cast_to(identity<owned_path_nv_name>{});
        }
    } create_paths_nv;

    // delete objects
    struct : func<OGLPAFP(DeleteSync)> {
        using func<OGLPAFP(DeleteSync)>::func;

        constexpr auto operator()(sync_type sync) const noexcept {
            return this->_chkcall(sync);
        }

        auto bind(sync_type sync) const noexcept {
            return [this, sync] { return (*this)(sync); };
        }

        template <typename Alloc>
        auto& later_by(
          basic_cleanup_group<Alloc>& cleanup, sync_type sync) const {
            return cleanup.add_ret(bind(sync));
        }

        auto raii(sync_type& sync) noexcept {
            return eagine::finally(bind(sync));
        }
    } delete_sync;

    template <typename ObjTag, typename W, W c_api::*DeleteObjects>
    struct delete_object_func : func<W, DeleteObjects> {
        using func<W, DeleteObjects>::func;

        constexpr auto operator()(span<const name_type> names) const noexcept {
            return this->_chkcall(sizei_type(names.size()), names.data());
        }

        constexpr auto operator()(gl_owned_object_name<ObjTag> name) const
          noexcept {
            auto n = name.release();
            return this->_chkcall(1, &n);
        }

        auto bind(gl_owned_object_name<ObjTag>& name) const noexcept {
            return [this, &name] { (*this)(std::move(name)); };
        }

        template <typename Alloc>
        auto& later_by(
          basic_cleanup_group<Alloc>& cleanup,
          gl_owned_object_name<ObjTag>& name) const {
            return cleanup.add_ret(bind(name));
        }

        auto raii(gl_owned_object_name<ObjTag>& name) noexcept {
            return eagine::finally(bind(name));
        }
    };

    struct : func<OGLPAFP(DeleteShader)> {
        using func<OGLPAFP(DeleteShader)>::func;

        constexpr auto operator()(owned_shader_name name) const noexcept {
            return this->_chkcall(name.release());
        }

        auto bind(owned_shader_name& name) const noexcept {
            return [this, &name] { return (*this)(std::move(name)); };
        }

        template <typename Alloc>
        auto& later_by(
          basic_cleanup_group<Alloc>& cleanup, owned_shader_name& name) const {
            return cleanup.add_ret(bind(name));
        }

        auto raii(owned_shader_name& name) noexcept {
            return eagine::finally(bind(name));
        }
    } delete_shader;

    struct : func<OGLPAFP(DeleteProgram)> {
        using func<OGLPAFP(DeleteProgram)>::func;

        constexpr auto operator()(owned_program_name name) const noexcept {
            return this->_chkcall(name.release());
        }

        auto bind(owned_program_name& name) const noexcept {
            return [this, &name] { return (*this)(std::move(name)); };
        }

        template <typename Alloc>
        auto& later_by(
          basic_cleanup_group<Alloc>& cleanup, owned_program_name& name) const {
            return cleanup.add_ret(bind(name));
        }

        auto raii(owned_program_name& name) noexcept {
            return eagine::finally(bind(name));
        }
    } delete_program;

    delete_object_func<buffer_tag, OGLPAFP(DeleteBuffers)> delete_buffers;

    delete_object_func<framebuffer_tag, OGLPAFP(DeleteFramebuffers)>
      delete_framebuffers;

    delete_object_func<program_pipeline_tag, OGLPAFP(DeleteProgramPipelines)>
      delete_program_pipelines;

    delete_object_func<query_tag, OGLPAFP(DeleteQueries)> delete_queries;

    delete_object_func<renderbuffer_tag, OGLPAFP(DeleteRenderbuffers)>
      delete_renderbuffers;

    delete_object_func<sampler_tag, OGLPAFP(DeleteSamplers)> delete_samplers;

    delete_object_func<texture_tag, OGLPAFP(DeleteTextures)> delete_textures;

    delete_object_func<
      transform_feedback_tag,
      OGLPAFP(DeleteTransformFeedbacks)>
      delete_transform_feedbacks;

    delete_object_func<vertex_array_tag, OGLPAFP(DeleteVertexArrays)>
      delete_vertex_arrays;

    struct : func<OGLPAFP(DeletePathsNV)> {
        using func<OGLPAFP(DeletePathsNV)>::func;

        constexpr auto operator()(owned_path_nv_name name) const noexcept {
            return this->_chkcall(name.release(), 1);
        }

        auto raii(owned_path_nv_name& name) noexcept {
            return eagine::finally([this, &name]() { (*this)(name); });
        }
    } delete_paths_nv;

    // is_object
    func<OGLPAFP(IsSync), true_false(sync_type)> is_sync;

    template <typename ObjTag, typename W, W c_api::*IsObject>
    using is_object_func =
      func<W, IsObject, true_false(gl_object_name<ObjTag>)>;

    is_object_func<buffer_tag, OGLPAFP(IsBuffer)> is_buffer;

    is_object_func<framebuffer_tag, OGLPAFP(IsFramebuffer)> is_framebuffer;

    is_object_func<program_pipeline_tag, OGLPAFP(IsProgramPipeline)>
      is_program_pipeline;

    is_object_func<program_tag, OGLPAFP(IsProgram)> is_program;

    is_object_func<query_tag, OGLPAFP(IsQuery)> is_query;

    is_object_func<renderbuffer_tag, OGLPAFP(IsRenderbuffer)> is_renderbuffer;

    is_object_func<sampler_tag, OGLPAFP(IsSampler)> is_sampler;

    is_object_func<shader_tag, OGLPAFP(IsShader)> is_shader;

    is_object_func<texture_tag, OGLPAFP(IsTexture)> is_texture;

    is_object_func<transform_feedback_tag, OGLPAFP(IsTransformFeedback)>
      is_transform_feedback;

    is_object_func<vertex_array_tag, OGLPAFP(IsVertexArray)> is_vertex_array;

    is_object_func<path_nv_tag, OGLPAFP(IsPathNV)> is_path_nv;

    // enable
    func<OGLPAFP(Enable), void(capability)> enable;
    func<OGLPAFP(Enablei), void(capability, uint_type)> enablei;

    // disable
    func<OGLPAFP(Disable), void(capability)> disable;
    func<OGLPAFP(Disablei), void(capability, uint_type)> disablei;

    // is_enabled
    func<OGLPAFP(IsEnabled), true_false(capability)> is_enabled;
    func<OGLPAFP(IsEnabledi), true_false(capability, uint_type)> is_enabledi;

    // memory barrier
    func<OGLPAFP(MemoryBarrier), void(enum_bitfield<memory_barrier_bit>)>
      memory_barrier;

    func<
      OGLPAFP(MemoryBarrierByRegion),
      void(enum_bitfield<memory_barrier_bit>)>
      memory_barrier_by_region;

    // viewport
    struct : func<OGLPAFP(Viewport)> {
        using base = func<OGLPAFP(Viewport)>;

        using base::base;
        using base::operator();

        constexpr auto operator()(sizei_type w, sizei_type h) const noexcept {
            return base::operator()(0, 0, w, h);
        }
    } viewport;

    // clear
    func<OGLPAFP(ClearColor)> clear_color;
    func<OGLPAFP(ClearDepth)> clear_depth;
    func<OGLPAFP(ClearStencil)> clear_stencil;
    func<OGLPAFP(Clear), void(enum_bitfield<buffer_clear_bit>)> clear;

    // shader ops
    struct : func<OGLPAFP(ShaderSource)> {
        using func<OGLPAFP(ShaderSource)>::func;

        constexpr auto operator()(
          shader_name shdr, const glsl_source_ref& source) const noexcept {
            return this->_chkcall(
              name_type(shdr),
              source.count(),
              source.parts(),
              source.lengths());
        }
    } shader_source;

    func<OGLPAFP(CompileShader), void(shader_name)> compile_shader;

    struct : func<OGLPAFP(GetShaderiv)> {
        using func<OGLPAFP(GetShaderiv)>::func;

        template <
          typename Query,
          typename =
            std::enable_if_t<is_enum_class_value_v<shader_parameter, Query>>,
          typename =
            std::enable_if_t<!std::is_array_v<typename Query::tag_type>>>
        constexpr auto operator()(shader_name shdr, Query query) const
          noexcept {
            using RV = typename Query::tag_type;
            int_type result{};
            return this->_chkcall(name_type(shdr), enum_type(query), &result)
              .replaced_with(result)
              .cast_to(identity<RV>{});
        }

        constexpr auto operator()(
          shader_name shdr, shader_parameter param, span<int_type> dest) const
          noexcept {
            return this->_chkcall(
              name_type(shdr), enum_type(param), dest.data());
        }
    } get_shaderi;

    struct : func<OGLPAFP(GetShaderInfoLog)> {
        using func<OGLPAFP(GetShaderInfoLog)>::func;

        constexpr auto operator()(shader_name shdr, span<char_type> dest) const
          noexcept {
            sizei_type real_len{0};
            return this
              ->_chkcall(
                name_type(shdr),
                sizei_type(dest.size()),
                &real_len,
                dest.data())
              .replaced_with(head(dest, span_size(real_len)));
        }
    } get_shader_info_log;

    // program ops
    func<OGLPAFP(AttachShader), void(program_name, shader_name)> attach_shader;

    func<OGLPAFP(DetachShader), void(program_name, shader_name)> detach_shader;

    func<OGLPAFP(LinkProgram), void(program_name)> link_program;

    struct : func<OGLPAFP(GetProgramiv)> {
        using func<OGLPAFP(GetProgramiv)>::func;

        template <
          typename Query,
          typename =
            std::enable_if_t<is_enum_class_value_v<program_parameter, Query>>,
          typename =
            std::enable_if_t<!std::is_array_v<typename Query::tag_type>>>
        constexpr auto operator()(program_name prog, Query query) const
          noexcept {
            using RV = typename Query::tag_type;
            int_type result{};
            return this->_chkcall(name_type(prog), enum_type(query), &result)
              .replaced_with(result)
              .cast_to(identity<RV>{});
        }

        constexpr auto operator()(
          program_name shdr, program_parameter param, span<int_type> dest) const
          noexcept {
            return this->_chkcall(
              name_type(shdr), enum_type(param), dest.data());
        }
    } get_programi;

    struct : func<OGLPAFP(GetProgramInfoLog)> {
        using func<OGLPAFP(GetProgramInfoLog)>::func;

        constexpr auto operator()(program_name prog, span<char_type> dest) const
          noexcept {
            sizei_type real_len{0};
            return this
              ->_chkcall(
                name_type(prog),
                sizei_type(dest.size()),
                &real_len,
                dest.data())
              .replaced_with(head(dest, span_size(real_len)));
        }
    } get_program_info_log;

    func<OGLPAFP(UseProgram), void(program_name)> use_program;

    func<
      OGLPAFP(GetAttribLocation),
      vertex_attrib_location(program_name, string_view)>
      get_attrib_location;

    func<
      OGLPAFP(GetUniformLocation),
      uniform_location(program_name, string_view)>
      get_uniform_location;

    // uniform
    // uint
    func<OGLPAFP(Uniform1ui), void(uniform_location, uint_type)> uniform1ui;
    func<OGLPAFP(Uniform2ui), void(uniform_location, uint_type, uint_type)>
      uniform2ui;
    func<
      OGLPAFP(Uniform3ui),
      void(uniform_location, uint_type, uint_type, uint_type)>
      uniform3ui;
    func<
      OGLPAFP(Uniform4ui),
      void(uniform_location, uint_type, uint_type, uint_type, uint_type)>
      uniform4ui;

    func<
      OGLPAFP(Uniform1uiv),
      void(uniform_location, sizei_type, const uint_type*)>
      uniform1uiv;

    func<
      OGLPAFP(Uniform2uiv),
      void(uniform_location, sizei_type, const uint_type*)>
      uniform2uiv;

    func<
      OGLPAFP(Uniform3uiv),
      void(uniform_location, sizei_type, const uint_type*)>
      uniform3uiv;

    func<
      OGLPAFP(Uniform4uiv),
      void(uniform_location, sizei_type, const uint_type*)>
      uniform4uiv;

    // int
    func<OGLPAFP(Uniform1i), void(uniform_location, int_type)> uniform1i;
    func<OGLPAFP(Uniform2i), void(uniform_location, int_type, int_type)>
      uniform2i;
    func<
      OGLPAFP(Uniform3i),
      void(uniform_location, int_type, int_type, int_type)>
      uniform3i;
    func<
      OGLPAFP(Uniform4i),
      void(uniform_location, int_type, int_type, int_type, int_type)>
      uniform4i;

    func<
      OGLPAFP(Uniform1iv),
      void(uniform_location, sizei_type, const int_type*)>
      uniform1iv;

    func<
      OGLPAFP(Uniform2iv),
      void(uniform_location, sizei_type, const int_type*)>
      uniform2iv;

    func<
      OGLPAFP(Uniform3iv),
      void(uniform_location, sizei_type, const int_type*)>
      uniform3iv;

    func<
      OGLPAFP(Uniform4iv),
      void(uniform_location, sizei_type, const int_type*)>
      uniform4iv;

    // float
    func<OGLPAFP(Uniform1f), void(uniform_location, float_type)> uniform1f;
    func<OGLPAFP(Uniform2f), void(uniform_location, float_type, float_type)>
      uniform2f;
    func<
      OGLPAFP(Uniform3f),
      void(uniform_location, float_type, float_type, float_type)>
      uniform3f;
    func<
      OGLPAFP(Uniform4f),
      void(uniform_location, float_type, float_type, float_type, float_type)>
      uniform4f;

    func<
      OGLPAFP(Uniform1fv),
      void(uniform_location, sizei_type, const float_type*)>
      uniform1fv;

    func<
      OGLPAFP(Uniform2fv),
      void(uniform_location, sizei_type, const float_type*)>
      uniform2fv;

    func<
      OGLPAFP(Uniform3fv),
      void(uniform_location, sizei_type, const float_type*)>
      uniform3fv;

    func<
      OGLPAFP(Uniform4fv),
      void(uniform_location, sizei_type, const float_type*)>
      uniform4fv;

    // buffer ops
    func<OGLPAFP(BindBuffer), void(buffer_target, buffer_name)> bind_buffer;

    struct : func<OGLPAFP(BufferData)> {
        using func<OGLPAFP(BufferData)>::func;

        constexpr auto operator()(
          buffer_target tgt,
          const buffer_data_spec& values,
          buffer_usage usg) const noexcept {
            return this->_chkcall(
              enum_type(tgt), values.size(), values.data(), enum_type(usg));
        }
    } buffer_data;

    // vertex_array ops
    func<OGLPAFP(BindVertexArray), void(vertex_array_name)> bind_vertex_array;

    func<OGLPAFP(EnableVertexAttribArray), void(vertex_attrib_location)>
      enable_vertex_attrib_array;

    func<
      OGLPAFP(EnableVertexArrayAttrib),
      void(vertex_array_name, vertex_attrib_location)>
      enable_vertex_array_attrib;

    func<OGLPAFP(DisableVertexAttribArray), void(vertex_attrib_location)>
      disable_vertex_attrib_array;

    func<
      OGLPAFP(DisableVertexArrayAttrib),
      void(vertex_array_name, vertex_attrib_location)>
      disable_vertex_array_attrib;

    func<
      OGLPAFP(VertexAttribPointer),
      void(
        vertex_attrib_location,
        int_type,
        data_type,
        true_false,
        sizei_type,
        const_void_ptr_type)>
      vertex_attrib_pointer;

    // texture ops
    func<OGLPAFP(ActiveTexture), void(texture_unit)> active_texture;
    func<OGLPAFP(BindTexture), void(texture_target, texture_name)> bind_texture;

    struct
      : func<
          OGLPAFP(BindTextures),
          void(uint_type, sizei_type, const name_type*)> {
        using base = func<
          OGLPAFP(BindTextures),
          void(uint_type, sizei_type, const name_type*)>;

        using base::base;

        constexpr auto operator()(
          uint_type first, span<const name_type> texs) const noexcept {
            return base::operator()(
              first, sizei_type(texs.size()), texs.data());
        }
    } bind_textures;

    func<OGLPAFP(BindTextureUnit), void(uint_type, texture_name)>
      bind_texture_unit;

    func<
      OGLPAFP(BindImageTexture),
      void(
        uint_type,
        texture_name,
        int_type,
        true_false,
        int_type,
        access_specifier,
        image_unit_format)>
      bind_image_texture;

    func<
      OGLPAFP(TexStorage3D),
      void(
        texture_target,
        sizei_type,
        pixel_internal_format,
        sizei_type,
        sizei_type,
        sizei_type)>
      tex_storage3d;

    func<
      OGLPAFP(TextureStorage3D),
      void(
        texture_name,
        sizei_type,
        pixel_internal_format,
        sizei_type,
        sizei_type,
        sizei_type)>
      texture_storage3d;

    func<
      OGLPAFP(TexStorage2D),
      void(
        texture_target,
        sizei_type,
        pixel_internal_format,
        sizei_type,
        sizei_type)>
      tex_storage2d;

    func<
      OGLPAFP(TextureStorage2D),
      void(
        texture_name,
        sizei_type,
        pixel_internal_format,
        sizei_type,
        sizei_type)>
      texture_storage2d;

    func<
      OGLPAFP(TexStorage1D),
      void(texture_target, sizei_type, pixel_internal_format, sizei_type)>
      tex_storage1d;

    func<
      OGLPAFP(TextureStorage1D),
      void(texture_name, sizei_type, pixel_internal_format, sizei_type)>
      texture_storage1d;

    func<
      OGLPAFP(TexStorage3DMultisample),
      void(
        texture_target,
        sizei_type,
        pixel_internal_format,
        sizei_type,
        sizei_type,
        sizei_type,
        bool_type)>
      tex_storage3d_multisample;

    func<
      OGLPAFP(TextureStorage3DMultisample),
      void(
        texture_name,
        sizei_type,
        pixel_internal_format,
        sizei_type,
        sizei_type,
        sizei_type,
        bool_type)>
      texture_storage3d_multisample;

    func<
      OGLPAFP(TexStorage2DMultisample),
      void(
        texture_target,
        sizei_type,
        pixel_internal_format,
        sizei_type,
        sizei_type,
        bool_type)>
      tex_storage2d_multisample;

    func<
      OGLPAFP(TextureStorage2DMultisample),
      void(
        texture_name,
        sizei_type,
        pixel_internal_format,
        sizei_type,
        sizei_type,
        bool_type)>
      texture_storage2d_multisample;

    func<
      OGLPAFP(TexImage3D),
      void(
        texture_target,
        int_type,
        pixel_internal_format,
        sizei_type,
        sizei_type,
        sizei_type,
        int_type,
        pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      tex_image3d;

    func<
      OGLPAFP(TexImage2D),
      void(
        texture_target,
        int_type,
        pixel_internal_format,
        sizei_type,
        sizei_type,
        int_type,
        pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      tex_image2d;

    func<
      OGLPAFP(TexImage1D),
      void(
        texture_target,
        int_type,
        pixel_internal_format,
        sizei_type,
        int_type,
        pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      tex_image1d;

    func<
      OGLPAFP(TexSubImage3D),
      void(
        texture_target,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      tex_sub_image3d;

    func<
      OGLPAFP(TextureSubImage3D),
      void(
        texture_name,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        sizei_type,
        pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      texture_sub_image3d;

    func<
      OGLPAFP(TexSubImage2D),
      void(
        texture_target,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      tex_sub_image2d;

    func<
      OGLPAFP(TextureSubImage2D),
      void(
        texture_name,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      texture_sub_image2d;

    func<
      OGLPAFP(TexSubImage1D),
      void(
        texture_target,
        int_type,
        int_type,
        sizei_type,
        pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      tex_sub_image1d;

    func<
      OGLPAFP(TexSubImage1D),
      void(
        texture_name,
        int_type,
        int_type,
        sizei_type,
        pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      texture_sub_image1d;

    func<
      OGLPAFP(CopyTexImage2D),
      void(
        texture_target,
        int_type,
        pixel_internal_format,
        int_type,
        int_type,
        sizei_type,
        sizei_type,
        int_type)>
      copy_tex_image2d;

    func<
      OGLPAFP(CopyTexImage1D),
      void(
        texture_target,
        int_type,
        pixel_internal_format,
        int_type,
        int_type,
        sizei_type,
        int_type)>
      copy_tex_image1d;

    func<
      OGLPAFP(CopyTexSubImage3D),
      void(
        texture_target,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type)>
      copy_tex_sub_image3d;

    func<
      OGLPAFP(CopyTextureSubImage3D),
      void(
        texture_name,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type)>
      copy_texture_sub_image3d;

    func<
      OGLPAFP(CopyTexSubImage2D),
      void(
        texture_target,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type)>
      copy_tex_sub_image2d;

    func<
      OGLPAFP(CopyTextureSubImage2D),
      void(
        texture_name,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        sizei_type,
        sizei_type)>
      copy_texture_sub_image2d;

    func<
      OGLPAFP(CopyTexSubImage1D),
      void(texture_target, int_type, int_type, int_type, int_type, sizei_type)>
      copy_tex_sub_image1d;

    func<
      OGLPAFP(CopyTextureSubImage1D),
      void(texture_name, int_type, int_type, int_type, int_type, sizei_type)>
      copy_texture_sub_image1d;

    func<
      OGLPAFP(TexBuffer),
      void(texture_target, pixel_internal_format, buffer_name)>
      tex_buffer;

    func<
      OGLPAFP(TextureBuffer),
      void(texture_name, pixel_internal_format, buffer_name)>
      texture_buffer;

    func<
      OGLPAFP(TexBufferRange),
      void(
        texture_target,
        pixel_internal_format,
        buffer_name,
        intptr_type,
        sizeiptr_type)>
      tex_buffer_range;

    func<
      OGLPAFP(TextureBufferRange),
      void(
        texture_name,
        pixel_internal_format,
        buffer_name,
        intptr_type,
        sizeiptr_type)>
      texture_buffer_range;

    // drawing
    // arrays
    func<OGLPAFP(DrawArrays), void(primitive_type, int_type, sizei_type)>
      draw_arrays;

    func<
      OGLPAFP(DrawArraysInstancedBaseInstance),
      void(primitive_type, int_type, sizei_type, sizei_type, uint_type)>
      draw_arrays_instanced_base_instance;

    func<
      OGLPAFP(DrawArraysInstanced),
      void(primitive_type, int_type, sizei_type, sizei_type)>
      draw_arrays_instanced;

    func<OGLPAFP(DrawArraysIndirect), void(primitive_type, const_void_ptr_type)>
      draw_arrays_indirect;

    func<
      OGLPAFP(MultiDrawArrays),
      void(primitive_type, const int_type*, const sizei_type*, sizei_type)>
      multi_draw_arrays;

    func<
      OGLPAFP(MultiDrawArraysIndirect),
      void(primitive_type, const_void_ptr_type, sizei_type, sizei_type)>
      multi_draw_arrays_indirect;

    func<
      OGLPAFP(MultiDrawArraysIndirectCount),
      void(
        primitive_type,
        const_void_ptr_type,
        intptr_type,
        sizei_type,
        sizei_type)>
      multi_draw_arrays_indirect_count;

    // elements
    func<
      OGLPAFP(DrawElements),
      void(primitive_type, sizei_type, index_data_type, const_void_ptr_type)>
      draw_elements;

    func<
      OGLPAFP(DrawRangeElements),
      void(
        primitive_type,
        uint_type,
        uint_type,
        sizei_type,
        index_data_type,
        const_void_ptr_type)>
      draw_range_elements;

    func<
      OGLPAFP(DrawElementsInstancedBaseInstance),
      void(
        primitive_type,
        sizei_type,
        index_data_type,
        const_void_ptr_type,
        sizei_type,
        uint_type)>
      draw_elements_instanced_base_instance;

    func<
      OGLPAFP(DrawElementsInstanced),
      void(
        primitive_type,
        sizei_type,
        index_data_type,
        const_void_ptr_type,
        sizei_type)>
      draw_elements_instanced;

    func<
      OGLPAFP(DrawElementsIndirect),
      void(primitive_type, index_data_type, const_void_ptr_type)>
      draw_elements_indirect;

    func<
      OGLPAFP(DrawElementsBaseVertex),
      void(
        primitive_type,
        sizei_type,
        index_data_type,
        const_void_ptr_type,
        int_type)>
      draw_elements_base_vertex;

    func<
      OGLPAFP(DrawRangeElements),
      void(
        primitive_type,
        uint_type,
        uint_type,
        sizei_type,
        index_data_type,
        const_void_ptr_type,
        int_type)>
      draw_range_elements_base_vertex;

    func<
      OGLPAFP(DrawElementsInstancedBaseVertex),
      void(
        primitive_type,
        sizei_type,
        index_data_type,
        const_void_ptr_type,
        sizei_type,
        int_type)>
      draw_elements_instanced_base_vertex;

    func<
      OGLPAFP(DrawElementsInstancedBaseVertexBaseInstance),
      void(
        primitive_type,
        sizei_type,
        index_data_type,
        const_void_ptr_type,
        sizei_type,
        int_type,
        uint_type)>
      draw_elements_instanced_base_vertex_base_instance;

    // computing
    func<OGLPAFP(DispatchCompute)> dispatch_compute;
    func<OGLPAFP(DispatchComputeIndirect)> dispatch_compute_indirect;

    // get_integer
    struct : func<OGLPAFP(GetIntegerv)> {
        using func<OGLPAFP(GetIntegerv)>::func;

        template <
          typename Query,
          typename = std::enable_if_t<
            is_enum_class_value_v<integer_query, Query> ||
            is_enum_class_value_v<binding_query, Query>>,
          typename =
            std::enable_if_t<!std::is_array_v<typename Query::tag_type>>>
        constexpr auto operator()(Query query) const noexcept {
            using RV = typename Query::tag_type;
            int_type result{};
            return this->_chkcall(enum_type(query), &result)
              .replaced_with(result)
              .cast_to(identity<RV>{});
        }

        template <
          typename Query,
          typename = std::enable_if_t<
            is_enum_class_value_v<integer_query, Query> ||
            is_enum_class_value_v<binding_query, Query>>>
        auto operator()(integer_query query, span<int_type> dest) const
          noexcept {
            EAGINE_ASSERT(dest.size());
            return this->_chkcall(enum_type(query), dest.data());
        }
    } get_integer;

    // get_integer64
    struct : func<OGLPAFP(GetInteger64v)> {
        using func<OGLPAFP(GetInteger64v)>::func;

        constexpr auto operator()(integer_query query) const noexcept {
            int64_type result{};
            return this->_chkcall(enum_type(query), &result)
              .replaced_with(result);
        }

        constexpr auto operator()(
          integer_query query, span<int64_type> dest) const noexcept {
            EAGINE_ASSERT(dest.size());
            return this->_chkcall(enum_type(query), dest.data());
        }
    } get_integer64;

    // get_float
    struct : func<OGLPAFP(GetFloatv)> {
        using func<OGLPAFP(GetFloatv)>::func;

        constexpr auto operator()(float_query query) const noexcept {
            float_type result{};
            return this->_chkcall(enum_type(query), &result)
              .replaced_with(result);
        }

        constexpr auto operator()(
          float_query query, span<float_type> dest) const noexcept {
            EAGINE_ASSERT(dest.size());
            return this->_chkcall(enum_type(query), dest.data());
        }
    } get_float;

    // get_string
    struct : func<OGLPAFP(GetString)> {
        using func<OGLPAFP(GetString)>::func;

        constexpr auto operator()(string_query query) const noexcept {
            return this->_chkcall(enum_type(query)).transformed([](auto src) {
                return reinterpret_cast<const char*>(src);
            });
        }

        constexpr auto operator()() const noexcept {
            return this->_fake("");
        }
    } get_string;

    // get_strings
    auto get_strings(string_query query, char separator) noexcept {
        return get_string(query).transformed([separator](auto src) {
            return split_c_str_into_string_list(src, separator);
        });
    }

    // get_extensions
    auto get_extensions() noexcept {
#ifdef GL_EXTENSIONS
        return get_string(string_query(GL_EXTENSIONS))
#else
        return get_string()
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, ' '); });
    }

    // arb compatibility
    func<OGLPAFP(Begin), void(old_primitive_type)> begin;
    func<OGLPAFP(End)> end;

    func<OGLPAFP(Vertex2i)> vertex2i;
    func<OGLPAFP(Vertex3i)> vertex3i;
    func<OGLPAFP(Vertex4i)> vertex4i;
    func<OGLPAFP(Vertex2f)> vertex2f;
    func<OGLPAFP(Vertex3f)> vertex3f;
    func<OGLPAFP(Vertex4f)> vertex4f;

    func<OGLPAFP(Color3i)> color3i;
    func<OGLPAFP(Color4i)> color4i;
    func<OGLPAFP(Color3f)> color3f;
    func<OGLPAFP(Color4f)> color4f;

    func<OGLPAFP(SecondaryColor3i)> secondary_color3i;
    func<OGLPAFP(SecondaryColor4i)> secondary_color4i;
    func<OGLPAFP(SecondaryColor3f)> secondary_color3f;
    func<OGLPAFP(SecondaryColor4f)> secondary_color4f;

    func<OGLPAFP(TexCoord1i)> tex_coord1i;
    func<OGLPAFP(TexCoord2i)> tex_coord2i;
    func<OGLPAFP(TexCoord3i)> tex_coord3i;
    func<OGLPAFP(TexCoord4i)> tex_coord4i;
    func<OGLPAFP(TexCoord1f)> tex_coord1f;
    func<OGLPAFP(TexCoord2f)> tex_coord2f;
    func<OGLPAFP(TexCoord3f)> tex_coord3f;
    func<OGLPAFP(TexCoord4f)> tex_coord4f;

    func<OGLPAFP(MultiTexCoord1i), void(texture_unit, int_type)>
      multi_tex_coord1i;
    func<OGLPAFP(MultiTexCoord2i), void(texture_unit, int_type, int_type)>
      multi_tex_coord2i;
    func<
      OGLPAFP(MultiTexCoord3i),
      void(texture_unit, int_type, int_type, int_type)>
      multi_tex_coord3i;
    func<
      OGLPAFP(MultiTexCoord4i),
      void(texture_unit, int_type, int_type, int_type, int_type)>
      multi_tex_coord4i;
    func<OGLPAFP(MultiTexCoord1f), void(texture_unit, float_type)>
      multi_tex_coord1f;
    func<OGLPAFP(MultiTexCoord2f), void(texture_unit, float_type, float_type)>
      multi_tex_coord2f;
    func<
      OGLPAFP(MultiTexCoord3f),
      void(texture_unit, float_type, float_type, float_type)>
      multi_tex_coord3f;
    func<
      OGLPAFP(MultiTexCoord4f),
      void(texture_unit, float_type, float_type, float_type, float_type)>
      multi_tex_coord4f;

    func<OGLPAFP(MatrixMode), void(matrix_mode)> matrix_mode;
    func<OGLPAFP(PushMatrix)> push_matrix;
    func<OGLPAFP(PopMatrix)> pop_matrix;

    func<OGLPAFP(LoadIdentity)> load_identity;

    func<OGLPAFP(Translatef)> translate_f;
    func<OGLPAFP(Translated)> translate_d;

    func<
      OGLPAFP(Rotatef),
      void(degrees_t<float_type>, float_type, float_type, float_type)>
      rotate_f;

    func<
      OGLPAFP(Rotated),
      void(degrees_t<double_type>, double_type, double_type, double_type)>
      rotate_d;

    func<OGLPAFP(Scalef)> scale_f;
    func<OGLPAFP(Scaled)> scale_d;

    func<OGLPAFP(Frustum)> frustum;
    func<OGLPAFP(Ortho)> ortho;

    func<OGLPAFP(LoadMatrixf)> load_matrix_f;
    func<OGLPAFP(LoadMatrixd)> load_matrix_d;

    func<OGLPAFP(MultMatrixf)> mult_matrix_f;
    func<OGLPAFP(MultMatrixd)> mult_matrix_d;

    func<OGLPAFP(LoadTransposeMatrixf)> load_transpose_matrix_f;
    func<OGLPAFP(LoadTransposeMatrixd)> load_transpose_matrix_d;

    func<OGLPAFP(MultTransposeMatrixf)> mult_transpose_matrix_f;
    func<OGLPAFP(MultTransposeMatrixd)> mult_transpose_matrix_d;

    func<OGLPAFP(Flush)> flush;
    func<OGLPAFP(Finish)> finish;

    constexpr basic_gl_api(api_traits& traits)
      : c_api{traits}
      , fence_sync("fence_sync", traits, *this)
      , create_shader("create_shader", traits, *this)
      , create_program("create_program", traits, *this)
      , gen_buffers("gen_buffers", traits, *this)
      , create_buffers("create_buffers", traits, *this)
      , gen_framebuffers("gen_framebuffers", traits, *this)
      , create_framebuffers("create_framebuffers", traits, *this)
      , gen_program_pipelines("gen_program_pipelines", traits, *this)
      , create_program_pipelines("create_program_pipelines", traits, *this)
      , gen_queries("gen_queries", traits, *this)
      , create_queries("create_queries", traits, *this)
      , gen_renderbuffers("gen_renderbuffers", traits, *this)
      , create_renderbuffers("create_renderbuffers", traits, *this)
      , gen_samplers("gen_samplers", traits, *this)
      , create_samplers("create_samplers", traits, *this)
      , gen_textures("gen_textures", traits, *this)
      , create_textures("create_textures", traits, *this)
      , gen_transform_feedbacks("gen_transform_feedbacks", traits, *this)
      , create_transform_feedbacks("create_transform_feedbacks", traits, *this)
      , gen_vertex_arrays("gen_vertex_arrays", traits, *this)
      , create_vertex_arrays("create_vertex_arrays", traits, *this)
      , create_paths_nv("create_paths_nv", traits, *this)
      , delete_sync("delete_sync", traits, *this)
      , delete_shader("delete_shader", traits, *this)
      , delete_program("delete_program", traits, *this)
      , delete_buffers("delete_buffers", traits, *this)
      , delete_framebuffers("delete_framebuffers", traits, *this)
      , delete_program_pipelines("delete_program_pipelines", traits, *this)
      , delete_queries("delete_queries", traits, *this)
      , delete_renderbuffers("delete_renderbuffers", traits, *this)
      , delete_samplers("delete_samplers", traits, *this)
      , delete_textures("delete_textures", traits, *this)
      , delete_transform_feedbacks("delete_transform_feedbacks", traits, *this)
      , delete_vertex_arrays("delete_vertex_arrays", traits, *this)
      , delete_paths_nv("delete_paths_nv", traits, *this)
      , is_sync("is_sync", traits, *this)
      , is_buffer("is_buffer", traits, *this)
      , is_framebuffer("is_framebuffer", traits, *this)
      , is_program_pipeline("is_program_pipeline", traits, *this)
      , is_program("is_program", traits, *this)
      , is_query("is_query", traits, *this)
      , is_renderbuffer("is_renderbuffer", traits, *this)
      , is_sampler("is_sampler", traits, *this)
      , is_shader("is_shader", traits, *this)
      , is_texture("is_texture", traits, *this)
      , is_transform_feedback("is_transform_feedback", traits, *this)
      , is_vertex_array("is_vertex_array", traits, *this)
      , is_path_nv("is_path_nv", traits, *this)
      , enable("enable", traits, *this)
      , enablei("enablei", traits, *this)
      , disable("disable", traits, *this)
      , disablei("disablei", traits, *this)
      , is_enabled("is_enabled", traits, *this)
      , is_enabledi("is_enabledi", traits, *this)
      , memory_barrier("memory_barrier", traits, *this)
      , memory_barrier_by_region("memory_barrier_by_region", traits, *this)
      , viewport("viewport", traits, *this)
      , clear_color("clear_color", traits, *this)
      , clear_depth("clear_depth", traits, *this)
      , clear_stencil("clear_stencil", traits, *this)
      , clear("clear", traits, *this)
      , shader_source("shader_source", traits, *this)
      , compile_shader("compile_shader", traits, *this)
      , get_shaderi("get_shaderi", traits, *this)
      , get_shader_info_log("get_shader_info_log", traits, *this)
      , attach_shader("attach_shader", traits, *this)
      , detach_shader("detach_shader", traits, *this)
      , link_program("link_program", traits, *this)
      , get_programi("get_programi", traits, *this)
      , get_program_info_log("get_program_info_log", traits, *this)
      , use_program("use_program", traits, *this)
      , get_attrib_location("get_attrib_location", traits, *this)
      , get_uniform_location("get_uniform_location", traits, *this)
      , uniform1ui("uniform1ui", traits, *this)
      , uniform2ui("uniform2ui", traits, *this)
      , uniform3ui("uniform3ui", traits, *this)
      , uniform4ui("uniform4ui", traits, *this)
      , uniform1uiv("uniform1uiv", traits, *this)
      , uniform2uiv("uniform2uiv", traits, *this)
      , uniform3uiv("uniform3uiv", traits, *this)
      , uniform4uiv("uniform4uiv", traits, *this)
      , uniform1i("uniform1i", traits, *this)
      , uniform2i("uniform2i", traits, *this)
      , uniform3i("uniform3i", traits, *this)
      , uniform4i("uniform4i", traits, *this)
      , uniform1iv("uniform1iv", traits, *this)
      , uniform2iv("uniform2iv", traits, *this)
      , uniform3iv("uniform3iv", traits, *this)
      , uniform4iv("uniform4iv", traits, *this)
      , uniform1f("uniform1f", traits, *this)
      , uniform2f("uniform2f", traits, *this)
      , uniform3f("uniform3f", traits, *this)
      , uniform4f("uniform4f", traits, *this)
      , uniform1fv("uniform1fv", traits, *this)
      , uniform2fv("uniform2fv", traits, *this)
      , uniform3fv("uniform3fv", traits, *this)
      , uniform4fv("uniform4fv", traits, *this)
      , bind_buffer("bind_buffer", traits, *this)
      , buffer_data("buffer_data", traits, *this)
      , bind_vertex_array("bind_vertex_array", traits, *this)
      , enable_vertex_attrib_array("enable_vertex_attrib_array", traits, *this)
      , enable_vertex_array_attrib("enable_vertex_array_attrib", traits, *this)
      , disable_vertex_attrib_array(
          "disable_vertex_attrib_array", traits, *this)
      , disable_vertex_array_attrib(
          "disable_vertex_array_attrib", traits, *this)
      , vertex_attrib_pointer("vertex_attrib_pointer", traits, *this)
      , active_texture("active_texture", traits, *this)
      , bind_texture("bind_texture", traits, *this)
      , bind_textures("bind_textures", traits, *this)
      , bind_texture_unit("bind_texture_unit", traits, *this)
      , bind_image_texture("bind_image_texture", traits, *this)
      , tex_storage3d("tex_storage3d", traits, *this)
      , texture_storage3d("texture_storage3d", traits, *this)
      , tex_storage2d("tex_storage2d", traits, *this)
      , texture_storage2d("texture_storage2d", traits, *this)
      , tex_storage1d("tex_storage1d", traits, *this)
      , texture_storage1d("texture_storage1d", traits, *this)
      , tex_storage3d_multisample("tex_storage3d_multisample", traits, *this)
      , texture_storage3d_multisample(
          "texture_storage3d_multisample", traits, *this)
      , tex_storage2d_multisample("tex_storage2d_multisample", traits, *this)
      , texture_storage2d_multisample(
          "texture_storage2d_multisample", traits, *this)
      , tex_image3d("tex_image3d", traits, *this)
      , tex_image2d("tex_image2d", traits, *this)
      , tex_image1d("tex_image1d", traits, *this)
      , tex_sub_image3d("tex_sub_image3d", traits, *this)
      , texture_sub_image3d("texture_sub_image3d", traits, *this)
      , tex_sub_image2d("tex_sub_image2d", traits, *this)
      , texture_sub_image2d("texture_sub_image2d", traits, *this)
      , tex_sub_image1d("tex_sub_image1d", traits, *this)
      , texture_sub_image1d("texture_sub_image1d", traits, *this)
      , copy_tex_image2d("copy_tex_image2d", traits, *this)
      , copy_tex_image1d("copy_tex_image1d", traits, *this)
      , copy_tex_sub_image3d("copy_tex_sub_image3d", traits, *this)
      , copy_texture_sub_image3d("copy_texture_sub_image3d", traits, *this)
      , copy_tex_sub_image2d("copy_tex_sub_image2d", traits, *this)
      , copy_texture_sub_image2d("copy_texture_sub_image2d", traits, *this)
      , copy_tex_sub_image1d("copy_tex_sub_image1d", traits, *this)
      , copy_texture_sub_image1d("copy_texture_sub_image1d", traits, *this)
      , tex_buffer("tex_buffer", traits, *this)
      , texture_buffer("texture_buffer", traits, *this)
      , tex_buffer_range("tex_buffer_range", traits, *this)
      , texture_buffer_range("texture_buffer_range", traits, *this)
      , draw_arrays("draw_arrays", traits, *this)
      , draw_arrays_instanced_base_instance(
          "draw_arrays_instanced_base_instance", traits, *this)
      , draw_arrays_instanced("draw_arrays_instanced", traits, *this)
      , draw_arrays_indirect("draw_arrays_indirect", traits, *this)
      , multi_draw_arrays("multi_draw_arrays", traits, *this)
      , multi_draw_arrays_indirect("multi_draw_arrays_indirect", traits, *this)
      , multi_draw_arrays_indirect_count(
          "multi_draw_arrays_indirect_count", traits, *this)
      , draw_elements("draw_elements", traits, *this)
      , draw_range_elements("draw_range_elements", traits, *this)
      , draw_elements_instanced_base_instance(
          "draw_elements_instanced_base_instance", traits, *this)
      , draw_elements_instanced("draw_elements_instanced", traits, *this)
      , draw_elements_indirect("draw_elements_indirect", traits, *this)
      , draw_elements_base_vertex("draw_elements_base_vertex", traits, *this)
      , draw_range_elements_base_vertex(
          "draw_range_elements_base_vertex", traits, *this)
      , draw_elements_instanced_base_vertex(
          "draw_elements_instanced_base_vertex", traits, *this)
      , draw_elements_instanced_base_vertex_base_instance(
          "draw_elements_instanced_base_vertex_base_instance", traits, *this)
      , dispatch_compute("dispatch_compute", traits, *this)
      , dispatch_compute_indirect("dispatch_compute_indirect", traits, *this)
      , get_integer("get_integer", traits, *this)
      , get_integer64("get_integer64", traits, *this)
      , get_float("get_float", traits, *this)
      , get_string("get_string", traits, *this)
      , begin("begin", traits, *this)
      , end("end", traits, *this)
      , vertex2i("vertex2i", traits, *this)
      , vertex3i("vertex3i", traits, *this)
      , vertex4i("vertex4i", traits, *this)
      , vertex2f("vertex2f", traits, *this)
      , vertex3f("vertex3f", traits, *this)
      , vertex4f("vertex4f", traits, *this)
      , color3i("color3i", traits, *this)
      , color4i("color4i", traits, *this)
      , color3f("color3f", traits, *this)
      , color4f("color4f", traits, *this)
      , secondary_color3i("secondary_color3i", traits, *this)
      , secondary_color4i("secondary_color4i", traits, *this)
      , secondary_color3f("secondary_color3f", traits, *this)
      , secondary_color4f("secondary_color4f", traits, *this)
      , tex_coord1i("tex_coord1i", traits, *this)
      , tex_coord2i("tex_coord2i", traits, *this)
      , tex_coord3i("tex_coord3i", traits, *this)
      , tex_coord4i("tex_coord4i", traits, *this)
      , tex_coord1f("tex_coord1f", traits, *this)
      , tex_coord2f("tex_coord2f", traits, *this)
      , tex_coord3f("tex_coord3f", traits, *this)
      , tex_coord4f("tex_coord4f", traits, *this)
      , multi_tex_coord1i("multi_tex_coord1i", traits, *this)
      , multi_tex_coord2i("multi_tex_coord2i", traits, *this)
      , multi_tex_coord3i("multi_tex_coord3i", traits, *this)
      , multi_tex_coord4i("multi_tex_coord4i", traits, *this)
      , multi_tex_coord1f("multi_tex_coord1f", traits, *this)
      , multi_tex_coord2f("multi_tex_coord2f", traits, *this)
      , multi_tex_coord3f("multi_tex_coord3f", traits, *this)
      , multi_tex_coord4f("multi_tex_coord4f", traits, *this)
      , matrix_mode("matrix_mode", traits, *this)
      , push_matrix("push_matrix", traits, *this)
      , pop_matrix("pop_matrix", traits, *this)
      , load_identity("load_identity", traits, *this)
      , translate_f("translate_f", traits, *this)
      , translate_d("translate_d", traits, *this)
      , rotate_f("rotate_f", traits, *this)
      , rotate_d("rotate_d", traits, *this)
      , scale_f("scale_f", traits, *this)
      , scale_d("scale_d", traits, *this)
      , frustum("frustum", traits, *this)
      , ortho("ortho", traits, *this)
      , load_matrix_f("load_matrix_f", traits, *this)
      , load_matrix_d("load_matrix_d", traits, *this)
      , mult_matrix_f("mult_matrix_f", traits, *this)
      , mult_matrix_d("mult_matrix_d", traits, *this)
      , load_transpose_matrix_f("load_transpose_matrix_f", traits, *this)
      , load_transpose_matrix_d("load_transpose_matrix_d", traits, *this)
      , mult_transpose_matrix_f("mult_transpose_matrix_f", traits, *this)
      , mult_transpose_matrix_d("mult_transpose_matrix_d", traits, *this)
      , flush("flush", traits, *this)
      , finish("finish", traits, *this) {
    }
};
//------------------------------------------------------------------------------
#undef OGLPAFP
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_API_HPP

