/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

namespace eagine::oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
basic_al_operations<ApiTraits>::basic_al_operations(api_traits& traits)
  : c_api{traits}
  , gen_sources("gen_sources", traits, *this)
  , gen_buffers("gen_buffers", traits, *this)
  , gen_effects("gen_effects", traits, *this)
  , gen_filters("gen_filters", traits, *this)
  , gen_auxiliary_effect_slots("gen_auxiliary_effect_slots", traits, *this)
  , delete_sources("delete_sources", traits, *this)
  , delete_buffers("delete_buffers", traits, *this)
  , delete_effects("delete_effects", traits, *this)
  , delete_filters("delete_filters", traits, *this)
  , delete_auxiliary_effect_slots("delete_auxiliary_effect_slots", traits, *this)
  , is_source("is_source", traits, *this)
  , is_buffer("is_buffer", traits, *this)
  , is_effect("is_effect", traits, *this)
  , is_filter("is_filter", traits, *this)
  , is_auxiliary_effect_slot("is_auxiliary_effect_slot", traits, *this)
  , listener_i("listener_i", traits, *this)
  , listener_f("listener_f", traits, *this)
  , get_listener_i("get_listener_i", traits, *this)
  , get_listener_f("get_listener_f", traits, *this)
  , buffer_i("buffer_i", traits, *this)
  , buffer_f("buffer_f", traits, *this)
  , get_buffer_i("get_buffer_i", traits, *this)
  , get_buffer_f("get_buffer_f", traits, *this)
  , source_i("source_i", traits, *this)
  , source_f("source_f", traits, *this)
  , get_source_i("get_source_i", traits, *this)
  , get_source_f("get_source_f", traits, *this)
  , source_queue_buffers("source_queue_buffers", traits, *this)
  , source_unqueue_buffers("source_unqueue_buffers", traits, *this)
  , source_play("source_play", traits, *this)
  , source_pause("source_pause", traits, *this)
  , source_stop("source_stop", traits, *this)
  , source_rewind("source_rewind", traits, *this)
  , get_string("get_string", traits, *this) {}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

