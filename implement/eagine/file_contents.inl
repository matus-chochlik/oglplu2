/**
 *  @file eagine/file_contents.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/config/platform.hpp>
#include <eagine/input_data.hpp>

#if EAGINE_POSIX
#include <eagine/posix/file.hpp>
#include <eagine/posix/memory_map.hpp>
#include <eagine/posix/sysconf.hpp>
#endif

namespace eagine {
//------------------------------------------------------------------------------
class buffered_file_contents : public file_contents_intf {
private:
    memory::buffer _buf;

public:
    buffered_file_contents(string_view path) {
        read_file_data(path, _buf);
    }

    const_memory_block block() noexcept override {
        return _buf;
    }
};
//------------------------------------------------------------------------------
#if EAGINE_POSIX
//------------------------------------------------------------------------------
class memory_mapped_file_contents : public file_contents_intf {
private:
    posix::memory_mapped_file _mmf;

public:
    memory_mapped_file_contents(posix::file_descriptor_owner& fd)
      : _mmf(fd, PROT_READ, MAP_SHARED) {
    }

    const_memory_block block() noexcept override {
        return _mmf.block();
    }
};
//------------------------------------------------------------------------------
inline std::shared_ptr<file_contents_intf>
make_file_contents_impl(string_view path) {
    posix::file_descriptor_owner fd(posix::open(path, 0));
    auto size = posix::file_size(fd);
    auto pgsize = posix::page_size();

    bool do_map = (size % pgsize) == 0;
    do_map |= (size % pgsize) > (pgsize / (2 * (1 + (size) / pgsize)));
    do_map |= (size > 8 * pgsize);

    if(do_map) {
        return std::make_shared<memory_mapped_file_contents>(fd);
    }
    return std::make_shared<buffered_file_contents>(path);
}
//------------------------------------------------------------------------------
#else
//------------------------------------------------------------------------------
inline std::shared_ptr<file_contents_intf>
make_file_contents_impl(string_view path) {
    return std::make_shared<buffered_file_contents>(path);
}
//------------------------------------------------------------------------------
#endif
//------------------------------------------------------------------------------
// file_contents::file_contents
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
file_contents::file_contents(string_view path)
  : _pimpl(make_file_contents_impl(path)) {
}
//------------------------------------------------------------------------------
} // namespace eagine
