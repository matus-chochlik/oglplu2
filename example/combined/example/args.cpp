/**
 *  .file oglplus/example/args.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "args.hpp"
#include <eagine/program_args.hpp>

namespace eagine {
namespace oglp {

bool example_arg::operator==(const example_param_tags& tags) const noexcept {
    return _arg == tags._stag || _arg == tags._ltag;
}

int example_args::argc() const noexcept {
    return _args.argc();
}

const char** example_args::argv() const noexcept {
    return _args.argv();
}

string_view example_args::command() const noexcept { // NOLINT
    return _args.command();
}

template <typename T>
bool example_args::_parse_param(example_param<T>& param) const {
    program_parameter<T> temp(param._stag, param._ltag, param._value);
    if(_args.parse_param(temp, _errlog)) {
        param._value = temp.value();
    }
    return false;
}

bool example_args::parse_param(example_string_param& param) const {
    return _parse_param(param);
}

} // namespace oglp
} // namespace eagine
