/**
 *  .file oglplus/example/random.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_RANDOM_HPP
#define OGLPLUS_EXAMPLE_RANDOM_HPP

#include <eagine/span.hpp>
#include <memory>

namespace eagine {
//------------------------------------------------------------------------------
class example_args;
class example_params;
//------------------------------------------------------------------------------
struct example_random_generator {
    virtual ~example_random_generator() noexcept = default;

    virtual void uniform_01(span<float>) = 0;
};
//------------------------------------------------------------------------------
std::unique_ptr<example_random_generator> make_example_random_generator(
  example_args&, example_params&);
//------------------------------------------------------------------------------
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_RANDOM_HPP
