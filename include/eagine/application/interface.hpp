/**
 *  @file eagine/application/interface.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_APPLICATION_INTERFACE_HPP
#define EAGINE_APPLICATION_INTERFACE_HPP

#include "../main_ctx_fwd.hpp"
#include "options.hpp"
#include <memory>

namespace eagine::application {

struct application {
    application() noexcept = default;
    application(application&&) = delete;
    application(const application&) = delete;
    auto operator=(application&&) = delete;
    auto operator=(const application&) = delete;
    virtual ~application() noexcept = default;

    virtual auto is_done() noexcept -> bool = 0;
};

struct launchpad {
    launchpad() noexcept = default;
    launchpad(launchpad&&) = delete;
    launchpad(const launchpad&) = delete;
    auto operator=(launchpad&&) = delete;
    auto operator=(const launchpad&) = delete;
    virtual ~launchpad() noexcept = default;

    virtual auto setup(main_ctx&, launch_options&) -> bool {
        return true;
    }

    virtual auto launch(main_ctx&, const launch_options&)
      -> std::unique_ptr<application> = 0;
};

} // namespace eagine::application

#endif
