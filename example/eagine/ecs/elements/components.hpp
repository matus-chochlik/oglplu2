/// @example eagine/ecs/elements/components.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef EAGINE_EXAMPLE_ECS_COMPONENTS_HPP // NOLINT(llvm-header-guard)
#define EAGINE_EXAMPLE_ECS_COMPONENTS_HPP

#include "decay_modes.hpp"
#include "entity.hpp"
#include <eagine/ecs/component.hpp>
#include <eagine/ecs/manipulator.hpp>
#include <eagine/identifier.hpp>
#include <chrono>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
struct element_name : ecs::component<element_name> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(Name);
    }

    std::string latin;
    std::string english;

    element_name() = default;

    element_name(std::string lat, std::string eng)
      : latin{std::move(lat)}
      , english{std::move(eng)} {}

    element_name(std::string lat)
      : latin{std::move(lat)} {}
};
//------------------------------------------------------------------------------
template <bool Const>
struct element_name_manip : ecs::basic_manipulator<element_name, Const> {
    using ecs::basic_manipulator<element_name, Const>::basic_manipulator;

    auto get_latin_name() const -> const std::string& {
        return this->read().latin;
    }

    auto get_english_name() const -> const std::string& {
        const auto& name = this->read().english;
        if(name.empty()) {
            return this->read().latin;
        }
        return name;
    }

    auto has_english_name() const -> bool {
        return !this->read().english.empty();
    }
};
namespace ecs {
template <bool Const>
struct get_manipulator<element_name, Const> {
    using type = element_name_manip<Const>;
};
} // namespace ecs
//------------------------------------------------------------------------------
struct element_protons : ecs::component<element_protons> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(Protons);
    }

    short number{0};

    element_protons() noexcept = default;

    element_protons(short n)
      : number{n} {}
};
//------------------------------------------------------------------------------
struct isotope_neutrons : ecs::component<isotope_neutrons> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(Neutrons);
    }

    short number{0};

    isotope_neutrons() noexcept = default;

    isotope_neutrons(short n)
      : number{n} {}
};
//------------------------------------------------------------------------------
struct element_period : ecs::component<element_period> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(Period);
    }

    short number{0};

    element_period() noexcept = default;

    element_period(short n)
      : number{n} {}
};
//------------------------------------------------------------------------------
struct element_group : ecs::component<element_group> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(Group);
    }

    short number{0};

    element_group() noexcept = default;

    element_group(short n)
      : number{n} {}
};
//------------------------------------------------------------------------------
struct atomic_weight : ecs::component<atomic_weight> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(AtomWeight);
    }

    float value{0.F};

    atomic_weight() noexcept = default;

    atomic_weight(float w)
      : value{w} {}
};
//------------------------------------------------------------------------------
struct half_life : ecs::component<half_life> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(HalfLife);
    }

    std::chrono::duration<float> time_seconds;

    half_life() noexcept = default;

    template <typename R, typename P>
    half_life(std::chrono::duration<R, P> hl)
      : time_seconds{hl} {}

    static auto milliseconds(float ms) noexcept -> half_life {
        return {std::chrono::duration<float, std::ratio<1LL, 1000LL>>{ms}};
    }

    static auto seconds(float s) noexcept -> half_life {
        return {std::chrono::duration<float, std::ratio<1LL, 1LL>>{s}};
    }

    static auto minutes(float m) noexcept -> half_life {
        return {std::chrono::duration<float, std::ratio<60LL, 1LL>>{m}};
    }

    static auto hours(float h) noexcept -> half_life {
        return {std::chrono::duration<float, std::ratio<3600LL, 1LL>>{h}};
    }

    static auto days(float d) noexcept -> half_life {
        return {std::chrono::duration<float, std::ratio<86400LL, 1LL>>{d}};
    }

    static auto years(float y) noexcept -> half_life {
        return {std::chrono::duration<float, std::ratio<31556952LL, 1LL>>{y}};
    }
};
//------------------------------------------------------------------------------
struct decay {
    std::vector<element_symbol> products;
};
//------------------------------------------------------------------------------
class decay_modes : ecs::component<decay_modes> {
public:
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(DecayModes);
    }

    auto add(string_view symbol) -> decay* {
        int nv = 0;
        if(auto nid{known_decay_modes::get_id(symbol)}) {
            for(auto& [id, v, info] : _modes) {
                if(nid == id) {
                    nv = nv + 1;
                }
            }
            _modes.push_back({nid, nv, {}});
            return &std::get<2>(_modes.back());
        }
        return nullptr;
    }

    template <typename Function>
    void for_each(const Function& func) {
        for(auto& [id, v, info] : _modes) {
            EAGINE_MAYBE_UNUSED(v);
            if(auto mode_info{known_decay_modes::get_info(id)}) {
                func(*mode_info, info);
            }
        }
    }

    template <typename Function>
    void for_each(const Function& func) const {
        for(const auto& [id, v, info] : _modes) {
            EAGINE_MAYBE_UNUSED(v);
            if(auto mode_info{known_decay_modes::get_info(id)}) {
                func(*mode_info, info);
            }
        }
    }

private:
    std::vector<std::tuple<identifier_t, int, decay>> _modes;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif
