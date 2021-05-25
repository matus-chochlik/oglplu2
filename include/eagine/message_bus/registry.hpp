/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_REGISTRY_HPP
#define EAGINE_MESSAGE_BUS_REGISTRY_HPP

#include "../extract.hpp"
#include "../main_ctx_object.hpp"
#include "direct.hpp"
#include "endpoint.hpp"
#include "router.hpp"
#include "service_interface.hpp"
#include <memory>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
struct registered_entry {
    std::unique_ptr<endpoint> _endpoint{};
    std::unique_ptr<service_interface> _service{};

    auto update_service() -> bool;
};
//------------------------------------------------------------------------------
/// @brief Class combining a local bus router and a set of endpoints.
/// @ingroup msgbus
class registry : public main_ctx_object {
public:
    /// @brief Construction from parent main context object.
    registry(main_ctx_parent parent);

    /// @brief Establishes a new endpoint with the specified logger identifier.
    /// @see emplace
    [[nodiscard]] auto establish(identifier log_id) -> endpoint& {
        return extract(_add_entry(log_id)._endpoint);
    }

    /// @brief Establishes an endpoint and instantiates a service object tied to it.
    /// @see establish
    template <typename Service, typename... Args>
    auto emplace(identifier log_id, Args&&... args) -> std::
      enable_if_t<std::is_base_of_v<service_interface, Service>, Service&> {
        auto& entry = _add_entry(log_id);
        auto temp{std::make_unique<Service>(
          extract(entry._endpoint), std::forward<Args>(args)...)};
        auto& result = extract(temp);
        entry._service = std::move(temp);
        return result;
    }

    /// @brief Removes a previously emplaced service.
    void remove(service_interface&);

    auto update() -> bool;
    auto update_all() -> bool;

    auto is_done() -> bool {
        return _router.is_done();
    }

    void finish() {
        _router.finish();
    }

private:
    std::shared_ptr<direct_acceptor> _acceptor;
    router _router;
    std::vector<registered_entry> _entries;

    auto _add_entry(identifier log_id) -> registered_entry&;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/message_bus/registry.inl>
#endif

#endif // EAGINE_MESSAGE_BUS_REGISTRY_HPP
