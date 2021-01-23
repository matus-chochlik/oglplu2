/**
 *  @file eagine/application/state.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

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
    context_state(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(AppliState), parent}
      , _rand_eng{extract_or(_rand_seed, std::random_device{}())} {}

    auto advance_time() noexcept -> auto& {
        if(_fixed_fps) {
            _frame_time.advance(extract(_fixed_fps));
        } else {
            _frame_time.assign(
              std::chrono::duration<float>(run_time()).count());
        }
        _old_user_idle = _new_user_idle;
        _new_user_idle = true;
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
    valid_if_positive<float> _fixed_fps{
      cfg_extr<valid_if_positive<float>>("application.video.fixed_fps", 0.F)};

    valid_if_positive<std::default_random_engine::result_type> _rand_seed{
      cfg_extr<valid_if_positive<std::default_random_engine::result_type>>(
        "application.random.seed",
        0U)};

    std::default_random_engine _rand_eng;
    std::uniform_int_distribution<byte> _dist_uniform_byte{0x00, 0xFF};
    std::uniform_real_distribution<float> _dist_uniform_float_01{0.F, 1.F};
    std::normal_distribution<float> _dist_normal_float{0.F, 1.F};
};
//------------------------------------------------------------------------------
} // namespace eagine::application

#endif
