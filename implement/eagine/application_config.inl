/**
 *  @file eagine/application_config.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <eagine/environment.hpp>
#include <eagine/file_contents.hpp>
#include <eagine/valid_if/not_empty.hpp>
#include <eagine/value_tree/json.hpp>
#include <eagine/value_tree/yaml.hpp>
#include <cctype>
#include <filesystem>
#include <map>

namespace eagine {
//------------------------------------------------------------------------------
class application_config_impl : public main_ctx_object {
public:
    application_config_impl(main_ctx_parent parent)
      : main_ctx_object{EAGINE_ID(AppCfgImpl), parent} {}

    auto find_compound_attribute(string_view key) noexcept
      -> valtree::compound_attribute {
        try {
            if(auto found{_find_config_of(main_context().app_name(), key)}) {
                return found;
            }
            for(auto arg : main_context().args()) {
                if(arg.is_tag("--config-group")) {
                    if(arg.next()) {
                        if(auto found{_find_config_of(arg.next().get(), key)}) {
                            return found;
                        }
                    }
                }
            }
            if(auto found{_find_config_of("defaults", key)}) {
                return found;
            }
        } catch(...) {
            log_error("exception while loading configuration value '${key}'")
              .arg(EAGINE_ID(key), key);
        }
        return {};
    }

private:
    auto _cat(string_view l, string_view r) noexcept -> std::string {
        std::string result;
        result.reserve(std_size(l.size() + r.size() + 1));
        result.append(l.data(), std_size(l.size()));
        result.append(r.data(), std_size(r.size()));
        return result;
    }

    auto _find_config_of(string_view group, string_view key) noexcept
      -> valtree::compound_attribute {
        if(auto found{_find_in(_user_config_path(_cat(group, ".yaml")), key)}) {
            return found;
        }
        if(auto found{_find_in(_user_config_path(_cat(group, ".json")), key)}) {
            return found;
        }
        return {};
    }

    auto _find_in(
      const valid_if_not_empty<std::filesystem::path>& cfg_path,
      string_view key) -> valtree::compound_attribute {
        if(cfg_path) {
            const bool can_open =
              is_regular_file(extract(cfg_path)) || is_fifo(extract(cfg_path));
            if(can_open) {
                if(auto comp{_get_config(extract(cfg_path))}) {
                    if(auto attr{comp.find(
                         basic_string_path(key, EAGINE_TAG(split_by), "."))}) {
                        return {comp, attr};
                    }
                }
            }
        }
        return {};
    }

    auto _user_config_path(string_view name)
      -> valid_if_not_empty<std::filesystem::path> {
        if(auto home_dir{main_context().user().home_dir_path()}) {
            std::filesystem::path result{std::string_view{extract(home_dir)}};
            result.append(".oglplus");
            result.append("config");
            result.append(std::string_view{name});

            return result;
        }
        return {};
    }

    auto _open_config(const std::filesystem::path& cfg_path)
      -> valtree::compound {
        if(cfg_path.extension() == ".yaml") {
            if(file_contents content{cfg_path.string()}) {
                return valtree::from_yaml_text(
                  memory::as_chars(content), *this);
            }
        } else if(cfg_path.extension() == ".json") {
            if(file_contents content{cfg_path.string()}) {
                return valtree::from_json_text(
                  memory::as_chars(content), *this);
            }
        }
        return {};
    }

    auto _get_config(const std::filesystem::path& cfg_path)
      -> valtree::compound& {
        const auto path_str{canonical(cfg_path).string()};
        auto pos = _open_configs.find(path_str);
        if(pos == _open_configs.end()) {
            pos = _open_configs.emplace(path_str, _open_config(cfg_path)).first;
        }
        return pos->second;
    }

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

