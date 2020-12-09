/**
 *  @file eagine/application/context.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_APPLICATION_CONTEXT_HPP
#define EAGINE_APPLICATION_CONTEXT_HPP

#include "../assert.hpp"
#include "../main_ctx_object.hpp"
#include "interface.hpp"
#include "options.hpp"

namespace eagine::application {

auto establish(main_ctx&) -> std::unique_ptr<launchpad>;

class execution_context : public main_ctx_object {
public:
    execution_context(main_ctx_parent parent)
      : main_ctx_object(EAGINE_ID(appExecCtx), parent) {}

    auto prepare(std::unique_ptr<launchpad> pad) -> execution_context&;
    auto keep_running() noexcept -> bool;
    auto update() noexcept -> bool;

    auto run() noexcept -> execution_context& {
        while(keep_running()) {
            update();
        }
        return *this;
    }

    auto result() const noexcept {
        return _exec_result;
    }

private:
    int _exec_result{0};
    launch_options _options;
    std::unique_ptr<application> _app;
};

} // namespace eagine::application

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/application/context.inl>
#endif

#endif
