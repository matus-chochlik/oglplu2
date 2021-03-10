/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_ALC_API_CONTEXT_ATTRIBS_HPP
#define OALPLUS_ALC_API_CONTEXT_ATTRIBS_HPP

#include "config.hpp"
#include "enum_types.hpp"
#include <eagine/key_val_list.hpp>

namespace eagine::oalp {

/// @brief Traits for ALC context attribute key/value list traits.
/// @ingroup alc_api_wrap
struct context_attrib_traits {
    /// @brief Alias for the key type.
    using key_type = context_attribute;
    using conv_type = alc_types::enum_type;
    /// @brief Alias for the value type.
    using value_type = alc_types::int_type;

    static constexpr auto terminator() noexcept -> alc_types::int_type {
        return 0;
    }
};

/// @brief Alias for ALC context attribute key/value list.
/// @ingroup alc_api_wrap
template <std::size_t N>
using context_attributes = key_value_list<context_attrib_traits, N>;

/// @brief Alias for ALC context attribute list key/value pair.
/// @ingroup alc_api_wrap
/// @see context_attributes
using context_attribute_value = key_value_list_element<context_attrib_traits>;

/// @brief Concatenation operator for context attribute list key and value.
/// @ingroup alc_api_wrap
/// @relates config_attributes
static constexpr auto
operator|(context_attribute key, alc_types::int_type value) noexcept
  -> context_attribute_value {
    return {key, value};
}

/// @brief Concatenation operator for context attribute list key and value.
/// @ingroup alc_api_wrap
/// @relates config_attributes
static constexpr auto operator|(context_attribute key, bool value) noexcept
  -> context_attribute_value {
#if defined(ALC_TRUE) && defined(ALC_FALSE)
    return {key, value ? ALC_TRUE : ALC_FALSE};
#else
    return {key, value ? 1 : 0};
#endif
}

} // namespace eagine::oalp

#endif // OALPLUS_ALC_API_CONTEXT_ATTRIBS_HPP
