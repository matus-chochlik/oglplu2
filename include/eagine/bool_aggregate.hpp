/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_BOOL_AGGREGATE_HPP
#define EAGINE_BOOL_AGGREGATE_HPP

namespace eagine {

/// @brief Class storing initially false value and logically or-ing other values.
/// @ingroup type_utils
class some_true {
public:
    /// @brief Logically or-s the stored state with the specified argument.
    constexpr auto operator()(bool b = true) noexcept -> auto& {
        _result |= b;
        return *this;
    }

    /// @brief Returns the current boolean state.
    constexpr operator bool() const noexcept {
        return _result;
    }

private:
    bool _result{false};
};

} // namespace eagine

#endif // EAGINE_BOOL_AGGREGATE_HPP
