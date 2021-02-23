/// @file
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
/// @brief Options for string variable substitution customization.
/// @ingroup string_utils
struct variable_substitution_options {
    /// @brief Keep the untranslated variable references in the format string.
    bool keep_untranslated{false};

    /// @brief The variable reference leading sign.
    char leading_sign{'$'};

    /// @brief The variable reference opening (left) bracket.
    char opening_bracket{'{'};

    /// @brief The variable reference closing (right) bracket.
    char closing_bracket{'}'};
};
//------------------------------------------------------------------------------
/// @brief Substitutes variable values by using translate, from src into dst.
/// @ingroup string_utils
/// @see substitute_variables
///
/// This function takes the format string @p src, finds variable references
/// using substitution options and substitutes the variables with their values
/// using the translation function into @p dst.
auto substitute_variables_into(
  std::string& dst,
  string_view src,
  const callable_ref<optionally_valid<string_view>(string_view)>& translate,
  variable_substitution_options = {}) -> std::string&;
//------------------------------------------------------------------------------
/// @brief Substitutes variable values by using translate, from src.
/// @ingroup string_utils
/// @see substitute_variables_into
///
/// This function takes the format string @p src, finds variable references
/// using substitution options and substitutes the variables with their values
/// using the translation function and returns the resulting string.
auto substitute_variables(
  string_view src,
  const callable_ref<optionally_valid<string_view>(string_view)>& translate,
  variable_substitution_options = {}) -> std::string;
//------------------------------------------------------------------------------
/// @brief Substitutes variable values by using translate, from src into dst.
/// @ingroup string_utils
/// @see substitute_variables_into
///
/// This function takes the format string @p src, finds numeric variable
/// references using substitution options and substitutes the variables with
/// their values the strings span and returns the resulting string.
auto substitute_variables(
  const std::string& str,
  span<const std::string> strings,
  variable_substitution_options = {}) -> std::string;
//------------------------------------------------------------------------------
/// @brief Substitutes variable values by using translate, from src.
/// @ingroup string_utils
/// @see substitute_variables_into
///
/// This function takes the format string @p src, finds variable references
/// using substitution options and substitutes the variables with their values
/// using the dictionary map and returns the resulting string.
auto substitute_variables(
  const std::string& str,
  const std::map<std::string, std::string, str_view_less>& dictionary,
  variable_substitution_options = {}) -> std::string;
//------------------------------------------------------------------------------
/// @brief Class storing a map of variable names to values, doing string substitution.
/// @ingroup string_utils
class string_variable_map {

public:
    /// @brief Set the @p value of a variable with @p name.
    auto set(std::string name, std::string value) -> string_variable_map& {
        _dict.emplace(std::move(name), std::move(value));
        return *this;
    }

    /// @brief Uses the stored variables to do substitution in the given string.
    auto subst_variables(const std::string& str) const -> std::string {
        return substitute_variables(str, _dict);
    }

    /// @brief Uses the stored variables to do substitution in the given string.
    auto operator()(const std::string& str) const -> std::string {
        return substitute_variables(str, _dict);
    }

private:
    std::map<std::string, std::string, str_view_less> _dict{};
};
//------------------------------------------------------------------------------
} // namespace eagine

#if !EAGINE_LINK_LIBRARY || defined(EAGINE_IMPLEMENTING_LIBRARY)
#include <eagine/str_var_subst.inl>
#endif

#endif // EAGINE_STR_VAR_SUBST_HPP
