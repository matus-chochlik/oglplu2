/// @file eagine/application/state.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_APPLICATION_STATE_HPP
#define EAGINE_APPLICATION_STATE_HPP

#include "../main_ctx_object.hpp"
#include "../valid_if/positive.hpp"
#include "state_view.hpp"
#include <random>

namespace eagine::application {
//------------------------------------------------------------------------------
class context_state
  : public main_ctx_object
  , public context_state_view {

public:
    context_state(main_ctx_parent parent);

    auto advance_time() noexcept -> auto& {
        if(EAGINE_UNLIKELY(_fixed_fps)) {
            _frame_time.advance(1.F / extract(_fixed_fps));
        } else {
            _frame_time.assign(
              std::chrono::duration<float>(run_time()).count());
        }
        return *this;
    }

    auto update_activity() noexcept -> context_state&;

    auto notice_user_active() noexcept -> auto& {
        _new_user_idle = false;
        return *this;
    }

    void random_uniform(span<byte> dest) {
        generate(dest, [this] { return _dist_uniform_byte(_rand_eng); });
    }

    void random_uniform_01(span<float> dest) {
        generate(dest, [this] { return _dist_uniform_float_01(_rand_eng); });
    }

    void random_normal(span<float> dest) {
        generate(dest, [this] { return _dist_normal_float(_rand_eng); });
    }

private:
    valid_if_positive<float> _fixed_fps;

    std::chrono::duration<float> _sim_activity_for;

    valid_if_positive<std::default_random_engine::result_type> _rand_seed;
    std::default_random_engine::result_type _rand_init;

    std::default_random_engine _rand_eng;
    std::uniform_int_distribution<byte> _dist_uniform_byte{0x00, 0xFF};
    std::uniform_real_distribution<float> _dist_uniform_float_01{0.F, 1.F};
    std::normal_distribution<float> _dist_normal_float{0.F, 1.F};
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#include <eagine/application/state.inl>

#endif
