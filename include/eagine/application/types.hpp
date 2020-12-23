/**
 *  @file eagine/application/types.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_APPLICATION_TYPES_HPP
#define EAGINE_APPLICATION_TYPES_HPP

#include "../reflect/map_enumerators.hpp"
#include "../value_tree/types.hpp"
#include <cstdint>

namespace eagine::application {
//------------------------------------------------------------------------------
enum class video_context_kind : std::uint8_t { opengl, opengl_es3, vulkan };
enum class audio_context_kind : std::uint8_t { openal };
//------------------------------------------------------------------------------
enum class framedump_data_type : std::uint8_t { none, float_type, byte_type };

template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<framedump_data_type>, Selector) noexcept {
    return enumerator_map_type<framedump_data_type, 3>{
      {{"none", framedump_data_type::none},
       {"float_type", framedump_data_type::float_type},
       {"byte_type", framedump_data_type::byte_type}}};
}

constexpr auto enumerator_mapping(
  type_identity<framedump_data_type>,
  value_tree_tag) noexcept {
    return enumerator_map_type<framedump_data_type, 3>{
      {{"none", framedump_data_type::none},
       {"float", framedump_data_type::float_type},
       {"byte", framedump_data_type::byte_type}}};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
#endif
