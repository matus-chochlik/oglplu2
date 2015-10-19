/**
 *  @file oglplus/prog_var/dsa_location.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_PROG_VAR_DSA_LOCATION_1509260923_HPP
#define OGLPLUS_PROG_VAR_DSA_LOCATION_1509260923_HPP

#include "location.hpp"

namespace oglplus {

template <typename VarTag>
class prog_var_loc<VarTag, true>
 : public prog_var_loc<VarTag, false>
{
private:
	GLuint _prog;

	static constexpr inline
	GLuint _invalid_prog(void)
	noexcept
	{
		return 0u;
	}
public:
	constexpr
	prog_var_loc(void)
	noexcept
	 : prog_var_loc<VarTag>()
	 , _prog(_invalid_prog())
	{ }

	constexpr
	prog_var_loc(program_name prog, prog_var_loc<VarTag> loc)
	noexcept
	 : prog_var_loc<VarTag>(loc)
	 , _prog(get_raw_name(prog))
	{ }

	constexpr
	program_name program(void) const
	noexcept
	{
		return program_name(_prog);
	}

	constexpr
	bool is_bound(void) const
	noexcept
	{
		return _prog != _invalid_prog();
	}

	constexpr explicit
	operator bool (void) const 
	noexcept
	{
		return this->is_bound() && this->is_active();
	}

	constexpr
	bool operator ! (void) const 
	noexcept
	{
		return !this->is_bound() || !this->is_active();
	}

	friend constexpr
	bool operator == (prog_var_loc a, prog_var_loc b)
	noexcept
	{
		return (a._prog == b._prog) && (a._loc == b._loc);
	}

	friend constexpr
	bool operator != (prog_var_loc a, prog_var_loc b)
	noexcept
	{
		return (a._prog != b._prog) || (a._loc != b._loc);
	}
};

template <typename VarTag>
using dsa_prog_var_loc = prog_var_loc<VarTag, true>;

} // namespace oglplus

#endif // include guard
