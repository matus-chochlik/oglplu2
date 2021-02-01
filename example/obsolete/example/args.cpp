/**
 *  .file oglplus/example/args.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "args.hpp"
#include <eagine/logging/logger.hpp>
#include <eagine/program_args.hpp>

namespace eagine {
//------------------------------------------------------------------------------
auto example_arg::operator==(const example_param_tags& tags) const noexcept
  -> bool {
    return _arg == tags._stag || _arg == tags._ltag;
}
//------------------------------------------------------------------------------
auto example_args::argc() const noexcept -> int {
    return _args.argc();
}
//------------------------------------------------------------------------------
auto example_args::argv() const noexcept -> const char** {
    return _args.argv();
}
//------------------------------------------------------------------------------
template <typename T>
auto example_args::_parse_param(example_param<T>& param) const -> bool {
    program_parameter<T> temp(param._stag, param._ltag, param._value);
    if(_args.parse_param(temp, _log.error_stream())) {
        param._value = temp.value();
    }
    return false;
}
//------------------------------------------------------------------------------
auto example_args::parse_param(example_string_param& param) const -> bool {
    return _parse_param(param);
}
//------------------------------------------------------------------------------
} // namespace eagine
