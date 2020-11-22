/**
 *  @file eagine/logging/type/filesystem.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_LOGGING_TYPE_FILESYSTEM_HPP
#define EAGINE_LOGGING_TYPE_FILESYSTEM_HPP

#include "../entry.hpp"
#include <filesystem>

namespace eagine {
//------------------------------------------------------------------------------
static inline auto
adapt_log_entry_arg(identifier name, const std::filesystem::path& fsp) {
    return [name, fsps{fsp.native()}](logger_backend& backend) {
        backend.add_string(name, EAGINE_ID(FsPath), string_view(fsps));
    };
}
//------------------------------------------------------------------------------
static inline auto adapt_log_entry_arg(
  identifier name,
  const std::filesystem::filesystem_error& value) {
    return [name, value](logger_backend& backend) {
        backend.add_string(
          name, EAGINE_ID(FlSysError), string_view(value.what()));
        backend.add_string(
          EAGINE_ID(category),
          EAGINE_ID(ErrorCtgry),
          string_view(value.code().category().name()));
    };
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_LOGGING_TYPE_FILESYSTEM_HPP
