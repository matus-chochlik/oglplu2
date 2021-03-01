/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_APPLICATION_TYPES_HPP
#define EAGINE_APPLICATION_TYPES_HPP

#include "../reflect/map_enumerators.hpp"
#include "../tags.hpp"
#include <cstdint>

namespace eagine::application {
//------------------------------------------------------------------------------
/// @brief Video / graphics rendering context kind.
/// @ingroup application
enum class video_context_kind : std::uint8_t {
    /// @brief OpenGL© (or OpenGL|ES) context.
    opengl,
    /// @brief OpenVG© context.
    openvg
};

template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<video_context_kind>, Selector) noexcept {
    return enumerator_map_type<video_context_kind, 2>{
      {{"opengl", video_context_kind::opengl},
       {"openvg", video_context_kind::openvg}}};
}
//------------------------------------------------------------------------------
/// @brief Audio / sound playback and recodring context kind.
/// @ingroup application
enum class audio_context_kind : std::uint8_t {
    /// @brief OpenAL© context.
    openal
};

template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<audio_context_kind>, Selector) noexcept {
    return enumerator_map_type<audio_context_kind, 1>{
      {{"openal", audio_context_kind::openal}}};
}
//------------------------------------------------------------------------------
/// @brief Video rendering device kind.
/// @ingroup application
enum class video_device_kind : std::uint8_t {
    /// @brief No preferrence.
    dont_care,
    /// @brief Hardware rendering device.
    hardware,
    /// @brief Software rendering device.
    software
};

template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<video_device_kind>, Selector) noexcept {
    return enumerator_map_type<video_device_kind, 3>{
      {{"dont_care", video_device_kind::dont_care},
       {"hardware", video_device_kind::hardware},
       {"software", video_device_kind::software}}};
}
//------------------------------------------------------------------------------
/// @brief Pixel data type used to store frame dump image data.
/// @ingroup application
/// @see framedump_pixel_format
enum class framedump_data_type : std::uint8_t {
    /// @brief None, not doing frame dump render run.
    none,
    /// @brief Floating-point pixel data.
    float_type,
    /// @brief Byte pixel data.
    byte_type
};

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
  application_config_tag) noexcept {
    return enumerator_map_type<framedump_data_type, 3>{
      {{"none", framedump_data_type::none},
       {"float", framedump_data_type::float_type},
       {"byte", framedump_data_type::byte_type}}};
}
//------------------------------------------------------------------------------
/// @brief Pixel data format of frame dump image data.
/// @ingroup application
/// @see framedump_data_type
enum class framedump_pixel_format : std::uint8_t {
    /// @brief None.
    none,
    /// @brief Red, green, blue, alpha color channel data.
    rgba,
    /// @brief Depth buffer data.
    depth,
    /// @brief Stencil buffer data.
    stencil
};

template <typename Selector>
constexpr auto
enumerator_mapping(type_identity<framedump_pixel_format>, Selector) noexcept {
    return enumerator_map_type<framedump_pixel_format, 4>{
      {{"none", framedump_pixel_format::none},
       {"rgba", framedump_pixel_format::rgba},
       {"depth", framedump_pixel_format::depth},
       {"stencil", framedump_pixel_format::stencil}}};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
#endif
