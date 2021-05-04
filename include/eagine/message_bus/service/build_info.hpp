/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_BUILD_INFO_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_BUILD_INFO_HPP

#include "../../bool_aggregate.hpp"
#include "../../main_ctx.hpp"
#include "../../maybe_unused.hpp"
#include "../../serialize/type/build_info.hpp"
#include "../service.hpp"
#include "../signal.hpp"
#include <array>
#include <chrono>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Service providing information about endpoint build version.
/// @ingroup msgbus
/// @see service_composition
/// @see build_info_consumer
template <typename Base = subscriber>
class build_info_provider : public Base {
    using This = build_info_provider;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_respond(
          EAGINE_MSG_ID(eagiBldInf, response),
          &main_ctx::get(),
          EAGINE_MEM_FUNC_C(
            main_ctx, build))[EAGINE_MSG_ID(eagiBldInf, request)]);
    }

private:
    default_function_skeleton<const build_info&() noexcept, 256> _respond;
};
//------------------------------------------------------------------------------
/// @brief Service consuming information about endpoint build version.
/// @ingroup msgbus
/// @see service_composition
/// @see build_info_provider
/// @see build_info
template <typename Base = subscriber>
class build_info_consumer : public Base {

    using This = build_info_consumer;

public:
    /// @brief Queries endpoint's build version information.
    /// @see build_info_received
    void query_build_info(identifier_t endpoint_id) {
        _build.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiBldInf, request));
    }

    /// @brief Triggered on receipt of endpoint's build version information.
    /// @see query_build_info
    signal<void(const result_context&, const build_info&)> build_info_received;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(
          _build(build_info_received)[EAGINE_MSG_ID(eagiBldInf, response)]);
    }

private:
    default_callback_invoker<build_info(), 32> _build;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_BUILD_INFO_HPP
