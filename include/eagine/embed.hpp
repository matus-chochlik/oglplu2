/**
 *  @file eagine/embed.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_EMBED_HPP
#define EAGINE_EMBED_HPP

#include "identifier.hpp"
#include "int_constant.hpp"
#include "memory/block.hpp"
#include "string_span.hpp"

namespace eagine {

extern memory::const_block get_embedded_resource(identifier);

memory::const_block embed(identifier res_id, string_view) noexcept {
    return get_embedded_resource(res_id);
}

} // namespace eagine

#endif // EAGINE_EMBED_HPP
