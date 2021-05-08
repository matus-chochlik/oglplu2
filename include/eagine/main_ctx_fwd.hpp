/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_MAIN_CTX_FWD_HPP
#define EAGINE_MAIN_CTX_FWD_HPP

#include "logging/fwd.hpp"

namespace eagine {

class application_config;
class build_info;
class compiler_info;
class system_info;
class user_info;
class data_compressor;
class process_watchdog;
class main_ctx;
class main_ctx_storage;
class main_ctx_log_backend_getter;
class main_ctx_object;
class main_ctx_object_parent_info;

/// @brief Alias for main_ctx_object_parent_info parameter type.
/// @ingroup main_context
using main_ctx_parent = const main_ctx_object_parent_info&;

/// @brief Helper class used to initialize main context objects.
/// @ingroup main_context
/// @see main_ctx_object
class main_ctx_object_parent_info {
public:
    /// @brief Construction from main_ctx instance.
    main_ctx_object_parent_info(main_ctx&) noexcept {}

    main_ctx_object_parent_info(main_ctx_storage& ctx) noexcept
      : _context{&ctx} {}

    /// @brief Construction from main context object.
    main_ctx_object_parent_info(const main_ctx_object& obj) noexcept
      : _object{&obj} {}

protected:
    main_ctx_object_parent_info() noexcept = default;

private:
    friend class main_ctx_object;

    main_ctx_storage* _context{nullptr};
    const main_ctx_object* _object{nullptr};
};

} // namespace eagine

#endif // EAGINE_MAIN_CTX_FWD_HPP
