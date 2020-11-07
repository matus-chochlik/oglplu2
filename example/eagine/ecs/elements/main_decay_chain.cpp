/**
 *  @example eagine/ecs/elements/main_decay_chain.cpp
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
#include <eagine/ecs/cmp_storage.hpp>
#include <eagine/ecs/entity/string.hpp>
#include <eagine/ecs/rel_storage.hpp>
#include <eagine/ecs/storage_caps.hpp>
#include <eagine/main.hpp>
#include <iostream>
#include <set>

namespace eagine {
//------------------------------------------------------------------------------
struct entity_node {
    const element_symbol& sym;
};

static auto operator<<(std::ostream& out, const entity_node& en)
  -> std::ostream& {
    return out << "n" << std::hash<element_symbol>()(en.sym);
}
//------------------------------------------------------------------------------
static void decay_of(
  ecs::basic_manager<element_symbol>& elements,
  const element_symbol& isot,
  std::set<element_symbol>& done) {

    done.insert(isot);

    auto func = [&](const auto&, auto& modes) {
        modes->for_each([&](const auto& mode, const auto& dcy) {
            for(const auto& prod : dcy.products) {
                if(done.find(prod) == done.end()) {
                    std::cout << entity_node{prod} << " [label=\"" << prod
                              << "\"];\n";
                    std::cout << entity_node{isot} << " -> "
                              << entity_node{prod} << " [label=\""
                              << mode.symbol << "\"];\n";
                    decay_of(elements, prod, done);
                }
            }
        });
    };

    elements.for_single(
      isot,
      callable_ref<void(
        const element_symbol&, ecs::manipulator<const decay_modes>& dm)>{func});
}
//------------------------------------------------------------------------------
static void decay_of(
  ecs::basic_manager<element_symbol>& elements,
  const element_symbol& isot) {
    std::set<element_symbol> done;
    std::cout << entity_node{isot} << " [label=\"" << isot << "\"];\n";

    decay_of(elements, isot, done);
}
//------------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    ctx.log().info("starting");

    ecs::basic_manager<element_symbol> elements;
    initialize(ctx, elements);

    element_symbol isot{"¹⁸⁰Tl"};

    std::cout << "digraph DecayChain {\n";
    std::cout << "rankdir=LR\n";
    std::cout << "label=\"Decay chain of " << isot << "\"\n";
    std::cout << "node [shape=plain]\n";

    decay_of(elements, isot);

    std::cout << "}\n";

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine
