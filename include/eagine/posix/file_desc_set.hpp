/**
 *  @file eagine/posix/file_desc_set.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_POSIX_FILE_DESC_SET_1509260923_HPP
#define EAGINE_POSIX_FILE_DESC_SET_1509260923_HPP

#include "file_descriptor.hpp"
#include "../valid_if.hpp"
#include <sys/types.h>

namespace eagine {
namespace posix {

class file_descriptor_set
{
private:
	fd_set _fds;
	int _min, _max;

	void _update(int fd)
	{
		if(_min > fd)
		{
			_min = fd;
		}
		if(_max < fd)
		{
			_max = fd;
		}
	}

	struct _valid_fd_policy
	{
		bool operator ()(file_descriptor fd) const
		noexcept
		{
			return	(get_raw_fd(fd) >= 0) &&
				(get_raw_fd(fd) < FD_SETSIZE);
		}

		struct do_log
		{
			do_log(const _valid_fd_policy&)
			noexcept
			{ }

			template <typename Log>
			void operator ()(Log& log, file_descriptor fd) const
			{
				if(get_raw_fd(fd) < 0)
				{
					log	<< "File descriptor value "
						<< get_raw_fd(fd)
						<< " (less than zero)"
						<< " is invalid.";
				}
				else
				{
					log	<< "File descriptor value "
						<< get_raw_fd(fd)
						<< " (not less than FD_SETSIZE)"
						<< " is invalid.";
				}
			}
		};

		struct abort
		{
			[[noreturn]]
			void operator ()(void) const
			noexcept
			{
				EAGINE_ABORT(
				"File descriptor value not between "
				"0 and FD_SETSIZE"
				);
			}
		};
	};
public:
	typedef valid_if<file_descriptor, _valid_fd_policy>
		valid_file_descriptor;

	file_descriptor_set(void)
	noexcept
	 : _min(FD_SETSIZE)
	 , _max(-1)
	{
		FD_ZERO(&_fds);
	}

	optionally_valid<int> nfds(void) const
	noexcept
	{
		return {_max+1, (_max >= 0) && (_max < FD_SETSIZE)};
	}

	bool is_set(valid_file_descriptor fd) const
	noexcept
	{
		int rfd = get_raw_fd(fd.value());
		return FD_ISSET(rfd, &_fds);
	}

	file_descriptor_set& set(valid_file_descriptor fd)
	noexcept
	{
		int rfd = get_raw_fd(fd.value());
		_update(rfd);
		FD_SET(rfd, &_fds);
		return *this;
	}

	file_descriptor_set& clear(valid_file_descriptor fd)
	noexcept
	{
		int rfd = get_raw_fd(fd.value());
		_update(rfd);
		FD_CLR(rfd, &_fds);
		return *this;
	}

	friend inline
	fd_set* get_raw_fd_set(file_descriptor_set& fds)
	noexcept
	{
		return &fds._fds;
	}
};


} // namespace posix
} // namespace eagine

#endif // include guard
