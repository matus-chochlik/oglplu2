/**
 *  @file oglplus/context.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_CONTEXT_1509260923_HPP
#define OGLPLUS_CONTEXT_1509260923_HPP

#include "ctxt/capabilities.hpp"
#include "ctxt/viewport.hpp"
#include "ctxt/buffer_clearing.hpp"
#include "ctxt/object_lifetime.hpp"
#include "ctxt/drawing.hpp"

namespace oglplus {

class context
 : public ctxt::capability_state
 , public ctxt::viewport_state
 , public ctxt::buffer_clearing_state
 , public ctxt::buffer_clearing_ops
 , public ctxt::object_lifetime_ops
 , public ctxt::drawing_ops
{ };

} // namespace oglplus

#endif // include guard
