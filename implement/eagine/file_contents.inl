/**
 *  @file eagine/file_contents.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <fstream>
#include <vector>

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
// file_contents::file_contents
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
file_contents::
file_contents(const cstr_ref& path)
 : _pimpl(std::make_shared<buffered_file_contents>(path))
{ }
//------------------------------------------------------------------------------
} // namespace eagine
