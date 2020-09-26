/**
 *  .file oglplus/example.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_OGLPLUS_EXAMPLE_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_OGLPLUS_EXAMPLE_HPP

#include "example/context.hpp"
#include "example/state.hpp"
#include <eagine/embed.hpp>
#include <memory>

namespace eagine {
//------------------------------------------------------------------------------
struct example {
    example() noexcept = default;
    example(example&&) noexcept = default;
    example(const example&) = default;
    auto operator=(example&&) = delete;
    auto operator=(const example&) = delete;
    virtual ~example() = default;

    virtual auto check_requirements(const example_context& ctx) -> bool = 0;

    virtual void init(example_context&) {}

    virtual auto default_timeout() -> seconds_t<float> {
        return seconds_(10);
    }

    virtual auto continue_running(const example_context& ctx) -> bool {
        return ctx.state().user_idle_time() < default_timeout();
    }

    virtual void user_idle(const example_context&) {}

    virtual void pointer_motion(const example_context&) {}

    virtual void pointer_scrolling(const example_context&) {}

    virtual void resize(const example_context&) {}

    virtual void render(const example_context&) = 0;

    virtual void cleanup(example_context& ctx) {
        ctx.cleanup().clear();
    }
};
//------------------------------------------------------------------------------
extern auto make_example(const example_args&, const example_context&)
  -> std::unique_ptr<example>;
//------------------------------------------------------------------------------
extern auto is_example_param(const example_arg&) -> bool;
//------------------------------------------------------------------------------
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_OGLPLUS_EXAMPLE_HPP
