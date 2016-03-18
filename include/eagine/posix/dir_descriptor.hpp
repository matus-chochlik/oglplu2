/**
 *  @file eagine/posix/dir_descriptor.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_POSIX_DIR_DESCRIPTOR_1509260923_HPP
#define EAGINE_POSIX_DIR_DESCRIPTOR_1509260923_HPP

#include "error.hpp"
#include <sys/types.h>
#include <dirent.h>

namespace eagine {
namespace posix {

class dir_descriptor
{
protected:
	DIR* _dp;
public:
	constexpr inline
	dir_descriptor(void)
	noexcept
	 : _dp(nullptr)
	{ }

	explicit inline
	dir_descriptor(DIR* dp)
	noexcept
	 : _dp(dp)
	{ }

	dir_descriptor(dir_descriptor&& temp)
	noexcept
	 : _dp(temp._dp)
	{
		temp._dp = nullptr;
	}

	dir_descriptor(const dir_descriptor&) = default;
	dir_descriptor& operator = (const dir_descriptor&) = default;

	dir_descriptor& operator = (dir_descriptor&& temp)
	noexcept
	{
		_dp = temp._dp;
		temp._dp = nullptr;
		return *this;
	}

	constexpr
	bool is_valid(void) const
	noexcept
	{
		return _dp != nullptr;
	}

	explicit constexpr
	operator bool (void) const
	noexcept
	{
		return is_valid();
	}

	constexpr
	bool operator ! (void) const
	noexcept
	{
		return !is_valid();
	}

	template <typename Func>
	outcome<void> for_each_entry(Func func)
	{
		::dirent entry;
		::dirent* pent =nullptr;
		do
		{
			if(::readdir_r(_dp, &entry, &pent) != 0)
			{
				return error_outcome(-1);
			}
			if(pent != nullptr)
			{
				func(entry);
			}
		}
		while(pent != nullptr);

		return {};
	}

	friend constexpr inline
	DIR* get_raw_dp(dir_descriptor dp)
	noexcept
	{
		return dp._dp;
	}

	friend inline
	void swap(dir_descriptor& a, dir_descriptor& b)
	noexcept
	{
		std::swap(a._dp, b._dp);
	}
};

class owned_dir_descriptor
 : public dir_descriptor
{
public:
	explicit
	owned_dir_descriptor(DIR* dp)
	noexcept
	 : dir_descriptor(dp)
	{ }

	explicit
	owned_dir_descriptor(dir_descriptor&& fdw)
	noexcept
	 : dir_descriptor(std::move(fdw))
	{ }

	owned_dir_descriptor(owned_dir_descriptor&&) = default;
	owned_dir_descriptor& operator = (owned_dir_descriptor&&) = default;
	owned_dir_descriptor(const owned_dir_descriptor&) = delete;
	owned_dir_descriptor& operator= (const owned_dir_descriptor&&) = delete;

	friend inline
	void swap(owned_dir_descriptor& a, owned_dir_descriptor& b)
	noexcept
	{
		std::swap(a._dp, b._dp);
	}
};

static inline
outcome<void> closedir(owned_dir_descriptor& dpw)
noexcept
{
	owned_dir_descriptor tdpw = std::move(dpw);
	DIR* dp = get_raw_dp(tdpw);
	return error_if_not_zero(::closedir(dp), -1);
}

class dir_descriptor_owner
{
private:
	owned_dir_descriptor _odd;
public:
	dir_descriptor_owner(void) = default;

	dir_descriptor_owner(owned_dir_descriptor&& odd)
	noexcept
	 : _odd(std::move(odd))
	{ }

	dir_descriptor_owner(dir_descriptor_owner&&) = default;
	dir_descriptor_owner(const dir_descriptor_owner&) = delete;

	dir_descriptor_owner& operator = (dir_descriptor_owner&& temp)
	noexcept
	{
		swap(_odd, temp._odd);
		try { ::closedir(get_raw_dp(temp._odd)); }
		catch(...) { }
		return *this;
	}

	dir_descriptor_owner& operator = (const dir_descriptor_owner&) = delete;

	~dir_descriptor_owner(void)
	noexcept
	{
		try { ::closedir(get_raw_dp(_odd)); }
		catch(...) { }
	}

	dir_descriptor get(void) const
	noexcept
	{
		return _odd;
	}

	operator dir_descriptor (void) const
	noexcept
	{
		return get();
	}
};

} // namespace posix
} // namespace eagine

#endif // include guard
