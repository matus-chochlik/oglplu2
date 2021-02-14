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
auto al_api_traits::load_constant(
  Api& api,
  string_view name,
  type_identity<Type>) -> std::tuple<Type, bool> {
    if(api.GetEnumValue && api.GetError) {
        _full_name.clear();
        _full_name.reserve(3 + name.size() + 1);
        _full_name.append("AL_");
        _full_name.append(name.data(), std::size_t(name.size()));
        const auto val = api.GetEnumValue(_full_name.c_str());
        if(al_types::error_code_no_error(api.GetError())) {
            return {static_cast<Type>(val), true};
        }
    }
    return {{}, false};
}
//------------------------------------------------------------------------------
template <typename Api, typename Tag, typename Signature>
auto al_api_traits::link_function(
  Api& api,
  Tag,
  string_view name,
  type_identity<Signature>) -> std::add_pointer_t<Signature> {
    if(api.GetProcAddress && api.GetError) {
        _full_name.clear();
        _full_name.reserve(2 + name.size() + 1);
        _full_name.append("al");
        _full_name.append(name.data(), std::size_t(name.size()));
        auto func = api.GetProcAddress(_full_name.c_str());
        if(al_types::error_code_no_error(api.GetError())) {
            return reinterpret_cast<std::remove_pointer_t<Signature>*>(func);
        }
    }
    return nullptr;
}
//------------------------------------------------------------------------------
} // namespace eagine::oalp

