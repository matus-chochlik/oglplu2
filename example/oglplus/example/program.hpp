/**
 *  .file oglplus/example/program.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#include "params.hpp"
#include <oglplus/utils/program.hpp>
#include <oglplus/utils/cstr_ref.hpp>

namespace oglplus {

class example_program_base
 : public program
{
private:
	program_source_file
	_get_source(const example_params& params, const cstr_ref& prog_name) {
		std::string path = params.get_resource_file_path(
			example_resource_type::program_source,
			prog_name
		);
		return program_source_file(cstr_ref(path));
	}
public:
	example_program_base(
		const example_params& params,
		const cstr_ref& prog_name
	): program(build_program(_get_source(params, prog_name)))
	{ }
};

} // namespace oglplus

