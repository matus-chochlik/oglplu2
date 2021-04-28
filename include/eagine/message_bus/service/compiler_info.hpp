/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_COMPILER_INFO_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_COMPILER_INFO_HPP

#include "../../bool_aggregate.hpp"
#include "../../main_ctx.hpp"
#include "../../maybe_unused.hpp"
#include "../../serialize/type/compiler_info.hpp"
#include "../service.hpp"
#include "../signal.hpp"
#include <array>
#include <chrono>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class compiler_info_provider : public Base {
    using This = compiler_info_provider;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_respond(
          EAGINE_MSG_ID(eagiCplInf, response),
          &main_ctx::get(),
          EAGINE_MEM_FUNC_C(
            main_ctx, compiler))[EAGINE_MSG_ID(eagiCplInf, request)]);
    }

private:
    default_function_skeleton<const compiler_info&() noexcept, 256> _respond;
};
//------------------------------------------------------------------------------
template <typename Base = subscriber>
class compiler_info_consumer : public Base {

    using This = compiler_info_consumer;

public:
    void query_compiler_info(identifier_t endpoint_id) {
        _compiler.invoke_on(
          this->bus(), endpoint_id, EAGINE_MSG_ID(eagiCplInf, request));
    }

    signal<void(const result_context&, const compiler_info&)>
      compiler_info_received;

protected:
    using Base::Base;

    void add_methods() {
        Base::add_methods();

        Base::add_method(_compiler(
          compiler_info_received)[EAGINE_MSG_ID(eagiCplInf, response)]);
    }

private:
    default_callback_invoker<compiler_info(), 32> _compiler;
};
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_COMPILER_INFO_HPP
