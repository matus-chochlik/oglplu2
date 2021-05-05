/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_SYSTEM_INFO_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_SYSTEM_INFO_HPP

#include "../../bool_aggregate.hpp"
#include "../../main_ctx.hpp"
#include "../../maybe_unused.hpp"
#include "../service.hpp"
#include "../signal.hpp"
#include <array>
#include <chrono>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Service providing basic information about endpoint's host system.
/// @ingroup msgbus
/// @see service_composition
/// @see system_info_consumer
/// @see system_info
template <typename Base = subscriber>
class system_info_provider : public Base {

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

        Base::add_method(_power_supply_kind(
          EAGINE_MSG_ID(eagiSysInf, powerSuply),
          &main_ctx::get().system(),
          EAGINE_MEM_FUNC_C(
            system_info, power_supply))[EAGINE_MSG_ID(eagiSysInf, rqPwrSuply)]);
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

    default_function_skeleton<power_supply_kind() noexcept, 32>
      _power_supply_kind;
};
//------------------------------------------------------------------------------
/// @brief Service consuming basic information about endpoint's host system.
/// @ingroup msgbus
/// @see service_composition
/// @see system_info_provider
/// @see system_info
template <typename Base = subscriber>
class system_info_consumer : public Base {

public:
    /// @brief Queries the endpoint's host system uptime.
    /// @see uptime_received
    void query_uptime(identifier_t endpoint_id) {
        _uptime.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqUptime));
    }

    /// @brief Triggered on receipt of endpoint's system uptime.
    /// @see query_uptime
    signal<void(const result_context&, const std::chrono::duration<float>&)>
      uptime_received;

    /// @brief Queries the endpoint's host CPU's supported concurrent thread count.
    /// @see cpu_concurrent_threads_received
    void query_cpu_concurrent_threads(identifier_t endpoint_id) {
        _cpu_concurrent_threads.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqCpuThrds));
    }

    /// @brief Triggered on receipt of CPU's supported concurrent thread count.
    /// @see query_cpu_concurrent_threads
    signal<void(const result_context&, const valid_if_positive<span_size_t>&)>
      cpu_concurrent_threads_received;

    /// @brief Queries the endpoint's host system short average load (0.0 - 1.0).
    /// @see short_average_load_received
    void query_short_average_load(identifier_t endpoint_id) {
        _short_average_load.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqShrtLoad));
    }

    /// @brief Triggered on receipt of endpoint's host short average load.
    /// @see query_short_average_load
    signal<void(const result_context&, const valid_if_nonnegative<float>&)>
      short_average_load_received;

    /// @brief Queries the endpoint's host system long average load (0.0 - 1.0).
    /// @see long_average_load_received
    void query_long_average_load(identifier_t endpoint_id) {
        _long_average_load.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqLongLoad));
    }

    /// @brief Triggered on receipt of endpoint's host long average load.
    /// @see query_long_average_load
    signal<void(const result_context&, const valid_if_nonnegative<float>&)>
      long_average_load_received;

    /// @brief Queries the endpoint's host system memory page size in bytes.
    /// @see memory_page_size_received
    void query_memory_page_size(identifier_t endpoint_id) {
        _memory_page_size.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqMemPgSz));
    }

    /// @brief Triggered on receipt of endpoint's host system memory page size.
    /// @see query_memory_page_size
    signal<void(const result_context&, const valid_if_positive<span_size_t>&)>
      memory_page_size_received;

    /// @brief Queries the endpoint's host system free RAM size in bytes.
    /// @see free_ram_size_received
    /// @see query_total_ram_size
    void query_free_ram_size(identifier_t endpoint_id) {
        _free_ram_size.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqFreRamSz));
    }

    /// @brief Triggered on receipt of endpoint's host system free RAM size.
    /// @see query_free_ram_size
    signal<void(const result_context&, const valid_if_positive<span_size_t>&)>
      free_ram_size_received;

    /// @brief Queries the endpoint's host system total RAM size in bytes.
    /// @see total_ram_size_received
    /// @see query_free_ram_size
    void query_total_ram_size(identifier_t endpoint_id) {
        _total_ram_size.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqTtlRamSz));
    }

    /// @brief Triggered on receipt of endpoint's host system total RAM size.
    /// @see query_total_ram_size
    signal<void(const result_context&, const valid_if_positive<span_size_t>&)>
      total_ram_size_received;

    /// @brief Queries the endpoint's host system free swap size in bytes.
    /// @see free_swap_size_received
    /// @see query_total_swap_size
    void query_free_swap_size(identifier_t endpoint_id) {
        _free_swap_size.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqFreSwpSz));
    }

    /// @brief Triggered on receipt of endpoint's host system free swap size.
    /// @see query_free_swap_size
    signal<void(const result_context&, const valid_if_nonnegative<span_size_t>&)>
      free_swap_size_received;

    /// @brief Queries the endpoint's host system total swap size in bytes.
    /// @see total_swap_size_received
    /// @see query_free_swap_size
    void query_total_swap_size(identifier_t endpoint_id) {
        _total_swap_size.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqTtlSwpSz));
    }

    /// @brief Triggered on receipt of endpoint's host system total swap size.
    /// @see query_total_swap_size
    signal<void(const result_context&, const valid_if_nonnegative<span_size_t>&)>
      total_swap_size_received;

    /// @brief Queries the endpoint's host system power supply kind information.
    void query_power_supply_kind(identifier_t endpoint_id) {
        _power_supply_kind.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiSysInf, rqPwrSuply));
    }

    /// @brief Triggered on receipt of endpoint's host system power supply kind.
    /// @see query_power_supply_kind
    signal<void(const result_context&, power_supply_kind)>
      power_supply_kind_received;

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

    default_callback_invoker<power_supply_kind(), 32> _power_supply_kind;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(
          _uptime(uptime_received)[EAGINE_MSG_ID(eagiSysInf, uptime)]);

        Base::add_method(_cpu_concurrent_threads(
          cpu_concurrent_threads_received)[EAGINE_MSG_ID(
          eagiSysInf, cpuThreads)]);

        Base::add_method(_short_average_load(
          short_average_load_received)[EAGINE_MSG_ID(eagiSysInf, shortLoad)]);

        Base::add_method(_long_average_load(
          long_average_load_received)[EAGINE_MSG_ID(eagiSysInf, longLoad)]);

        Base::add_method(_memory_page_size(
          memory_page_size_received)[EAGINE_MSG_ID(eagiSysInf, memPageSz)]);

        Base::add_method(_free_ram_size(
          free_ram_size_received)[EAGINE_MSG_ID(eagiSysInf, freeRamSz)]);

        Base::add_method(_total_ram_size(
          total_ram_size_received)[EAGINE_MSG_ID(eagiSysInf, totalRamSz)]);

        Base::add_method(_free_swap_size(
          free_swap_size_received)[EAGINE_MSG_ID(eagiSysInf, freeSwpSz)]);

        Base::add_method(_total_swap_size(
          total_swap_size_received)[EAGINE_MSG_ID(eagiSysInf, totalSwpSz)]);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_SYSTEM_INFO_HPP
