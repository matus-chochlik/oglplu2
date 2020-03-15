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

    // gen objects
    template <typename ObjTag, typename W, W c_api::*GenObjects>
    struct gen_object_func : derived_func {
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

    gen_object_func<buffer_tag, decltype(c_api::GenBuffers), &c_api::GenBuffers>
      gen_buffers;

    gen_object_func<
      framebuffer_tag,
      decltype(c_api::GenFramebuffers),
      &c_api::GenFramebuffers>
      gen_framebuffers;

    gen_object_func<
      program_pipeline_tag,
      decltype(c_api::GenProgramPipelines),
      &c_api::GenProgramPipelines>
      gen_program_pipelines;

    gen_object_func<query_tag, decltype(c_api::GenQueries), &c_api::GenQueries>
      gen_queries;

    gen_object_func<
      renderbuffer_tag,
      decltype(c_api::GenRenderbuffers),
      &c_api::GenRenderbuffers>
      gen_renderbuffers;

    gen_object_func<
      sampler_tag,
      decltype(c_api::GenSamplers),
      &c_api::GenSamplers>
      gen_samplers;

    gen_object_func<
      texture_tag,
      decltype(c_api::GenTextures),
      &c_api::GenTextures>
      gen_textures;

    gen_object_func<
      transform_feedback_tag,
      decltype(c_api::GenTransformFeedbacks),
      &c_api::GenTransformFeedbacks>
      gen_transform_feedbacks;

    gen_object_func<
      vertex_array_tag,
      decltype(c_api::GenVertexArrays),
      &c_api::GenVertexArrays>
      gen_vertex_arrays;

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
      , gen_buffers("gen_buffers", traits, *this)
      , gen_framebuffers("gen_framebuffers", traits, *this)
      , gen_program_pipelines("gen_program_pipelines", traits, *this)
      , gen_queries("gen_queries", traits, *this)
      , gen_renderbuffers("gen_renderbuffers", traits, *this)
      , gen_samplers("gen_samplers", traits, *this)
      , gen_textures("gen_textures", traits, *this)
      , gen_transform_feedbacks("gen_transform_feedbacks", traits, *this)
      , gen_vertex_arrays("gen_vertex_arrays", traits, *this)
      , delete_buffers("delete_buffers", traits, *this)
      , delete_framebuffers("delete_framebuffers", traits, *this)
      , delete_program_pipelines("delete_program_pipelines", traits, *this)
      , delete_queries("delete_queries", traits, *this)
      , delete_renderbuffers("delete_renderbuffers", traits, *this)
      , delete_samplers("delete_samplers", traits, *this)
      , delete_textures("delete_textures", traits, *this)
      , delete_transform_feedbacks("delete_transform_feedbacks", traits, *this)
      , delete_vertex_arrays("delete_vertex_arrays", traits, *this)
      , viewport("viewport", traits, *this)
      , clear_color("clear_color", traits, *this)
      , clear_depth("clear_depth", traits, *this)
      , clear_stencil("clear_stencil", traits, *this)
      , clear("clear", traits, *this)
      , get_string("get_string", traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_API_HPP

