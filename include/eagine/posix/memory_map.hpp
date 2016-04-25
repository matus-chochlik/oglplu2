/**
 *  @file eagine/posix/memory_map.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_POSIX_MEMORY_MAP_1509260923_HPP
#define EAGINE_POSIX_MEMORY_MAP_1509260923_HPP

#include "file_descriptor.hpp"
#include "file_stat.hpp"
#include <sys/mman.h>

namespace eagine {
namespace posix {

static inline
outcome<memory_block> mmap(
	void* addr, size_t len,
	int prot, int flags,
	file_descriptor fdw,
	off_t offs
) noexcept
{
	void* result = ::mmap(addr, len, prot, flags, get_raw_fd(fdw), offs);
	return (result == MAP_FAILED)?
		outcome<memory_block>(error_info(errno, get_raw_fd(fdw))):
		outcome<memory_block>(memory_block(result, len));
}

static inline
outcome<memory_block> mmap(int prot, int flags, file_descriptor fdw)
noexcept
{
	return mmap(nullptr, size_t(file_size(fdw)), prot, flags, fdw, 0);
}

static inline
outcome<void> munmap(memory_block blk)
noexcept
{
	return error_if_not_zero(::munmap(blk.data(), blk.size()), -1);
}

class memory_mapped_file
{
private:
	memory_block _blk;
public:
	memory_mapped_file(file_descriptor fdw, int prot, int flags)
	 : _blk(mmap(prot, flags, fdw))
	{ }

	~memory_mapped_file(void)
	noexcept
	{
		if(_blk)
		{
			try { ::munmap(_blk.data(), _blk.size()); }
			catch(...) { }
		}
	}

	memory_block block(void)
	noexcept
	{
		return _blk;
	}
};

} // namespace posix
} // namespace eagine

#endif // include guard
