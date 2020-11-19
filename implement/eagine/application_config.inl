/**
 *  @file eagine/application_config.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/environment.hpp>
#include <eagine/value_tree/filesystem.hpp>
#include <cctype>
#include <map>

namespace eagine {
//------------------------------------------------------------------------------
class application_config_impl : public main_ctx_object {
public:
    application_config_impl(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(AppCfgImpl), parent} {}

    auto find_compound_attribute(string_view) noexcept
      -> valtree::compound_attribute {
        // TODO: search configuration files in locations like /etc/oglplus/
        // ~/.oglplus, find configuration files, create compounds,
        // find attribute
        return {};
    }

private:
    std::map<std::string, valtree::compound> _open_configs;
};
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto application_config::_impl() noexcept -> application_config_impl* {
    if(EAGINE_UNLIKELY(!_pimpl)) {
        try {
            _pimpl = std::make_shared<application_config_impl>(*this);
        } catch(...) {
        }
    }
    return _pimpl.get();
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto application_config::_find_comp_attr(string_view key) noexcept
  -> valtree::compound_attribute {
    if(auto impl{_impl()}) {
        return extract(impl).find_compound_attribute(key);
    }
    return {};
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto application_config::_find_prog_arg(string_view key) noexcept
  -> program_arg {
    std::string arg_name;
    arg_name.reserve(std_size(3 + key.size()));
    arg_name.append("--");
    for(auto c : key) {
        if(c == '.' || c == '_') {
            c = '-';
        }
        arg_name.append(&c, 1U);
    }
    return main_context().args().find(arg_name);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto application_config::_eval_env_var(string_view key) noexcept
  -> optionally_valid<string_view> {
    std::string arg_name;
    arg_name.reserve(std_size(7 + key.size()));
    arg_name.append("EAGINE_");
    for(auto c : key) {
        if(c == '.') {
            c = '_';
        } else {
            c = std::toupper(c);
        }
        arg_name.append(&c, 1U);
    }
    return get_environment_variable(arg_name);
}
//------------------------------------------------------------------------------
} // namespace eagine

