/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_FUTURE_HPP
#define EAGINE_MESSAGE_BUS_FUTURE_HPP

#include "../flat_map.hpp"
#include "../nothing.hpp"
#include "../timeout.hpp"
#include <functional>
#include <memory>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename T>
struct future_state {
    timeout too_late{std::chrono::seconds{1}};
    std::function<void(T)> success_handler{};
    std::function<void()> timeout_handler{};
};
//------------------------------------------------------------------------------
template <typename T>
class promise {
public:
    promise() noexcept = default;
    promise(std::shared_ptr<future_state<T>>& state) noexcept
      : _state{state} {}

    auto should_be_removed() -> bool {
        if(auto state{_state.lock()}) {
            if(state->too_late) {
                if(state->timeout_handler) {
                    state->timeout_handler();
                    _state.reset();
                }
            } else {
                return false;
            }
        }
        return true;
    }

    void fulfill(T value) {
        if(auto state{_state.lock()}) {
            _state.reset();
            if(state->too_late) {
                if(state->timeout_handler) {
                    state->timeout_handler();
                }
            } else {
                if(state->success_handler) {
                    state->success_handler(std::move(value));
                }
            }
        }
    }

private:
    std::weak_ptr<future_state<T>> _state{};
};
//------------------------------------------------------------------------------
template <typename T>
class future {
public:
    future() = default;
    future(nothing_t) noexcept
      : _state{} {}

    explicit operator bool() const noexcept {
        return bool(_state);
    }

    template <typename R, typename P>
    auto set_timeout(std::chrono::duration<R, P> dur) -> future<T>& {
        if(_state) {
            _state->too_late.reset(dur);
        }
        return *this;
    }

    auto on_success(const std::function<void(T)>& handler) -> future<T>& {
        if(_state) {
            _state->success_handler = handler;
        }
        return *this;
    }

    auto on_timeout(const std::function<void()>& handler) -> future<T>& {
        if(_state) {
            _state->timeout_handler = handler;
        }
        return *this;
    }

    template <
      typename Handler,
      typename = std::enable_if_t<std::is_invocable_v<Handler, T>>>
    auto then(Handler handler) -> future<T>& {
        if(_state) {
            _state->success_handler = std::function<void(T)>(
              [state{_state}, handler{std::move(handler)}](T value) {
                  handler(value);
              });
        }
        return *this;
    }

    template <
      typename Handler,
      typename = std::enable_if_t<std::is_invocable_v<Handler>>>
    auto otherwise(Handler handler) -> future<T>& {
        if(_state) {
            _state->timeout_handler = std::function<void()>(
              [state{_state}, handler{std::move(handler)}]() { handler(); });
        }
        return *this;
    }

    auto get_promise() -> promise<T> {
        return {_state};
    }

private:
    std::shared_ptr<future_state<T>> _state{
      std::make_shared<future_state<T>>()};
};
//------------------------------------------------------------------------------
template <typename T>
class pending_promises {
public:
    using id_t = message_sequence_t;

    auto make() -> std::tuple<id_t, future<T>> {
        future<T> result{};
        const auto id{++_id_seq};
        _promises[id] = result.get_promise();
        return {id, result};
    }

    void fulfill(id_t id, T value) {
        auto pos = _promises.find(id);
        if(pos != _promises.end()) {
            pos->second.fulfill(std::move(value));
            _promises.erase(pos);
        }
        update();
    }

    auto update() -> bool {
        return _promises.erase_if(
                 [](auto& p) { return p.second.should_be_removed(); }) > 0;
    }

    auto has_some() const noexcept -> bool {
        return !_promises.empty();
    }

    auto has_none() const noexcept -> bool {
        return _promises.empty();
    }

private:
    id_t _id_seq{0};
    flat_map<id_t, promise<T>> _promises{};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_FUTURE_HPP
