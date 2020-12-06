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

        Base::add_method(_uptime(
          EAGINE_MSG_ID(eagiSysInf, uptime),
          &main_ctx::get().system(),
          EAGINE_MEM_FUNC_C(
            system_info, uptime))[EAGINE_MSG_ID(eagiSysInf, rqUptime)]);

        Base::add_method(_cpu_concurrent_threads(
          EAGINE_MSG_ID(eagiSysInf, cpuThreads),
          &main_ctx::get().system(),
          EAGINE_MEM_FUNC_C(
            system_info,
            cpu_concurrent_threads))[EAGINE_MSG_ID(eagiSysInf, rqCpuThrds)]);

        Base::add_method(_short_average_load(
          EAGINE_MSG_ID(eagiSysInf, shortLoad),
          &main_ctx::get().system(),
          EAGINE_MEM_FUNC_C(
            system_info,
            short_average_load))[EAGINE_MSG_ID(eagiSysInf, rqShrtLoad)]);

        Base::add_method(_long_average_load(
          EAGINE_MSG_ID(eagiSysInf, longLoad),
          &main_ctx::get().system(),
          EAGINE_MEM_FUNC_C(
            system_info,
            long_average_load))[EAGINE_MSG_ID(eagiSysInf, rqLongLoad)]);

        Base::add_method(_memory_page_size(
          EAGINE_MSG_ID(eagiSysInf, memPageSz),
          &main_ctx::get().system(),
          EAGINE_MEM_FUNC_C(
            system_info,
            memory_page_size))[EAGINE_MSG_ID(eagiSysInf, rqMemPgSz)]);

        Base::add_method(_free_ram_size(
          EAGINE_MSG_ID(eagiSysInf, freeRamSz),
          &main_ctx::get().system(),
          EAGINE_MEM_FUNC_C(
            system_info,
            free_ram_size))[EAGINE_MSG_ID(eagiSysInf, rqFreRamSz)]);

        Base::add_method(_total_ram_size(
          EAGINE_MSG_ID(eagiSysInf, totalRamSz),
          &main_ctx::get().system(),
          EAGINE_MEM_FUNC_C(
            system_info,
            total_ram_size))[EAGINE_MSG_ID(eagiSysInf, rqTtlRamSz)]);

        Base::add_method(_free_swap_size(
          EAGINE_MSG_ID(eagiSysInf, freeSwpSz),
          &main_ctx::get().system(),
          EAGINE_MEM_FUNC_C(
            system_info,
            free_swap_size))[EAGINE_MSG_ID(eagiSysInf, rqFreSwpSz)]);

        Base::add_method(_total_swap_size(
          EAGINE_MSG_ID(eagiSysInf, totalSwpSz),
          &main_ctx::get().system(),
          EAGINE_MEM_FUNC_C(
            system_info,
            total_swap_size))[EAGINE_MSG_ID(eagiSysInf, rqTtlSwpSz)]);
    }

private:
    default_function_skeleton<std::chrono::duration<float>() noexcept, 32>
      _uptime;

    default_function_skeleton<valid_if_positive<span_size_t>() noexcept, 32>
      _cpu_concurrent_threads;

    default_function_skeleton<valid_if_nonnegative<float>() noexcept, 32>
      _short_average_load;

    default_function_skeleton<valid_if_nonnegative<float>() noexcept, 32>
      _long_average_load;

    default_function_skeleton<valid_if_positive<span_size_t>() noexcept, 32>
      _memory_page_size;

    default_function_skeleton<valid_if_positive<span_size_t>() noexcept, 32>
      _free_ram_size;

    default_function_skeleton<valid_if_positive<span_size_t>() noexcept, 32>
      _total_ram_size;

    default_function_skeleton<valid_if_nonnegative<span_size_t>() noexcept, 32>
      _free_swap_size;

    default_function_skeleton<valid_if_nonnegative<span_size_t>() noexcept, 32>
      _total_swap_size;
};
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class system_info_consumer : public Base {

    using This = system_info_consumer;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_uptime(
          this,
          EAGINE_MEM_FUNC_C(
            This, on_uptime_received))[EAGINE_MSG_ID(eagiSysInf, uptime)]);

        Base::add_method(_cpu_concurrent_threads(
          this, EAGINE_MEM_FUNC_C(This, on_cpu_concurrent_threads_received))
                           [EAGINE_MSG_ID(eagiSysInf, cpuThreads)]);

        Base::add_method(_short_average_load(
          this,
          EAGINE_MEM_FUNC_C(This, on_short_average_load_received))[EAGINE_MSG_ID(
          eagiSysInf, shortLoad)]);

        Base::add_method(_long_average_load(
          this,
          EAGINE_MEM_FUNC_C(This, on_long_average_load_received))[EAGINE_MSG_ID(
          eagiSysInf, longLoad)]);

        Base::add_method(_memory_page_size(
          this,
          EAGINE_MEM_FUNC_C(This, on_memory_page_size_received))[EAGINE_MSG_ID(
          eagiSysInf, memPageSz)]);

        Base::add_method(_free_ram_size(
          this,
          EAGINE_MEM_FUNC_C(
            This,
            on_free_ram_size_received))[EAGINE_MSG_ID(eagiSysInf, freeRamSz)]);

        Base::add_method(_total_ram_size(
          this,
          EAGINE_MEM_FUNC_C(This, on_total_ram_size_received))[EAGINE_MSG_ID(
          eagiSysInf, totalRamSz)]);

        Base::add_method(_free_swap_size(
          this,
          EAGINE_MEM_FUNC_C(
            This,
            on_free_swap_size_received))[EAGINE_MSG_ID(eagiSysInf, freeSwpSz)]);

        Base::add_method(_total_swap_size(
          this,
          EAGINE_MEM_FUNC_C(This, on_total_swap_size_received))[EAGINE_MSG_ID(
          eagiSysInf, totalSwpSz)]);
    }

