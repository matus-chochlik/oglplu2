/**
 *  @file oglplus/texgen/newton_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <cassert>
#include <iostream>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
newton_output::newton_output(node_intf& parent, newton_function func)
  : base_output(parent)
  , _function(func) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
newton_output::type_name() {
    return cstr_ref("Newton");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type
newton_output::value_type() {
    return slot_data_type::float_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref
newton_output::_func_name() const {
    if(_function == newton_function::xe3minus1) {
        return cstr_ref("fXe3Minus1");
    } else if(_function == newton_function::xe4minus1) {
        return cstr_ref("fXe4Minus1");
    }
    return cstr_ref();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
newton_output::definitions(std::ostream& result, compile_context& context) {
    if(already_defined(context))
        return result;

    input_defs(result, context);

    cstr_ref tag("complex_div");
    if(!context.has_tag(tag)) {
        result << "vec2 oglptgComplexDiv(vec2 a, vec2 b)";
        result << std::endl;
        result << "{";
        result << std::endl;
        result << "	float d = dot(b, b);";
        result << std::endl;
        result << "	return (d == 0.0)?a:vec2(";
        result << std::endl;
        result << "		(a.x*b.x + a.y*b.y) / d,";
        result << std::endl;
        result << "		(a.y*b.x - a.x*b.y) / d";
        result << std::endl;
        result << "	);";
        result << std::endl;
        result << "}";
        result << std::endl;

        context.add_tag(tag);
    }

    if(_function == newton_function::xe3minus1) {
        tag = cstr_ref("complex_xe3minus1");
        if(!context.has_tag(tag)) {
            result << "vec2 oglptgNewton_";
            result << _func_name() << "(vec2 n)";
            result << std::endl;
            result << "{";
            result << std::endl;
            result << "\treturn vec2(";
            result << std::endl;
            result << "\t	n.x*n.x*n.x-3.0*n.x*n.y*n.y-1.0,";
            result << std::endl;
            result << "\t	-n.y*n.y*n.y+3.0*n.x*n.x*n.y";
            result << std::endl;
            result << "\t);";
            result << std::endl;
            result << "}";
            result << std::endl;

            result << "vec2 oglptgNewton_d";
            result << _func_name() << "(vec2 n)";
            result << std::endl;
            result << "{";
            result << std::endl;
            result << "\treturn 3.0 * vec2(";
            result << std::endl;
            result << "\t	n.x*n.x - n.y*n.y,";
            result << std::endl;
            result << "\t	2.0 * n.x * n.y";
            result << std::endl;
            result << "\t);";
            result << std::endl;
            result << "}";
            result << std::endl;

            context.add_tag(tag);
        }
    } else if(_function == newton_function::xe4minus1) {
        tag = cstr_ref("complex_xe4minus1");
        if(!context.has_tag(tag)) {
            result << "vec2 oglptgNewton_";
            result << _func_name() << "(vec2 n)";
            result << std::endl;
            result << "{";
            result << std::endl;
            result << "\treturn vec2(";
            result << std::endl;
            result << "\t	n.x*n.x*n.x*n.x +";
            result << std::endl;
            result << "\t	n.y*n.y*n.y*n.y -";
            result << std::endl;
            result << "\t	6.0*n.x*n.x*n.y*n.y - 1.0,";
            result << std::endl;
            result << "\t	4.0*n.x*n.x*n.x*n.y -";
            result << std::endl;
            result << "\t	4.0*n.x*n.y*n.y*n.y";
            result << std::endl;
            result << "\t);";
            result << std::endl;
            result << "}";
            result << std::endl;

            result << "vec2 oglptgNewton_d";
            result << _func_name() << "(vec2 n)";
            result << std::endl;
            result << "{";
            result << std::endl;
            result << "\treturn 4.0 * vec2(";
            result << std::endl;
            result << "\t	 n.x*n.x*n.x - 3.0*n.x*n.y*n.y,";
            result << std::endl;
            result << "\t	-n.y*n.y*n.y + 3.0*n.x*n.x*n.y";
            result << std::endl;
            result << "\t);";
            result << std::endl;
            result << "}";
            result << std::endl;

            context.add_tag(tag);
        }
    }

    opening_expr(result, context);

    result << "\tvec3 k = " << expr::norm_sample_coord{*this} << ";";
    result << std::endl;
    result << "\tvec2 z = k.xy;";
    result << std::endl;
    result << "\tint i, max = 64;";
    result << std::endl;
    result << "\tfor(i = 0; i < max; ++i)";
    result << std::endl;
    result << "\t{";
    result << std::endl;
    result << "\t	vec2 zn = z - oglptgComplexDiv(";
    result << std::endl;

    result << "\t		oglptgNewton_" << _func_name() << "(z),";
    result << std::endl;
    result << "\t		oglptgNewton_d" << _func_name() << "(z)";
    result << std::endl;

    result << "\t	);";
    result << std::endl;
    result << "\t	if(distance(zn, z) < 0.00001) break;";
    result << std::endl;
    result << "\t	z = zn;";
    result << std::endl;
    result << "\t}";
    result << std::endl;
    result << "\treturn float(i)/float(max);";
    result << std::endl;

    return closing_expr(result, context);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
