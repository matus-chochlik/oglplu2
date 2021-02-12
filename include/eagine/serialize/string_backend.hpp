/// @file eagine/serialize/string_backend.hpp
///
/// Copyright Matus Chochlik.
/// Distributed under the Boost Software License, Version 1.0.
/// See accompanying file LICENSE_1_0.txt or copy at
///  http://www.boost.org/LICENSE_1_0.txt
///

#ifndef EAGINE_SERIALIZE_STRING_BACKEND_HPP
#define EAGINE_SERIALIZE_STRING_BACKEND_HPP

#include "read_backend.hpp"
#include "write_backend.hpp"
#include <cstdio>

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-nonliteral"
#endif

namespace eagine {
//------------------------------------------------------------------------------
class string_serializer_backend
  : public serializer_backend_id<
      common_serializer_backend<string_serializer_backend>,
      EAGINE_ID_V(String)> {
    using base = serializer_backend_id<
      common_serializer_backend<string_serializer_backend>,
      EAGINE_ID_V(String)>;

public:
    using base::base;
    using base::remaining_size;
    using base::sink;
    using error_code = serialization_error_code;
    using result = serialization_errors;

private:
    auto _write_one(bool value, type_identity<bool>) -> result {
        if(value) {
            return sink("true");
        }
        return sink("false");
    }

    auto _write_one(char value, type_identity<char>) {
        result errors = sink('\'');
        errors |= sink(value);
        errors |= sink('\'');
        return errors;
    }

    template <typename T, std::size_t L>
    auto _sprintf_one(T value, const char (&fmt)[L]) -> result {
        std::array<char, 64> temp{};
        // TODO: to_chars from_chars when available
        // NOLINTNEXTLINE(hicpp-vararg)
        std::snprintf(
          temp.data(), temp.size(), static_cast<const char*>(fmt), value);
        return sink(string_view(temp.data()));
    }

    auto _write_one(byte value, type_identity<byte>) {
        return _sprintf_one(value, "%02hhx");
    }

    auto _write_one(signed char value, type_identity<signed char>) {
        return _sprintf_one(value, "%hhd");
    }

    auto _write_one(short value, type_identity<short>) {
        return _sprintf_one(value, "%hd");
    }

    auto _write_one(unsigned short value, type_identity<unsigned short>) {
        return _sprintf_one(value, "%hu");
    }

    auto _write_one(int value, type_identity<int>) {
        return _sprintf_one(value, "%d");
    }

    auto _write_one(unsigned value, type_identity<unsigned>) {
        return _sprintf_one(value, "%u");
    }

    auto _write_one(long value, type_identity<long>) {
        return _sprintf_one(value, "%ld");
    }

    auto _write_one(unsigned long value, type_identity<unsigned long>) {
        return _sprintf_one(value, "%lu");
    }

    auto _write_one(long long value, type_identity<long long>) {
        return _sprintf_one(value, "%lld");
    }

    auto
    _write_one(unsigned long long value, type_identity<unsigned long long>) {
        return _sprintf_one(value, "%llu");
    }

    auto _write_one(float value, type_identity<float>) {
        return _sprintf_one(value, "%f");
    }

    auto _write_one(double value, type_identity<double>) {
        return _sprintf_one(value, "%lf");
    }

    auto _write_one(identifier id, type_identity<identifier>) {
        return sink(id.name().view());
    }

    auto _write_one(decl_name name, type_identity<decl_name>) {
        return sink(name);
    }

    auto _write_one(string_view str, type_identity<string_view>) {
        result errors = sink('"');
        errors |= _write_one(str.size(), type_identity<span_size_t>{});
        errors |= sink('|');
        errors |= sink(str);
        errors |= sink('"');
        return errors;
    }

public:
    template <typename T>
    auto do_write(span<const T> values, span_size_t& done) -> result {
        done = 0;
        result errors{};
        for(auto& val : values) {
            errors |= _write_one(val, type_identity<T>{});
            errors |= sink(';');
            if(errors) {
                break;
            }
            ++done;
        }

        return errors;
    }

    auto enum_as_string() -> bool final {
        return true;
    }

    auto begin() -> result final {
        return sink('<');
    }

    auto begin_struct(span_size_t count) -> result final {
        result errors = sink('{');
        errors |= _write_one(count, type_identity<span_size_t>{});
        errors |= sink('|');
        return errors;
    }

    auto begin_member(string_view name) -> result final {
        result errors = sink(name);
        errors |= sink(':');
        return errors;
    }

    auto finish_member(string_view) -> result final {
        return {};
    }

    auto finish_struct() -> result final {
        return sink("};");
    }

    auto begin_list(span_size_t count) -> result final {
        result errors = sink('[');
        errors |= _write_one(count, type_identity<span_size_t>{});
        errors |= sink('|');
        return errors;
    }

    auto begin_element(span_size_t) -> result final {
        return {};
    }

    auto finish_element(span_size_t) -> result final {
        return {};
    }

    auto finish_list() -> result final {
        return sink("];");
    }

    auto finish() -> result final {
        return sink(">\0");
    }
};
//------------------------------------------------------------------------------
class string_deserializer_backend
  : public serializer_backend_id<
      common_deserializer_backend<string_deserializer_backend>,
      EAGINE_ID_V(String)> {
    using base = serializer_backend_id<
      common_deserializer_backend<string_deserializer_backend>,
      EAGINE_ID_V(String)>;

public:
    using base::base;
    using base::consume_until;
    using base::require;
    using error_code = deserialization_error_code;
    using result = deserialization_errors;

private:
    auto _read_one(bool& value, char delimiter) -> result {
        result temp{};
        if(this->consume("true", temp)) {
            value = true;
        } else if(this->consume("false", temp)) {
            value = false;
        } else {
            return temp;
        }
        return require(delimiter);
    }

    auto _read_one(char& value, char delimiter) {
        result errors = require('\'');
        if(!errors) {
            if(auto opt_char = this->top_char()) {
                value = extract(opt_char);
                pop(1);
            } else {
                errors |= error_code::not_enough_data;
            }
            if(!errors) {
                const char t[3] = {'\'', delimiter, '\0'};
                errors |= require(string_view(t));
            }
        }
        return errors;
    }

    template <typename T, std::size_t L>
    auto _sscanf_one(T& value, char delimiter, const char (&fmt)[L]) -> result {
        result errors{};
        if(auto src = this->string_before(delimiter, 128)) {
            auto fmtstr = static_cast<const char*>(fmt);
            // TODO: to_chars from_chars when available
            // NOLINTNEXTLINE(hicpp-vararg)
            if(std::sscanf(src.data(), fmtstr, &value) == 1) {
                pop(src.size() + 1);
            } else {
                errors |= error_code::invalid_format;
            }
        } else {
            errors |= error_code::not_enough_data;
        }
        return errors;
    }

    auto _read_one(byte& value, char delimiter) {
        const char fmt[6] = {'%', 'h', 'h', 'x', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    auto _read_one(signed char& value, char delimiter) {
        const char fmt[6] = {'%', 'h', 'h', 'd', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    auto _read_one(short& value, char delimiter) {
        const char fmt[5] = {'%', 'h', 'd', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    auto _read_one(unsigned short& value, char delimiter) {
        const char fmt[5] = {'%', 'h', 'u', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    auto _read_one(int& value, char delimiter) {
        const char fmt[4] = {'%', 'd', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    auto _read_one(unsigned& value, char delimiter) {
        const char fmt[4] = {'%', 'u', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    auto _read_one(long& value, char delimiter) {
        const char fmt[5] = {'%', 'l', 'd', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    auto _read_one(unsigned long& value, char delimiter) {
        const char fmt[5] = {'%', 'l', 'u', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    auto _read_one(long long& value, char delimiter) {
        const char fmt[6] = {'%', 'l', 'l', 'd', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    auto _read_one(unsigned long long& value, char delimiter) {
        const char fmt[6] = {'%', 'l', 'l', 'u', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    auto _read_one(float& value, char delimiter) {
        const char fmt[4] = {'%', 'f', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    auto _read_one(double& value, char delimiter) {
        const char fmt[5] = {'%', 'l', 'f', delimiter, '\0'};
        return _sscanf_one(value, delimiter, fmt);
    }

    auto _read_one(identifier& value, char delimiter) {
        result errors{};
        if(auto src = this->string_before(delimiter, 32)) {
            value = identifier(src);
            pop(src.size() + 1);
        } else {
            errors |= error_code::not_enough_data;
        }
        return errors;
    }

    auto _read_one(decl_name_storage& value, char delimiter) {
        result errors{};
        const auto max = decl_name_storage::max_length + 1;
        if(auto src = this->string_before(delimiter, max)) {
            value.assign(src);
            pop(src.size() + 1);
        } else {
            errors |= error_code::not_enough_data;
        }
        return errors;
    }

    auto _read_one(std::string& value, char delimiter) {
        result errors = require('"');
        if(!errors) {
            span_size_t len{0};
            errors |= _read_one(len, '|');
            if(!errors) {
                auto str = this->top_string(len);
                if(str.size() < len) {
                    errors |= error_code::not_enough_data;
                } else {
                    assign_to(value, str);
                    pop(str.size());
                    errors |= require('"');
                    errors |= require(delimiter);
                }
            }
        }
        return errors;
    }

public:
    template <typename T>
    auto do_read(span<T> values, span_size_t& done) -> result {
        done = 0;
        result errors{};
        for(T& val : values) {
            errors |= _read_one(val, ';');
            if(errors) {
                break;
            }
            ++done;
        }

        return errors;
    }

    auto enum_as_string() -> bool final {
        return true;
    }

    void skip_whitespaces() {
        consume_until([](byte b) { return !std::isspace(b); });
    }

    auto begin() -> result final {
        skip_whitespaces();
        return require('<');
    }

    auto begin_struct(span_size_t& count) -> result final {
        result errors = require('{');
        if(!errors) {
            errors |= _read_one(count, '|');
        }
        return errors;
    }

    auto begin_member(string_view name) -> result final {
        result errors = require(name);
        if(!errors) {
            errors |= require(':');
        }
        return errors;
    }

    auto finish_member(string_view) -> result final {
        return {};
    }

    auto finish_struct() -> result final {
        return require("};");
    }

    auto begin_list(span_size_t& count) -> result final {
        result errors = require('[');
        if(!errors) {
            errors |= _read_one(count, '|');
        }
        return errors;
    }

    auto begin_element(span_size_t) -> result final {
        return {};
    }

    auto finish_element(span_size_t) -> result final {
        return {};
    }

    auto finish_list() -> result final {
        return require("];");
    }

    auto finish() -> result final {
        return require(">\0");
    }
};
//------------------------------------------------------------------------------
} // namespace eagine

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif // EAGINE_SERIALIZE_STRING_BACKEND_HPP
