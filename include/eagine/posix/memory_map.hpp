/**
 *  @file eagine/posix/memory_map.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef EAGINE_POSIX_MEMORY_MAP_HPP
#define EAGINE_POSIX_MEMORY_MAP_HPP

#include "file_descriptor.hpp"
#include "file_stat.hpp"
#include <sys/mman.h>

namespace eagine {
namespace posix {

static inline outcome<memory::block> mmap(
  void* addr,
  size_t len,
  int prot,
  int flags,
  file_descriptor fdw,
  off_t offs) noexcept {
    void* result = ::mmap(addr, len, prot, flags, get_raw_fd(fdw), offs);
    return (result == MAP_FAILED)
             ? outcome<memory::block>(error_info(errno, get_raw_fd(fdw)))
             : outcome<memory::block>(
                 memory::block(memory::address(result), span_size(len)));
}

static inline outcome<memory::block> mmap(
  int prot, int flags, file_descriptor fdw) noexcept {
    return mmap(nullptr, size_t(file_size(fdw)), prot, flags, fdw, 0);
}

static inline outcome<void> munmap(memory::block blk) noexcept {
    return error_if_not_zero(::munmap(blk.data(), std_size(blk.size())), -1);
}

class memory_mapped_file {
private:
    memory::block _blk;

public:
    memory_mapped_file(file_descriptor fdw, int prot, int flags)
      : _blk(mmap(prot, flags, fdw)) {
    }

    memory_mapped_file(memory_mapped_file&&) noexcept = default;
    memory_mapped_file(const memory_mapped_file&) = delete;
    memory_mapped_file& operator=(memory_mapped_file&&) noexcept = default;
    memory_mapped_file& operator=(const memory_mapped_file&) = delete;

    ~memory_mapped_file() noexcept {
        if(_blk) {
            try {
                ::munmap(_blk.data(), std_size(_blk.size()));
            } catch(...) {
            }
        }
    }

    memory::block block() noexcept {
        return _blk;
    }
};

} // namespace posix
} // namespace eagine

#endif // EAGINE_POSIX_MEMORY_MAP_HPP
