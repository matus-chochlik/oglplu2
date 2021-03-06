/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef TEXGEN_PARSER_HPP // NOLINT(llvm-header-guard)
#define TEXGEN_PARSER_HPP

#include "input_stream.hpp"
#include "semantic_actions.hpp"

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
class parser {
public:
    parser(semantic_actions actions) noexcept
      : _actions(std::move(actions)) {}

    void begin();
    void parse(input_stream input);
    void finish();

private:
    semantic_actions _actions;
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen

#endif // TEXGEN_PARSER_HPP
