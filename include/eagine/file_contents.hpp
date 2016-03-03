/**
 *  @file eagine/file_contents.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_FILE_CONTENTS_1509260923_HPP
#define EAGINE_FILE_CONTENTS_1509260923_HPP

#include "config/basic.hpp"
#include "cstr_ref.hpp"
#include "struct_memory_block.hpp"
#include "protected_member.hpp"
#include <memory>

namespace eagine {

struct file_contents_intf
{
	virtual ~file_contents_intf(void) = default;

	virtual
	const_memory_block block(void)
	noexcept = 0;
};

class file_contents
{
private:
	std::shared_ptr<file_contents_intf> _pimpl;
public:
	file_contents(void) = default;
	file_contents(const file_contents&) = default;
	file_contents(file_contents&&) = default;
	file_contents& operator = (const file_contents&) = default;
	file_contents& operator = (file_contents&&) = default;

	file_contents(const cstr_ref& path);

	bool is_loaded(void) const
	noexcept
	{
		return bool(_pimpl);
	}

	const_memory_block block(void) const
	noexcept
	{
		return bool(_pimpl)?_pimpl->block():const_memory_block();
	}

	operator const_memory_block (void) const
	noexcept
	{
		return block();
	}
};

template <typename T>
class structured_file_content
 : protected_member<file_contents>
 , public structured_memory_block<const T>
{
public:
	structured_file_content(const cstr_ref& path)
	 : protected_member<file_contents>(path)
	 , structured_memory_block<const T>(get_the_member())
	{ }

	structured_file_content(file_contents&& fc)
	 : protected_member<file_contents>(std::move(fc))
	 , structured_memory_block<const T>(get_the_member())
	{ }
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/file_contents.inl>
#endif

#endif // include guard
