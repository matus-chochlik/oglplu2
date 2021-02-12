/// @file eagine/file_contents.inl
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/config/platform.hpp>
#include <eagine/input_data.hpp>

namespace eagine {
//------------------------------------------------------------------------------
class buffered_file_contents : public file_contents_intf {
private:
    memory::buffer _buf;

public:
    buffered_file_contents(string_view path) {
        read_file_data(path, _buf);
    }

    auto block() noexcept -> memory::const_block override {
        return _buf;
    }
};
//------------------------------------------------------------------------------
inline auto make_file_contents_impl(string_view path)
  -> std::shared_ptr<file_contents_intf> {
    try {
        return std::make_shared<buffered_file_contents>(path);
    } catch(std::system_error&) {
        return {};
    }
}
//------------------------------------------------------------------------------
// file_contents::file_contents
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
file_contents::file_contents(string_view path)
  : _pimpl{make_file_contents_impl(path)} {}
//------------------------------------------------------------------------------
} // namespace eagine
