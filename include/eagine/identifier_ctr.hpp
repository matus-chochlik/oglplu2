/**
 *  @file eagine/identifier_ctr.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_IDENTIFIER_CTR_HPP
#define EAGINE_IDENTIFIER_CTR_HPP

#include "identifier.hpp"
#include "types.hpp"

namespace eagine {
//------------------------------------------------------------------------------
identifier byte_to_identifier(byte b) noexcept;
identifier dec_to_identifier(int i) noexcept;
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/identifier_ctr.inl>
#endif

#endif // EAGINE_IDENTIFIER_CTR_HPP
