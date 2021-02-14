/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

extern "C" {

auto glXGetProcAddress(const eagine::oglp::gl_types::ubyte_type*) -> void*;

} // extern "C"

namespace eagine::oglp {
//------------------------------------------------------------------------------
template <typename Api, typename Tag, typename Signature>
inline auto gl_api_traits::link_function(
  Api&,
  Tag,
  string_view name,
  type_identity<Signature>) -> std::add_pointer_t<Signature> {
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
//------------------------------------------------------------------------------
} // namespace eagine::oglp

