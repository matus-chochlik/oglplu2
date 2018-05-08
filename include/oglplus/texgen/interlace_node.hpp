/**
 *  @file oglplus/texgen/interlace_node.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_TEXGEN_INTERLACE_NODE_1509260923_HPP
#define OGLPLUS_TEXGEN_INTERLACE_NODE_1509260923_HPP

#include "base_node.hpp"
#include "fallback_input.hpp"

namespace oglplus {
namespace texgen {

enum class interlace_mode { columns, rows, layers };

class interlace_output : public base_output {
private:
    interlace_mode _mode;

    friend class interlace_node;

public:
    interlace_output(node_intf& parent, interlace_mode);

    interlace_output(node_intf& parent)
      : interlace_output(parent, interlace_mode::rows) {
    }

    cstr_ref type_name(void) override;

    slot_data_type value_type(void) override;

    std::ostream& definitions(
      std::ostream& out, compile_context& ctxt) override;
};

class interlace_node : public single_output_node<interlace_output> {
public:
    interlace_node& set_mode(interlace_mode mode) {
	_output._mode = mode;
	return *this;
    }
};

} // namespace texgen
} // namespace oglplus

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/texgen/interlace_node.inl>
#endif

#endif // include guard
