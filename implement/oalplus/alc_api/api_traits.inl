/// @file
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

namespace eagine::oalp {
//------------------------------------------------------------------------------
template <typename Api, typename Type>
auto alc_api_traits::load_constant(
  Api& api,
  string_view name,
  type_identity<Type>) -> std::tuple<Type, bool> {
    if(api.GetEnumValue) {
        _full_name.clear();
        _full_name.reserve(4 + name.size() + 1);
        _full_name.append("ALC_");
        _full_name.append(name.data(), std::size_t(name.size()));
        return {
          static_cast<Type>(api.GetEnumValue(nullptr, _full_name.c_str())),
          true};
    }
    return {{}, false};
}
//------------------------------------------------------------------------------
template <typename Api, typename Tag, typename Signature>
auto alc_api_traits::link_function(
  Api& api,
  Tag,
  string_view name,
  type_identity<Signature>) -> std::add_pointer_t<Signature> {
    if(api.GetProcAddress && api.GetError) {
        _full_name.clear();
        _full_name.reserve(3 + name.size() + 1);
        _full_name.append("alc");
        _full_name.append(name.data(), std::size_t(name.size()));
        auto func = api.GetProcAddress(nullptr, _full_name.c_str());
        if(alc_types::error_code_no_error(api.GetError())) {
            return reinterpret_cast<std::remove_pointer_t<Signature>*>(func);
        }
    }
    return nullptr;
}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

