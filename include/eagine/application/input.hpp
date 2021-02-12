/// @file eagine/application/input.hpp
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
class input_setup {
public:
    auto value_kinds(input_value_kinds init) noexcept -> auto& {
        _value_kinds = init;
        return *this;
    }

    auto relative() noexcept -> auto& {
        _value_kinds |= input_value_kind::relative;
        return *this;
    }

    auto absolute_norm() noexcept -> auto& {
        _value_kinds |= input_value_kind::absolute_norm;
        return *this;
    }

    auto absolute_free() noexcept -> auto& {
        _value_kinds |= input_value_kind::absolute_free;
        return *this;
    }

    auto any_value_kind() noexcept -> auto& {
        _value_kinds = all_input_value_kinds();
        return *this;
    }

    auto trigger() noexcept -> auto& {
        return absolute_free().absolute_norm();
    }

    auto invert(bool init = true) noexcept -> auto& {
        _invert = init;
        return *this;
    }

    auto has(input_value_kind kind) const noexcept -> bool {
        return _value_kinds.has(kind);
    }

    auto multiply(double mult) noexcept -> auto& {
        _multiplier = mult;
        return *this;
    }

    auto multiplier() const noexcept {
        return _invert ? -_multiplier : _multiplier;
    }

    auto only_if(bool& flag) noexcept -> auto& {
        _only_if = &flag;
        return *this;
    }

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

    explicit operator bool() const noexcept {
        return !are_equal(this->get(), 0.0);
    }
};
//------------------------------------------------------------------------------
using input_handler = callable_ref<void(const input&)>;
struct input_slot : std::tuple<message_id, input_handler> {
    using base = std::tuple<message_id, input_handler>;
    using base::base;

    auto id() const noexcept -> auto& {
        return std::get<0>(*this);
    }

    auto handler() const noexcept -> auto& {
        return std::get<1>(*this);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