public:
    void query_uptime(identifier_t endpoint_id) {
        _uptime.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqUptime));
    }

    virtual void
    on_uptime_received(const result_context&, std::chrono::duration<float>&&) {}

    void query_cpu_concurrent_threads(identifier_t endpoint_id) {
        _cpu_concurrent_threads.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqCpuThrds));
    }

    virtual void on_cpu_concurrent_threads_received(
      const result_context&,
      valid_if_positive<span_size_t>&&) {}

    void query_short_average_load(identifier_t endpoint_id) {
        _short_average_load.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqShrtLoad));
    }

    virtual void on_short_average_load_received(
      const result_context&,
      valid_if_nonnegative<float>&&) {}

    void query_long_average_load(identifier_t endpoint_id) {
        _long_average_load.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqLongLoad));
    }

    virtual void on_long_average_load_received(
      const result_context&,
      valid_if_nonnegative<float>&&) {}

    void query_memory_page_size(identifier_t endpoint_id) {
        _memory_page_size.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqMemPgSz));
    }

    virtual void on_memory_page_size_received(
      const result_context&,
      valid_if_positive<span_size_t>&&) {}

    void query_free_ram_size(identifier_t endpoint_id) {
        _free_ram_size.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqFreRamSz));
    }

    virtual void on_free_ram_size_received(
      const result_context&,
      valid_if_positive<span_size_t>&&) {}

    void query_total_ram_size(identifier_t endpoint_id) {
        _total_ram_size.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqTtlRamSz));
    }

    virtual void on_total_ram_size_received(
      const result_context&,
      valid_if_positive<span_size_t>&&) {}

    void query_free_swap_size(identifier_t endpoint_id) {
        _free_swap_size.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqFreSwpSz));
    }

    virtual void on_free_swap_size_received(
      const result_context&,
      valid_if_nonnegative<span_size_t>&&) {}

    void query_total_swap_size(identifier_t endpoint_id) {
        _total_swap_size.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqTtlSwpSz));
    }

    virtual void on_total_swap_size_received(
      const result_context&,
      valid_if_nonnegative<span_size_t>&&) {}

private:
    default_callback_invoker<std::chrono::duration<float>(), 32> _uptime;

    default_callback_invoker<valid_if_positive<span_size_t>(), 32>
      _cpu_concurrent_threads;

    default_callback_invoker<valid_if_nonnegative<float>(), 32>
      _short_average_load;

    default_callback_invoker<valid_if_nonnegative<float>(), 32>
      _long_average_load;

    default_callback_invoker<valid_if_positive<span_size_t>(), 32>
      _memory_page_size;

    default_callback_invoker<valid_if_positive<span_size_t>(), 32>
      _free_ram_size;

    default_callback_invoker<valid_if_positive<span_size_t>(), 32>
      _total_ram_size;

    default_callback_invoker<valid_if_nonnegative<span_size_t>(), 32>
      _free_swap_size;

    default_callback_invoker<valid_if_nonnegative<span_size_t>(), 32>
      _total_swap_size;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_SYSTEM_INFO_HPP
