/**
 *  @file oalplus/al_api/api.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OALPLUS_AL_API_API_HPP
#define OALPLUS_AL_API_API_HPP

#include "c_api.hpp"
#include "enum_types.hpp"
#include "object_name.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

namespace eagine {
namespace oalp {
//------------------------------------------------------------------------------
template <typename ApiTraits>
class basic_al_api : public basic_al_c_api<ApiTraits> {

public:
    using api_traits = ApiTraits;
    using c_api = basic_al_c_api<ApiTraits>;

    using int_type = typename al_types::int_type;
    using bool_type = typename al_types::char_type;
    using char_type = typename al_types::char_type;
    using enum_type = typename al_types::enum_type;
    using name_type = typename al_types::name_type;
    using size_type = typename al_types::size_type;
    using float_type = typename al_types::float_type;

    struct derived_func : derived_c_api_function<c_api, api_traits, nothing_t> {
        using base = derived_c_api_function<c_api, api_traits, nothing_t>;
        using base::base;

        template <typename Res>
        constexpr auto _check(Res&& res) const noexcept {
            res.error_code(this->api().GetError());
            return std::forward<Res>(res);
        }
    };

    template <typename ObjTag, typename W, W c_api::*GenObjects>
    struct gen_object_func : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().*GenObjects);
        }

        constexpr auto operator()(span<name_type> names) const noexcept {
            return this->_check(this->call(
              this->api().*GenObjects, size_type(names.size()), names.data()));
        }

        constexpr auto operator()() const noexcept {
            name_type n{};
            return this->_check(this->call(this->api().*GenObjects, 1, &n))
              .transformed([&n]() { return al_owned_object_name<ObjTag>(n); });
        }
    };

    // gen_sources
    gen_object_func<source_tag, decltype(c_api::GenSources), &c_api::GenSources>
      gen_sources;

    // gen_buffers
    gen_object_func<buffer_tag, decltype(c_api::GenBuffers), &c_api::GenBuffers>
      gen_buffers;

    // gen_effects
    gen_object_func<effect_tag, decltype(c_api::GenEffects), &c_api::GenEffects>
      gen_effects;

    // gen_filters
    gen_object_func<filter_tag, decltype(c_api::GenFilters), &c_api::GenFilters>
      gen_filters;

    // gen_auxiliary_effect_slots
    gen_object_func<
      auxiliary_effect_slot_tag,
      decltype(c_api::GenAuxiliaryEffectSlots),
      &c_api::GenAuxiliaryEffectSlots>
      gen_auxiliary_effect_slots;

    template <typename ObjTag, typename W, W c_api::*DeleteObjects>
    struct delete_object_func : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().*DeleteObjects);
        }

        constexpr auto operator()(span<const name_type> names) const noexcept {
            return this->_check(this->call(
              this->api().*DeleteObjects,
              size_type(names.size()),
              names.data()));
        }

        constexpr auto operator()(al_owned_object_name<ObjTag>& name) const
          noexcept {
            auto n = name.release();
            return this->_check(this->call(this->api().*DeleteObjects, 1, &n));
        }

        auto raii(al_owned_object_name<ObjTag>& name) noexcept {
            return eagine::finally([this, &name]() { (*this)(name); });
        }

        template <typename Res>
        auto raii_opt(Res& res) noexcept {
            return eagine::finally([this, &res]() {
                if(res) {
                    (*this)(extract(res));
                }
            });
        }
    };

    // delete_sources
    delete_object_func<
      source_tag,
      decltype(c_api::GenSources),
      &c_api::GenSources>
      delete_sources;

    // delete_buffers
    delete_object_func<
      buffer_tag,
      decltype(c_api::GenBuffers),
      &c_api::GenBuffers>
      delete_buffers;

    // delete_effects
    delete_object_func<
      effect_tag,
      decltype(c_api::GenEffects),
      &c_api::GenEffects>
      delete_effects;

    // delete_filters
    delete_object_func<
      filter_tag,
      decltype(c_api::GenFilters),
      &c_api::GenFilters>
      delete_filters;

    // delete_auxiliary_effects
    delete_object_func<
      auxiliary_effect_slot_tag,
      decltype(c_api::GenAuxiliaryEffectSlots),
      &c_api::GenAuxiliaryEffectSlots>
      delete_auxiliary_effect_slots;

    // listener_i
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Listeneri) &&
                   bool(this->api().Listener3i) && bool(this->api().Listeneriv);
        }

        constexpr auto operator()(listener_attribute attr, int_type v0) const
          noexcept {
            return this->_check(
              this->call(this->api().Listeneri, enum_type(attr), v0));
        }

        constexpr auto operator()(
          listener_attribute attr, int_type v0, int_type v1, int_type v2) const
          noexcept {
            return this->_check(
              this->call(this->api().Listener3i, enum_type(attr), v0, v1, v2));
        }

        constexpr auto operator()(
          listener_attribute attr, span<const int_type> v) const noexcept {
            return this->_check(
              this->call(this->api().Listeneriv, enum_type(attr), v.data()));
        }
    } listener_i;

    // listener_f
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Listenerf) &&
                   bool(this->api().Listener3f) && bool(this->api().Listenerfv);
        }

        constexpr auto operator()(listener_attribute attr, float_type v0) const
          noexcept {
            return this->_check(
              this->call(this->api().Listenerf, enum_type(attr), v0));
        }

        constexpr auto operator()(
          listener_attribute attr,
          float_type v0,
          float_type v1,
          float_type v2) const noexcept {
            return this->_check(
              this->call(this->api().Listener3f, enum_type(attr), v0, v1, v2));
        }

        constexpr auto operator()(
          listener_attribute attr, span<const float_type> v) const noexcept {
            return this->_check(
              this->call(this->api().Listenerfv, enum_type(attr), v.data()));
        }
    } listener_f;

    // get_listener_i
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetListeneriv);
        }

        constexpr auto operator()(
          listener_attribute attr, span<int_type> v) const noexcept {
            return this->_check(
              this->call(this->api().GetListeneriv, enum_type(attr), v.data()));
        }
    } get_listener_i;

    // get_listener_f
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetListenerfv);
        }

        constexpr auto operator()(
          listener_attribute attr, span<float_type> v) const noexcept {
            return this->_check(
              this->call(this->api().GetListenerfv, enum_type(attr), v.data()));
        }
    } get_listener_f;

    // source_i
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Sourcei) && bool(this->api().Source3i) &&
                   bool(this->api().Sourceiv);
        }

        constexpr auto operator()(
          source_name src, source_attribute attr, int_type v0) const noexcept {
            return this->_check(this->call(
              this->api().Sourcei, name_type(src), enum_type(attr), v0));
        }

        constexpr auto operator()(
          source_name src,
          source_attribute attr,
          int_type v0,
          int_type v1,
          int_type v2) const noexcept {
            return this->_check(this->call(
              this->api().Source3i,
              name_type(src),
              enum_type(attr),
              v0,
              v1,
              v2));
        }

        constexpr auto operator()(
          source_name src, source_attribute attr, span<const int_type> v) const
          noexcept {
            return this->_check(this->call(
              this->api().Sourceiv, name_type(src), enum_type(attr), v.data()));
        }
    } source_i;

    // source_f
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Sourcef) && bool(this->api().Source3f) &&
                   bool(this->api().Sourcefv);
        }

        constexpr auto operator()(
          source_name src, source_attribute attr, float_type v0) const
          noexcept {
            return this->_check(this->call(
              this->api().Sourcef, name_type(src), enum_type(attr), v0));
        }

        constexpr auto operator()(
          source_name src,
          source_attribute attr,
          float_type v0,
          float_type v1,
          float_type v2) const noexcept {
            return this->_check(this->call(
              this->api().Source3f,
              name_type(src),
              enum_type(attr),
              v0,
              v1,
              v2));
        }

        constexpr auto operator()(
          source_name src,
          source_attribute attr,
          span<const float_type> v) const noexcept {
            return this->_check(this->call(
              this->api().Sourcefv, name_type(src), enum_type(attr), v.data()));
        }
    } source_f;

    // get_source_i
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetSourceiv);
        }

        constexpr auto operator()(
          source_name src, source_attribute attr, span<int_type> v) const
          noexcept {
            return this->_check(this->call(
              this->api().GetSourceiv,
              name_type(src),
              enum_type(attr),
              v.data()));
        }
    } get_source_i;

    // get_source_f
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetSourcefv);
        }

        constexpr auto operator()(
          source_name src, source_attribute attr, span<float_type> v) const
          noexcept {
            return this->_check(this->call(
              this->api().GetSourcefv,
              name_type(src),
              enum_type(attr),
              v.data()));
        }
    } get_source_f;

    // source_queue_buffers
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().SourceQueueBuffers);
        }

        constexpr auto operator()(source_name src, buffer_name buf) const
          noexcept {
            const auto n = name_type(buf);
            return this->_check(this->call(
              this->api().SourceQueueBuffers, name_type(src), 1, &n));
        }

        constexpr auto operator()(
          source_name src, span<const name_type> bufs) const noexcept {
            return this->_check(this->call(
              this->api().SourceQueueBuffers,
              name_type(src),
              size_type(bufs.size()),
              bufs.data()));
        }
    } source_queue_buffers;

    // source_unqueue_buffers
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().SourceUnqueueBuffers);
        }

        constexpr auto operator()(source_name src, buffer_name buf) const
          noexcept {
            auto n = name_type(buf);
            return this->_check(this->call(
              this->api().SourceUnqueueBuffers, name_type(src), 1, &n));
        }

        constexpr auto operator()(source_name src, span<name_type> bufs) const
          noexcept {
            return this->_check(this->call(
              this->api().SourceUnqueueBuffers,
              name_type(src),
              size_type(bufs.size()),
              bufs.data()));
        }
    } source_unqueue_buffers;

    // source_play
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().SourcePlay) &&
                   bool(this->api().SourcePlayv);
        }

        constexpr auto operator()(source_name src) const noexcept {
            return this->_check(
              this->call(this->api().SourcePlay, name_type(src)));
        }

        constexpr auto operator()(span<const name_type> srcs) const noexcept {
            return this->_check(this->call(
              this->api().SourcePlayv, size_type(srcs.size()), srcs.data()));
        }
    } source_play;

    // source_pause
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().SourcePause) &&
                   bool(this->api().SourcePausev);
        }

        constexpr auto operator()(source_name src) const noexcept {
            return this->_check(
              this->call(this->api().SourcePausev, name_type(src)));
        }

        constexpr auto operator()(span<const name_type> srcs) const noexcept {
            return this->_check(this->call(
              this->api().SourcePausev, size_type(srcs.size()), srcs.data()));
        }
    } source_pause;

    // source_stop
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().SourceStop) &&
                   bool(this->api().SourceStopv);
        }

        constexpr auto operator()(source_name src) const noexcept {
            return this->_check(
              this->call(this->api().SourceStop, name_type(src)));
        }

        constexpr auto operator()(span<const name_type> srcs) const noexcept {
            return this->_check(this->call(
              this->api().SourceStopv, size_type(srcs.size()), srcs.data()));
        }
    } source_stop;

    // source_rewind
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().SourceRewind) &&
                   bool(this->api().SourceRewindv);
        }

        constexpr auto operator()(source_name src) const noexcept {
            return this->_check(
              this->call(this->api().SourceRewind, name_type(src)));
        }

        constexpr auto operator()(span<const name_type> srcs) const noexcept {
            return this->_check(this->call(
              this->api().SourceRewindv, size_type(srcs.size()), srcs.data()));
        }
    } source_rewind;

    // get_string
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().GetString);
        }

        constexpr auto operator()(al_string_query query) const noexcept {
            return this->_check(
              this->call(this->api().GetString, enum_type(query)));
        }

        constexpr auto operator()() const noexcept {
            return this->fake(this->api().GetString, "");
        }
    } get_string;

    // get_strings
    auto get_strings(al_string_query query, char separator) noexcept {
        return get_string(query).transformed([separator](auto src) {
            return split_c_str_into_string_list(src, separator);
        });
    }

    // get_extensions
    auto get_extensions() noexcept {
#ifdef AL_EXTENSIONS
        return get_string(al_string_query(AL_EXTENSIONS))
#else
        return get_string()
#endif
          .transformed(
            [](auto src) { return split_c_str_into_string_list(src, ' '); });
    }

    constexpr basic_al_api(api_traits& traits)
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
      , delete_auxiliary_effect_slots(
          "delete_auxiliary_effect_slots", traits, *this)
      , listener_i("listener_i", traits, *this)
      , listener_f("listener_f", traits, *this)
      , get_listener_i("get_listener_i", traits, *this)
      , get_listener_f("get_listener_f", traits, *this)
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
      , get_string("get_string", traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_API_HPP

