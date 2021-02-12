/**
 *  @file eagine/math/curve.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_MATH_CURVE_HPP
#define EAGINE_MATH_CURVE_HPP

#include "../assert.hpp"
#include "../integer_range.hpp"
#include "../memory/span_algo.hpp"
#include "../span.hpp"
#include "../types.hpp"
#include "../valid_if/positive.hpp"
#include "functions.hpp"
#include <cmath>
#include <vector>

namespace eagine::math {

/// @brief A sequence of Bezier curves, possibly connected at end points.
/// @ingroup math
/// @see CubicBezierLoop
///
/// This class stores the data for a sequence of connected Bezier curves
/// of a given @c Order. The begin of the i-th curve (segment) is equal
/// to the end of the (i-1)-th curve and the end of the i-th curve is
/// equal to the begin of the (i+1)-th curve. Between the begin and
/// end (control) points there is a fixed number (Order - 1) of curve control
/// points. The curves pass through the begin and end and are influenced
/// by the other control points.
template <typename Type, typename Parameter, span_size_t Order>
class bezier_curves {
private:
    static_assert(Order > 0);

    std::vector<Type> _points;
    bezier_t<Type, Order + 1> _bezier{};
    bool _connected;

public:
    /// @brief Returns whether the curves made from points are connected.
    static auto are_connected(const std::vector<Type>& points) noexcept
      -> bool {
        return ((points.size() - 1) != Order) &&
               ((points.size() - 1) % Order) == 0;
    }

    /// @brief Returns true if the individual curves are connected.
    auto is_connected() const noexcept -> bool {
        return _connected;
    }

    static auto are_separated(const std::vector<Type>& points) noexcept
      -> bool {
        return (points.size() % (Order + 1)) == 0;
    }

    /// @brief Returns true if the individual curves are disconnected.
    auto is_separated() const noexcept -> bool {
        return !_connected;
    }

    /// @brief checks if the sequence of control points is OK for this curve type.
    static auto points_are_ok(const std::vector<Type>& points) noexcept
      -> bool {
        return !points.empty() &&
               (are_connected(points) || are_separated(points));
    }

    /// @brief Creates the bezier curves from the control @c points.
    /// @pre points_are_ok(points)
    ///
    /// The number of points must be ((C * Order) + 1) or (C * (Order + 1))
    /// where @em C is the number of curves (segments) in the sequence.
    /// If both of the above are true then the curves are considered
    /// to be connected.
    bezier_curves(std::vector<Type> points)
      : _points{std::move(points)}
      , _connected{are_connected(_points)} {
        EAGINE_ASSERT(points_are_ok(_points));
    }

    /// @brief Creates the bezier curves from the control @c points.
    /// @pre points_are_ok(points)
    /// @pre are_connected(points) == connected
    ///
    /// The number of points must be ((C * Order) + 1) and connected
    /// or (C * (Order + 1)) and not(connected),
    /// where @em C is the number of curves (segments) in the sequence.
    bezier_curves(std::vector<Type> points, bool connected)
      : _points{std::move(points)}
      , _connected{connected} {
        EAGINE_ASSERT(points_are_ok(_points));
        EAGINE_ASSERT(are_connected(_points) == _connected);
    }

    /// @brief Creates the bezier curves from the control @c points.
    /// @pre points_are_ok(points)
    ///
    /// The number of points must be ((C * Order) + 1) or (C * (Order + 1))
    /// where @em C is the number of curves (segments) in the sequence.
    /// If both of the above are true then the curves are considered
    /// to be connected.
    template <typename P, typename S>
    bezier_curves(memory::basic_span<const Type, P, S>& points)
      : _points(points.begin(), points.end())
      , _connected{are_connected(_points)} {
        EAGINE_ASSERT(points_are_ok(_points));
    }

    /// @brief Creates the bezier curves from the control @c points.
    /// @pre points_are_ok(points)
    /// @pre are_connected(points) == connected
    ///
    /// The number of points must be ((C * Order) + 1) or (C * (Order + 1))
    /// where @em C is the number of curves (segments) in the sequence.
    /// If both of the above are true then the curves are considered
    /// to be connected.
    template <typename P, typename S>
    bezier_curves(memory::basic_span<Type, P, S>& points, bool connected)
      : _points(points.begin(), points.end())
      , _connected(connected) {
        EAGINE_ASSERT(points_are_ok(_points));
        EAGINE_ASSERT(are_connected(_points) == _connected);
    }

    auto segment_step() const noexcept -> span_size_t {
        EAGINE_ASSERT(points_are_ok(_points));
        return _connected ? Order : Order + 1;
    }

    /// @brief Returns the count of individual curves in the sequence.
    auto segment_count() const noexcept -> span_size_t {
        EAGINE_ASSERT(points_are_ok(_points));

        return _connected ? span_size(_points.size() - 1) / Order
                          : span_size(_points.size()) / (Order + 1);
    }

    /// @brief Returns the contol points of the curve.
    auto control_points() const noexcept -> const std::vector<Type>& {
        return _points;
    }

    /// @brief Wraps the parameter value to [0.0, 1.0].
    static auto wrap(Parameter t) noexcept -> Parameter {
        const Parameter zero{0};
        const Parameter one{1};
        if(t < zero) {
            t += std::floor(std::fabs(t)) + one;
        } else if(t > one) {
            t -= std::floor(t);
        }
        EAGINE_ASSERT(t >= zero && t <= one);
        return t;
    }

    /// @brief Gets the point on the curve at position t (must be in (0.0, 1.0)).
    auto position01(Parameter t) const noexcept -> Type {
        const Parameter zero{0};
        const Parameter one{1};

        if(t >= one) {
            t = zero;
        }
        EAGINE_ASSERT(t >= zero && t < one);

        const auto toffs = t * segment_count();
        const auto t_sub = toffs - std::floor(toffs);
        const auto poffs = span_size_t(toffs) * segment_step();
        EAGINE_ASSERT(poffs < span_size(_points.size()) - Order);

        return _bezier(t_sub, skip(view(_points), poffs));
    }

    /// @brief Gets the point on the curve at position t wrapped to [0.0, 1.0].
    auto position(Parameter t) const noexcept -> Type {
        return position01(wrap(t));
    }

    /// @brief Makes a sequence of points on the curve (n points per segment).
    void approximate(std::vector<Type>& dest, valid_if_positive<span_size_t> n)
      const noexcept {
        const auto sstep = segment_step();
        const auto s = segment_count();

        dest.resize(std_size(s * extract(n) + 1));

        auto p = dest.begin();
        const Parameter t_step = Parameter(1) / extract(n);

        for(auto i : integer_range(s)) {
            const auto poffs = i * sstep;
            auto t_sub = Parameter(0);
            for(auto j : integer_range(extract(n))) {
                EAGINE_MAYBE_UNUSED(j);
                EAGINE_ASSERT(p != dest.end());
                *p = Type(_bezier(t_sub, skip(view(_points), poffs)));
                ++p;

                t_sub += t_step;
            }
        }
        EAGINE_ASSERT(p != dest.end());
        *p = _points.back();
        ++p;
        EAGINE_ASSERT(p == dest.end());
    }

    /// @brief Returns a sequence of points on the curve (n points per segment).
    auto approximate(valid_if_positive<span_size_t> n) const
      -> std::vector<Type> {
        std::vector<Type> result;
        approximate(result, n);
        return result;
    }

    /// @brief Returns a derivative of this curve
    auto derivative() const noexcept
      -> bezier_curves<Type, Parameter, Order - 1> {
        const auto sstep = segment_step();
        const auto s = segment_count();

        std::vector<Type> new_points(std_size(s * Order));
        auto p = new_points.begin();

        for(auto i : integer_range(s)) {
            for(auto j : integer_range(Order)) {
                const auto k = i * sstep + j;
                EAGINE_ASSERT(p != new_points.end());
                *p = (_points[std_size(k + 1)] - _points[std_size(k)]) * Order;
                ++p;
            }
        }
        EAGINE_ASSERT(p == new_points.end());

        return {std::move(new_points), false};
    }
};

} // namespace eagine::math

#endif // EAGINE_MATH_CURVE_HPP
