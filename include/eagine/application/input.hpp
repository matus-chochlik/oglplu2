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

#include "../bitfield.hpp"
#include "../message_id.hpp"
#include "../value_with_history.hpp"

namespace eagine::application {
//------------------------------------------------------------------------------
enum class input_value_kind : unsigned {
    relative = 1U << 0U,
    absolute_norm = 1U << 1U,
    absolute_free = 1U << 2U
};
using input_value_kinds = bitfield<input_value_kind>;

static inline auto operator|(input_value_kind l, input_value_kind r) noexcept
  -> input_value_kinds {
    return {l, r};
}

static inline auto all_input_value_kinds() noexcept -> input_value_kinds {
    return input_value_kind::relative | input_value_kind::absolute_norm |
           input_value_kind::absolute_free;
}
//------------------------------------------------------------------------------
template <typename T>
using input_value = value_with_history<T, 3>;

template <typename T>
using input_variable = variable_with_history<T, 3>;
//------------------------------------------------------------------------------
struct input_info {
    message_id signal_id{};
    input_value_kind value_kind{};

    constexpr input_info(message_id sig_id, input_value_kind kind) noexcept
      : signal_id{std::move(sig_id)}
      , value_kind{kind} {}
};
//------------------------------------------------------------------------------
class input : public input_value<double> {
public:
    template <typename T>
    input(const input_value<T>& value) noexcept
      : input_value<double>{value} {}

    explicit operator bool() const noexcept {
        return !are_equal(this->get(), 0.0);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
