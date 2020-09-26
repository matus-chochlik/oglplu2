/**
 *  @file texgen/validator.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef TEXGEN_VALIDATOR_HPP // NOLINT(llvm-header-guard)
#define TEXGEN_VALIDATOR_HPP

#include "semantic_actions.hpp"

namespace eagine::oglp::texgen {
//------------------------------------------------------------------------------
class validator : public semantic_actions_intf {
    void begin() final;
    void finish() final;
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp::texgen

#endif // TEXGEN_VALIDATOR_HPP
