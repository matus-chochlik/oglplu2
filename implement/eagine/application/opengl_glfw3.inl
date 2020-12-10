/**
 *  @file eagine/application/opengl_glfw3.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

namespace eagine::application {

#include <eagine/maybe_unused.hpp>
#include <oglplus/config/basic.hpp>

#if OGLPLUS_GLFW3_FOUND

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#endif
#include <GLFW/glfw3.h>
#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // OGLPLUS_GLFW3_FOUND
//------------------------------------------------------------------------------
class glfw3_opengl_context : public opengl_context {
public:
    auto is_implemented() const noexcept -> bool final;
    auto implementation_name() const noexcept -> string_view final;

    auto initialize(execution_context&) -> bool final;
    void cleanup(execution_context&) final;
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_context::is_implemented() -> bool {
    return bool(OGLPLUS_GLFW3_FOUND);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_context::implementation_name() const noexcept -> string_view {
    return {"GLFW3"};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto glfw3_opengl_context::initialize(execution_context&) -> bool {
    // TODO
    return false;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
void glfw3_opengl_context::cleanup(execution__context&) {
    // TODO
}
//------------------------------------------------------------------------------
auto make_glfw3_context(execution_context&) -> std::unique_ptr<opengl_context> {
    return {std::make_unique<glfw3_opengl_context>()};
}
//------------------------------------------------------------------------------
} // namespace eagine::application
