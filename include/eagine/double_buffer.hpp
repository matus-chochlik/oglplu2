/**
 *  @file eagine/double_buffer.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_DOUBLE_BUFFER_HPP
#define EAGINE_DOUBLE_BUFFER_HPP

#include <array>

namespace eagine {

template <typename T>
class double_buffer {
public:
    double_buffer() = default;

    double_buffer(const T& initial)
      : _values{{initial, initial}} {
    }

    void swap() noexcept {
        _idx = !_idx;
    }

    T& front() noexcept {
        return _idx ? _values.back() : _values.front();
    }

    const T& front() const noexcept {
        return _idx ? _values.back() : _values.front();
    }

    T& back() noexcept {
        return _idx ? _values.front() : _values.back();
    }

    const T& back() const noexcept {
        return _idx ? _values.front() : _values.back();
    }

private:
    std::array<T, 2> _values{};
    bool _idx{false};
};

} // namespace eagine

#endif // EAGINE_DOUBLE_BUFFER_HPP
