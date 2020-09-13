/**
 *  @file oalplus/alc_api/context_attribs.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_ALC_API_CONTEXT_ATTRIBS_HPP
#define OALPLUS_ALC_API_CONTEXT_ATTRIBS_HPP

#include "config.hpp"
#include "enum_types.hpp"
#include <eagine/key_val_list.hpp>

namespace eagine::oalp {

struct context_attrib_traits {
    using key_type = context_attribute;
    using conv_type = alc_types::enum_type;
    using value_type = alc_types::int_type;

    static constexpr inline alc_types::int_type terminator() noexcept {
        return 0;
    }
};

template <std::size_t N>
using context_attributes = key_value_list<context_attrib_traits, N>;

using context_attribute_value = key_value_list_element<context_attrib_traits>;

static constexpr inline context_attribute_value
operator|(context_attribute key, alc_types::int_type value) noexcept {
    return {key, value};
}

#if defined(ALC_TRUE) && defined(ALC_FALSE)
static constexpr inline context_attribute_value
operator|(context_attribute key, bool value) noexcept {
    return {key, value ? ALC_TRUE : ALC_FALSE};
}
#endif

} // namespace eagine::oalp

#endif // OALPLUS_ALC_API_CONTEXT_ATTRIBS_HPP
