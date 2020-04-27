/**
 *  .file oglplus/example/run_context.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_EXAMPLE_RUN_CONTEXT_HPP
#define OGLPLUS_EXAMPLE_RUN_CONTEXT_HPP

namespace eagine {
//------------------------------------------------------------------------------
class example_args;
class example_params;
class example_state;
//------------------------------------------------------------------------------
struct example_run_context {
    example_args& args;
    example_params& params;
    example_state& state;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_RUN_CONTEXT_HPP

