/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_GL_API_PROG_VAR_LOC_HPP
#define OGLPLUS_GL_API_PROG_VAR_LOC_HPP

#include "config.hpp"
#include <eagine/identifier.hpp>

namespace eagine::oglp {
//------------------------------------------------------------------------------
/// @brief Class wrapping GL shader program variable location.
/// @ingroup gl_api_wrap
template <identifier_t TagId>
class prog_var_location {
    using int_type = gl_types::int_type;
    using uint_type = gl_types::uint_type;

public:
    /// @brief Default constructor.
    /// @post !is_active()
    constexpr prog_var_location() noexcept = default;

    /// @brief Explicit location initialization.
    explicit constexpr prog_var_location(int_type init) noexcept
      : _location{init} {}

    /// @brief Indicates if this instance wraps an active program variable.
    auto is_active() const noexcept -> bool {
        return _location >= 0;
    }

    /// @brief Indicates if this instance wraps an active program variable.
    /// @see is_active
    explicit constexpr operator bool() const noexcept {
        return is_active();
    }

    /// @brief Returns the location value.
    constexpr auto location() const noexcept -> int_type {
        return _location;
    }

    constexpr auto index() const noexcept -> uint_type {
        if(_location < 0) {
#ifdef GL_INVALID_INDEX
            return GL_INVALID_INDEX;
#endif
        }
        return uint_type(_location);
    }

    /// @brief Explicit conversion to the variable location value.
    explicit constexpr operator int_type() const noexcept {
        return _location;
    }

    /// @brief Equality comparison (compares the location numeric value).
    friend constexpr auto
    operator==(prog_var_location a, prog_var_location b) noexcept {
        return a._location == b._location;
    }

    /// @brief Nonequality comparison (compares the location numeric value).
    friend constexpr auto
    operator!=(prog_var_location a, prog_var_location b) noexcept {
        return a._location != b._location;
    }

    /// @brief Less-than comparison (compares the location numeric value).
    friend constexpr auto
    operator<(prog_var_location a, prog_var_location b) noexcept {
        return a._location < b._location;
    }

private:
    int_type _location{-1};
};
//------------------------------------------------------------------------------
/// @brief Alias for generic shader program resource location wrapper.
/// @ingroup gl_api_wrap
/// @see vertex_attrib_location
/// @see uniform_location
/// @see subroutine_uniform_location
/// @see subroutine_location
/// @see frag_data_location
/// @see uniform_block_index
/// @see shader_storage_block_index
using program_resource_location = prog_var_location<EAGINE_ID_V(Resource)>;

/// @brief Alias for program vertex attribute location wrapper.
/// @ingroup gl_api_wrap
/// @see program_resource_location
/// @see uniform_location
/// @see subroutine_uniform_location
/// @see subroutine_location
/// @see frag_data_location
/// @see uniform_block_index
/// @see shader_storage_block_index
using vertex_attrib_location = prog_var_location<EAGINE_ID_V(VertexAttr)>;

/// @brief Alias for shader program uniform location wrapper.
/// @ingroup gl_api_wrap
/// @see program_resource_location
/// @see vertex_attrib_location
/// @see subroutine_uniform_location
/// @see subroutine_location
/// @see frag_data_location
/// @see uniform_block_index
/// @see shader_storage_block_index
using uniform_location = prog_var_location<EAGINE_ID_V(Uniform)>;

/// @brief Alias for shader program subroutine uniform location wrapper.
/// @ingroup gl_api_wrap
/// @see program_resource_location
/// @see vertex_attrib_location
/// @see uniform_location
/// @see subroutine_location
/// @see frag_data_location
/// @see uniform_block_index
/// @see shader_storage_block_index
using subroutine_uniform_location = prog_var_location<EAGINE_ID_V(SubrtUnfrm)>;

/// @brief Alias for shader program subroutine location wrapper.
/// @ingroup gl_api_wrap
/// @see program_resource_location
/// @see vertex_attrib_location
/// @see uniform_location
/// @see subroutine_uniform_location
/// @see frag_data_location
/// @see uniform_block_index
/// @see shader_storage_block_index
using subroutine_location = prog_var_location<EAGINE_ID_V(Subroutine)>;

/// @brief Alias for shader program fragment data variable location wrapper.
/// @ingroup gl_api_wrap
/// @see program_resource_location
/// @see vertex_attrib_location
/// @see uniform_location
/// @see subroutine_uniform_location
/// @see subroutine_location
/// @see uniform_block_index
/// @see shader_storage_block_index
using frag_data_location = prog_var_location<EAGINE_ID_V(FragData)>;

/// @brief Alias for shader program uniform block location wrapper.
/// @ingroup gl_api_wrap
/// @see program_resource_location
/// @see vertex_attrib_location
/// @see uniform_location
/// @see subroutine_uniform_location
/// @see subroutine_location
/// @see frag_data_location
/// @see shader_storage_block_index
using uniform_block_index = prog_var_location<EAGINE_ID_V(UniformBlk)>;

/// @brief Alias for program shader storage block location wrapper.
/// @ingroup gl_api_wrap
/// @see program_resource_location
/// @see vertex_attrib_location
/// @see uniform_location
/// @see subroutine_uniform_location
/// @see subroutine_location
/// @see frag_data_location
/// @see uniform_block_index
using shader_storage_block_index = prog_var_location<EAGINE_ID_V(ShdrStrBlk)>;
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_PROG_VAR_LOC_HPP
