/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/git_info.hpp>

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto build_info::query() noexcept -> build_info {
    return {{config_git_version_tuple()}};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto build_info::version_at_least(int major, int minor) const -> tribool {
    if(const auto opt_maj{version_major()}) {
        if(extract(opt_maj) < major) {
            return false;
        }
        if(extract(opt_maj) > major) {
            return true;
        }
        if(const auto opt_min{version_minor()}) {
            if(extract(opt_min) < minor) {
                return false;
            }
            return true;
        }
    }
    return indeterminate;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto build_info::version_at_least(int major, int minor, int patch) const
  -> tribool {
    if(const auto opt_maj{version_major()}) {
        if(extract(opt_maj) < major) {
            return false;
        }
        if(extract(opt_maj) > major) {
            return true;
        }
        if(const auto opt_min{version_minor()}) {
            if(extract(opt_min) < minor) {
                return false;
            }
            if(extract(opt_min) > minor) {
                return true;
            }
            if(const auto opt_ptch{version_patch()}) {
                if(extract(opt_ptch) < patch) {
                    return false;
                }
                return true;
            }
        }
    }
    return indeterminate;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto build_info::version_at_least(int major, int minor, int patch, int commit)
  const -> tribool {
    if(const auto opt_maj{version_major()}) {
        if(extract(opt_maj) < major) {
            return false;
        }
        if(extract(opt_maj) > major) {
            return true;
        }
        if(const auto opt_min{version_minor()}) {
            if(extract(opt_min) < minor) {
                return false;
            }
            if(extract(opt_min) > minor) {
                return true;
            }
            if(const auto opt_ptch{version_patch()}) {
                if(extract(opt_ptch) < patch) {
                    return false;
                }
                if(extract(opt_ptch) > patch) {
                    return true;
                }
                if(const auto opt_cmit{version_commit()}) {
                    if(extract(opt_cmit) < commit) {
                        return false;
                    }
                    return true;
                }
            }
        }
    }
    return indeterminate;
}
//------------------------------------------------------------------------------
} // namespace eagine
