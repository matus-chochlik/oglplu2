/**
 *  @file texgen/parser.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "parser.hpp"
#include "tokenizer.hpp"

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
void parser::begin() {
    _actions.begin();
}
//------------------------------------------------------------------------------
void parser::parse(input_stream) {
}
//------------------------------------------------------------------------------
void parser::finish() {
    _actions.finish();
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
