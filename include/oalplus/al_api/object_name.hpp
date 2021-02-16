/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_AL_API_OBJECT_NAME_HPP
#define OALPLUS_AL_API_OBJECT_NAME_HPP

#include "config.hpp"
#include <eagine/handle.hpp>
#include <eagine/message_id.hpp>

namespace eagine::oalp {
//------------------------------------------------------------------------------
template <typename Tag>
using al_object_name = basic_handle<Tag, al_types::name_type>;

template <typename Tag>
using al_owned_object_name = basic_owned_handle<Tag, al_types::name_type>;
//------------------------------------------------------------------------------
using source_tag = EAGINE_MSG_TYPE(al, Source);
using buffer_tag = EAGINE_MSG_TYPE(al, Buffer);
using effect_tag = EAGINE_MSG_TYPE(al, Effect);
using filter_tag = EAGINE_MSG_TYPE(al, Filter);
using auxiliary_effect_slot_tag = EAGINE_MSG_TYPE(al, AuxEffSlot);
//------------------------------------------------------------------------------
using source_name = al_object_name<source_tag>;
using buffer_name = al_object_name<buffer_tag>;
using effect_name = al_object_name<effect_tag>;
using filter_name = al_object_name<filter_tag>;
using auxiliary_effect_slot_name = al_object_name<auxiliary_effect_slot_tag>;
//------------------------------------------------------------------------------
using owned_source_name = al_owned_object_name<source_tag>;
using owned_buffer_name = al_owned_object_name<buffer_tag>;
using owned_effect_name = al_owned_object_name<effect_tag>;
using owned_filter_name = al_owned_object_name<filter_tag>;
using owned_auxiliary_effect_slot_name =
  al_owned_object_name<auxiliary_effect_slot_tag>;
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_AL_API_OBJECT_NAME_HPP
