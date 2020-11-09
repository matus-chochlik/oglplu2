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
#include <eagine/string_algo.hpp>
#include <array>
#include <iostream>
#include <set>

namespace eagine {
//------------------------------------------------------------------------------
struct entity_node {
    const element_symbol& sym;
};

static auto operator<<(std::ostream& out, const entity_node& en)
  -> std::ostream& {
    static const std::array<std::tuple<string_view, string_view>, 11> dict{
      {{"⁰", "0"},
       {"¹", "1"},
       {"²", "2"},
       {"³", "3"},
       {"⁴", "4"},
       {"⁵", "5"},
       {"⁶", "6"},
       {"⁷", "7"},
       {"⁸", "8"},
       {"⁹", "9"},
       {"ᵐ", "m"}}};

    std::string sym{en.sym};
    string_replace(sym, view(dict));
    return out << "E" << sym;
}
//------------------------------------------------------------------------------
static void decay_of(
  ecs::basic_manager<element_symbol>& elements,
  const element_symbol& isot,
  std::set<element_symbol>& done) {

    int d = 0;
    auto func = [&](const auto&, auto& modes) {
        modes->for_each([&](const auto& mode, const auto& dcy) {
            const auto direct = dcy.products.size() == 1;
            if(!direct) {
                std::cout << "D" << d << "_" << entity_node{isot}
                          << " [shape=point];\n";
                std::cout << entity_node{isot} << " -> "
                          << "D" << d << "_" << entity_node{isot}
                          << " [label=\"" << mode.symbol
                          << "\", arrowhead=none];\n";
            }

            for(const auto& prod : dcy.products) {
                std::cout << entity_node{prod} << " [label=\"" << prod
                          << "\"];\n";

                if(direct) {
                    std::cout << entity_node{isot} << " -> "
                              << entity_node{prod} << " [label=\""
                              << mode.symbol << "\"];\n";
                } else {
                    std::cout << "D" << d << "_" << entity_node{isot} << " -> "
                              << entity_node{prod} << "\n";
                }
                done.insert(isot);

                if(done.find(prod) == done.end()) {
                    decay_of(elements, prod, done);
                }
            }
            ++d;
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

    if(auto arg{ctx.args().get(1)}) {
        const std::array<std::tuple<string_view, string_view>, 11> dict{
          {{"0", "⁰"},
           {"1", "¹"},
           {"2", "²"},
           {"3", "³"},
           {"4", "⁴"},
           {"5", "⁵"},
           {"6", "⁶"},
           {"7", "⁷"},
           {"8", "⁸"},
           {"9", "⁹"},
           {"*", "ᵐ"}}};

        isot = arg.to_string();
        string_replace(isot, view(dict));
    }

    std::cout << "digraph DecayChain {\n";
    std::cout << "rankdir=LR\n";
    std::cout << "overlap=false\n";
    std::cout << "concentrate=false\n";
    std::cout << "ranksep=0.33\n";
    std::cout << "nodesep=0.50\n";
    std::cout << "label=\"Decay chain of " << isot << "\"\n";
    std::cout << "node [shape=egg]\n";

    decay_of(elements, isot);

    std::cout << "}\n";

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine
