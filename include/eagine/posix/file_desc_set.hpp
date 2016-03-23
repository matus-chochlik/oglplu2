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
#include "../optional_ref.hpp"
#include "../valid_if.hpp"
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>

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

static inline
outcome<int> select(
	int nfds,
	optional_reference_wrapper<file_descriptor_set> read_fds,
	optional_reference_wrapper<file_descriptor_set> write_fds,
	optional_reference_wrapper<file_descriptor_set> except_fds,
	long timeout_sec,
	long timeout_nanosec
) noexcept
{
	struct timespec timeout;
	timeout.tv_sec = timeout_sec;
	timeout.tv_nsec = timeout_nanosec;

	int res = ::pselect(
		nfds,
		read_fds?get_raw_fd_set(read_fds):nullptr,
		write_fds?get_raw_fd_set(write_fds):nullptr,
		except_fds?get_raw_fd_set(except_fds):nullptr,
		&timeout,
		nullptr
	);

	return error_if_negative(res, -1);
}

static inline
outcome<int> select(
	optional_reference_wrapper<file_descriptor_set> read_fds,
	optional_reference_wrapper<file_descriptor_set> write_fds,
	optional_reference_wrapper<file_descriptor_set> except_fds,
	long timeout_sec,
	long timeout_nsec
) noexcept
{
	int nfds = 0;

	auto upd_nfds =
	[&nfds](optional_reference_wrapper<file_descriptor_set> fds)
	{
		if(fds.is_valid())
		{
			if(auto fdsn = fds.get().nfds())
			{
				if(nfds < fdsn.value())
				{
					nfds = fdsn.value();
				}
			}
		}
	};
	upd_nfds(read_fds);
	upd_nfds(write_fds);
	upd_nfds(except_fds);

	return posix::select(
		nfds,
		read_fds,
		write_fds,
		except_fds,
		timeout_sec,
		timeout_nsec
	);
}

} // namespace posix
} // namespace eagine

#endif // include guard
