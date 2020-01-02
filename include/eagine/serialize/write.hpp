/**
 *  @file eagine/serialize/write.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_WRITE_HPP
#define EAGINE_SERIALIZE_WRITE_HPP

#include "write_backend.hpp"
#include <array>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
struct serializer;
//------------------------------------------------------------------------------
template <typename T>
struct serializer<T&> : serializer<T> {};
//------------------------------------------------------------------------------
template <typename T>
struct serializer<const T&> : serializer<T> {};
//------------------------------------------------------------------------------
template <typename T>
struct plain_serializer {
    template <typename Backend>
    static void write(T value, Backend& backend) {
        backend.write(view_one(value));
    }

    template <typename Backend>
    static void write(span<const T> values, Backend& backend) {
        backend.write(values);
    }
};

//------------------------------------------------------------------------------
template <>
struct serializer<bool> : plain_serializer<bool> {};
template <>
struct serializer<char> : plain_serializer<char> {};
template <>
struct serializer<std::int16_t> : plain_serializer<std::int16_t> {};
template <>
struct serializer<std::int32_t> : plain_serializer<std::int32_t> {};
template <>
struct serializer<std::int64_t> : plain_serializer<std::int64_t> {};
template <>
struct serializer<std::uint8_t> : plain_serializer<std::uint8_t> {};
template <>
struct serializer<std::uint16_t> : plain_serializer<std::uint16_t> {};
template <>
struct serializer<std::uint32_t> : plain_serializer<std::uint32_t> {};
template <>
struct serializer<std::uint64_t> : plain_serializer<std::uint64_t> {};
template <>
struct serializer<float> : plain_serializer<float> {};
template <>
struct serializer<double> : plain_serializer<double> {};
template <>
struct serializer<string_view> : plain_serializer<string_view> {};
//------------------------------------------------------------------------------
template <typename T>
struct common_serializer {

    template <typename Backend>
    void write(span<const T> values, Backend& backend) const {
        span_size_t i = 0;
        for(auto& elem : values) {
            backend.begin_element(i);
            static_cast<const serializer<T>*>(this)->write(elem, backend);
            backend.finish_element(i++);
        }
    }
};
//------------------------------------------------------------------------------
template <typename... T>
struct serializer<std::tuple<T...>> : common_serializer<std::tuple<T...>> {
    template <typename Backend>
    void write(const std::tuple<T...>& values, Backend& backend) {
        backend.begin_list(span_size_t(sizeof...(T)));
        _write_elements(
          values, backend, std::make_index_sequence<sizeof...(T)>());
        backend.finish_list();
    }

private:
    template <typename Tuple, typename Backend, std::size_t... I>
    void _write_elements(
      Tuple& values, Backend& backend, std::index_sequence<I...>) {
        (...,
         _write_element(
           I, std::get<I>(values), backend, std::get<I>(_serializers)));
    }

    template <typename Elem, typename Backend, typename Serializer>
    static void _write_element(
      std::size_t index, Elem& elem, Backend& backend, Serializer& serial) {
        backend.begin_element(span_size_t(index));
        serial.write(elem, backend);
        backend.finish_element(span_size_t(index));
    }

    std::tuple<serializer<T>...> _serializers{};
};
//------------------------------------------------------------------------------
template <typename... T>
struct serializer<std::tuple<std::pair<string_view, T>...>>
  : common_serializer<std::tuple<std::pair<string_view, T>...>> {
    template <typename Backend>
    void write(
      const std::tuple<std::pair<string_view, T>...>& members,
      Backend& backend) {
        backend.begin_struct(span_size_t(sizeof...(T)));
        _write_members(
          members, backend, std::make_index_sequence<sizeof...(T)>());
        backend.finish_struct();
    }

private:
    template <typename Tuple, typename Backend, std::size_t... I>
    void _write_members(
      Tuple& members, Backend& backend, std::index_sequence<I...>) {
        (...,
         _write_member(
           std::get<0>(std::get<I>(members)),
           std::get<1>(std::get<I>(members)),
           backend,
           std::get<I>(_serializers)));
    }

    template <typename Memb, typename Backend, typename Serializer>
    static void _write_member(
      string_view name, Memb& value, Backend& backend, Serializer& serial) {
        backend.begin_member(name);
        serial.write(value, backend);
        backend.finish_member(name);
    }

    std::tuple<serializer<T>...> _serializers{};
};
//------------------------------------------------------------------------------
template <std::size_t N>
struct serializer<char[N]> : serializer<string_view> {};
//------------------------------------------------------------------------------
template <typename Char, typename Traits, typename Alloc>
struct serializer<std::basic_string<Char, Traits, Alloc>>
  : common_serializer<std::basic_string<Char, Traits, Alloc>> {
    template <typename Backend>
    void write(
      const std::basic_string<Char, Traits, Alloc>& value,
      Backend& backend) const {
        _serializer.write(value, backend);
    }

private:
    serializer<string_view> _serializer{};
};
//------------------------------------------------------------------------------
template <typename T>
struct serializer<span<const T>> : common_serializer<span<const T>> {
    template <typename Backend>
    void write(span<const T> values, Backend& backend) const {
        backend.begin_list(values.size());
        _elem_serializer.write(values, backend);
        backend.finish_list();
    }

private:
    serializer<T> _elem_serializer{};
};
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
struct serializer<std::array<T, N>> : common_serializer<std::array<T, N>> {
    template <typename Backend>
    void write(const std::array<T, N>& values, Backend& backend) const {
        backend.begin_list(span_size_t(N));
        _elem_serializer.write(view(values), backend);
        backend.finish_list();
    }

private:
    serializer<T> _elem_serializer{};
};
//------------------------------------------------------------------------------
template <typename T, typename A>
struct serializer<std::vector<T, A>> : common_serializer<std::vector<T, A>> {
    template <typename Backend>
    void write(const std::vector<T, A>& values, Backend& backend) const {
        backend.begin_list(values.size());
        _elem_serializer.write(view(values), backend);
        backend.finish_list();
    }

private:
    serializer<T> _elem_serializer{};
};
//------------------------------------------------------------------------------
template <typename T, typename Backend>
std::enable_if_t<std::is_base_of_v<serializer_backend, Backend>> serialize(
  const T& value, Backend& backend) {
    backend.start();
    serializer<T> writer;
    writer.write(value, backend);
    backend.finish();
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_WRITE_HPP

