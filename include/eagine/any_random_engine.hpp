/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_ANY_RANDOM_ENGINE_HPP
#define EAGINE_ANY_RANDOM_ENGINE_HPP

#include "callable_ref.hpp"

namespace eagine {

/// @brief Type-erasing reference for standard random engine types.
template <typename Result>
class any_random_engine : public callable_ref<Result()> {
public:
    /// @brief Alias for the engine result type.
    using result_type = Result;

    /// @brief Constructor initializing reference to the actual engine.
    template <typename Engine>
    any_random_engine(Engine& engine) noexcept
      : callable_ref<Result()>{construct_from, engine}
      , _min{engine.min()}
      , _max{engine.max()} {}

    /// @brief The minimal result value.
    auto min() const noexcept -> result_type {
        return _min;
    }

    /// @brief The maximal result value.
    auto max() const noexcept -> result_type {
        return _max;
    }

private:
    result_type _min{0};
    result_type _max{0};
};

/// @brief Deduction guide for any_random_engine.
template <typename Engine>
any_random_engine(Engine&) -> any_random_engine<typename Engine::result_type>;

} // namespace eagine

#endif // EAGINE_ANY_RANDOM_ENGINE_HPP
