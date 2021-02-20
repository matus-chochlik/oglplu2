/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MAIN_CTX_HPP
#define EAGINE_MAIN_CTX_HPP

#include "build_info.hpp"
#include "identifier_t.hpp"
#include "logging/logger.hpp"
#include "logging/root_logger_opts.hpp"
#include "memory/buffer_fwd.hpp"
#include "program_args.hpp"
#include "system_info.hpp"
#include "user_info.hpp"

namespace eagine {

/// @brief Structure storing customization options for main context.
/// @ingroup main_context
struct main_ctx_options {

    /// @brief The application name. Defaults to the executable name.
    std::string app_name{};

    /// @brief The application root logger identifier.
    identifier app_id{"RootLogger"};

    /// @brief Options for the root logger.
    root_logger_options logger_opts{};
};

class data_compressor;
class process_watchdog;

/// @brief Class for a single-instance object providing useful information ans services.
/// @ingroup main_context
///
/// A single instance of this class is initialized in the main function
/// and constructs several useful utility service objects that can be shared
/// throughout the system.
class main_ctx {
public:
    main_ctx(master_ctx&) noexcept;

    /// @brief Not move constructible.
    main_ctx(main_ctx&&) = delete;

    /// @brief Not copy constructible.
    main_ctx(const main_ctx&) = delete;

    /// @brief Not move assignable.
    auto operator=(main_ctx&&) = delete;

    /// @brief Not copy asignable.
    auto operator=(const main_ctx&) = delete;

    ~main_ctx() noexcept;

    /// @brief Returns the single instance.
    static inline auto get() noexcept -> main_ctx& {
        EAGINE_ASSERT(_single_ptr());
        return *_single_ptr();
    }

    /// @brief Returns this process instance id. Not equal to system PID.
    auto instance_id() const noexcept -> process_instance_id_t {
        return _instance_id;
    }

    /// @brief Does potentially expensive initialization and caching.
    auto preinitialize() noexcept -> main_ctx&;

    /// @brief Returns a reference to build information instance.
    auto build() const noexcept -> const build_info& {
        return _bld_info;
    }

    /// @brief Returns a reference to program arguments wrapper.
    auto args() noexcept -> program_args& {
        return _args;
    }

    /// @brief Returns a reference to the root logger object.
    auto log() noexcept -> logger& {
        return _log;
    }

    /// @brief Returns a reference to process watchdog object.
    auto watchdog() noexcept -> process_watchdog& {
        return _watchdog;
    }

    /// @brief Returns a reference to application config object.
    auto config() noexcept -> application_config& {
        return _app_config;
    }

    /// @brief Returns a reference to system information object.
    auto system() noexcept -> system_info& {
        return _sys_info;
    }

    /// @brief Returns a reference to user information object.
    auto user() noexcept -> user_info& {
        return _usr_info;
    }

    /// @brief Returns a reference to shared temporary buffer.
    auto scratch_space() noexcept -> memory::buffer& {
        return _scratch_space;
    }

    /// @brief Returns a reference to shared data compressor object.
    auto compressor() noexcept -> data_compressor& {
        return _compressor;
    }

    /// @brief Returns the executable path.
    auto exe_path() const noexcept -> string_view {
        return _exe_path;
    }

    /// @brief Returns the application name.
    auto app_name() const noexcept -> string_view {
        return _app_name;
    }

private:
    process_instance_id_t _instance_id{};
    program_args& _args;
    logger& _log;
    process_watchdog& _watchdog;
    application_config& _app_config;
    build_info& _bld_info;
    system_info& _sys_info;
    user_info& _usr_info;
    memory::buffer& _scratch_space;
    data_compressor& _compressor;
    string_view _exe_path;
    string_view _app_name;

    static auto _single_ptr() noexcept -> main_ctx*&;
};

#if !EAGINE_IMPLEMENTING_LIBRARY
extern auto main_impl(int, const char**, const main_ctx_options&) -> int;
#endif

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/main_ctx.inl>
#endif

#endif // EAGINE_MAIN_CTX_HPP
