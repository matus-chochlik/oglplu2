/**
 *  @file oglplus/texgen/constants.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <iostream>

namespace oglplus {
namespace texgen {
namespace expr {
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& operator<<(std::ostream& out, const constant_id& e) {
    e.constant.expression(out, e.context);
    return out;
}
//------------------------------------------------------------------------------
} // namespace expr
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
slot_data_type base_constant::value_type() {
    return slot_data_type::float_;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::string base_constant::identifier() {
    string_view n = name();
    std::string result;
    result.reserve(std_size(7 + n.size()));
    result.append("oglptg_");
    result.append(n.data(), std_size(n.size()));
    return result;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream&
base_constant::definitions(std::ostream& out, compile_context& ctxt) {
    if(!ctxt.remembers_constant(*this)) {
        out << "const " << data_type_name(value_type());
        out << " " << identifier() << " = ";
        value(out, ctxt);
        out << ";" << std::endl << std::endl;
        ctxt.remember_constant(*this);
    }
    return out;
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& base_constant::expression(std::ostream& out, compile_context&) {
    return out << identifier();
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view constant_pi::name() const noexcept {
    return string_view("pi");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& constant_pi::value(std::ostream& out, compile_context&) {
    return out << "(atan(1.0)*4.0)";
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
string_view constant_phi::name() const noexcept {
    return string_view("phi");
}
//------------------------------------------------------------------------------
OGLPLUS_LIB_FUNC
std::ostream& constant_phi::value(std::ostream& out, compile_context&) {
    return out << "((1.0+sqrt(5.0))*0.5)";
}
//------------------------------------------------------------------------------
} // namespace texgen
} // namespace oglplus
//------------------------------------------------------------------------------
