/**
 *  .file oglplus/example/main.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_EXAMPLE_MAIN_HPP
#define OGLPLUS_EXAMPLE_MAIN_HPP

#include <eagine/string_span.hpp>
#include <oglplus/config/site.hpp>

namespace eagine {
//------------------------------------------------------------------------------
class example_args;
class example_params;
class example_state;
//------------------------------------------------------------------------------
struct example_main_intf {
    virtual ~example_main_intf() noexcept = default;
    example_main_intf() noexcept = default;
    example_main_intf(example_main_intf&&) = delete;
    example_main_intf(const example_main_intf&) = delete;
    example_main_intf& operator=(example_main_intf&&) = delete;
    example_main_intf& operator=(const example_main_intf&) = delete;

    virtual bool is_implemented() = 0;
    virtual string_view implementation_name() = 0;
    virtual int run(example_args&, example_params&, example_state&) = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_MAIN_HPP

