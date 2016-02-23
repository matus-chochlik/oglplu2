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
#include "memory_block.hpp"
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
{
private:
	file_contents _fc;

	static
	bool _valid_block(const_memory_block blk)
	noexcept
	{
		return (blk.size() >= sizeof(T)) && (blk.data() != nullptr);
	}

	const T* _ptr(void) const
	noexcept
	{
		const_memory_block blk = _fc.block();
		assert(_valid_block(blk));
		return static_cast<const T*>(blk.addr());
	}
public:
	structured_file_content(const cstr_ref& path)
	 : _fc(path)
	{ }

	bool is_valid(void) const
	noexcept
	{
		return _fc.is_loaded() && _valid_block(_fc.block());
	}

	const T& get(void) const
	noexcept
	{
		return *_ptr();
	}

	const T* operator -> (void) const
	noexcept
	{
		return _ptr();
	}
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/file_contents.inl>
#endif

#endif // include guard
