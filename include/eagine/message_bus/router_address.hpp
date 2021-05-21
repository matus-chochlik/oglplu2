/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_ROUTER_ADDRESS_HPP
#define EAGINE_MESSAGE_BUS_ROUTER_ADDRESS_HPP

#include "../application_config.hpp"
#include "../main_ctx_object.hpp"
#include <vector>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Class loading and managing message bus router address(es).
/// @ingroup msgbus
class router_address : public main_ctx_object {
public:
    router_address(main_ctx_parent parent, nothing_t)
      : main_ctx_object{EAGINE_ID(RouterAddr), parent} {}

    /// @brief Construction from parent main context object.
    router_address(main_ctx_parent parent)
      : router_address{parent, nothing} {
        configure(app_config());
    }

    void configure(application_config& config) {
        if(config.fetch("msg_bus.router.address", _addrs)) {
            log_debug("configured router address(es) ${addr}")
              .arg_func([&](logger_backend& backend) {
                  for(auto& addr : _addrs) {
                      backend.add_string(
                        EAGINE_ID(address), EAGINE_ID(string), addr);
                  }
              });
        }
    }

    /// @brief Indicates if this instance contains at least one address.
    explicit operator bool() const noexcept {
        return !_addrs.empty();
    }

    /// @brief Implicit conversion to string_view, returning the first address.
    operator string_view() const noexcept {
        if(_addrs.empty()) {
            return {};
        }
        return {_addrs.front()};
    }

    /// @brief Returns the number of addresses stored in this instance.
    auto count() const noexcept -> span_size_t {
        return span_size(_addrs.size());
    }

    /// @brief Returns a const iterator to the start of the range of addresses.
    auto begin() const noexcept {
        return _addrs.cbegin();
    }

    /// @brief Returns a const iterator past the end of the range of addresses.
    auto end() const noexcept {
        return _addrs.cend();
    }

private:
    std::vector<std::string> _addrs{};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_ROUTER_ADDRESS_HPP
