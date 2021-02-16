/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_ACCEPTOR_HPP
#define EAGINE_MESSAGE_BUS_ACCEPTOR_HPP

#include "connection.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
struct acceptor : connection_info {

    using accept_handler = callable_ref<void(std::unique_ptr<connection>)>;

    virtual auto update() -> bool {
        return false;
    }

    virtual auto process_accepted(const accept_handler& handler) -> bool = 0;
};
//------------------------------------------------------------------------------
struct acceptor_user {
    virtual ~acceptor_user() noexcept = default;
    acceptor_user() noexcept = default;
    acceptor_user(acceptor_user&&) noexcept = default;
    acceptor_user(const acceptor_user&) = delete;
    auto operator=(acceptor_user&&) = delete;
    auto operator=(const acceptor_user&) = delete;

    virtual auto add_acceptor(std::shared_ptr<acceptor> an_acceptor)
      -> bool = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_ACCEPTOR_HPP
