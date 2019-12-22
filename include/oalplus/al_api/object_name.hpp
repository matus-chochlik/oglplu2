/**
 *  @file oalplus/al_api/object_name.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_OBJECT_NAME_HPP
#define OALPLUS_AL_API_OBJECT_NAME_HPP

#include "config.hpp"
#include <eagine/handle.hpp>
#include <eagine/identifier.hpp>

namespace eagine {
//------------------------------------------------------------------------------
namespace oalp {
//------------------------------------------------------------------------------
template <typename Tag>
using al_object_name = basic_handle<Tag, al_types::name_type>;

template <typename Tag>
using al_owned_object_name = basic_owned_handle<Tag, al_types::name_type>;
//------------------------------------------------------------------------------
using buffer_tag = EAGINE_TAG_TYPE(Buffer);
using source_tag = EAGINE_TAG_TYPE(Source);
//------------------------------------------------------------------------------
using buffer_name = al_object_name<buffer_tag>;
using source_name = al_object_name<buffer_tag>;
//------------------------------------------------------------------------------
using owned_buffer_name = al_owned_object_name<buffer_tag>;
using owned_source_name = al_owned_object_name<source_tag>;
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_OBJECT_NAME_HPP

