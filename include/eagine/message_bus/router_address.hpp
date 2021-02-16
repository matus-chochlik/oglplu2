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
class router_address : public main_ctx_object {
public:
    router_address(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(RouterAddr), parent} {
        if(app_config().fetch("msg_bus.router.address", _addrs)) {
            log_debug("configured router address(es) ${addr}")
              .arg_func([&](logger_backend& backend) {
                  for(auto& addr : _addrs) {
                      backend.add_string(
                        EAGINE_ID(address), EAGINE_ID(string), addr);
                  }
              });
        }
    }

    explicit operator bool() const noexcept {
        return !_addrs.empty();
    }

    operator string_view() const noexcept {
        if(_addrs.empty()) {
            return {};
        }
        return {_addrs.front()};
    }

    auto count() const noexcept {
        return span_size(_addrs.size());
    }

    auto begin() const noexcept {
        return _addrs.cbegin();
    }

    auto end() const noexcept {
        return _addrs.cend();
    }

private:
    std::vector<std::string> _addrs{};
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_ROUTER_ADDRESS_HPP
