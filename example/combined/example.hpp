/**
 *  .file oglplus/example.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_OGLPLUS_EXAMPLE_HPP
#define OGLPLUS_EXAMPLE_OGLPLUS_EXAMPLE_HPP

#include "example/context.hpp"
#include <memory>

namespace eagine {
//------------------------------------------------------------------------------
struct example {
    virtual ~example() = default;

    virtual bool check_requirements(const example_context& ctx) = 0;

    virtual void init(example_context&) {
    }

    virtual seconds_t<float> default_timeout() {
        return seconds_(10);
    }

    virtual bool continue_running(const example_context& ctx) {
        return ctx.state().user_idle_time() < default_timeout();
    }

    virtual void user_idle(const example_context&) {
    }

    virtual void pointer_motion(const example_context&) {
    }

    virtual void pointer_scrolling(const example_context&) {
    }

    virtual void resize(const example_context&) = 0;

    virtual void render(const example_context&) = 0;

    virtual void cleanup(example_context& ctx) {
        ctx.cleanup().clear();
    }
};
//------------------------------------------------------------------------------
extern std::unique_ptr<example> make_example(
  const example_args&, const example_context&);
//------------------------------------------------------------------------------
extern bool is_example_param(const example_arg&);
//------------------------------------------------------------------------------
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_OGLPLUS_EXAMPLE_HPP
