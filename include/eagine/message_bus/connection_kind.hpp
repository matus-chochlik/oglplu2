/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_MESSAGE_BUS_CONNECTION_KIND_HPP
#define EAGINE_MESSAGE_BUS_CONNECTION_KIND_HPP

#include "../bitfield.hpp"
#include "../reflect/map_enumerators.hpp"
#include <type_traits>

namespace eagine::msgbus {
//------------------------------------------------------------------------------
/// @brief Message bus connection kind bits enumeration.
/// @ingroup msgbus
/// @see connection_kinds
enum class connection_kind : std::uint8_t {
    /// @brief Unknown connection kind.
    unknown = 0U,
    /// @brief In-process connection (cannot be used for inter-process communication).
    in_process = 1U << 0U,
    /// @brief Inter-process connection for local communication.
    local_interprocess = 1U << 1U,
    /// @brief Inter-process connection for remote communucation
    remote_interprocess = 1U << 2U
};
//------------------------------------------------------------------------------
template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<connection_kind>, Selector) noexcept {
    return enumerator_map_type<connection_kind, 4>{
      {{"unknown", connection_kind::unknown},
       {"in_process", connection_kind::in_process},
       {"local_interprocess", connection_kind::local_interprocess},
       {"remote_interprocess", connection_kind::remote_interprocess}}};
}
//------------------------------------------------------------------------------
/// @brief Alias for connection kind bitfield.
/// @ingroup msgbus
using connection_kinds = bitfield<connection_kind>;

static inline auto operator|(connection_kind l, connection_kind r) noexcept
  -> connection_kinds {
    return {l, r};
}
//------------------------------------------------------------------------------
} // namespace eagine::msgbus

#endif // EAGINE_MESSAGE_BUS_CONNECTION_KIND_HPP
