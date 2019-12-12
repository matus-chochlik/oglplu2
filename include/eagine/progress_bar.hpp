/**
 *  @file eagine/progress_bar.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_PROGRESS_BAR_HPP
#define EAGINE_PROGRESS_BAR_HPP

#include "string_span.hpp"
#include <string>

namespace eagine {
//------------------------------------------------------------------------------
template <typename Putter>
void format_progress_bar(
  Putter& put, int width, float min, float max, float prev, float curr);
//------------------------------------------------------------------------------
class progress_bar {
public:
    progress_bar() noexcept = default;

    progress_bar& set_width(int w) noexcept {
        _width = w < 0 ? 0 : w;
        return *this;
    };

    progress_bar& set_min(float min) noexcept {
        _min = min;
        return *this;
    }

    progress_bar& set_max(float max) noexcept {
        _max = max;
        return *this;
    }

    progress_bar& reformat() noexcept;

    progress_bar& update(float value) noexcept;

    string_view get() const noexcept {
        return {_buffer.c_str(), span_size_t(_idx)};
    }

private:
    int _width{80};
    float _min{-1.f};
    float _max{+1.f};
    float _prev{0.f};
    float _curr{0.f};
    std::size_t _idx{0};
    std::string _buffer;
};

} // namespace eagine

#include <eagine/progress_bar.inl>

#endif // EAGINE_PROGRESS_BAR_HPP
