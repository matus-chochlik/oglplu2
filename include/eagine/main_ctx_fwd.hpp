/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MAIN_CTX_FWD_HPP
#define EAGINE_MAIN_CTX_FWD_HPP

#include "identifier_t.hpp"
#include "interface.hpp"
#include "logging/fwd.hpp"
#include "memory/buffer_fwd.hpp"
#include "string_span.hpp"

namespace eagine {

class application_config;
class build_info;
class compiler_info;
class system_info;
class user_info;
class data_compressor;
class program_args;
class process_watchdog;
class message_bus;
class main_ctx;
class main_ctx_storage;
class main_ctx_log_backend_getter;
class main_ctx_object;
class main_ctx_object_parent_info;

/// @brief Alias for main_ctx_object_parent_info parameter type.
/// @ingroup main_context
using main_ctx_parent = const main_ctx_object_parent_info&;

/// @brief Interface for classes providing access to some singletons.
/// @ingroup main_context
/// @see main_ctx
struct main_ctx_getters : interface<main_ctx_getters> {

    /// @brief Does potentially expensive initialization and caching.
    virtual auto preinitialize() noexcept -> main_ctx_getters& = 0;

    /// @brief Returns this process instance id. Not equal to system PID.
    virtual auto instance_id() const noexcept -> process_instance_id_t = 0;

    /// @brief Returns the executable path.
    virtual auto exe_path() const noexcept -> string_view = 0;

    /// @brief Returns the application name.
    virtual auto app_name() const noexcept -> string_view = 0;

    /// @brief Returns a reference to program arguments wrapper.
    virtual auto args() const noexcept -> const program_args& = 0;

    /// @brief Returns a reference to compiler information instance.
    /// @see build
    virtual auto compiler() const noexcept -> const compiler_info& = 0;

    /// @brief Returns a reference to build information instance.
    /// @see compiler
    virtual auto build() const noexcept -> const build_info& = 0;

    /// @brief Returns a reference to system information object.
    /// @see user
    virtual auto system() noexcept -> system_info& = 0;

    /// @brief Returns a reference to user information object.
    /// @see system
    virtual auto user() noexcept -> user_info& = 0;

    /// @brief Returns a reference to the root logger object.
    virtual auto log() noexcept -> logger& = 0;

    /// @brief Returns a reference to application config object.
    virtual auto config() noexcept -> application_config& = 0;

    /// @brief Returns a reference to process watchdog object.
    virtual auto watchdog() noexcept -> process_watchdog& = 0;

    /// @brief Returns a reference to message bus facade object.
    virtual auto msg_bus() noexcept -> message_bus& = 0;

    /// @brief Returns a reference to shared data compressor object.
    virtual auto compressor() noexcept -> data_compressor& = 0;

    /// @brief Returns a reference to shared temporary buffer.
    virtual auto scratch_space() noexcept -> memory::buffer& = 0;
};

/// @brief Helper class used to initialize main context objects.
/// @ingroup main_context
/// @see main_ctx_object
class main_ctx_object_parent_info {
public:
    /// @brief Construction from main_ctx instance.
    main_ctx_object_parent_info(main_ctx_getters& ctx) noexcept
      : _context{&ctx} {}

    /// @brief Construction from main context object.
    main_ctx_object_parent_info(const main_ctx_object& obj) noexcept
      : _object{&obj} {}

protected:
    main_ctx_object_parent_info() noexcept = default;

private:
    friend class main_ctx_object;

    main_ctx_getters* _context{nullptr};
    const main_ctx_object* _object{nullptr};
};

} // namespace eagine

#endif // EAGINE_MAIN_CTX_FWD_HPP
