/**
 *  @file oglplus/oper/synchronization.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <oglplus/utils/gl_func.hpp>

namespace oglplus {
//------------------------------------------------------------------------------
namespace oper {
//------------------------------------------------------------------------------
#if defined(GL_VERSION_3_2) || defined(GL_ARB_sync)
//------------------------------------------------------------------------------
inline outcome<sync_object>
synchronization::fence_sync(sync_condition cond) noexcept {
    GLsync result = OGLPLUS_GLFUNC(FenceSync)(GLenum(cond), 0);
    OGLPLUS_VERIFY(FenceSync, gl_enum_value(cond), debug);
    return {sync_object(result)};
}
//------------------------------------------------------------------------------
inline outcome<sync_object>
synchronization::fence_sync() noexcept {
    return fence_sync(sync_condition(GL_SYNC_GPU_COMMANDS_COMPLETE));
}
//------------------------------------------------------------------------------
inline outcome<void>
synchronization::delete_sync(sync_object sync) noexcept {
    OGLPLUS_GLFUNC(DeleteSync)(get_raw_handle(sync));
    OGLPLUS_VERIFY_SIMPLE(DeleteSync, debug);
    return {};
}
//------------------------------------------------------------------------------
inline outcome<boolean>
synchronization::is_sync(sync_object sync) noexcept {
    GLboolean result = OGLPLUS_GLFUNC(IsSync)(get_raw_handle(sync));
    OGLPLUS_VERIFY_SIMPLE(IsSync, debug);
    return {boolean(result)};
}
//------------------------------------------------------------------------------
inline outcome<void>
synchronization::get_sync_iv(
  sync_object sync,
  oglplus::sync_parameter param,
  span<GLint> values) noexcept {
    assert(values.size() > 0);
    OGLPLUS_GLFUNC(GetSynciv)
    (get_raw_handle(sync),
     GLenum(param),
     GLsizei(values.size()),
     static_cast<GLsizei*>(nullptr),
     values.data());
    OGLPLUS_VERIFY(GetSynciv, gl_enum_value(param), always);
    return {};
}
//------------------------------------------------------------------------------
template <typename R, typename T>
inline outcome<R>
synchronization::return_sync_i(
  sync_object sync, sync_parameter parameter) noexcept {
    GLint result = 0;
    return get_sync_iv(sync, parameter, {&result, 1}).add(R(T(result)));
}
//------------------------------------------------------------------------------
inline outcome<sync_status>
synchronization::get_sync_status(sync_object sync) noexcept {
    return return_sync_i<sync_status, GLenum>(
      sync, sync_parameter(GL_SYNC_STATUS));
}
//------------------------------------------------------------------------------
inline outcome<boolean>
synchronization::is_sync_signaled(sync_object sync) noexcept {
    GLint result = 0;
    return get_sync_iv(sync, sync_parameter(GL_SYNC_STATUS), {&result, 1})
      .add(boolean(result == GL_SIGNALED));
}
//------------------------------------------------------------------------------
inline outcome<void>
synchronization::wait_sync(sync_object sync) noexcept {
    OGLPLUS_GLFUNC(WaitSync)(get_raw_handle(sync), 0, GL_TIMEOUT_IGNORED);
    OGLPLUS_VERIFY_SIMPLE(WaitSync, debug);
    return {};
}
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
} // namespace oper
//------------------------------------------------------------------------------
} // namespace oglplus
