/**
 *  @file eagine/file_contents.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/config/platform.hpp>

#include <fstream>
#include <vector>

#if EAGINE_POSIX
#include <eagine/posix/sysconf.hpp>
#include <eagine/posix/file.hpp>
#include <eagine/posix/memory_map.hpp>
#endif

namespace eagine {
//------------------------------------------------------------------------------
class buffered_file_contents
 : public file_contents_intf
{
private:
	std::vector<char> _buf;

	void _load_fast(const cstr_ref& path)
	{
		std::ifstream file;
		file.exceptions(std::ios::failbit | std::ios::badbit);
		file.open(path.c_str(), std::ios::in | std::ios::binary);
		file.seekg(0, std::ios::end);
		_buf.resize(decltype(_buf)::size_type(file.tellg()));
		file.seekg(0, std::ios::beg);
		file.read(
			static_cast<char*>(_buf.data()),
			static_cast<std::streamsize>(_buf.size())
		);
	}

	void _load_alt(const cstr_ref& path)
	{
		std::ifstream file;
		file.exceptions(std::ios::failbit | std::ios::badbit);
		file.open(path.c_str(), std::ios::in | std::ios::binary);
		_buf.clear();
		_buf.insert(
			_buf.begin(),
			std::istreambuf_iterator<char>(file),
			std::istreambuf_iterator<char>()
		);
	}
public:
	buffered_file_contents(const cstr_ref& path)
	{
		try { _load_fast(path); }
		catch(std::ios_base::failure&)
		{ _load_alt(path); }
	}

	const_memory_block block(void)
	noexcept
	override
	{
		return {_buf.data(), _buf.size()};
	}
};
//------------------------------------------------------------------------------
#if EAGINE_POSIX
//------------------------------------------------------------------------------
class memory_mapped_file_contents
 : public file_contents_intf
{
private:
	posix::memory_mapped_file _mmf;
public:
	memory_mapped_file_contents(posix::file_descriptor_owner& fd)
	 : _mmf(fd, PROT_READ, MAP_SHARED)
	{ }

	const_memory_block block(void)
	noexcept
	override
	{
		return _mmf.block();
	}
};
//------------------------------------------------------------------------------
inline
std::shared_ptr<file_contents_intf>
make_file_contents_impl(const cstr_ref& path)
{
	posix::file_descriptor_owner fd(posix::open(path, 0));
	auto size = posix::file_size(fd);
	auto pgsize = posix::page_size();

	bool do_map = (size % pgsize) == 0;
	do_map |= (size % pgsize) > (pgsize / (2*(1+(size)/pgsize)));
	do_map |= (size > 8*pgsize);

	if(do_map)
	{
		return std::make_shared<memory_mapped_file_contents>(fd);
	}
	return std::make_shared<buffered_file_contents>(path);
}
//------------------------------------------------------------------------------
#else
//------------------------------------------------------------------------------
inline
std::shared_ptr<file_contents_intf>
make_file_contents_impl(const cstr_ref& path)
{
	return std::make_shared<buffered_file_contents>(path);
}
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
// file_contents::file_contents
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
file_contents::
file_contents(const cstr_ref& path)
 : _pimpl(make_file_contents_impl(path))
{ }
//------------------------------------------------------------------------------
} // namespace eagine
