/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_ENDPOINT_INFO_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_ENDPOINT_INFO_HPP

#include "../../bool_aggregate.hpp"
#include "../../main_ctx.hpp"
#include "../../maybe_unused.hpp"
#include "../service.hpp"
#include "../types.hpp"
#include <array>
#include <chrono>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Service providing basic information about message bus endpoint.
/// @ingroup msgbus
/// @see service_composition
/// @see endpoint_info_consumer
/// @see endpoint_info
template <typename Base = subscriber>
class endpoint_info_provider : public Base {

public:
    /// @brief Sets the endpoint info to be provided.
    auto provided_endpoint_info() noexcept -> endpoint_info& {
        return _info;
    }

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_respond(
          EAGINE_MSG_ID(eagiEptInf, response),
          EAGINE_THIS_MEM_FUNC_REF(
            _get_endpoint_info))[EAGINE_MSG_ID(eagiEptInf, request)]);
    }

private:
    auto _get_endpoint_info() -> const endpoint_info& {
        return _info;
    }

    default_function_skeleton<const endpoint_info&(), 1024> _respond;
    endpoint_info _info;
};
//------------------------------------------------------------------------------
/// @brief Service consuming basic information about message bus endpoint.
/// @ingroup msgbus
/// @see service_composition
/// @see endpoint_info_provider
/// @see endpoint_info
template <typename Base = subscriber>
class endpoint_info_consumer : public Base {

public:
    /// @brief Queries basic information about the specified endpoint.
    /// @see endpoint_info_received
    void query_endpoint_info(identifier_t endpoint_id) {
        _info.invoke_on(
          this->bus_node(), endpoint_id, EAGINE_MSG_ID(eagiEptInf, request));
    }

    /// @brief Triggered on receipt of basic endpoint information.
    /// @see query_endpoint_info
    signal<void(const result_context&, const endpoint_info&)>
      endpoint_info_received;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(
          _info(endpoint_info_received)[EAGINE_MSG_ID(eagiEptInf, response)]);
    }

private:
    default_callback_invoker<endpoint_info(), 1024> _info;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_ENDPOINT_INFO_HPP
