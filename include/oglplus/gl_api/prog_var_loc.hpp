/**
 *  @file oglplus/gl_api/prog_var_loc.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_PROG_VAR_LOC_HPP
#define OGLPLUS_GL_API_PROG_VAR_LOC_HPP

#include "config.hpp"
#include <eagine/identifier.hpp>

namespace eagine {
namespace oglp {
//------------------------------------------------------------------------------
template <identifier_t TagId>
class prog_var_location {
    using int_type = gl_types::int_type;
    using uint_type = gl_types::uint_type;

    int_type _location{-1};

public:
    constexpr prog_var_location() noexcept = default;

    explicit constexpr prog_var_location(int_type init) noexcept
      : _location{init} {
    }

    bool is_active() const noexcept {
        return _location >= 0;
    }

    constexpr int_type location() const noexcept {
        return _location;
    }

    constexpr uint_type index() const noexcept {
        if(_location < 0) {
#ifdef GL_INVALID_INDEX
            return GL_INVALID_INDEX;
#endif
        }
        return uint_type(_location);
    }

    explicit constexpr operator int_type() const noexcept {
        return _location;
    }

    explicit constexpr operator bool() const noexcept {
        return is_active();
    }

    constexpr bool operator!() const noexcept {
        return !is_active();
    }

    friend constexpr bool operator==(
      prog_var_location a, prog_var_location b) noexcept {
        return a._location == b._location;
    }

    friend constexpr bool operator!=(
      prog_var_location a, prog_var_location b) noexcept {
        return a._location != b._location;
    }

    friend constexpr bool operator<(
      prog_var_location a, prog_var_location b) noexcept {
        return a._location < b._location;
    }
};
//------------------------------------------------------------------------------
using program_resource_location = prog_var_location<EAGINE_ID_V(Resource)>;
using vertex_attrib_location = prog_var_location<EAGINE_ID_V(VertexAttr)>;
using uniform_location = prog_var_location<EAGINE_ID_V(Uniform)>;
using subroutine_uniform_location = prog_var_location<EAGINE_ID_V(SubrtUnfrm)>;
using subroutine_location = prog_var_location<EAGINE_ID_V(Subroutine)>;
using frag_data_location = prog_var_location<EAGINE_ID_V(FragData)>;
//------------------------------------------------------------------------------
} // namespace oglp
} // namespace eagine

#endif // OGLPLUS_GL_API_PROG_VAR_LOC_HPP
