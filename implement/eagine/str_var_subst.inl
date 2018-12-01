/**
 *  @file eagine/str_var_subst.inl
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#include <cstdlib>

namespace eagine {
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::string
substitute_variables(
  const std::string& str,
  const callable_ref<std::string(const std::string&)>& translate,
  bool keep_untranslated) {
    std::string::size_type p = str.find_first_of('$');
    if(p < str.size()) {
        std::string res(str.data(), p);

        while(p < str.size()) {
            std::string::size_type r = p + 1;
            if(str[r] == '{') {
                int depth = 0;

                while(r < str.size()) {
                    if(str[r] == '{') {
                        ++depth;
                    } else if(str[r] == '}') {
                        --depth;
                    }

                    if(depth == 0) {
                        break;
                    }
                    ++r;
                }
                if(depth != 0) {
                    res.append(str.data() + p, str.size() - p);
                    break;
                }
            }

            if(p + 2 < r) {
                std::string sub = substitute_variables(
                  std::string(str.data() + p + 2, r - p - 2),
                  translate,
                  keep_untranslated);
                std::string tmp = translate(sub);
                if(!tmp.empty()) {
                    res.append(tmp);
                } else if(keep_untranslated) {
                    res.append(str.data() + p, r - p + 1);
                }
                p = r + 1;
            }

            r = str.find_first_of('$', r);

            if(r < str.size()) {
                res.append(str.data() + p, r - p);
            } else {
                res.append(str.data() + p, str.size() - p);
            }

            p = r;
        }
        return res;
    }
    return str;
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::string
substitute_variables(
  const std::string& str,
  span<const std::string> strings,
  bool keep_untranslated) {
    callable_ref<std::string(const std::string&)> translate{
      [&strings](const std::string& key) -> std::string {
          span_size_t idx = span_size_t(std::stol(key));
          if((0 < idx) && (idx <= strings.size())) {
              return strings[idx - 1];
          }
          return {};
      }};
    return substitute_variables(str, translate, keep_untranslated);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::string
substitute_variables(
  const std::string& str,
  const std::map<std::string, std::string>& dictionary,
  bool keep_untranslated) {
    callable_ref<std::string(const std::string&)> translate{
      [&dictionary](const std::string& key) -> std::string {
          auto i = dictionary.find(key);
          if(i != dictionary.end()) {
              return i->second;
          }
          return {};
      }};
    return substitute_variables(str, translate, keep_untranslated);
}
//------------------------------------------------------------------------------
EAGINE_LIB_FUNC
std::string
environment_variable_map::_translate(const std::string& name) {
    const char* ptr = ::getenv(name.c_str());
    return ptr ? std::string(ptr) : std::string();
}
//------------------------------------------------------------------------------
} // namespace eagine
