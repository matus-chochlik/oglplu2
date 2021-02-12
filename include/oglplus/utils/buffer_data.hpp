/// @file oglplus/utils/buffer_data.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#ifndef OGLPLUS_UTILS_BUFFER_DATA_HPP
#define OGLPLUS_UTILS_BUFFER_DATA_HPP

#include <eagine/buffer_data.hpp>
#include <oglplus/gl_api/config.hpp>

namespace eagine::oglp {

using buffer_data_spec = eagine::buffer_data_spec<gl_types::sizeiptr_type>;

} // namespace eagine::oglp

#endif // OGLPLUS_UTILS_BUFFER_DATA_HPP
