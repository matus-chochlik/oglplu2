/**
 *  .file oglplus/example/params.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "params.hpp"

namespace oglplus {

example_params::
example_params(void)
noexcept
 : _rand_seed(0)
 , _screenshot_time(3)
 , _fixed_fps(30)
 , _x_pos(64)
 , _y_pos(64)
 , _x_tiles(1)
 , _y_tiles(1)
 , _samples(4)
 , _color_bits(8)
 , _alpha_bits(0)
 , _depth_bits(24)
 , _stencil_bits(0)
 , _compat_ctxt(false)
 , _debug_ctxt(true)
 , _auto_tiles(true)
{ }

} // namespace oglplus
