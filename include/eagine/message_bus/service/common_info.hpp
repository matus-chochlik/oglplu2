/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_SERVICE_COMMON_INFO_HPP
#define EAGINE_MESSAGE_BUS_SERVICE_COMMON_INFO_HPP

#include "../service_requirements.hpp"
#include "application_info.hpp"
#include "build_info.hpp"
#include "compiler_info.hpp"
#include "endpoint_info.hpp"
#include "host_info.hpp"

namespace eagine::msgbus {

/// @brief Alias for a common composition of information provider services.
/// @ingroup msgbus
/// @see service_composition
/// @see common_info_consumers
template <typename Base = subscriber>
using common_info_providers = require_services<
  Base,
  compiler_info_provider,
  build_info_provider,
  host_info_provider,
  application_info_provider,
  endpoint_info_provider>;

/// @brief Alias for a common composition of information consumer services.
/// @ingroup msgbus
/// @see service_composition
/// @see common_info_providers
template <typename Base = subscriber>
using common_info_consumers = require_services<
  Base,
  compiler_info_consumer,
  build_info_consumer,
  host_info_consumer,
  application_info_consumer,
  endpoint_info_consumer>;

} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_SERVICE_COMMON_INFO_HPP
