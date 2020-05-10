/**
 *  @file eagine/message_bus/acceptor.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_ACCEPTOR_HPP
#define EAGINE_MESSAGE_BUS_ACCEPTOR_HPP

#include "connection.hpp"

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
struct acceptor {
    virtual ~acceptor() noexcept = default;
    acceptor() noexcept = default;
    acceptor(acceptor&&) noexcept = default;
    acceptor(const acceptor&) = delete;
    acceptor& operator=(acceptor&&) = delete;
    acceptor& operator=(const acceptor&) = delete;

    using accept_handler = callable_ref<void(std::unique_ptr<connection>)>;

    virtual bool update() {
        return false;
    }

    virtual bool process_accepted(const accept_handler& handler) = 0;
};
//------------------------------------------------------------------------------
struct acceptor_user {
    virtual ~acceptor_user() noexcept = default;
    acceptor_user() noexcept = default;
    acceptor_user(acceptor_user&&) noexcept = default;
    acceptor_user(const acceptor_user&) = delete;
    acceptor_user& operator=(acceptor_user&&) = delete;
    acceptor_user& operator=(const acceptor_user&) = delete;

    virtual bool add_acceptor(std::unique_ptr<acceptor> an_acceptor) = 0;
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#endif // EAGINE_MESSAGE_BUS_ACCEPTOR_HPP

