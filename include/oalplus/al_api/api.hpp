/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OALPLUS_AL_API_API_HPP
#define OALPLUS_AL_API_API_HPP

#include "c_api.hpp"
#include "enum_types.hpp"
#include "object_name.hpp"
#include <eagine/scope_exit.hpp>
#include <eagine/string_list.hpp>

namespace eagine::oalp {
//------------------------------------------------------------------------------
#define OALPAFP(FUNC) decltype(c_api::FUNC), &c_api::FUNC
//------------------------------------------------------------------------------
/// @brief Class wrapping the functions from the AL API.
/// @ingroup al_api_wrap
/// @see basic_al_constants
/// @see basic_al_c_api
template <typename ApiTraits>
class basic_al_operations : public basic_al_c_api<ApiTraits> {

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

    template <typename W, W c_api::*F, typename Signature = typename W::signature>
    class func;

    template <typename W, W c_api::*F, typename RVC, typename... Params>
    class func<W, F, RVC(Params...)>
      : public wrapped_c_api_function<c_api, api_traits, nothing_t, W, F> {
        using base = wrapped_c_api_function<c_api, api_traits, nothing_t, W, F>;

    private:
        template <typename Res>
        constexpr auto _check(Res&& res) const noexcept {
            res.error_code(this->api().GetError());
            return std::forward<Res>(res);
        }

    protected:
        template <typename... Args>
        constexpr auto _chkcall(Args&&... args) const noexcept {
            return this->_check(this->_call(std::forward<Args>(args)...));
        }

        using base::_conv;

    public:
        using base::base;

        constexpr auto operator()(Params... params) const noexcept {
            return this->_chkcall(_conv(params)...)
              .cast_to(type_identity<RVC>{});
        }
    };

    template <typename ObjTag, typename W, W c_api::*GenObjects>
    struct gen_object_func : func<W, GenObjects> {
        using func<W, GenObjects>::func;

        constexpr auto operator()(span<name_type> names) const noexcept {
            return this->_chkcall(size_type(names.size()), names.data());
        }

        constexpr auto operator()() const noexcept {
            name_type n{};
            return this->_chkcall(1, &n).transformed(
              [&n]() { return al_owned_object_name<ObjTag>(n); });
        }
    };

    // gen_sources
    gen_object_func<source_tag, OALPAFP(GenSources)> gen_sources;

    // gen_buffers
    gen_object_func<buffer_tag, OALPAFP(GenBuffers)> gen_buffers;

    // gen_effects
    gen_object_func<effect_tag, OALPAFP(GenEffects)> gen_effects;

    // gen_filters
    gen_object_func<filter_tag, OALPAFP(GenFilters)> gen_filters;

    // gen_auxiliary_effect_slots
    gen_object_func<auxiliary_effect_slot_tag, OALPAFP(GenAuxiliaryEffectSlots)>
      gen_auxiliary_effect_slots;

    template <typename ObjTag, typename W, W c_api::*DeleteObjects>
    struct delete_object_func : func<W, DeleteObjects> {
        using func<W, DeleteObjects>::func;

        constexpr auto operator()(span<const name_type> names) const noexcept {
            return this->_chkcall(size_type(names.size()), names.data());
        }

        constexpr auto
        operator()(al_owned_object_name<ObjTag>& name) const noexcept {
            auto n = name.release();
            return this->_chkcall(1, &n);
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
    delete_object_func<source_tag, OALPAFP(DeleteSources)> delete_sources;

    // delete_buffers
    delete_object_func<buffer_tag, OALPAFP(DeleteBuffers)> delete_buffers;

    // delete_effects
    delete_object_func<effect_tag, OALPAFP(DeleteEffects)> delete_effects;

    // delete_filters
    delete_object_func<filter_tag, OALPAFP(DeleteFilters)> delete_filters;

    // delete_auxiliary_effect_slots
    delete_object_func<
      auxiliary_effect_slot_tag,
      OALPAFP(DeleteAuxiliaryEffectSlots)>
      delete_auxiliary_effect_slots;

    template <typename ObjTag, typename W, W c_api::*IsObject>
    struct is_object_func : func<W, IsObject> {
        using func<W, IsObject>::func;

        constexpr auto operator()(al_object_name<ObjTag> name) const noexcept {
            return this->_chkcall(name_type(name));
        }
    };

    // is_source
    is_object_func<source_tag, OALPAFP(IsSource)> is_source;

    // is_buffer
    is_object_func<buffer_tag, OALPAFP(IsBuffer)> is_buffer;

    // is_effect
    is_object_func<effect_tag, OALPAFP(IsEffect)> is_effect;

    // is_filter
    is_object_func<filter_tag, OALPAFP(IsFilter)> is_filter;

    // is_auxiliary_effect_slot
    is_object_func<auxiliary_effect_slot_tag, OALPAFP(IsAuxiliaryEffectSlot)>
      is_auxiliary_effect_slot;

    // listener_i
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Listeneri) &&
                   bool(this->api().Listener3i) && bool(this->api().Listeneriv);
        }

        constexpr auto
        operator()(listener_attribute attr, int_type v0) const noexcept {
            return this->_check(
              this->_call(this->api().Listeneri, enum_type(attr), v0));
        }

        constexpr auto operator()(
          listener_attribute attr,
          int_type v0,
          int_type v1,
          int_type v2) const noexcept {
            return this->_check(
              this->_call(this->api().Listener3i, enum_type(attr), v0, v1, v2));
        }

        constexpr auto operator()(
          listener_attribute attr,
          span<const int_type> v) const noexcept {
            return this->_check(
              this->_call(this->api().Listeneriv, enum_type(attr), v.data()));
        }
    } listener_i;

    // listener_f
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Listenerf) &&
                   bool(this->api().Listener3f) && bool(this->api().Listenerfv);
        }

        constexpr auto
        operator()(listener_attribute attr, float_type v0) const noexcept {
            return this->_check(
              this->_call(this->api().Listenerf, enum_type(attr), v0));
        }

        constexpr auto operator()(
          listener_attribute attr,
          float_type v0,
          float_type v1,
          float_type v2) const noexcept {
            return this->_check(
              this->_call(this->api().Listener3f, enum_type(attr), v0, v1, v2));
        }

        constexpr auto operator()(
          listener_attribute attr,
          span<const float_type> v) const noexcept {
            return this->_check(
              this->_call(this->api().Listenerfv, enum_type(attr), v.data()));
        }
    } listener_f;

    // get_listener_i
    struct : func<OALPAFP(GetListeneriv)> {
        using func<OALPAFP(GetListeneriv)>::func;

        constexpr auto
        operator()(listener_attribute attr, span<int_type> v) const noexcept {
            return this->_chkcall(enum_type(attr), v.data());
        }
    } get_listener_i;

    // get_listener_f
    struct : func<OALPAFP(GetListenerfv)> {
        using func<OALPAFP(GetListenerfv)>::func;

        constexpr auto
        operator()(listener_attribute attr, span<float_type> v) const noexcept {
            return this->_chkcall(enum_type(attr), v.data());
        }
    } get_listener_f;

    // buffer_i
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Bufferi) && bool(this->api().Buffer3i) &&
                   bool(this->api().Bufferiv);
        }

        constexpr auto operator()(
          buffer_name src,
          buffer_attribute attr,
          int_type v0) const noexcept {
            return this->_check(this->_call(
              this->api().Bufferi, name_type(src), enum_type(attr), v0));
        }

        constexpr auto operator()(
          buffer_name src,
          buffer_attribute attr,
          int_type v0,
          int_type v1,
          int_type v2) const noexcept {
            return this->_check(this->_call(
              this->api().Buffer3i,
              name_type(src),
              enum_type(attr),
              v0,
              v1,
              v2));
        }

        constexpr auto operator()(
          buffer_name src,
          buffer_attribute attr,
          span<const int_type> v) const noexcept {
            return this->_check(this->_call(
              this->api().Bufferiv, name_type(src), enum_type(attr), v.data()));
        }
    } buffer_i;

    // buffer_f
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Bufferf) && bool(this->api().Buffer3f) &&
                   bool(this->api().Bufferfv);
        }

        constexpr auto operator()(
          buffer_name src,
          buffer_attribute attr,
          float_type v0) const noexcept {
            return this->_check(this->_call(
              this->api().Bufferf, name_type(src), enum_type(attr), v0));
        }

        constexpr auto operator()(
          buffer_name src,
          buffer_attribute attr,
          float_type v0,
          float_type v1,
          float_type v2) const noexcept {
            return this->_check(this->_call(
              this->api().Buffer3f,
              name_type(src),
              enum_type(attr),
              v0,
              v1,
              v2));
        }

        constexpr auto operator()(
          buffer_name src,
          buffer_attribute attr,
          span<const float_type> v) const noexcept {
            return this->_check(this->_call(
              this->api().Bufferfv, name_type(src), enum_type(attr), v.data()));
        }
    } buffer_f;

    // get_buffer_i
    struct : func<OALPAFP(GetBufferiv)> {
        using func<OALPAFP(GetBufferiv)>::func;

        constexpr auto operator()(
          buffer_name src,
          buffer_attribute attr,
          span<int_type> v) const noexcept {
            return this->_chkcall(name_type(src), enum_type(attr), v.data());
        }
    } get_buffer_i;

    // get_buffer_f
    struct : func<OALPAFP(GetBufferfv)> {
        using func<OALPAFP(GetBufferfv)>::func;

        constexpr auto operator()(
          buffer_name src,
          buffer_attribute attr,
          span<float_type> v) const noexcept {
            return this->_chkcall(name_type(src), enum_type(attr), v.data());
        }
    } get_buffer_f;

    // source_i
    struct : derived_func {
        using derived_func::derived_func;

        explicit constexpr operator bool() const noexcept {
            return bool(this->api().Sourcei) && bool(this->api().Source3i) &&
                   bool(this->api().Sourceiv);
        }

        constexpr auto operator()(
          source_name src,
          source_attribute attr,
          int_type v0) const noexcept {
            return this->_check(this->_call(
              this->api().Sourcei, name_type(src), enum_type(attr), v0));
        }

        constexpr auto operator()(
          source_name src,
          source_attribute attr,
          int_type v0,
          int_type v1,
          int_type v2) const noexcept {
            return this->_check(this->_call(
              this->api().Source3i,
              name_type(src),
              enum_type(attr),
              v0,
              v1,
              v2));
        }

        constexpr auto operator()(
          source_name src,
          source_attribute attr,
          span<const int_type> v) const noexcept {
            return this->_check(this->_call(
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
          source_name src,
          source_attribute attr,
          float_type v0) const noexcept {
            return this->_check(this->_call(
              this->api().Sourcef, name_type(src), enum_type(attr), v0));
        }

        constexpr auto operator()(
          source_name src,
          source_attribute attr,
          float_type v0,
          float_type v1,
          float_type v2) const noexcept {
            return this->_check(this->_call(
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
            return this->_check(this->_call(
              this->api().Sourcefv, name_type(src), enum_type(attr), v.data()));
        }
    } source_f;

    // get_source_i
    struct : func<OALPAFP(GetSourceiv)> {
        using func<OALPAFP(GetSourceiv)>::func;

        constexpr auto operator()(
          source_name src,
          source_attribute attr,
          span<int_type> v) const noexcept {
            return this->_chkcall(name_type(src), enum_type(attr), v.data());
        }
    } get_source_i;

    // get_source_f
    struct : func<OALPAFP(GetSourcefv)> {
        using func<OALPAFP(GetSourcefv)>::func;

        constexpr auto operator()(
          source_name src,
          source_attribute attr,
          span<float_type> v) const noexcept {
            return this->_chkcall(name_type(src), enum_type(attr), v.data());
        }
    } get_source_f;

    // source_queue_buffers
    struct : func<OALPAFP(SourceQueueBuffers)> {
        using func<OALPAFP(SourceQueueBuffers)>::func;

        constexpr auto
        operator()(source_name src, buffer_name buf) const noexcept {
            const auto n = name_type(buf);
            return this->_chkcall(name_type(src), 1, &n);
        }

        constexpr auto
        operator()(source_name src, span<const name_type> bufs) const noexcept {
            return this->_chkcall(
              name_type(src), size_type(bufs.size()), bufs.data());
        }
    } source_queue_buffers;

    // source_unqueue_buffers
    struct : func<OALPAFP(SourceUnqueueBuffers)> {
        using func<OALPAFP(SourceUnqueueBuffers)>::func;

        constexpr auto
        operator()(source_name src, buffer_name buf) const noexcept {
            auto n = name_type(buf);
            return this->_chkcall(name_type(src), 1, &n);
        }

        constexpr auto
        operator()(source_name src, span<name_type> bufs) const noexcept {
            return this->_chkcall(
              name_type(src), size_type(bufs.size()), bufs.data());
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
              this->_call(this->api().SourcePlay, name_type(src)));
        }

        constexpr auto operator()(span<const name_type> srcs) const noexcept {
            return this->_check(this->_call(
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
              this->_call(this->api().SourcePause, name_type(src)));
        }

        constexpr auto operator()(span<const name_type> srcs) const noexcept {
            return this->_check(this->_call(
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
              this->_call(this->api().SourceStop, name_type(src)));
        }

        constexpr auto operator()(span<const name_type> srcs) const noexcept {
            return this->_check(this->_call(
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
              this->_call(this->api().SourceRewind, name_type(src)));
        }

        constexpr auto operator()(span<const name_type> srcs) const noexcept {
            return this->_check(this->_call(
              this->api().SourceRewindv, size_type(srcs.size()), srcs.data()));
        }
    } source_rewind;

    // get_string
    struct : func<OALPAFP(GetString)> {
        using func<OALPAFP(GetString)>::func;

        constexpr auto operator()(al_string_query query) const noexcept {
            return this->_chkcall(enum_type(query))
              .cast_to(type_identity<string_view>{});
        }

        constexpr auto operator()() const noexcept {
            return this->_fake_empty_c_str().cast_to(
              type_identity<string_view>{});
        }
    } get_string;

    // get_strings
    auto get_strings(al_string_query query, char separator) noexcept {
        return get_string(query).transformed([separator](auto src) {
            return split_into_string_list(src, separator);
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
            [](auto src) { return split_into_string_list(src, ' '); });
    }

    basic_al_operations(api_traits& traits);
};
//------------------------------------------------------------------------------
#undef OALPAFP
//------------------------------------------------------------------------------
} // namespace eagine::oalp

#endif // OALPLUS_AL_API_API_HPP
