/**
 *  @file oglplus/oper/prog_var_location.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_PROG_VAR_LOCATION_HPP
#define OGLPLUS_OPER_PROG_VAR_LOCATION_HPP

#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../prog_var/dsa_location.hpp"
#include "../utils/boolean.hpp"
#include "../utils/string_span.hpp"

namespace oglplus {
namespace oper {

struct prog_var_location_ops {
    template <typename VarTag>
    static inline outcome<prog_var_loc<VarTag>>
    get_location(program_name prog, string_view identifier) noexcept {
        return prog_var_loc_ops<VarTag>::get_location(prog, identifier);
    }

    template <typename VarTag>
    static inline outcome<boolean> query_location(
      prog_var_loc<VarTag>& pvl,
      program_name prog,
      string_view identifier) noexcept {
        auto loc = success(get_location<VarTag>(prog, identifier));
        if(loc) {
            pvl = loc;
            return {pvl.is_active()};
        }
        return loc.release_handler();
    }

    template <typename VarTag>
    static inline outcome<boolean> query_location(
      dsa_prog_var_loc<VarTag>& pvl, string_view identifier) noexcept {
        return query_location(pvl, pvl.program(), identifier);
    }
};

} // namespace oper
} // namespace oglplus

#endif // OGLPLUS_OPER_PROG_VAR_LOCATION_HPP
