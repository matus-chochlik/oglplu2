/**
 *  @example eagine/ecs/elements/init.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include "init.hpp"
#include "components.hpp"
#include "entity.hpp"
#include "relations.hpp"
#include <eagine/ecs/storage/std_map.hpp>
#include <eagine/embed.hpp>
#include <eagine/value_tree/json.hpp>
#include <eagine/value_tree/wrappers.hpp>

namespace eagine {
//------------------------------------------------------------------------------
static void populate(
  ecs::basic_manager<element_symbol>& elements,
  const valtree::compound& source) {

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
                    using hl_t = std::chrono::duration<float>;
                    if(auto hl{source.get(half_life_a, identity<hl_t>())}) {
                        elements.add(isot, half_life(extract(hl)));
                    }
                }

                if(auto decays_a{source.nested(isot_attr, "decay")}) {
                    const auto n = source.nested_count(decays_a);
                    decay_modes isot_decay;
                    for(span_size_t d = 0; d < n; ++d) {
                        if(auto decay_a{source.nested(decays_a, d)}) {
                            if(auto mode_a{source.nested(decay_a, "mode")}) {
                                std::string mode_sym;
                                if(source.fetch_value(mode_a, mode_sym)) {
                                    if(auto info{isot_decay.add(mode_sym)}) {
                                        if(auto prod_a{source.nested(
                                             decay_a, "products")}) {
                                            auto& prod = extract(info).products;
                                            prod.resize(std_size(
                                              source.value_count(prod_a)));
                                            source.fetch_values(
                                              prod_a, cover(prod));
                                        }
                                    }
                                }
                            }
                        }
                    }
                    elements.add(isot, std::move(isot_decay));
                }

                elements.add_relation<isotope>(elem, isot);
            }
        }
    }
}
//------------------------------------------------------------------------------
static void cache_decay_products(ecs::basic_manager<element_symbol>& elements) {

    // for each original isotope with neutron cound and some decay modes
    elements.for_each_with<const isotope_neutrons, decay_modes>(
      [&](auto& orig_is, auto& orig_nc, auto& modes) {
          // for each product isotope
          elements.for_each_with<const isotope_neutrons>(
            [&](auto& prod_is, auto& prod_nc) {
                // for each decay mode of the original isotope
                modes->for_each([&](auto& dcy_mode, auto& dcy) {
                    // if the isotope neutron count after the decay matches
                    if(
                      dcy.products.empty() &&
                      (orig_nc->number + dcy_mode.neutron_count_diff ==
                       prod_nc->number)) {
                        // for each original element with proton count
                        elements.for_each_with<const element_protons>(
                          [&](auto& orig_el, auto& orig_pc) {
                              // if the original element has the original isotope
                              if(elements.has<isotope>(orig_el, orig_is)) {
                                  // for each product element
                                  elements.for_each_with<const element_protons>(
                                    [&](auto& prod_el, auto& prod_pc) {
                                        // if the element proton count after the
                                        // decay matches
                                        if(
                                          orig_pc->number +
                                            dcy_mode.proton_count_diff ==
                                          prod_pc->number) {
                                            // if the product element has the
                                            // product isotope
                                            if(elements.has<isotope>(
                                                 prod_el, prod_is)) {
                                                // cache the product isotope in
                                                // the original isotope decay info
                                                dcy.products.push_back(prod_is);
                                            }
                                        }
                                    });
                              }
                          });
                    }
                });
            });
      });
}
//------------------------------------------------------------------------------
static void do_initialize(
  ecs::basic_manager<element_symbol>& elements,
  const valtree::compound& source) {
    // components
    elements
      .register_component_storage<ecs::std_map_cmp_storage, element_name>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, element_protons>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, isotope_neutrons>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, element_period>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, element_group>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, atomic_weight>();
    elements.register_component_storage<ecs::std_map_cmp_storage, half_life>();
    elements.register_component_storage<ecs::std_map_cmp_storage, decay_modes>();

    // relations
    elements.register_relation_storage<ecs::std_map_rel_storage, isotope>();

    populate(elements, source);
    cache_decay_products(elements);
}
//------------------------------------------------------------------------------
void initialize(main_ctx& ctx, ecs::basic_manager<element_symbol>& elements) {

    const auto json_res{embed(EAGINE_ID(ElemJSON), "elements.json")};

    auto json_tree{
      valtree::from_json_text(as_chars(json_res.unpack(ctx)), ctx.log())};

    do_initialize(elements, json_tree);
}
} // namespace eagine
