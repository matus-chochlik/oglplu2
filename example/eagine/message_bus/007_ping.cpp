/// @example eagine/message_bus/007_ping.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/identifier_ctr.hpp>
#include <eagine/main_ctx.hpp>
#include <eagine/main_fwd.hpp>
#include <eagine/math/functions.hpp>
#include <eagine/message_bus.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/discovery.hpp>
#include <eagine/message_bus/service/host_info.hpp>
#include <eagine/message_bus/service/ping_pong.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/message_bus/service_requirements.hpp>
#include <eagine/timeout.hpp>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <map>
#include <vector>

namespace eagine {
namespace msgbus {
//------------------------------------------------------------------------------
struct ping_stats {
    host_id_t host_id{0};
    std::string hostname;
    std::chrono::microseconds min_time{std::chrono::microseconds::max()};
    std::chrono::microseconds max_time{std::chrono::microseconds::zero()};
    std::chrono::microseconds sum_time{std::chrono::microseconds::zero()};
    std::chrono::steady_clock::time_point start{
      std::chrono::steady_clock::now()};
    std::chrono::steady_clock::time_point finish{
      std::chrono::steady_clock::now()};
    std::intmax_t responded{0};
    std::intmax_t timeouted{0};
    resetting_timeout should_check_info{std::chrono::seconds(5), nothing};

    auto avg_time() const noexcept {
        return sum_time / responded;
    }

    auto time_interval() const noexcept {
        return std::chrono::duration_cast<std::chrono::duration<float>>(
          finish - start);
    }

    auto total_count() const noexcept {
        return float(responded) + float(timeouted);
    }

    auto respond_rate() const noexcept {
        return math::ratio(float(responded), total_count());
    }

