/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_HOST_INFO_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_HOST_INFO_HPP

#include "../../bool_aggregate.hpp"
#include "../../main_ctx.hpp"
#include "../../maybe_unused.hpp"
#include "../service.hpp"
#include "../signal.hpp"
#include <array>
#include <chrono>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class host_info_provider : public Base {
    using This = host_info_provider;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_host_id(
          EAGINE_MSG_ID(eagiSysInf, hostId),
          &main_ctx::get().system(),
          EAGINE_MEM_FUNC_C(
            system_info, host_id))[EAGINE_MSG_ID(eagiSysInf, rqHostId)]);

        Base::add_method(_hostname(
          EAGINE_MSG_ID(eagiSysInf, hostname),
          &main_ctx::get().system(),
          EAGINE_MEM_FUNC_C(
            system_info, hostname))[EAGINE_MSG_ID(eagiSysInf, rqHostname)]);
    }

private:
    default_function_skeleton<valid_if_positive<host_id_t>() noexcept, 64>
      _host_id;

    default_function_skeleton<valid_if_not_empty<std::string>() noexcept, 1024>
      _hostname;
};
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class host_info_consumer : public Base {

    using This = host_info_consumer;

public:
    void query_host_id(identifier_t endpoint_id) {
        _host_id.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqHostId));
    }

    signal<void(const result_context&, const valid_if_positive<host_id_t>&)>
      host_id_received;

    void query_hostname(identifier_t endpoint_id) {
        _hostname.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqHostname));
    }

    signal<void(const result_context&, const valid_if_not_empty<std::string>&)>
      hostname_received;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(
          _host_id(host_id_received)[EAGINE_MSG_ID(eagiSysInf, hostId)]);

        Base::add_method(
          _hostname(hostname_received)[EAGINE_MSG_ID(eagiSysInf, hostname)]);
    }

private:
    default_callback_invoker<valid_if_positive<host_id_t>(), 32> _host_id;

    default_callback_invoker<valid_if_not_empty<std::string>(), 1024> _hostname;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_HOST_INFO_HPP
