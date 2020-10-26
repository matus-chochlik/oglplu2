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
#include "../service.hpp"
#include <array>
#include <chrono>

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
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiSysInf, rqUptime, This, _provide_uptime));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiSysInf, rqCpuThrds, This, _provide_cpu_threads));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiSysInf, rqShrtLoad, This, _provide_short_load));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiSysInf, rqLongLoad, This, _provide_long_load));
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

    auto _provide_uptime(stored_message& message) -> bool {
        const auto uptime{main_ctx::get().system().uptime()};
        std::array<byte, 32> temp{};
        if(auto serialized{default_serialize(uptime, cover(temp))}) {
            this->bus().respond_to(
              message,
              EAGINE_MSG_ID(eagiSysInf, uptime),
              {extract(serialized)});
        }
        return true;
    }

    auto _provide_cpu_threads(stored_message& message) -> bool {
        if(auto opt_cores{main_ctx::get().system().cpu_concurrent_threads()}) {
            std::array<byte, 32> temp{};
            if(auto serialized{
                 default_serialize(extract(opt_cores), cover(temp))}) {
                this->bus().respond_to(
                  message,
                  EAGINE_MSG_ID(eagiSysInf, cpuThreads),
                  {extract(serialized)});
            }
        }
        return true;
    }

    auto _provide_short_load(stored_message& message) -> bool {
        if(auto opt_load{main_ctx::get().system().short_average_load()}) {
            std::array<byte, 32> temp{};
            if(auto serialized{
                 default_serialize(extract(opt_load), cover(temp))}) {
                this->bus().respond_to(
                  message,
                  EAGINE_MSG_ID(eagiSysInf, shortLoad),
                  {extract(serialized)});
            }
        }
        return true;
    }

    auto _provide_long_load(stored_message& message) -> bool {
        if(auto opt_load{main_ctx::get().system().long_average_load()}) {
            std::array<byte, 32> temp{};
            if(auto serialized{
                 default_serialize(extract(opt_load), cover(temp))}) {
                this->bus().respond_to(
                  message,
                  EAGINE_MSG_ID(eagiSysInf, longLoad),
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
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiSysInf, uptime, This, _consume_uptime));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiSysInf, cpuThreads, This, _consume_cpu_threads));
        Base::add_method(
          this,
          EAGINE_MSG_MAP(eagiSysInf, shortLoad, This, _consume_short_load));
        Base::add_method(
          this, EAGINE_MSG_MAP(eagiSysInf, longLoad, This, _consume_long_load));
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

    void query_uptime(identifier_t endpoint_id) {
        message_view request{};
        request.set_target_id(endpoint_id);
        this->bus().send(EAGINE_MSG_ID(eagiSysInf, rqUptime), request);
    }

    virtual void on_uptime_received(
      identifier_t endpoint_id,
      std::chrono::duration<float> uptime) {
        EAGINE_MAYBE_UNUSED(endpoint_id);
        EAGINE_MAYBE_UNUSED(uptime);
    }

    void query_cpu_concurrent_threads(identifier_t endpoint_id) {
        message_view request{};
        request.set_target_id(endpoint_id);
        this->bus().send(EAGINE_MSG_ID(eagiSysInf, rqCpuThrds), request);
    }

    virtual void on_cpu_concurrent_threads_received(
      identifier_t endpoint_id,
      span_size_t cores) {
        EAGINE_MAYBE_UNUSED(endpoint_id);
        EAGINE_MAYBE_UNUSED(cores);
    }

    void query_short_average_load(identifier_t endpoint_id) {
        message_view request{};
        request.set_target_id(endpoint_id);
        this->bus().send(EAGINE_MSG_ID(eagiSysInf, rqShrtLoad), request);
    }

    virtual void
    on_short_average_load_received(identifier_t endpoint_id, float load) {
        EAGINE_MAYBE_UNUSED(endpoint_id);
        EAGINE_MAYBE_UNUSED(load);
    }

    void query_long_average_load(identifier_t endpoint_id) {
        message_view request{};
        request.set_target_id(endpoint_id);
        this->bus().send(EAGINE_MSG_ID(eagiSysInf, rqLongLoad), request);
    }

    virtual void
    on_long_average_load_received(identifier_t endpoint_id, float load) {
        EAGINE_MAYBE_UNUSED(endpoint_id);
        EAGINE_MAYBE_UNUSED(load);
    }

private:
    auto _consume_hostname(stored_message& message) -> bool {
        std::string hostname;
        if(default_deserialize(hostname, message.content())) {
            on_hostname_received(message.source_id, {hostname});
        }
        return true;
    }

    auto _consume_uptime(stored_message& message) -> bool {
        std::chrono::duration<float> uptime{};
        if(default_deserialize(uptime, message.content())) {
            on_uptime_received(message.source_id, uptime);
        }
        return true;
    }

    auto _consume_cpu_threads(stored_message& message) -> bool {
        span_size_t num_threads{0};
        if(default_deserialize(num_threads, message.content())) {
            on_cpu_concurrent_threads_received(message.source_id, num_threads);
        }
        return true;
    }

    auto _consume_short_load(stored_message& message) -> bool {
        float load{0.F};
        if(default_deserialize(load, message.content())) {
            on_short_average_load_received(message.source_id, load);
        }
        return true;
    }

    auto _consume_long_load(stored_message& message) -> bool {
        float load{0.F};
        if(default_deserialize(load, message.content())) {
            on_long_average_load_received(message.source_id, load);
        }
        return true;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_SYSTEM_INFO_HPP
