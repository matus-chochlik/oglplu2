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

#include "../math/functions.hpp"
#include "../memory/span_algo.hpp"
#include "../reflect/enumerators.hpp"
#include "read_backend.hpp"
#include <algorithm>
#include <array>
#include <string>
#include <tuple>
#include <type_traits>
#include <vector>

namespace eagine {
//------------------------------------------------------------------------------
template <typename T>
struct fragment_deserialize_wrapper;
//------------------------------------------------------------------------------
template <typename T>
class fragment_deserialize_wrapper<span<T>> {
public:
    constexpr fragment_deserialize_wrapper() noexcept = default;

    constexpr fragment_deserialize_wrapper(span<T> dst) noexcept {
        set_target(dst);
    }

    void set_target(span<T> dst) noexcept {
        _dst = dst;
        _done_bits.resize(std_size(dst.size()), false);
        _done_size = 0;
    }

    auto slice(span_size_t offset, span_size_t size) const noexcept {
        return memory::slice(_dst, offset, size);
    }

    void mark_done(span_size_t offs, span_size_t size) noexcept {
        auto i = math::minimum(_done_bits.begin() + offs, _done_bits.end());
        auto e = math::minimum(i + size, _done_bits.end());
        while(i != e) {
            if(!*i) {
                *i = true;
                ++_done_size;
            }
            ++i;
        }
    }

    bool is_done() const noexcept {
        return _done_size >= _dst.size();
    }

private:
    span<T> _dst{};
    std::vector<bool> _done_bits{};
    span_size_t _done_size{0};
};
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
    static deserialization_result read(T& value, Backend& backend) {
        span_size_t done{0};
        return backend.read(cover_one(value), done);
    }

