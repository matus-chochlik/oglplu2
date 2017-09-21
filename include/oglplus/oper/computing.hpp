/**
 *  @file oglplus/oper/computing.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_OPER_COMPUTING_1509260923_HPP
#define OGLPLUS_OPER_COMPUTING_1509260923_HPP

#include "../error/handling.hpp"
#include "../error/outcome.hpp"
#include "../enum/types.hpp"

namespace oglplus {
namespace oper {

struct compute_work_group_size
{
	compute_work_group_size(GLsizei num_x, GLsizei num_y, GLsizei num_z) {
		_v[0] = num_x;
		_v[1] = num_y;
		_v[2] = num_z;
	}

	GLsizei num_groups_x(void) const
	noexcept { return GLsizei(_v[0]); }

	GLsizei num_groups_y(void) const
	noexcept { return GLsizei(_v[1]); }

	GLsizei num_groups_z(void) const
	noexcept { return GLsizei(_v[2]); }

	span<const GLint> num_groups(void) const
	noexcept { return {_v, 3}; }

	span<GLint> num_groups(void)
	noexcept { return {_v, 3}; }

	GLint _v[3];
};

struct computing_ops
{
#if defined(GL_VERSION_4_2)
	static
	outcome<void>
	dispatch_compute(GLuint x_groups, GLuint y_groups, GLuint z_groups)
	noexcept;

	static
	outcome<void>
	dispatch_compute(const compute_work_group_size& wgs)
	noexcept {
		return dispatch_compute(
			wgs.num_groups_x(),
			wgs.num_groups_y(),
			wgs.num_groups_z()
		);
	}
#endif
};

} // namespace oper
} // namespace oglplus

#include <oglplus/oper/computing.inl>

#endif // include guard
