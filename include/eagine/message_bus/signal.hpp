/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SIGNAL_HPP
#define EAGINE_MESSAGE_BUS_SIGNAL_HPP

#include "../callable_ref.hpp"
#include "../flat_map.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename Signature>
class signal;
//------------------------------------------------------------------------------
/// @brief Class that allows connecting and invoking callables with the specified signature.
/// @ingroup msgbus
template <typename... Params>
class signal<void(Params...)> {
public:
    /// @brief Type of key that can be used to remove connected slot.
    using connection_key = unsigned;

    /// @brief Connects the specified callable, returns a key for removal.
    /// @see disconnect
    auto connect(callable_ref<void(Params...)> slot) -> connection_key {
        auto get_key = [](auto& entry) {
            return std::get<0>(entry);
        };
        auto key = 0U;
        auto pos = _slots.begin();

        if(!_slots.empty()) {
            key = get_key(_slots.back()) + 1U;
            pos = [&]() {
                while(true) {
                    auto [p, unused] = _slots.find_insert_position(key);
                    if(unused) {
                        return p;
                    }
                    ++key;
                }
            }();
        }
        _slots.insert(pos, {key, slot});
        return key;
    }

    /// @brief Disconnects the callable by specifying the connection key.
    /// @see connect
    auto disconnect(connection_key key) -> auto& {
        _slots.erase(key);
        return *this;
    }

    /// @brief Implicit conversion to a compatible callable_ref.
    template <typename... P>
    operator callable_ref<void(P...)>() const noexcept {
        return {
          this,
          member_function_constant<
            void (signal::*)(P...) const,
            &signal::_call>{}};
    }

private:
    template <typename... P>
    void _call(P... args) const {
        for(const auto& entry : _slots) {
            std::get<1>(entry)(args...);
        }
    }

    flat_map<unsigned, callable_ref<void(Params...)>> _slots;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SIGNAL_HPP
