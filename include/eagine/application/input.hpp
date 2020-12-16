/**
 *  @file eagine/application/input.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_APPLICATION_INPUT_HPP
#define EAGINE_APPLICATION_INPUT_HPP

#include "../identifier.hpp"

namespace eagine::application {
//------------------------------------------------------------------------------
struct input_slot {
    input_slot() noexcept = default;
    input_slot(input_slot&&) = delete;
    input_slot(const input_slot&) = delete;
    auto operator=(input_slot&&) = delete;
    auto operator=(const input_slot&) = delete;
    virtual ~input_slot() noexcept = default;

    virtual auto id() noexcept -> identifier = 0;
};
//------------------------------------------------------------------------------
struct position_input : input_slot {
    virtual void position_changed(float ndcx, float ndcy, float ndcz) = 0;
};
//------------------------------------------------------------------------------
struct value_input : input_slot {
    virtual void value_changed(float value, float norm_delta) = 0;
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