    auto responds_per_second() const noexcept {
        return math::ratio(float(responded), time_interval().count());
    }
};
//------------------------------------------------------------------------------
using ping_base = service_composition<require_services<
  subscriber,
  pinger,
  host_info_consumer,
  subscriber_discovery,
  shutdown_invoker>>;

class ping_example
  : public main_ctx_object
  , public ping_base {
    using base = ping_base;

public:
    ping_example(endpoint& bus, const valid_if_positive<std::intmax_t>& max)
      : main_ctx_object{EAGINE_ID(PingExampl), bus}
      , base{bus}
      , _max{extract_or(max, 100000)} {
        object_description("Pinger", "Ping example");

        bus.id_assigned.connect(EAGINE_THIS_MEM_FUNC_REF(on_id_assigned));
        bus.connection_lost.connect(
          EAGINE_THIS_MEM_FUNC_REF(on_connection_lost));
        bus.connection_established.connect(
          EAGINE_THIS_MEM_FUNC_REF(on_connection_established));

        subscribed.connect(EAGINE_THIS_MEM_FUNC_REF(on_subscribed));
        unsubscribed.connect(EAGINE_THIS_MEM_FUNC_REF(on_unsubscribed));
        not_subscribed.connect(EAGINE_THIS_MEM_FUNC_REF(on_not_subscribed));
        ping_responded.connect(EAGINE_THIS_MEM_FUNC_REF(on_ping_response));
        ping_timeouted.connect(EAGINE_THIS_MEM_FUNC_REF(on_ping_timeout));
        host_id_received.connect(EAGINE_THIS_MEM_FUNC_REF(on_host_id_received));
        hostname_received.connect(
          EAGINE_THIS_MEM_FUNC_REF(on_hostname_received));
    }

    void on_id_assigned(identifier_t endpoint_id) {
        log_info("new id ${id} assigned").arg(EAGINE_ID(id), endpoint_id);
        _do_ping = true;
    }

    void on_connection_established(bool usable) {
        log_info("connection established");
        _do_ping = usable;
    }

    void on_connection_lost() {
        log_info("connection lost");
        _do_ping = false;
    }

    void on_subscribed(const subscriber_info& info, message_id sub_msg) {
        if(sub_msg == this->ping_msg_id()) {
            if(_targets.try_emplace(info.endpoint_id, ping_stats{}).second) {
                log_info("new pingable ${id} appeared")
                  .arg(EAGINE_ID(id), info.endpoint_id);
            }
        }
    }

    void on_unsubscribed(const subscriber_info& info, message_id sub_msg) {
        if(sub_msg == this->ping_msg_id()) {
            log_info("pingable ${id} disappeared")
              .arg(EAGINE_ID(id), info.endpoint_id);
        }
    }

    void on_not_subscribed(const subscriber_info& info, message_id sub_msg) {
        if(sub_msg == this->ping_msg_id()) {
            log_info("target ${id} is not pingable")
              .arg(EAGINE_ID(id), info.endpoint_id);
        }
    }

    void on_host_id_received(
      const result_context& res_ctx,
      const valid_if_positive<host_id_t>& host_id) {
        if(host_id) {
            auto& stats = _targets[res_ctx.source_id()];
            stats.host_id = extract(host_id);
        }
    }

    void on_hostname_received(
      const result_context& res_ctx,
      const valid_if_not_empty<std::string>& hostname) {
        if(hostname) {
            auto& stats = _targets[res_ctx.source_id()];
            stats.hostname = extract(hostname);
        }
    }

    void on_ping_response(
      identifier_t pinger_id,
      message_sequence_t,
      std::chrono::microseconds age,
      verification_bits) {
        auto& stats = _targets[pinger_id];
        stats.responded++;
        stats.min_time = std::min(stats.min_time, age);
        stats.max_time = std::max(stats.max_time, age);
        stats.sum_time += age;
        stats.finish = std::chrono::steady_clock::now();
        if(EAGINE_UNLIKELY((++_rcvd % _mod) == 0)) {
            const auto now{std::chrono::steady_clock::now()};
            const std::chrono::duration<float> interval{now - prev_log};

            if(EAGINE_LIKELY(interval > decltype(interval)::zero())) {
                const auto msgs_per_sec{float(_mod) / interval.count()};

                log_chart_sample(EAGINE_ID(msgsPerSec), msgs_per_sec);
                log_info("received ${rcvd} pongs")
                  .arg(EAGINE_ID(rcvd), _rcvd)
                  .arg(EAGINE_ID(interval), interval)
                  .arg(EAGINE_ID(msgsPerSec), msgs_per_sec)
                  .arg(EAGINE_ID(done), EAGINE_ID(Progress), 0, _rcvd, _max);
            }
            prev_log = now;
        }
    }

    void on_ping_timeout(
      identifier_t pinger_id,
      message_sequence_t,
      std::chrono::microseconds) {
        auto& stats = _targets[pinger_id];
        stats.timeouted++;
        if(EAGINE_UNLIKELY((++_tout % _mod) == 0)) {
            log_info("${tout} pongs timeouted").arg(EAGINE_ID(tout), _tout);
        }
    }

    auto is_done() const noexcept -> bool {
        return !(((_rcvd + _tout + _mod) < _max) || this->has_pending_pings());
    }

    auto update() -> work_done {
        some_true something_done{};
        something_done(base::update());
        if(_do_ping) {
            if(EAGINE_UNLIKELY(_should_query_pingable)) {
                log_info("searching for pingables");
                query_pingables();
            }
            if(!_targets.empty()) {
                for(auto& [pingable_id, entry] : _targets) {
                    if(_rcvd < _max) {
                        const auto lim{
                          _rcvd +
                          static_cast<std::intmax_t>(
                            _mod * (1 + std::log(float(1 + _targets.size()))))};

                        if(_sent < lim) {
                            this->ping(pingable_id, std::chrono::seconds(5));
                            if(EAGINE_UNLIKELY((++_sent % _mod) == 0)) {
                                log_info("sent ${sent} pings")
                                  .arg(EAGINE_ID(sent), _sent);
                            }

                            if(EAGINE_UNLIKELY(entry.should_check_info)) {
                                if(!entry.host_id) {
                                    this->query_host_id(pingable_id);
                                }
                                if(entry.hostname.empty()) {
                                    this->query_hostname(pingable_id);
                                }
                            }
                            something_done();
                        }
                    } else {
                        break;
                    }
                }
            }
        }
        something_done(base::process_all() > 0);
        return something_done;
    }

    void shutdown() {
        for(auto& entry : _targets) {
            this->shutdown_one(std::get<0>(entry));
        }
        base::update();
    }

    void log_stats() {
        const string_view not_avail{"N/A"};
        for(auto& [id, info] : _targets) {

            log_stat("pingable ${id} stats:")
              .arg(EAGINE_ID(id), id)
              .arg(EAGINE_ID(hostId), info.host_id)
              .arg(EAGINE_ID(hostname), info.hostname)
              .arg(EAGINE_ID(minTime), info.min_time)
              .arg(EAGINE_ID(maxTime), info.max_time)
              .arg(EAGINE_ID(avgTime), info.avg_time())
              .arg(EAGINE_ID(responded), info.responded)
              .arg(EAGINE_ID(timeouted), info.timeouted)
              .arg(EAGINE_ID(duration), info.time_interval())
              .arg(
                EAGINE_ID(rspdRate),
                EAGINE_ID(Ratio),
                info.respond_rate(),
                not_avail)
              .arg(
                EAGINE_ID(rspdPerSec),
                EAGINE_ID(RatePerSec),
                info.responds_per_second(),
                not_avail);
        }
    }

private:
    resetting_timeout _should_query_pingable{std::chrono::seconds(2), nothing};
    std::chrono::steady_clock::time_point prev_log{
      std::chrono::steady_clock::now()};
    std::map<identifier_t, ping_stats> _targets{};
    std::intmax_t _mod{5000};
    std::intmax_t _max{100000};
    std::intmax_t _sent{0};
    std::intmax_t _rcvd{0};
    std::intmax_t _tout{0};
    bool _do_ping{false};
};
//------------------------------------------------------------------------------
} // namespace msgbus

auto main(main_ctx& ctx) -> int {
    ctx.preinitialize();

    msgbus::endpoint bus{EAGINE_ID(PingEndpt), ctx};

    valid_if_positive<std::intmax_t> ping_count{};
    if(auto arg{ctx.args().find("--ping-count")}) {
        arg.next().parse(ping_count, ctx.log().error_stream());
    }

    msgbus::ping_example the_pinger{bus, ping_count};
    ctx.bus().setup_connectors(the_pinger);

    resetting_timeout do_chart_stats{std::chrono::seconds(15), nothing};

    while(!the_pinger.is_done()) {
        the_pinger.process_all();
        if(!the_pinger.update()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            if(do_chart_stats) {
                the_pinger.log_chart_sample(
                  EAGINE_ID(shortLoad), ctx.system().short_average_load());
                the_pinger.log_chart_sample(
                  EAGINE_ID(longLoad), ctx.system().long_average_load());
                if(auto temp_k{ctx.system().cpu_temperature()}) {
                    the_pinger.log_chart_sample(
                      EAGINE_ID(cpuTempC),
                      extract(temp_k).to<units::degree_celsius>());
                }
            }
        }
    }
    the_pinger.shutdown();
    the_pinger.log_stats();

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine

auto main(int argc, const char** argv) -> int {
    eagine::main_ctx_options options;
    options.app_id = EAGINE_ID(PingExe);
    return eagine::main_impl(argc, argv, options);
}
