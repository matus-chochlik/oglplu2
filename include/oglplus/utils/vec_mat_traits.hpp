/**
 *  @file oglplus/utils/vec_mat_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef OGLPLUS_UTILS_VEC_MAT_TRAITS_1509260923_HPP
#define OGLPLUS_UTILS_VEC_MAT_TRAITS_1509260923_HPP

#include <eagine/vec_mat_traits.hpp>

namespace oglplus {

using eagine::is_known_matrix_type;
using eagine::is_known_matrix_type_v;
using eagine::is_known_vector_type;
using eagine::is_known_vector_type_v;

using eagine::canonical_compound_type;
using eagine::canonical_compound_type_t;
using eagine::canonical_element_type;
using eagine::canonical_element_type_t;
using eagine::has_canonical_type;

using eagine::element_view;
using eagine::is_row_major;

} // namespace oglplus

#endif // include guard
