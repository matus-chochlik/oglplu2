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
    using uint64_type = typename gl_types::uint64_type;
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

    using vertex_buffer_binding = uint_type;

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

        template <typename... Args>
        constexpr auto _cnvchkcall(Args&&... args) const noexcept {
            return this->_chkcall(_conv(args)...).cast_to(identity<RVC>{});
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

    // numerc query function
    template <
      typename PreTypeList,
      typename QueryClassList,
      typename PostTypeList,
      typename QueryResult,
      typename W,
      W c_api::*F>
    struct query_func;

    template <
      typename... PreParams,
      typename... QueryClasses,
      typename... PostParams,
      typename QueryResult,
      typename W,
      W c_api::*F>
    struct query_func<
      mp_list<PreParams...>,
      mp_list<QueryClasses...>,
      mp_list<PostParams...>,
      QueryResult,
      W,
      F> : func<W, F> {
        using func<W, F>::func;

        template <
          typename Query,
          typename = std::enable_if_t<
            (true || ... || is_enum_class_value_v<QueryClasses, Query>)>,
          typename =
            std::enable_if_t<!std::is_array_v<typename Query::tag_type>>>
        constexpr auto operator()(
          PreParams... pre_params, Query query, PostParams... post_params) const
          noexcept {
            using RV = typename Query::tag_type;
            QueryResult result{};
            return this
              ->_cnvchkcall(
                pre_params..., enum_type(query), post_params..., &result)
              .replaced_with(result)
              .cast_to(identity<RV>{});
        }

        template <
          typename Query,
          typename = std::enable_if_t<
            (true || ... || is_enum_class_value_v<QueryClasses, Query>)>>
        auto operator()(
          PreParams... pre_params,
          Query query,
          PostParams... post_params,
          span<QueryResult> dest) const noexcept {
            EAGINE_ASSERT(dest.size());
            return this->_cnvchkcall(
              pre_params..., enum_type(query), post_params..., dest.data());
        }
    };

    // generate / create objects
    struct : func<OGLPAFP(FenceSync)> {
        using func<OGLPAFP(FenceSync)>::func;

        constexpr auto operator()(sync_condition cond) const noexcept {
            return this->_cnvchkcall(cond, bitfield_type(0));
        }

        constexpr auto operator()(
          sync_condition cond, enum_bitfield<sync_flag_bit> flags) const
          noexcept {
            return this->_cnvchkcall(cond, bitfield_type(flags));
        }
    } fence_sync;

    template <typename ObjTag, typename W, W c_api::*GenObjects>
    struct make_object_func : func<W, GenObjects> {
        using func<W, GenObjects>::func;

        constexpr auto operator()(span<name_type> names) const noexcept {
            return this->_chkcall(sizei_type(names.size()), names.data());
        }

        constexpr auto operator()(
          gl_object_name_span<gl_object_name<ObjTag>> names) const noexcept {
            return (*this)(names.raw_handles());
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
            return this->_cnvchkcall(type).cast_to(
              identity<owned_shader_name>{});
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

        constexpr auto operator()(
          gl_object_name_view<gl_object_name<ObjTag>> names) const noexcept {
            return (*this)(names.raw_handles());
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

    query_func<
      mp_list<shader_name>,
      mp_list<shader_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetShaderiv)>
      get_shader_i;

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

    query_func<
      mp_list<program_name>,
      mp_list<program_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetProgramiv)>
      get_program_i;

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

    struct : func<OGLPAFP(Uniform1uiv)> {
        using func<OGLPAFP(Uniform1uiv)>::func;

        constexpr auto operator()(
          uniform_location loc, span<const uint_type> v) const noexcept {
            return this->_cnvchkcall(loc, sizei_type(v.size()), v.data());
        }
    } uniform1uiv;

    struct : func<OGLPAFP(Uniform2uiv)> {
        using func<OGLPAFP(Uniform2uiv)>::func;

        constexpr auto operator()(
          uniform_location loc, span<const uint_type> v) const noexcept {
            return this->_cnvchkcall(loc, sizei_type(v.size()), v.data());
        }
    } uniform2uiv;

    struct : func<OGLPAFP(Uniform3uiv)> {
        using func<OGLPAFP(Uniform3uiv)>::func;

        constexpr auto operator()(
          uniform_location loc, span<const uint_type> v) const noexcept {
            return this->_cnvchkcall(loc, sizei_type(v.size()), v.data());
        }
    } uniform3uiv;

    struct : func<OGLPAFP(Uniform4uiv)> {
        using func<OGLPAFP(Uniform4uiv)>::func;

        constexpr auto operator()(
          uniform_location loc, span<const uint_type> v) const noexcept {
            return this->_cnvchkcall(loc, sizei_type(v.size()), v.data());
        }
    } uniform4uiv;

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

    struct : func<OGLPAFP(Uniform1iv)> {
        using func<OGLPAFP(Uniform1iv)>::func;

        constexpr auto operator()(
          uniform_location loc, span<const int_type> v) const noexcept {
            return this->_cnvchkcall(loc, sizei_type(v.size()), v.data());
        }
    } uniform1iv;

    struct : func<OGLPAFP(Uniform2iv)> {
        using func<OGLPAFP(Uniform2iv)>::func;

        constexpr auto operator()(
          uniform_location loc, span<const int_type> v) const noexcept {
            return this->_cnvchkcall(loc, sizei_type(v.size()), v.data());
        }
    } uniform2iv;

    struct : func<OGLPAFP(Uniform3iv)> {
        using func<OGLPAFP(Uniform3iv)>::func;

        constexpr auto operator()(
          uniform_location loc, span<const int_type> v) const noexcept {
            return this->_cnvchkcall(loc, sizei_type(v.size()), v.data());
        }
    } uniform3iv;

    struct : func<OGLPAFP(Uniform4iv)> {
        using func<OGLPAFP(Uniform4iv)>::func;

        constexpr auto operator()(
          uniform_location loc, span<const int_type> v) const noexcept {
            return this->_cnvchkcall(loc, sizei_type(v.size()), v.data());
        }
    } uniform4iv;

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

    struct : func<OGLPAFP(Uniform1fv)> {
        using func<OGLPAFP(Uniform1fv)>::func;

        constexpr auto operator()(
          uniform_location loc, span<const float_type> v) const noexcept {
            return this->_cnvchkcall(loc, sizei_type(v.size()), v.data());
        }
    } uniform1fv;

    struct : func<OGLPAFP(Uniform2fv)> {
        using func<OGLPAFP(Uniform2fv)>::func;

        constexpr auto operator()(
          uniform_location loc, span<const float_type> v) const noexcept {
            return this->_cnvchkcall(loc, sizei_type(v.size()), v.data());
        }
    } uniform2fv;

    struct : func<OGLPAFP(Uniform3fv)> {
        using func<OGLPAFP(Uniform3fv)>::func;

        constexpr auto operator()(
          uniform_location loc, span<const float_type> v) const noexcept {
            return this->_cnvchkcall(loc, sizei_type(v.size()), v.data());
        }
    } uniform3fv;

    struct : func<OGLPAFP(Uniform4fv)> {
        using func<OGLPAFP(Uniform4fv)>::func;

        constexpr auto operator()(
          uniform_location loc, span<const float_type> v) const noexcept {
            return this->_cnvchkcall(loc, sizei_type(v.size()), v.data());
        }
    } uniform4fv;

    // matrix float
    struct : func<OGLPAFP(UniformMatrix2fv)> {
        using func<OGLPAFP(UniformMatrix2fv)>::func;

        constexpr auto operator()(
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              loc, sizei_type(v.size()), transp, v.data());
        }
    } uniform_matrix2fv;

    struct : func<OGLPAFP(UniformMatrix3fv)> {
        using func<OGLPAFP(UniformMatrix3fv)>::func;

        constexpr auto operator()(
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              loc, sizei_type(v.size()), transp, v.data());
        }
    } uniform_matrix3fv;

    struct : func<OGLPAFP(UniformMatrix4fv)> {
        using func<OGLPAFP(UniformMatrix4fv)>::func;

        constexpr auto operator()(
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              loc, sizei_type(v.size()), transp, v.data());
        }
    } uniform_matrix4fv;

    struct : func<OGLPAFP(UniformMatrix2x3fv)> {
        using func<OGLPAFP(UniformMatrix2x3fv)>::func;

        constexpr auto operator()(
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              loc, sizei_type(v.size()), transp, v.data());
        }
    } uniform_matrix2x3fv;

    struct : func<OGLPAFP(UniformMatrix2x4fv)> {
        using func<OGLPAFP(UniformMatrix2x4fv)>::func;

        constexpr auto operator()(
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              loc, sizei_type(v.size()), transp, v.data());
        }
    } uniform_matrix2x4fv;

    struct : func<OGLPAFP(UniformMatrix3x2fv)> {
        using func<OGLPAFP(UniformMatrix3x2fv)>::func;

        constexpr auto operator()(
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              loc, sizei_type(v.size()), transp, v.data());
        }
    } uniform_matrix3x2fv;

    struct : func<OGLPAFP(UniformMatrix3x4fv)> {
        using func<OGLPAFP(UniformMatrix3x4fv)>::func;

        constexpr auto operator()(
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              loc, sizei_type(v.size()), transp, v.data());
        }
    } uniform_matrix3x4fv;

    struct : func<OGLPAFP(UniformMatrix4x2fv)> {
        using func<OGLPAFP(UniformMatrix4x2fv)>::func;

        constexpr auto operator()(
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              loc, sizei_type(v.size()), transp, v.data());
        }
    } uniform_matrix4x2fv;

    struct : func<OGLPAFP(UniformMatrix4x3fv)> {
        using func<OGLPAFP(UniformMatrix4x3fv)>::func;

        constexpr auto operator()(
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              loc, sizei_type(v.size()), transp, v.data());
        }
    } uniform_matrix4x3fv;

    // program uniform
    // uint
    func<
      OGLPAFP(ProgramUniform1ui),
      void(program_name, uniform_location, uint_type)>
      program_uniform1ui;

    func<
      OGLPAFP(ProgramUniform2ui),
      void(program_name, uniform_location, uint_type, uint_type)>
      program_uniform2ui;

    func<
      OGLPAFP(ProgramUniform3ui),
      void(program_name, uniform_location, uint_type, uint_type, uint_type)>
      program_uniform3ui;

    func<
      OGLPAFP(ProgramUniform4ui),
      void(
        program_name,
        uniform_location,
        uint_type,
        uint_type,
        uint_type,
        uint_type)>
      program_uniform4ui;

    struct : func<OGLPAFP(ProgramUniform1uiv)> {
        using func<OGLPAFP(ProgramUniform1uiv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          span<const uint_type> v) const noexcept {
            return this->_cnvchkcall(prog, loc, sizei_type(v.size()), v.data());
        }
    } program_uniform1uiv;

    struct : func<OGLPAFP(ProgramUniform2uiv)> {
        using func<OGLPAFP(ProgramUniform2uiv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          span<const uint_type> v) const noexcept {
            return this->_cnvchkcall(prog, loc, sizei_type(v.size()), v.data());
        }
    } program_uniform2uiv;

    struct : func<OGLPAFP(ProgramUniform3uiv)> {
        using func<OGLPAFP(ProgramUniform3uiv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          span<const uint_type> v) const noexcept {
            return this->_cnvchkcall(prog, loc, sizei_type(v.size()), v.data());
        }
    } program_uniform3uiv;

    struct : func<OGLPAFP(ProgramUniform4uiv)> {
        using func<OGLPAFP(ProgramUniform4uiv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          span<const uint_type> v) const noexcept {
            return this->_cnvchkcall(prog, loc, sizei_type(v.size()), v.data());
        }
    } program_uniform4uiv;

    // int
    func<
      OGLPAFP(ProgramUniform1i),
      void(program_name, uniform_location, int_type)>
      program_uniform1i;

    func<
      OGLPAFP(ProgramUniform2i),
      void(program_name, uniform_location, int_type, int_type)>
      program_uniform2i;

    func<
      OGLPAFP(ProgramUniform3i),
      void(program_name, uniform_location, int_type, int_type, int_type)>
      program_uniform3i;

    func<
      OGLPAFP(ProgramUniform4i),
      void(
        program_name, uniform_location, int_type, int_type, int_type, int_type)>
      program_uniform4i;

    struct : func<OGLPAFP(ProgramUniform1iv)> {
        using func<OGLPAFP(ProgramUniform1iv)>::func;

        constexpr auto operator()(
          program_name prog, uniform_location loc, span<const int_type> v) const
          noexcept {
            return this->_cnvchkcall(prog, loc, sizei_type(v.size()), v.data());
        }
    } program_uniform1iv;

    struct : func<OGLPAFP(ProgramUniform2iv)> {
        using func<OGLPAFP(ProgramUniform2iv)>::func;

        constexpr auto operator()(
          program_name prog, uniform_location loc, span<const int_type> v) const
          noexcept {
            return this->_cnvchkcall(prog, loc, sizei_type(v.size()), v.data());
        }
    } program_uniform2iv;

    struct : func<OGLPAFP(ProgramUniform3iv)> {
        using func<OGLPAFP(ProgramUniform3iv)>::func;

        constexpr auto operator()(
          program_name prog, uniform_location loc, span<const int_type> v) const
          noexcept {
            return this->_cnvchkcall(prog, loc, sizei_type(v.size()), v.data());
        }
    } program_uniform3iv;

    struct : func<OGLPAFP(ProgramUniform4iv)> {
        using func<OGLPAFP(ProgramUniform4iv)>::func;

        constexpr auto operator()(
          program_name prog, uniform_location loc, span<const int_type> v) const
          noexcept {
            return this->_cnvchkcall(prog, loc, sizei_type(v.size()), v.data());
        }
    } program_uniform4iv;

    // float
    func<
      OGLPAFP(ProgramUniform1f),
      void(program_name, uniform_location, float_type)>
      program_uniform1f;

    func<
      OGLPAFP(ProgramUniform2f),
      void(program_name, uniform_location, float_type, float_type)>
      program_uniform2f;

    func<
      OGLPAFP(ProgramUniform3f),
      void(program_name, uniform_location, float_type, float_type, float_type)>
      program_uniform3f;

    func<
      OGLPAFP(ProgramUniform4f),
      void(
        program_name,
        uniform_location,
        float_type,
        float_type,
        float_type,
        float_type)>
      program_uniform4f;

    struct : func<OGLPAFP(ProgramUniform1fv)> {
        using func<OGLPAFP(ProgramUniform1fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(prog, loc, sizei_type(v.size()), v.data());
        }
    } program_uniform1fv;

    struct : func<OGLPAFP(ProgramUniform2fv)> {
        using func<OGLPAFP(ProgramUniform2fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(prog, loc, sizei_type(v.size()), v.data());
        }
    } program_uniform2fv;

    struct : func<OGLPAFP(ProgramUniform3fv)> {
        using func<OGLPAFP(ProgramUniform3fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(prog, loc, sizei_type(v.size()), v.data());
        }
    } program_uniform3fv;

    struct : func<OGLPAFP(ProgramUniform4fv)> {
        using func<OGLPAFP(ProgramUniform4fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(prog, loc, sizei_type(v.size()), v.data());
        }
    } program_uniform4fv;

    // matrix float
    struct : func<OGLPAFP(ProgramUniformMatrix2fv)> {
        using func<OGLPAFP(ProgramUniformMatrix2fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              prog, loc, sizei_type(v.size()), transp, v.data());
        }
    } program_uniform_matrix2fv;

    struct : func<OGLPAFP(ProgramUniformMatrix3fv)> {
        using func<OGLPAFP(ProgramUniformMatrix3fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              prog, loc, sizei_type(v.size()), transp, v.data());
        }
    } program_uniform_matrix3fv;

    struct : func<OGLPAFP(ProgramUniformMatrix4fv)> {
        using func<OGLPAFP(ProgramUniformMatrix4fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              prog, loc, sizei_type(v.size()), transp, v.data());
        }
    } program_uniform_matrix4fv;

    struct : func<OGLPAFP(ProgramUniformMatrix2x3fv)> {
        using func<OGLPAFP(ProgramUniformMatrix2x3fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              prog, loc, sizei_type(v.size()), transp, v.data());
        }
    } program_uniform_matrix2x3fv;

    struct : func<OGLPAFP(ProgramUniformMatrix2x4fv)> {
        using func<OGLPAFP(ProgramUniformMatrix2x4fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              prog, loc, sizei_type(v.size()), transp, v.data());
        }
    } program_uniform_matrix2x4fv;

    struct : func<OGLPAFP(ProgramUniformMatrix3x2fv)> {
        using func<OGLPAFP(ProgramUniformMatrix3x2fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              prog, loc, sizei_type(v.size()), transp, v.data());
        }
    } program_uniform_matrix3x2fv;

    struct : func<OGLPAFP(ProgramUniformMatrix3x4fv)> {
        using func<OGLPAFP(ProgramUniformMatrix3x4fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              prog, loc, sizei_type(v.size()), transp, v.data());
        }
    } program_uniform_matrix3x4fv;

    struct : func<OGLPAFP(ProgramUniformMatrix4x2fv)> {
        using func<OGLPAFP(ProgramUniformMatrix4x2fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              prog, loc, sizei_type(v.size()), transp, v.data());
        }
    } program_uniform_matrix4x2fv;

    struct : func<OGLPAFP(ProgramUniformMatrix4x3fv)> {
        using func<OGLPAFP(ProgramUniformMatrix4x3fv)>::func;

        constexpr auto operator()(
          program_name prog,
          uniform_location loc,
          true_false transp,
          span<const float_type> v) const noexcept {
            return this->_cnvchkcall(
              prog, loc, sizei_type(v.size()), transp, v.data());
        }
    } program_uniform_matrix4x3fv;

    // buffer ops
    func<OGLPAFP(BindBuffer), void(buffer_target, buffer_name)> bind_buffer;

    func<OGLPAFP(BindBufferBase), void(buffer_target, uint_type, buffer_name)>
      bind_buffer_base;

    func<
      OGLPAFP(BindBufferRange),
      void(buffer_target, uint_type, buffer_name, intptr_type, sizeiptr_type)>
      bind_buffer_range;

    func<
      OGLPAFP(BufferStorage),
      void(
        buffer_target,
        sizeiptr_type,
        const_void_ptr_type,
        enum_bitfield<buffer_storage_bit>)>
      buffer_storage;

    func<
      OGLPAFP(NamedBufferStorage),
      void(
        buffer_name,
        sizeiptr_type,
        const_void_ptr_type,
        enum_bitfield<buffer_storage_bit>)>
      named_buffer_storage;

    struct : func<OGLPAFP(BufferData)> {
        using func<OGLPAFP(BufferData)>::func;

        constexpr auto operator()(
          buffer_target tgt,
          const buffer_data_spec& values,
          buffer_usage usg) const noexcept {
            return this->_cnvchkcall(
              tgt, sizei_type(values.size()), values.data(), usg);
        }
    } buffer_data;

    struct : func<OGLPAFP(NamedBufferData)> {
        using func<OGLPAFP(NamedBufferData)>::func;

        constexpr auto operator()(
          buffer_name buf,
          const buffer_data_spec& values,
          buffer_usage usg) const noexcept {
            return this->_cnvchkcall(
              buf, sizei_type(values.size()), values.data(), usg);
        }
    } named_buffer_data;

    struct : func<OGLPAFP(BufferSubData)> {
        using func<OGLPAFP(BufferSubData)>::func;

        constexpr auto operator()(
          buffer_target tgt,
          intptr_type offs,
          const buffer_data_spec& values) const noexcept {
            return this->_cnvchkcall(
              tgt, offs, sizei_type(values.size()), values.data());
        }
    } buffer_sub_data;

    struct : func<OGLPAFP(NamedBufferSubData)> {
        using func<OGLPAFP(NamedBufferSubData)>::func;

        constexpr auto operator()(
          buffer_name buf,
          intptr_type offs,
          const buffer_data_spec& values) const noexcept {
            return this->_cnvchkcall(
              buf, offs, sizei_type(values.size()), values.data());
        }
    } named_buffer_sub_data;

    func<
      OGLPAFP(ClearBufferData),
      void(
        buffer_target,
        pixel_internal_format,
        pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      clear_buffer_data;

    func<
      OGLPAFP(ClearNamedBufferData),
      void(
        buffer_name,
        pixel_internal_format,
        pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      clear_named_buffer_data;

    func<
      OGLPAFP(ClearBufferSubData),
      void(
        buffer_target,
        pixel_internal_format,
        intptr_type,
        sizeiptr_type pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      clear_buffer_sub_data;

    func<
      OGLPAFP(ClearNamedBufferSubData),
      void(
        buffer_name,
        pixel_internal_format,
        intptr_type,
        sizeiptr_type pixel_format,
        pixel_data_type,
        const_void_ptr_type)>
      clear_named_buffer_sub_data;

    func<
      OGLPAFP(MapBuffer),
      void_ptr_type(buffer_target, enum_bitfield<buffer_map_access_bit>)>
      map_buffer;

    func<
      OGLPAFP(MapNamedBuffer),
      void_ptr_type(buffer_name, enum_bitfield<buffer_map_access_bit>)>
      map_named_buffer;

    func<
      OGLPAFP(MapBufferRange),
      void_ptr_type(
        buffer_target,
        intptr_type,
        sizeiptr_type,
        enum_bitfield<buffer_map_access_bit>)>
      map_buffer_range;

    func<
      OGLPAFP(MapNamedBufferRange),
      void_ptr_type(
        buffer_name,
        intptr_type,
        sizeiptr_type,
        enum_bitfield<buffer_map_access_bit>)>
      map_named_buffer_range;

    func<
      OGLPAFP(FlushMappedBufferRange),
      void_ptr_type(buffer_target, intptr_type, sizeiptr_type)>
      flush_mapped_buffer_range;

    func<
      OGLPAFP(FlushMappedNamedBufferRange),
      void_ptr_type(buffer_name, intptr_type, sizeiptr_type)>
      flush_mapped_named_buffer_range;

    func<OGLPAFP(UnmapBuffer), void_ptr_type(buffer_target)> unmap_buffer;

    func<OGLPAFP(UnmapNamedBuffer), void_ptr_type(buffer_name)>
      unmap_named_buffer;

    func<OGLPAFP(InvalidateBufferData), void(buffer_name)>
      invalidate_buffer_data;

    func<
      OGLPAFP(InvalidateBufferData),
      void(buffer_name, intptr_type, sizeiptr_type)>
      invalidate_buffer_sub_data;

    func<
      OGLPAFP(CopyBufferSubData),
      void(
        buffer_target, buffer_target, intptr_type, intptr_type, sizeiptr_type)>
      copy_buffer_sub_data;

    func<
      OGLPAFP(CopyNamedBufferSubData),
      void(buffer_name, buffer_name, intptr_type, intptr_type, sizeiptr_type)>
      copy_named_buffer_sub_data;

    query_func<
      mp_list<buffer_target>,
      mp_list<buffer_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetBufferParameteriv)>
      get_buffer_parameter_i;

    query_func<
      mp_list<buffer_name>,
      mp_list<buffer_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetNamedBufferParameteriv)>
      get_named_buffer_parameter_i;

    query_func<
      mp_list<buffer_target>,
      mp_list<buffer_parameter>,
      mp_list<>,
      int64_type,
      OGLPAFP(GetBufferParameteri64v)>
      get_buffer_parameter_i64;

    query_func<
      mp_list<buffer_name>,
      mp_list<buffer_parameter>,
      mp_list<>,
      int64_type,
      OGLPAFP(GetNamedBufferParameteri64v)>
      get_named_buffer_parameter_i64;

    // vertex_array ops
    func<OGLPAFP(BindVertexArray), void(vertex_array_name)> bind_vertex_array;

    func<
      OGLPAFP(BindVertexBuffer),
      void(vertex_buffer_binding, buffer_name, intptr_type, sizei_type)>
      bind_vertex_buffer;

    func<
      OGLPAFP(VertexArrayVertexBuffer),
      void(
        vertex_array_name,
        vertex_buffer_binding,
        buffer_name,
        intptr_type,
        sizei_type)>
      vertex_array_vertex_buffer;

    func<
      OGLPAFP(VertexArrayElementBuffer),
      void(vertex_array_name, buffer_name)>
      vertex_array_element_buffer;

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
      OGLPAFP(VertexAttribFormat),
      void(vertex_attrib_location, int_type, data_type, true_false, uint_type)>
      vertex_attrib_format;

    func<
      OGLPAFP(VertexAttribIFormat),
      void(vertex_attrib_location, int_type, data_type, uint_type)>
      vertex_attrib_iformat;

    func<
      OGLPAFP(VertexAttribLFormat),
      void(vertex_attrib_location, int_type, data_type, uint_type)>
      vertex_attrib_lformat;

    func<
      OGLPAFP(VertexArrayAttribFormat),
      void(
        vertex_array_name,
        vertex_attrib_location,
        int_type,
        data_type,
        true_false,
        uint_type)>
      vertex_array_attrib_format;

    func<
      OGLPAFP(VertexArrayAttribIFormat),
      void(
        vertex_array_name,
        vertex_attrib_location,
        int_type,
        data_type,
        uint_type)>
      vertex_array_attrib_iformat;

    func<
      OGLPAFP(VertexArrayAttribLFormat),
      void(
        vertex_array_name,
        vertex_attrib_location,
        int_type,
        data_type,
        uint_type)>
      vertex_array_attrib_lformat;

    struct : func<OGLPAFP(VertexAttribPointer)> {
        using func<OGLPAFP(VertexAttribPointer)>::func;

        constexpr auto operator()(
          vertex_attrib_location loc,
          int_type size,
          data_type type,
          true_false norm) const noexcept {
            return this->_cnvchkcall(loc, size, type, norm, 0, nullptr);
        }

        constexpr auto operator()(
          vertex_attrib_location loc,
          int_type size,
          data_type type,
          true_false norm,
          sizei_type stride,
          const_void_ptr_type pointer) const noexcept {
            return this->_cnvchkcall(loc, size, type, norm, stride, pointer);
        }
    } vertex_attrib_pointer;

    struct : func<OGLPAFP(VertexAttribIPointer)> {
        using func<OGLPAFP(VertexAttribIPointer)>::func;

        constexpr auto operator()(
          vertex_attrib_location loc, int_type size, data_type type) const
          noexcept {
            return this->_cnvchkcall(loc, size, type, 0, nullptr);
        }

        constexpr auto operator()(
          vertex_attrib_location loc,
          int_type size,
          data_type type,
          sizei_type stride,
          const_void_ptr_type pointer) const noexcept {
            return this->_cnvchkcall(loc, size, type, stride, pointer);
        }
    } vertex_attrib_ipointer;

    struct : func<OGLPAFP(VertexAttribLPointer)> {
        using func<OGLPAFP(VertexAttribLPointer)>::func;

        constexpr auto operator()(
          vertex_attrib_location loc, int_type size, data_type type) const
          noexcept {
            return this->_cnvchkcall(loc, size, type, 0, nullptr);
        }

        constexpr auto operator()(
          vertex_attrib_location loc,
          int_type size,
          data_type type,
          sizei_type stride,
          const_void_ptr_type pointer) const noexcept {
            return this->_cnvchkcall(loc, size, type, stride, pointer);
        }
    } vertex_attrib_lpointer;

    func<
      OGLPAFP(VertexAttribBinding),
      void(vertex_attrib_location, vertex_buffer_binding)>
      vertex_attrib_binding;

    func<
      OGLPAFP(VertexArrayAttribBinding),
      void(vertex_array_name, vertex_attrib_location, vertex_buffer_binding)>
      vertex_array_attrib_binding;

    func<OGLPAFP(VertexBindingDivisor), void(vertex_buffer_binding, uint_type)>
      vertex_binding_divisor;

    func<
      OGLPAFP(VertexArrayBindingDivisor),
      void(vertex_buffer_binding, uint_type)>
      vertex_array_binding_divisor;

    func<OGLPAFP(VertexAttribDivisor), void(vertex_attrib_location, uint_type)>
      vertex_attrib_divisor;

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
        memory::const_block)>
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
        memory::const_block)>
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
        memory::const_block)>
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
        memory::const_block)>
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
        memory::const_block)>
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
        memory::const_block)>
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
        memory::const_block)>
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
        memory::const_block)>
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
        memory::const_block)>
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

    struct : func<OGLPAFP(CompressedTexImage3D)> {
        using func<OGLPAFP(CompressedTexImage3D)>::func;

        constexpr auto operator()(
          texture_target tgt,
          int_type level,
          pixel_internal_format ifmt,
          sizei_type width,
          sizei_type height,
          sizei_type depth,
          int_type border,
          memory::const_block data) const noexcept {
            return this->_cnvchkcall(
              tgt,
              level,
              ifmt,
              width,
              height,
              depth,
              border,
              data.size(),
              data.data());
        }
    } compressed_tex_image3d;

    struct : func<OGLPAFP(CompressedTexImage2D)> {
        using func<OGLPAFP(CompressedTexImage2D)>::func;

        constexpr auto operator()(
          texture_target tgt,
          int_type level,
          pixel_internal_format ifmt,
          sizei_type width,
          sizei_type height,
          int_type border,
          memory::const_block data) const noexcept {
            return this->_cnvchkcall(
              tgt,
              level,
              ifmt,
              width,
              height,
              border,
              data.size(),
              data.data());
        }
    } compressed_tex_image2d;

    struct : func<OGLPAFP(CompressedTexImage1D)> {
        using func<OGLPAFP(CompressedTexImage1D)>::func;

        constexpr auto operator()(
          texture_target tgt,
          int_type level,
          pixel_internal_format ifmt,
          sizei_type width,
          int_type border,
          memory::const_block data) const noexcept {
            return this->_cnvchkcall(
              tgt, level, ifmt, width, border, data.size(), data.data());
        }
    } compressed_tex_image1d;

    struct : func<OGLPAFP(CompressedTexSubImage3D)> {
        using func<OGLPAFP(CompressedTexSubImage3D)>::func;
        constexpr auto operator()(
          texture_target tgt,
          int_type level,
          int_type xoffset,
          int_type yoffset,
          int_type zoffset,
          sizei_type width,
          sizei_type height,
          sizei_type depth,
          pixel_format fmt,
          memory::const_block data) const noexcept {
            return this->_cnvchkcall(
              tgt,
              level,
              xoffset,
              yoffset,
              zoffset,
              width,
              height,
              depth,
              fmt,
              data.size(),
              data.data());
        }
    } compressed_tex_sub_image3d;

    struct : func<OGLPAFP(CompressedTextureSubImage3D)> {
        using func<OGLPAFP(CompressedTextureSubImage3D)>::func;
        constexpr auto operator()(
          texture_name tex,
          int_type level,
          int_type xoffset,
          int_type yoffset,
          int_type zoffset,
          sizei_type width,
          sizei_type height,
          sizei_type depth,
          pixel_format fmt,
          memory::const_block data) const noexcept {
            return this->_cnvchkcall(
              tex,
              level,
              xoffset,
              yoffset,
              zoffset,
              width,
              height,
              depth,
              fmt,
              data.size(),
              data.data());
        }
    } compressed_texture_sub_image3d;

    struct : func<OGLPAFP(CompressedTexSubImage2D)> {
        using func<OGLPAFP(CompressedTexSubImage2D)>::func;
        constexpr auto operator()(
          texture_target tgt,
          int_type level,
          int_type xoffset,
          int_type yoffset,
          sizei_type width,
          sizei_type height,
          pixel_format fmt,
          memory::const_block data) const noexcept {
            return this->_cnvchkcall(
              tgt,
              level,
              xoffset,
              yoffset,
              width,
              height,
              fmt,
              data.size(),
              data.data());
        }
    } compressed_tex_sub_image2d;

    struct : func<OGLPAFP(CompressedTextureSubImage2D)> {
        using func<OGLPAFP(CompressedTextureSubImage2D)>::func;
        constexpr auto operator()(
          texture_name tex,
          int_type level,
          int_type xoffset,
          int_type yoffset,
          sizei_type width,
          sizei_type height,
          pixel_format fmt,
          memory::const_block data) const noexcept {
            return this->_cnvchkcall(
              tex,
              level,
              xoffset,
              yoffset,
              width,
              height,
              fmt,
              data.size(),
              data.data());
        }
    } compressed_texture_sub_image2d;

    struct : func<OGLPAFP(CompressedTexSubImage1D)> {
        using func<OGLPAFP(CompressedTexSubImage1D)>::func;
        constexpr auto operator()(
          texture_target tgt,
          int_type level,
          int_type xoffset,
          sizei_type width,
          pixel_format fmt,
          memory::const_block data) const noexcept {
            return this->_cnvchkcall(
              tgt, level, xoffset, width, fmt, data.size(), data.data());
        }
    } compressed_tex_sub_image1d;

    struct : func<OGLPAFP(CompressedTextureSubImage1D)> {
        using func<OGLPAFP(CompressedTextureSubImage1D)>::func;
        constexpr auto operator()(
          texture_name tex,
          int_type level,
          int_type xoffset,
          sizei_type width,
          pixel_format fmt,
          memory::const_block data) const noexcept {
            return this->_cnvchkcall(
              tex, level, xoffset, width, fmt, data.size(), data.data());
        }
    } compressed_texture_sub_image1d;

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

    func<
      OGLPAFP(TexParameterf),
      void(texture_target, texture_parameter, float_type)>
      tex_parameter_f;

    func<
      OGLPAFP(TextureParameterf),
      void(texture_name, texture_parameter, float_type)>
      texture_parameter_f;

    struct : func<OGLPAFP(TexParameteri)> {
        using func<OGLPAFP(TexParameteri)>::func;

        template <
          typename TexParam,
          typename Value,
          typename = std::enable_if_t<is_enum_parameter_value_v<
            texture_parameter,
            TexParam,
            int_type,
            Value>>>
        constexpr auto operator()(
          texture_target tgt, TexParam param, Value value) const noexcept {
            return this->_chkcall(
              enum_type(tgt), enum_type(param), enum_type(value));
        }
    } tex_parameter_i;

    struct : func<OGLPAFP(TextureParameteri)> {
        using func<OGLPAFP(TextureParameteri)>::func;

        template <
          typename TexParam,
          typename Value,
          typename = std::enable_if_t<is_enum_parameter_value_v<
            texture_parameter,
            TexParam,
            int_type,
            Value>>>
        constexpr auto operator()(
          texture_name tex, TexParam param, Value value) noexcept {
            return this->_chkcall(
              name_type(tex), enum_type(param), enum_type(value));
        }
    } texture_parameter_i;

    struct : func<OGLPAFP(TexParameterfv)> {
        using func<OGLPAFP(TexParameterfv)>::func;

        constexpr auto operator()(
          texture_target tgt,
          texture_parameter param,
          span<const float_type> values) noexcept {
            return this->_cnvchkcall(tgt, param, values.data());
        }
    } tex_parameter_fv;

    struct : func<OGLPAFP(TextureParameterfv)> {
        using func<OGLPAFP(TextureParameterfv)>::func;

        constexpr auto operator()(
          texture_name tex,
          texture_parameter param,
          span<const float_type> values) noexcept {
            return this->_cnvchkcall(tex, param, values.data());
        }
    } texture_parameter_fv;

    struct : func<OGLPAFP(TexParameteriv)> {
        using func<OGLPAFP(TexParameteriv)>::func;

        constexpr auto operator()(
          texture_target tgt,
          texture_parameter param,
          span<const int_type> values) noexcept {
            return this->_cnvchkcall(tgt, param, values.data());
        }
    } tex_parameter_iv;

    struct : func<OGLPAFP(TextureParameteriv)> {
        using func<OGLPAFP(TextureParameteriv)>::func;

        constexpr auto operator()(
          texture_name tex,
          texture_parameter param,
          span<const int_type> values) noexcept {
            return this->_cnvchkcall(tex, param, values.data());
        }
    } texture_parameter_iv;

    struct : func<OGLPAFP(TexParameterIiv)> {
        using func<OGLPAFP(TexParameterIiv)>::func;

        constexpr auto operator()(
          texture_target tgt,
          texture_parameter param,
          span<const int_type> values) noexcept {
            return this->_cnvchkcall(tgt, param, values.data());
        }
    } tex_parameter_iiv;

    struct : func<OGLPAFP(TextureParameterIiv)> {
        using func<OGLPAFP(TextureParameterIiv)>::func;

        constexpr auto operator()(
          texture_name tex,
          texture_parameter param,
          span<const int_type> values) noexcept {
            return this->_cnvchkcall(tex, param, values.data());
        }
    } texture_parameter_iiv;

    struct : func<OGLPAFP(TexParameterIuiv)> {
        using func<OGLPAFP(TexParameterIuiv)>::func;

        constexpr auto operator()(
          texture_target tgt,
          texture_parameter param,
          span<const uint_type> values) noexcept {
            return this->_cnvchkcall(tgt, param, values.data());
        }
    } tex_parameter_iuiv;

    struct : func<OGLPAFP(TextureParameterIuiv)> {
        using func<OGLPAFP(TextureParameterIuiv)>::func;

        constexpr auto operator()(
          texture_name tex,
          texture_parameter param,
          span<const uint_type> values) noexcept {
            return this->_cnvchkcall(tex, param, values.data());
        }
    } texture_parameter_iuiv;

    query_func<
      mp_list<texture_target>,
      mp_list<texture_parameter>,
      mp_list<>,
      float_type,
      OGLPAFP(GetTexParameterfv)>
      get_tex_parameter_f;

    query_func<
      mp_list<texture_name>,
      mp_list<texture_parameter>,
      mp_list<>,
      float_type,
      OGLPAFP(GetTextureParameterfv)>
      get_texture_parameter_f;

    query_func<
      mp_list<texture_target>,
      mp_list<texture_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetTexParameteriv)>
      get_tex_parameter_i;

    query_func<
      mp_list<texture_name>,
      mp_list<texture_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetTextureParameteriv)>
      get_texture_parameter_i;

    query_func<
      mp_list<texture_target>,
      mp_list<texture_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetTexParameterIiv)>
      get_tex_parameter_ii;

    query_func<
      mp_list<texture_name>,
      mp_list<texture_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetTextureParameterIiv)>
      get_texture_parameter_ii;

    query_func<
      mp_list<texture_target>,
      mp_list<texture_parameter>,
      mp_list<>,
      uint_type,
      OGLPAFP(GetTexParameterIuiv)>
      get_tex_parameter_iui;

    query_func<
      mp_list<texture_name>,
      mp_list<texture_parameter>,
      mp_list<>,
      uint_type,
      OGLPAFP(GetTextureParameterIuiv)>
      get_texture_parameter_iui;

    func<OGLPAFP(GenerateMipmap), void(texture_target)> generate_mipmap;

    func<OGLPAFP(GenerateTextureMipmap), void(texture_name)>
      generate_texture_mipmap;

    // sampler ops
    func<OGLPAFP(BindSampler), void(uint_type, sampler_name)> bind_sampler;

    func<
      OGLPAFP(SamplerParameterf),
      void(sampler_name, sampler_parameter, float_type)>
      sampler_parameter_f;

    func<
      OGLPAFP(SamplerParameteri),
      void(sampler_name, sampler_parameter, int_type)>
      sampler_parameter_i;

    struct : func<OGLPAFP(SamplerParameterfv)> {
        using func<OGLPAFP(SamplerParameterfv)>::func;

        constexpr auto operator()(
          sampler_name sam,
          sampler_parameter param,
          span<const float_type> values) noexcept {
            return this->_cnvchkcall(sam, param, values.data());
        }
    } sampler_parameter_fv;

    struct : func<OGLPAFP(SamplerParameteriv)> {
        using func<OGLPAFP(SamplerParameteriv)>::func;

        constexpr auto operator()(
          sampler_name sam,
          sampler_parameter param,
          span<const int_type> values) noexcept {
            return this->_cnvchkcall(sam, param, values.data());
        }
    } sampler_parameter_iv;

    struct : func<OGLPAFP(SamplerParameterIiv)> {
        using func<OGLPAFP(SamplerParameterIiv)>::func;

        constexpr auto operator()(
          sampler_name sam,
          sampler_parameter param,
          span<const int_type> values) noexcept {
            return this->_cnvchkcall(sam, param, values.data());
        }
    } sampler_parameter_iiv;

    struct : func<OGLPAFP(SamplerParameterIuiv)> {
        using func<OGLPAFP(SamplerParameterIuiv)>::func;

        constexpr auto operator()(
          sampler_name sam,
          sampler_parameter param,
          span<const uint_type> values) noexcept {
            return this->_cnvchkcall(sam, param, values.data());
        }
    } sampler_parameter_iuiv;

    query_func<
      mp_list<sampler_name>,
      mp_list<sampler_parameter>,
      mp_list<>,
      float_type,
      OGLPAFP(GetSamplerParameterfv)>
      get_sampler_parameter_f;

    query_func<
      mp_list<sampler_name>,
      mp_list<sampler_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetSamplerParameteriv)>
      get_sampler_parameter_i;

    query_func<
      mp_list<sampler_name>,
      mp_list<sampler_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetSamplerParameterIiv)>
      get_sampler_parameter_ii;

    query_func<
      mp_list<sampler_name>,
      mp_list<sampler_parameter>,
      mp_list<>,
      uint_type,
      OGLPAFP(GetSamplerParameterIuiv)>
      get_sampler_parameter_iui;

    // renderbuffer ops
    func<
      OGLPAFP(BindRenderbuffer),
      void(renderbuffer_target, renderbuffer_name)>
      bind_renderbuffer;

    func<
      OGLPAFP(RenderbufferStorage),
      void(renderbuffer_target, pixel_internal_format, sizei_type, sizei_type)>
      renderbuffer_storage;

    func<
      OGLPAFP(NamedRenderbufferStorage),
      void(renderbuffer_target, pixel_internal_format, sizei_type, sizei_type)>
      named_renderbuffer_storage;

    func<
      OGLPAFP(RenderbufferStorageMultisample),
      void(
        renderbuffer_target,
        sizei_type,
        pixel_internal_format,
        sizei_type,
        sizei_type)>
      renderbuffer_storage_multisample;

    func<
      OGLPAFP(NamedRenderbufferStorageMultisample),
      void(
        renderbuffer_target,
        sizei_type,
        pixel_internal_format,
        sizei_type,
        sizei_type)>
      named_renderbuffer_storage_multisample;

    query_func<
      mp_list<renderbuffer_target>,
      mp_list<renderbuffer_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetRenderbufferParameteriv)>
      get_renderbuffer_parameter_i;

    query_func<
      mp_list<renderbuffer_name>,
      mp_list<renderbuffer_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetNamedRenderbufferParameteriv)>
      get_named_renderbuffer_parameter_i;

    // framebuffer ops
    func<OGLPAFP(BindFramebuffer), void(framebuffer_target, framebuffer_name)>
      bind_framebuffer;

    func<OGLPAFP(DrawBuffer), void(surface_buffer)> draw_buffer;

    func<
      OGLPAFP(NamedFramebufferDrawBuffer),
      void(framebuffer_name, surface_buffer)>
      named_framebuffer_draw_buffer;

    func<OGLPAFP(ReadBuffer), void(surface_buffer)> read_buffer;

    func<
      OGLPAFP(NamedFramebufferReadBuffer),
      void(framebuffer_name, surface_buffer)>
      named_framebuffer_read_buffer;

    func<
      OGLPAFP(FramebufferParameteri),
      void(framebuffer_target, framebuffer_parameter, int_type)>
      framebuffer_parameter_i;

    func<
      OGLPAFP(NamedFramebufferParameteri),
      void(framebuffer_name, framebuffer_parameter, int_type)>
      named_framebuffer_parameter_i;

    query_func<
      mp_list<framebuffer_target>,
      mp_list<framebuffer_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetFramebufferParameteriv)>
      get_framebuffer_parameter_i;

    query_func<
      mp_list<framebuffer_name>,
      mp_list<framebuffer_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetNamedFramebufferParameteriv)>
      get_named_framebuffer_parameter_i;

    query_func<
      mp_list<framebuffer_target, framebuffer_attachment>,
      mp_list<framebuffer_attachment_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetFramebufferAttachmentParameteriv)>
      get_framebuffer_attachment_parameter_i;

    query_func<
      mp_list<framebuffer_name, framebuffer_attachment>,
      mp_list<framebuffer_attachment_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetNamedFramebufferAttachmentParameteriv)>
      get_named_framebuffer_attachment_parameter_i;

    func<
      OGLPAFP(FramebufferRenderbuffer),
      void(
        framebuffer_target,
        oglp::framebuffer_attachment,
        renderbuffer_target,
        renderbuffer_name)>
      framebuffer_renderbuffer;

    func<
      OGLPAFP(NamedFramebufferRenderbuffer),
      void(
        framebuffer_name,
        oglp::framebuffer_attachment,
        renderbuffer_target,
        renderbuffer_name)>
      named_framebuffer_renderbuffer;

    func<
      OGLPAFP(FramebufferTexture),
      void(
        framebuffer_target,
        oglp::framebuffer_attachment,
        texture_name,
        int_type)>
      framebuffer_texture;

    func<
      OGLPAFP(NamedFramebufferTexture),
      void(
        framebuffer_name, oglp::framebuffer_attachment, texture_name, int_type)>
      named_framebuffer_texture;

    func<
      OGLPAFP(FramebufferTexture1D),
      void(
        framebuffer_target,
        oglp::framebuffer_attachment,
        texture_name,
        int_type)>
      framebuffer_texture1d;

    func<
      OGLPAFP(FramebufferTexture2D),
      void(
        framebuffer_target,
        oglp::framebuffer_attachment,
        texture_name,
        int_type)>
      framebuffer_texture2d;

    func<
      OGLPAFP(FramebufferTexture3D),
      void(
        framebuffer_target,
        oglp::framebuffer_attachment,
        texture_name,
        int_type)>
      framebuffer_texture3d;

    func<
      OGLPAFP(FramebufferTextureLayer),
      void(
        framebuffer_target,
        oglp::framebuffer_attachment,
        texture_name,
        int_type,
        int_type)>
      framebuffer_texture_layer;

    func<
      OGLPAFP(NamedFramebufferTextureLayer),
      void(
        framebuffer_name,
        oglp::framebuffer_attachment,
        texture_name,
        int_type,
        int_type)>
      named_framebuffer_texture_layer;

    func<
      OGLPAFP(CheckFramebufferStatus),
      framebuffer_status(framebuffer_target)>
      check_framebuffer_status;

    func<
      OGLPAFP(CheckNamedFramebufferStatus),
      framebuffer_status(framebuffer_name, framebuffer_target)>
      check_named_framebuffer_status;

    func<
      OGLPAFP(BlitFramebuffer),
      void(
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        enum_bitfield<buffer_blit_bit>,
        blit_filter)>
      blit_framebuffer;

    func<
      OGLPAFP(BlitNamedFramebuffer),
      void(
        framebuffer_name,
        framebuffer_name,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        int_type,
        enum_bitfield<buffer_blit_bit>,
        blit_filter)>
      blit_named_framebuffer;

    // transform feedback ops
    func<
      OGLPAFP(BindTransformFeedback),
      void(transform_feedback_target, transform_feedback_name)>
      bind_transform_feedback;

    func<
      OGLPAFP(BeginTransformFeedback),
      void(transform_feedback_primitive_type)>
      begin_transform_feedback;

    func<OGLPAFP(PauseTransformFeedback)> pause_transform_feedback;

    func<OGLPAFP(ResumeTransformFeedback)> resume_transform_feedback;

    func<OGLPAFP(EndTransformFeedback)> end_transform_feedback;

    func<
      OGLPAFP(TransformFeedbackBufferBase),
      void(transform_feedback_name, uint_type, buffer_name)>
      transform_feedback_buffer_base;

    func<
      OGLPAFP(TransformFeedbackBufferRange),
      void(
        transform_feedback_name,
        uint_type,
        buffer_name,
        intptr_type,
        sizeiptr_type)>
      transform_feedback_buffer_range;

    query_func<
      mp_list<transform_feedback_name>,
      mp_list<transform_feedback_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetTransformFeedbackiv)>
      get_transform_feedback_i;

    query_func<
      mp_list<transform_feedback_name>,
      mp_list<transform_feedback_parameter>,
      mp_list<uint_type>,
      int_type,
      OGLPAFP(GetTransformFeedbacki_v)>
      get_transform_feedback_ii;

    query_func<
      mp_list<transform_feedback_name>,
      mp_list<transform_feedback_parameter>,
      mp_list<uint_type>,
      int64_type,
      OGLPAFP(GetTransformFeedbacki64_v)>
      get_transform_feedback_i64i;

    // query ops
    query_func<
      mp_list<query_target>,
      mp_list<query_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetQueryiv)>
      get_query_i;

    query_func<
      mp_list<query_target, uint_type>,
      mp_list<query_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetQueryIndexediv)>
      get_query_indexed_i;

    query_func<
      mp_list<query_name>,
      mp_list<query_parameter>,
      mp_list<>,
      int_type,
      OGLPAFP(GetQueryObjectiv)>
      get_query_object_i;

    query_func<
      mp_list<query_name>,
      mp_list<query_parameter>,
      mp_list<>,
      uint_type,
      OGLPAFP(GetQueryObjectuiv)>
      get_query_object_ui;

    query_func<
      mp_list<query_name>,
      mp_list<query_parameter>,
      mp_list<>,
      int64_type,
      OGLPAFP(GetQueryObjecti64v)>
      get_query_object_i64;

    query_func<
      mp_list<query_name>,
      mp_list<query_parameter>,
      mp_list<>,
      uint64_type,
      OGLPAFP(GetQueryObjectui64v)>
      get_query_object_ui64;

    func<
      OGLPAFP(GetQueryBufferObjectiv),
      void(query_name, buffer_name, query_parameter, intptr_type)>
      get_query_buffer_object_i;

    func<
      OGLPAFP(GetQueryBufferObjectuiv),
      void(query_name, buffer_name, query_parameter, intptr_type)>
      get_query_buffer_object_ui;

    func<
      OGLPAFP(GetQueryBufferObjecti64v),
      void(query_name, buffer_name, query_parameter, intptr_type)>
      get_query_buffer_object_i64;

    func<
      OGLPAFP(GetQueryBufferObjectui64v),
      void(query_name, buffer_name, query_parameter, intptr_type)>
      get_query_buffer_object_ui64;

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
    query_func<
      mp_list<>,
      mp_list<integer_query, binding_query>,
      mp_list<>,
      int_type,
      OGLPAFP(GetIntegerv)>
      get_integer;

    // get_integer64
    query_func<
      mp_list<>,
      mp_list<integer_query>,
      mp_list<>,
      int64_type,
      OGLPAFP(GetInteger64v)>
      get_integer64;

    // get_float
    query_func<
      mp_list<>,
      mp_list<float_query>,
      mp_list<>,
      float_type,
      OGLPAFP(GetFloatv)>
      get_float;

    // get_double
    query_func<
      mp_list<>,
      mp_list<float_query>,
      mp_list<>,
      double_type,
      OGLPAFP(GetDoublev)>
      get_double;

    // get_string
    struct : func<OGLPAFP(GetString)> {
        using func<OGLPAFP(GetString)>::func;

        constexpr auto operator()(string_query query) const noexcept {
            return this->_cnvchkcall(query).transformed(
              [](auto src) { return reinterpret_cast<const char*>(src); });
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
      , get_shader_i("get_shader_i", traits, *this)
      , get_shader_info_log("get_shader_info_log", traits, *this)
      , attach_shader("attach_shader", traits, *this)
      , detach_shader("detach_shader", traits, *this)
      , link_program("link_program", traits, *this)
      , get_program_i("get_program_i", traits, *this)
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
      , uniform_matrix2fv("uniform_matrix2fv", traits, *this)
      , uniform_matrix3fv("uniform_matrix3fv", traits, *this)
      , uniform_matrix4fv("uniform_matrix4fv", traits, *this)
      , uniform_matrix2x3fv("uniform_matrix2x3fv", traits, *this)
      , uniform_matrix2x4fv("uniform_matrix2x4fv", traits, *this)
      , uniform_matrix3x2fv("uniform_matrix3x2fv", traits, *this)
      , uniform_matrix3x4fv("uniform_matrix3x4fv", traits, *this)
      , uniform_matrix4x2fv("uniform_matrix4x2fv", traits, *this)
      , uniform_matrix4x3fv("uniform_matrix4x3fv", traits, *this)
      , program_uniform1ui("program_uniform1ui", traits, *this)
      , program_uniform2ui("program_uniform2ui", traits, *this)
      , program_uniform3ui("program_uniform3ui", traits, *this)
      , program_uniform4ui("program_uniform4ui", traits, *this)
      , program_uniform1uiv("program_uniform1uiv", traits, *this)
      , program_uniform2uiv("program_uniform2uiv", traits, *this)
      , program_uniform3uiv("program_uniform3uiv", traits, *this)
      , program_uniform4uiv("program_uniform4uiv", traits, *this)
      , program_uniform1i("program_uniform1i", traits, *this)
      , program_uniform2i("program_uniform2i", traits, *this)
      , program_uniform3i("program_uniform3i", traits, *this)
      , program_uniform4i("program_uniform4i", traits, *this)
      , program_uniform1iv("program_uniform1iv", traits, *this)
      , program_uniform2iv("program_uniform2iv", traits, *this)
      , program_uniform3iv("program_uniform3iv", traits, *this)
      , program_uniform4iv("program_uniform4iv", traits, *this)
      , program_uniform1f("program_uniform1f", traits, *this)
      , program_uniform2f("program_uniform2f", traits, *this)
      , program_uniform3f("program_uniform3f", traits, *this)
      , program_uniform4f("program_uniform4f", traits, *this)
      , program_uniform1fv("program_uniform1fv", traits, *this)
      , program_uniform2fv("program_uniform2fv", traits, *this)
      , program_uniform3fv("program_uniform3fv", traits, *this)
      , program_uniform4fv("program_uniform4fv", traits, *this)
      , program_uniform_matrix2fv("program_uniform_matrix2fv", traits, *this)
      , program_uniform_matrix3fv("program_uniform_matrix3fv", traits, *this)
      , program_uniform_matrix4fv("program_uniform_matrix4fv", traits, *this)
      , program_uniform_matrix2x3fv(
          "program_uniform_matrix2x3fv", traits, *this)
      , program_uniform_matrix2x4fv(
          "program_uniform_matrix2x4fv", traits, *this)
      , program_uniform_matrix3x2fv(
          "program_uniform_matrix3x2fv", traits, *this)
      , program_uniform_matrix3x4fv(
          "program_uniform_matrix3x4fv", traits, *this)
      , program_uniform_matrix4x2fv(
          "program_uniform_matrix4x2fv", traits, *this)
      , program_uniform_matrix4x3fv(
          "program_uniform_matrix4x3fv", traits, *this)
      , bind_buffer("bind_buffer", traits, *this)
      , bind_buffer_base("bind_buffer_base", traits, *this)
      , bind_buffer_range("bind_buffer_range", traits, *this)
      , buffer_storage("buffer_storage", traits, *this)
      , named_buffer_storage("named_buffer_storage", traits, *this)
      , buffer_data("buffer_data", traits, *this)
      , named_buffer_data("named_buffer_data", traits, *this)
      , buffer_sub_data("buffer_sub_data", traits, *this)
      , named_buffer_sub_data("named_buffer_sub_data", traits, *this)
      , clear_buffer_data("clear_buffer_data", traits, *this)
      , clear_named_buffer_data("clear_named_buffer_data", traits, *this)
      , clear_buffer_sub_data("clear_buffer_sub_data", traits, *this)
      , clear_named_buffer_sub_data(
          "clear_named_buffer_sub_data", traits, *this)
      , map_buffer("map_buffer", traits, *this)
      , map_named_buffer("map_named_buffer", traits, *this)
      , map_buffer_range("map_buffer_range", traits, *this)
      , map_named_buffer_range("map_named_buffer_range", traits, *this)
      , flush_mapped_buffer_range("flush_mapped_buffer_range", traits, *this)
      , flush_mapped_named_buffer_range(
          "flush_mapped_named_buffer_range", traits, *this)
      , unmap_buffer("unmap_buffer", traits, *this)
      , unmap_named_buffer("unmap_named_buffer", traits, *this)
      , invalidate_buffer_data("invalidate_buffer_data", traits, *this)
      , invalidate_buffer_sub_data("invalidate_buffer_sub_data", traits, *this)
      , copy_buffer_sub_data("copy_buffer_sub_data", traits, *this)
      , copy_named_buffer_sub_data("copy_named_buffer_sub_data", traits, *this)
      , get_buffer_parameter_i("get_buffer_parameter_i", traits, *this)
      , get_named_buffer_parameter_i(
          "get_named_buffer_parameter_i", traits, *this)
      , get_buffer_parameter_i64("get_buffer_parameter_i64", traits, *this)
      , get_named_buffer_parameter_i64(
          "get_named_buffer_parameter_i64", traits, *this)
      , bind_vertex_array("bind_vertex_array", traits, *this)
      , bind_vertex_buffer("bind_vertex_buffer", traits, *this)
      , vertex_array_vertex_buffer("vertex_array_vertex_buffer", traits, *this)
      , vertex_array_element_buffer(
          "vertex_array_element_buffer", traits, *this)
      , enable_vertex_attrib_array("enable_vertex_attrib_array", traits, *this)
      , enable_vertex_array_attrib("enable_vertex_array_attrib", traits, *this)
      , disable_vertex_attrib_array(
          "disable_vertex_attrib_array", traits, *this)
      , disable_vertex_array_attrib(
          "disable_vertex_array_attrib", traits, *this)
      , vertex_attrib_format("vertex_attrib_format", traits, *this)
      , vertex_attrib_iformat("vertex_attrib_iformat", traits, *this)
      , vertex_attrib_lformat("vertex_attrib_lformat", traits, *this)
      , vertex_array_attrib_format("vertex_array_attrib_format", traits, *this)
      , vertex_array_attrib_iformat(
          "vertex_array_attrib_iformat", traits, *this)
      , vertex_array_attrib_lformat(
          "vertex_array_attrib_lformat", traits, *this)
      , vertex_attrib_pointer("vertex_attrib_pointer", traits, *this)
      , vertex_attrib_ipointer("vertex_attrib_ipointer", traits, *this)
      , vertex_attrib_lpointer("vertex_attrib_lpointer", traits, *this)
      , vertex_attrib_binding("vertex_attrib_binding", traits, *this)
      , vertex_array_attrib_binding(
          "vertex_array_attrib_binding", traits, *this)
      , vertex_binding_divisor("vertex_binding_divisor", traits, *this)
      , vertex_array_binding_divisor(
          "vertex_array_binding_divisor", traits, *this)
      , vertex_attrib_divisor("vertex_attrib_divisor", traits, *this)
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
      , compressed_tex_image3d("compressed_tex_image3d", traits, *this)
      , compressed_tex_image2d("compressed_tex_image2d", traits, *this)
      , compressed_tex_image1d("compressed_tex_image1d", traits, *this)
      , compressed_tex_sub_image3d("compressed_tex_sub_image3d", traits, *this)
      , compressed_texture_sub_image3d(
          "compressed_texture_sub_image3d", traits, *this)
      , compressed_tex_sub_image2d("compressed_tex_sub_image2d", traits, *this)
      , compressed_texture_sub_image2d(
          "compressed_texture_sub_image2d", traits, *this)
      , compressed_tex_sub_image1d("compressed_tex_sub_image1d", traits, *this)
      , compressed_texture_sub_image1d(
          "compressed_texture_sub_image1d", traits, *this)
      , tex_buffer("tex_buffer", traits, *this)
      , texture_buffer("texture_buffer", traits, *this)
      , tex_buffer_range("tex_buffer_range", traits, *this)
      , texture_buffer_range("texture_buffer_range", traits, *this)
      , tex_parameter_f("tex_parameter_f", traits, *this)
      , texture_parameter_f("texture_parameter_f", traits, *this)
      , tex_parameter_i("tex_parameter_i", traits, *this)
      , texture_parameter_i("texture_parameter_i", traits, *this)
      , tex_parameter_fv("tex_parameter_fv", traits, *this)
      , texture_parameter_fv("texture_parameter_fv", traits, *this)
      , tex_parameter_iv("tex_parameter_iv", traits, *this)
      , texture_parameter_iv("texture_parameter_iv", traits, *this)
      , tex_parameter_iiv("tex_parameter_iiv", traits, *this)
      , texture_parameter_iiv("texture_parameter_iiv", traits, *this)
      , tex_parameter_iuiv("tex_parameter_iuiv", traits, *this)
      , texture_parameter_iuiv("texture_parameter_iuiv", traits, *this)
      , get_tex_parameter_f("get_tex_parameter_f", traits, *this)
      , get_texture_parameter_f("get_texture_parameter_f", traits, *this)
      , get_tex_parameter_i("get_tex_parameter_i", traits, *this)
      , get_texture_parameter_i("get_texture_parameter_i", traits, *this)
      , get_tex_parameter_ii("get_tex_parameter_ii", traits, *this)
      , get_texture_parameter_ii("get_texture_parameter_ii", traits, *this)
      , get_tex_parameter_iui("get_tex_parameter_iui", traits, *this)
      , get_texture_parameter_iui("get_texture_parameter_iui", traits, *this)
      , generate_mipmap("generate_mipmap", traits, *this)
      , generate_texture_mipmap("generate_texture_mipmap", traits, *this)
      , bind_sampler("bind_sampler", traits, *this)
      , sampler_parameter_f("sampler_parameter_f", traits, *this)
      , sampler_parameter_i("sampler_parameter_i", traits, *this)
      , sampler_parameter_fv("sampler_parameter_fv", traits, *this)
      , sampler_parameter_iv("sampler_parameter_iv", traits, *this)
      , sampler_parameter_iiv("sampler_parameter_iiv", traits, *this)
      , sampler_parameter_iuiv("sampler_parameter_iuiv", traits, *this)
      , get_sampler_parameter_f("get_sampler_parameter_f", traits, *this)
      , get_sampler_parameter_i("get_sampler_parameter_i", traits, *this)
      , get_sampler_parameter_ii("get_sampler_parameter_ii", traits, *this)
      , get_sampler_parameter_iui("get_sampler_parameter_iui", traits, *this)
      , bind_renderbuffer("bind_renderbuffer", traits, *this)
      , renderbuffer_storage("renderbuffer_storage", traits, *this)
      , named_renderbuffer_storage("named_renderbuffer_storage", traits, *this)
      , renderbuffer_storage_multisample(
          "renderbuffer_storage_multisample", traits, *this)
      , named_renderbuffer_storage_multisample(
          "named_renderbuffer_storage_multisample", traits, *this)
      , get_renderbuffer_parameter_i(
          "get_renderbuffer_parameter_i", traits, *this)
      , get_named_renderbuffer_parameter_i(
          "get_named_renderbuffer_parameter_i", traits, *this)
      , bind_framebuffer("bind_framebuffer", traits, *this)
      , draw_buffer("draw_buffer", traits, *this)
      , named_framebuffer_draw_buffer(
          "named_framebuffer_draw_buffer", traits, *this)
      , read_buffer("read_buffer", traits, *this)
      , named_framebuffer_read_buffer(
          "named_framebuffer_read_buffer", traits, *this)
      , framebuffer_parameter_i("framebuffer_parameter_i", traits, *this)
      , named_framebuffer_parameter_i(
          "named_framebuffer_parameter_i", traits, *this)
      , get_framebuffer_parameter_i(
          "get_framebuffer_parameter_i", traits, *this)
      , get_named_framebuffer_parameter_i(
          "get_named_framebuffer_parameter_i", traits, *this)
      , get_framebuffer_attachment_parameter_i(
          "get_framebuffer_attachment_parameter_i", traits, *this)
      , get_named_framebuffer_attachment_parameter_i(
          "get_named_framebuffer_attachment_parameter_i", traits, *this)
      , framebuffer_renderbuffer("framebuffer_renderbuffer", traits, *this)
      , named_framebuffer_renderbuffer(
          "named_framebuffer_renderbuffer", traits, *this)
      , framebuffer_texture("framebuffer_texture", traits, *this)
      , named_framebuffer_texture("named_framebuffer_texture", traits, *this)
      , framebuffer_texture1d("framebuffer_texture1d", traits, *this)
      , framebuffer_texture2d("framebuffer_texture2d", traits, *this)
      , framebuffer_texture3d("framebuffer_texture3d", traits, *this)
      , framebuffer_texture_layer("framebuffer_texture_layer", traits, *this)
      , named_framebuffer_texture_layer(
          "named_framebuffer_texture_layer", traits, *this)
      , check_framebuffer_status("check_framebuffer_status", traits, *this)
      , check_named_framebuffer_status(
          "check_named_framebuffer_status", traits, *this)
      , blit_framebuffer("blit_framebuffer", traits, *this)
      , blit_named_framebuffer("blit_named_framebuffer", traits, *this)
      , bind_transform_feedback("bind_transform_feedback", traits, *this)
      , begin_transform_feedback("begin_transform_feedback", traits, *this)
      , pause_transform_feedback("pause_transform_feedback", traits, *this)
      , resume_transform_feedback("resume_transform_feedback", traits, *this)
      , end_transform_feedback("end_transform_feedback", traits, *this)
      , transform_feedback_buffer_base(
          "transform_feedback_buffer_base", traits, *this)
      , transform_feedback_buffer_range(
          "transform_feedback_buffer_range", traits, *this)
      , get_transform_feedback_i("get_transform_feedback_i", traits, *this)
      , get_transform_feedback_ii("get_transform_feedback_ii", traits, *this)
      , get_transform_feedback_i64i(
          "get_transform_feedback_i64i", traits, *this)
      , get_query_i("get_query_i", traits, *this)
      , get_query_indexed_i("get_query_indexed_i", traits, *this)
      , get_query_object_i("get_query_object_i", traits, *this)
      , get_query_object_ui("get_query_object_ui", traits, *this)
      , get_query_object_i64("get_query_object_i64", traits, *this)
      , get_query_object_ui64("get_query_object_ui64", traits, *this)
      , get_query_buffer_object_i("get_query_buffer_object_i", traits, *this)
      , get_query_buffer_object_ui("get_query_buffer_object_ui", traits, *this)
      , get_query_buffer_object_i64(
          "get_query_buffer_object_i64", traits, *this)
      , get_query_buffer_object_ui64(
          "get_query_buffer_object_ui64", traits, *this)
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
      , get_double("get_double", traits, *this)
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

