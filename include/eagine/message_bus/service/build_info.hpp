/**
 *  @file eagine/message_bus/service/build_info.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_MESSAGE_BUS_SERVICE_BUILD_INFO_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_BUILD_INFO_HPP

#include "../../bool_aggregate.hpp"
#include "../../main_ctx.hpp"
#include "../../maybe_unused.hpp"
#include "../service.hpp"
#include <array>
#include <chrono>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class build_info_provider : public Base {
    using This = build_info_provider;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_version(
          EAGINE_MSG_ID(eagiBldInf, version),
          &main_ctx::get(),
          EAGINE_MEM_FUNC_C(
            main_ctx, version))[EAGINE_MSG_ID(eagiBldInf, rqVersion)]);
    }

private:
    default_function_skeleton<
      optionally_valid<std::tuple<int, int, int, int>>() noexcept,
      64>
      _version;
};
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class build_info_consumer : public Base {

    using This = build_info_consumer;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_version(
          this,
          EAGINE_MEM_FUNC_C(
            This, on_version_received))[EAGINE_MSG_ID(eagiBldInf, version)]);
    }

public:
    void query_version(identifier_t endpoint_id) {
        _version.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiBldInf, rqVersion));
    }

    virtual void on_version_received(
      const result_context&,
      optionally_valid<std::tuple<int, int, int, int>>&&) = 0;

private:
    default_callback_invoker<
      optionally_valid<std::tuple<int, int, int, int>>(),
      32>
      _version;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_BUILD_INFO_HPP
