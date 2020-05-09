/**
 *  @file eagine/message_bus/context.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_CONTEXT_HPP
#define EAGINE_MESSAGE_BUS_CONTEXT_HPP

#include "../memory/buffer.hpp"
#include "../ssl.hpp"
#include "../ssl_api.hpp"
#include "context_fwd.hpp"

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
class context {
public:
    context(logger& parent);
    context(logger& parent, const program_args& args);

    context(context&&) = delete;
    context(const context&) = delete;
    context& operator=(context&&) = delete;
    context& operator=(const context&) = delete;

    ~context() noexcept;

private:
    logger _log{};
    //
    sslp::ssl_api _ssl{};
    sslp::owned_engine _ssl_engine{};
    sslp::owned_x509_store _ssl_store{};
};
//------------------------------------------------------------------------------
} // namespace msgbus
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/context.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_CONTEXT_HPP

