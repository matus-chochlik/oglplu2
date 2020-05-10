/**
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/bool_aggregate.hpp>
#include <eagine/branch_predict.hpp>
#include <eagine/message_bus/context.hpp>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
struct bridge_state {
    bridge_state() noexcept = default;

    std::istream& input{std::cin};
    std::ostream& output{std::cout};
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::add_connection(std::unique_ptr<connection> conn) {
    _connections.emplace_back(std::move(conn));
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void bridge::_setup_from_args(const program_args&) {
    // TODO
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_handle_special(
  identifier_t class_id, identifier_t method_id, message_view message) {
    // TODO
    EAGINE_MAYBE_UNUSED(class_id);
    EAGINE_MAYBE_UNUSED(method_id);
    EAGINE_MAYBE_UNUSED(message);
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_do_forward_message(
  identifier_t class_id, identifier_t method_id, message_view message) {
    // TODO
    EAGINE_MAYBE_UNUSED(class_id);
    EAGINE_MAYBE_UNUSED(method_id);
    EAGINE_MAYBE_UNUSED(message);
    return true;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_forward_messages() {
    some_true something_done{};

    auto handler = [this](
                     identifier_t class_id,
                     identifier_t method_id,
                     const message_view& message) {
        if(this->_handle_special(class_id, method_id, message)) {
            return true;
        }
        return this->_do_forward_message(class_id, method_id, message);
    };

    for(auto& conn : _connections) {
        if(EAGINE_LIKELY(conn && conn->is_usable())) {
            something_done(
              conn->fetch_messages(connection::fetch_handler(handler)));
        }
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::_update_connections() {
    some_true something_done{};

    for(auto& conn : _connections) {
        if(EAGINE_LIKELY(conn)) {
            if(conn->update()) {
                something_done();
                _no_connection_timeout.reset();
            }
        }
    }
    return something_done;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
bool bridge::update() {
    some_true something_done{};
    something_done(_update_connections());
    something_done(_forward_messages());
    return something_done;
}
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

