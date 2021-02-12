/// @file eagine/str_var_subst.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_STR_VAR_SUBST_HPP
#define EAGINE_STR_VAR_SUBST_HPP

#include "callable_ref.hpp"
#include "config/basic.hpp"
#include "string_span.hpp"
#include <map>
#include <string>

namespace eagine {
//------------------------------------------------------------------------------
struct variable_substitution_options {
    bool keep_untranslated = false;
    char leading_sign = '$';
    char opening_bracket = '{';
    char closing_bracket = '}';
};
//------------------------------------------------------------------------------
auto substitute_variables_into(
  std::string& dst,
  string_view src,
  const callable_ref<optionally_valid<string_view>(string_view)>& translate,
  variable_substitution_options = {}) -> std::string&;
//------------------------------------------------------------------------------
auto substitute_variables(
  string_view src,
  const callable_ref<optionally_valid<string_view>(string_view)>& translate,
  variable_substitution_options = {}) -> std::string;
//------------------------------------------------------------------------------
auto substitute_variables(
  const std::string& str,
  span<const std::string> strings,
  variable_substitution_options = {}) -> std::string;
//------------------------------------------------------------------------------
auto substitute_variables(
  const std::string& str,
  const std::map<std::string, std::string, str_view_less>& dictionary,
  variable_substitution_options = {}) -> std::string;
//------------------------------------------------------------------------------
class string_variable_map {
private:
    std::map<std::string, std::string, str_view_less> _dict{};

public:
    auto set(std::string name, std::string value) -> string_variable_map& {
        _dict.emplace(std::move(name), std::move(value));
        return *this;
    }

    auto subst_variables(const std::string& str) const -> std::string {
        return substitute_variables(str, _dict);
    }

    auto operator()(const std::string& str) const -> std::string {
        return substitute_variables(str, _dict);
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/str_var_subst.inl>
#endif

#endif // EAGINE_STR_VAR_SUBST_HPP
