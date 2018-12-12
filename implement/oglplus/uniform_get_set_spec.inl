/**
 *  @file oglplus/uniform_get_set_spec.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <cassert>

namespace oglplus {

template <>
struct prog_var_get_set_ops<tag::uniform, GLuint64> {

#if defined(GL_NV_shader_buffer_load)
    static outcome<void> set(
      identity<GLuint64EXT>, uniform_location u, GLuint64EXT v0) noexcept {
        OGLPLUS_GLFUNC(Uniformui64NV)(u.location(), v0);
        OGLPLUS_VERIFY_SIMPLE(Uniformui64NV, debug);
        return {};
    }

    static outcome<void> set(
      identity<GLuint64EXT>,
      uniform_location u,
      GLsizei count,
      span<const GLuint64EXT> v) noexcept {
        assert(count >= 0);
        assert(v.size() >= span_size_t(count));
        OGLPLUS_GLFUNC(Uniformui64vNV)(u.location(), count, v.data());
        OGLPLUS_VERIFY_SIMPLE(Uniformui64vNV, debug);
        return {};
    }

    template <span_size_t N>
    static outcome<void> set(
      identity<GLuint64EXT[N]>,
      uniform_location u,
      GLsizei count,
      span<const GLuint64EXT> v) noexcept {
        return set(identity<GLuint64EXT>(), u, N * count, v);
    }

#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shader_objects)

    static outcome<void> set(
      identity<GLuint64EXT>,
      program_uniform_location pu,
      GLuint64EXT v0) noexcept {
        OGLPLUS_GLFUNC(ProgramUniformui64NV)
        (get_raw_name(pu.program()), pu.location(), v0);
        OGLPLUS_VERIFY(ProgramUniformui64NV, gl_object(pu.program()), debug);
        return {};
    }

    static outcome<void> set(
      identity<GLuint64EXT>,
      program_uniform_location pu,
      GLsizei count,
      span<const GLuint64EXT> v) noexcept {
        assert(count >= 0);
        assert(v.size() >= span_size_t(count));
        OGLPLUS_GLFUNC(ProgramUniformui64vNV)
        (get_raw_name(pu.program()), pu.location(), count, v.data());
        OGLPLUS_VERIFY(ProgramUniformui64vNV, gl_object(pu.program()), debug);
        return {};
    }

    template <span_size_t N>
    static outcome<void> set(
      identity<GLuint64EXT[N]>,
      program_uniform_location pu,
      GLsizei count,
      span<const GLuint64EXT> v) noexcept {
        return set(identity<GLuint64EXT>(), pu, N * count, v);
    }
#endif

#endif // NV_shader_buffer_load

#if defined(GL_ARB_bindless_texture)
    static outcome<void> set_handle(
      identity<GLuint64>, uniform_location u, GLuint64 v0) noexcept {
        OGLPLUS_GLFUNC(UniformHandleui64ARB)(u.location(), v0);
        OGLPLUS_VERIFY_SIMPLE(UniformHandleui64ARB, debug);
        return {};
    }

    static outcome<void> set_handle(
      identity<GLuint64>,
      uniform_location u,
      GLsizei count,
      span<const GLuint64> v) noexcept {
        assert(count >= 0);
        assert(v.size() >= span_size_t(count));
        OGLPLUS_GLFUNC(UniformHandleui64vNV)(u.location(), count, v.data());
        OGLPLUS_VERIFY_SIMPLE(UniformHandleui64vNV, debug);
        return {};
    }

#if defined(GL_VERSION_4_1) || defined(GL_ARB_separate_shader_objects)
    static outcome<void> set_handle(
      identity<GLuint64>, program_uniform_location pu, GLuint64 v0) noexcept {
        OGLPLUS_GLFUNC(ProgramUniformHandleui64ARB)
        (get_raw_name(pu.program()), pu.location(), v0);
        OGLPLUS_VERIFY_SIMPLE(ProgramUniformHandleui64ARB, debug);
        return {};
    }

    static outcome<void> set_handle(
      identity<GLuint64>,
      program_uniform_location pu,
      GLsizei count,
      span<const GLuint64> v) noexcept {
        assert(count >= 0);
        assert(v.size() >= span_size_t(count));
        OGLPLUS_GLFUNC(ProgramUniformHandleui64vNV)
        (get_raw_name(pu.program()), pu.location(), count, v.data());
        OGLPLUS_VERIFY_SIMPLE(ProgramUniformHandleui64vNV, debug);
        return {};
    }
#endif
#endif // ARB_bindless_texture
};

} // namespace oglplus
