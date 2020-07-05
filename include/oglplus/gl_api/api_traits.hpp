/**
 *  @file oglplus/gl_api/api_traits.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */
#ifndef OGLPLUS_GL_API_API_TRAITS_HPP
#define OGLPLUS_GL_API_API_TRAITS_HPP

#include "result.hpp"

namespace eagine::oglp {
//------------------------------------------------------------------------------
extern "C" {

void* glXGetProcAddress(const gl_types::ubyte_type*);

} // extern "C"
//------------------------------------------------------------------------------
class gl_api_traits : public default_c_api_traits {
public:
    template <typename R>
    using no_result = gl_no_result<R>;
    template <typename R>
    using result = gl_result<R>;
    template <typename R>
    using opt_result = gl_opt_result<R>;

    template <typename R>
    using combined_result = gl_combined_result<R>;

    template <typename Api, typename Tag, typename Signature>
    std::add_pointer_t<Signature> link_function(
      Api&, Tag, string_view name, identity<Signature>) {
        _full_name.clear();
        _full_name.reserve(2 + name.size() + 1);
        _full_name.append("gl");
        _full_name.append(name.data(), std::size_t(name.size()));
        auto func = glXGetProcAddress(
          reinterpret_cast<const gl_types::ubyte_type*>(_full_name.c_str()));
        // TODO: support for extension also needs to be checked
        if(func != nullptr) {
            return reinterpret_cast<std::remove_pointer_t<Signature>*>(func);
        }
        return nullptr;
    }

private:
    std::string _full_name;
};
//------------------------------------------------------------------------------
} // namespace eagine::oglp

#endif // OGLPLUS_GL_API_API_TRAITS_HPP

