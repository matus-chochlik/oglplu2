/**
 *  @file oglplus/texgen/mandelbrot_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_MANDELBROT_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_MANDELBROT_NODE_1509260923_HPP

#include "base_node.hpp"

namespace oglplus {
namespace texgen {

class mandelbrot_output : public base_output {
public:
    mandelbrot_output(node_intf& parent);

    string_view type_name() override;

    slot_data_type value_type() override;

    std::ostream&
    definitions(std::ostream& out, compile_context& ctxt) override;
};

using mandelbrot_node = single_output_node<mandelbrot_output>;

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/mandelbrot_node.inl>
#endif

#endif // include guard
