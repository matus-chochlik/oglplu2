/**
 *  @file oglplus/texgen/mandelbrot_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <cassert>
#include <iostream>
#include <set>
#include <string>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
mandelbrot_output::mandelbrot_output(node_intf& parent)
  : base_output(parent) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view mandelbrot_output::type_name() {
    return string_view("Mandelbrot");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type mandelbrot_output::value_type() {
    return slot_data_type::float_2;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& mandelbrot_output::definitions(
  std::ostream& result, compile_context& context) {
    if(already_defined(context)) {
        return result;
    }

    input_defs(result, context);

    opening_expr(result, context);

    result << "\tvec3 k = " << expr::norm_sample_coord{*this} << ";";
    result << std::endl;
    result << "\tvec2 c = k.xy;";
    result << std::endl;
    result << "\tvec2 z = vec2(0.0);";
    result << std::endl;
    result << "\tint i, max = 128;"; // TODO variable maximum?
    result << std::endl;
    result << "\tfor(i = 0; (i<max) && (distance(c, z) < 2.0); ++i)";
    result << std::endl;
    result << "\t{";
    result << std::endl;
    result << "\t	z = vec2(";
    result << std::endl;
    result << "\t		z.x * z.x - z.y * z.y + c.x,";
    result << std::endl;
    result << "\t		2.0 * z.x * z.y + c.y";
    result << std::endl;
    result << "\t	);";
    result << std::endl;
    result << "\t}";
    result << std::endl;
    result << "\treturn vec2(";
    result << std::endl;
    result << "\t	float(i)/float(max),";
    result << std::endl;
    result << "\t	distance(z, c)*0.5";
    result << std::endl;
    result << "\t);";
    result << std::endl;

    return closing_expr(result, context);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
