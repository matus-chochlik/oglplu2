/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_VALUE_TREE_FILESYSTEM_HPP
#define EAGINE_VALUE_TREE_FILESYSTEM_HPP

#include "../config/basic.hpp"
#include "../main_ctx_fwd.hpp"
#include "wrappers.hpp"
#include <memory>

namespace eagine::valtree {
//------------------------------------------------------------------------------
struct file_compound_factory {
    file_compound_factory() noexcept = default;
    file_compound_factory(file_compound_factory&&) noexcept = default;
    file_compound_factory(const file_compound_factory&) = delete;
    auto operator=(file_compound_factory&&) = delete;
    auto operator=(const file_compound_factory&) = delete;
    virtual ~file_compound_factory() noexcept = default;

    virtual auto make_compound(string_view path, logger&) -> compound = 0;
};
//------------------------------------------------------------------------------
/// @brief Creates a compound representing a filesystem subtree.
/// @ingroup valtree
auto from_filesystem_path(
  string_view root_path,
  main_ctx_parent,
  std::shared_ptr<file_compound_factory> = {}) -> compound;
//------------------------------------------------------------------------------
} // namespace eagine::valtree

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/value_tree/filesystem.inl>
#endif

#endif // EAGINE_VALUE_TREE_FILESYSTEM_HPP
