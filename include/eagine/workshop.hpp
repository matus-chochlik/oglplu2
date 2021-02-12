/// @file eagine/workshop.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_WORKSHOP_HPP
#define EAGINE_WORKSHOP_HPP

#include "branch_predict.hpp"
#include "extract.hpp"
#include "integer_range.hpp"
#include "types.hpp"
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <tuple>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
struct work_unit {
    work_unit() noexcept = default;
    work_unit(work_unit&&) noexcept = default;
    work_unit(const work_unit&) noexcept = default;
    auto operator=(work_unit&&) noexcept -> work_unit& = default;
    auto operator=(const work_unit&) noexcept -> work_unit& = default;
    virtual ~work_unit() noexcept = default;

    virtual auto do_it() -> bool = 0;
    virtual void deliver() = 0;
};
//------------------------------------------------------------------------------
class workshop {
private:
    std::vector<std::thread> _workers{};
    std::mutex _mutex{};
    std::condition_variable _cond{};
    std::queue<work_unit*> _work_queue{};
    bool _shutdown{false};

    auto _fetch() -> std::tuple<work_unit*, bool> {
        std::unique_lock lock{_mutex};
        work_unit* work = nullptr;
        if(!_shutdown) {
            _cond.wait(
              lock, [this] { return !_work_queue.empty() || _shutdown; });
            if(!_work_queue.empty()) {
                work = _work_queue.front();
                _work_queue.pop();
            }
        }
        return {work, _shutdown};
    }

    void _employ() {
        while(true) {
            auto [opt_work, shutdown] = _fetch();
            if(opt_work) {
                auto& work = extract(opt_work);
                if(work.do_it()) {
                    std::unique_lock lock{_mutex};
                    work.deliver();
                    _cond.notify_all();
                } else {
                    enqueue(work);
                }
            }
            if(shutdown) {
                break;
            }
        }
    }

public:
    workshop() = default;
    workshop(workshop&&) = delete;
    workshop(const workshop&) = delete;
    auto operator=(workshop&&) = delete;
    auto operator=(const workshop&) = delete;
    ~workshop() noexcept {
        try {
            shutdown();
            wait_until_closed();
        } catch(...) {
        }
    }

    auto shutdown() -> workshop& {
        std::unique_lock lock{_mutex};
        _shutdown = true;
        _cond.notify_all();
        return *this;
    }

    auto wait_until_closed() -> workshop& {
        for(auto& worker : _workers) {
            worker.join();
        }
        return *this;
    }

    auto wait_until_idle() -> workshop& {
        std::unique_lock lock{_mutex};
        _cond.wait(lock, [this]() { return _work_queue.empty(); });
        return *this;
    }

    auto add_worker() -> workshop& {
        _workers.emplace_back([this]() { this->_employ(); });
        return *this;
    }

    auto add_workers(span_size_t n) -> workshop& {
        _workers.reserve(_workers.size() + std_size(n));
        for(auto i : integer_range(n)) {
            EAGINE_MAYBE_UNUSED(i);
            add_worker();
        }
        return *this;
    }

    auto ensure_workers(span_size_t n) -> workshop& {
        const auto c = span_size(_workers.size());
        if(n > c) {
            add_workers(n - c);
        }
        return *this;
    }

    auto populate() -> workshop& {
        return ensure_workers(span_size(std::thread::hardware_concurrency()));
    }

    auto release_worker() -> workshop& {
        _workers.pop_back();
        return *this;
    }

    auto enqueue(work_unit& work) -> workshop& {
        std::unique_lock lock{_mutex};
        if(EAGINE_UNLIKELY(_workers.empty())) {
            add_worker();
        }
        _work_queue.push(&work);
        _cond.notify_one();
        return *this;
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_WORKSHOP_HPP
