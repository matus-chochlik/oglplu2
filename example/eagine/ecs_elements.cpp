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

    element_protons() noexcept = default;

    element_protons(short n)
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
static void
print_elements_with_english_name(ecs::basic_manager<std::string>& elements) {
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
print_names_of_noble_gasses(ecs::basic_manager<std::string>& elements) {
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
static void print_names_of_actinides(ecs::basic_manager<std::string>& elements) {
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
void populate(ecs::basic_manager<std::string>& elements);
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    ctx.log().info("starting");

    using ecs::std_map_cmp_storage;

    ecs::basic_manager<std::string> elements;
    elements.register_component_storage<std_map_cmp_storage, element_name>();
    elements.register_component_storage<std_map_cmp_storage, element_protons>();
    elements.register_component_storage<std_map_cmp_storage, element_period>();
    elements.register_component_storage<std_map_cmp_storage, element_group>();
    elements.register_component_storage<std_map_cmp_storage, atomic_weight>();

    populate(elements);

    print_elements_with_english_name(elements);
    print_names_of_noble_gasses(elements);
    print_names_of_actinides(elements);

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
