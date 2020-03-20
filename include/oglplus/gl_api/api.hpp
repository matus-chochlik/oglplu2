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
#include "c_api.hpp"
#include "enum_types.hpp"
#include "object_name.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

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

    using void_ptr_type = typename gl_types::void_ptr_type;
    using sizei_type = typename gl_types::sizei_type;
    using int_type = typename gl_types::int_type;
    using uint_type = typename gl_types::uint_type;
    using int64_type = typename gl_types::int64_type;
    using bool_type = typename gl_types::bool_type;
    using char_type = typename gl_types::char_type;
    using enum_type = typename gl_types::enum_type;
    using float_type = typename gl_types::float_type;
    using double_type = typename gl_types::double_type;
    using bitfield_type = typename gl_types::bitfield_type;

    using sync_type = typename gl_types::sync_type;
    using name_type = typename gl_types::name_type;

    template <typename W, W c_api::*F>
    class func
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
            return this->_check(this->call(std::forward<Args>(args)...));
        }

    public:
        using base::base;
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

        auto raii(sync_type& sync) noexcept {
            return eagine::finally([this, &sync]() { (*this)(sync); });
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

        auto raii(gl_owned_object_name<ObjTag>& name) noexcept {
            return eagine::finally([this, &name]() { (*this)(name); });
        }

        template <typename Res>
        auto raii_opt(Res& res) noexcept {
            return eagine::finally([this, &res]() {
                if(res) {
                    (*this)(extract(res));
                }
            });
        }
    };

    struct : func<OGLPAFP(DeleteShader)> {
        using func<OGLPAFP(DeleteShader)>::func;

        constexpr auto operator()(owned_shader_name name) const noexcept {
            return this->_chkcall(name.release());
        }

        auto raii(owned_shader_name& name) noexcept {
            return eagine::finally([this, &name]() { (*this)(name); });
        }
    } delete_shader;

    struct : func<OGLPAFP(DeleteProgram)> {
        using func<OGLPAFP(DeleteProgram)>::func;

        constexpr auto operator()(owned_program_name name) const noexcept {
            return this->_chkcall(name.release());
        }

        auto raii(owned_program_name& name) noexcept {
            return eagine::finally([this, &name]() { (*this)(name); });
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
    struct : func<OGLPAFP(IsSync)> {
        using func<OGLPAFP(IsSync)>::func;

        constexpr true_false operator()(sync_type sync) const noexcept {
            return this->_chkcall(sync).cast_to(identity<true_false>{});
        }
    } is_sync;

    template <typename ObjTag, typename W, W c_api::*IsObject>
    struct is_object_func : func<W, IsObject> {
        using func<W, IsObject>::func;

        constexpr true_false operator()(gl_object_name<ObjTag> name) const
          noexcept {
            return this->_chkcall(name_type(name))
              .cast_to(identity<true_false>{});
        }
    };

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
    struct : func<OGLPAFP(Enable)> {
        using func<OGLPAFP(Enable)>::func;

        constexpr auto operator()(capability cap) const noexcept {
            return this->_chkcall(enum_type(cap));
        }
    } enable;

    struct : func<OGLPAFP(Enablei)> {
        using func<OGLPAFP(Enablei)>::func;

        constexpr auto operator()(capability cap, uint_type idx) const
          noexcept {
            return this->_chkcall(enum_type(cap), idx);
        }
    } enablei;

    // disable
    struct : func<OGLPAFP(Disable)> {
        using func<OGLPAFP(Disable)>::func;

        constexpr auto operator()(capability cap) const noexcept {
            return this->_chkcall(enum_type(cap));
        }
    } disable;

    struct : func<OGLPAFP(Disablei)> {
        using func<OGLPAFP(Disablei)>::func;

        constexpr auto operator()(capability cap, uint_type idx) const
          noexcept {
            return this->_chkcall(enum_type(cap), idx);
        }
    } disablei;

    // is_enabled
    struct : func<OGLPAFP(IsEnabled)> {
        using func<OGLPAFP(IsEnabled)>::func;

        constexpr auto operator()(capability cap) const noexcept {
            return this->_chkcall(enum_type(cap))
              .cast_to(identity<true_false>{});
        }
    } is_enabled;

    struct : func<OGLPAFP(IsEnabledi)> {
        using func<OGLPAFP(IsEnabledi)>::func;

        constexpr auto operator()(capability cap, uint_type idx) const
          noexcept {
            return this->_chkcall(enum_type(cap), idx)
              .cast_to(identity<true_false>{});
        }
    } is_enabledi;

    // memory barrier
    struct : func<OGLPAFP(MemoryBarrier)> {
        using func<OGLPAFP(MemoryBarrier)>::func;

        constexpr auto operator()(enum_bitfield<memory_barrier_bit> bits) const
          noexcept {
            return this->_chkcall(bitfield_type(bits));
        }
    } memory_barrier;

    struct : func<OGLPAFP(MemoryBarrierByRegion)> {
        using func<OGLPAFP(MemoryBarrierByRegion)>::func;

        constexpr auto operator()(enum_bitfield<memory_barrier_bit> bits) const
          noexcept {
            return this->_chkcall(bitfield_type(bits));
        }
    } memory_barrier_by_region;

    // viewport
    struct : func<OGLPAFP(Viewport)> {
        using func<OGLPAFP(Viewport)>::func;

        constexpr auto operator()(
          int_type x, int_type y, sizei_type w, sizei_type h) const noexcept {
            return this->_chkcall(x, y, w, h);
        }

        constexpr auto operator()(sizei_type w, sizei_type h) const noexcept {
            return this->_chkcall(0, 0, w, h);
        }
    } viewport;

    // clear_color
    struct : func<OGLPAFP(ClearColor)> {
        using func<OGLPAFP(ClearColor)>::func;

        constexpr auto operator()(
          float_type r, float_type g, float_type b, float_type a) const
          noexcept {
            return this->_chkcall(r, g, b, a);
        }
    } clear_color;

    // clear_depth
    struct : func<OGLPAFP(ClearDepth)> {
        using func<OGLPAFP(ClearDepth)>::func;

        constexpr auto operator()(float_type d) const noexcept {
            return this->_chkcall(d);
        }
    } clear_depth;

    // clear_stencil
    struct : func<OGLPAFP(ClearStencil)> {
        using func<OGLPAFP(ClearStencil)>::func;

        constexpr auto operator()(int_type s) const noexcept {
            return this->_chkcall(s);
        }
    } clear_stencil;

    // clear
    struct : func<OGLPAFP(Clear)> {
        using func<OGLPAFP(Clear)>::func;

        constexpr auto operator()(enum_bitfield<buffer_clear_bit> mask) const
          noexcept {
            return this->_chkcall(bitfield_type(mask));
        }
    } clear;

    // shader_source
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

    // compile_shader
    struct : func<OGLPAFP(CompileShader)> {
        using func<OGLPAFP(CompileShader)>::func;

        constexpr auto operator()(shader_name shdr) const noexcept {
            return this->_chkcall(name_type(shdr));
        }
    } compile_shader;

    // get_shaderi
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

    // attach_shader
    struct : func<OGLPAFP(AttachShader)> {
        using func<OGLPAFP(AttachShader)>::func;

        constexpr auto operator()(program_name prog, shader_name shdr) const
          noexcept {
            return this->_chkcall(name_type(prog), name_type(shdr));
        }
    } attach_shader;

    // detach_shader
    struct : func<OGLPAFP(DetachShader)> {
        using func<OGLPAFP(DetachShader)>::func;

        constexpr auto operator()(program_name prog, shader_name shdr) const
          noexcept {
            return this->_chkcall(name_type(prog), name_type(shdr));
        }
    } detach_shader;

    // link_program
    struct : func<OGLPAFP(LinkProgram)> {
        using func<OGLPAFP(LinkProgram)>::func;

        constexpr auto operator()(program_name prog) const noexcept {
            return this->_chkcall(name_type(prog));
        }
    } link_program;

    // get_programi
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

    // use_program
    struct : func<OGLPAFP(UseProgram)> {
        using func<OGLPAFP(UseProgram)>::func;

        constexpr auto operator()(program_name prog) const noexcept {
            return this->_chkcall(name_type(prog));
        }
    } use_program;

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
            return this->fake(this->api().GetString, "");
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
      , attach_shader("attach_shader", traits, *this)
      , detach_shader("detach_shader", traits, *this)
      , link_program("link_program", traits, *this)
      , get_programi("get_programi", traits, *this)
      , use_program("use_program", traits, *this)
      , get_integer("get_integer", traits, *this)
      , get_integer64("get_integer64", traits, *this)
      , get_float("get_float", traits, *this)
      , get_string("get_string", traits, *this) {
    }
};
//------------------------------------------------------------------------------
#undef OGLPAFP
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_API_HPP

