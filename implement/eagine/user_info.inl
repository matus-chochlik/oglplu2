/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#include <eagine/environment.hpp>
#include <eagine/main_ctx.hpp>

#if EAGINE_POSIX
#include <array>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#endif

namespace eagine {
//------------------------------------------------------------------------------
class user_info_impl {
public:
    user_info_impl(main_ctx_parent) {}

    const std::string login_name{_get_username()};
    const std::string home_dir_path{_get_home_dir_path()};

private:
    static auto _get_username() -> std::string {
#if EAGINE_POSIX
        if(auto pw{::getpwuid(::getuid())}) {
            return {extract(pw).pw_name};
        }
        std::array<char, 128> temp{};
        if(::getlogin_r(temp.data(), temp.size())) {
            return {temp.data(), temp.size()};
        }
#endif
        if(const auto opt_var{get_environment_variable("USER")}) {
            return to_string(extract(opt_var));
        }
        return {};
    }

    static auto _get_home_dir_path() -> std::string {
#if EAGINE_POSIX
        if(auto pw{::getpwuid(::getuid())}) {
            return {extract(pw).pw_dir};
        }
#endif
        if(const auto opt_var{get_environment_variable("HOME")}) {
            return to_string(extract(opt_var));
        }
        return {};
    }
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto user_info::_impl() noexcept -> user_info_impl* {
    if(EAGINE_UNLIKELY(!_pimpl)) {
        try {
            _pimpl = std::make_shared<user_info_impl>(*this);
        } catch(...) {
        }
    }
    return _pimpl.get();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto user_info::login_name() -> valid_if_not_empty<string_view> {
    if(auto impl{_impl()}) {
        return {extract(impl).login_name};
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto user_info::home_dir_path() -> valid_if_not_empty<string_view> {
    if(auto impl{_impl()}) {
        return {extract(impl).home_dir_path};
    }
    return {};
}
//------------------------------------------------------------------------------
} // namespace eagine
