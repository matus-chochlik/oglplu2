/**
 *  @example eagine/ecs_elements.cpp
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
#include <eagine/main.hpp>
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

    static constexpr auto proton_count_diff() noexcept -> short {
        return 1;
    }

    static constexpr auto neutron_count_diff() noexcept -> short {
        return -1;
    }

    element_symbol product;
};
//------------------------------------------------------------------------------
struct beta_m_n_decay : ecs::component<beta_m_n_decay> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(BetaMNDcy);
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

    static constexpr auto proton_count_diff() noexcept -> short {
        return -1;
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

    elements.for_each_with<const element_name, const isotope_neutrons>(
      [&](
        const auto& isot,
        ecs::manipulator<const element_name>& name,
        ecs::manipulator<const isotope_neutrons>& neutrons) {
          if(elements.has<isotope>("H", isot)) {
              std::cout << name.get_latin_name() << ": "
                        << neutrons.read().number;
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
      [&](
        const auto& original_i,
        ecs::manipulator<const isotope_neutrons>& original_n,
        ecs::manipulator<Decay>& decay) {
          elements.for_each_with<const isotope_neutrons>(
            [&](
              const auto& decayed_i,
              ecs::manipulator<const isotope_neutrons>& decayed_n) {
                if(
                  original_n.read().number +
                    decay.read().neutron_count_diff() ==
                  decayed_n.read().number) {
                    elements.for_each_with<const element_protons>(
                      [&](
                        const auto& original_e,
                        ecs::manipulator<const element_protons>& original_p) {
                          if(elements.has<isotope>(original_e, original_i)) {
                              elements.for_each_with<const element_protons>(
                                [&](
                                  const auto& decayed_e,
                                  ecs::manipulator<const element_protons>&
                                    decayed_p) {
                                    if(elements.has<isotope>(
                                         decayed_e, decayed_i)) {
                                        if(
                                          original_p.read().number +
                                            decay.read().proton_count_diff() ==
                                          decayed_p.read().number) {
                                            decay.write().product = decayed_i;
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
}
//------------------------------------------------------------------------------
void populate(ecs::basic_manager<element_symbol>& elements);
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

    elements.register_relation_storage<std_map_rel_storage, isotope>();

    populate(elements);
    cache_decay_products(elements);

    print_elements_with_english_name(elements);
    print_names_of_noble_gasses(elements);
    print_names_of_actinides(elements);
    print_isotopes_of_hydrogen(elements);

    return 0;
}
//------------------------------------------------------------------------------
void populate(ecs::basic_manager<element_symbol>& elements) {
    elements.add(
      "H",
      element_name("Hydrogenium", "Hydrogen"),
      element_protons(1),
      element_period(1),
      element_group(1),
      atomic_weight(1.F));

    elements.add("¹H", element_name("Protium"), isotope_neutrons(0));
    elements.add("²H", element_name("Deuterium"), isotope_neutrons(1));
    elements.add(
      "³H",
      element_name("Tritium"),
      isotope_neutrons(2),
      half_life::years(12.32F));
    elements.add(
      "⁴H",
      isotope_neutrons(3),
      half_life::seconds(1.39e-22F),
      neutron_emission());

    elements.add_relation<isotope>("H", "¹H");
    elements.add_relation<isotope>("H", "²H");
    elements.add_relation<isotope>("H", "³H");
    elements.add_relation<isotope>("H", "⁴H");

    elements.add(
      "He",
      element_name("Helium"),
      element_protons(2),
      element_period(1),
      element_group(18),
      atomic_weight(4.002602F));

    elements.add("³He", isotope_neutrons(1));
    elements.add("⁴He", isotope_neutrons(2));
    elements.add(
      "⁵He",
      isotope_neutrons(3),
      half_life::seconds(700.e-24F),
      neutron_emission());
    elements.add(
      "⁶He",
      isotope_neutrons(4),
      half_life::milliseconds(806.92F),
      beta_m_decay(),
      beta_m_alpha_decay());
    elements.add(
      "⁷He",
      isotope_neutrons(5),
      half_life::seconds(2.51e-21F),
      neutron_emission());

    elements.add_relation<isotope>("He", "³He");
    elements.add_relation<isotope>("He", "⁴He");
    elements.add_relation<isotope>("He", "⁵He");
    elements.add_relation<isotope>("He", "⁶He");
    elements.add_relation<isotope>("He", "⁷He");

    elements.add(
      "Li",
      element_name("Lithium"),
      element_protons(3),
      element_period(2),
      element_group(1),
      atomic_weight(6.94F));

    elements.add(
      "⁵Li",
      isotope_neutrons(2),
      half_life::seconds(370.e-24F),
      proton_emission());
    elements.add("⁶Li", isotope_neutrons(3));
    elements.add("⁷Li", isotope_neutrons(4));
    elements.add(
      "⁸Li",
      isotope_neutrons(5),
      half_life::milliseconds(839.40F),
      beta_m_decay());
    elements.add(
      "⁹Li",
      isotope_neutrons(6),
      half_life::milliseconds(178.3F),
      beta_m_decay(),
      beta_m_n_decay());
    elements.add(
      "¹⁰Li",
      isotope_neutrons(7),
      half_life::seconds(2.e-21F),
      neutron_emission());

    elements.add_relation<isotope>("Li", "⁵Li");
    elements.add_relation<isotope>("Li", "⁶Li");
    elements.add_relation<isotope>("Li", "⁷Li");
    elements.add_relation<isotope>("Li", "⁸Li");
    elements.add_relation<isotope>("Li", "⁹Li");
    elements.add_relation<isotope>("Li", "¹⁰Li");

    elements.add(
      "Be",
      element_name("Beryllium"),
      element_protons(4),
      element_period(2),
      element_group(2),
      atomic_weight(9.0121831F));

    elements.add(
      "⁷Be", isotope_neutrons(3), half_life::days(53.12F), electron_capture());
    elements.add(
      "⁸Be", isotope_neutrons(4), half_life::seconds(8.19e-17F), alpha_decay());
    elements.add("⁹Be", isotope_neutrons(5));
    elements.add(
      "¹⁰Be", isotope_neutrons(6), half_life::days(1.39e6F), beta_m_decay());

    elements.add_relation<isotope>("Be", "⁷Be");
    elements.add_relation<isotope>("Be", "⁸Be");
    elements.add_relation<isotope>("Be", "⁹Be");
    elements.add_relation<isotope>("Be", "¹⁰Be");

    elements.add(
      "B",
      element_name("Borium", "Boron"),
      element_protons(5),
      element_period(2),
      element_group(13),
      atomic_weight(10.81F));

    elements.add("¹⁰B", isotope_neutrons(5));
    elements.add("¹¹B", isotope_neutrons(6));
    elements.add(
      "¹²B",
      isotope_neutrons(7),
      half_life::milliseconds(20.20F),
      beta_m_decay(),
      beta_m_alpha_decay());

    elements.add_relation<isotope>("B", "¹⁰B");
    elements.add_relation<isotope>("B", "¹¹B");
    elements.add_relation<isotope>("B", "¹²B");

    elements.add(
      "C",
      element_name("Carboneum", "Carbon"),
      element_protons(6),
      element_period(2),
      element_group(14),
      atomic_weight(12.011F));

    elements.add(
      "¹¹C", isotope_neutrons(5), half_life::minutes(20.F), beta_p_decay());
    elements.add("¹²C", isotope_neutrons(6));
    elements.add("¹³C", isotope_neutrons(7));
    elements.add(
      "¹⁴C", isotope_neutrons(8), half_life::years(5730.F), beta_m_decay());

    elements.add_relation<isotope>("C", "¹¹C");
    elements.add_relation<isotope>("C", "¹²C");
    elements.add_relation<isotope>("C", "¹³C");
    elements.add_relation<isotope>("C", "¹⁴C");

    elements.add(
      "N",
      element_name("Nitrogenium", "Nitrogen"),
      element_protons(7),
      element_period(2),
      element_group(15),
      atomic_weight(14.007F));

    elements.add(
      "¹³N",
      isotope_neutrons(6),
      half_life::minutes(9.965F),
      electron_capture());
    elements.add("¹⁴N", isotope_neutrons(7));
    elements.add("¹⁵N", isotope_neutrons(8));
    elements.add(
      "¹⁶N",
      isotope_neutrons(8),
      half_life::seconds(7.13F),
      beta_m_decay(),
      beta_m_alpha_decay());

    elements.add_relation<isotope>("N", "¹³N");
    elements.add_relation<isotope>("N", "¹⁴N");
    elements.add_relation<isotope>("N", "¹⁵N");
    elements.add_relation<isotope>("N", "¹⁶N");

    elements.add(
      "O",
      element_name("Oxygenium", "Oxygen"),
      element_protons(8),
      element_period(2),
      element_group(16),
      atomic_weight(15.999F));

    elements.add(
      "¹⁴O", isotope_neutrons(6), half_life::seconds(70.620F), beta_p_decay());
    elements.add(
      "¹⁵O", isotope_neutrons(7), half_life::seconds(122.24F), beta_p_decay());
    elements.add("¹⁶O", isotope_neutrons(8));
    elements.add("¹⁷O", isotope_neutrons(9));
    elements.add("¹⁸O", isotope_neutrons(10));
    elements.add(
      "¹⁹O", isotope_neutrons(11), half_life::seconds(26.470F), beta_m_decay());
    elements.add(
      "²⁰O", isotope_neutrons(12), half_life::seconds(15.51F), beta_m_decay());
    elements.add(
      "²¹O", isotope_neutrons(13), half_life::seconds(3.24F), beta_m_decay());

    elements.add_relation<isotope>("O", "¹⁴O");
    elements.add_relation<isotope>("O", "¹⁵O");
    elements.add_relation<isotope>("O", "¹⁶O");
    elements.add_relation<isotope>("O", "¹⁷O");
    elements.add_relation<isotope>("O", "¹⁸O");
    elements.add_relation<isotope>("O", "¹⁹O");
    elements.add_relation<isotope>("O", "²⁰O");
    elements.add_relation<isotope>("O", "²¹O");

    elements.add(
      "F",
      element_name("Fluorum", "Fluorine"),
      element_protons(9),
      element_period(2),
      element_group(17),
      atomic_weight(18.998403163F));

    elements.add(
      "¹⁷F", isotope_neutrons(8), half_life::seconds(64.370F), beta_p_decay());
    elements.add("¹⁹F", isotope_neutrons(10));
    elements.add(
      "²⁰F", isotope_neutrons(11), half_life::seconds(11.163F), beta_m_decay());
    elements.add(
      "²¹F", isotope_neutrons(12), half_life::seconds(4.158F), beta_m_decay());

    elements.add_relation<isotope>("F", "¹⁷F");
    elements.add_relation<isotope>("F", "¹⁹F");
    elements.add_relation<isotope>("F", "²⁰F");
    elements.add_relation<isotope>("F", "²¹F");

    elements.add(
      "Ne",
      element_name("Neon"),
      element_protons(10),
      element_period(2),
      element_group(18),
      atomic_weight(20.1797F));

    elements.add(
      "¹⁸Ne", isotope_neutrons(8), half_life::seconds(1.66420F), beta_p_decay());
    elements.add(
      "¹⁹Ne", isotope_neutrons(9), half_life::seconds(17.274F), beta_p_decay());
    elements.add("²⁰Ne", isotope_neutrons(10));
    elements.add("²¹Ne", isotope_neutrons(11));
    elements.add("²²Ne", isotope_neutrons(12));
    elements.add(
      "²³Ne", isotope_neutrons(13), half_life::seconds(37.140F), beta_m_decay());
    elements.add(
      "²⁴Ne", isotope_neutrons(13), half_life::minutes(3.38F), beta_m_decay());

    elements.add_relation<isotope>("Ne", "¹⁸Ne");
    elements.add_relation<isotope>("Ne", "¹⁹Ne");
    elements.add_relation<isotope>("Ne", "²⁰Ne");
    elements.add_relation<isotope>("Ne", "²¹Ne");
    elements.add_relation<isotope>("Ne", "²²Ne");
    elements.add_relation<isotope>("Ne", "²³Ne");
    elements.add_relation<isotope>("Ne", "²⁴Ne");

    elements.add(
      "Na",
      element_name("Natrium", "Sodium"),
      element_protons(11),
      element_period(3),
      element_group(1),
      atomic_weight(22.98976928F));

    elements.add(
      "²¹Na", isotope_neutrons(10), half_life::seconds(22.422F), beta_p_decay());
    elements.add(
      "²²Na", isotope_neutrons(11), half_life::years(2.6018F), beta_p_decay());
    elements.add("²³Na", isotope_neutrons(12));
    elements.add(
      "²⁴Na", isotope_neutrons(13), half_life::hours(14.957F), beta_m_decay());
    elements.add(
      "²⁵Na", isotope_neutrons(14), half_life::seconds(59.1F), beta_m_decay());
    elements.add(
      "²⁶Na",
      isotope_neutrons(15),
      half_life::seconds(1.07128F),
      beta_m_decay());

    elements.add_relation<isotope>("Na", "²¹Na");
    elements.add_relation<isotope>("Na", "²²Na");
    elements.add_relation<isotope>("Na", "²³Na");
    elements.add_relation<isotope>("Na", "²⁴Na");
    elements.add_relation<isotope>("Na", "²⁵Na");
    elements.add_relation<isotope>("Na", "²⁶Na");

    elements.add(
      "Mg",
      element_name("Magnesium"),
      element_protons(12),
      element_period(3),
      element_group(2),
      atomic_weight(24.305F));

    elements.add(
      "²²Mg", isotope_neutrons(10), half_life::seconds(3.8755F), beta_p_decay());
    elements.add(
      "²³Mg", isotope_neutrons(11), half_life::seconds(11.317F), beta_p_decay());
    elements.add("²⁴Mg", isotope_neutrons(12));
    elements.add("²⁵Mg", isotope_neutrons(13));
    elements.add("²⁶Mg", isotope_neutrons(14));
    elements.add(
      "²⁷Mg", isotope_neutrons(15), half_life::minutes(9.435F), beta_m_decay());
    elements.add(
      "²⁸Mg", isotope_neutrons(16), half_life::hours(20.915F), beta_m_decay());
    elements.add(
      "²⁹Mg", isotope_neutrons(17), half_life::seconds(1.30F), beta_m_decay());

    elements.add_relation<isotope>("Mg", "²²Mg");
    elements.add_relation<isotope>("Mg", "²³Mg");
    elements.add_relation<isotope>("Mg", "²⁴Mg");
    elements.add_relation<isotope>("Mg", "²⁵Mg");
    elements.add_relation<isotope>("Mg", "²⁶Mg");
    elements.add_relation<isotope>("Mg", "²⁷Mg");
    elements.add_relation<isotope>("Mg", "²⁸Mg");
    elements.add_relation<isotope>("Mg", "²⁹Mg");

    elements.add(
      "Al",
      element_name("Aluminum"),
      element_protons(13),
      element_period(3),
      element_group(13),
      atomic_weight(26.9815384F));

    elements.add(
      "²⁵Al", isotope_neutrons(12), half_life::seconds(7.183F), beta_p_decay());
    elements.add(
      "²⁶Al", isotope_neutrons(13), half_life::years(7.17e5F), beta_p_decay());
    elements.add("²⁷Al", isotope_neutrons(14));
    elements.add(
      "²⁸Al", isotope_neutrons(15), half_life::minutes(2.245F), beta_m_decay());
    elements.add(
      "²⁹Al", isotope_neutrons(16), half_life::minutes(6.56F), beta_m_decay());
    elements.add(
      "³⁰Al", isotope_neutrons(17), half_life::seconds(3.62F), beta_m_decay());

    elements.add_relation<isotope>("Al", "²⁵Al");
    elements.add_relation<isotope>("Al", "²⁶Al");
    elements.add_relation<isotope>("Al", "²⁷Al");
    elements.add_relation<isotope>("Al", "²⁸Al");
    elements.add_relation<isotope>("Al", "²⁹Al");
    elements.add_relation<isotope>("Al", "³⁰Al");

    elements.add(
      "Si",
      element_name("Silicium", "Silicon"),
      element_protons(14),
      element_period(3),
      element_group(14),
      atomic_weight(28.085F));

    elements.add(
      "²⁶Si", isotope_neutrons(12), half_life::seconds(2.2453F), beta_p_decay());
    elements.add(
      "²⁷Si", isotope_neutrons(13), half_life::seconds(4.15F), beta_p_decay());
    elements.add("²⁸Si", isotope_neutrons(14));
    elements.add("²⁹Si", isotope_neutrons(15));
    elements.add("³⁰Si", isotope_neutrons(16));
    elements.add(
      "³¹Si", isotope_neutrons(17), half_life::minutes(157.36F), beta_m_decay());
    elements.add(
      "³²Si", isotope_neutrons(18), half_life::years(153.F), beta_m_decay());
    elements.add(
      "³³Si", isotope_neutrons(19), half_life::seconds(6.18F), beta_m_decay());
    elements.add(
      "³⁴Si", isotope_neutrons(20), half_life::seconds(2.77F), beta_m_decay());

    elements.add_relation<isotope>("Si", "²⁶Si");
    elements.add_relation<isotope>("Si", "²⁷Si");
    elements.add_relation<isotope>("Si", "²⁸Si");
    elements.add_relation<isotope>("Si", "²⁹Si");
    elements.add_relation<isotope>("Si", "³⁰Si");
    elements.add_relation<isotope>("Si", "³¹Si");
    elements.add_relation<isotope>("Si", "³²Si");
    elements.add_relation<isotope>("Si", "³³Si");
    elements.add_relation<isotope>("Si", "³⁴Si");

    elements.add(
      "P",
      element_name("Phosphorus"),
      element_protons(15),
      element_period(3),
      element_group(15),
      atomic_weight(30.973761998F));

    elements.add(
      "²⁹P", isotope_neutrons(14), half_life::seconds(4.142F), beta_p_decay());
    elements.add(
      "³⁰P", isotope_neutrons(15), half_life::minutes(2.498F), beta_p_decay());
    elements.add("³¹P", isotope_neutrons(16));
    elements.add(
      "³²P", isotope_neutrons(17), half_life::days(14.268F), beta_m_decay());
    elements.add(
      "³³P", isotope_neutrons(18), half_life::days(25.35F), beta_m_decay());
    elements.add(
      "³⁴P", isotope_neutrons(19), half_life::seconds(12.43F), beta_m_decay());
    elements.add(
      "³⁵P", isotope_neutrons(20), half_life::seconds(47.3F), beta_m_decay());
    elements.add(
      "³⁶P", isotope_neutrons(21), half_life::seconds(5.6F), beta_m_decay());
    elements.add(
      "³⁷P", isotope_neutrons(22), half_life::seconds(2.31F), beta_m_decay());

    elements.add_relation<isotope>("P", "²⁹P");
    elements.add_relation<isotope>("P", "³⁰P");
    elements.add_relation<isotope>("P", "³¹P");
    elements.add_relation<isotope>("P", "³²P");
    elements.add_relation<isotope>("P", "³³P");
    elements.add_relation<isotope>("P", "³⁴P");
    elements.add_relation<isotope>("P", "³⁵P");
    elements.add_relation<isotope>("P", "³⁶P");
    elements.add_relation<isotope>("P", "³⁷P");

    elements.add(
      "S",
      element_name("Sulfur"),
      element_protons(16),
      element_period(3),
      element_group(16),
      atomic_weight(32.06F));

    elements.add(
      "³⁰S", isotope_neutrons(14), half_life::seconds(1.1759F), beta_p_decay());
    elements.add(
      "³¹S", isotope_neutrons(15), half_life::seconds(2.5534F), beta_p_decay());
    elements.add("³²S", isotope_neutrons(16));
    elements.add("³³S", isotope_neutrons(17));
    elements.add("³⁴S", isotope_neutrons(18));
    elements.add(
      "³⁵S", isotope_neutrons(19), half_life::days(87.37F), beta_m_decay());
    elements.add("³⁶S", isotope_neutrons(20));
    elements.add(
      "³⁷S", isotope_neutrons(21), half_life::minutes(5.05F), beta_m_decay());
    elements.add(
      "³⁸S", isotope_neutrons(22), half_life::minutes(170.3F), beta_m_decay());
    elements.add(
      "³⁹S", isotope_neutrons(23), half_life::seconds(11.5F), beta_m_decay());
    elements.add(
      "⁴⁰S", isotope_neutrons(24), half_life::seconds(8.8F), beta_m_decay());

    elements.add_relation<isotope>("S", "³⁰S");
    elements.add_relation<isotope>("S", "³¹S");
    elements.add_relation<isotope>("S", "³²S");
    elements.add_relation<isotope>("S", "³³S");
    elements.add_relation<isotope>("S", "³⁴S");
    elements.add_relation<isotope>("S", "³⁵S");
    elements.add_relation<isotope>("S", "³⁶S");
    elements.add_relation<isotope>("S", "³⁷S");
    elements.add_relation<isotope>("S", "³⁸S");
    elements.add_relation<isotope>("S", "³⁹S");
    elements.add_relation<isotope>("S", "⁴⁰S");

    elements.add(
      "Cl",
      element_name("Chlorum", "Chlorine"),
      element_protons(17),
      element_period(3),
      element_group(17),
      atomic_weight(35.45F));

    elements.add(
      "³³Cl", isotope_neutrons(16), half_life::seconds(2.5038F), beta_p_decay());
    elements.add(
      "³⁴Cl", isotope_neutrons(17), half_life::seconds(1.5266F), beta_p_decay());
    elements.add("³⁵Cl", isotope_neutrons(18));
    elements.add(
      "³⁶Cl",
      isotope_neutrons(19),
      half_life::years(1.013e5F),
      beta_p_decay(),
      beta_m_decay());
    elements.add("³⁷Cl", isotope_neutrons(20));
    elements.add(
      "³⁸Cl", isotope_neutrons(21), half_life::minutes(37.24F), beta_m_decay());
    elements.add(
      "³⁹Cl", isotope_neutrons(22), half_life::minutes(56.2F), beta_m_decay());
    elements.add(
      "⁴⁰Cl", isotope_neutrons(23), half_life::minutes(1.35F), beta_m_decay());
    elements.add(
      "⁴¹Cl", isotope_neutrons(24), half_life::seconds(38.4F), beta_m_decay());
    elements.add(
      "⁴²Cl", isotope_neutrons(25), half_life::seconds(6.8F), beta_m_decay());
    elements.add(
      "⁴³Cl",
      isotope_neutrons(26),
      half_life::seconds(3.13F),
      beta_m_decay(),
      beta_m_n_decay());

    elements.add_relation<isotope>("Cl", "³³Cl");
    elements.add_relation<isotope>("Cl", "³⁴Cl");
    elements.add_relation<isotope>("Cl", "³⁵Cl");
    elements.add_relation<isotope>("Cl", "³⁶Cl");
    elements.add_relation<isotope>("Cl", "³⁷Cl");
    elements.add_relation<isotope>("Cl", "³⁸Cl");
    elements.add_relation<isotope>("Cl", "³⁹Cl");
    elements.add_relation<isotope>("Cl", "⁴⁰Cl");
    elements.add_relation<isotope>("Cl", "⁴¹Cl");
    elements.add_relation<isotope>("Cl", "⁴²Cl");
    elements.add_relation<isotope>("Cl", "⁴³Cl");

    elements.add(
      "Ar",
      element_name("Argon"),
      element_protons(18),
      element_period(3),
      element_group(18),
      atomic_weight(39.95F));

    elements.add(
      "³⁴Ar",
      isotope_neutrons(16),
      half_life::milliseconds(843.8F),
      beta_p_decay());
    elements.add(
      "³⁵Ar", isotope_neutrons(17), half_life::seconds(1.7756F), beta_p_decay());
    elements.add("³⁶Ar", isotope_neutrons(18));
    elements.add(
      "³⁷Ar", isotope_neutrons(19), half_life::days(35.011F), beta_p_decay());
    elements.add("³⁸Ar", isotope_neutrons(20));
    elements.add(
      "³⁹Ar", isotope_neutrons(21), half_life::years(269.F), beta_m_decay());
    elements.add("⁴⁰Ar", isotope_neutrons(22));
    elements.add(
      "⁴¹Ar", isotope_neutrons(23), half_life::minutes(109.61F), beta_m_decay());
    elements.add(
      "⁴²Ar", isotope_neutrons(24), half_life::years(32.9F), beta_m_decay());
    elements.add(
      "⁴³Ar", isotope_neutrons(25), half_life::minutes(5.37F), beta_m_decay());
    elements.add(
      "⁴⁴Ar", isotope_neutrons(26), half_life::minutes(11.87F), beta_m_decay());
    elements.add(
      "⁴⁵Ar", isotope_neutrons(27), half_life::seconds(21.48F), beta_m_decay());
    elements.add(
      "⁴⁶Ar", isotope_neutrons(28), half_life::seconds(8.4F), beta_m_decay());

    elements.add_relation<isotope>("Ar", "³⁴Ar");
    elements.add_relation<isotope>("Ar", "³⁵Ar");
    elements.add_relation<isotope>("Ar", "³⁶Ar");
    elements.add_relation<isotope>("Ar", "³⁷Ar");
    elements.add_relation<isotope>("Ar", "³⁸Ar");
    elements.add_relation<isotope>("Ar", "³⁹Ar");
    elements.add_relation<isotope>("Ar", "⁴⁰Ar");
    elements.add_relation<isotope>("Ar", "⁴¹Ar");
    elements.add_relation<isotope>("Ar", "⁴²Ar");
    elements.add_relation<isotope>("Ar", "⁴³Ar");
    elements.add_relation<isotope>("Ar", "⁴⁴Ar");
    elements.add_relation<isotope>("Ar", "⁴⁵Ar");
    elements.add_relation<isotope>("Ar", "⁴⁶Ar");

    elements.add(
      "K",
      element_name("Kalium", "Potasium"),
      element_protons(19),
      element_period(4),
      element_group(1),
      atomic_weight(39.0983F));

    elements.add(
      "³⁷K", isotope_neutrons(18), half_life::seconds(1.2365F), beta_p_decay());
    elements.add(
      "³⁸K", isotope_neutrons(19), half_life::minutes(7.636F), beta_p_decay());
    elements.add("³⁹K", isotope_neutrons(20));
    elements.add(
      "⁴⁰K",
      isotope_neutrons(21),
      half_life::years(1.248e9F),
      beta_p_decay(),
      beta_m_decay(),
      electron_capture());
    elements.add("⁴¹K", isotope_neutrons(22));
    elements.add(
      "⁴²K", isotope_neutrons(23), half_life::hours(12.355F), beta_m_decay());
    elements.add(
      "⁴³K", isotope_neutrons(24), half_life::hours(22.3F), beta_m_decay());
    elements.add(
      "⁴⁴K", isotope_neutrons(25), half_life::minutes(22.13F), beta_m_decay());
    elements.add(
      "⁴⁵K", isotope_neutrons(26), half_life::minutes(17.8F), beta_m_decay());
    elements.add(
      "⁴⁶K", isotope_neutrons(27), half_life::seconds(105.F), beta_m_decay());
    elements.add(
      "⁴⁷K", isotope_neutrons(28), half_life::seconds(17.50F), beta_m_decay());

    elements.add_relation<isotope>("K", "³⁷K");
    elements.add_relation<isotope>("K", "³⁸K");
    elements.add_relation<isotope>("K", "³⁹K");
    elements.add_relation<isotope>("K", "⁴⁰K");
    elements.add_relation<isotope>("K", "⁴¹K");
    elements.add_relation<isotope>("K", "⁴²K");
    elements.add_relation<isotope>("K", "⁴³K");
    elements.add_relation<isotope>("K", "⁴⁴K");
    elements.add_relation<isotope>("K", "⁴⁵K");
    elements.add_relation<isotope>("K", "⁴⁶K");
    elements.add_relation<isotope>("K", "⁴⁷K");

    elements.add(
      "Ca",
      element_name("Calcium"),
      element_protons(20),
      element_period(4),
      element_group(2),
      atomic_weight(40.078F));

    elements.add(
      "³⁹Ca",
      isotope_neutrons(19),
      half_life::milliseconds(860.3F),
      beta_p_decay());
    elements.add("⁴⁰Ca", isotope_neutrons(20));
    elements.add(
      "⁴¹Ca",
      isotope_neutrons(21),
      half_life::years(9.94e4F),
      electron_capture());
    elements.add("⁴²Ca", isotope_neutrons(22));
    elements.add("⁴³Ca", isotope_neutrons(23));
    elements.add("⁴⁴Ca", isotope_neutrons(24));
    elements.add(
      "⁴⁵Ca", isotope_neutrons(25), half_life::days(162.61F), beta_m_decay());
    elements.add("⁴⁶Ca", isotope_neutrons(26));
    elements.add(
      "⁴⁷Ca", isotope_neutrons(27), half_life::days(4.536F), beta_m_decay());
    elements.add(
      "⁴⁸Ca", isotope_neutrons(28), half_life::years(6.4e19F), beta_m2_decay());
    elements.add(
      "⁴⁹Ca", isotope_neutrons(29), half_life::minutes(8.718F), beta_m_decay());
    elements.add(
      "⁵⁰Ca", isotope_neutrons(30), half_life::seconds(13.9F), beta_m_decay());
    elements.add(
      "⁵¹Ca", isotope_neutrons(31), half_life::seconds(10.0F), beta_m_decay());

    elements.add_relation<isotope>("Ca", "³⁹Ca");
    elements.add_relation<isotope>("Ca", "⁴⁰Ca");
    elements.add_relation<isotope>("Ca", "⁴¹Ca");
    elements.add_relation<isotope>("Ca", "⁴²Ca");
    elements.add_relation<isotope>("Ca", "⁴³Ca");
    elements.add_relation<isotope>("Ca", "⁴⁴Ca");
    elements.add_relation<isotope>("Ca", "⁴⁵Ca");
    elements.add_relation<isotope>("Ca", "⁴⁶Ca");
    elements.add_relation<isotope>("Ca", "⁴⁷Ca");
    elements.add_relation<isotope>("Ca", "⁴⁸Ca");
    elements.add_relation<isotope>("Ca", "⁴⁹Ca");
    elements.add_relation<isotope>("Ca", "⁵⁰Ca");
    elements.add_relation<isotope>("Ca", "⁵¹Ca");

    elements.add(
      "Sc",
      element_name("Scandium"),
      element_protons(21),
      element_period(4),
      element_group(3),
      atomic_weight(44.955908F));

    elements.add(
      "⁴¹Sc",
      isotope_neutrons(20),
      half_life::milliseconds(596.3F),
      beta_p_decay());
    elements.add(
      "⁴²Sc",
      isotope_neutrons(21),
      half_life::milliseconds(681.3F),
      beta_p_decay());
    elements.add(
      "⁴³Sc", isotope_neutrons(22), half_life::hours(3.891F), beta_p_decay());
    elements.add(
      "⁴⁴Sc", isotope_neutrons(23), half_life::hours(3.97F), beta_p_decay());
    elements.add("⁴⁵Sc", isotope_neutrons(24));
    elements.add(
      "⁴⁶Sc", isotope_neutrons(25), half_life::days(83.79F), beta_m_decay());
    elements.add(
      "⁴⁷Sc", isotope_neutrons(26), half_life::days(3.3492F), beta_m_decay());
    elements.add(
      "⁴⁸Sc", isotope_neutrons(27), half_life::hours(43.67F), beta_m_decay());
    elements.add(
      "⁴⁹Sc", isotope_neutrons(28), half_life::minutes(57.2F), beta_m_decay());
    elements.add(
      "⁵⁰Sc", isotope_neutrons(29), half_life::seconds(102.5F), beta_m_decay());
    elements.add(
      "⁵¹Sc", isotope_neutrons(30), half_life::seconds(12.4F), beta_m_decay());
    elements.add(
      "⁵²Sc", isotope_neutrons(31), half_life::seconds(8.2F), beta_m_decay());

    elements.add_relation<isotope>("Sc", "⁴¹Sc");
    elements.add_relation<isotope>("Sc", "⁴²Sc");
    elements.add_relation<isotope>("Sc", "⁴³Sc");
    elements.add_relation<isotope>("Sc", "⁴⁴Sc");
    elements.add_relation<isotope>("Sc", "⁴⁵Sc");
    elements.add_relation<isotope>("Sc", "⁴⁶Sc");
    elements.add_relation<isotope>("Sc", "⁴⁷Sc");
    elements.add_relation<isotope>("Sc", "⁴⁸Sc");
    elements.add_relation<isotope>("Sc", "⁴⁹Sc");
    elements.add_relation<isotope>("Sc", "⁵⁰Sc");
    elements.add_relation<isotope>("Sc", "⁵¹Sc");
    elements.add_relation<isotope>("Sc", "⁵²Sc");

    elements.add(
      "Ti",
      element_name("Titanium"),
      element_protons(22),
      element_period(4),
      element_group(4),
      atomic_weight(47.867F));

    elements.add(
      "⁴²Ti",
      isotope_neutrons(20),
      half_life::milliseconds(199.F),
      beta_p_decay());
    elements.add(
      "⁴³Ti",
      isotope_neutrons(21),
      half_life::milliseconds(509.F),
      beta_p_decay());
    elements.add(
      "⁴⁴Ti", isotope_neutrons(22), half_life::years(60.0F), electron_capture());
    elements.add(
      "⁴⁵Ti", isotope_neutrons(23), half_life::hours(184.8F), beta_p_decay());
    elements.add("⁴⁶Ti", isotope_neutrons(24));
    elements.add("⁴⁷Ti", isotope_neutrons(25));
    elements.add("⁴⁸Ti", isotope_neutrons(26));
    elements.add("⁴⁹Ti", isotope_neutrons(27));
    elements.add("⁵⁰Ti", isotope_neutrons(28));
    elements.add(
      "⁵¹Ti", isotope_neutrons(29), half_life::minutes(5.75F), beta_m_decay());
    elements.add(
      "⁵²Ti", isotope_neutrons(30), half_life::minutes(1.7F), beta_m_decay());
    elements.add(
      "⁵³Ti", isotope_neutrons(31), half_life::seconds(32.7F), beta_m_decay());
    elements.add(
      "⁵⁴Ti", isotope_neutrons(32), half_life::seconds(1.5F), beta_m_decay());
    elements.add(
      "⁵⁵Ti",
      isotope_neutrons(33),
      half_life::milliseconds(490.F),
      beta_m_decay());

    elements.add_relation<isotope>("Ti", "⁴²Ti");
    elements.add_relation<isotope>("Ti", "⁴³Ti");
    elements.add_relation<isotope>("Ti", "⁴⁴Ti");
    elements.add_relation<isotope>("Ti", "⁴⁵Ti");
    elements.add_relation<isotope>("Ti", "⁴⁶Ti");
    elements.add_relation<isotope>("Ti", "⁴⁷Ti");
    elements.add_relation<isotope>("Ti", "⁴⁸Ti");
    elements.add_relation<isotope>("Ti", "⁴⁹Ti");
    elements.add_relation<isotope>("Ti", "⁵⁰Ti");
    elements.add_relation<isotope>("Ti", "⁵⁰Ti");
    elements.add_relation<isotope>("Ti", "⁵¹Ti");
    elements.add_relation<isotope>("Ti", "⁵²Ti");
    elements.add_relation<isotope>("Ti", "⁵³Ti");
    elements.add_relation<isotope>("Ti", "⁵⁴Ti");
    elements.add_relation<isotope>("Ti", "⁵⁵Ti");

    elements.add(
      "V",
      element_name("Vanadium"),
      element_protons(23),
      element_period(4),
      element_group(5),
      atomic_weight(50.9415F));

    elements.add(
      "⁴⁵V",
      isotope_neutrons(22),
      half_life::milliseconds(547.F),
      beta_p_decay());
    elements.add(
      "⁴⁶V",
      isotope_neutrons(23),
      half_life::milliseconds(422.5F),
      beta_p_decay());
    elements.add(
      "⁴⁷V", isotope_neutrons(24), half_life::minutes(32.6F), beta_p_decay());
    elements.add(
      "⁴⁸V", isotope_neutrons(25), half_life::days(15.9735F), beta_p_decay());
    elements.add(
      "⁴⁹V", isotope_neutrons(26), half_life::days(329.F), electron_capture());
    elements.add(
      "⁵⁰V",
      isotope_neutrons(27),
      half_life::years(1.4F),
      beta_m_decay(),
      electron_capture());
    elements.add("⁵¹V", isotope_neutrons(28));
    elements.add(
      "⁵²V", isotope_neutrons(29), half_life::minutes(3.743F), beta_m_decay());
    elements.add(
      "⁵³V", isotope_neutrons(30), half_life::minutes(1.60F), beta_m_decay());
    elements.add(
      "⁵⁴V", isotope_neutrons(31), half_life::seconds(49.80F), beta_m_decay());
    elements.add(
      "⁵⁵V", isotope_neutrons(32), half_life::seconds(6.54F), beta_m_decay());
    elements.add(
      "⁵⁶V",
      isotope_neutrons(33),
      half_life::milliseconds(216.F),
      beta_m_n_decay());

    elements.add_relation<isotope>("V", "⁴⁵V");
    elements.add_relation<isotope>("V", "⁴⁶V");
    elements.add_relation<isotope>("V", "⁴⁷V");
    elements.add_relation<isotope>("V", "⁴⁸V");
    elements.add_relation<isotope>("V", "⁴⁹V");
    elements.add_relation<isotope>("V", "⁵⁰V");
    elements.add_relation<isotope>("V", "⁵¹V");
    elements.add_relation<isotope>("V", "⁵²V");
    elements.add_relation<isotope>("V", "⁵³V");
    elements.add_relation<isotope>("V", "⁵⁴V");
    elements.add_relation<isotope>("V", "⁵⁵V");
    elements.add_relation<isotope>("V", "⁵⁶V");

    elements.add(
      "Cr",
      element_name("Chromium"),
      element_protons(24),
      element_period(4),
      element_group(6),
      atomic_weight(51.9961F));

    elements.add(
      "Mn",
      element_name("Manganum", "Manganese"),
      element_protons(25),
      element_period(4),
      element_group(7),
      atomic_weight(54.938043F));

    elements.add(
      "Fe",
      element_name("Ferrum", "Iron"),
      element_protons(26),
      element_period(4),
      element_group(8),
      atomic_weight(55.845F));

    elements.add(
      "Co",
      element_name("Cobaltum", "Cobalt"),
      element_protons(27),
      element_period(4),
      element_group(9),
      atomic_weight(58.933194F));

    elements.add(
      "Ni",
      element_name("Niccolum", "Nickel"),
      element_protons(28),
      element_period(4),
      element_group(10),
      atomic_weight(58.6934F));

    elements.add(
      "Cu",
      element_name("Cuprum", "Copper"),
      element_protons(29),
      element_period(4),
      element_group(11),
      atomic_weight(63.546F));

    elements.add(
      "Zn",
      element_name("Zincum", "Zinc"),
      element_protons(30),
      element_period(4),
      element_group(12),
      atomic_weight(65.38F));

    elements.add(
      "Ga",
      element_name("Gallium"),
      element_protons(31),
      element_period(4),
      element_group(13),
      atomic_weight(69.723F));

    elements.add(
      "Ge",
      element_name("Germanium"),
      element_protons(32),
      element_period(4),
      element_group(14),
      atomic_weight(72.630F));

    elements.add(
      "As",
      element_name("Arsenicum", "Arsenic"),
      element_protons(33),
      element_period(4),
      element_group(15),
      atomic_weight(74.921595F));

    elements.add(
      "Se",
      element_name("Selenium"),
      element_protons(34),
      element_period(4),
      element_group(16),
      atomic_weight(78.971F));

    elements.add(
      "Br",
      element_name("Bromum", "Bromine"),
      element_protons(35),
      element_period(4),
      element_group(17),
      atomic_weight(79.904F));

    elements.add(
      "Kr",
      element_name("Krypton"),
      element_protons(36),
      element_period(4),
      element_group(18),
      atomic_weight(83.798F));

    elements.add(
      "Rb",
      element_name("Rubidium"),
      element_protons(37),
      element_period(5),
      element_group(1),
      atomic_weight(85.4678F));

    elements.add(
      "Sr",
      element_name("Strontium"),
      element_protons(38),
      element_period(5),
      element_group(2),
      atomic_weight(87.62F));

    elements.add(
      "Y",
      element_name("Yttrium"),
      element_protons(39),
      element_period(5),
      element_group(3),
      atomic_weight(88.90584F));

    elements.add(
      "Zr",
      element_name("Zirconium"),
      element_protons(40),
      element_period(5),
      element_group(4),
      atomic_weight(91.224F));

    elements.add(
      "Nb",
      element_name("Niobium"),
      element_protons(41),
      element_period(5),
      element_group(5),
      atomic_weight(92.90637F));

    elements.add(
      "Mo",
      element_name("Molybdenum"),
      element_protons(42),
      element_period(5),
      element_group(6),
      atomic_weight(95.95F));

    elements.add(
      "Tc",
      element_name("Technetium"),
      element_protons(43),
      element_period(5),
      element_group(7),
      atomic_weight(98.F));

    elements.add(
      "Ru",
      element_name("Ruthenium"),
      element_protons(44),
      element_period(5),
      element_group(8),
      atomic_weight(101.07F));

    elements.add(
      "Rh",
      element_name("Rhodium"),
      element_protons(45),
      element_period(5),
      element_group(9),
      atomic_weight(102.90549F));

    elements.add(
      "Pd",
      element_name("Palladium"),
      element_protons(46),
      element_period(5),
      element_group(10),
      atomic_weight(106.42F));

    elements.add(
      "Ag",
      element_name("Argentum", "Silver"),
      element_protons(47),
      element_period(5),
      element_group(11),
      atomic_weight(107.8682F));

    elements.add(
      "Cd",
      element_name("Cadmium"),
      element_protons(48),
      element_period(5),
      element_group(12),
      atomic_weight(112.414F));

    elements.add(
      "In",
      element_name("Indium"),
      element_protons(49),
      element_period(5),
      element_group(13),
      atomic_weight(114.818F));

    elements.add(
      "Sn",
      element_name("Stannum", "Tin"),
      element_protons(50),
      element_period(5),
      element_group(14),
      atomic_weight(118.710F));

    elements.add(
      "Sb",
      element_name("Stibium", "Antimony"),
      element_protons(51),
      element_period(5),
      element_group(15),
      atomic_weight(121.760F));

    elements.add(
      "Te",
      element_name("Tellurium"),
      element_protons(52),
      element_period(5),
      element_group(16),
      atomic_weight(127.60F));

    elements.add(
      "I",
      element_name("Iodium", "Iodine"),
      element_protons(53),
      element_period(5),
      element_group(17),
      atomic_weight(126.90447F));

    elements.add(
      "Xe",
      element_name("Xenon"),
      element_protons(54),
      element_period(5),
      element_group(18),
      atomic_weight(131.293F));

    elements.add(
      "Cs",
      element_name("Caesium"),
      element_protons(55),
      element_period(6),
      element_group(1),
      atomic_weight(132.90545196F));

    elements.add(
      "Ba",
      element_name("Barium"),
      element_protons(56),
      element_period(6),
      element_group(2),
      atomic_weight(137.327F));

    elements.add(
      "La",
      element_name("Lanthanum"),
      element_protons(57),
      element_period(6),
      element_group(3),
      atomic_weight(138.90547F));

    elements.add(
      "Ce",
      element_name("Cerium"),
      element_protons(58),
      element_period(6),
      atomic_weight(140.116F));

    elements.add(
      "Pr",
      element_name("Praseodymium"),
      element_protons(59),
      element_period(6),
      atomic_weight(140.90766F));

    elements.add(
      "Nd",
      element_name("Neodymium"),
      element_protons(60),
      element_period(6),
      atomic_weight(144.242F));

    elements.add(
      "Pm",
      element_name("Promethium"),
      element_protons(61),
      element_period(6),
      atomic_weight(145.F));

    elements.add(
      "Sm",
      element_name("Samarium"),
      element_protons(62),
      element_period(6),
      atomic_weight(150.36F));

    elements.add(
      "Eu",
      element_name("Europium"),
      element_protons(63),
      element_period(6),
      atomic_weight(151.964F));

    elements.add(
      "Gd",
      element_name("Gadolinium"),
      element_protons(64),
      element_period(6),
      atomic_weight(157.25F));

    elements.add(
      "Tb",
      element_name("Terbium"),
      element_protons(65),
      element_period(6),
      atomic_weight(158.925354F));

    elements.add(
      "Dy",
      element_name("Dysprosium"),
      element_protons(66),
      element_period(6),
      atomic_weight(162.500F));

    elements.add(
      "Ho",
      element_name("Holmium"),
      element_protons(67),
      element_period(6),
      atomic_weight(164.930328F));

    elements.add(
      "Er",
      element_name("Erbium"),
      element_protons(68),
      element_period(6),
      atomic_weight(167.259F));

    elements.add(
      "Tm",
      element_name("Thulium"),
      element_protons(69),
      element_period(6),
      atomic_weight(168.934218F));

    elements.add(
      "Yb",
      element_name("Ytterbium"),
      element_protons(70),
      element_period(6),
      atomic_weight(173.045F));

    elements.add(
      "Lu",
      element_name("Lutetium"),
      element_protons(71),
      element_period(6),
      atomic_weight(174.9668F));

    elements.add(
      "Hf",
      element_name("Hafnium"),
      element_protons(72),
      element_period(6),
      element_group(4),
      atomic_weight(178.49F));

    elements.add(
      "Ta",
      element_name("Tantalum"),
      element_protons(73),
      element_period(6),
      element_group(5),
      atomic_weight(180.94788F));

    elements.add(
      "W",
      element_name("Wolframium", "Tungsten"),
      element_protons(74),
      element_period(6),
      element_group(6),
      atomic_weight(183.84F));

    elements.add(
      "Re",
      element_name("Rhenium"),
      element_protons(75),
      element_period(6),
      element_group(7),
      atomic_weight(186.207F));

    elements.add(
      "Os",
      element_name("Osmium"),
      element_protons(76),
      element_period(6),
      element_group(8),
      atomic_weight(190.23F));

    elements.add(
      "Ir",
      element_name("Iridium"),
      element_protons(77),
      element_period(6),
      element_group(9),
      atomic_weight(192.217F));

    elements.add(
      "Pt",
      element_name("Platinum"),
      element_protons(78),
      element_period(6),
      element_group(10),
      atomic_weight(195.084F));

    elements.add(
      "Au",
      element_name("Aurum", "Gold"),
      element_protons(79),
      element_period(6),
      element_group(11),
      atomic_weight(196.966570F));

    elements.add(
      "Hg",
      element_name("Hydrargyrum", "Mercury"),
      element_protons(80),
      element_period(6),
      element_group(12),
      atomic_weight(200.592F));

    elements.add(
      "Tl",
      element_name("Thallium"),
      element_protons(81),
      element_period(6),
      element_group(13),
      atomic_weight(204.38F));

    elements.add(
      "Pb",
      element_name("Plumbum", "Lead"),
      element_protons(82),
      element_period(6),
      element_group(14),
      atomic_weight(207.2F));

    elements.add(
      "Bi",
      element_name("Bismuth"),
      element_protons(83),
      element_period(6),
      element_group(15),
      atomic_weight(208.98040F));

    elements.add(
      "Po",
      element_name("Polonium"),
      element_protons(84),
      element_period(6),
      element_group(16),
      atomic_weight(209.F));

    elements.add(
      "At",
      element_name("Astatium", "Astatine"),
      element_protons(85),
      element_period(6),
      element_group(17),
      atomic_weight(210.F));

    elements.add(
      "Rn",
      element_name("Radon"),
      element_protons(86),
      element_period(6),
      element_group(18),
      atomic_weight(222.0F));

    elements.add(
      "Fr",
      element_name("Francium"),
      element_protons(87),
      element_period(7),
      element_group(1),
      atomic_weight(223.F));

    elements.add(
      "Ra",
      element_name("Radium"),
      element_protons(88),
      element_period(7),
      element_group(2),
      atomic_weight(226.F));

    elements.add(
      "Ac",
      element_name("Actinium"),
      element_protons(89),
      element_period(7),
      element_group(3),
      atomic_weight(227.F));

    elements.add(
      "Th",
      element_name("Thorium"),
      element_protons(90),
      element_period(7),
      atomic_weight(232.0377F));

    elements.add(
      "Pa",
      element_name("Protactinium"),
      element_protons(91),
      element_period(7),
      atomic_weight(231.03588F));

    elements.add(
      "U",
      element_name("Uranium"),
      element_protons(92),
      element_period(7),
      atomic_weight(238.02891F));

    elements.add(
      "Np",
      element_name("Neptunium"),
      element_protons(93),
      element_period(7),
      atomic_weight(237.F));

    elements.add(
      "Pu",
      element_name("Plutonium"),
      element_protons(94),
      element_period(7),
      atomic_weight(244.F));

    elements.add(
      "Am",
      element_name("Americium"),
      element_protons(95),
      element_period(7),
      atomic_weight(243.F));

    elements.add(
      "Cm",
      element_name("Curium"),
      element_protons(96),
      element_period(7),
      atomic_weight(247.F));

    elements.add(
      "Bk",
      element_name("Berkelium"),
      element_protons(97),
      element_period(7),
      atomic_weight(247.F));

    elements.add(
      "Cf",
      element_name("Californium"),
      element_protons(98),
      element_period(7),
      atomic_weight(251.F));

    elements.add(
      "Es",
      element_name("Einsteinium"),
      element_protons(99),
      element_period(7),
      atomic_weight(252.F));

    elements.add(
      "Fm",
      element_name("Fermium"),
      element_protons(100),
      element_period(7),
      atomic_weight(257.F));

    elements.add(
      "Md",
      element_name("Mendelevium"),
      element_protons(101),
      element_period(7),
      atomic_weight(258.F));

    elements.add(
      "No",
      element_name("Nobelium"),
      element_protons(102),
      element_period(7),
      atomic_weight(259.F));

    elements.add(
      "Lr",
      element_name("Lawrencium"),
      element_protons(103),
      element_period(7),
      atomic_weight(266.F));

    elements.add(
      "Rf",
      element_name("Rutherfordium"),
      element_protons(104),
      element_period(7),
      element_group(4),
      atomic_weight(267.F));

    elements.add(
      "Db",
      element_name("Dubnium"),
      element_protons(105),
      element_period(7),
      element_group(5),
      atomic_weight(268.F));

    elements.add(
      "Sg",
      element_name("Seaborgium"),
      element_protons(106),
      element_period(7),
      element_group(6),
      atomic_weight(269.F));

    elements.add(
      "Bh",
      element_name("Bohrium"),
      element_protons(107),
      element_period(7),
      element_group(7),
      atomic_weight(270.F));

    elements.add(
      "Hs",
      element_name("Hassium"),
      element_protons(108),
      element_period(7),
      element_group(8),
      atomic_weight(270.F));

    elements.add(
      "Mt",
      element_name("Meitnerium"),
      element_protons(109),
      element_period(7),
      element_group(9),
      atomic_weight(278.F));

    elements.add(
      "Ds",
      element_name("Darmstadtium"),
      element_protons(110),
      element_period(7),
      element_group(10),
      atomic_weight(281.F));

    elements.add(
      "Rg",
      element_name("Roentgenium"),
      element_protons(111),
      element_period(7),
      element_group(11),
      atomic_weight(282.F));

    elements.add(
      "Cn",
      element_name("Copernicum"),
      element_protons(112),
      element_period(7),
      element_group(12),
      atomic_weight(285.F));

    elements.add(
      "Nh",
      element_name("Nihonium"),
      element_protons(113),
      element_period(7),
      element_group(13),
      atomic_weight(286.F));

    elements.add(
      "Fl",
      element_name("Flerovium"),
      element_protons(114),
      element_period(7),
      element_group(14),
      atomic_weight(289.F));

    elements.add(
      "Mc",
      element_name("Moscovium"),
      element_protons(115),
      element_period(7),
      element_group(15),
      atomic_weight(290.F));

    elements.add(
      "Lv",
      element_name("Livermorium"),
      element_protons(116),
      element_period(7),
      element_group(16),
      atomic_weight(293.F));

    elements.add(
      "Ts",
      element_name("Tennessine"),
      element_protons(117),
      element_period(7),
      element_group(17),
      atomic_weight(294.F));

    elements.add(
      "Og",
      element_name("Oganesson"),
      element_protons(118),
      element_period(7),
      element_group(18),
      atomic_weight(294.F));
}

} // namespace eagine
