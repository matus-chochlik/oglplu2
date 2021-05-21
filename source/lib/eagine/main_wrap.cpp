/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

// clang-format off
#include "prologue.inl"

#include <eagine/bindump.hpp>
#include <eagine/build_info.hpp>
#include <eagine/git_info.hpp>
#include <eagine/compiler_info.hpp>
#include <eagine/system_info.hpp>
#include <eagine/user_info.hpp>
#include <eagine/compression.hpp>
#include <eagine/file_contents.hpp>
#include <eagine/from_string.hpp>
#include <eagine/hexdump.hpp>
#include <eagine/input_data.hpp>
#include <eagine/type_name.hpp>
#include <eagine/logging/entry.hpp>
#include <eagine/random_identifier.hpp>
#include <eagine/value_tree/filesystem.hpp>
#include <eagine/value_tree/json.hpp>
#include <eagine/value_tree/yaml.hpp>
#include <eagine/watchdog.hpp>

#include "implement.inl"
#include <eagine/main_ctx.hpp>
#include <eagine/main.hpp>
#include "epilogue.inl"
// clang-format on
