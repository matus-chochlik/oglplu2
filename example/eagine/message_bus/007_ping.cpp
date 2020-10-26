/**
 *  @example eagine/message_bus/007_ping.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/identifier_ctr.hpp>
#include <eagine/main_ctx.hpp>
#include <eagine/math/functions.hpp>
#include <eagine/message_bus/conn_setup.hpp>
#include <eagine/message_bus/router_address.hpp>
#include <eagine/message_bus/service.hpp>
#include <eagine/message_bus/service/discovery.hpp>
#include <eagine/message_bus/service/ping_pong.hpp>
#include <eagine/message_bus/service/shutdown.hpp>
#include <eagine/message_bus/service/system_info.hpp>
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
    std::string hostname;
    span_size_t num_cores{0};
    std::chrono::microseconds min_time{std::chrono::microseconds::max()};
    std::chrono::microseconds max_time{std::chrono::microseconds::zero()};
    std::chrono::microseconds sum_time{std::chrono::microseconds::zero()};
    std::chrono::steady_clock::time_point start{
      std::chrono::steady_clock::now()};
    std::chrono::steady_clock::time_point finish{
      std::chrono::steady_clock::now()};
    std::chrono::steady_clock::time_point prev_log{
      std::chrono::steady_clock::now()};
    std::intmax_t responded{0};
    std::intmax_t timeouted{0};

    std::vector<float> messages_per_second{};

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
using ping_base = service_composition<
  pinger<system_info_consumer<subscriber_discovery<shutdown_invoker<>>>>>;

class ping_example : public ping_base {
    using base = ping_base;

public:
    ping_example(endpoint& bus, const valid_if_positive<std::intmax_t>& max)
      : base{bus}
      , _log{EAGINE_ID(PingExampl), bus.log()}
      , _max{extract_or(max, 100000)} {}

    void on_subscribed(identifier_t id, message_id sub_msg) final {
        if(sub_msg == EAGINE_MSG_ID(eagiPing, ping)) {
            _log.info("pingable ${id} appeared").arg(EAGINE_ID(id), id);
            _targets.try_emplace(id, ping_stats{});
        }
    }

    void on_unsubscribed(identifier_t id, message_id sub_msg) final {
        if(sub_msg == EAGINE_MSG_ID(eagiPing, ping)) {
            _log.info("pingable ${id} disappeared").arg(EAGINE_ID(id), id);
        }
    }

    void on_hostname_received(identifier_t id, string_view hostname) final {
        auto& stats = _targets[id];
        stats.hostname = to_string(hostname);
    }

    void on_cpu_concurrent_threads_received(
      identifier_t id,
      span_size_t num_cores) final {
        auto& stats = _targets[id];
        stats.num_cores = num_cores;
    }

    void on_ping_response(
      identifier_t pinger_id,
      message_sequence_t,
      std::chrono::microseconds age,
      verification_bits) final {
        auto& stats = _targets[pinger_id];
        stats.responded++;
        stats.min_time = std::min(stats.min_time, age);
        stats.max_time = std::max(stats.max_time, age);
        stats.sum_time += age;
        stats.finish = std::chrono::steady_clock::now();
        if(EAGINE_UNLIKELY((++_rcvd % _mod) == 0)) {
            const auto now{std::chrono::steady_clock::now()};
            const std::chrono::duration<float> interval{now - stats.prev_log};

            if(EAGINE_LIKELY(interval > decltype(interval)::zero())) {
                const auto msgs_per_sec{float(_mod) / interval.count()};
                stats.messages_per_second.push_back(msgs_per_sec);

                _log.info("received ${rcvd} pongs")
                  .arg(EAGINE_ID(rcvd), _rcvd)
                  .arg(EAGINE_ID(interval), interval)
                  .arg(EAGINE_ID(msgsPerSec), msgs_per_sec)
                  .arg(EAGINE_ID(done), EAGINE_ID(Progress), 0, _rcvd, _max);
            }
            stats.prev_log = now;
        }
    }

    void on_ping_timeout(
      identifier_t pinger_id,
      message_sequence_t,
      std::chrono::microseconds) final {
        auto& stats = _targets[pinger_id];
        stats.timeouted++;
        if(EAGINE_UNLIKELY((++_tout % _mod) == 0)) {
            _log.info("${tout} pongs timeouted").arg(EAGINE_ID(tout), _tout);
        }
    }

    auto is_done() const noexcept -> bool {
        return !(((_rcvd + _tout + _mod) < _max) || this->has_pending_pings());
    }

    auto update() -> bool {
        some_true something_done{};
        something_done(base::update());
        if(EAGINE_UNLIKELY(_targets.empty())) {
            if(EAGINE_UNLIKELY(_should_query_pingable)) {
                _log.info("searching for pingables");
                query_subscribers_of(EAGINE_MSG_ID(eagiPing, ping));
                _should_query_pingable.reset();
            }
        } else {
            for(auto& [pingable_id, entry] : _targets) {
                if(_rcvd < _max) {
                    if(_sent < (_rcvd + _tout + _mod)) {
                        this->ping(pingable_id, std::chrono::seconds(5));
                        if(EAGINE_UNLIKELY((++_sent % _mod) == 0)) {
                            _log.info("sent ${sent} pings")
                              .arg(EAGINE_ID(sent), _sent);
                            if(entry.hostname.empty()) {
                                this->query_hostname(pingable_id);
                            }
                            if(!entry.num_cores) {
                                this->query_cpu_concurrent_threads(pingable_id);
                            }
                        }
                        something_done();
                    }
                } else {
                    break;
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
            const auto& infoc{info};

            _log.stat("pingable ${id} stats:")
              .arg(EAGINE_ID(id), id)
              .arg(EAGINE_ID(hostname), info.hostname)
              .arg(EAGINE_ID(numCores), info.num_cores)
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

            _log.stat("pingable ${id} messages per second:")
              .arg(EAGINE_ID(id), id)
              .arg_func([&](logger_backend& backend) {
                  if(!infoc.messages_per_second.empty()) {
                      const auto max_mps = *std::max_element(
                        infoc.messages_per_second.begin(),
                        infoc.messages_per_second.end());

                      std::size_t i{0};
                      if(const auto div{
                           std::size_t(_max / ((std::log(_max) - 1) * _mod))}) {

                          float sum_mps = 0.F;
                          const float mpsn{1.F / div};

                          for(const float mps : infoc.messages_per_second) {
                              sum_mps += mps;
                              if(++i % div == 0) {
                                  sum_mps *= mpsn;
                                  backend.add_float(
                                    EAGINE_ID(mps),
                                    EAGINE_ID(Histogram),
                                    float(0),
                                    float(sum_mps),
                                    float(max_mps));
                                  sum_mps = 0.F;
                              }
                          }
                          if(i % div != 0) {
                              sum_mps *= 1.F / float(i % div);
                              backend.add_float(
                                EAGINE_ID(mps),
                                EAGINE_ID(Histogram),
                                float(0),
                                float(sum_mps),
                                float(max_mps));
                          }
                      }
                  }
              });
        }
    }

private:
    logger _log{};
    timeout _should_query_pingable{std::chrono::seconds(2)};
    std::map<identifier_t, ping_stats> _targets{};
    std::intmax_t _mod{10000};
    std::intmax_t _max{100000};
    std::intmax_t _sent{0};
    std::intmax_t _rcvd{0};
    std::intmax_t _tout{0};
};
//------------------------------------------------------------------------------
} // namespace msgbus

auto main(main_ctx& ctx) -> int {

    msgbus::router_address address{ctx.log(), ctx.args()};
    msgbus::connection_setup conn_setup(ctx.log(), ctx.args());

    msgbus::endpoint bus{logger{EAGINE_ID(PingEndpt), ctx.log()}};

    valid_if_positive<std::intmax_t> ping_count{};
    if(auto arg{ctx.args().find("--ping-count")}) {
        arg.next().parse(ping_count, ctx.log().error_stream());
    }

    msgbus::ping_example the_pinger{bus, ping_count};
    conn_setup.setup_connectors(the_pinger, address);

    while(!the_pinger.is_done()) {
        the_pinger.process_all();
        if(!the_pinger.update()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
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
    options.logger_id = EAGINE_ID(PingExe);
    return eagine::main_impl(argc, argv, options);
}
