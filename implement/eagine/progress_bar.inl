/// @file eagine/progress_bar.inl
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

namespace eagine {
//------------------------------------------------------------------------------
template <typename Putter>
inline void format_progress_bar(
  Putter& put,
  int width,
  float min,
  float max,
  float prev,
  float curr) {
    int i = 0;
    if(min < max) {
        const float inorm = 1.F / (max - min);
        const float pcoef = (prev - min) * inorm;
        const float ccoef = (curr - min) * inorm;
        const float ppos = pcoef * float(width);
        const float cpos = ccoef * float(width);
        const auto pn = int(ppos);
        const auto cn = int(cpos);

        const auto do_put = [&put](const char* str) {
            while(char c = *str++) {
                put(c);
            }
        };

        while(i < cn) {
            do_put("█");
            ++i;
        }

        if((pn + 1) < cn) {
            do_put("▙");
            ++i;
        } else if(pn > cn) {
            do_put("▛");
            ++i;
        } else if(i < width) {
            const char* parts[9] = {
              " ", "▏", "▎", "▍", "▌", "▋", "▊", "▉", "█"};
            do_put(parts[int(9 * (cpos - float(cn)))]);
            ++i;
        }

        while(i < width) {
            put(' ');
            ++i;
        }
    } else {
        while(i < width) {
            put(' ');
            ++i;
        }
    }
}
//------------------------------------------------------------------------------
inline auto progress_bar::reformat() noexcept -> progress_bar& {
    _idx = 0;
    auto put = [this](char c) {
        if(_idx >= _buffer.size()) {
            _buffer.resize(_idx + 1);
        }
        _buffer[_idx++] = c;
    };
    format_progress_bar(put, _width, _min, _max, _prev, _curr);
    put('\0');
    return *this;
}
//------------------------------------------------------------------------------
inline auto progress_bar::update(float value) noexcept -> progress_bar& {
    if(value < _min) {
        value = _min;
    }
    if(value > _max) {
        value = _max;
    }
    _prev = _curr;
    _curr = value;

    return *this;
}
//------------------------------------------------------------------------------
} // namespace eagine
