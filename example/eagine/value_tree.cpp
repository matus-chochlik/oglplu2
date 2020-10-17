/**
 *  @example eagine/value_tree.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/main.hpp>
#include <eagine/value_tree/filesystem.hpp>
#include <eagine/value_tree/json.hpp>
#include <eagine/value_tree/yaml.hpp>
#include <iostream>
#include <memory>

namespace eagine {

auto main(main_ctx& ctx) -> int {
    auto& log = ctx.log();
    const string_view n_a{"N/A"};

    auto path = [](string_view str) {
        return basic_string_path(str, EAGINE_TAG(split_by), "/");
    };

    auto visitor = [&ctx](
                     valtree::compound& c,
                     const valtree::attribute& a,
                     const basic_string_path& p) {
        ctx.log()
          .info("visit")
          .arg(EAGINE_ID(nested), c.nested_count(a))
          .arg(EAGINE_ID(values), c.value_count(a))
          .arg(EAGINE_ID(isLink), EAGINE_ID(bool), c.is_link(a))
          .arg(EAGINE_ID(canonType), c.canonical_type(a))
          .arg(EAGINE_ID(path), p.as_string("/", c.nested_count(a) > 0))
          .arg(EAGINE_ID(name), a.name());
        return true;
    };

    const string_view json_text(R"({
		"attribA" : {
			"attribB": 123
		},
		"attribC" : [
			45, "six", 78.9, {"zero": false}
		]
	})");

    if(auto json_tree{valtree::from_json_text(json_text, log)}) {
        log.info("parsed from json")
          .arg(
            EAGINE_ID(attribB),
            EAGINE_ID(int),
            json_tree.get<int>(path("attribA/attribB")),
            n_a)
          .arg(
            EAGINE_ID(attribC0),
            EAGINE_ID(int),
            json_tree.get<int>(path("attribC/0")),
            n_a)
          .arg(
            EAGINE_ID(attribC1),
            EAGINE_ID(string),
            json_tree.get<std::string>(path("attribC/1")),
            n_a)
          .arg(
            EAGINE_ID(attribC2),
            EAGINE_ID(float),
            json_tree.get<float>(path("attribC/2")),
            n_a)
          .arg(
            EAGINE_ID(attribC3z),
            EAGINE_ID(bool),
            json_tree.get<bool>(path("attribC/3/zero")),
            n_a);
        json_tree.traverse(valtree::compound::visit_handler(visitor));
    }

    const string_view yaml_text(
      "attribA:\n"
      "    attribB: 123\n"
      "attribC: [45, six, 78.9, zero: false]\n");

    if(auto yaml_tree{valtree::from_yaml_text(yaml_text, log)}) {
        log.info("parsed from yaml")
          .arg(
            EAGINE_ID(attribB),
            EAGINE_ID(int),
            yaml_tree.get<int>(path("attribA/attribB")),
            n_a)
          .arg(
            EAGINE_ID(attribC0),
            EAGINE_ID(int),
            yaml_tree.get<int>(path("attribC/0")),
            n_a)
          .arg(
            EAGINE_ID(attribC1),
            EAGINE_ID(string),
            yaml_tree.get<std::string>(path("attribC/1")),
            n_a)
          .arg(
            EAGINE_ID(attribC2),
            EAGINE_ID(float),
            yaml_tree.get<float>(path("attribC/2")),
            n_a)
          .arg(
            EAGINE_ID(attribC3z),
            EAGINE_ID(bool),
            yaml_tree.get<bool>(path("attribC/3/zero")),
            n_a);
        yaml_tree.traverse(valtree::compound::visit_handler(visitor));
    }

    if(auto path_arg{ctx.args().find("--fs-tree").next()}) {
        log.info("opening ${root} filesystem tree")
          .arg(EAGINE_ID(root), path_arg.get());
        if(auto fs_tree{valtree::from_filesystem_path(path_arg, log)}) {
            fs_tree.traverse(valtree::compound::visit_handler(visitor));
        }
    }

    return 0;
}

} // namespace eagine
