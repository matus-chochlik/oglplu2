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
#include "../../serialize/type/build_info.hpp"
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
template <typename Base = subscriber>
class build_info_consumer : public Base {

    using This = build_info_consumer;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_build(
          this,
          EAGINE_MEM_FUNC_C(
            This,
            on_build_info_received))[EAGINE_MSG_ID(eagiBldInf, response)]);
    }

public:
    void query_build_info(identifier_t endpoint_id) {
        _build.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiBldInf, request));
    }

    virtual void on_build_info_received(const result_context&, build_info&&) = 0;

private:
    default_callback_invoker<build_info(), 32> _build;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_BUILD_INFO_HPP
