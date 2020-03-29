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
#include "state_view.hpp"
#include <eagine/cleanup_group.hpp>
#include <eagine/memory/c_realloc.hpp>
#include <memory>

namespace eagine {
//------------------------------------------------------------------------------
namespace oglp {
class gl_api;
} // namespace oglp
//------------------------------------------------------------------------------
using example_cleanup_group = basic_cleanup_group<
  memory::c_byte_reallocator<memory::byte_alloc_managed_policy>>;
//------------------------------------------------------------------------------
class example_requirement_marker {
public:
    template <typename X>
    bool operator()(const X& x) const noexcept {
        // TODO
        return bool(x);
    }
};
//------------------------------------------------------------------------------
class example_context {
public:
    example_context(example_args&, example_params&, example_state&);
    ~example_context() noexcept;

    example_cleanup_group& cleanup() noexcept {
        return _cleanup;
    }

    example_state& state() noexcept {
        return _state;
    }

    example_random_generator& random() noexcept {
        EAGINE_ASSERT(_random);
        return *_random;
    }

    const example_state_view& state() const noexcept;

    const example_params& params() const noexcept {
        return _params;
    }

    example_requirement_marker req_mark() const {
        return {};
    }

    oglp::gl_api& gl() const noexcept;

    const example_context& debug_notification(string_view message) const;

private:
    example_cleanup_group _cleanup{};
    example_params& _params;
    example_state& _state;
    std::shared_ptr<example_random_generator> _random{};
    std::shared_ptr<oglp::gl_api> _gl_ptr{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_CONTEXT_HPP
