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
#include <iostream>

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
      : latin{std::move(lat)}
      , english{latin} {}
};
//------------------------------------------------------------------------------
template <bool Const>
struct element_name_manip : ecs::basic_manipulator<element_name, Const> {
    using ecs::basic_manipulator<element_name, Const>::basic_manipulator;

    auto get_latin_name() const -> const std::string& {
        return this->read().latin;
    }

    auto get_english_name() const -> const std::string& {
        return this->read().english;
    }

    auto has_english_name() const -> bool {
        return this->read().latin != this->read().english;
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

    element_protons(short n)
      : number{n} {}
};
//------------------------------------------------------------------------------
struct element_period : ecs::component<element_period> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(Period);
    }

    short number{0};

    element_period(short n)
      : number{n} {}
};
//------------------------------------------------------------------------------
struct element_group : ecs::component<element_group> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(Group);
    }

    short number{0};

    element_group(short n)
      : number{n} {}
};
//------------------------------------------------------------------------------
struct atomic_weight : ecs::component<atomic_weight> {
    static constexpr auto uid() noexcept {
        return EAGINE_ID_V(AtomWeight);
    }

    float value{0.F};

    atomic_weight(float w)
      : value{w} {}
};
//------------------------------------------------------------------------------
void populate(ecs::basic_manager<std::string>& elements);
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    ctx.log().info("starting");

    using symbol = std::string;
    using ecs::std_map_cmp_storage;

    ecs::basic_manager<symbol> elements;
    elements.register_component_storage<std_map_cmp_storage, element_name>();
    elements.register_component_storage<std_map_cmp_storage, element_protons>();
    elements.register_component_storage<std_map_cmp_storage, element_period>();
    elements.register_component_storage<std_map_cmp_storage, element_group>();
    elements.register_component_storage<std_map_cmp_storage, atomic_weight>();

    populate(elements);

    // print elements that have english name (different from latin)
    elements.for_each_with<const element_name>(
      [](const symbol& sym, ecs::manipulator<const element_name>& name) {
          if(name.has_english_name()) {
              std::cout << sym << ": " << name.get_english_name() << std::endl;
          }
      });
    std::cout << std::endl;

    // print names of noble gasses (group 18)
    elements.for_each_with<const element_name, const element_group>(
      [](
        const symbol&,
        ecs::manipulator<const element_name>& name,
        ecs::manipulator<const element_group>& group) {
          if(group.read(&element_group::number) == 18) {
              std::cout << name.get_latin_name() << std::endl;
          }
      });
    std::cout << std::endl;

    return 0;
}
//------------------------------------------------------------------------------
void populate(ecs::basic_manager<std::string>& elements) {
    elements.add(
      "H",
      element_name("Hydrogenium", "Hydrogen"),
      element_protons(1),
      element_period(1),
      element_group(1),
      atomic_weight(1.F));

    elements.add(
      "He",
      element_name("Helium"),
      element_protons(2),
      element_period(1),
      element_group(18),
      atomic_weight(4.002602F));

    elements.add(
      "Li",
      element_name("Lithium"),
      element_protons(3),
      element_period(2),
      element_group(1),
      atomic_weight(6.94F));

    elements.add(
      "Be",
      element_name("Beryllium"),
      element_protons(4),
      element_period(2),
      element_group(2),
      atomic_weight(9.0121831F));

    elements.add(
      "B",
      element_name("Borium", "Boron"),
      element_protons(5),
      element_period(2),
      element_group(13),
      atomic_weight(10.81F));

    elements.add(
      "C",
      element_name("Carboneum", "Carbon"),
      element_protons(6),
      element_period(2),
      element_group(14),
      atomic_weight(12.011F));

    elements.add(
      "N",
      element_name("Nitrogenium", "Nitrogen"),
      element_protons(7),
      element_period(2),
      element_group(15),
      atomic_weight(14.007F));

    elements.add(
      "O",
      element_name("Oxygenium", "Oxygen"),
      element_protons(8),
      element_period(2),
      element_group(16),
      atomic_weight(15.999F));

    elements.add(
      "F",
      element_name("Fluorum", "Fluorine"),
      element_protons(9),
      element_period(2),
      element_group(17),
      atomic_weight(18.998403163F));

    elements.add(
      "Ne",
      element_name("Neon"),
      element_protons(10),
      element_period(2),
      element_group(18),
      atomic_weight(20.1797F));

    elements.add(
      "Na",
      element_name("Natrium", "Sodium"),
      element_protons(11),
      element_period(3),
      element_group(1),
      atomic_weight(22.98976928F));

    elements.add(
      "Mg",
      element_name("Magnesium"),
      element_protons(12),
      element_period(3),
      element_group(2),
      atomic_weight(24.305F));

    elements.add(
      "Al",
      element_name("Aluminum"),
      element_protons(13),
      element_period(3),
      element_group(13),
      atomic_weight(26.9815384F));

    elements.add(
      "Si",
      element_name("Silicium", "Silicon"),
      element_protons(14),
      element_period(3),
      element_group(14),
      atomic_weight(28.085F));

    elements.add(
      "P",
      element_name("Phosphorus"),
      element_protons(15),
      element_period(3),
      element_group(15),
      atomic_weight(30.973761998F));

    elements.add(
      "S",
      element_name("Sulfur"),
      element_protons(16),
      element_period(3),
      element_group(16),
      atomic_weight(32.06F));

    elements.add(
      "Cl",
      element_name("Chlorum", "Chlorine"),
      element_protons(17),
      element_period(3),
      element_group(17),
      atomic_weight(35.45F));

    elements.add(
      "Ar",
      element_name("Argon"),
      element_protons(18),
      element_period(3),
      element_group(18),
      atomic_weight(39.95F));

    elements.add(
      "K",
      element_name("Kalium", "Potasium"),
      element_protons(19),
      element_period(4),
      element_group(1),
      atomic_weight(39.0983F));

    elements.add(
      "Ca",
      element_name("Calcium"),
      element_protons(20),
      element_period(4),
      element_group(2),
      atomic_weight(40.078F));

    elements.add(
      "Sc",
      element_name("Scandium"),
      element_protons(21),
      element_period(4),
      element_group(3),
      atomic_weight(44.955908F));

    elements.add(
      "Ti",
      element_name("Titanium"),
      element_protons(22),
      element_period(4),
      element_group(4),
      atomic_weight(47.867F));

    elements.add(
      "V",
      element_name("Vanadium"),
      element_protons(23),
      element_period(4),
      element_group(5),
      atomic_weight(50.9415F));

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
      "Xe",
      element_name("Xenon"),
      element_protons(54),
      element_period(5),
      element_group(18),
      atomic_weight(131.293F));

    elements.add(
      "Au",
      element_name("Aurum", "Gold"),
      element_protons(79),
      element_period(6),
      element_group(11),
      atomic_weight(196.966570F));

    elements.add(
      "Rn",
      element_name("Radon"),
      element_protons(86),
      element_period(6),
      element_group(18),
      atomic_weight(222.0F));

    elements.add(
      "U",
      element_name("Uranium"),
      element_protons(92),
      element_period(7),
      atomic_weight(238.02891F));

    elements.add(
      "Og",
      element_name("Oganesson"),
      element_protons(118),
      element_period(7),
      element_group(18),
      atomic_weight(294.0F));
}

} // namespace eagine