    template <typename Backend>
    static deserialization_result read(span<T> values, Backend& backend) {
        span_size_t done{0};
        return backend.read(values, done);
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
struct deserializer<identifier> : plain_deserializer<identifier> {};
template <>
struct deserializer<decl_name_storage>
  : plain_deserializer<decl_name_storage> {};
template <>
struct deserializer<std::string> : plain_deserializer<std::string> {};
//------------------------------------------------------------------------------
template <typename T>
struct common_deserializer {

    template <typename Backend>
    deserialization_result read(span<T> values, Backend& backend) const {
        using ec = deserialization_error_code;
        deserialization_result result{};
        for(auto& elem : values) {
            result |=
              static_cast<const deserializer<T>*>(this)->read(elem, backend);
            if(
              result.has(ec::not_enough_data) ||
              result.has(ec::backend_error)) {
                break;
            }
        }
        return result;
    }
};
//------------------------------------------------------------------------------
template <typename... T>
struct deserializer<std::tuple<T...>> : common_deserializer<std::tuple<T...>> {

    template <typename Backend>
    deserialization_result read(std::tuple<T...>& values, Backend& backend) {
        deserialization_result errors{};
        span_size_t elem_count{0};
        errors |= backend.begin_list(elem_count);
        if(elem_count < span_size(sizeof...(T))) {
            errors |= deserialization_error_code::missing_element;
        } else if(elem_count > span_size(sizeof...(T))) {
            errors |= deserialization_error_code::excess_element;
        }
        if(errors.has_at_most(deserialization_error_code::excess_element)) {
            _read_elements(
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
    void _read_elements(
      deserialization_result& errors,
      Tuple& values,
      Backend& backend,
      std::index_sequence<I...>) {
        (...,
         _read_element(
           errors,
           I,
           std::get<I>(values),
           backend,
           std::get<I>(_deserializers)));
    }

    template <typename Elem, typename Backend, typename Serializer>
    static void _read_element(
      deserialization_result& errors,
      std::size_t index,
      Elem& elem,
      Backend& backend,
      Serializer& serial) {
        if(!errors) {
            errors |= backend.begin_element(span_size(index));
            if(!errors) {
                errors |= serial.read(elem, backend);
                errors |= backend.finish_element(span_size(index));
            }
        }
    }

    std::tuple<deserializer<T>...> _deserializers{};
};
//------------------------------------------------------------------------------
template <typename... T>
struct deserializer<std::tuple<std::pair<string_view, T>...>>
  : common_deserializer<std::tuple<std::pair<string_view, T>...>> {

    template <typename Backend>
    deserialization_result read(
      std::tuple<std::pair<string_view, T>...>& values, Backend& backend) {
        deserialization_result errors{};
        span_size_t memb_count{0};
        errors |= backend.begin_struct(memb_count);
        if(memb_count < span_size(sizeof...(T))) {
            errors |= deserialization_error_code::missing_member;
        } else if(memb_count > span_size(sizeof...(T))) {
            errors |= deserialization_error_code::excess_member;
        }
        if(errors.has_at_most(deserialization_error_code::excess_member)) {
            _read_members(
              errors,
              values,
              backend,
              std::make_index_sequence<sizeof...(T)>());
            errors |= backend.finish_struct();
        }
        return errors;
    }

private:
    template <typename Tuple, typename Backend, std::size_t... I>
    void _read_members(
      deserialization_result& errors,
      Tuple& values,
      Backend& backend,
      std::index_sequence<I...>) {
        (...,
         _read_member(
           errors,
           std::get<0>(std::get<I>(values)),
           std::get<1>(std::get<I>(values)),
           backend,
           std::get<I>(_deserializers)));
    }

    template <typename Memb, typename Backend, typename Serializer>
    static void _read_member(
      deserialization_result& errors,
      string_view name,
      Memb& value,
      Backend& backend,
      Serializer& serial) {
        if(!errors) {
            errors |= backend.begin_member(name);
            if(!errors) {
                errors |= serial.read(value, backend);
                errors |= backend.finish_member(name);
            }
        }
    }

    std::tuple<deserializer<T>...> _deserializers{};
};
//------------------------------------------------------------------------------
template <typename T>
struct deserializer<fragment_deserialize_wrapper<span<T>>>
  : common_deserializer<fragment_deserialize_wrapper<span<T>>> {

    template <typename Backend>
    deserialization_result read(
      fragment_deserialize_wrapper<span<T>>& frag, Backend& backend) const {
        deserialization_result errors{};
        span_size_t offs{0};
        errors |= _size_deserializer.read(offs, backend);
        if(!errors) {
            span_size_t size{0};
            errors |= _size_deserializer.read(size, backend);
            if(!errors) {
                span_size_t done{0};
                errors |= backend.read(frag.slice(offs, size), done);
                frag.mark_done(offs, done);
            }
        }
        return errors;
    }

    deserializer<span_size_t> _size_deserializer{};
};
//------------------------------------------------------------------------------
template <typename T, std::size_t N>
struct deserializer<std::array<T, N>> : common_deserializer<std::array<T, N>> {
    template <typename Backend>
    deserialization_result read(
      std::array<T, N>& values, Backend& backend) const {
        deserialization_result errors{};
        span_size_t elem_count{0};
        errors |= backend.begin_list(elem_count);
        if(elem_count < span_size(N)) {
            errors |= deserialization_error_code::missing_element;
        } else if(elem_count > span_size(N)) {
            errors |= deserialization_error_code::excess_element;
        }
        if(errors.has_at_most(deserialization_error_code::excess_element)) {
            errors |= _elem_deserializer.read(cover(values), backend);
            errors |= backend.finish_list();
        }
        return errors;
    }

private:
    deserializer<T> _elem_deserializer{};
};
//------------------------------------------------------------------------------
template <typename T, typename A>
struct deserializer<std::vector<T, A>>
  : common_deserializer<std::vector<T, A>> {
    template <typename Backend>
    deserialization_result read(
      std::vector<T, A>& values, Backend& backend) const {
        deserialization_result errors{};
        span_size_t elem_count{0};
        errors |= backend.begin_list(elem_count);
        if(!errors) {
            values.resize(std_size(elem_count));
            errors |= _elem_deserializer.read(cover(values), backend);
            errors |= backend.finish_list();
        }
        return errors;
    }

private:
    deserializer<T> _elem_deserializer{};
};
//------------------------------------------------------------------------------
template <typename T>
struct enum_deserializer {
    template <typename Backend>
    deserialization_result read(T& enumerator, Backend& backend) {
        deserialization_result errors{};
        if(backend.enum_as_string()) {
            decl_name_storage temp_name{};
            errors |= _name_deserializer.read(temp_name, backend);
            if(!errors) {
                if(auto found = from_string(temp_name.get(), identity<T>{})) {
                    enumerator = extract(found);
                } else {
                    errors |= deserialization_error_code::unexpected_data;
                }
            }
        } else {
            std::underlying_type_t<T> temp_value{};
            errors |= _value_deserializer.read(temp_value, backend);
            if(!errors) {
                if(auto found = from_value(temp_value, identity<T>{})) {
                    enumerator = extract(found);
                } else {
                    errors |= deserialization_error_code::unexpected_data;
                }
            }
        }
        return errors;
    }

private:
    deserializer<std::underlying_type_t<T>> _value_deserializer{};
    deserializer<decl_name_storage> _name_deserializer{};
};
//------------------------------------------------------------------------------
template <typename T>
struct deserializer
  : std::conditional_t<
      has_enumerator_mapping_v<T>,
      enum_deserializer<T>,
      nothing_t> {};
//------------------------------------------------------------------------------
template <typename T, typename Backend>
std::enable_if_t<
  std::is_base_of_v<deserializer_backend, Backend>,
  deserialization_result>
deserialize(T& value, Backend& backend) {
    deserialization_result errors{};
    errors |= backend.begin();
    if(!errors) {
        deserializer<T> reader;
        errors |= reader.read(value, backend);
        errors |= backend.finish();
    }
    return errors;
}
//------------------------------------------------------------------------------
} // namespace eagine

#endif // EAGINE_SERIALIZE_READ_HPP

