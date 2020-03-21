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
#include "state_view.hpp"
#include <memory>

namespace eagine {
namespace oglp {

class gl_api;

class example_requirement_marker {
public:
    template <typename X>
    bool operator()(const X& x) const noexcept {
        // TODO
        return bool(x);
    }
};

class example_context {
public:
    example_context(example_args&, example_params&, example_state&);
    ~example_context() noexcept;

    example_state& state() noexcept {
        return _state;
    }

    const example_state_view& state() const noexcept;

    const example_params& params() const noexcept {
        return _params;
    }

    example_requirement_marker req_mark() const {
        return {};
    }

    gl_api& gl() const noexcept;

    const example_context& debug_notification(string_view message) const;

private:
    example_params& _params;
    example_state& _state;
    std::shared_ptr<gl_api> _gl_ptr{};
};

} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_CONTEXT_HPP
