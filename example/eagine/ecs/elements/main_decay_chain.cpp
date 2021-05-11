/// @example eagine/ecs/elements/main_decay_chain.cpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include "components.hpp"
#include "entity.hpp"
#include "init.hpp"
#include "relations.hpp"
#include <eagine/ecs/basic_manager.hpp>
#include <eagine/ecs/cmp_storage.hpp>
#include <eagine/ecs/entity/string.hpp>
#include <eagine/ecs/rel_storage.hpp>
#include <eagine/ecs/storage_caps.hpp>
#include <eagine/logging/logger.hpp>
#include <eagine/main.hpp>
#include <eagine/string_algo.hpp>
#include <array>
#include <iostream>
#include <set>

namespace eagine {
//------------------------------------------------------------------------------
struct entity_node {
    const element_symbol& sym;
    int branch;
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
    return out << "E" << sym << "_" << en.branch;
}
//------------------------------------------------------------------------------
static void decay_of(
  ecs::basic_manager<element_symbol>& elements,
  const element_symbol& isot,
  int branch,
  std::set<element_symbol>& done) {

    int d = 0;
    auto func = [&](const auto&, auto& modes) {
        modes->for_each([&](const auto& mode, const auto& dcy) {
            const auto direct = dcy.products.size() == 1;
            if(!direct) {
                std::cout << "D" << d << "_" << entity_node{isot, branch}
                          << " [shape=point];\n";
                std::cout << entity_node{isot, branch} << " -> "
                          << "D" << d << "_" << entity_node{isot, branch}
                          << " [label=\"" << mode.symbol
                          << "\", arrowhead=none];\n";
            }

            for(const auto& prod : dcy.products) {
                std::cout << entity_node{prod, branch} << " [label=\"" << prod
                          << "\"];\n";

                if(direct) {
                    std::cout << entity_node{isot, branch} << " -> "
                              << entity_node{prod, branch} << " [label=\""
                              << mode.symbol << "\"];\n";
                } else {
                    std::cout << "D" << d << "_" << entity_node{isot, branch}
                              << " -> " << entity_node{prod, branch} << "\n";
                }
                done.insert(isot);

                if(done.find(prod) == done.end()) {
                    decay_of(elements, prod, branch, done);
                }
            }
            ++d;
        });
    };

    elements.for_single<const decay_modes>(isot, {construct_from, func});
}
//------------------------------------------------------------------------------
static void decay_of(
  ecs::basic_manager<element_symbol>& elements,
  string_view sym,
  int branch) {

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
    std::string isot(to_string(sym));
    string_replace(isot, view(dict));

    std::set<element_symbol> done;
    std::cout << entity_node{isot, branch} << " [label=\"" << isot << "\"];\n";

    decay_of(elements, isot, branch, done);
}
//------------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------------
auto main(main_ctx& ctx) -> int {
    ctx.log().info("starting");

    ecs::basic_manager<element_symbol> elements;
    initialize(ctx, elements);

    std::cout << "digraph DecayChain {\n";
    std::cout << "rankdir=LR\n";
    std::cout << "overlap=false\n";
    std::cout << "concentrate=false\n";
    std::cout << "ranksep=0.33\n";
    std::cout << "nodesep=0.50\n";
    std::cout << "node [shape=egg]\n";

    if(ctx.args().none()) {
        std::cout << "label=\"Decay chains of ²³⁸U\"\n";
        decay_of(elements, "²³⁸U", 0);
    } else {
        std::cout << "label=\"Decay chains of ";
        for(auto arg : ctx.args()) {
            if(!arg.is_first()) {
                std::cout << ",";
            }
            std::cout << arg;
        }
        std::cout << "\"\n";

        for(auto arg : ctx.args()) {
            decay_of(elements, arg.get(), arg.position());
        }
    }

    std::cout << "}\n";

    return 0;
}
//------------------------------------------------------------------------------
} // namespace eagine
