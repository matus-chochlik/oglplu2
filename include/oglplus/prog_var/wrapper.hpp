/**
 *  @file oglplus/prog_var/wrapper.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PROG_VAR_WRAPPER_1509260923_HPP
#define OGLPLUS_PROG_VAR_WRAPPER_1509260923_HPP

#include "../program_name.hpp"
#include "../utils/string_span.hpp"
#include "fwd.hpp"

namespace oglplus {

template <typename VarTag, typename T>
class prog_var_wrapper<prog_var_loc<VarTag>, T> : public prog_var_loc<VarTag> {
private:
    typedef prog_var_loc_ops<VarTag> _loc_ops;

public:
    typedef T value_type;

    prog_var_wrapper() = default;

    prog_var_wrapper(prog_var_loc<VarTag> loc) noexcept
      : prog_var_loc<VarTag>(loc) {
    }

    prog_var_wrapper(program_name prog, string_view identifier)
      : prog_var_loc<VarTag>(_loc_ops::get_location(prog, identifier)) {
    }
};

template <typename VarTag, typename T>
class prog_var_wrapper<dsa_prog_var_loc<VarTag>, T>
  : public dsa_prog_var_loc<VarTag> {
private:
    typedef prog_var_loc_ops<VarTag> _loc_ops;

public:
    typedef T value_type;

    prog_var_wrapper() = default;

    prog_var_wrapper(dsa_prog_var_loc<VarTag> loc) noexcept
      : dsa_prog_var_loc<VarTag>(loc) {
    }

    prog_var_wrapper(program_name prog, string_view identifier)
      : dsa_prog_var_loc<VarTag>(
          prog, _loc_ops::get_location(prog, identifier)) {
    }
};

} // namespace oglplus

#endif // include guard
