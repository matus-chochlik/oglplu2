/**
 *  @file eagine/message_bus/service/endpoint_info.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SERVICE_ENDPOINT_INFO_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_ENDPOINT_INFO_HPP

#include "../../bool_aggregate.hpp"
#include "../../main_ctx.hpp"
#include "../../maybe_unused.hpp"
#include "../service.hpp"
#include "../types.hpp"
#include <array>
#include <chrono>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class endpoint_info_provider : public Base {
    using This = endpoint_info_provider;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_respond(
          EAGINE_MSG_ID(eagiEptInf, response),
          this,
          EAGINE_MEM_FUNC_C(
            This, provide_endpoint_info))[EAGINE_MSG_ID(eagiEptInf, request)]);
    }

public:
    virtual auto provide_endpoint_info() -> endpoint_info = 0;

private:
    default_function_skeleton<endpoint_info(), 1024> _respond;
};
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class endpoint_info_consumer : public Base {

    using This = endpoint_info_consumer;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_info(
          this,
          EAGINE_MEM_FUNC_C(
            This,
            on_endpoint_info_received))[EAGINE_MSG_ID(eagiEptInf, response)]);
    }

public:
    void query_endpoint_info(identifier_t endpoint_id) {
        _info.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiEptInf, request));
    }

    virtual void
    on_endpoint_info_received(const result_context&, endpoint_info&&) = 0;

private:
    default_callback_invoker<endpoint_info(), 1024> _info;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_ENDPOINT_INFO_HPP
