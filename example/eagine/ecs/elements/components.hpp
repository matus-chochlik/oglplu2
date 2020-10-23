/**
 *  @example eagine/ecs/elements/components.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_EXAMPLE_ECS_COMPONENTS_HPP // NOLINT(llvm-header-guard)
#define EAGINE_EXAMPLE_ECS_COMPONENTS_HPP

#include "entity.hpp"
#include <eagine/ecs/component.hpp>
#include <eagine/ecs/manipulator.hpp>
#include <eagine/identifier.hpp>
#include <chrono>

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
struct alpha_decay : ecs::component<alpha_decay> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(AlphaDcy);
    }

    static auto symbol() noexcept -> string_view {
        return {"α"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return -2;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return -2;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct proton_emission : ecs::component<proton_emission> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(PrtnEmissn);
    }

    static auto symbol() noexcept -> string_view {
        return {"p"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return -1;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return 0;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct neutron_emission : ecs::component<neutron_emission> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(NtrnEmissn);
    }

    static auto symbol() noexcept -> string_view {
        return {"n"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return 0;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return -1;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct electron_capture : ecs::component<electron_capture> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(ElnCapDcy);
    }

    static auto symbol() noexcept -> string_view {
        return {"+e⁻"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return -1;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return 1;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct electron2_capture : ecs::component<electron2_capture> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(2ElnCapDcy);
    }

    static auto symbol() noexcept -> string_view {
        return {"+2e⁻"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return -2;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return 2;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct beta_m_decay : ecs::component<beta_m_decay> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(BetaMDcy);
    }

    static auto symbol() noexcept -> string_view {
        return {"β⁻"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return 1;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return -1;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct beta_m2_decay : ecs::component<beta_m2_decay> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(BetaM2Dcy);
    }

    static auto symbol() noexcept -> string_view {
        return {"β⁻,β⁻"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return 2;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return -2;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct beta_m_alpha_decay : ecs::component<beta_m_alpha_decay> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(BtaMAlpDcy);
    }

    static auto symbol() noexcept -> string_view {
        return {"β⁻,α"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return -1;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return -3;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct beta_m_n_decay : ecs::component<beta_m_n_decay> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(BetaMNDcy);
    }

    static auto symbol() noexcept -> string_view {
        return {"β⁻,n"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return 1;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return -2;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct beta_m_n2_decay : ecs::component<beta_m_n2_decay> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(BetaMN2Dcy);
    }

    static auto symbol() noexcept -> string_view {
        return {"β⁻,2n"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return 1;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return -3;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct beta_p_decay : ecs::component<beta_p_decay> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(BetaPDcy);
    }

    static auto symbol() noexcept -> string_view {
        return {"β⁺"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return -1;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return 1;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct beta_p_alpha_decay : ecs::component<beta_p_alpha_decay> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(BtaPAlpDcy);
    }

    static auto symbol() noexcept -> string_view {
        return {"β⁺,α"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return -3;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return -1;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct beta_p_p_decay : ecs::component<beta_p_p_decay> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(BetaPPDcy);
    }

    static auto symbol() noexcept -> string_view {
        return {"β⁺,p"};
    }

    static constexpr auto proton_count_diff() noexcept -> short {
        return -2;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return 1;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif
