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

    using bool_type = typename al_types::char_type;
    using char_type = typename al_types::char_type;
    using enum_type = typename al_types::enum_type;
    using name_type = typename al_types::name_type;
    using size_type = typename al_types::size_type;

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
      , get_string("get_string", traits, *this) {
    }
};
//------------------------------------------------------------------------------
} // namespace oalp
} // namespace eagine

#endif // OALPLUS_AL_API_API_HPP

