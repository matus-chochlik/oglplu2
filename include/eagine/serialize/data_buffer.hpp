/// @file eagine/serialize/data_buffer.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SERIALIZE_DATA_BUFFER_HPP
#define EAGINE_SERIALIZE_DATA_BUFFER_HPP

#include "../identifier.hpp"
#include "../int_constant.hpp"
#include "../reflect/data_members.hpp"
#include "../reflect/enumerators.hpp"
#include "../types.hpp"
#include <array>
#include <cstdint>
#include <string>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
template <std::size_t S, bool C = true>
struct serialize_size_constant : size_constant<S> {

    static constexpr bool is_constant = C;

    template <typename X>
    static constexpr auto get(const X&) noexcept {
        return std_size(S);
    }
};
//------------------------------------------------------------------------------
template <identifier_t SerializerId, typename T, typename Selector>
struct get_serialize_buffer_size;

template <identifier_t SerializerId, typename T, typename Selector>
constexpr const auto serialize_buffer_size_v =
  get_serialize_buffer_size<SerializerId, T, Selector>::value;

template <identifier_t SerializerId, typename T, typename Selector>
constexpr const auto serialize_buffer_is_constant_v =
  get_serialize_buffer_size<SerializerId, T, Selector>::value;
//------------------------------------------------------------------------------
template <identifier_t Sid, typename T, typename Selector>
struct get_serialize_buffer_size<Sid, T&, Selector>
  : get_serialize_buffer_size<Sid, T, Selector> {};

template <identifier_t Sid, typename T, typename Selector>
struct get_serialize_buffer_size<Sid, const T, Selector>
  : get_serialize_buffer_size<Sid, T, Selector> {};

template <identifier_t Sid, typename T, typename Selector>
struct get_serialize_buffer_size<Sid, const T&, Selector>
  : get_serialize_buffer_size<Sid, T, Selector> {};
//------------------------------------------------------------------------------
template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, bool, Selector>
  : serialize_size_constant<8> {};

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, byte, Selector>
  : serialize_size_constant<4> {};

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, char, Selector>
  : serialize_size_constant<4> {};

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, std::int16_t, Selector>
  : serialize_size_constant<6> {};

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, std::uint16_t, Selector>
  : serialize_size_constant<6> {};

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, std::int32_t, Selector>
  : serialize_size_constant<12> {};

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, std::uint32_t, Selector>
  : serialize_size_constant<12> {};

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, std::int64_t, Selector>
  : serialize_size_constant<24> {};

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, std::uint64_t, Selector>
  : serialize_size_constant<24> {};

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, float, Selector>
  : serialize_size_constant<24> {};

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, double, Selector>
  : serialize_size_constant<48> {};

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, identifier, Selector>
  : serialize_size_constant<12> {};

template <identifier_t Sid, typename Selector>
struct get_serialize_buffer_size<Sid, std::string, Selector>
  : serialize_size_constant<0, false> {

    static constexpr auto
    get(std::pair<string_view, const std::string&> mapped) noexcept {
        return std_size(
          12 + mapped.first.size() + 2 + span_size(mapped.second.size()));
    }
};
//------------------------------------------------------------------------------
template <identifier_t Sid, typename T, std::size_t N, typename Selector>
struct get_serialize_buffer_size<Sid, std::array<T, N>, Selector>
  : serialize_size_constant<
      (4 + (2 + serialize_buffer_size_v<Sid, T, Selector>)*N),
      (get_serialize_buffer_size<Sid, T, Selector>::is_constant)> {

    static constexpr auto
    get(std::pair<string_view, const std::array<T, N>&> mapped) noexcept {
        auto result = std_size(12 + mapped.first.size());
        for(auto& e : mapped.second) {
            result +=
              2 + get_serialize_buffer_size<Sid, T, Selector>::get({{}, e});
        }
        return result;
    }
};
//------------------------------------------------------------------------------
template <identifier_t Sid, typename... T, typename Selector>
struct get_serialize_buffer_size<Sid, std::tuple<T...>, Selector>
  : serialize_size_constant<
      (4 + ... + (2 + serialize_buffer_size_v<Sid, T, Selector>)),
      (true && ... && (serialize_buffer_is_constant_v<Sid, T, Selector>))> {

    template <typename Tup>
    static constexpr auto
    get(std::pair<string_view, const Tup&> mapped) noexcept {
        return std_size(
          12 + mapped.first.size() + 2 +
          _do_get(mapped.second, std::make_index_sequence<sizeof...(T)>()));
    }

private:
    template <typename Tup, std::size_t... I>
    static constexpr auto
    _do_get(const Tup& t, std::index_sequence<I...>) noexcept {
        return (
          0 + ... +
          (2 + get_serialize_buffer_size<Sid, T, Selector>::get(
                 {string_view(), std::get<I>(t)})));
    }
};
//------------------------------------------------------------------------------
template <identifier_t Sid, typename T, typename Selector>
struct get_struct_serialize_buffer_size : serialize_size_constant<0, false> {

    static constexpr auto get(std::pair<string_view, const T&> mapped) noexcept {
        return std_size(
          12 + mapped.first.size() + 2 + _get(map_data_members(mapped.second)));
    }

private:
    template <typename Mapped>
    static constexpr auto _get(const Mapped& mapped) noexcept {
        return _do_get(
          mapped, std::make_index_sequence<std::tuple_size_v<Mapped>>());
    }

    template <typename... M, std::size_t... I>
    static constexpr auto _do_get(
      const std::tuple<std::pair<string_view, const M&>...>& mapped,
      std::index_sequence<I...>) noexcept {
        return span_size(
          (0 + ... +
           (2 + get_serialize_buffer_size<Sid, M, Selector>::get(
                  std::pair<string_view, const M&>{
                    std::get<I>(mapped).first, std::get<I>(mapped).second}))));
    }
};
//------------------------------------------------------------------------------
template <identifier_t Sid, typename T, typename Selector>
struct get_serialize_buffer_size
  : std::conditional_t<
      has_data_member_mapping_v<T>,
      get_struct_serialize_buffer_size<Sid, T, Selector>,
      std::conditional_t<
        has_enumerator_mapping_v<T>,
        serialize_size_constant<96>,
        void>> {};
//------------------------------------------------------------------------------
template <identifier_t SerializerId, typename T, typename Selector>
constexpr auto get_serialize_array_for(const T&, Selector) noexcept
  -> std::array<byte, serialize_buffer_size_v<SerializerId, T, Selector>> {
    return {};
}
//------------------------------------------------------------------------------
template <identifier_t SerializerId, typename T, typename Selector>
inline auto get_serialize_vector_for(const T& inst, Selector) noexcept
  -> std::vector<byte> {
    std::vector<byte> result;
    result.resize(get_serialize_buffer_size<SerializerId, T, Selector>::get(
      std::pair<string_view, const T&>({}, inst)));
    return result;
}
//------------------------------------------------------------------------------
template <
  identifier_t SerializerId,
  typename T,
  typename Selector = default_selector_t>
constexpr auto serialize_buffer_for(const T& inst, Selector sel = {}) {
    if constexpr(get_serialize_buffer_size<SerializerId, T, Selector>::
                   is_constant) {
        return get_serialize_array_for<SerializerId>(inst, sel);
    } else {
        return get_serialize_vector_for<SerializerId>(inst, sel);
    }
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif
