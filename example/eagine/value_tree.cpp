/**
 *  @example eagine/value_tree.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/main.hpp>
#include <eagine/value_tree/json.hpp>
#include <iostream>
#include <memory>

namespace eagine {

int main(main_ctx& ctx) {
    auto& log = ctx.log();

    const string_view json_text(R"({
		"attribA" : {
			"attribB": 123
		},
		"attribC" : [
			456, 78.9, {"zero": 0}
		]
	})");

    const string_view n_a{"N/A"};

    if(auto json_tree{valtree::from_json_text(json_text, log)}) {
        log.info("parsed from json")
          .arg(
            EAGINE_ID(attribB),
            EAGINE_ID(int),
            json_tree.get<int>("attribA/attribB"),
            n_a)
          .arg(
            EAGINE_ID(attribC0),
            EAGINE_ID(int),
            json_tree.get<int>("attribC/0"),
            n_a)
          .arg(
            EAGINE_ID(attribC1),
            EAGINE_ID(float),
            json_tree.get<float>("attribC/1"),
            n_a)
          .arg(
            EAGINE_ID(attribC2z),
            EAGINE_ID(int),
            json_tree.get<int>("attribC/2/zero"),
            n_a);
    }

    return 0;
}

} // namespace eagine
