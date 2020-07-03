/**
 *  @file oglplus/texgen/constants.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_CONSTANTS_HPP
#define OGLPLUS_TEXGEN_CONSTANTS_HPP

#include "interface.hpp"
#include <string>

namespace eagine::oglp::texgen {
namespace expr {
struct constant_id {
    constant_intf& constant;
    compile_context& context;
};
std::ostream& operator<<(std::ostream& out, const constant_id&);
} // namespace expr

class base_constant : public constant_intf {
public:
    std::string identifier();

    slot_data_type value_type() override;

    virtual std::ostream& value(std::ostream&, compile_context&) = 0;

    std::ostream& definitions(std::ostream&, compile_context&) override;

    std::ostream& expression(std::ostream&, compile_context&) override;
};

class constant_pi : public base_constant {
public:
    string_view name() const noexcept override;

    std::ostream& value(std::ostream&, compile_context&) override;
};

class constant_phi : public base_constant {
public:
    string_view name() const noexcept override;

    std::ostream& value(std::ostream&, compile_context&) override;
};

} // namespace eagine::oglp::texgen

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/constants.inl>
#endif

#endif // OGLPLUS_TEXGEN_CONSTANTS_HPP
