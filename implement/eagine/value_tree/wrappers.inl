/**
 *  @file eagine/value_tree/wrappers.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <stack>
#include <string>
#include <tuple>

namespace eagine::valtree {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void compound::traverse(visit_handler visit) {
    std::stack<attribute> atr;
    std::stack<span_size_t> pos;
    basic_string_path path{};

    atr.push(structure());
    pos.push(0);

    while(true) {
        EAGINE_ASSERT(atr.size() == pos.size());

        if(pos.top() < nested_count(atr.top())) {
            auto child{nested(atr.top(), pos.top())};
            if(const auto n{attribute_name(child)}) {
                path.push_back(n);
            } else {
                path.push_back(std::to_string(pos.top()));
            }
            if(visit(*this, child, path) && !is_link(atr.top())) {
                atr.push(child);
                pos.push(0);
                continue;
            }
        } else {
            atr.pop();
            pos.pop();
        }
        if(pos.empty()) {
            break;
        }
        ++pos.top();
        path.pop_back();
    }
}
//------------------------------------------------------------------------------
} // namespace eagine::valtree
