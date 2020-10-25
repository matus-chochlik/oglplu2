/**
 *  @file eagine/message_bus/service/system_info.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SERVICE_SYSTEM_INFO_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_SYSTEM_INFO_HPP

#include "../../bool_aggregate.hpp"
#include "../../main_ctx.hpp"
#include "../../maybe_unused.hpp"
#include "../serialize.hpp"
#include "../subscriber.hpp"
#include <vector>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class system_info_provider : public Base {
    using This = system_info_provider;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiSysInf, rqHostname, This, _provide_hostname));
    }

private:
    auto _provide_hostname(stored_message& message) -> bool {
        if(auto opt_hostname{main_ctx::get().system().hostname()}) {
            std::array<byte, 1024> temp{};
            if(auto serialized{
                 default_serialize(extract(opt_hostname), cover(temp))}) {
                this->bus().respond_to(
                  message,
                  EAGINE_MSG_ID(eagiSysInf, hostname),
                  {extract(serialized)});
            }
        }
        return true;
    }
};
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class system_info_consumer : public Base {

    using This = system_info_consumer;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiSysInf, hostname, This, _consume_hostname));
    }

public:
    void query_hostname(identifier_t endpoint_id) {
        message_view request{};
        request.set_target_id(endpoint_id);
        this->bus().send(EAGINE_MSG_ID(eagiSysInf, rqHostname), request);
    }

    virtual void
    on_hostname_received(identifier_t endpoint_id, string_view hostname) {
        EAGINE_MAYBE_UNUSED(endpoint_id);
        EAGINE_MAYBE_UNUSED(hostname);
    }

private:
    auto _consume_hostname(stored_message& message) -> bool {
        std::string hostname;
        if(default_deserialize(hostname, message.content())) {
            on_hostname_received(message.source_id, {hostname});
        }
        return true;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_SYSTEM_INFO_HPP
