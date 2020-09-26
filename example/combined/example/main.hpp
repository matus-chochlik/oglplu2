/**
 *  .file oglplus/example/main.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_EXAMPLE_MAIN_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_MAIN_HPP

#include "run_context.hpp"
#include <eagine/string_span.hpp>
#include <oglplus/config/site.hpp>

namespace eagine {
//------------------------------------------------------------------------------
struct example_main_intf {
    virtual ~example_main_intf() noexcept = default;
    example_main_intf() noexcept = default;
    example_main_intf(example_main_intf&&) = delete;
    example_main_intf(const example_main_intf&) = delete;
    auto operator=(example_main_intf&&) = delete;
    auto operator=(const example_main_intf&) = delete;

    virtual auto is_implemented() -> bool = 0;
    virtual auto implementation_name() -> string_view = 0;
    virtual auto run(example_run_context&) -> int = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_MAIN_HPP
