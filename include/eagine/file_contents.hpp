/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_FILE_CONTENTS_HPP
#define EAGINE_FILE_CONTENTS_HPP

#include "branch_predict.hpp"
#include "config/basic.hpp"
#include "protected_member.hpp"
#include "string_span.hpp"
#include "struct_memory_block.hpp"
#include <memory>

namespace eagine {

struct file_contents_intf {
    file_contents_intf() = default;
    file_contents_intf(file_contents_intf&&) noexcept = default;
    file_contents_intf(const file_contents_intf&) = delete;
    auto operator=(file_contents_intf&&) = delete;
    auto operator=(const file_contents_intf&) = delete;
    virtual ~file_contents_intf() = default;

    virtual auto block() noexcept -> memory::const_block = 0;
};

class file_contents {
private:
    std::shared_ptr<file_contents_intf> _pimpl{};

public:
    file_contents() = default;
    file_contents(file_contents&&) noexcept = default;
    file_contents(const file_contents&) = default;
    auto operator=(file_contents&&) noexcept -> file_contents& = default;
    auto operator=(const file_contents&) -> file_contents& = default;
    ~file_contents() noexcept = default;

    file_contents(string_view path);

    auto is_loaded() const noexcept -> bool {
        return bool(_pimpl);
    }

    explicit operator bool() const noexcept {
        return is_loaded();
    }

    auto block() const noexcept -> memory::const_block {
        return bool(EAGINE_LIKELY(_pimpl)) ? _pimpl->block()
                                           : memory::const_block();
    }

    operator memory::const_block() const noexcept {
        return block();
    }
};

template <typename T>
class structured_file_content
  : protected_member<file_contents>
  , public structured_memory_block<const T> {
public:
    structured_file_content(string_view path)
      : protected_member<file_contents>(path)
      , structured_memory_block<const T>(get_the_member()) {}

    structured_file_content(file_contents&& fc)
      : protected_member<file_contents>(std::move(fc))
      , structured_memory_block<const T>(get_the_member()) {}
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/file_contents.inl>
#endif

#endif // EAGINE_FILE_CONTENTS_HPP
