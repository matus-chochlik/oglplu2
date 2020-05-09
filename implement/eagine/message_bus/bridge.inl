/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/branch_predict.hpp>
#include <eagine/message_bus/context.hpp>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::add_connection(std::unique_ptr<connection>) {
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void bridge::_setup_from_args(const program_args&) {
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void bridge::update() {
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

