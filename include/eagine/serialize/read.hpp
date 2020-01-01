/**
 *  @file eagine/serialize/read.hpp
 *
 *  Copyright Matus Chochlik.
 *  Distributed under the Boost Software License, Version 1.0.
 *  See accompanying file LICENSE_1_0.txt or copy at
 *   http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef EAGINE_SERIALIZE_READ_HPP
#define EAGINE_SERIALIZE_READ_HPP

#include "../memory/span_algo.hpp"
#include "read_backend.hpp"
#include <array>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
struct deserializer;
//------------------------------------------------------------------------------
template <typename T>
struct deserializer<T&> : deserializer<T> {};
//------------------------------------------------------------------------------
template <typename T>
struct plain_deserializer {

    template <typename Backend>
    static void read(T& value, Backend& backend) {
        backend.read(cover_one(value));
    }

    template <typename Backend>
    static void read(span<T> values, Backend& backend) {
        backend.read(values);
    }
};
//------------------------------------------------------------------------------
template <>
struct deserializer<bool> : plain_deserializer<bool> {};
template <>
struct deserializer<char> : plain_deserializer<char> {};
template <>
struct deserializer<std::int16_t> : plain_deserializer<std::int16_t> {};
template <>
struct deserializer<std::int32_t> : plain_deserializer<std::int32_t> {};
template <>
struct deserializer<std::int64_t> : plain_deserializer<std::int64_t> {};
template <>
struct deserializer<std::uint8_t> : plain_deserializer<std::uint8_t> {};
template <>
struct deserializer<std::uint16_t> : plain_deserializer<std::uint16_t> {};
template <>
struct deserializer<std::uint32_t> : plain_deserializer<std::uint32_t> {};
template <>
struct deserializer<std::uint64_t> : plain_deserializer<std::uint64_t> {};
template <>
struct deserializer<float> : plain_deserializer<float> {};
template <>
struct deserializer<double> : plain_deserializer<double> {};
template <>
struct deserializer<std::string> : plain_deserializer<std::string> {};
//------------------------------------------------------------------------------
template <typename T>
struct common_deserializer {

    template <typename Backend>
    void read(span<T> values, Backend& backend) const {
        for(auto& elem : values) {
            static_cast<const deserializer<T>*>(this)->read(elem, backend);
        }
    }
};
//------------------------------------------------------------------------------
template <typename... T>
struct deserializer<std::tuple<T...>> : common_deserializer<std::tuple<T...>> {

    template <typename Backend>
    void read(std::tuple<T...>& values, Backend& backend) {
        span_size_t elem_count{span_size_t(sizeof...(T))};
        backend.begin_list(elem_count);
        _read_members(
          values, backend, std::make_index_sequence<sizeof...(T)>());
        backend.finish_list();
    }

private:
    template <typename Tuple, typename Backend, std::size_t... I>
    void _read_members(
      Tuple& values, Backend& backend, std::index_sequence<I...>) {
        (...,
         _read_member(
           I, std::get<I>(values), backend, std::get<I>(_deserializers)));
    }

    template <typename Elem, typename Backend, typename Serializer>
    static void _read_member(
      std::size_t index, Elem& elem, Backend& backend, Serializer& serial) {
        backend.begin_element(span_size_t(index));
        serial.read(elem, backend);
        backend.finish_element(span_size_t(index));
    }

    std::tuple<deserializer<T>...> _deserializers{};
};
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
struct deserializer<std::array<T, N>> : common_deserializer<std::array<T, N>> {
    template <typename Backend>
    void read(std::array<T, N>& values, Backend& backend) const {
        auto elem_count = span_size_t(N);
        backend.begin_list(elem_count);
        _elem_deserializer.read(cover(values), backend);
        backend.finish_list();
    }

private:
    deserializer<T> _elem_deserializer{};
};
//------------------------------------------------------------------------------
template <typename T, typename A>
struct deserializer<std::vector<T, A>>
  : common_deserializer<std::vector<T, A>> {
    template <typename Backend>
    void read(std::vector<T, A>& values, Backend& backend) const {
        auto elem_count{0};
        backend.begin_list(elem_count);
        values.resize(elem_count);
        _elem_deserializer.read(view(values), backend);
        backend.finish_list();
    }

private:
    deserializer<T> _elem_deserializer{};
};
//------------------------------------------------------------------------------
template <typename T, typename Backend>
std::enable_if_t<std::is_base_of_v<deserializer_backend, Backend>> deserialize(
  T& value, Backend& backend) {
    backend.start();
    deserializer<T> reader;
    reader.read(value, backend);
    backend.finish();
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_READ_HPP

