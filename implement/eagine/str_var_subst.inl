/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///
#include <eagine/memory/span_algo.hpp>
#include <eagine/string_span.hpp>
#include <cstdlib>

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto substitute_variables_into(
  std::string& dst,
  string_view src,
  const callable_ref<optionally_valid<string_view>(string_view)>& translate,
  variable_substitution_options opts) -> std::string& {

    do {
        if(auto lpos = find_element(src, opts.leading_sign)) {
            append_to(dst, head(src, lpos.value()));
            src = skip(src, lpos.value());

            if(
              auto inner = slice_inside_brackets(
                src, opts.opening_bracket, opts.closing_bracket)) {

                if(auto translation = translate(inner)) {
                    append_to(dst, translation.value());
                } else {
                    if(find_element(inner, opts.leading_sign)) {
                        std::string temp;
                        substitute_variables_into(temp, inner, translate, opts);
                        if(auto translation2 = translate(temp)) {
                            append_to(dst, translation2.value());
                        } else if(opts.keep_untranslated) {
                            append_to(dst, head(src, inner.size() + 3));
                        }
                    } else if(opts.keep_untranslated) {
                        append_to(dst, head(src, inner.size() + 3));
                    }
                }
                src = skip(src, inner.size() + 3);
            } else {
                append_to(dst, head(src, 3));
                src = skip(src, 3);
            }

        } else {
            append_to(dst, src);
            src.reset();
        }
    } while(!src.empty());

    return dst;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto substitute_variables(
  string_view src,
  const callable_ref<optionally_valid<string_view>(string_view)>& translate,
  variable_substitution_options opts) -> std::string {
    std::string result;
    return std::move(substitute_variables_into(result, src, translate, opts));
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto substitute_variables(
  const std::string& str,
  span<const std::string> strings,
  variable_substitution_options opts) -> std::string {
    auto translate_func =
      [&strings](string_view key) -> optionally_valid<string_view> {
        char* e = nullptr;
        const span_size_t idx = span_size(std::strtol(c_str(key), &e, 10));
        if((0 < idx) && (idx <= strings.size())) {
            return {{strings[idx - 1]}, true};
        }
        return {};
    };
    return substitute_variables(str, {construct_from, translate_func}, opts);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
auto substitute_variables(
  const std::string& str,
  const std::map<std::string, std::string, str_view_less>& dictionary,
  variable_substitution_options opts) -> std::string {
    auto translate_func =
      [&dictionary](string_view key) -> optionally_valid<string_view> {
        if(!dictionary.empty()) {
            auto i = dictionary.find(key);
            if(i != dictionary.end()) {
                return {i->second, true};
            }
        }
        return {};
    };
    return substitute_variables(str, {construct_from, translate_func}, opts);
}
//------------------------------------------------------------------------------
} // namespace eagine
