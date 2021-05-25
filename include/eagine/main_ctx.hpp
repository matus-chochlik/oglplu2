/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MAIN_CTX_HPP
#define EAGINE_MAIN_CTX_HPP

#include "identifier.hpp"
#include "logging/root_logger_opts.hpp"
#include "main_ctx_fwd.hpp"
#include "program_args.hpp"

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

/// @brief Class for a single-instance object providing useful information ans services.
/// @ingroup main_context
///
/// A single instance of this class is initialized in the main function
/// and constructs several useful utility service objects that can be shared
/// throughout the system.
class main_ctx : public main_ctx_getters {
public:
    main_ctx(main_ctx_getters&) noexcept;

    /// @brief Not move constructible.
    main_ctx(main_ctx&&) = delete;

    /// @brief Not copy constructible.
    main_ctx(const main_ctx&) = delete;

    /// @brief Not move assignable.
    auto operator=(main_ctx&&) = delete;

    /// @brief Not copy asignable.
    auto operator=(const main_ctx&) = delete;

    ~main_ctx() noexcept override;

    /// @brief Returns the single instance.
    static inline auto get() noexcept -> main_ctx& {
        EAGINE_ASSERT(_single_ptr());
        return *_single_ptr();
    }

    auto preinitialize() noexcept -> main_ctx& final;

    auto instance_id() const noexcept -> process_instance_id_t final {
        return _instance_id;
    }

    auto exe_path() const noexcept -> string_view final {
        return _exe_path;
    }

    auto app_name() const noexcept -> string_view final {
        return _app_name;
    }

    auto args() const noexcept -> const program_args& final {
        return _args;
    }

    auto compiler() const noexcept -> const compiler_info& final {
        return _cmplr_info;
    }

    auto build() const noexcept -> const build_info& final {
        return _bld_info;
    }

    auto system() noexcept -> system_info& final {
        return _sys_info;
    }

    auto user() noexcept -> user_info& final {
        return _usr_info;
    }

    auto log() noexcept -> logger& final {
        return _log;
    }

    auto config() noexcept -> application_config& final {
        return _app_config;
    }

    auto watchdog() noexcept -> process_watchdog& final {
        return _watchdog;
    }

    auto bus() noexcept -> message_bus& final {
        return _msg_bus;
    }

    auto compressor() noexcept -> data_compressor& final {
        return _compressor;
    }

    auto scratch_space() noexcept -> memory::buffer& final {
        return _scratch_space;
    }

private:
    const process_instance_id_t _instance_id;
    main_ctx_getters& _source;
    const program_args& _args;
    const compiler_info& _cmplr_info;
    const build_info& _bld_info;
    logger& _log;
    process_watchdog& _watchdog;
    application_config& _app_config;
    system_info& _sys_info;
    user_info& _usr_info;
    message_bus& _msg_bus;
    memory::buffer& _scratch_space;
    data_compressor& _compressor;
    string_view _exe_path;
    string_view _app_name;

    static auto _single_ptr() noexcept -> main_ctx*&;
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/main_ctx.inl>
#endif

#endif // EAGINE_MAIN_CTX_HPP
