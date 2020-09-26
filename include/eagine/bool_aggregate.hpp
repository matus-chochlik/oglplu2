/**
 *  @file eagine/bool_aggregate.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_BOOL_AGGREGATE_HPP
#define EAGINE_BOOL_AGGREGATE_HPP

namespace eagine {

class some_true {
public:
    constexpr auto operator()(bool b = true) noexcept -> auto& {
        if(b) {
            _result = true;
        }
        return *this;
    }

    constexpr operator bool() const noexcept {
        return _result;
    }

    constexpr auto operator!() const noexcept {
        return !_result;
    }

private:
    bool _result{false};
};

} // namespace eagine

#endif // EAGINE_BOOL_AGGREGATE_HPP
