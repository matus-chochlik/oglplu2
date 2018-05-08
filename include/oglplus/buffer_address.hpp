/**
 *  @file oglplus/buffer_address.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_BUFFER_ADDRESS_1509260923_HPP
#define OGLPLUS_BUFFER_ADDRESS_1509260923_HPP

#if defined(GL_NV_shader_buffer_load)

namespace oglplus {

struct buffer_address {
    GLuint64EXT _addr;

    constexpr buffer_address(GLuint64EXT addr) noexcept
      : _addr(addr) {
    }
};

static inline GLuint64EXT
get_raw_address(buffer_address ba) noexcept {
    return ba._addr;
}

} // namespace oglplus

#endif // NV_shader_buffer_load

#endif // include guard
