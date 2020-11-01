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

namespace eagine {
//------------------------------------------------------------------------------
static void populate(
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
                    using hl_t = std::chrono::duration<float>;
                    if(auto hl{source.get(half_life_a, identity<hl_t>())}) {
                        elements.add(isot, half_life(extract(hl)));
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
                if(auto decay_a{
                     source.nested(isot_attr, "electron2_capture")}) {
                    elements.add(isot, electron2_capture());
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
                if(auto decay_a{source.nested(isot_attr, "beta_m_n2_decay")}) {
                    elements.add(isot, beta_m_n2_decay());
                }
                if(auto decay_a{source.nested(isot_attr, "beta_p_decay")}) {
                    elements.add(isot, beta_p_decay());
                }
                if(auto decay_a{source.nested(isot_attr, "beta_p2_decay")}) {
                    elements.add(isot, beta_p2_decay());
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
    cache_decay_products_of<electron2_capture>(elements);
    cache_decay_products_of<beta_m_decay>(elements);
    cache_decay_products_of<beta_m2_decay>(elements);
    cache_decay_products_of<beta_m_alpha_decay>(elements);
    cache_decay_products_of<beta_m_n_decay>(elements);
    cache_decay_products_of<beta_m_n2_decay>(elements);
    cache_decay_products_of<beta_p_decay>(elements);
    cache_decay_products_of<beta_p2_decay>(elements);
    cache_decay_products_of<beta_p_alpha_decay>(elements);
    cache_decay_products_of<beta_p_p_decay>(elements);
}
//------------------------------------------------------------------------------
void initialize(
  ecs::basic_manager<element_symbol>& elements,
  const valtree::compound& source) {
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
    elements.register_component_storage<ecs::std_map_cmp_storage, alpha_decay>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, proton_emission>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, neutron_emission>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, electron_capture>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, electron2_capture>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, beta_m_decay>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, beta_m2_decay>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, beta_m_alpha_decay>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, beta_m_n_decay>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, beta_m_n2_decay>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, beta_p_decay>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, beta_p2_decay>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, beta_p_alpha_decay>();
    elements
      .register_component_storage<ecs::std_map_cmp_storage, beta_p_p_decay>();

    elements.register_relation_storage<ecs::std_map_rel_storage, isotope>();

    populate(elements, source);
    cache_decay_products(elements);
}
//------------------------------------------------------------------------------
} // namespace eagine
