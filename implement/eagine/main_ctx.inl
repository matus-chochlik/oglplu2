/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/main_ctx_storage.hpp>

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_ctx::_single_ptr() noexcept -> main_ctx*& {
    static main_ctx* the_ptr{nullptr};
    return the_ptr;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
main_ctx::main_ctx(main_ctx_storage& storage) noexcept
  : _instance_id{storage.instance_id()}
  , _args{storage.args()}
  , _log{storage.log()}
  , _watchdog{storage.watchdog()}
  , _app_config{storage.config()}
  , _cmplr_info{storage.compiler()}
  , _bld_info{storage.build()}
  , _sys_info{storage.system()}
  , _usr_info{storage.user()}
  , _scratch_space{storage.scratch_space()}
  , _compressor{storage.compressor()}
  , _exe_path{storage.exe_path()}
  , _app_name{storage.app_name()} {
    EAGINE_ASSERT(!_single_ptr());
    _single_ptr() = this;
    _log.configure(_app_config);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
main_ctx::~main_ctx() noexcept {
    EAGINE_ASSERT(_single_ptr());
    _single_ptr() = nullptr;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_ctx::preinitialize() noexcept -> main_ctx& {
    _sys_info.preinitialize();
    return *this;
}
//------------------------------------------------------------------------------
// main_ctx_object-related
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
main_ctx_log_backend_getter::main_ctx_log_backend_getter(
  main_ctx_storage& c) noexcept
  : _backend{c.log().backend()} {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
main_ctx_log_backend_getter::main_ctx_log_backend_getter() noexcept
  : _backend{main_ctx::get().log().backend()} {}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_ctx_object::main_context() const noexcept -> main_ctx& {
    return main_ctx::get();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_ctx_object::process_instance_id() const noexcept
  -> process_instance_id_t {
    return main_context().instance_id();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto main_ctx_object::app_config() const noexcept -> application_config& {
    return main_context().config();
}
//------------------------------------------------------------------------------
} // namespace eagine
