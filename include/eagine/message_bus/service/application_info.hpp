/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_APPLICATION_INFO_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_APPLICATION_INFO_HPP

#include "../../bool_aggregate.hpp"
#include "../../main_ctx.hpp"
#include "../../maybe_unused.hpp"
#include "../service.hpp"
#include "../signal.hpp"

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class application_info_provider : public Base {
    using This = application_info_provider;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_app_name(
          EAGINE_MSG_ID(eagiAppInf, appName),
          &main_ctx::get(),
          EAGINE_MEM_FUNC_C(
            main_ctx, app_name))[EAGINE_MSG_ID(eagiAppInf, rqAppName)]);
    }

private:
    default_function_skeleton<string_view() noexcept, 256> _app_name;
};
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class application_info_consumer : public Base {

    using This = application_info_consumer;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_app_name(
          application_name_received)[EAGINE_MSG_ID(eagiAppInf, appName)]);
    }

public:
    void query_application_name(identifier_t endpoint_id) {
        _app_name.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiAppInf, rqAppName));
    }

    signal<void(const result_context&, const valid_if_not_empty<std::string>&)>
      application_name_received;

private:
    default_callback_invoker<std::string(), 256> _app_name;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_APPLICATION_INFO_HPP
