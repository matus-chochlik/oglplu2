/**
 *  .file oglplus/example/wrapper.cpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_EXAMPLE_WRAPPER_HPP // NOLINT(llvm-header-guard)
#define OGLPLUS_EXAMPLE_WRAPPER_HPP

#include "../example.hpp"
#include "run_context.hpp"
#include <cassert>
#include <chrono>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
class example_wrapper {
private:
    example_context _context;

    std::unique_ptr<example> _example;

    bool _screenshot_done;

    using clock_type = std::chrono::system_clock;
    std::chrono::time_point<clock_type> _start{};
    std::chrono::time_point<clock_type> _now{};

    std::vector<char> _pixel_data;
    auto pixels() -> std::vector<char>&;

    std::vector<char> _textbuf;
    auto textbuf(std::size_t) -> std::vector<char>&;

public:
    example_wrapper(example_run_context&);

    auto context() noexcept -> example_context& {
        return _context;
    }

    auto is_ready() const -> bool;

    void destroy();

    auto next_frame() -> bool;

    void update();

    void render();

    void set_size(int width, int height);

    void set_mouse_btn(int i, bool pressed);

    void set_mouse_pos(int x, int y);

    void set_mouse_wheel(int w);
};
//------------------------------------------------------------------------------
} // namespace eagine

#endif // OGLPLUS_EXAMPLE_WRAPPER_HPP
