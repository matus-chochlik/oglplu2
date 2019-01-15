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

namespace oglplus {

class debug_output;

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

    const example_context& debug_notification(string_view message) const;

private:
    example_params& _params;
    example_state& _state;
    std::shared_ptr<debug_output> _debug;
};

} // namespace oglplus

#endif // OGLPLUS_EXAMPLE_CONTEXT_HPP
