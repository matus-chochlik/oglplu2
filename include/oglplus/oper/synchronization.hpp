/**
 *  @file oglplus/oper/synchronization.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_SYNCHRONIZATION_1509260923_HPP
#define OGLPLUS_OPER_SYNCHRONIZATION_1509260923_HPP

#include "../enum/types.hpp"
#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../utils/gl_func.hpp"

namespace oglplus {

#if defined(GL_VERSION_3_2) || defined(GL_ARB_sync)
struct sync_object {
public:
    inline sync_object(void) noexcept
      : _handle{} {
    }

    explicit inline sync_object(GLsync s) noexcept
      : _handle(s) {
    }

    sync_object(const sync_object&) = default;
    sync_object(sync_object&&) = default;

private:
    GLsync _handle;

    friend const GLsync& get_raw_handle(const sync_object& so) noexcept {
        return so._handle;
    }

    friend GLsync& get_raw_handle(sync_object& so) noexcept {
        return so._handle;
    }
};
#endif

namespace oper {

struct synchronization {
#if defined(GL_VERSION_4_5)
    static outcome<void> texture_barrier(void) noexcept {
        OGLPLUS_GLFUNC(TextureBarrier)();
        OGLPLUS_VERIFY_SIMPLE(TextureBarrier, debug);
        return {};
    }
#endif

#if defined(GL_VERSION_4_2) || defined(GL_ARB_shader_image_load_store)
    static outcome<void> memory_barrier(
      enum_bitfield<memory_barrier_bits> bits) noexcept {
        OGLPLUS_GLFUNC(MemoryBarrier)(GLbitfield(bits));
        OGLPLUS_VERIFY_SIMPLE(MemoryBarrier, debug);
        return {};
    }
#endif

#if defined(GL_ES_VERSION_3_1)
    static outcome<void> memory_barrier_by_region(
      enum_bitfield<memory_barrier_bits> bits) noexcept {
        OGLPLUS_GLFUNC(MemoryBarrierByRegion)(GLbitfield(bits));
        OGLPLUS_VERIFY_SIMPLE(MemoryBarrierByRegion, debug);
        return {};
    }
#endif

    static outcome<void> flush(void) noexcept {
        OGLPLUS_GLFUNC(Flush)();
        OGLPLUS_VERIFY_SIMPLE(Flush, debug);
        return {};
    }

    static outcome<void> finish(void) noexcept {
        OGLPLUS_GLFUNC(Finish)();
        OGLPLUS_VERIFY_SIMPLE(Finish, debug);
        return {};
    }

#if defined(GL_VERSION_3_2) || defined(GL_ARB_sync)
    static outcome<sync_object> fence_sync(sync_condition cond) noexcept;

    static outcome<sync_object> fence_sync(void) noexcept;

    static outcome<void> delete_sync(sync_object sync) noexcept;

    static outcome<boolean> is_sync(sync_object sync) noexcept;

    static outcome<void> get_sync_iv(
      sync_object sync,
      oglplus::sync_parameter param,
      span<GLint> values) noexcept;

    template <typename R, typename T>
    static outcome<R> return_sync_i(
      sync_object sync, sync_parameter param) noexcept;

    static outcome<sync_status> get_sync_status(sync_object sync) noexcept;

    static outcome<boolean> is_sync_signaled(sync_object sync) noexcept;

    static outcome<void> wait_sync(sync_object sync) noexcept;
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/synchronization.inl>

#endif // include guard
