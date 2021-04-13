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
#include "interface.hpp"
#include "protected_member.hpp"
#include "string_span.hpp"
#include "struct_memory_block.hpp"
#include <memory>

namespace eagine {

/// @brief Interface for file content getter implementations.
/// @see file_contents
struct file_contents_intf : interface<file_contents_intf> {
    virtual auto block() noexcept -> memory::const_block = 0;
};

/// @brief Class providing access to the contents of a file.
/// @see structured_file_content
class file_contents {
public:
    /// @brief Default constructor.
    file_contents() = default;

    /// @brief Constructor that opens and loads contents of file at the given path.
    file_contents(string_view path);

    /// @brief Checks if the contents were loaded.
    /// @see block
    auto is_loaded() const noexcept -> bool {
        return bool(_pimpl);
    }

    /// @brief Checks if the contents were loaded.
    /// @see is_loaded
    explicit operator bool() const noexcept {
        return is_loaded();
    }

    /// @brief Returns the block viewing the loaded file contents.
    /// @see is_loaded
    auto block() const noexcept -> memory::const_block {
        return bool(EAGINE_LIKELY(_pimpl)) ? _pimpl->block()
                                           : memory::const_block();
    }

    /// @brief Implicit conversion to the block viewing the loaded file contents.
    /// @see block
    /// @see is_loaded
    operator memory::const_block() const noexcept {
        return block();
    }

private:
    std::shared_ptr<file_contents_intf> _pimpl{};
};

/// @brief Class loading a baked structured data from a file.
/// @see file_contents
template <typename T>
class structured_file_content
  : protected_member<file_contents>
  , public structured_memory_block<const T> {
public:
    /// @brief Constructor that opens and loads contents of file at the given path.
    structured_file_content(string_view path)
      : protected_member<file_contents>(path)
      , structured_memory_block<const T>(get_the_member()) {}

    /// @brief Construction from a file contents instance.
    /// @see file_contents
    structured_file_content(file_contents&& fc)
      : protected_member<file_contents>(std::move(fc))
      , structured_memory_block<const T>(get_the_member()) {}
};

} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/file_contents.inl>
#endif

#endif // EAGINE_FILE_CONTENTS_HPP
