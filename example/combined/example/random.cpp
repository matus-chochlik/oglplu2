/**
 *  .file oglplus/example/random.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "random.hpp"
#include "args.hpp"
#include "params.hpp"
#include <eagine/memory/span_algo.hpp>
#include <random>

namespace eagine {
//------------------------------------------------------------------------------
class random_generator_impl : public example_random_generator {
public:
    random_generator_impl(example_args& args, example_params& params)
      : _gen{_get_seed(args, params)} {
    }

    void uniform_01(span<float> dest) final {
        generate(dest, [this] { return _dist_uniform_float_01(_gen); });
    }

private:
    std::mt19937 _gen;
    std::uniform_real_distribution<float> _dist_uniform_float_01{0.f, 1.f};

    static std::random_device::result_type _get_seed(
      example_args&, example_params& params) {
        if(auto opt_seed{params.rand_seed()}) {
            return extract(opt_seed);
        } else {
            return std::random_device()();
        }
    }
};
//------------------------------------------------------------------------------
std::unique_ptr<example_random_generator> make_example_random_generator(
  example_args& args, example_params& params) {
    return std::make_unique<random_generator_impl>(args, params);
}
//------------------------------------------------------------------------------
} // namespace eagine
