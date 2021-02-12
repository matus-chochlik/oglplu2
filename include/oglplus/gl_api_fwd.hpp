/// @file oglplus/gl_api_fwd.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_GL_API_FWD_HPP
#define OGLPLUS_GL_API_FWD_HPP

namespace eagine::oglp {
//------------------------------------------------------------------------------
class gl_api_traits;

template <typename ApiTraits>
class basic_gl_api;

using gl_api = basic_gl_api<gl_api_traits>;
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_FWD_HPP
