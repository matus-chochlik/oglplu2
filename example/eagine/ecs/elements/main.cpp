/**
 *  @example eagine/ecs/elements/main.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "components.hpp"
#include "entity.hpp"
#include "init.hpp"
#include "relations.hpp"
#include <eagine/ecs/basic_manager.hpp>
#include <eagine/ecs/entity/string.hpp>
#include <eagine/ecs/storage/std_map.hpp>
#include <eagine/ecs/storage_caps.hpp>
#include <eagine/embed.hpp>
#include <eagine/main.hpp>
#include <eagine/value_tree/json.hpp>
#include <iostream>

namespace eagine {
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
    elements
      .register_component_storage<std_map_cmp_storage, electron_capture_2>();
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
} // namespace eagine
