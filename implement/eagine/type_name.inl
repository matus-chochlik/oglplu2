/**
 *  @file eagine/type_name.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifdef __GNUG__
#include <cstdlib>
#include <memory>
#include <cxxabi.h>
#endif

namespace eagine {
//------------------------------------------------------------------------------
// demangle_type_name
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::string demangle_type_name(const char* name)
noexcept
{
#ifdef __GNUG__
	try
	{
		int status = -1;

		std::unique_ptr<char, void(*)(void*)> demangled {
			::abi::__cxa_demangle(
				name,
				nullptr,
				nullptr,
				&status
			),
			::std::free
		};

		return (status == 0) ? demangled.get() : name;
	}
	catch(...) { }
#endif
	return name;
}
//------------------------------------------------------------------------------
} // namespace eagine
