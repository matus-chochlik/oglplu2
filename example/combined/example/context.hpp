/**
 *  .file oglplus/example/context.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_CONTEXT_HPP
#define OGLPLUS_EXAMPLE_CONTEXT_HPP

#include "args.hpp"
#include "params.hpp"
#include "random.hpp"
#include "run_context.hpp"
#include "state_view.hpp"
#include <eagine/cleanup_group.hpp>
#include <eagine/enum_log.hpp>
#include <eagine/logging/logger.hpp>
#include <eagine/main_ctx.hpp>
#include <eagine/memory/buffer.hpp>
#include <oglplus/gl_api_fwd.hpp>
#include <memory>

namespace eagine {
//------------------------------------------------------------------------------
class example_requirement_marker {
public:
    template <typename X>
    auto operator()(const X& x) const noexcept {
        // TODO
        return bool(x);
    }
};
//------------------------------------------------------------------------------
class example_context {
public:
    example_context(example_run_context&);
    ~example_context() noexcept;

    auto log() noexcept -> auto& {
        return _log;
    }

    auto main() noexcept -> auto& {
        return _erc.main;
    }

    auto buffer() noexcept -> auto& {
        return main().scratch_space();
    }

    auto cleanup() noexcept -> auto& {
        return _cleanup;
    }

    auto state() noexcept -> auto& {
        return _erc.state;
    }

    auto random() noexcept -> auto& {
        EAGINE_ASSERT(_random);
        return *_random;
    }

    auto state() const noexcept -> const example_state_view&;

    auto params() const noexcept -> const example_params& {
        return _erc.params;
    }

    auto req_mark() const -> example_requirement_marker {
        return {};
    }

    auto gl() const noexcept -> oglp::gl_api&;

private:
    logger _log;
    cleanup_group _cleanup{};
    example_run_context& _erc;
    std::shared_ptr<example_random_generator> _random{};
    std::shared_ptr<oglp::gl_api> _gl_ptr{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_CONTEXT_HPP
