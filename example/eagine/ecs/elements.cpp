/**
 *  @example eagine/ecs/elements.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/ecs/basic_manager.hpp>
#include <eagine/ecs/entity/string.hpp>
#include <eagine/ecs/storage/std_map.hpp>
#include <eagine/ecs/storage_caps.hpp>
#include <eagine/embed.hpp>
#include <eagine/main.hpp>
#include <eagine/value_tree/json.hpp>
#include <chrono>
#include <iostream>

namespace eagine {
//------------------------------------------------------------------------------
// Entity type
//------------------------------------------------------------------------------
using element_symbol = std::string;
//------------------------------------------------------------------------------
// Components
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
// Relations
//------------------------------------------------------------------------------
struct isotope : ecs::relation<isotope> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(Isotope);
    }
};
//------------------------------------------------------------------------------
// Usage
//------------------------------------------------------------------------------
static void
print_elements_with_english_name(ecs::basic_manager<element_symbol>& elements) {

    elements.for_each_with<const element_name>(
      [](const auto& sym, ecs::manipulator<const element_name>& name) {
          if(name.has_english_name()) {
              std::cout << sym << ": " << name.get_english_name() << std::endl;
          }
      });
    std::cout << std::endl;
}
//------------------------------------------------------------------------------
static void
print_names_of_noble_gasses(ecs::basic_manager<element_symbol>& elements) {

    elements.for_each_with<const element_name, const element_group>(
      [](
        const auto&,
        ecs::manipulator<const element_name>& name,
        ecs::manipulator<const element_group>& group) {
          if(group.read(&element_group::number) == 18) {
              std::cout << name.get_latin_name() << std::endl;
          }
      });
    std::cout << std::endl;
}
//------------------------------------------------------------------------------
static void
print_names_of_actinides(ecs::basic_manager<element_symbol>& elements) {

    elements.for_each_with_opt<
      const element_name,
      const element_period,
      const element_group>([](
                             const auto&,
                             ecs::manipulator<const element_name>& name,
                             ecs::manipulator<const element_period>& period,
                             ecs::manipulator<const element_group>& group) {
        if(period.read(&element_period::number) == 7) {
            auto opt_grp{group.read(&element_group::number)};
            if(opt_grp.value_or(3) == 3) {
                std::cout << name.get_latin_name() << std::endl;
            }
        }
    });
    std::cout << std::endl;
}
//------------------------------------------------------------------------------
static void
print_isotopes_of_hydrogen(ecs::basic_manager<element_symbol>& elements) {

    elements.for_each_with<const isotope_neutrons>(
      [&](const auto& isot, auto& neutrons) {
          if(elements.has<isotope>("H", isot)) {
              std::cout << isot << ": " << neutrons.read().number;
              if(elements.has<half_life>(isot)) {
                  std::cout << " (radioactive)";
              }
              std::cout << std::endl;
          }
      });
    std::cout << std::endl;
}
//------------------------------------------------------------------------------
template <typename Decay>
void cache_decay_products_of(ecs::basic_manager<element_symbol>& elements) {

    elements.for_each_with<const isotope_neutrons, Decay>(
      [&](const auto& original_i, auto& original_n, auto& decay) {
          elements.for_each_with<const isotope_neutrons>(
            [&](const auto& decayed_i, auto& decayed_n) {
                if(
                  original_n->number + decay->neutron_count_diff() ==
                  decayed_n->number) {
                    elements.for_each_with<const element_protons>(
                      [&](const auto& original_e, auto& original_p) {
                          if(elements.has<isotope>(original_e, original_i)) {
                              elements.for_each_with<const element_protons>(
                                [&](const auto& decayed_e, auto& decayed_p) {
                                    if(elements.has<isotope>(
                                         decayed_e, decayed_i)) {
                                        if(
                                          original_p->number +
                                            decay->proton_count_diff() ==
                                          decayed_p->number) {
                                            decay->product = decayed_i;
                                        }
                                    }
                                });
                          }
                      });
                }
            });
      });
}
//------------------------------------------------------------------------------
static void cache_decay_products(ecs::basic_manager<element_symbol>& elements) {
    cache_decay_products_of<alpha_decay>(elements);
    cache_decay_products_of<proton_emission>(elements);
    cache_decay_products_of<neutron_emission>(elements);
    cache_decay_products_of<electron_capture>(elements);
    cache_decay_products_of<beta_m_decay>(elements);
    cache_decay_products_of<beta_m2_decay>(elements);
    cache_decay_products_of<beta_m_alpha_decay>(elements);
    cache_decay_products_of<beta_m_n_decay>(elements);
    cache_decay_products_of<beta_p_decay>(elements);
    cache_decay_products_of<beta_p_alpha_decay>(elements);
    cache_decay_products_of<beta_p_p_decay>(elements);
}
//------------------------------------------------------------------------------
void populate(
  ecs::basic_manager<element_symbol>& elements,
  valtree::compound source);
//------------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    ctx.log().info("starting");

    using ecs::std_map_cmp_storage;
    using ecs::std_map_rel_storage;

    ecs::basic_manager<element_symbol> elements;
    elements.register_component_storage<std_map_cmp_storage, element_name>();
    elements.register_component_storage<std_map_cmp_storage, element_protons>();
    elements.register_component_storage<std_map_cmp_storage, isotope_neutrons>();
    elements.register_component_storage<std_map_cmp_storage, element_period>();
    elements.register_component_storage<std_map_cmp_storage, element_group>();
    elements.register_component_storage<std_map_cmp_storage, atomic_weight>();
    elements.register_component_storage<std_map_cmp_storage, half_life>();
    elements.register_component_storage<std_map_cmp_storage, alpha_decay>();
    elements.register_component_storage<std_map_cmp_storage, proton_emission>();
    elements.register_component_storage<std_map_cmp_storage, neutron_emission>();
    elements.register_component_storage<std_map_cmp_storage, electron_capture>();
    elements.register_component_storage<std_map_cmp_storage, beta_m_decay>();
    elements.register_component_storage<std_map_cmp_storage, beta_m2_decay>();
    elements
      .register_component_storage<std_map_cmp_storage, beta_m_alpha_decay>();
    elements.register_component_storage<std_map_cmp_storage, beta_m_n_decay>();
    elements.register_component_storage<std_map_cmp_storage, beta_p_decay>();
    elements
      .register_component_storage<std_map_cmp_storage, beta_p_alpha_decay>();
    elements.register_component_storage<std_map_cmp_storage, beta_p_p_decay>();

    elements.register_relation_storage<std_map_rel_storage, isotope>();

    const auto json_res{embed(EAGINE_ID(ElemJSON), "elements.json")};

    auto json_tree{
      valtree::from_json_text(as_chars(json_res.unpack(ctx)), ctx.log())};

    populate(elements, json_tree);
    cache_decay_products(elements);

    print_elements_with_english_name(elements);
    print_names_of_noble_gasses(elements);
    print_names_of_actinides(elements);
    print_isotopes_of_hydrogen(elements);

    return 0;
}
//------------------------------------------------------------------------------
void populate(
  ecs::basic_manager<element_symbol>& elements,
  valtree::compound source) {

    const auto elem_root{source.structure()};
    const auto elem_count = source.nested_count(elem_root);
    for(span_size_t e = 0; e < elem_count; ++e) {
        const auto elem_attr{source.nested(elem_root, e)};
        const element_symbol elem{to_string(elem_attr.name())};

        if(auto name_a{source.nested(elem_attr, "name")}) {
            std::string latin;
            if(auto latin_a{source.nested(name_a, "latin")}) {
                source.fetch_value(latin_a, latin);
            }
            std::string english;
            if(auto english_a{source.nested(name_a, "english")}) {
                source.fetch_value(english_a, english);
            }
            elements.add(elem, element_name(latin, english));
        }
        if(auto protons_a{source.nested(elem_attr, "protons")}) {
            if(auto number{source.get(protons_a, identity<short>())}) {
                elements.add(elem, element_protons(extract(number)));
            }
        }
        if(auto period_a{source.nested(elem_attr, "period")}) {
            if(auto number{source.get(period_a, identity<short>())}) {
                elements.add(elem, element_period(extract(number)));
            }
        }
        if(auto group_a{source.nested(elem_attr, "group")}) {
            if(auto number{source.get(group_a, identity<short>())}) {
                elements.add(elem, element_group(extract(number)));
            }
        }
        if(auto atomic_weight_a{source.nested(elem_attr, "atomic_weight")}) {
            if(auto number{source.get(atomic_weight_a, identity<float>())}) {
                elements.add(elem, atomic_weight(extract(number)));
            }
        }

        if(auto isot_root{source.nested(elem_attr, "isotopes")}) {
            const auto isot_count = source.nested_count(isot_root);
            for(span_size_t i = 0; i < isot_count; ++i) {
                const auto isot_attr{source.nested(isot_root, i)};

                element_symbol isot;
                if(auto symbol_a{source.nested(isot_attr, "symbol")}) {
                    source.fetch_value(symbol_a, isot);
                }
                if(isot.empty()) {
                    break;
                }

                if(auto name_a{source.nested(isot_attr, "name")}) {
                    std::string latin;
                    if(auto latin_a{source.nested(name_a, "latin")}) {
                        source.fetch_value(latin_a, latin);
                    }
                    std::string english;
                    if(auto english_a{source.nested(name_a, "english")}) {
                        source.fetch_value(english_a, english);
                    }
                    elements.add(isot, element_name(latin, english));
                }
                if(auto neutrons_a{source.nested(isot_attr, "neutrons")}) {
                    if(auto number{source.get(neutrons_a, identity<short>())}) {
                        elements.add(isot, isotope_neutrons(extract(number)));
                    }
                }
                if(auto half_life_a{source.nested(isot_attr, "half_life")}) {
                    if(auto years_a{source.nested(half_life_a, "years")}) {
                        if(auto x{source.get(years_a, identity<float>())}) {
                            elements.add(isot, half_life::years(extract(x)));
                        }
                    }
                    if(auto days_a{source.nested(half_life_a, "days")}) {
                        if(auto x{source.get(days_a, identity<float>())}) {
                            elements.add(isot, half_life::days(extract(x)));
                        }
                    }
                    if(auto hours_a{source.nested(half_life_a, "hours")}) {
                        if(auto x{source.get(hours_a, identity<float>())}) {
                            elements.add(isot, half_life::hours(extract(x)));
                        }
                    }
                    if(auto minutes_a{source.nested(half_life_a, "minutes")}) {
                        if(auto x{source.get(minutes_a, identity<float>())}) {
                            elements.add(isot, half_life::minutes(extract(x)));
                        }
                    }
                    if(auto seconds_a{source.nested(half_life_a, "seconds")}) {
                        if(auto x{source.get(seconds_a, identity<float>())}) {
                            elements.add(isot, half_life::seconds(extract(x)));
                        }
                    }
                    if(auto milliseconds_a{
                         source.nested(half_life_a, "milliseconds")}) {
                        if(auto x{
                             source.get(milliseconds_a, identity<float>())}) {
                            elements.add(
                              isot, half_life::milliseconds(extract(x)));
                        }
                    }
                }
                if(auto decay_a{source.nested(isot_attr, "alpha_decay")}) {
                    elements.add(isot, alpha_decay());
                }
                if(auto decay_a{source.nested(isot_attr, "proton_emission")}) {
                    elements.add(isot, proton_emission());
                }
                if(auto decay_a{source.nested(isot_attr, "neutron_emission")}) {
                    elements.add(isot, neutron_emission());
                }
                if(auto decay_a{source.nested(isot_attr, "electron_capture")}) {
                    elements.add(isot, electron_capture());
                }
                if(auto decay_a{source.nested(isot_attr, "beta_m_decay")}) {
                    elements.add(isot, beta_m_decay());
                }
                if(auto decay_a{source.nested(isot_attr, "beta_m2_decay")}) {
                    elements.add(isot, beta_m2_decay());
                }
                if(auto decay_a{
                     source.nested(isot_attr, "beta_m_alpha_decay")}) {
                    elements.add(isot, beta_m_alpha_decay());
                }
                if(auto decay_a{source.nested(isot_attr, "beta_m_n_decay")}) {
                    elements.add(isot, beta_m_n_decay());
                }
                if(auto decay_a{source.nested(isot_attr, "beta_p_decay")}) {
                    elements.add(isot, beta_p_decay());
                }
                if(auto decay_a{
                     source.nested(isot_attr, "beta_p_alpha_decay")}) {
                    elements.add(isot, beta_p_alpha_decay());
                }
                if(auto decay_a{source.nested(isot_attr, "beta_p_p_decay")}) {
                    elements.add(isot, beta_p_p_decay());
                }

                elements.add_relation<isotope>(elem, isot);
            }
        }
    }
}

} // namespace eagine
