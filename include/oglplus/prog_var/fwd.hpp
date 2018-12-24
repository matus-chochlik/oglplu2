/**
 *  @file oglplus/prog_var/fwd.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PROG_VAR_FWD_HPP
#define OGLPLUS_PROG_VAR_FWD_HPP

namespace oglplus {

template <typename VarTag, bool IsDSA = false>
class prog_var_loc;

template <typename VarTag>
using dsa_prog_var_loc = prog_var_loc<VarTag, true>;

template <typename VarTag>
struct prog_var_loc_ops;

template <typename VarTag, typename T>
struct prog_var_get_set_ops;

template <typename ProgVarLoc, typename T>
class prog_var_wrapper;

} // namespace oglplus

#endif // OGLPLUS_PROG_VAR_FWD_HPP
