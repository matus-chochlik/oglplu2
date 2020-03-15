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

#include "c_api.hpp"
#include "enum_types.hpp"
#include "object_name.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

namespace eagine {
namespace oglp {
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
    using bool_type = typename gl_types::bool_type;
    using char_type = typename gl_types::char_type;
    using enum_type = typename gl_types::enum_type;
    using float_type = typename gl_types::float_type;
    using double_type = typename gl_types::double_type;
    using bitfield_type = typename gl_types::bitfield_type;

    using name_type = typename gl_types::name_type;

    struct derived_func : derived_c_api_function<c_api, api_traits, nothing_t> {
        using base = derived_c_api_function<c_api, api_traits, nothing_t>;
        using base::base;

        template <typename Res>
        constexpr auto _check(Res&& res) const noexcept {
            res.error_code(this->api().GetError());
            return std::forward<Res>(res);
        }
    };

    // generate / create objects
    template <typename ObjTag, typename W, W c_api::*GenObjects>
    struct make_object_func : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().*GenObjects);
        }

        constexpr auto operator()(span<name_type> names) const noexcept {
            return this->_check(this->call(
              this->api().*GenObjects, sizei_type(names.size()), names.data()));
        }

        constexpr auto operator()() const noexcept {
            name_type n{};
            return this->_check(this->call(this->api().*GenObjects, 1, &n))
              .transformed([&n]() { return gl_owned_object_name<ObjTag>(n); });
        }
    };

    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().CreateShader);
        }

        constexpr auto operator()(shader_type type) const noexcept {
            return this
              ->_check(this->call(this->api().CreateShader, enum_type(type)))
              .transformed([](name_type n) { return owned_shader_name(n); });
        }
    } create_shader;

    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().CreateProgram);
        }

        constexpr auto operator()() const noexcept {
            return this->_check(this->call(this->api().CreateProgram))
              .transformed([](name_type n) { return owned_program_name(n); });
        }
    } create_program;

    make_object_func<
      buffer_tag,
      decltype(c_api::GenBuffers),
      &c_api::GenBuffers>
      gen_buffers;

    make_object_func<
      buffer_tag,
      decltype(c_api::CreateBuffers),
      &c_api::CreateBuffers>
      create_buffers;

    make_object_func<
      framebuffer_tag,
      decltype(c_api::GenFramebuffers),
      &c_api::GenFramebuffers>
      gen_framebuffers;

    make_object_func<
      framebuffer_tag,
      decltype(c_api::CreateFramebuffers),
      &c_api::CreateFramebuffers>
      create_framebuffers;

    make_object_func<
      program_pipeline_tag,
      decltype(c_api::GenProgramPipelines),
      &c_api::GenProgramPipelines>
      gen_program_pipelines;

    make_object_func<
      program_pipeline_tag,
      decltype(c_api::CreateProgramPipelines),
      &c_api::CreateProgramPipelines>
      create_program_pipelines;

    make_object_func<query_tag, decltype(c_api::GenQueries), &c_api::GenQueries>
      gen_queries;

    make_object_func<
      query_tag,
      decltype(c_api::CreateQueries),
      &c_api::CreateQueries>
      create_queries;

    make_object_func<
      renderbuffer_tag,
      decltype(c_api::GenRenderbuffers),
      &c_api::GenRenderbuffers>
      gen_renderbuffers;

    make_object_func<
      renderbuffer_tag,
      decltype(c_api::CreateRenderbuffers),
      &c_api::CreateRenderbuffers>
      create_renderbuffers;

    make_object_func<
      sampler_tag,
      decltype(c_api::GenSamplers),
      &c_api::GenSamplers>
      gen_samplers;

    make_object_func<
      sampler_tag,
      decltype(c_api::CreateSamplers),
      &c_api::CreateSamplers>
      create_samplers;

    make_object_func<
      texture_tag,
      decltype(c_api::GenTextures),
      &c_api::GenTextures>
      gen_textures;

    make_object_func<
      texture_tag,
      decltype(c_api::CreateTextures),
      &c_api::CreateTextures>
      create_textures;

    make_object_func<
      transform_feedback_tag,
      decltype(c_api::GenTransformFeedbacks),
      &c_api::GenTransformFeedbacks>
      gen_transform_feedbacks;

    make_object_func<
      transform_feedback_tag,
      decltype(c_api::CreateTransformFeedbacks),
      &c_api::CreateTransformFeedbacks>
      create_transform_feedbacks;

    make_object_func<
      vertex_array_tag,
      decltype(c_api::GenVertexArrays),
      &c_api::GenVertexArrays>
      gen_vertex_arrays;

    make_object_func<
      vertex_array_tag,
      decltype(c_api::CreateVertexArrays),
      &c_api::CreateVertexArrays>
      create_vertex_arrays;

    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GenPathsNV);
        }

        constexpr auto operator()() const noexcept {
            return this->_check(this->call(this->api().GenPathsNV, 1))
              .transformed([](name_type n) { return owned_path_nv_name(n); });
        }
    } create_paths_nv;

    // delete objects
    template <typename ObjTag, typename W, W c_api::*DeleteObjects>
    struct delete_object_func : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().*DeleteObjects);
        }

        constexpr auto operator()(span<const name_type> names) const noexcept {
            return this->_check(this->call(
              this->api().*DeleteObjects,
              sizei_type(names.size()),
              names.data()));
        }

        constexpr auto operator()(gl_owned_object_name<ObjTag>& name) const
          noexcept {
            auto n = name.release();
            return this->_check(this->call(this->api().*DeleteObjects, 1, &n));
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

    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().DeleteShader);
        }

        constexpr auto operator()(owned_shader_name name) const noexcept {
            return this->_check(
              this->call(this->api().DeleteShader, name.release()));
        }

        auto raii(owned_shader_name& name) noexcept {
            return eagine::finally([this, &name]() { (*this)(name); });
        }
    } delete_shader;

    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().DeleteProgram);
        }

        constexpr auto operator()(owned_program_name name) const noexcept {
            return this->_check(
              this->call(this->api().DeleteProgram, name.release()));
        }

        auto raii(owned_program_name& name) noexcept {
            return eagine::finally([this, &name]() { (*this)(name); });
        }
    } delete_program;

    delete_object_func<
      buffer_tag,
      decltype(c_api::DeleteBuffers),
      &c_api::DeleteBuffers>
      delete_buffers;

    delete_object_func<
      framebuffer_tag,
      decltype(c_api::DeleteFramebuffers),
      &c_api::DeleteFramebuffers>
      delete_framebuffers;

    delete_object_func<
      program_pipeline_tag,
      decltype(c_api::DeleteProgramPipelines),
      &c_api::DeleteProgramPipelines>
      delete_program_pipelines;

    delete_object_func<
      query_tag,
      decltype(c_api::DeleteQueries),
      &c_api::DeleteQueries>
      delete_queries;

    delete_object_func<
      renderbuffer_tag,
      decltype(c_api::DeleteRenderbuffers),
      &c_api::DeleteRenderbuffers>
      delete_renderbuffers;

    delete_object_func<
      sampler_tag,
      decltype(c_api::DeleteSamplers),
      &c_api::DeleteSamplers>
      delete_samplers;

    delete_object_func<
      texture_tag,
      decltype(c_api::DeleteTextures),
      &c_api::DeleteTextures>
      delete_textures;

    delete_object_func<
      transform_feedback_tag,
      decltype(c_api::DeleteTransformFeedbacks),
      &c_api::DeleteTransformFeedbacks>
      delete_transform_feedbacks;

    delete_object_func<
      vertex_array_tag,
      decltype(c_api::DeleteVertexArrays),
      &c_api::DeleteVertexArrays>
      delete_vertex_arrays;

    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().DeletePathsNV);
        }

        constexpr auto operator()(owned_path_nv_name name) const noexcept {
            return this->_check(
              this->call(this->api().DeletePathsNV, name.release(), 1));
        }

        auto raii(owned_path_nv_name& name) noexcept {
            return eagine::finally([this, &name]() { (*this)(name); });
        }
    } delete_paths_nv;

    // is_object
    template <typename ObjTag, typename W, W c_api::*IsObject>
    struct is_object_func : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().*IsObject);
        }

        constexpr bool operator()(gl_object_name<ObjTag> name) const noexcept {
            return this
              ->_check(this->call(this->api().*IsObject, name_type(name)))
              .transformed([](bool_type b) { return b == GL_TRUE; });
        }
    };

    is_object_func<buffer_tag, decltype(c_api::IsBuffer), &c_api::IsBuffer>
      is_buffer;

    is_object_func<
      framebuffer_tag,
      decltype(c_api::IsFramebuffer),
      &c_api::IsFramebuffer>
      is_framebuffer;

    is_object_func<
      program_pipeline_tag,
      decltype(c_api::IsProgramPipeline),
      &c_api::IsProgramPipeline>
      is_program_pipeline;

    is_object_func<program_tag, decltype(c_api::IsProgram), &c_api::IsProgram>
      is_program;

    is_object_func<query_tag, decltype(c_api::IsQuery), &c_api::IsQuery>
      is_query;

    is_object_func<
      renderbuffer_tag,
      decltype(c_api::IsRenderbuffer),
      &c_api::IsRenderbuffer>
      is_renderbuffer;

    is_object_func<sampler_tag, decltype(c_api::IsSampler), &c_api::IsSampler>
      is_sampler;

    is_object_func<shader_tag, decltype(c_api::IsShader), &c_api::IsShader>
      is_shader;

    is_object_func<texture_tag, decltype(c_api::IsTexture), &c_api::IsTexture>
      is_texture;

    is_object_func<
      transform_feedback_tag,
      decltype(c_api::IsTransformFeedback),
      &c_api::IsTransformFeedback>
      is_transform_feedback;

    is_object_func<
      vertex_array_tag,
      decltype(c_api::IsVertexArray),
      &c_api::IsVertexArray>
      is_vertex_array;

    is_object_func<path_nv_tag, decltype(c_api::IsPathNV), &c_api::IsPathNV>
      is_path_nv;

    // viewport
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Viewport);
        }

        constexpr auto operator()(
          int_type x, int_type y, sizei_type w, sizei_type h) const noexcept {
            return this->_check(this->call(this->api().Viewport, x, y, w, h));
        }

        constexpr auto operator()(sizei_type w, sizei_type h) const noexcept {
            return this->_check(this->call(this->api().Viewport, 0, 0, w, h));
        }
    } viewport;

    // clear_color
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().ClearColor);
        }

        constexpr auto operator()(
          float_type r, float_type g, float_type b, float_type a) const
          noexcept {
            return this->_check(this->call(this->api().ClearColor, r, g, b, a));
        }
    } clear_color;

    // clear_depth
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().ClearDepthf) ||
                   bool(this->api().ClearDepth);
        }

        constexpr auto operator()(float_type d) const noexcept {
            if(EAGINE_LIKELY(this->api().ClearDepthf)) {
                return this->_check(this->call(this->api().ClearDepthf, d));
            }
            return this->_check(
              this->call(this->api().ClearDepth, double_type(d)));
        }

        constexpr auto operator()(double_type d) const noexcept {
            return this->_check(this->call(this->api().ClearDepth, d));
        }
    } clear_depth;

    // clear_stencil
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().ClearStencil);
        }

        constexpr auto operator()(int_type s) const noexcept {
            return this->_check(this->call(this->api().ClearStencil, s));
        }
    } clear_stencil;

    // clear
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Clear);
        }

        constexpr auto operator()(enum_bitfield<buffer_clear_bit> mask) const
          noexcept {
            return this->_check(
              this->call(this->api().Clear, bitfield_type(mask)));
        }
    } clear;

    // get_integer
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetIntegerv);
        }

        constexpr auto operator()(integer_query query) const noexcept {
            int_type result{};
            return this
              ->_check(
                this->call(this->api().GetIntegerv, enum_type(query), &result))
              .transformed([&result]() { return result; });
        }

        constexpr auto operator()(
          integer_query query, span<int_type> dest) const noexcept {
            return this->_check(this->call(
              this->api().GetIntegerv, enum_type(query), dest.data()));
        }
    } get_integer;

    // get_float
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetFloatv);
        }

        constexpr auto operator()(float_query query) const noexcept {
            float_type result{};
            return this
              ->_check(
                this->call(this->api().GetFloatv, enum_type(query), &result))
              .transformed([&result]() { return result; });
        }

        constexpr auto operator()(
          float_query query, span<float_type> dest) const noexcept {
            return this->_check(
              this->call(this->api().GetFloatv, enum_type(query), dest.data()));
        }
    } get_float;

    // get_string
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetString);
        }

        constexpr auto operator()(string_query query) const noexcept {
            return this
              ->_check(this->call(this->api().GetString, enum_type(query)))
              .transformed(
                [](auto src) { return reinterpret_cast<const char*>(src); });
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
      , viewport("viewport", traits, *this)
      , clear_color("clear_color", traits, *this)
      , clear_depth("clear_depth", traits, *this)
      , clear_stencil("clear_stencil", traits, *this)
      , clear("clear", traits, *this)
      , get_integer("get_integer", traits, *this)
      , get_float("get_float", traits, *this)
      , get_string("get_string", traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_API_HPP

