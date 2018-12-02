/**
 *  @file oglplus/texgen/random_node.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/math/constants.hpp>
#include <cassert>
#include <iostream>
#include <string>

namespace oglplus {
namespace texgen {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
random_output::random_output(node_intf& parent)
  : base_output(parent)
  , seed(parent, cstr_ref("Seed"), 1.f, 1.f, 1.f)
  , dims(3) {
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
cstr_ref random_output::type_name() {
    return cstr_ref("Random");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type random_output::value_type() {
    assert(dims >= 1 && dims <= 4);
    return make_data_type(scalar_data_type::float_, dims);
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
random_output::definitions(std::ostream& out, compile_context& ctxt) {
    if(already_defined(ctxt))
        return out;
    assert(dims >= 1 && dims <= 4);

    input_defs(out, ctxt);
    opening_expr(out, ctxt);

    slot_data_type vec3_type = slot_data_type::float_3;

    out << "\tvec3 s = " << expr::normalized_coord{*this};
    out << ";" << std::endl;
    out << "\ts += ";
    out << expr::conversion_prefix{seed.value_type(), vec3_type};
    out << expr::output_id{seed.output(), ctxt};
    out << expr::render_param_pass{seed.output()};
    out << expr::conversion_suffix{seed.value_type(), vec3_type};
    out << ";" << std::endl;

    const decltype(eagine::math::phi) sdm[4] = {
      eagine::math::phi,
      1 / eagine::math::phi,
      eagine::math::phi * eagine::math::phi,
      eagine::math::phi / eagine::math::phi};

    for(span_size_t d = 0; d < dims; ++d) {
        auto s = std::fmod(get_id() / sdm[d], 100.0);
        auto cx = std::fmod(s * get_id() / 11, 100.0);
        auto cy = std::fmod(s * get_id() / 13, 100.0);
        auto cz = std::fmod(s * get_id() / 17, 100.0);

        out << "\tvec3 c" << d << " = vec3(";
        out << float(cx) << ", ";
        out << float(cy) << ", ";
        out << float(cz) << ");";
        out << std::endl;
    }

    out << "\tvec3 m = vec3(12.9898, 4.1414, 78.233);" << std::endl;
    out << "\treturn " << data_type_name(value_type()) << "(" << std::endl;
    for(span_size_t d = 0; d < dims; ++d) {
        out << "\t\tfract(sin(dot(s*c" << d;
        out << ", m)) * 43758.5453)";
        if(d + 1 < dims)
            out << ",";
        out << std::endl;
    }
    out << "\t);" << std::endl;

    return closing_expr(out, ctxt);
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
