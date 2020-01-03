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

#include "../assert.hpp"
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
    static serialization_result write(T value, Backend& backend) {
        span_size_t written{0};
        auto errors = backend.write(view_one(value), written);
        if(written < 1) {
            EAGINE_ASSERT(
              errors.has(serialization_error_code::incomplete_write));
        }
        return errors;
    }

    template <typename Backend>
    static serialization_result write(span<const T> values, Backend& backend) {
        span_size_t written{0};
        auto errors = backend.write(values, written);
        if(written < values.size()) {
            EAGINE_ASSERT(
              errors.has(serialization_error_code::incomplete_write));
        }
        return errors;
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
    serialization_result write(span<const T> values, Backend& backend) const {
        serialization_result errors{};
        span_size_t i = 0;
        for(auto& elem : values) {
            errors |= backend.begin_element(i);
            if(!errors) {
                errors |=
                  static_cast<const serializer<T>*>(this)->write(elem, backend);
                errors |= backend.finish_element(i++);
            }
        }
        return errors;
    }
};
//------------------------------------------------------------------------------
template <typename... T>
struct serializer<std::tuple<T...>> : common_serializer<std::tuple<T...>> {
    template <typename Backend>
    serialization_result write(
      const std::tuple<T...>& values, Backend& backend) {
        serialization_result errors{};
        errors |= backend.begin_list(span_size_t(sizeof...(T)));
        if(!errors) {
            _write_elements(
              errors,
              values,
              backend,
              std::make_index_sequence<sizeof...(T)>());
            errors |= backend.finish_list();
        }
        return errors;
    }

private:
    template <typename Tuple, typename Backend, std::size_t... I>
    void _write_elements(
      serialization_result& errors,
      Tuple& values,
      Backend& backend,
      std::index_sequence<I...>) {
        (...,
         _write_element(
           errors, I, std::get<I>(values), backend, std::get<I>(_serializers)));
    }

    template <typename Elem, typename Backend, typename Serializer>
    static void _write_element(
      serialization_result& errors,
      std::size_t index,
      Elem& elem,
      Backend& backend,
      Serializer& serial) {
        if(!errors) {
            errors |= backend.begin_element(span_size_t(index));
            if(!errors) {
                errors |= serial.write(elem, backend);
                errors |= backend.finish_element(span_size_t(index));
            }
        }
    }

    std::tuple<serializer<T>...> _serializers{};
};
//------------------------------------------------------------------------------
template <typename... T>
struct serializer<std::tuple<std::pair<string_view, T>...>>
  : common_serializer<std::tuple<std::pair<string_view, T>...>> {
    template <typename Backend>
    serialization_result write(
      const std::tuple<std::pair<string_view, T>...>& members,
      Backend& backend) {
        serialization_result errors{};
        errors |= backend.begin_struct(span_size_t(sizeof...(T)));
        if(!errors) {
            _write_members(
              errors,
              members,
              backend,
              std::make_index_sequence<sizeof...(T)>());
            errors |= backend.finish_struct();
        }
        return errors;
    }

private:
    template <typename Tuple, typename Backend, std::size_t... I>
    void _write_members(
      serialization_result& errors,
      Tuple& members,
      Backend& backend,
      std::index_sequence<I...>) {
        (...,
         _write_member(
           errors,
           std::get<0>(std::get<I>(members)),
           std::get<1>(std::get<I>(members)),
           backend,
           std::get<I>(_serializers)));
    }

    template <typename Memb, typename Backend, typename Serializer>
    static void _write_member(
      serialization_result& errors,
      string_view name,
      Memb& value,
      Backend& backend,
      Serializer& serial) {
        if(!errors) {
            errors |= backend.begin_member(name);
            if(!errors) {
                errors |= serial.write(value, backend);
                errors |= backend.finish_member(name);
            }
        }
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
    serialization_result write(
      const std::basic_string<Char, Traits, Alloc>& value,
      Backend& backend) const {
        return _serializer.write(value, backend);
    }

private:
    serializer<string_view> _serializer{};
};
//------------------------------------------------------------------------------
template <typename T>
struct serializer<span<const T>> : common_serializer<span<const T>> {
    template <typename Backend>
    serialization_result write(span<const T> values, Backend& backend) const {
        serialization_result errors{};
        errors |= backend.begin_list(values.size());
        if(!errors) {
            errors |= _elem_serializer.write(values, backend);
            errors |= backend.finish_list();
        }
        return errors;
    }

private:
    serializer<T> _elem_serializer{};
};
//------------------------------------------------------------------------------
template <typename T>
struct serializer<span<T>> : serializer<span<const T>> {};
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
struct serializer<std::array<T, N>> : common_serializer<std::array<T, N>> {
    template <typename Backend>
    serialization_result write(
      const std::array<T, N>& values, Backend& backend) const {
        serialization_result errors{};
        errors |= backend.begin_list(span_size_t(N));
        if(!errors) {
            errors |= _elem_serializer.write(view(values), backend);
            errors |= backend.finish_list();
        }
        return errors;
    }

private:
    serializer<T> _elem_serializer{};
};
//------------------------------------------------------------------------------
template <typename T, typename A>
struct serializer<std::vector<T, A>> : common_serializer<std::vector<T, A>> {
    template <typename Backend>
    serialization_result write(
      const std::vector<T, A>& values, Backend& backend) const {
        serialization_result errors{};
        errors |= backend.begin_list(values.size());
        if(!errors) {
            errors |= _elem_serializer.write(view(values), backend);
            errors |= backend.finish_list();
        }
        return errors;
    }

private:
    serializer<T> _elem_serializer{};
};
//------------------------------------------------------------------------------
template <typename T, typename Backend>
std::enable_if_t<
  std::is_base_of_v<serializer_backend, Backend>,
  serialization_result>
serialize(const T& value, Backend& backend) {
    serialization_result errors{};
    errors |= backend.start();
    if(!errors) {
        serializer<T> writer;
        errors |= writer.write(value, backend);
        errors |= backend.finish();
    }
    return errors;
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_WRITE_HPP

