/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_APPLICATION_INPUT_HPP
#define EAGINE_APPLICATION_INPUT_HPP

#include "../bitfield.hpp"
#include "../callable_ref.hpp"
#include "../message_id.hpp"
#include "../value_with_history.hpp"

namespace eagine::application {
//------------------------------------------------------------------------------
/// @brief Application input value kind bits enumeration.
/// @ingroup application
/// @see input_value_kinds
enum class input_value_kind : unsigned {
    /// @brief Relative input value change.
    relative = 1U << 0U,
    /// @brief Absolute input value normalized to <-1, 1>.
    absolute_norm = 1U << 1U,
    /// @brief Absolute input value without bounds.
    absolute_free = 1U << 2U
};

/// @brief Application input value kind bitfield.
/// @ingroup application
/// @see input_value_kinds
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
/// @brief Alias for input value with history.
/// @ingroup application
/// @see input_variable
/// @see input_setup
/// @see input
template <typename T>
using input_value = value_with_history<T, 3>;

/// @brief Alias for input value with history.
/// @ingroup application
/// @see input_value
/// @see input_setup
/// @see input
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
/// @brief Class that managers user input state.
/// @ingroup application
class input_setup {
public:
    /// @brief Constructor with input kinds specification.
    auto value_kinds(input_value_kinds init) noexcept -> auto& {
        _value_kinds = init;
        return *this;
    }

    /// @brief Specifies that relative input values are tracked.
    /// @see absolute_norm
    /// @see absolute_free
    /// @see any_value_kind
    auto relative() noexcept -> auto& {
        _value_kinds |= input_value_kind::relative;
        return *this;
    }

    /// @brief Specifies that absolute normalized input values are tracked.
    /// @see relative
    /// @see absolute_free
    /// @see any_value_kind
    auto absolute_norm() noexcept -> auto& {
        _value_kinds |= input_value_kind::absolute_norm;
        return *this;
    }

    /// @brief Specifies that absolute unbounded input values are tracked.
    /// @see relative
    /// @see absolute_norm
    /// @see any_value_kind
    auto absolute_free() noexcept -> auto& {
        _value_kinds |= input_value_kind::absolute_free;
        return *this;
    }

    /// @brief Specifies that input values of any kind are tracked.
    /// @see relative
    /// @see absolute_norm
    /// @see absolute_free
    auto any_value_kind() noexcept -> auto& {
        _value_kinds = all_input_value_kinds();
        return *this;
    }

    /// @brief Indicates if values of the specified kind are tracked.
    auto has(input_value_kind kind) const noexcept -> bool {
        return _value_kinds.has(kind);
    }

    /// @brief Specifies that this is a trigger-like input.
    /// @see absolute_norm
    /// @see absolute_free
    auto trigger() noexcept -> auto& {
        return absolute_free().absolute_norm();
    }

    /// @brief Specifies that the raw value from the input source should be inverted.
    auto invert(bool init = true) noexcept -> auto& {
        _invert = init;
        return *this;
    }

    /// @brief Specifies the multiplier for the raw value from the input source.
    auto multiply(double mult) noexcept -> auto& {
        _multiplier = mult;
        return *this;
    }

    /// @brief Returns the raw input value multiplier and the inverse setting.
    auto multiplier() const noexcept {
        return _invert ? -_multiplier : _multiplier;
    }

    /// @brief Registers a flag that "switches" the input on and off.
    /// @see is_applicable
    auto only_if(bool& flag) noexcept -> auto& {
        _only_if = &flag;
        return *this;
    }

    /// @brief Checks if an input value is currently applicable.
    /// @see only_if
    auto is_applicable() const noexcept {
        return !_only_if || *_only_if;
    }

private:
    double _multiplier{1.0};
    bool* _only_if{nullptr};
    input_value_kinds _value_kinds{};
    bool _invert{false};
};
//------------------------------------------------------------------------------
/// @brief Class representing a user input.
/// @ingroup application
class input : public input_value<double> {
public:
    template <typename T>
    input(
      const input_value<T>& value,
      const input_info&,
      const input_setup& setup) noexcept
      : input_value<double>{transform(
          [&](auto elem) { return double(setup.multiplier() * elem); },
          value)} {}

    /// @brief Indicates if the current value is non-zero.
    explicit operator bool() const noexcept {
        return !are_equal(this->get(), 0.0);
    }
};
//------------------------------------------------------------------------------
/// @brief Alias for a input handler callable reference.
/// @ingroup application
using input_handler = callable_ref<void(const input&)>;

/// @brief Class that allows binding of a user input device to a handler callable.
/// @ingroup application
struct input_slot : std::tuple<message_id, input_handler> {
    using base = std::tuple<message_id, input_handler>;
    using base::base;

    /// @brief Descriptive id of this input slot (what it accomplishes).
    auto id() const noexcept -> auto& {
        return std::get<0>(*this);
    }

    /// @brief Reference to a callable object bound to the input.
    auto handler() const noexcept -> auto& {
        return std::get<1>(*this);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
